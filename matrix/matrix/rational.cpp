/* matrix - operacje na macierzach zespolonych by konserw
 * rational.cpp - kod odpowiedzialny za liczby rzeczywiste
 * 
 * Copyright (C) 2009 Kamil Strzempowicz
 * Niniejszy program jest wolnym oprogramowaniem; mo¿esz go 
 * rozprowadzaæ dalej i/lub modyfikowaæ na warunkach Powszechnej
 * Licencji Publicznej GNU, wydanej przez Fundacjê Wolnego
 * Oprogramowania - wed³ug wersji 2-giej tej Licencji lub którejœ
 * z póŸniejszych wersji. 
 * Niniejszy program rozpowszechniany jest z nadziej¹, i¿ bêdzie on 
 * u¿yteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyœlnej 
 * gwarancji PRZYDATNOŒCI HANDLOWEJ albo PRZYDATNOŒCI DO OKREŒLONYCH 
 * ZASTOSOWAÑ. W celu uzyskania bli¿szych informacji - Powszechna 
 * Licencja Publiczna GNU. 
 * Z pewnoœci¹ wraz z niniejszym programem otrzyma³eœ te¿ egzemplarz 
 * Powszechnej Licencji Publicznej GNU (GNU General Public License);
 * jeœli nie - napisz do Free Software Foundation, Inc., 675 Mass Ave,
 * Cambridge, MA 02139, USA.
 * 
 * Pozdrawiam, konserw.
 * konserw@gmail.com
 */

#include "stdafx.h"
unsigned long long NWD(unsigned long long, unsigned long long);
/* moja implementacja abs() ze wzglêdu na brak wersji long long */
long long abs(long long x){
	if(x >= 0) return x;
	else return -x;
}

cRational::cRational(long long _licznik, long long _mianownik, bool _minus){
	minus = _minus;
	licznik = abs(_licznik);
	mianownik = abs(_mianownik);
	if(mianownik * licznik < 0) minus = true; /*ró¿ne znaki -> liczba ujemna*/
	else minus = false;
}

cRational operator+(const cRational& a, const cRational& b){
	if(!a.ujemne() && !b.ujemne()){//oba dodatnie
		if(a.mian() == b.mian())
			return cRational(a.licz() + b.licz(), a.mian());
		else{
			/* wspolny mianownik */
		}
	}
	else if (a.ujemne() && b.ujemne()){//oba ujemne
		if(a.mian() == b.mian())
			return cRational(a.licz() + b.licz(), a.mian(), false);
		else{
			/* wspolny mianownik */
		}
	}
}
cRational operator-(const cRational& a, const cRational& _b){
	cRational b = _b;
	b.zmien_znak();
	return a+b;
}
/*
friend cRational operator*(const cRational&, const cRational&);
friend cRational operator/(const cRational&, const cRational&);
void operator+=(const cRational&);
void operator-=(const cRational&);
void operator*=(const cRational&);
void operator/=(const cRational&);
*/

unsigned long long nwd(unsigned long long a, unsigned long long b){ //z neta binarne szukanie NWD
	unsigned long long k,r;

	if(!a || !b)
		return(a | b);

	for(k = 0; !((a | b) & 1); k++){
		a >>= 1;
		b >>= 1;
	}
	do{
		if(!a){
			a = b; 
			break;
		}
		while(!(a & 1)) a >>= 1;
		while(!(b & 1)) b >>= 1;
		if(a < b){
			r = (b - a) >> 1;
			b = a;
			a = r;
		}else
			a = (a - b) >> 1;
	}while(b);
	if(k) a <<= k;
	return a;
}
void common(const cRational& l1, cRational& l2, cRational& out1, cRational& out2);
	unsigned long long NWW, NWD, a, b, c, d;

	a = l1.mian();
	b = l2.mian();
	c = l1.licz();
	d = l2.licz();

	NWD=nwd(a,b); 
	NWW=a*b/NWD; 

	cRational out1((NWW/a)*c, NWW);
	cRational out2((NWW/b)*d, NWW);

