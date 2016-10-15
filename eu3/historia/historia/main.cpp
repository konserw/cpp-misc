/*
 * historia - program do grzebania w plikach historii EU3
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
#include "menu.h"
#include "header.h"



int main()
{
	log();//czyszczenie loga przed rozpocz�ciem programu
	log("main", "Rozpoczecie programu");

	std::vector<std::string> pliki, opis, opcje, nowe_pliki;
	char cExit = 't';


	//aktywacja curses
	initscr();  
	keypad(stdscr, true);
	raw();
	resize_term(25, 70);
	if(has_colors() == TRUE){
		start_color();
		init_pair(1, COLOR_WHITE, COLOR_BLUE);
		wbkgd(stdscr, COLOR_PAIR(1));
		attron(COLOR_PAIR(1));
	}
	attron(A_BOLD);
	noecho();
	log("main", "curses aktywne");

	border('|', '|', '-', '-', '+', '+', '+', '+');
	short s = 8;
	mvprintw(s++, 10, "Witam w edytorze plikow historii!");
	mvprintw(s++, 10, "Pliki ktore chcesz edytowac powinny sie znajdowac");
	mvprintw(s++, 10, "w folderze >provinces< w katalogu programu");
	mvprintw(s++, 10, "Przy wpisywaniu ulamkow nalezy uzywac KROPKI");
	mvprintw(s++, 10, "Milej zabawy, pozdrawiam, konserw");
	attroff(A_BOLD);
	mvprintw(15, 15, "Aby kontynuowac nacisnij dowolny klawisz");
	attron(A_BOLD);
	refresh();
	getch();

	log("main", "Po wstepie");
	loading();

	find_files(pliki);
	log("main", "Znalezionych plikow", pliki.size());

	opis.push_back("Ktore prowy chcesz zmienic?");
	opcje.push_back("Wszystkie");
	opcje.push_back("Wybranego kraju (TAG)");
	opcje.push_back("O wybranej kulturze");
	opcje.push_back("Nalezace do HRE");
	opcje.push_back("[Licencja]");
	opcje.push_back("[Wyjscie]");
	cMenu mFiltr(opis, opcje);

	opis.push_back("Wybierz co chcesz zmienic:");
	opcje.push_back("Wroc");
	opcje.push_back("Populacje");
	opcje.push_back("Manopwer");
	opcje.push_back("Base tax");
	cMenu mZmiana(opis, opcje);

	opis.push_back("Chcesz pomnozyc czy dodac?");
	opcje.push_back("Pomnozyc");
	opcje.push_back("Dodac");
	cMenu mDod(opis, opcje);

	unsigned short tmp;
	do{
		tmp = mFiltr.wybor(8, 10);
		if(tmp == 4){
			log("main", "licencja");
			system("Licencja.htm");
			continue;
		}
		if(tmp == 5){
			log("main", "exit");
			break;
		}
		ktore_pliki(tmp, pliki, nowe_pliki);
		std::vector<cProv> provy;
		//provy.clear();
		bool dodaj;
		float ile;

		unsigned short uZmiana = mZmiana.wybor(8, 10);
		if(uZmiana == 0){
			log("main", "wbrano wr��");
			continue;
		}
		std::vector<std::string> vZmiana;
		vZmiana.push_back("wroc");
		vZmiana.push_back("population");
		vZmiana.push_back("manpower");
		vZmiana.push_back("base_tax");

		echo();
		log("main", "wybrano", vZmiana[uZmiana].c_str());
		if(mDod.wybor(10, 10) == 1){
			dodaj = true;
			mvprintw(15, 10, "Ilosc do dodania:\t");
			scanw("%f", &ile);
		}
		else{
			dodaj = false;
			mvprintw(15, 10, "Przez jaka liczbe chcesz pomnozyc?\t");
			scanw("%f", &ile);
		}
		noecho();
		log("main", "Wybrano parametry");

		loading();
		for(unsigned long i=0; i < nowe_pliki.size(); ++i){
			cProv prov(nowe_pliki[i]);
			provy.push_back(prov);
		}

		for(unsigned long i=0; i < provy.size(); ++i){
			log("main", "Przetwa�anie prova", i);
			provy[i].zmien(vZmiana[uZmiana], dodaj, ile);
		}

//---------- Ko�c�wka programu --------------
		for(;;){
			clear();
			border('|', '|', '-', '-', '+', '+', '+', '+');
			mvprintw(10, 20, "Zakonczyc program? [T/N]");
			refresh();
			cExit = getch();
			if(cExit == 'N' || cExit == 'T' || cExit == 'n' || cExit == 't')break;
		}
		if(cExit == 't' || cExit == 'T') log("main", "czy wyj�� = tak");
		else log("main", "czy wyjsc = nie\n\n\n===================== Nowa P�tla ===================\n\n");
	}while(cExit == 'N' || cExit == 'n');

	endwin();
	log("main", "Koniec programu");
	return 0;
}