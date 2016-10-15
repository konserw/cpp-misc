/* matrix - operacje na macierzach zespolonych by konserw
 * matrix.cpp - kod odpowiedzialny za macierze
 *
 * Copyright (C) 2009 Kamil Strzempowicz
 * Niniejszy program jest wolnym oprogramowaniem; mo�esz go 
 * rozprowadza� dalej i/lub modyfikowa� na warunkach Powszechnej
 * Licencji Publicznej GNU, wydanej przez Fundacj� Wolnego
 * Oprogramowania - wed�ug wersji 2-giej tej Licencji lub kt�rej�
 * z p�niejszych wersji. 
 * Niniejszy program rozpowszechniany jest z nadziej�, i� b�dzie on 
 * u�yteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domy�lnej 
 * gwarancji PRZYDATNO�CI HANDLOWEJ albo PRZYDATNO�CI DO OKRE�LONYCH 
 * ZASTOSOWA�. W celu uzyskania bli�szych informacji - Powszechna 
 * Licencja Publiczna GNU. 
 * Z pewno�ci� wraz z niniejszym programem otrzyma�e� te� egzemplarz 
 * Powszechnej Licencji Publicznej GNU (GNU General Public License);
 * je�li nie - napisz do Free Software Foundation, Inc., 675 Mass Ave,
 * Cambridge, MA 02139, USA.
 * 
 * Pozdrawiam, konserw.
 * konserw@gmail.com
 */

#include "stdafx.h"

unsigned cMatrix::wierszy() const{
	return p.size();
}
unsigned cMatrix::kolumn() const{
	return p[0].size();
}
std::vector<cComplex>& cMatrix::operator[](unsigned ktory){
	return p[ktory];
}

const std::vector<cComplex>& cMatrix::operator[](unsigned ktory) const{
	return p[ktory];
}

cMatrix cMatrix::operator++(){
	if(kwadratowa == true)
		this->wymiary(wierszy()+1, wierszy()+1);

	else
		this->wymiary(wierszy(), kolumn()+1);

	log("cMatrix", "postinkrementacja (zwiekszenie rozmiaru)");
	return *this;
}
cMatrix cMatrix::operator++(int){
	if(kwadratowa == true)
		this->wymiary(wierszy()+1, wierszy()+1);

	else
		this->wymiary(wierszy()+1, kolumn());

	log("cMatrix", "preinkrementacja (zwiekszenie rozmiaru)");	
	return *this;
}

void cMatrix::wyswietl(unsigned y, unsigned x){

	log("cMatrix", "wyswietlanie");
	win = subwin(stdscr, wierszy()+2, kolumn()*14+2, y, x);
	win_init = true;

	clear();
	border();
	wclear(win);
	wborder(win, 0, 0, ' ', ' ', 0, 0, 0, 0);
/*
	refresh();
	wrefresh(win);
	getch();
*/
	for(unsigned i=0; i < wierszy(); ++i)
		for(unsigned j=0; j < kolumn(); ++j){
			if(p[i][j].im() > 0)
				mvwprintw(win, i+1, 1+(j*14), "%.3lf+%.3lfi", p[i][j].re(), p[i][j].im());
			else if(p[i][j].im() >= -0.000001 && p[i][j].im() <= 0.000001)
				mvwprintw(win, i+1, 1+(j*14), "%.3lf", p[i][j].re());
			else 
				mvwprintw(win, i+1, 1+(j*14), "%.3lf%.3lfi", p[i][j].re(), p[i][j].im());
		}
	wrefresh(win);


}

cMatrix operator+(const cMatrix& m1, const cMatrix& m2){

	cMatrix nowa(m1.kw());
	
	if(m1.kolumn() == m2.kolumn() && m1.wierszy() == m2.wierszy()){
		nowa.wymiary(m1.wierszy(), m1.kolumn());
		for(unsigned i=0; i<m1.wierszy(); ++i)
			for(unsigned j=0; j<m1.kolumn(); ++j)
				nowa[i][j] = m1[i][j] + m2[i][j];
	}
	else{
		log("cMatrix", "r�ne wymiary dodwanie");
		nowa.error();
	}

	return nowa;
}
cMatrix operator-(const cMatrix& m1, const cMatrix& m2){

	cMatrix nowa(m1.kw());
	
	if(m1.kolumn() == m2.kolumn() && m1.wierszy() == m2.wierszy()){
		nowa.wymiary(m1.wierszy(), m1.kolumn());
		for(unsigned i=0; i<m1.wierszy(); ++i)
			for(unsigned j=0; j<m1.kolumn(); ++j)
				nowa[i][j] = m1[i][j] - m2[i][j];
	}
	else{
		log("cMatrix", "r�ne wymiary odejmowanie");
		nowa.error();
	}

	return nowa;
}
cMatrix operator*(const cMatrix& m1, const cMatrix& m2){

	cMatrix nowa(m1.kw());
	cComplex suma=0, buf;
	
	if(m1.kolumn() == m2.wierszy()){
		nowa.wymiary(m1.wierszy(), m2.kolumn());
		for(unsigned i=0; i<m1.wierszy(); ++i)
			for(unsigned j=0; j<m1.kolumn(); ++j){
				for(unsigned k=0; k<m1.kolumn(); ++k)suma += m1[i][k] * m2[k][j];
				nowa[i][j] = suma;
			}
	}
	else{
		log("cMatrix", "z�e wymiary mno�enie");
		nowa.error();
	}

	return nowa;
}
//cMatrix operator*(const cMatrix& m1, const cMatrix& m2);