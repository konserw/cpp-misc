#include "stdafx.h"
#include "tetris.h"
/***************
***	FUNKCJE ***
***************/

void time(cKlocek* klocek, bot* bot_block){//, HWND hWnd){
	if(klocek->down(bot_block)){//kolizja
		if(bot_block->maxy() < 2)
			PostQuitMessage(0);

		bot_block->add(klocek);
		delete klocek;

		switch(rand()%8){
			case 0:
				klocek = new sqb;
				break;
			case 1:
				klocek = new tb;
				break;
			case 2:
				klocek = new zb;
				break;
			case 3:
				klocek = new lb;
				break;
			case 4:
				klocek = new rlb;
				break;
			case 5:
				klocek = new ib;
				break;
			case 6:
				klocek = new rtb;
				break;
			case 7:
				klocek = new rzb;
				break;
		}

		for(UINT i=0; i<klocek->ile_blokow(); i++)
			bot_block->check();
	}
//	ref(hWnd);
}

void ref(HWND hWnd){
	RedrawWindow(hWnd, NULL, NULL,  RDW_INVALIDATE | RDW_ERASE | RDW_INTERNALPAINT);
}

/*****************
*** DOLNY BLOK ***
******************/
bot::bot(){
	nowych = 0;
}
void bot::add(cKlocek* k){
	UINT starych;
	cBlock* n;
	starych = nowych;
	nowych += k->ile_blokow();

	if(starych == 0){
		nowe = new cBlock[nowych];
		for(UINT i=0; i < nowych; i++)
			nowe[i] = k->blok(i);
		return;
	}
	n = new cBlock[nowych];
	for(UINT i=0; i<starych; i++)
		n[i] = nowe[i];
	for(UINT i=0; i < k->ile_blokow(); i++)
		n[starych+i] = k->blok(i);
	delete[] nowe;
	nowe = n;
}

UINT bot::maxy()const{
	UINT m = dim_y;
	for(UINT i=0; i<nowych; i++)
		if(nowe[i].pozy() < m) m = nowe[i].pozy();
	return m;
}
void bot::check(){
	bool f;
	bool** t=new bool*[dim_y];
	for(UINT i=0; i<dim_y; i++)
		t[i] = new bool[dim_x];
	for(UINT i=0; i < dim_y; i++)
		for(UINT j=0; j<dim_x; j++)
			t[i][j] = false;

	for(UINT k=0; k<nowych; k++)
		t[nowe[k].pozy()][nowe[k].pozx()] = true;

	for(UINT i=0; i < dim_y; i++){
		f = true;
		for(UINT j=0; j<dim_x; j++){
			if(t[i][j] == false){
				f = false;
				break;
			}
		}
		if(f==true)del(i);
	}

	for(UINT i=0; i<dim_y; i++)
		delete[] t[i];
	delete[] t;
}
void bot::del(UINT ui){
	cBlock* n = new cBlock[nowych-dim_x];
	UINT i=0;
	for(UINT k=0; k<nowych; k++)
		if(nowe[k].pozy() != ui){
			n[i] = nowe[k];
			if(n[i].pozy() > ui)n[i].sety(n[i].pozy()+1);
			i++;
		}
	delete[] nowe;
	nowe = n;
}

void bot::down(){
	for(UINT k=0; k<nowych; k++)
		nowe[k].sety(nowe[k].pozy()+1);
}


void bot::draw(HDC hdc)const{
	for(UINT i=0; i<nowych; ++i){
		nowe[i].draw(hdc);
	}
}

/**************
*** cBlock ***
**************/

cBlock::cBlock(){
	x = 0;
	y = 0;
	hb = CreateSolidBrush(RGB(0,255,0));
}
cBlock & cBlock::operator=(const cBlock &wzor){
	if(&wzor==this) return *this;

	poz_x = wzor.poz_x;
	poz_y = wzor.poz_y;
	x = wzor.x;
	y = wzor.y;
	hb = CreateSolidBrush(wzor.kolor());// wzor.hb;
	return *this;
}

