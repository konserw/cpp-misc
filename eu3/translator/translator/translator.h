/*
 * Plik translator.h
 * CSV Translator - program u�atwiaj�cy t�umaczenie plik�w 
 * lokalizacyjnych gier ParadoxInteractive; wersja kompatybilna z EU3
 * Potrzebujesz wersji pasuj�cej do innej gry paradoxu - pisz na mojego mejla! ;)
 * Zawsze warto te� zajrze� na forum strategiczne wayofwar.pl
 * 
 * Copyright (C) 2010 Kamil Strzempowicz
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
#pragma once
#include "resource.h"
#include <deque>

typedef std::deque<std::string>::const_iterator iter;

extern int wers, byl;
extern int lang;
/*
enum eJaka_gra{
	EU3,
	vic2
};
extern eJaka_gra gra;
*/
void explode(const std::string &str, const char *delim, std::deque<std::string> &out);

class cWers{
private:
	//std::string sDesc, sEng, sPol;
	std::deque<std::string> vec;
public:
	cWers(const std::string& linia){
		explode(linia, ";", vec);
	};
	cWers(){
		vec.push_back("ID");
		vec.push_back("ENGLISH");
		vec.push_back("FRENCH");
		vec.push_back("GERMAN");
		vec.push_back("POLSKI");
		vec.push_back("SPANISH");
		vec.push_back("ITALIAN");
		vec.push_back("SWEDISH");
		vec.push_back("CZECH");
		vec.push_back("HUNGARIAN");
		vec.push_back("DUTCH");
		vec.push_back("PORTUGESE");
		vec.push_back("RUSSIAN");
		vec.push_back("FINNISH");
		vec.push_back("x");
	};
	const char* eng()const{
		return vec[1].c_str();//sEng;
	}
	const char* pol()const{
		return vec[lang+1].c_str();//sPol;
	}
	const char* desc()const{
		return vec[0].c_str();//sDesc;
	}
	std::string print()const;

	void set_desc(char* text){
		vec[0] = static_cast<std::string>(text);
	}
	void set_eng(char* text){
		vec[1] = static_cast<std::string>(text);
	}
	void set_pol(char* text){
		vec[lang+1] = static_cast<std::string>(text);
	}

};

bool wczyt(std::deque<cWers>& vWersy, HWND hWnd, char* szFile);
bool zapis(std::deque<cWers>& vWersy, HWND hWnd, char* szFile);
void refresh(HWND hDlg, std::deque<cWers>& wersy);
void disable(HWND hDlg);
void update(HWND hDlg, std::deque<cWers>& wersy);

INT_PTR CALLBACK MainProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK wybor_pliku(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);
//BOOL CALLBACK GraProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK LangProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
