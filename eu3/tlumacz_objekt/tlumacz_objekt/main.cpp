/*
 * T³umacz - program s³u¿¹cy do t³umaczenia plików .CSV w EU3
 * Wersja objektowa ;)
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

	if(sNazwa_pliku == "ERR"){//brak plików .csv
		clear();
		border('|', '|', '-', '-', '+', '+', '+', '+');
		mvprintw(10, 10, "W folderze release nie znajduje sie zaden plik .csv!");
		mvprintw(12, 10, "Nastapi zakonczenie programu po nacisnieciu klawisza.");
		refresh();
		getch();
		return 0;
	}
	std::vector<std::string> vGra;
	vGra.push_back("Wybierz grê z której pochodzi ten plik.");
	vGra.push_back("Je¿eli na liœcie nie ma tej gry proszê o kontakt na konserw@gmail.com");
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
		cerr << ++licznik << ". obrót pêtli" << std::endl;
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




