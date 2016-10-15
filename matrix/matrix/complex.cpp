/* matrix - operacje na macierzach zespolonych by konserw
 * complex.cpp - kod odpowiedzialny za liczby zespolone
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
/*
cComplex::cComplex(std::string liczba){ //konwersja z ³añcucha znaków
	std::istringstream sstr(liczba);
	sstr >> x;
	if(!sstr.good()){
		if(liczba.find("-i") != -1){
			y = -1;
			x = 0;
		}
		else{
			y = 1;
			x = 0;
		}
	}
	else{
		sstr >> y;
		if(!sstr.good()){
			if(liczba.find('i') == -1){
				y = 0;
			}
			else{
				y = x;
				x = 0;
			}
		}
	}
}
*/
/*	std::istringstream sstr(liczba);	

	if(liczba.find('i') == -1){ //bez i czyli rzeczywista
		sstr >> x;
		y = 0;
		//mod = fabs(r);
		//arg = 0;
	}
	else{
		size_t s;
		s = liczba.rfind('-');

		if(s != -1){//gdzies minus
			if(s == 0){//-yi
				sstr >> u;
				r = 0;
				//mod = fabs(u);
				//arg = (3/2)*M_PI;
			}
			else{//x-yi || -x-yi
				sstr >> r;
				sstr >> u;
				//mod = sqrt((r*r) + (u*u));
			}
		}
		else{
			if(liczba[0] == 'i'){//samo i
				u = 1;
				r = 0;
				//mod = 1;
				//arg = (1/2)*M_PI;
			}
			else{//typowo x+yi
				sstr >> r;
				sstr >> u;
				//6mod = sqrt((r*r) + (u*u));
			}
		}
	}
}*/

cComplex operator+(const cComplex& Liczba1, const cComplex& Liczba2){
	return cComplex(Liczba1.re() + Liczba2.re(), Liczba1.im() + Liczba2.im());
}
cComplex operator-(const cComplex& Liczba1, const cComplex& Liczba2){
	return cComplex(Liczba1.re() - Liczba2.re(), Liczba1.im() - Liczba2.im());
}

cComplex operator*(const cComplex& Liczba1, const cComplex& Liczba2){
	double re, im;
	re = (Liczba1.re() * Liczba2.re()) - (Liczba1.im() * Liczba2.im());
	im = (Liczba1.re() * Liczba2.im()) + (Liczba1.im() * Liczba2.re());
	return cComplex(re, im);
}
cComplex operator/(const cComplex& l1, const cComplex& l2){
	double re=0, im=0;
	
	re = (l1*l2.sprzezenie()).re() / (pow(l2.re(), 2) + pow(l2.im(), 2));
	im = (l1*l2.sprzezenie()).im() / (pow(l2.re(), 2) + pow(l2.im(), 2));
	return cComplex(re, im);
}

void cComplex::operator+=(const cComplex& Liczba2){
	*this = *this + Liczba2;
}
void cComplex::operator-=(const cComplex& Liczba2){
	*this = *this - Liczba2;
}
void cComplex::operator*=(const cComplex& Liczba2){
	*this = *this * Liczba2;
}
void cComplex::operator/=(const cComplex& Liczba2){
	*this = *this / Liczba2;
}

double cComplex::argument()const{ // do skonczenia
	double fi;


	return fi;
}