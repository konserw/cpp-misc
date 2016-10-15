/*
 * automat z napojami
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
#include "header.h"

unsigned short menu();
double wrzuc();
bool control(std::vector<cNapoj> napoje);
void kupione(std::vector<cNapoj> napoje);

int main()
{
	bool out = false;
	double coin = 0;
	double buff;

	//inicjacja okna curses i klawiatury
	initscr();  
	keypad(stdscr, true);
	raw();
	resize_term(25, 75);
	noecho();

	//graficzne bajerki 
	if(has_colors() == TRUE) start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    bkgd(COLOR_PAIR(1));	attron(COLOR_PAIR(1));	attron(A_BOLD);
	border(0, 0, 0, 0, 0, 0, 0, 0);

	std::vector<cNapoj> napoje; //wektor przechowujacy kupione napoje

	for(;;){
		coin = 0;

		if(control(napoje)) break;
		
		cNapoj nowy(menu()); // tworzymy nowy obiekt npoju
		clear();
		mvprintw(3, 5, "Wybrany napoj: %s", nowy.nazwa.c_str());
		mvprintw(7, 10, "Wrzuc %.2lf", nowy.cena);
		for(;;){
			buff = wrzuc();
			if (buff != -1){
				coin = buff;
				break;
			}
		}
		while(coin < nowy.cena){
			clear();
			mvprintw(3, 5, "Wybrany napoj: %s", nowy.nazwa.c_str());
			mvprintw(5, 10, "Narazie wrzuciles %.2lf, brakuje %.2lf", coin, nowy.cena - coin);
			move(7, 15);
			buff = wrzuc();
			if( buff != -1) //o ile wrzucono monete (odpowiedni klawisz zostal wcisniety)
				coin += buff; //dodajemy dorzucona kasê
		}
		clear();
		mvprintw(5, 10, "Wrzuciles %.2lf, napoj kosztowal %.2lf", coin, nowy.cena);
		mvprintw(7, 10, "Twoja reszta: %.2lf", coin - nowy.cena);
		napoje.push_back(nowy); //zaplacono wiec mamy upragniony napoj w reku (plecaku)
		kupione(napoje); //wyswietlamy kupione napoje
	}
	return 0;
}

unsigned short menu(){
	std::vector<std::string> opcje;
	int znak=1;
	const short int min_wybor = 0;
	short int max_wybor;
	unsigned short ktory = 0;

	//opcje w menu glownym
	opcje.push_back("Pepsi\t2.50");
	opcje.push_back("Mirinda\t2.00");
	opcje.push_back("Coca - cola\t4.00");
	opcje.push_back("Sprite\t2.00");
	
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

		//--------opcje w menu----------
		for(unsigned short i=0; i<=max_wybor; ++i)
			mvprintw(5+i, 4, "%s", opcje[i].c_str());

		//----------kursor---------
		mvprintw(5+ktory, 2, "=>");

		//---------kursr w rog i oczekiwanie na klawisz
		move(0,0);
		refresh();
		znak = getch();
	}
}

double wrzuc(){
	mvprintw(19, 2, "WRZUC MONETE: F1: 10 gr\tF2: 50 gr\tF3: 1 zl\tF4: 2 zl");
	move(9, 15);

	switch (getch()){
		case 265:
			return 0.1;
		case 266:
			return 0.5;
		case 267:
			return 1.0;
		case 268:
			return 2.0;
		default:
			return -1; //zwraca -1 jezeli zostal nacisniety nieodpowiedni klawisz
	}
}

bool control(std::vector<cNapoj> napoje){
	std::vector<std::string> opcje;
	int znak=1;
	const short int min_wybor = 0;
	short int max_wybor;
	unsigned short ktory = 0;

	//opcje w menu glownym
	opcje.push_back("Kup cos w automacie");
	opcje.push_back("Przejzyj kupione napoje");
	opcje.push_back("Wyswietl licencje");
	opcje.push_back("Wyjscie");
	
	max_wybor=opcje.size();//maxymalny wybor rowny ilosci opcji
	max_wybor--;//-1 bo od zera

	for(;;){
		znak = 1;
		for(;;){
			clear();//czysci ekran
			//przejscia pionowe
			if (znak == 259 && ktory != min_wybor) ktory--;
			else if(znak == 258 && ktory != max_wybor) ktory++;
			else if(znak ==258 && ktory == max_wybor) ktory = min_wybor;
			else if(znak ==259 && ktory == min_wybor) ktory = max_wybor; 
			
			else if(znak == 13 || znak==261)//strzalka lub enter koncza petle
				break;

			//--------opcje w menu----------
			for(unsigned short i=0; i<=max_wybor; ++i)
				mvprintw(5+i, 4, "%s", opcje[i].c_str());

			//----------kursor---------
			mvprintw(5+ktory, 2, "=>");

			//---------kursr w rog i oczekiwanie na klawisz
			move(0,0);
			refresh();
			znak = getch();
		}

		switch(ktory){
			case 0:
				return false;
				break;
			case 1:
				kupione(napoje);
				break;
			case 2:
				system("licencja.htm");
				break;
			case 3:
				return true;
		}
	}
}

void kupione(std::vector<cNapoj> napoje){
	mvprintw(9, 10, "Kupione napoje:");
	move(11, 1);
	for(unsigned i = 0; i < napoje.size(); ++i)
		printw("%s; ", napoje[i].nazwa.c_str());
	getch();
}