void cBlock::set(UINT _y, UINT _x, COLORREF kolor){
	poz_x = _x;
	poz_y = _y;
	cr = kolor;
	DeleteObject((HGDIOBJ)hb);
	hb = CreateSolidBrush(kolor);
}

void cBlock::draw(HDC hdc){
	RECT rc;
	rc.top = (y + poz_y)*dim;
	rc.bottom = (y + poz_y+1)*dim;
	rc.left = (x + poz_x)*dim;
	rc.right = (x + poz_x+1)*dim;
	FillRect(hdc, &rc, hb);
}
UINT cBlock::pozx()const{
	return x + poz_x;
}
UINT cBlock::pozy()const{
	return y + poz_y;
}
void cBlock::setx(UINT in){
	x = in;
}
void cBlock::sety(UINT in){
	y = in;
}

/**************
*** cKlocek ***
***************/
UINT cKlocek::ile_blokow()const{
	return blokow;
}
const cBlock& cKlocek::blok(UINT i){
	if(i < blokow)return bloki[i];
	return bloki[0];
}
const cBlock& bot::blok(UINT i){
	if(i < nowych)return nowe[i];
	return nowe[0];
}
void cKlocek::move(char dir, bot* b){
	switch(dir){
		case 'a':
			if(x > 1)
				x--;
			break;
		case 'd':
			if(x+ix < dim_x)
				x++;
			break;
		case ' ':
			rot();
			break;
		case 's':
			time(this, b);
			break;
	}
}
bool cKlocek::down(bot* b){
	/*if(y+iy < dim_y) y++;
	else{
		y = dim_y - iy;
		return true;
	}*/
	if(y+iy >= dim_y){
		y = dim_y - iy;
		return true;
	}
	for(UINT i=0; i < blokow; i++)
		for(UINT j=0; j<b->ile(); j++)
			if(bloki[i].pozx() == b->blok(j).pozx() && bloki[i].pozy()+1 == b->blok(j).pozy())
				return true;
	y++;
	return false;
}
void cKlocek::draw(HDC hdc)const{
	for(UINT i=0; i<blokow; ++i){
		bloki[i].setx(x);
		bloki[i].sety(y);
		bloki[i].draw(hdc);
	}
}

/************
*** BLOKI ***
*************/

sqb::sqb(){
	x = dim_x/2;
	y = 0;
	ix = 2;
	iy = 2;
	blokow = 4;
	cr = RGB(255, 0, 0);
	bloki = new cBlock[blokow];
	bloki[0].set(0, 0, cr);
	bloki[1].set(1, 0, cr);
	bloki[2].set(0, 1, cr);
	bloki[3].set(1, 1, cr);
}

