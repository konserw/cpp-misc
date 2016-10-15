/* build 240110
 * biblioteka obs�ugi menu i loga by konserw
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

########################################################
############			NAG��WKI			############
########################################################
*/

#include <vector>
#include <fstream>
#include <ctime>
#include <curses.h>

/*
########################################################
############		DEKLARACJE FUNKCJI		############
########################################################
*/

void init(unsigned y_term_size=25, unsigned x_term_size=80); //inicjacja. rozpoczyna curses i czysci log.

//void explode(const std::string &str,char delim, std::vector<std::string> &out);
void explode(const std::string &str,const char *delim, std::vector<std::string> &out);

/* funkcje logowania */
void log(const char*, const char*, const char*);
void log(const char*, const char*, double);
void log(const char*, const char*);
inline void log(const char*);
void logline();

/*inne funkcje */
void chcp();
void border(WINDOW* wOkno = stdscr);
void error(WINDOW* wOkno = stdscr, bool eng = false);
void loading(WINDOW* wOkno = stdscr, bool eng = false);
void cont(WINDOW* wOkno = stdscr, bool eng = false);
/*
inline void cont(bool eng){
	cont(stdscr, eng);
}
inline void error(bool eng){
	error(stdscr, eng);
}
inline void loading(bool eng){
	loading(stdscr, eng);
}

inline void error(){
	error(stdscr, false);
}
inline void cont(){
	cont(stdscr, false);
}
inline void border(){
	border(stdscr);
}
*/

/*
################################################
############		KLASA cMenu		############
################################################
*/

class cMenu{
private:
	static const short int min_wybor = 0;
	unsigned short max_wybor, sWstep;
	unsigned short ktory;//niezainicjowane - pami�taj!
	std::vector<std::string> vOpcje;
	WINDOW * wOkno;
	std::vector<std::string> vWstep;
	bool bWstep;

public:
	cMenu(std::vector<std::string>& inOpcje, WINDOW* okno = stdscr);
	cMenu(std::vector<std::string>& inWstep, std::vector<std::string>& inOpcje, WINDOW* okno = stdscr);
	cMenu(std::string& inWstep, std::vector<std::string>& inOpcje, WINDOW* okno = stdscr);
	/*
	cMenu(WINDOW* inwin, std::vector<std::string>& inOpcje);
	cMenu(WINDOW* inwin, std::vector<std::string>& inWstep, std::vector<std::string>& inOpcje);
	*/
	cMenu(std::string& inWstep, std::string& inOpcje, WINDOW* okno = stdscr);
	cMenu(std::string& inOpcje, WINDOW* okno = stdscr);
	cMenu(const char* inWstep, const char* inOpcje, WINDOW* okno = stdscr);
	cMenu(const char* inOpcje, WINDOW* okno = stdscr);

	unsigned short wybor();
	unsigned short wybor(unsigned y, unsigned x);
	void co(unsigned y, unsigned x, std::string& buf){
		buf = vOpcje[wybor(y, x)];
	}

};


