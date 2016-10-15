/*
 * Edytor save dla EU3 by konserw
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
#include "stdafx.h"
//#include "menu.h"

bool sciezka(std::string& path);
void wybor_moda(std::string& path);
bool load(const std::string& path, std::string& buff, size_t& indeks_human);//, std::string& tag_human);
bool wybor_save(std::string& path);

typedef void (*pfun)(std::string&, WINDOW*, std::string&, size_t&);

void ustawienia(std::string& linie, WINDOW* wDol, std::string& sReserved, size_t& tReserved);
void save(std::string& linie, WINDOW* wDol, std::string& path, size_t& tReserved);
void flagi(std::string& linie, WINDOW* wDol, std::string& sReserved, size_t& indeks);
void data(std::string& linie, WINDOW* win, std::string& sReserved, size_t& tReserved);
void wybor_tag(std::string& linie, WINDOW* win, std::string& sReserved, size_t& indeks);
//void kraj(std::string& linie, WINDOW* win, std::string& sReserved, size_t& indeks);

void explode(const std::string &str, const char *delim, std::vector<std::string> &out);

class cDana{
public:
	std::string co;
	std::string wartosc;
	size_t poczatek, koniec, rown;
	bool ok;
	//const std::string& linie;

	cDana(const std::string& linie, const std::string& nazwa, size_t indeks);

	void zapis(std::string& linie);

	bool good(){return ok;}

	const char* chco(){
		return co.c_str();
	}
	const char* chwartosc(){
		return wartosc.c_str();
	}
	std::string strco(){
		return co;
	}
	/*
	std::string& strwartosc(){
		return wartosc;
	}*/
	//void strwartosc(std::string& 


};
