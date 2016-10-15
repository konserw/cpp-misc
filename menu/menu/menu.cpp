/*
 *  biblioteka obs³ugi menu i loga by konserw
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

#include "menu.h"

bool windows_coding = false; /* zmiana na rzeciwne przez chcp();
							  * true = chcp 1250 
							  * false = chcp 852
							  */
/*
void explode(const std::string &str, char delim, std::vector<std::string> &out){
	//char del = delim;
	const char* ptr = &delim;
	explode(str, ptr, out);
}*/
void explode(const std::string &str, const char *delim, std::vector<std::string> &out){

    std::string::const_iterator i1 = str.begin(); 
    std::string::const_iterator i2 = i1; 
	std::string::const_iterator i3 = str.end(); 

    while(i1 != i3){ 
        while(i2 != i3 && !strchr(delim,*i2))++i2; 
		out.push_back(std::string(i1,i2)); 
        i1 = i2 != i3 ? ++i2 : i2; 
    } 
}						  
/*
####################################################
############		INICJALIZACJA		############
####################################################
*/

void init(unsigned y_term_size, unsigned x_term_size){
	//czyszczenie loga
	std::ofstream cerr("error.log", std::fstream::trunc);
	cerr << "czas\t/funkcja/\tdzia³anie" << std::endl;
	logline();
	cerr.close();

	log("init", "Zainicjowano log");
	log("init", "Inicjalizacja...");
	//aktywacja curses
	initscr();  
	keypad(stdscr, true);
	raw();
	resize_term(y_term_size, x_term_size);
	log("init", "Przewymiarowano terminal");
	log("init", "wierszy", y_term_size);
	log("init", "kolumn", x_term_size);
	if(has_colors() == TRUE){
		log("init", "Ma kolory");
		start_color();
		init_pair(1, COLOR_WHITE, COLOR_BLUE);
		wbkgd(stdscr, COLOR_PAIR(1));
		attron(COLOR_PAIR(1));
		init_pair(2, COLOR_YELLOW, COLOR_BLUE);
		//init_pair(3, COLOR_WHITE, COLOR_BLACK);
	}
	else log("init", "Nie ma kolorów");
	attron(A_BOLD);
	log("init", "Curses aktywne");
	log("init", "Koniec inicjalizacji");
	logline();
}

/*
####################################################
############		METODY cMenu		############
####################################################
*/
/* Konstruktory */
cMenu::cMenu(std::vector<std::string>& inOpcje, WINDOW* okno){
	vOpcje = inOpcje;
	wOkno = okno;
	bWstep = false;
	log("cMenu", "utworzono instancje klasy cMenu /stdscr/ bez wstepu");
}
cMenu::cMenu(std::vector<std::string>& inWstep, std::vector<std::string>& inOpcje, WINDOW* okno){
	vOpcje = inOpcje;
	inOpcje.clear();
	wOkno = okno;
	vWstep = inWstep;
	inWstep.clear();
	bWstep = true;
	log("cMenu", "utworzono instancje klasy cMenu");
}
/*
cMenu::cMenu(WINDOW* inwin, std::vector<std::string>& inOpcje){
	vOpcje = inOpcje;
	inOpcje.clear();
	wOkno = inwin;
	bWstep = false;
	log("cMenu", "utworzono instancje klasy cMenu");
}
cMenu::cMenu(WINDOW* inwin, std::vector<std::string>& inWstep, std::vector<std::string>& inOpcje){
	vOpcje = inOpcje;
	inOpcje.clear();
	wOkno = inwin;
	vWstep = inWstep;
	inWstep.clear();
	bWstep = true;
	log("cMenu", "utworzono instancje klasy cMenu");
}
*/
cMenu::cMenu(std::string& inWstep, std::string& inOpcje, WINDOW* okno){
	explode(inOpcje, "\n", vOpcje);
	inOpcje.clear();
	explode(inWstep, "\n", vWstep);
	inWstep.clear();
	wOkno = okno;
	bWstep = true;
	log("cMenu", "utworzono instancje klasy cMenu");
}		
cMenu::cMenu(std::string& inOpcje, WINDOW* okno){
	explode(inOpcje, "\n", vOpcje);
	inOpcje.clear();
	wOkno = okno;
	bWstep = false;
	log("cMenu", "utworzono instancje klasy cMenu");
}
cMenu::cMenu(const char* inWstep, const char* inOpcje, WINDOW* okno){
	/*
	explode(static_cast<std::string>(inOpcje), "\n", vOpcje);
	explode(static_cast<std::string>(inWstep), "\n", vWstep);
	*/
	std::string w(inWstep);
	std::string o(inOpcje);
	explode(w, "\n", vWstep);
	explode(o, "\n", vOpcje);

	wOkno = okno;
	bWstep = true;
	log("cMenu", "utworzono instancje klasy cMenu");
}		
cMenu::cMenu(const char* inOpcje, WINDOW* okno){
	explode(static_cast<std::string>(inOpcje), "\n", vOpcje);
	wOkno = okno;
	bWstep = false;
	log("cMenu", "utworzono instancje klasy cMenu");
}
cMenu::cMenu(std::string& inWstep, std::vector<std::string>& inOpcje, WINDOW* okno){
	vOpcje = inOpcje;
	inOpcje.clear();
	wOkno = okno;
	explode(inWstep, "\n", vWstep);
	inWstep.clear();
	bWstep = true;
	log("cMenu", "utworzono instancje klasy cMenu");
}


