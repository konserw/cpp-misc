/*
 * no time limit patch 4 EU III by konserw
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
LONG wersja(std::string dodatek, HKEY hkEU, std::string& patch);
bool sciezka(std::string& path);
void wybor_moda(std::string& path);
bool data(std::string& sciezka, struct sData dat, short start);
bool techy(unsigned zadana, std::string& sciezka);
struct sData{
	unsigned yy;
	unsigned mm;
	unsigned dd;
};
enum eVer{
	h3t, 
	in
};
extern eVer ver;

