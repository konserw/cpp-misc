/* matrix - operacje na macierzach zespolonych by konserw
 * matrix.h - kod odpowiedzialny za macierze
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

#include "complex.h"

class cMatrix{
private:
	std::vector<std::vector<cComplex> > p;
	WINDOW* win;
	bool win_init;
	bool ok;
	bool kwadratowa;

public:
	unsigned wierszy() const;
	unsigned kolumn() const;

	cMatrix(bool czy_kwadratowa=true): kwadratowa(czy_kwadratowa), win_init(false), ok(true){ 
		wymiary(1, 1);
	}
	void wymiary(unsigned x, unsigned y){
		p.resize(x);
		for(unsigned i=0; i < wierszy(); ++i) p[i].resize(y);
	}

	~cMatrix(){
		if(win_init == true) delwin(win);
	}

	cMatrix operator++();
	cMatrix operator++(int);
	void cMatrix::wyswietl(unsigned y, unsigned x);
	std::vector<cComplex>& operator[](unsigned);

	void error(){
		ok = false;
	}
	bool good() const{
		return ok;
	}
	bool kw() const{
		return kwadratowa;
	}

	friend cMatrix operator+(const cMatrix&, const cMatrix&);
	friend cMatrix operator-(const cMatrix&, const cMatrix&);
	friend cMatrix operator*(const cMatrix&, const cMatrix&);
	//friend cMatrix operator/(const cMatrix&, const cMatrix&);
	const std::vector<cComplex>& cMatrix::operator[](unsigned ktory) const;
};