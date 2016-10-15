/* matrix - operacje na macierzach zespolonych by konserw
 * rational.h - kod odpowiedzialny za liczby rzeczywiste
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

class cRational{
private:
	unsigned long long licznik;
	unsigned long long mianownik;
	bool minus;
public:
	cRational(): licznik(0), mianownik(1), minus(false){ /*element domyslny - zero*/
	};
	cRational(long long _licznik, long long _mianownik, bool _minus = false);

	unsigned long long mian()const{
		return mianownik;
	}
	unsigned long long licz()const{
		return licznik;
	}
	bool ujemne()const{
		if(minus) return true;
		return false;
	}
	cRational zmien_znak(){
		if(minus) minus = false;
		else minus = true;
		return *this;
	}
	double approx()const{
		if(minus) return - (licznik / static_cast<long double>(mianownik));
		return licznik / static_cast<long double>(mianownik);
	}
	

	friend cRational operator+(const cRational&, const cRational&);
	friend cRational operator-(const cRational&, const cRational&);
	friend cRational operator*(const cRational&, const cRational&);
	friend cRational operator/(const cRational&, const cRational&);
	void operator+=(const cRational&);
	void operator-=(const cRational&);
	void operator*=(const cRational&);
	void operator/=(const cRational&);
};