tb::tb(){
	x = dim_x/2;
	y = 0;
	blokow = 4;
	bloki = new cBlock[blokow];
	roted = true;
	cr = RGB(0, 0, 255);
	rot();
}
void tb::rot(){
	if(roted){
		ix = 3;
		iy = 2;
		bloki[0].set(0, 1, cr);
		bloki[1].set(1, 0, cr);
		bloki[2].set(1, 1, cr);
		bloki[3].set(1, 2, cr);
		roted = false;
	}
	else{
		ix = 2;
		iy = 3;
		bloki[0].set(0, 0, cr);
		bloki[1].set(1, 0, cr);
		bloki[2].set(1, 1, cr);
		bloki[3].set(2, 0, cr);
		roted = true;
	}
}
zb::zb(){
	x = dim_x/2;
	y = 0;
	blokow = 4;
	bloki = new cBlock[blokow];
	roted = true;
	cr = RGB(255, 255, 0);
	rot();
}
void zb::rot(){
	if(roted){
		ix = 3;
		iy = 2;
		bloki[0].set(0, 0, cr);
		bloki[1].set(0, 1, cr);
		bloki[2].set(1, 1, cr);
		bloki[3].set(1, 2, cr);
		roted = false;
	}
	else{
		ix = 2;
		iy = 3;
		bloki[0].set(0, 1, cr);
		bloki[1].set(1, 0, cr);
		bloki[2].set(1, 1, cr);
		bloki[3].set(2, 0, cr);
		roted = true;
	}
}
ib::ib(){
	x = dim_x/2;
	y = 0;
	blokow = 4;
	bloki = new cBlock[blokow];
	roted = true;
	cr = RGB(0, 255, 255);
	rot();
}
void ib::rot(){
	if(roted){
		ix = 4;
		iy = 1;
		bloki[0].set(0, 2, cr);
		bloki[1].set(0, 1, cr);
		bloki[2].set(0, 3, cr);
		bloki[3].set(0, 0, cr);
		roted = false;
	}
	else{
		ix = 1;
		iy = 4;
		bloki[0].set(3, 0, cr);
		bloki[1].set(0, 0, cr);
		bloki[2].set(1, 0, cr);
		bloki[3].set(2, 0, cr);
		roted = true;
	}
}
lb::lb(){
	x = dim_x/2;
	y = 0;
	blokow = 4;
	bloki = new cBlock[blokow];
	roted = true;
	cr = RGB(128, 128, 128);
	rot();
}
void lb::rot(){
	if(roted){
		ix = 3;
		iy = 2;
		bloki[0].set(0, 0, cr);
		bloki[1].set(1, 1, cr);
		bloki[2].set(1, 0, cr);
		bloki[3].set(1, 2, cr);
		roted = false;
	}
	else{
		ix = 2;
		iy = 3;
		bloki[0].set(0, 0, cr);
		bloki[1].set(0, 1, cr);
		bloki[2].set(1, 0, cr);
		bloki[3].set(2, 0, cr);
		roted = true;
	}
}
rlb::rlb(){
	x = dim_x/2;
	y = 0;
	blokow = 4;
	bloki = new cBlock[blokow];
	roted = true;
	cr = RGB(255, 0, 255);
	rot();
}
void rlb::rot(){
	if(roted){
		ix = 3;
		iy = 2;
		bloki[0].set(0, 0, cr);
		bloki[1].set(0, 1, cr);
		bloki[2].set(1, 0, cr);
		bloki[3].set(0, 2, cr);
		roted = false;
	}
	else{
		ix = 2;
		iy = 3;
		bloki[0].set(0, 0, cr);
		bloki[1].set(0, 1, cr);
		bloki[2].set(1, 1, cr);
		bloki[3].set(2, 1, cr);
		roted = true;
	}
}

rtb::rtb(){
	x = dim_x/2;
	y = 0;
	blokow = 4;
	bloki = new cBlock[blokow];
	roted = true;
	cr = RGB(128, 0, 255);
	rot();
}
void rtb::rot(){
	if(roted){
		ix = 3;
		iy = 2;
		bloki[0].set(0, 0, cr);
		bloki[1].set(1, 0, cr);
		bloki[2].set(0, 1, cr);
		bloki[3].set(0, 2, cr);
		roted = false;
	}
	else{
		ix = 2;
		iy = 3;
		bloki[0].set(0, 1, cr);
		bloki[1].set(1, 0, cr);
		bloki[2].set(1, 1, cr);
		bloki[3].set(2, 1, cr);
		roted = true;
	}
}
rzb::rzb(){
	x = dim_x/2;
	y = 0;
	blokow = 4;
	bloki = new cBlock[blokow];
	roted = true;
	cr = RGB(128, 255, 0);
	rot();
}
void rzb::rot(){
	if(roted){
		ix = 3;
		iy = 2;
		bloki[0].set(0, 2, cr);
		bloki[1].set(0, 1, cr);
		bloki[2].set(1, 1, cr);
		bloki[3].set(1, 0, cr);
		roted = false;
	}
	else{
		ix = 2;
		iy = 3;
		bloki[0].set(0, 0, cr);
		bloki[1].set(1, 0, cr);
		bloki[2].set(1, 1, cr);
		bloki[3].set(2, 1, cr);
		roted = true;
	}
}