/*
 * Plik log.cpp
 * log - biblioteka dziennika programu
 * 
 * Copyright (C) 2010 Kamil Strzempowicz
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
