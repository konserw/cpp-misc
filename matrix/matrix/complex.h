/* matrix - operacje na macierzach zespolonych by konserw
 * complex.h - kod odpowiedzialny za liczby zespolone
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

#pragma once

class cComplex{
private:
	double x, y; // czêœæ rzeczywista i urojona
//	double arg, mod; //modu³ i argument (g³) - narazie nie wykorzystane

public:

	cComplex(): x(0), y(0) {}
	cComplex(double rzeczywista, double urojona): x(rzeczywista), y(urojona) {}
	cComplex(double rzeczywista): x(rzeczywista), y(0) {}
	//cComplex(std::string liczba);

	double re()const{
		return x;
	}
	double im()const{
		return y;
	}
	double mod()const{
		return sqrt((x*x) + (y*y));
	}
	cComplex sprzezenie()const{
		return cComplex(x, -y);
	}
	double argument()const;

	friend cComplex operator+(const cComplex&, const cComplex&);
	friend cComplex operator-(const cComplex&, const cComplex&);
	friend cComplex operator*(const cComplex&, const cComplex&);
	friend cComplex operator/(const cComplex&, const cComplex&);
	void operator+=(const cComplex&);
	void operator-=(const cComplex&);
	void operator*=(const cComplex&);
	void operator/=(const cComplex&);
};




