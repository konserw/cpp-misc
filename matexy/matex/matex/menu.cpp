/*
 * Matex2
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

#include "PCH.h"
#include "naglowek.h"

menu::menu(eJakie_menu jakie, unsigned short ktore){
	jakie_menu = jakie;
	ktore_menu = ktore;
	ktory = 0;

	opcje.push_back("Powrot do menu glownego");

	switch(jakie_menu){
		case menu_glowne:
			opcje.pop_back();
			opcje.push_back("Zakonczenie programu");
			opcje.push_back("Planimetria");
			opcje.push_back("Stereometria");
			opcje.push_back("Geometria analityczna");
			opcje.push_back("Algebra");
			opcje.push_back("Kombinatoryka");
			opcje.push_back("Ciagi");
			opcje.push_back("Teoria liczb");
			opcje.push_back("Wyswietl readme");
			opcje.push_back("Licencja");
			pion = 11;
			poziom = 4;
			break;
		case menu_pierwsze:
			switch(ktore_menu){
				case 1:
					opcje.push_back("trojkat");
					opcje.push_back("kwadrat");
					opcje.push_back("prostokat");
					opcje.push_back("romb");
					opcje.push_back("rownoleglobok");
					opcje.push_back("trapez");
					opcje.push_back("deltoid");
					opcje.push_back("szesciokat foremny");
					opcje.push_back("kolo");
					break;
				case 2:
					opcje.push_back("Graniastoslupy");
					opcje.push_back("Ostroslupy");
					opcje.push_back("Bryly obrotowe");
					break;
				case 3:
					opcje.push_back("Odleglosc punktu od prostej");
					opcje.push_back("Odleglosc miedzy dwoma punktami (dlugosc odcinaka)");
					opcje.push_back("Dwie proste");
					break;
				case 4:
					opcje.push_back("Rozwiazywanie rownania kwadratowego");
					opcje.push_back("Rozwiazywanie ukladu I stopnia 2 rownan z 2 niewiadomymi");
					opcje.push_back("Rozwiazywania ukladu I stopnia 3 rownan z 3 niewiadomymi");
					opcje.push_back("Szukanie pierwiastkow wielomianu dowolnego stopnia");
					opcje.push_back("Dzielenie wielomianu przez dwumian (schematem hornera)");
					break;
				case 5:		
					opcje.push_back("Permutacja (silnia)");
					opcje.push_back("Warjacje bez powtorzen");
					opcje.push_back("Wariacje z powtorzeniami");
					opcje.push_back("Kombinacje");
					break;
				case 6:
					opcje.push_back("n-ty wyraz za pomoca pierwszego wyrazu ciagu i roznicy");
					opcje.push_back("n-ty wyraz za pomoca sumy czesciowej n pierwszych wyrazow oraz pierwszego wyrazu ciagu");
					opcje.push_back("Wyraz za pomoca wyrazu poprzedniego i wyrazu nastepnego");
					opcje.push_back("Suma czesciowa n pierwszych wyrazow");
					opcje.push_back("n-ty wyraz za pomoca pierwszego wyrazu i ilorazu");
					opcje.push_back("Wyraz za pomoca wyrazu poprzedniego i wyrazu nastepnego");
					opcje.push_back("Suma czesciowa n pierwszych wyrazow");
					break;
				case 7:
					opcje.push_back("Sprawdzanie, czy dana liczba jest pierwsza");
					opcje.push_back("Szukanie wszystkich liczb pierwsze (i ich ilosc) nie wieksze niz podana");
					opcje.push_back("Szukanie wszystkich dzielnikow danej liczby");
					break;
			}
			pion = 11 + ktore_menu;
			poziom = 28;
			break;
		case menu_planimetria:
			switch(ktore_menu){
				case 1:
					opcje.push_back("typowy trojkat");
					opcje.push_back("trojkat rownoboczny");
					opcje.push_back("trojkat - 3 boki");
					opcje.push_back("trojkat - 2 boki i kat");
					break;
				case 2:
					opcje.push_back("typowy kwadrat");
					opcje.push_back("kwadrat - przekatne");
					break;
				case 4:
					opcje.push_back("typowy romb");
					opcje.push_back("romb - kat");
					opcje.push_back("romb - przekatna");
					break;
				case 5:
					opcje.push_back("typowy rownoleglobok");
					opcje.push_back("rownoleglobok - 2 boki i kat");
					opcje.push_back("rownoleglobok - przekatne i kat");
					break;
				case 6:
					opcje.push_back("trapez - obie podstawy i wysokosc");
					opcje.push_back("trapez rownoramienny - wysokosc, ramie i krotsza podstawa");
					opcje.push_back("trapez rownoramienny - ramie i obie podstawy");
					opcje.push_back("trapez rownoramienny - kat ostry, ramie i krotsza podstawa");
					opcje.push_back("trapez rownoramienny - kat ostry, wysokosc i krotsza podstawa");
					opcje.push_back("trapez prostokatny - kat ostry, wysokosc i krotsza podstawa");
					opcje.push_back("trapez prostokatny - kat ostry, ramie i krotsza podstawa");
					opcje.push_back("trapez prostokatny - obie podstawy i dluzsza przekatna");
					opcje.push_back("trapez prostokatny - obie podstawy i krotsza przekatna");
					break;
			}
			pion = 12 + ktore_menu;
			poziom = 54;
			break;
		case menu_stereometria:
			switch(ktore_menu){
				case 1:
					opcje.push_back("szescian");
					opcje.push_back("prostopadloscian");
					opcje.push_back("prosty trojkatny");
					opcje.push_back("prawidlowy trojkatny");
					opcje.push_back("prawidlowy czworokatny");
					opcje.push_back("prosty czworokatny");
					opcje.push_back("prawidlowy szesciokatny");
					break;
				case 2:
					opcje.push_back("czworoscian");
					opcje.push_back("trojkatny");
					opcje.push_back("prawidlowy trojkatny");	
					opcje.push_back("czworokatny");
					opcje.push_back("prawidlowy czworokatny");
					opcje.push_back("prawidlowy szesciokatny");
					break;
				case 3:
					opcje.push_back("Walec");
					opcje.push_back("Stozek");	
					opcje.push_back("Kula");	
					break;
			}
			pion = 13 + ktore_menu;
			poziom = 54;
			break;
		case menu_gran_troj:
				opcje.push_back("Wysokosc, bok i wysokosc podstawy");
				opcje.push_back("Wysokosc, 2 boki podstawy i kat miedzy nimi");
				opcje.push_back("Wysokosc i 3 boki podstawy");
				opcje.push_back("Wysokosc i pole powierzchni podstawy");
				pion = 17;
				poziom = 82;
				break;
	}
	ile = opcje.size();
	--ile; //bo od 0
}

void menu::wyswietl(){

	for(unsigned short i = 0; i <= ile; ++i)
		mvprintw(pion+i, poziom, "%s", opcje[i].c_str());
	attron(A_REVERSE);
	mvprintw(pion + ktory, poziom - 2, "=>");
	attroff(A_REVERSE);

	refresh();

}
