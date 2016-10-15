/*
 * SPOJe konserwa :)
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

#include <iostream>
#include <sstream>
#include <cstring>

float get();

int main(){

	unsigned uczniow;
	float srednia = 0;

	std::cin>> uczniow;
	for(unsigned i = 0; i < uczniow; ++i)
		srednia += get();
	std::cout<< srednia / static_cast<float>(uczniow);

	//std::cin.get();
	return 0;
}

float get(){
	std::string linia;
	std::cin.ignore();
	std::getline(std::cin, linia);
	linia = linia.substr(linia.find_last_of(' '), std::string::npos);
	float i;
	std::istringstream iss(linia);
	iss >> i;
	return i;
}