/*
 * T�umacz - program s�u��cy do t�umaczenia plik�w .CSV w EU3
 * Wersja objektowa ;)
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

std::ofstream cerr("error.log");
eJaka_gra sGra;

int main(){
	system("CHCP 1250");//kodowanie windowsowe

	char cZnak;
	unsigned uWers;
	std::string sNazwa_pliku;

	//aktywacja curses
	initscr();  
	keypad(stdscr, true);
	raw();
	if(has_colors() == TRUE) start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    wbkgd(stdscr, COLOR_PAIR(1));
	attron(COLOR_PAIR(1));
	attron(A_BOLD);

	sNazwa_pliku = wybor_pliku();
	cerr << "wybrany plik:\t" << sNazwa_pliku << std::endl;

	if(sNazwa_pliku == "ERR"){//brak plik�w .csv
		clear();
		border('|', '|', '-', '-', '+', '+', '+', '+');
		mvprintw(10, 10, "W folderze release nie znajduje sie zaden plik .csv!");
		mvprintw(12, 10, "Nastapi zakonczenie programu po nacisnieciu klawisza.");
		refresh();
		getch();
		return 0;
	}
	std::vector<std::string> vGra;
	vGra.push_back("Wybierz gr� z kt�rej pochodzi ten plik.");
	vGra.push_back("Je�eli na li�cie nie ma tej gry prosz� o kontakt na konserw@gmail.com");
	std::vector<std::string> vGra_opcje;
	vGra_opcje.push_back("Europa Universalis III");
	vGra_opcje.push_back("Hearts of Iron II");
	cMenu mGra(vGra_opcje, stdscr);
	
	sGra = static_cast<eJaka_gra>(mGra.wybor(10, 10, vGra));
	cerr << "wybrana gra:\t" << sGra << std::endl;

	std::vector<cWers> vWersy;
	wczyt(sNazwa_pliku, vWersy);

	clear();
	resize_term(55, 155);
	border('|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(stdscr);
	cOkno oTop(4, 5);
	cEdytor oEdytor(4, 30);
	uWers = 0;

	unsigned long licznik=0;
	for(;;){
		cerr << ++licznik << ". obr�t p�tli" << std::endl;
		oTop.wyswietl(vWersy[uWers].eng());
		oEdytor.wyswietl(vWersy[uWers].pol());
		//refresh();
		
		


		noecho();
		cZnak = getch();
		if(cZnak == 27)break;//esc
	}









	cerr << "zakonczenie programu" << std::endl;
	cerr.close();
	endwin();
	return 0;
}




