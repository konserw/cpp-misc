/*
 * Edytor save dla EU3 by konserw
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

#include "stdafx.h"
//#include "header.h"
//#include "menu.h"


int main(){

	init(40, 80);//25 bez paska
	//zmienne
	std::string path, buff, linie, tag, nazwa;
	size_t indeks;
	const short int min_wybor = 0;
	unsigned short max_wybor, ktory = 0, gdzie, y_max, x_max;
	bool exit = false;
	char znak;
	WINDOW* wPasek;
	WINDOW* wDol;
	std::vector<std::string> popcje;

	//powitanie
	short x=4, y=6;
	border();
	attron(COLOR_PAIR(2));
	mvprintw(y++, x+20, "EU3 Save Editor v 0.5");
	attroff(COLOR_PAIR(2));
	mvprintw(++y, x+4, "Witam w edytorze sejwow dla EU3 mojego autorstwa.");
	mvprintw(++y, x, "Na razie mozna zmienic jedynie ustawienia poczatkowe, flagi i var.");
	//mvprintw(++y, x, "lecz mam nadzieje ze z Wasza pomoca uda mi sie rozwinac ten projekt.");
	//mvprintw(++y, x, "Ta wersja powinna dzialac o niebo szybciej (dzieki ludziom z programuj.com)");
	//mvprintw(++y, x, "Radze wykonac kopie zapasowa edytowanych save");
	mvprintw(++y, x, "Program rozprowadzany na podstawie GNU GPL.");
	mvprintw(++y, x, "Mam nadzieje, ze sie przyda!");
	mvprintw(y+2, x + 40, "Pozdrawiam, konserw.");
	cont();

	if(!(sciezka(path))){
		log("main", "sciezka error");
		error();
		return 0;
	}

	wybor_moda(path);

	if(!(wybor_save(path))){
		log("main", "wybor save error");
		error();
		return 0;
	}

	if(!(load(path, linie, indeks))){
		log("main", "load error");
		error();
		return 0;
	}

/*
###############################
###		W³aœciwy edytor		###
###############################
*/	
	logline();
	log("main", "Pocz¹tek w³aœciwego edytora");

	resize_term(51, 80);
	clear();

	getmaxyx(stdscr, y_max, x_max);
	log("main", "Przewymiarowano terminal");
	log("main", "max y", y_max);
	log("main", "max x", x_max);

	nazwa = path.substr(path.find_last_of('\\')+1, std::string::npos);
	log("main", "Wybrany save", nazwa.c_str());
	nazwa += "\tkraj: ";
	//nazwa += tag;
	tag = linie.substr(indeks, 3);
	mvprintw(5, (x_max - nazwa.size() -3)/2, "%s%s", nazwa.c_str(), tag.c_str());

	wPasek = subwin(stdscr, 5, 80, 0, 0);
	wDol = subwin(stdscr, 45, 80, 6, 0);

	pfun funkcje[] = { 
		data,
		ustawienia,
		flagi,
		wybor_tag,
//		kraj,

		save,
		//licencja,
		//wyjscie,
		0      // wartownik koñca tablicy aby ³atwo by³o wklejaæ powy¿ej wiersze 
	}; 

	popcje.push_back("Data");
	popcje.push_back("Opcje");
	popcje.push_back("Flagi");
	popcje.push_back("TAG");
	popcje.push_back("Kraj");

	/*dalsze opcje, które bêdê dodawa³*/	
	popcje.push_back("Zapis");
	popcje.push_back("Licencja");
	popcje.push_back("Wyjscie");
	max_wybor = popcje.size() -1;

	for(;;){
		border(wPasek);
		border(wDol);

		wmove(wPasek, 2, 4);
		for(unsigned i=0; i < popcje.size(); ++i)
			//mvwprintw(wPasek, 2, 10 + (i*10), "%s", popcje[i].c_str());
			wprintw(wPasek, "%s    ", popcje[i].c_str());

		gdzie = 4 * (ktory +1); //na poczatek wszystkie taby
		for(short i=0; i < ktory; ++i) gdzie += popcje[i].size();


		wattron(wPasek, COLOR_PAIR(2));
		mvwprintw(wPasek, 2, gdzie, "%s", popcje[ktory].c_str());
		wattroff(wPasek, COLOR_PAIR(2));

		wrefresh(wPasek);
		noecho();
		znak = getch();

		if (znak == 4){
			if(ktory != min_wybor) ktory--;
			else if(ktory == min_wybor) ktory = max_wybor;
		}
		else if(znak == 5){
			if(ktory != max_wybor) ktory++;
			else if(ktory == max_wybor) ktory = min_wybor;
		}
		else if(znak == 13){//enter
			if(ktory == max_wybor-1)system("licencja.htm");
			else if(ktory == max_wybor)exit = true;

			else funkcje[ktory](linie, wDol, path, indeks);

			if(ktory == 3){// zmiana tag
				tag = linie.substr(indeks, 3);
				mvprintw(5, (x_max-nazwa.size()-3)/2, "%s%s", nazwa.c_str(), tag.c_str());
				log("main", "aktualny tag", tag.c_str());
			}
		}
		if(exit == true)break;
	}

	//pozegnanie
	y=5; x=4;
	delwin(wDol);
	delwin(wPasek);
	border();
	mvprintw(y++, x+20, "Koniec");
	mvprintw(++y, x, "Mam nadzieje ze program spisal sie dobrze.");
	mvprintw(++y, x, "Przebieg pracy mozna sprawdzic w pliku error.log");
	mvprintw(++y, x, "Podziekowania naleza sie Paradygmatowi, za jego tutorial edycji save");
	mvprintw(++y, x, "Oraz ludziom z forum.programuj.com za nieoceniona pomoc");
	mvprintw(++y, x, "I to nie tylko przy tym projekcie");
	mvprintw(++++y, x+35, "Pozdrawiam, konserw");
	cont();
	endwin();
	log("main", "koniec programu");
	return 0;
}

