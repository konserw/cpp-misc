/*
 * Kalkulator w curses
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
//#include <stdlib.h>
#include <curses.h>
#include <vector>
#include <string>

//dzialania:
double dodawanie ( double a, double b ){
return ( a + b );}
double odejmowanie ( double a, double b ){
return ( a - b );}
double mnozenie ( double a, double b ){
return ( a * b );}
double dzielenie ( double a, double b ){
if (b != 0) return ( static_cast<double>(a) / b );
else return 0;}

//prototypy:
unsigned short menu();

int main()
{
	double a, b;
	int key;
	bool end = false;
	int g;

	//inicjacja okna curses i klawiatury
	initscr();  
	keypad(stdscr, true);
	raw();

	//graficzne bajerki 
	if(has_colors() == TRUE) start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    bkgd(COLOR_PAIR(1));	attron(COLOR_PAIR(1));	attron(A_BOLD);
	border(0, 0, 0, 0, 0, 0, 0, 0);

	while(!end){
		clear();
		mvprintw(9, 10, "Podaj liczbe na ktorej chcesz wykonac dzialanie\t");
		g = scanw("%lf", &a); //wczytujemy pierwsza liczbe
		if(g != 1){ //obsluga blednego wpisu
			mvprintw(12, 10, "Nieprawidlowy format danych!");
			noecho();
			getch();
			echo();
			continue;
		}

		switch(menu()){
			case 0:
				end = true;
				break;
			case 1:
				clear();
				mvprintw(10, 10, "Podaj droga liczbe\t");
				g = scanw("%lf", &b); //wczytujemy droga liczbe
				if(g != 1){ //obsluga blednego wpisu
					mvprintw(12, 10, "Nieprawidlowy format danych!");
					break;
				}
				mvprintw(12, 10, "Wynik: %lf", dodawanie(a, b));
				break;
			case 2:
				clear();
				mvprintw(10, 10, "Podaj droga liczbe\t");
				g = scanw("%lf", &b); //wczytujemy droga liczbe
				if(g != 1){ //obsluga blednego wpisu
					mvprintw(12, 10, "Nieprawidlowy format danych!");
					break;
				}
				mvprintw(12, 10, "Wynik: %lf", odejmowanie(a, b));
				break;
			case 3:
				clear();
				mvprintw(10, 10, "Podaj droga liczbe\t");
				g = scanw("%lf", &b); //wczytujemy droga liczbe
				if(g != 1){ //obsluga blednego wpisu
					mvprintw(12, 10, "Nieprawidlowy format danych!");
					break;
				}
				mvprintw(12, 10, "Wynik: %lf", mnozenie(a, b));
				break;
			case 4:
				clear();
				mvprintw(10, 10, "Podaj droga liczbe\t");
				g = scanw("%lf", &b); //wczytujemy droga liczbe
				if(g != 1){ //obsluga blednego wpisu
					mvprintw(12, 10, "Nieprawidlowy format danych!");
					break;
				}
				if((dzielenie(a, b) == 0) && a != 0){
					mvprintw(12, 10, "Wynikiem dzielenia przez 0 jest symbol nieoznaczony");
					break;
				}
				mvprintw(12, 10, "Wynik: %lf", dzielenie(a, b));
				break;
			case 5:
				system("licencja.htm");
				break;
		}
		if (end) break;
		mvprintw(15, 10, "nacisnij ESC aby zakonczyc");
		refresh();
		noecho();
		move(0, 0);
		key = getch();
		echo();
		if(key == 27) end = true;
	}
	return 0;
}

void info(){
	mvprintw(3, 10, "Wybierz dzialanie:");
	attroff(A_BOLD);
	mvprintw(10, 95, "Strzalki w gore i w dol - kursor");
	mvprintw(11, 95, "Enter lub => - wybor");
	attron(A_BOLD);
}

unsigned short menu(){
	std::vector<std::string> opcje;
	int znak=1;
	const short int min_wybor = 0;
	short int max_wybor;
	unsigned short ktory = 0;

	//opcje w menu glownym
	opcje.push_back("Zakonczenie programu");
	opcje.push_back("Dodawanie");
	opcje.push_back("Odejmowanie");
	opcje.push_back("Mnozenie");
	opcje.push_back("Dzielenie");
	opcje.push_back("Licencja");
	
	max_wybor=opcje.size();//maxymalny wybor rowny ilosci opcji
	max_wybor--;//-1 bo od zera
	for(;;){
		clear();//czysci ekran
		//przejscia pionowe
		if (znak == 259 && ktory != min_wybor) ktory--;
		else if(znak == 258 && ktory != max_wybor) ktory++;
		else if(znak ==258 && ktory == max_wybor) ktory = min_wybor;
		else if(znak ==259 && ktory == min_wybor) ktory = max_wybor; 
		
		else if(znak == 13 || znak==261)//strzalka lub enter koncza petle
			return ktory;

		info();//wyswietlamy instrukcje uzytkowania
		//--------opcje w menu----------
		for(unsigned short i=0; i<=max_wybor; ++i)
			mvprintw(5+i, 4, "%s", opcje[i].c_str());
		//----------kursor---------

		mvprintw(5+ktory, 2, "=>");

		//---------kursr w rog i oczekiwanie na klawisz
		noecho();
		move(0,0);
		refresh();
		znak = getch();
		echo();
	}
}