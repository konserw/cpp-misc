/*
 * no time limit patch 4 EU III by konserw
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
#include "menu.h"
#include "header.h"


int main()
{
	init();
	bool out = false;
	std::string path;
	sData dat;
	unsigned ile;
	std::vector<std::string> opcje;

	if(!sciezka(path)){
		error();
		return 0;
	}

	border();
	mvprintw(5, 25, "Witam w NoTimeLimitPatch dla EU3!");
	mvprintw(10, 10, "Zalecana jest gra na ustawieniach domyslnych");
	mvprintw(11, 10, "Wykryta wersja gry:\t");
	attron(COLOR_PAIR(2));
	if(ver == in) printw("In Nomine 3.2");
	else if(ver == h3t) printw("Heir to the Throne");
	attroff(COLOR_PAIR(2));
	mvprintw(12, 10, "W razie wszelkich watliwosci zapraszam na www.eufi.org");
	cont();

	opcje.push_back("Zmiana daty poczatku gry");
	opcje.push_back("Zmiana daty konca gry");
	opcje.push_back("Dodawanie poziomow technologii");
	opcje.push_back("Licencja");
	opcje.push_back("Wyjscie");

	cMenu menu(opcje);
	

	wybor_moda(path);

	while(!out){
		switch(menu.wybor()){
			case 0:
				border();
				echo();
				mvprintw(10, 10, "Podaj rok w ktorym chcesz rozpoczynac rozgrywke:\t");
				scanw("%u", &dat.yy);
				mvprintw(12, 10, "Podaj miesiac w ktorym chcesz rozpoczynac rozgrywke:\t");
				scanw("%u", &dat.mm);
				mvprintw(14, 10, "Podaj dzien w ktorym chcesz rozpoczynac rozgrywke:\t");
				scanw("%u", &dat.dd);
				if(data(path, dat, 0)){
					border();
					mvprintw(10, 10, "Zmiana daty zakonczone pomyslnie!");
					cont();
				}
				else{
					border();
					mvprintw(10, 10, "Wystapil blad!");
					mvprintw(12, 10, "zajrzyj do pliku error.log w katalogu release");
					cont();
				}	
				break;
			case 1:
				border();
				echo();
				mvprintw(10, 10, "Podaj rok w ktorym chcesz zakonczyc rozgrywke:\t");
				scanw("%u", &dat.yy);
				mvprintw(12, 10, "Podaj miesiac w ktorym chcesz zakonczyc rozgrywke:\t");
				scanw("%u", &dat.mm);
				mvprintw(14, 10, "Podaj dzien w ktorym chcesz zakonczyc rozgrywke:\t");
				scanw("%u", &dat.dd);
				if(data(path, dat, 1)){
					border();
					mvprintw(10, 10, "Zmiana daty zakonczone pomyslnie!");
					cont();
				}
				else{
					border();
					mvprintw(10, 10, "Wystapil blad!");
					mvprintw(12, 10, "zajrzyj do pliku error.log w katalogu release");
					cont();
				}	
				break;
			case 2:
				border();
				echo();
				mvprintw(10, 10, "Do ktorego poziomu maja zostac wygenerowane technologie:\t");
				scanw("%u", &ile);
				if(techy(ile, path)){
					border();
					mvprintw(10, 10, "Dodawania technologi zakonczone pomyslnie!");
					cont();
				}
				else{
					border();
					mvprintw(10, 10, "Wystapil blad!");
					mvprintw(12, 10, "zajrzyj do pliku error.log w katalogu release");
					cont();
				}				
				break;				
			case 3:
				system("licencja.htm");
				break;
			case 4:
				out = true;
				break;
		}
	}
	border();
	mvprintw(10, 10, "Dziekuje za skorzystanie z mojego programu");
	mvprintw(12, 10, "Zapraszam na najlepsze forum o strategiach WayOfWar.org");
	mvprintw(14, 10, "pozdrawiam i zycze milej zabawy, konserw");
	cont();
	endwin();
	return 0;
}

