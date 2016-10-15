/*
MaTeX2 - program matematyczny z lepszym interfejsem :)
Copyright (C) 2009 Kamil Strzempowicz
Niniejszy program jest wolnym oprogramowaniem; mo�esz go 
rozprowadza� dalej i/lub modyfikowa� na warunkach Powszechnej
Licencji Publicznej GNU, wydanej przez Fundacj� Wolnego
Oprogramowania - wed�ug wersji 2-giej tej Licencji lub kt�rej�
z p�niejszych wersji. 
Niniejszy program rozpowszechniany jest z nadziej�, i� b�dzie on 
u�yteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domy�lnej 
gwarancji PRZYDATNO�CI HANDLOWEJ albo PRZYDATNO�CI DO OKRE�LONYCH 
ZASTOSOWA�. W celu uzyskania bli�szych informacji - Powszechna 
Licencja Publiczna GNU. 
Z pewno�ci� wraz z niniejszym programem otrzyma�e� te� egzemplarz 
Powszechnej Licencji Publicznej GNU (GNU General Public License);
je�li nie - napisz do Free Software Foundation, Inc., 675 Mass Ave,
Cambridge, MA 02139, USA.

Pozdrawiam, konserw.
konserw@gmail.com
*/
#pragma once
#include "PCH.h"

enum eTyp {N, R, J};//R- whatever; N > 0; J >= 1 i ca�kowite
enum eJakie_menu{
	menu_glowne,
	menu_pierwsze,
	menu_planimetria,
	menu_stereometria,
	menu_gran_troj //r�ne graniastos�upy tr�jk�tne
};

extern std::vector<double> tablica;

//--------------------------------------------
//----------------prototypy funkcji----------
//-------------------------------------------
void stop();

long double ctg (long double alfa);

unsigned __int64 silnia(__int64);

long double twcos(long double, long double, long double);

bool in (unsigned short, eTyp); 

void logo ();

//----------------wybory----------------
void geometria(unsigned short);
void algebra(unsigned short);
void kombinatoryka(unsigned short);
void ciagi(unsigned short);
void teoria(unsigned short);
//stereometria
void graniastoslupy(unsigned short);
	void grantroj(unsigned short);
void ostroslupy(unsigned short);
void obrotowe(unsigned short);
//planimetria
void planimetria(unsigned short);
void trapezy(unsigned short);
void trojkaty(unsigned short);
void kwadraty(unsigned short);
void romby(unsigned short);
void rownolegloboki(unsigned short);
void trapezy(unsigned short);


//----- klasa menu -----------
class menu
{
    public:
        menu(eJakie_menu, unsigned short ktore);
        unsigned short operator++(){
			if (ktory == ile) ktory = 0;
			else ++ktory;
			return ktory;
		}
         unsigned short operator--(){
			 if (ktory == 0) ktory = ile;
			 else --ktory;
			 return ktory;
		 }
        operator unsigned short() {return ktory;}

        void wyswietl();
    private:
		//zmienne ogolne:
        unsigned short ktory;
        unsigned short ile;
		unsigned short ktore_menu;
		eJakie_menu jakie_menu;
		std::vector<std::string> opcje;
		//gdzie ma sie zaczynac wyswietlanie:
		unsigned short pion; //Y
		unsigned short poziom; //X
};