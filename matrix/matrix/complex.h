/* matrix - operacje na macierzach zespolonych by konserw
 * complex.h - kod odpowiedzialny za liczby zespolone
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

#pragma once

class cComplex{
private:
	double x, y; // cz�� rzeczywista i urojona
//	double arg, mod; //modu� i argument (g�) - narazie nie wykorzystane

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




