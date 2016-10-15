/*
 * Matex 2 - program o zastosowaniu ogólnomatematycznym
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
#pragma once
#include "PCH.h"
#include "naglowek.h"

std::vector<double> tablica;

unsigned short ktory=0, ktory2=0, ktory3=0, ktory4=0;
void menuglowne();
void logo();
void info();

int main(){

bool out=false;
initscr();  
keypad(stdscr, true);
resize_term(50, 130);
raw();

if(has_colors() == TRUE) start_color();
init_pair(1, COLOR_WHITE, COLOR_BLUE);
bkgd(COLOR_PAIR(1));	attron(COLOR_PAIR(1));	attron(A_BOLD);
border(0, 0, 0, 0, 0, 0, 0, 0);

do{
	menuglowne();
	switch(ktory){
		case 0: 
			out=true;
			break;
		case 1:
			if (ktory2 == 1 || ktory2 == 2 || ktory2 == 4 || ktory2 == 5 || ktory2 == 6)
			switch(ktory2){
				case 1:
					trojkaty(ktory3);
					break;
				case 2:
					kwadraty(ktory3);
					break;
				case 4:
					romby(ktory3);
					break;
				case 5:
					rownolegloboki(ktory3);
					break;
				case 6:
					trapezy(ktory3);
			}
			else
				planimetria(ktory2);
			break;
		case 2:
			switch(ktory2){
				case 1:
					if(ktory3 == 3)
						grantroj(ktory4);
					else
						graniastoslupy(ktory3);
					break;
				case 2:
					ostroslupy(ktory3);
					break;
				case 3:
					obrotowe(ktory3);
					break;
			}
			break;
		case 3:
			geometria(ktory2);
			break;
		case 4:
			algebra(ktory2);
			break;
		case 5:
			kombinatoryka(ktory2);
			break;
		case 6:
			ciagi(ktory2);
			break ;
		case 7:
			teoria(ktory2);
			break;
		case 8:
			system("readme.txt");
			break;
		case 9:
			system("licencja.htm");
			break;
	}
}while(out!=true);
//--------------pozegnanie------------------
clear();
mvprintw(20, 20, "Dziekuje za korzystanie z mojego programu :)");
mvprintw(22, 20, "coptleft Kamil 'konserw' Strzempowicz");
mvprintw(24, 20, "W programie wykorzystano biblioteke PDCurses");
mvprintw(26, 20, "Specjalne podziekowania dla:");
mvprintw(28, 30, "# Dyzia, za podrzucenie kawalka kodu");
mvprintw(29, 30, "# ludzi z forum programuj.com za nieoceniona wielokrotna pomoc");
mvprintw(30, 30, "# wszystkich wylapujacych bugi (szczegolnie Wator!)");
stop();
endwin();
return 0;
}

//########################
//##		MENU		##
//########################

void info(){
	attron(A_BOLD);
	mvprintw(10, 95, "Strzalki w gore i w dol - kursor");
	mvprintw(11, 95, "Enter lub => aby wybor");
	mvprintw(12, 95, "Esc lub <= - poprzednie menu");
	attroff(A_BOLD);
}

void menuglowne(){
	std::vector<std::string> opcje;
	std::vector<std::string> opcje2;
	std::vector<std::string> opcje3;
	std::vector<std::string> opcje4;
	bool out=false;
	int znak=1;
	const short int min_wybor = 0;
	short int max_wybor;

	//opcje w menu glownym
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
	
	max_wybor=opcje.size();//maxymalny wybor rowny ilosci opcji
	max_wybor--;//-1 bo od zera
	for(;;){//zeby break dzialal
	for(;;){
		clear();//czysci ekran
		logo();//wyswietla logo
		//przejscia pionowe
		if (znak == 259 && ktory != min_wybor) ktory--;
		else if(znak == 258 && ktory != max_wybor) ktory++;
		else if(znak ==258 && ktory == max_wybor) ktory = min_wybor;
		else if(znak ==259 && ktory == min_wybor) ktory = max_wybor; 
		//przejscia poziome
		else if(znak == 13 || znak==261)
			break;
		info();
		//--------opcje w menu----------
		for(unsigned short i=0; i<=max_wybor; ++i)
			mvprintw(11+i, 4, "%s", opcje[i].c_str());
		//----------kursor---------
		attron(A_UNDERLINE | A_BOLD);
		mvprintw(11+ktory, 2, "=>");
		attroff(A_UNDERLINE | A_BOLD);
		//---------kursr w rog i oczekiwanie na klawisz
		noecho();
		move(0,0);
		znak = getch();
	}
//-------------------------------------------------------------------------------------------------
podmenu1:
	if(ktory==0 || ktory==8 || ktory==9)break; //podmenu niepotrzebne do tych case
		//ktore podemnu ma byc wyswietlone
		opcje2.clear();
		opcje2.push_back("Powrot do menu glownego");
		switch(ktory){
			case 1:
				opcje2.push_back("trojkat");
				opcje2.push_back("kwadrat");
				opcje2.push_back("prostokat");
				opcje2.push_back("romb");
				opcje2.push_back("rownoleglobok");
				opcje2.push_back("trapez");
				opcje2.push_back("deltoid");
				opcje2.push_back("szesciokat foremny");
				opcje2.push_back("kolo");
				break;
			case 2:
				opcje2.push_back("Graniastoslupy");
				opcje2.push_back("Ostroslupy");
				opcje2.push_back("Bryly obrotowe");
				break;
			case 3:
				opcje2.push_back("Odleglosc punktu od prostej");
				opcje2.push_back("Odleglosc miedzy dwoma punktami (dlugosc odcinaka)");
				opcje2.push_back("Dwie proste");
				break;
			case 4:
				opcje2.push_back("Rozwiazywanie rownania kwadratowego");
				opcje2.push_back("Rozwiazywanie ukladu I stopnia 2 rownan z 2 niewiadomymi");
				opcje2.push_back("Rozwiazywania ukladu I stopnia 3 rownan z 3 niewiadomymi");
				opcje2.push_back("Szukanie pierwiastkow wielomianu dowolnego stopnia");
				opcje2.push_back("Dzielenie wielomianu przez dwumian (schematem hornera)");
				break;
			case 5:		
				opcje2.push_back("Permutacja (silnia)");
				opcje2.push_back("Warjacje bez powtorzen");
				opcje2.push_back("Wariacje z powtorzeniami");
				opcje2.push_back("Kombinacje");
				break;
			case 6:
				opcje2.push_back("n-ty wyraz za pomoca pierwszego wyrazu ciagu i roznicy");
				opcje2.push_back("n-ty wyraz za pomoca sumy czesciowej n pierwszych wyrazow oraz pierwszego wyrazu ciagu");
				opcje2.push_back("Wyraz za pomoca wyrazu poprzedniego i wyrazu nastepnego");
				opcje2.push_back("Suma czesciowa n pierwszych wyrazow");
				opcje2.push_back("n-ty wyraz za pomoca pierwszego wyrazu i ilorazu");
				opcje2.push_back("Wyraz za pomoca wyrazu poprzedniego i wyrazu nastepnego");
				opcje2.push_back("Suma czesciowa n pierwszych wyrazow");
			case 7:
				opcje2.push_back("Sprawdzanie, czy dana liczba jest pierwsza");
				opcje2.push_back("Szukanie wszystkich liczb pierwsze (i ich ilosc) nie wieksze niz podana");
				opcje2.push_back("Szukanie wszystkich dzielnikow danej liczby");
			break;
		}
		unsigned short max_wybor2;
		max_wybor2=opcje2.size();	
		max_wybor2--;
		ktory2=0;
		znak=1;
		for(;;){
			clear();//czysci ekran
			logo();//wyswietla logo
			info(); //wyswietla instrukcje przejsc
			//przejscia pionowe
			if (znak == 259 && ktory2 != min_wybor) ktory2--;
			else if(znak == 258 && ktory2 != max_wybor2) ktory2++;
			else if(znak ==258 && ktory2 == max_wybor2) ktory2 = min_wybor;
			else if(znak ==259 && ktory2 == min_wybor) ktory2 = max_wybor2; 
			//przejscia poziome
			else if(znak == 13 || znak == 261) break;
			else if (znak == 260 || znak == 27){
				ktory2=0;
				break;
			}
			//--------opcje w menu glownym----------
			for(unsigned short i=0; i<=max_wybor; ++i)
				mvprintw(11+i, 4, "%s", opcje[i].c_str());
			attron(A_REVERSE);
			mvprintw(11+ktory, 4, "%s", opcje[ktory].c_str());
			attroff(A_REVERSE);
			//podmenu
			if(ktory==6){//wyjatek dla ciagow
				mvprintw(17, 28, "%s", opcje2[0].c_str());
				attron(A_BOLD);
				mvprintw(18, 28, "Ciag arytmetyczny:");
				attroff(A_BOLD);
				attron(A_BOLD);
				mvprintw(23, 28, "Ciag geometryczny:");
				attroff(A_BOLD);
				for(unsigned short i=1; i<=4; ++i)
					mvprintw(18+i, 28, "%s", opcje2[i].c_str());
				for(unsigned short i=5; i<=7; ++i)
					mvprintw(19+i, 28, "%s", opcje2[i].c_str());			
				attron(A_UNDERLINE | A_BOLD);
				if(ktory2==0) mvprintw(17, 26, "=>");
				else if(ktory2>0 && ktory2<5) mvprintw(18+ktory2, 26, "=>");
				else if(ktory2>4) mvprintw(19+ktory2, 26, "=>");
				attroff(A_UNDERLINE | A_BOLD);
			}
			else{
				for(unsigned short i=0; i<=max_wybor2; ++i)
					mvprintw(11+i+ktory, 28, "%s", opcje2[i].c_str());
				attron(A_UNDERLINE | A_BOLD);
				mvprintw(11+ktory+ktory2, 26, "=>");
				attroff(A_UNDERLINE | A_BOLD);
			}
							//kursr w rog i oczekiwanie na klawisz
			noecho();
			move(0,0);
			refresh();
			znak = getch();
		}
//-------------------------------------------------------------------------------------------------------------
podmenu2:
if( !(
   (ktory == 1 && (ktory2 == 1 || ktory2 == 2 || ktory2 == 4 || ktory2 == 5 || ktory2 == 6))//podmenusy dla planimetrii
   || (ktory == 2 && ktory2 != 0) //podmenu dla stereometrii
   )) break;	
		//ktore podemnu ma byc wyswietlone
		opcje3.clear();
		opcje3.push_back("Powrot do menu glownego");
		if(ktory == 1)//switch dla planimetrii
			switch(ktory2){
				case 1:
					opcje3.push_back("typowy trojkat");
					opcje3.push_back("trojkat rownoboczny");
					opcje3.push_back("trojkat - 3 boki");
					opcje3.push_back("trojkat - 2 boki i kat");
					break;
				case 2:
					opcje3.push_back("typowy kwadrat");
					opcje3.push_back("kwadrat - przekatne");
					break;
				case 4:
					opcje3.push_back("typowy romb");
					opcje3.push_back("romb - kat");
					opcje3.push_back("romb - przekatna");
					break;
				case 5:
					opcje3.push_back("typowy rownoleglobok");
					opcje3.push_back("rownoleglobok - 2 boki i kat");
					opcje3.push_back("rownoleglobok - przekatne i kat");
					break;
				case 6:
					opcje3.push_back("trapez - obie podstawy i wysokosc");
					opcje3.push_back("trapez rownoramienny - wysokosc, ramie i krotsza podstawa");
					opcje3.push_back("trapez rownoramienny - ramie i obie podstawy");
					opcje3.push_back("trapez rownoramienny - kat ostry, ramie i krotsza podstawa");
					opcje3.push_back("trapez rownoramienny - kat ostry, wysokosc i krotsza podstawa");
					opcje3.push_back("trapez prostokatny - kat ostry, wysokosc i krotsza podstawa");
					opcje3.push_back("trapez prostokatny - kat ostry, ramie i krotsza podstawa");
					opcje3.push_back("trapez prostokatny - obie podstawy i dluzsza przekatna");
					opcje3.push_back("trapez prostokatny - obie podstawy i krotsza przekatna");
					break;
		}
		if(ktory == 2)//switch dla stereometrii
			switch(ktory2){
				case 1:
					opcje3.push_back("szescian");
					opcje3.push_back("prostopadloscian");
					opcje3.push_back("prosty trojkatny");
					opcje3.push_back("prawidlowy trojkatny");
					opcje3.push_back("prawidlowy czworokatny");
					opcje3.push_back("prosty czworokatny");
					opcje3.push_back("prawidlowy szesciokatny");
					break;
				case 2:
					opcje3.push_back("czworoscian");
					opcje3.push_back("trojkatny");
					opcje3.push_back("prawidlowy trojkatny");	
					opcje3.push_back("czworokatny");
					opcje3.push_back("prawidlowy czworokatny");
					opcje3.push_back("prawidlowy szesciokatny");
					break;
				case 3:
					opcje3.push_back("Walec");
					opcje3.push_back("Stozek");	
					opcje3.push_back("Kula");	
					break;
			}
		unsigned short max_wybor3;
		max_wybor3=opcje3.size();	
		max_wybor3--;
		ktory3=0;
		znak=1;
		for(;;){
			clear();//czysci ekran
			logo();//wyswietla logo
			info(); //wyswietla instrukcje przejsc
			//przejscia pionowe
			if (znak == 259 && ktory3 != min_wybor) ktory3--;
			else if(znak == 258 && ktory3 != max_wybor3) ktory3++;
			else if(znak ==258 && ktory3 == max_wybor3) ktory3 = min_wybor;
			else if(znak ==259 && ktory3 == min_wybor) ktory3 = max_wybor3; 
			//przejscia poziome
			else if(znak == 13 || znak==261) break;
			else if (znak == 260 || znak == 27)
				goto podmenu1; //poowrot do pierwszego podmenu
			//--------opcje w menu glownym----------
			for(unsigned short i=0; i<=max_wybor; ++i)
				mvprintw(11+i, 4, "%s", opcje[i].c_str());
			attron(A_REVERSE);
			mvprintw(11+ktory, 4, "%s", opcje[ktory].c_str());
			attroff(A_REVERSE);
			//pierwsze podmenu
			for(unsigned short i=0; i<=max_wybor2; ++i)
				mvprintw(11+i+ktory, 28, "%s", opcje2[i].c_str());
			attron(A_REVERSE);
			mvprintw(11+ktory+ktory2, 28, "%s", opcje2[ktory2].c_str());
			attroff(A_REVERSE);
			//2 podmenu
			for(unsigned short i=0; i<=max_wybor3; ++i)
				mvprintw(11+i+ktory+ktory2, 54, opcje3[i].c_str());
			attron(A_UNDERLINE | A_BOLD);
			mvprintw(11+ktory+ktory2+ktory3, 52, "=>");
			attroff(A_UNDERLINE | A_BOLD);
			//kursr w rog i oczekiwanie na klawisz
			noecho();
			move(0,0);
			refresh();
			znak = getch();
		}

//-------------------------------------------------------------------------------------------------
if( !(
(ktory == 2 && ktory2 == 1 && ktory3 == 3) //podmenu3 dla roznych graniastoslupow trojkatnych
   )) break;	
		//ktore podemnu ma byc wyswietlone
		opcje4.clear();
		opcje4.push_back("Powrot do menu glownego");
		switch(ktory3){
			case 3:
				opcje4.push_back("Wysokosc, bok i wysokosc podstawy");
				opcje4.push_back("Wysokosc, 2 boki podstawy i kat miedzy nimi");
				opcje4.push_back("Wysokosc i 3 boki podstawy");
				opcje4.push_back("Wysokosc i pole powierzchni podstawy");
				break;
		}
		unsigned short max_wybor4;
		max_wybor4=opcje4.size();	
		max_wybor4--;
		ktory4=0;
		znak=1;
		for(;;){
			clear();//czysci ekran
			logo();//wyswietla logo
			info(); //wyswietla instrukcje przejsc
			//przejscia pionowe
			if (znak == 259 && ktory4 != min_wybor) ktory4--;
			else if(znak == 258 && ktory4 != max_wybor4) ktory4++;
			else if(znak ==258 && ktory4 == max_wybor4) ktory4 = min_wybor;
			else if(znak ==259 && ktory4 == min_wybor) ktory4 = max_wybor4; 
			//przejscia poziome
			else if(znak == 13 || znak==261) break;
			else if (znak == 260 || znak == 27)//{
				goto podmenu2; //poowrot do drugiego podmenu
			//--------opcje w menu glownym----------
			for(unsigned short i=0; i<=max_wybor; ++i)
				mvprintw(11+i, 4, "%s", opcje[i].c_str());
			attron(A_REVERSE);
			mvprintw(11+ktory, 4, "%s", opcje[ktory].c_str());
			attroff(A_REVERSE);
			//pierwsze podmenu
			for(unsigned short i=0; i<=max_wybor2; ++i)
				mvprintw(11+i+ktory, 28, "%s", opcje2[i].c_str());
			attron(A_REVERSE);
			mvprintw(11+ktory+ktory2, 28, "%s", opcje2[ktory2].c_str());
			attroff(A_REVERSE);
			//2 podmenu
			for(unsigned short i=0; i<=max_wybor3; ++i)
				mvprintw(11+i+ktory+ktory2, 54, "%s", opcje3[i].c_str());
			attron(A_REVERSE);
			mvprintw(11+ktory+ktory2+ktory3, 54, "%s", opcje3[ktory3].c_str());
			attroff(A_REVERSE);
			//3 podmenu
			for(unsigned short i=0; i<=max_wybor4; ++i)
				mvprintw(11+i+ktory+ktory2+ktory3, 82, opcje4[i].c_str());
			attron(A_UNDERLINE | A_BOLD);
			mvprintw(11+ktory+ktory2+ktory3+ktory4, 80, "=>");
			attroff(A_UNDERLINE | A_BOLD);

			//kursr w rog i oczekiwanie na klawisz
			noecho();
			move(0,0);
			refresh();
			znak = getch();
		}
	break;//koniec nieskonczonej petli po jednym obrocie
	}	
}
