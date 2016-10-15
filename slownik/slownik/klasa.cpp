/*
 * slownik
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

#include "stdafx.h"
#include "header.h"

rekord::rekord(std::string slowo, std::string word, bool jak){
	pol = slowo;
	eng = word;
	tryb = jak;
}
bool rekord::spr(std::string in){
	if(tryb == false){
		if(in == eng) return true;
		else return false;
	}
	else{
		if(in == pol) return true;
		else return false;
	}
}
void rekord::tlum(){
	if(tryb == true) std::cout<<pol<<" to po angielsku "<<eng<<"\n";
	else std::cout<<"Slowo "<<eng<<" znaczy tyle, co "<<pol<<"\n";
}
	