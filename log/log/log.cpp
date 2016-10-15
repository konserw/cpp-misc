/*
 * Plik log.cpp
 * log - biblioteka dziennika programu
 * 
 * Copyright (C) 2010 Kamil Strzempowicz
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

#include "log.h"

//Zmienne globalne
std::string dir;
//FUNKCJE LOGA
void czyszczenie_loga(HMODULE hMod){
	char d[MAX_PATH];
	//GetCurrentDirectory(1024, d);
	GetModuleFileName(hMod, d, MAX_PATH);
	dir = d;
	dir = dir.substr(0, dir.find_last_of('\\'));
	dir += "\\error.log";

	std::ofstream cerr(dir.c_str(), std::fstream::trunc);
	cerr << "czas\t/funkcja/\tdzialanie\n" << std::endl;
	cerr.close();
}
void log(const char* info){
	log("main", info);
}
void log(const char* fun, const char* info){
	std::ofstream err(dir.c_str(), std::fstream::app);
	err << clock() / CLOCKS_PER_SEC << ":\t/" << fun << "/\t" << info << std::endl;
	err.close();
}
void log(const char* fun, const char* info, double liczba){
	std::ofstream err(dir.c_str(), std::fstream::app);
	err << clock() / CLOCKS_PER_SEC << ":\t/" << fun << "/\t" << info << ":\t" << liczba << std::endl;
	err.close();
}
void log(const char* fun, const char* info, const char* string){
	std::ofstream err(dir.c_str(), std::fstream::app);
	err << clock() / CLOCKS_PER_SEC << ":\t/" << fun << "/\t" << info << ":\t" << string << std::endl;
	err.close();
}
void logline(){
	std::ofstream err(dir.c_str(), std::fstream::app);
	err << "\n";
	for(int i=0; i<30; ++i)err << "##";
	err << "\n" << std::endl;
	err.close();	
}
