#pragma once

#include "resource.h"

extern UINT dim_x, dim_y;
extern const int dim;

class cKlocek;

class cBlock{
private:
	UINT poz_x, poz_y, x, y;
	COLORREF cr;
	HBRUSH hb;
public:
	cBlock();
	cBlock & operator=(const cBlock &wzor);
	void set(UINT _y, UINT _x, COLORREF kolor);
	void draw(HDC hdc);
	void setx(UINT in);
	void sety(UINT in);
	UINT pozx()const;
	UINT pozy()const;
	COLORREF kolor()const{
		return cr;
	}
	~cBlock(){
		DeleteObject((HGDIOBJ)hb);
	}
};
		
class bot{
private:
	UINT nowych;
	cBlock* nowe;
public:
	bot();
	void add(cKlocek* k);
	void draw(HDC hdc)const;
	const cBlock& blok(UINT i);
	UINT ile()const{
		return nowych;
	}
	void check();
	void del(UINT);
	void down();
	UINT maxy()const;
	~bot(){
		delete[] nowe;
	}
};

class cKlocek{
protected:
	cBlock* bloki;
	UINT x, y, ix, iy, blokow;
	bool roted;
	COLORREF cr;
public:
//	virtual void draw(HDC hdc)const = 0;
	virtual void rot() = 0;
//	virtual void move(char dir) = 0;
//	virtual bool down() = 0;
	UINT ile_blokow()const;
	const cBlock& blok(UINT i);
	void move(char dir, bot* b);
	bool down(bot* b);
	void draw(HDC hdc)const;
};

//void nowy(bot*, cKlocek*);
void ref(HWND hWnd);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
void time(cKlocek* klocek, bot* bot_block);

class sqb: public cKlocek{
public:
	sqb();
	void rot(){
	}
	~sqb(){
		delete[] bloki;
	}
};
class tb: public cKlocek{
public:
	tb();
	void rot();
	~tb(){
		delete[] bloki;
	}
};
class zb: public cKlocek{
public:
	zb();
	void rot();
	~zb(){
		delete[] bloki;
	}
};
class ib: public cKlocek{
public:
	ib();
	void rot();
	~ib(){
		delete[] bloki;
	}
};
class lb: public cKlocek{
public:
	lb();
	void rot();
	~lb(){
		delete[] bloki;
	}
};
class rlb: public cKlocek{
public:
	rlb();
	void rot();
	~rlb(){
		delete[] bloki;
	}
};
class rtb: public cKlocek{
public:
	rtb();
	void rot();
	~rtb(){
		delete[] bloki;
	}
};
class rzb: public cKlocek{
public:
	rzb();
	void rot();
	~rzb(){
		delete[] bloki;
	}
};