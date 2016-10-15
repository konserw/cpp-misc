/* matrix - operacje na macierzach zespolonych by konserw
 * matrix.h - kod odpowiedzialny za macierze
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