/* Metody */
unsigned short cMenu::wybor(){
	unsigned x, y, nx, ny;
	getmaxyx(wOkno, y, x);
	
	if(x > 40)nx = 10;
	else nx = 5;
	if(y > 25) ny = 10;
	else ny = 5;

	return wybor(ny, nx);
}

unsigned short cMenu::wybor(unsigned y, unsigned x){

	max_wybor = vOpcje.size()-1;
	ktory = 0;
	char znak;

	for(;;){
		border(wOkno);

		if(bWstep == false){
			for(unsigned i = 0; i < vOpcje.size(); ++i) mvwprintw(wOkno, y+i, x, "%s", vOpcje[i].c_str()); 
			mvwprintw(wOkno, y+ktory, x-2, "=>");
		}
		else{
			short ny = y + vWstep.size() +1;
			for(unsigned short i=0; i < vWstep.size(); ++i) mvwprintw(wOkno, y+i, x, "%s", vWstep[i].c_str()); 
			for(unsigned short i = 0; i < vOpcje.size(); ++i) mvwprintw(wOkno, ny+i, x, "%s", vOpcje[i].c_str()); 
			mvwprintw(wOkno, ny + ktory, x-2, "=>");
		}

		wrefresh(wOkno);
		noecho();
        znak = getch();
		if (znak == 3){
			if(ktory != min_wybor) ktory--;
			else if(ktory == min_wybor) ktory = max_wybor;
		}
		else if(znak == 2){
			if(ktory != max_wybor) ktory++;
			else if(ktory == max_wybor) ktory = min_wybor;
		}
		else if(znak == 13){
			log("wybor", "Wybrano", vOpcje[ktory].c_str());
			return ktory;
		}
	}
}

/*
####################################################
############		FUNKCJE LOGA		############
####################################################
*/

inline void log(const char* ch){
	log("main", ch);
}
void log(const char* fun, const char* info){
	std::ofstream err("error.log", std::fstream::app);
	err << clock() / CLOCKS_PER_SEC << ":\t/" << fun << "/\t" << info << std::endl;
	err.close();
}
void log(const char* fun, const char* info, double liczba){
	std::ofstream err("error.log", std::fstream::app);
	err << clock() / CLOCKS_PER_SEC << ":\t/" << fun << "/\t" << info << ":\t" << liczba << std::endl;
	err.close();
}
void log(const char* fun, const char* info, const char* string){
	std::ofstream err("error.log", std::fstream::app);
	err << clock() / CLOCKS_PER_SEC << ":\t/" << fun << "/\t" << info << ":\t" << string << std::endl;
	err.close();
}
void logline(){
	std::ofstream err("error.log", std::fstream::app);
	err << "\n";
	for(int i=0; i<30; ++i)err << "##";
	err << "\n" << std::endl;
	err.close();	
}

/*
########################################################
############			INNE FUNKCJE		############
########################################################
*/
/*
void loading(){
	border();
	mvprintw(12, 25, "Wczytywanie, prosze czekac...");
	refresh();
}*/
void loading(WINDOW* wOkno, bool eng){
	border(wOkno);
	if(eng)
		mvwprintw(wOkno, 12, 25, "Loading, please wait...");
	else
		mvwprintw(wOkno, 12, 25, "Wczytywanie, prosze czekac...");


	refresh();
}
void border(WINDOW* wOkno){
	wclear(wOkno);
	if(windows_coding == true) wborder(wOkno, '|', '|', '-', '-', '+', '+', '+', '+');
	else wborder(wOkno, 0, 0, 0, 0, 0, 0, 0, 0);
	wrefresh(wOkno);
}
/*
void border(){
	clear();
	if(windows_coding == true) border('|', '|', '-', '-', '+', '+', '+', '+');
	else border(0, 0, 0, 0, 0, 0, 0, 0);
	refresh();
}
*//*
void error(WINDOW* wOkno = stdscr){
		border();
		mvprintw(10, 10, "Wystapil blad. Wiecj informacji w error.log");
		mvprintw(12, 10, "Nastapi zakonczenie programu");
		refresh();
		getch();
		endwin();
}
*/
void error(WINDOW* wOkno, bool eng){
		border(wOkno);
		if(eng){
			mvwprintw(wOkno, 10, 10, "An error has occurred. Please post file error.log to konserw@gmail.com");
			mvwprintw(wOkno, 12, 10, "This app will be terminated");
		}else{
			mvwprintw(wOkno, 10, 10, "Wystapil blad. Prosze wyslac plik error.log na adres konserw@gmail.com");
			mvwprintw(wOkno, 12, 10, "Nastapi zakonczenie programu");
		}
		wrefresh(wOkno);
		getch();
		endwin();
}

/*
void cont(){
	mvprintw(22, 37, "Nacisnij dowolny klawisz aby kontynuowac.");
	refresh();
	getch();
}
*/
void cont(WINDOW* wOkno, bool eng){
	if(eng)
		mvwprintw(wOkno, 22, 37, "Please press any key to continue.");
	else
		mvwprintw(wOkno, 22, 37, "Nacisnij dowolny klawisz aby kontynuowac.");
	wrefresh(wOkno);
	getch();
}
void chcp(){
	if(windows_coding == false){
		system("chcp 1250");
		log("chcp", "Zmina strony kodowej na windowsow¹ (1250)");
		windows_coding = true;
	}
	else{
		system("chcp 852");
		log("chcp", "Zmina strony kodowej na dosow¹ (852)");
		windows_coding = false;
	}
}