/*
 * T³umacz - program s³u¿¹cy do t³umaczenia plików .CSV w EU3
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

std::vector<std::string> eng;
std::vector<std::string> desc;
std::vector<std::string> v_pol;
std::vector<char> hasz;

bool zapis(std::string);
bool wczyt(std::string);
int main(){

	system("CHCP 1250");
	
	bool czy_menu = false, exit = false, enter = false;
	std::string pol, nazwa_pliku;
	char znak;
	const short int min_wybor = 0;
	unsigned short max_wybor;
	unsigned short ktory = 0;
    char path[255]; 
	unsigned i;

	initscr();  
	keypad(stdscr, true);
	raw();

	if(has_colors() == TRUE) start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    bkgd(COLOR_PAIR(1));
	attron(COLOR_PAIR(1));	attron(A_BOLD);

TOP:
	clear();
	v_pol.clear();
	eng.clear();
	desc.clear();
	i = 0;
	ktory = 0;

	border('|', '|', '-', '-', '+', '+', '+', '+');

    WIN32_FIND_DATAA wfd; 
    std::vector<std::string> pliki; 
	std::vector<std::string> csv;

    GetModuleFileNameA(NULL, path, sizeof(path)); 
    int pos = std::string(path).find_last_of("\\"); 
    path[pos + 1] = '*'; 
    path[pos + 2] = 0; 

    HANDLE uchwyt = FindFirstFileA(path, &wfd); 
    if (uchwyt != INVALID_HANDLE_VALUE) 
    { 
        do 
            pliki.push_back(static_cast<std::string>(wfd.cFileName)); 
        while (FindNextFileA(uchwyt, &wfd)); 
        FindClose(uchwyt); 
    } 
	for(unsigned j = 0; j < pliki.size(); ++j)
		if(pliki[j].find(".csv") != std::string::npos || pliki[j].find(".CSV") != std::string::npos)
			csv.push_back(pliki[j]);

	if(csv.size() == 0){
		mvprintw(10, 10, "W folderze release nie znajduje sie zaden plik .csv!");
		mvprintw(12, 10, "Nastapi zakonczenie programu po nacisnieciu klawisza.");
		refresh();
		getch();
		endwin();
		return 0;
	}

	max_wybor = csv.size()-1;

	for(;;){
		clear();
		mvprintw(5, 10, "Witaj w programie do tlumaczenia plikow .CSV z EU3!");
		mvprintw(7, 10, "Wybierz plik z lokalizacja:");
		for(unsigned j = 0; j < csv.size(); ++j) mvprintw(9+j, 5, "%s", csv[j].c_str()); 
		mvprintw(9+ktory, 2, "=>");
		wmove(stdscr, 0, 0);
        refresh(); 
        znak = getch();
		if (znak == 3 && ktory != min_wybor) ktory--;
		else if(znak == 2 && ktory != max_wybor) ktory++;
		else if(znak ==2 && ktory == max_wybor) ktory = min_wybor;
		else if(znak ==3 && ktory == min_wybor) ktory = max_wybor; 
		else if(znak == 13)	break;
	}
	nazwa_pliku = csv[ktory];

	if(wczyt(nazwa_pliku)){

		resize_term(55, 155);
		
		WINDOW * www = subwin (stdscr, 22, 102, 5, 4);

		WINDOW * w_eng = subwin (stdscr, 20, 100, 6, 5);

		WINDOW * ww = subwin (stdscr, 22, 102, 30, 4);

		WINDOW * w_pl = subwin (stdscr, 20, 100, 31, 5);		

		WINDOW * prawa_ramka = subwin (stdscr, 20, 40, 10, 110);

		WINDOW * prawa = subwin (stdscr, 18, 38, 11, 111);
		
		unsigned long i = 0;
		std::vector<std::string> opcje;
		//opcje w menu 
		
		opcje.push_back("Nastepny (enter / =>)");
		opcje.push_back("Poprzedni (<=)");
		opcje.push_back("Usun tekst (shift + del)");
		opcje.push_back("Wklej ze schowka (ctrl + v)");
		opcje.push_back("Zapis (ctrl + s / F11)");
		opcje.push_back("Skok do linii");
		opcje.push_back("Licencja");
		opcje.push_back("Zakonczenie programu (alt + F4)");
		opcje.push_back("Zmiana pliku");
		opcje.push_back("Usuñ hasz (ctrl+del)");
		max_wybor = opcje.size() -1;

		noecho();
		pol = v_pol[i];
		for(;;){
			if(exit)break;
			
			//wyswietlanie
			clear();
			wborder(www, '|', '|', '-', '-', '+', '+', '+', '+');
			wborder(ww, '|', '|', '-', '-', '+', '+', '+', '+');
			wborder(prawa_ramka, '|', '|', '-', '-', '+', '+', '+', '+');

			for(unsigned short j=0; j<=max_wybor; ++j)
				mvwprintw(prawa, 3+j, 3, "%s", opcje[j].c_str());
			mvwprintw(prawa, 3+ktory, 0, "=>");

			mvprintw(2, 120, "Linia: %lu / %lu", i, desc.size() -1);

			mvwprintw(prawa, 0, 2, "Przejœcie miêdzy ramkami: TAB / F1");
			mvwprintw(prawa, 2, 10, "MENU:");

			mvprintw(2, 5, "nazwa kodowa: ");
			addstr(desc[i].c_str());

			mvprintw(2, 80, "hasz: ");
			if(hasz.at(i) != ';'){
				attron(A_REVERSE);
				printw("%c", hasz.at(i));
				attroff(A_REVERSE);
			}else printw("brak oznaczenia");

			mvprintw(2, 50, "Plik:\t%s", nazwa_pliku.c_str());

			mvprintw(4, 5, "Angielski tekst:");
			mvwaddstr(w_eng, 1, 1, eng[i].c_str());

			mvprintw(29, 5, "Polski tekst:");
			mvwaddstr(w_pl, 1, 1, pol.c_str());

			refresh();
			znak = getch();

			if(znak == 9){ //tab
				if(czy_menu)czy_menu = false;
				else czy_menu = true;
				continue;
			}
			if(czy_menu == false){
				if(znak == 125) pol.clear(); //shift+del
				else if(znak == 4){ //<=
					ktory = 1;
					znak = 13;
					czy_menu = true;
					enter = true;
				}	
				else if(znak == 15){ //ctrl+del
					ktory = 9;
					znak = 13;
					czy_menu = true;
					enter = true;
				}	
				else if(znak == 22){ //ctrl+v
					ktory = 3;
					znak = 13;
					czy_menu = true;
					enter = true;
				}
				else if(znak == 13 || znak == 5){// enter / =>
					ktory = 0;
					znak = 13;
					czy_menu = true;
					enter = true;
				}
				else if(znak == 19){ //ctrl + s
					ktory = 4;
					znak = 13;
					czy_menu = true;
					enter = true;
				}
				else if(znak == 48)break; //alt + f4
				else if(znak == 8 && pol.size() > 0)	pol.erase(--pol.end());
				else pol += znak;
			}
			if(czy_menu == true){

				if (znak == 3 && ktory != min_wybor) ktory--;
				else if(znak == 2 && ktory != max_wybor) ktory++;
				else if(znak ==2 && ktory == max_wybor) ktory = min_wybor;
				else if(znak ==3 && ktory == min_wybor) ktory = max_wybor; 
				else if(znak == 13)	switch(ktory){

						case 0:
							if(i == v_pol.size() -1)break;
							v_pol[i] = pol;
							++i;
							pol = v_pol[i];
							break;
						case 1:
							if(i == 0)break;
							v_pol[i] = pol;
							--i;
							pol = v_pol[i];
							break;
						case 2:
							pol.clear();
							break;
						case 3:
							if(IsClipboardFormatAvailable(CF_TEXT)){ 
								OpenClipboard(0); 
								HANDLE ClipboardData = GetClipboardData(CF_TEXT); 
								CloseClipboard();
								std::string clip = (const char*)ClipboardData; 
								pol += clip;
							}
							else {
								mvwprintw(prawa, 14, 2, "Nieprawid³owe dane w schowku");
								mvwprintw(prawa, 15, 2, "Lub brak danych.");
								mvwprintw(prawa, 16, 2, "Aby kontynuowaæ");
								mvwprintw(prawa, 17, 2, "Naciœnij dowolny klawisz");
								wrefresh(prawa);
								getch();
							}
							break;
						case 4:
							v_pol.at(i) = pol;
							if(zapis(nazwa_pliku))mvwprintw(prawa, 15, 8, "Zapisano pomyslnie"); 
							else mvwprintw(prawa, 15, 8, "Zapis nie powiodl sie");
							mvwprintw(prawa, 16, 2, "Nacisniej dowolny klawisz");
							mvwprintw(prawa, 17, 2, "aby kontynuowac...");
							wrefresh(prawa);
							getch();
							break;
						case 5:
							{
								int nowe = 0;
								for(;;){
									clear();
									WINDOW * ramka_srodek = subwin (stdscr, 8, 60, 20, 50);
									WINDOW * srodek = subwin (stdscr, 6, 58, 21, 51);
									wborder(ramka_srodek, '|', '|', '-', '-', '+', '+', '+', '+');
									mvwprintw(srodek, 2, 5, "Podaj nr. linii do której chcesz skoczyæ:\t");
									refresh();
									echo();
									wscanw(srodek, "%i", &nowe);
									if(nowe >= 0 && nowe < desc.size()){	
										v_pol[i] = pol;
										i = nowe;
										pol = v_pol[i];
										break;
									}
									else {
										mvwprintw(srodek, 4, 2, "Poda³eœ nieprawid³ow¹ wartoœæ!(ncisnij dowolny klawisz)");
										wrefresh(srodek);
										getchar();
									}
								}
								noecho();
							}
							break;
						case 6:
							system("licencja.htm");
							break;
						case 7:
							exit = true;
							break;
						case 8:
							ktory = 0;
							goto TOP;
							break;
						case 9:
							hasz.at(i) = '@';
							break;
				}
				if(enter == true){
					czy_menu = false;
					enter = false;
				}
			}
		}
	}
	else{
		clear();
		mvprintw(17, 10, "wczytanie pliku nie powiodlo sie\nNastapi zakonczenie programu po nacisnieciu dowolnego klawisza");
		refresh();
		noecho();
		getch();
	}
	clear();
	attroff(A_BOLD);
	attroff(COLOR_PAIR(1));
	endwin();
	return 0;
}

bool wczyt(std::string path){

	size_t poz, poz2, poz3, poz4, poz5;
	std::string buff;

	std::ifstream plik;
	plik.open(path.c_str());
	if(!( plik.is_open() && plik.good())){
		return false;
	}

	while(getline( plik, buff ).good()){
		poz = buff.find(';');

		desc.push_back(buff.substr(0, poz));
		poz2 = buff.find(';', poz+1);
		eng.push_back(buff.substr(++poz, poz2 - poz));
		poz3 = buff.find(';', poz2+1);
		poz4 = buff.find(';', poz3+1);
		poz5 = buff.find(';', poz4+1);
		v_pol.push_back(buff.substr(++poz4, poz5 - poz4));
		hasz.push_back(buff[poz5+3]);//szukanie oznaczenia wprowadzonego prze pirexusa
	}
	if(eng.size() == desc.size() && desc.size() == v_pol.size()){
		plik.close();
		return true;
	}
	else {
		plik.close();
		return false;
	}
}

bool zapis(std::string path){

	std::ofstream plik;
	plik.open(path.c_str());

	if( plik.is_open() && plik.good())
		for(unsigned long i=0; i<desc.size(); ++i){
			plik<<desc[i]<<';'<<eng[i]<<';'<<eng[i]<<';'<<eng[i]<<';'<<v_pol[i]<<";;;";
			if(hasz[i] != ';')plik<<hasz.at(i);
			plik <<";;;;;;;x"<<std::endl;		
		}
	else return false;
	return true;
}