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

void edycja();

int main()
{
	bool tryb; //true = pol -> eng; false = eng -> pol
	std::string in, buff;
	bool out = false, exit = false;

//-------------- W�a�ciwa cz�� programu ---------------
while(out == false){
	std::cout<<"Witaj w slowniku pol - ang by konserw\n"
		"\n"
		"Nie uzywaj polskich znakow!\n"
		"Wybierz tryb:\n"
		"[D]odaj slowa\n"
		"Slownik:\n"
		"\t[P]ol -> Eng\n"
		"\t[E]ng -> Pol\n"
		"[L]icencja\n"
		"[W]yjscie\n";
		
	
		switch(std::cin.get()){
			case 'L':
				system("licencja.htm");
				break;
			case 'W':
				out = true;
				exit = true;
				break;
			case 'D':
				edycja();
				//exit = true;
				//out = true;
				break;
			case 'P':
				out = true;
				tryb = true;
				break;
			case 'E':
				out = true;
				tryb = false;
				break;
			default:
				std::cout<<"Musiszy wybrac P lub E!\n";
				break;
		}
	}
	if(exit == false){
		
	//-------------- Wczaytujemy baze -----------------
		std::vector<rekord> baza;

		std::ifstream plik_pol;
		plik_pol.open("pol");
		std::ifstream plik_eng;
		plik_eng.open("eng");

		while(getline(plik_pol, in)){
			getline(plik_eng, buff);
			rekord nowy(in, buff, tryb);
			baza.push_back(nowy);
		}

		plik_eng.close();
		plik_pol.close();
	//----------- baza wczytana ---------------------
		while(exit == false){
			char znak;
			out = true;
			std::cout<<"Wpisz slowo do tlumaczenia (UZYWAJ TYLKO MALYCH LITER):\n";
			std::cin.ignore();
			std::getline(std::cin, in);
			
			for(unsigned long i=0; i < baza.size(); ++i)
				if(baza[i].spr(in) == true){
					baza[i].tlum();
					out = false; //recycling zmiennych
					break;//konczymy petle w wypadku znalezienia odpowiedniego rekordu
				};
			if(out == true) std::cout<<"Nie znaleziono slowa!\n";
			std::cout<<"Zakonczyc dzialanie programu?\t T/N\t";
			for(;;){
				znak = std::cin.get();
				if(znak == 't' || znak == 'T'){
					exit = true;
					break;
				}
				if(znak == 'N' || znak == 'n')
					break;
				else std::cout<<"Wybierz T lub N!\n";
			}			
		}
	}
	return 0;
}
void edycja(){
	std::string pol;
	std::string eng;

	std::fstream plik_pol ("pol", std::fstream::out | std::fstream::ate);
	std::fstream plik_eng ("eng", std::fstream::out | std::fstream::ate);
	std::cin.ignore();
	for(;;){
		std::cout<<"Podaj polskie slowo, lub e, by zakonczyc:\t";
		//std::cin.ignore();
		std::getline(std::cin, pol);
		if(pol == "e") break;
		std::cout<<"Podaj angielskie tlumaczenie:\t";
		//std::cin.ignore();
		std::getline(std::cin, eng);
		plik_pol<<pol<<std::endl;
		plik_eng<<eng<<std::endl;
	}

	plik_eng.close();
	plik_pol.close();
}