/*
 * SPOJe konserwa :)
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