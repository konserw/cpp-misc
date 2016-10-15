/* matrix - operacje na macierzach zespolonych by konserw
 * rational.h - kod odpowiedzialny za liczby rzeczywiste
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