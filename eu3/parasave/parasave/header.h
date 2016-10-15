/*
 * Edytor save dla EU3 by konserw
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
extern bool eng; /*language of gui
				  *true - english
				  *false - polish
				  */
bool beg(std::string& path, std::string& linie);

bool sciezka(std::string& path);
void wybor_moda(std::string& path);
bool load(const std::string& path, std::string& buff);
bool wybor_save(std::string& path);
void save(std::string& linie, std::string& path);
void historia(std::string&);
void flag(std::string& wejscie);
void latin(std::string& wejscie);
void sz_id(const std::string& wej);
void mag(std::string& wejscie);
void nawiasy(std::string& wej);
void rev_nawiasy(std::string& wej);

class id{
public:
	int nr;
	int type;
	id(int n, int m): nr(n), type(m){};
	std::string print(){
		std::stringstream ss;
		ss << "id: " << nr;
		if(nr < 1000)ss << "\t";
		ss << "\tTyp: "	<< type;
		return ss.str();
	}

};