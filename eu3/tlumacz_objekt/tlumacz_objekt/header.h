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

enum eJaka_gra{
	EU3,
	hoi2
};

extern std::ofstream cerr;
extern eJaka_gra sGra;

bool zapis(std::string&);
std::string wybor_pliku();

class cWers{
private:
	std::string sDesc, sEng, sPol;
	char cHasz;
	bool bHasz;

public:
	cWers(std::string& inDesc, std::string& inEng, std::string& inPol){
		sDesc = inDesc;
		sEng = inEng;
		sPol = inPol;
		bHasz = false;
		cerr << "utworzono instancje klasy cWers bez hasza" << std::endl;

	}
	cWers(std::string& inDesc, std::string& inEng, std::string& inPol, char inHasz){
		sDesc = inDesc;
		sEng = inEng;
		sPol = inPol;
		cHasz = inHasz;
		bHasz = true;
		cerr << "utworzono instancje klasy cWers z haszem" << std::endl;
	}
	bool zapis(std::fstream& plik)const;
	std::string eng()const{
		return sEng;
	}
	std::string pol()const{
		return sPol;
	}


};

bool wczyt(const std::string&, std::vector<cWers>&);

class cMenu{
private:
	static const short int min_wybor = 0;
	unsigned short max_wybor;
	unsigned short ktory;//niezainicjowane - pamiêtaj!
	std::vector<std::string> vOpcje;
	WINDOW * wOkno;

public:
	cMenu(std::vector<std::string>& inOpcje, WINDOW* inwin){
		vOpcje = inOpcje;
		wOkno = inwin;
		cerr << "utworzono instancje klasy cMenu" << std::endl;
	}
	unsigned short wybor(unsigned y, unsigned x);
	unsigned short wybor(unsigned y, unsigned x, std::vector<std::string>& wstep);

};

class cOkno{
protected:
	WINDOW* wRamka;
	WINDOW* wOkno;
	//std::string sTekst;

public:
	cOkno(){};
	cOkno(int x, int y){
		wRamka = subwin(stdscr, 22, 102, y, x);
		wOkno = subwin(stdscr, 20, 100, y+1, x+1);
		cerr << "utworzono instancje klasy cOkno" << std::endl;
	}
	void wyswietl(const std::string& sTekst);
};

class cEdytor : public cOkno{
protected:
	std::string sBuff;

public:
	cEdytor(int x, int y){
		wRamka = subwin(stdscr, 22, 102, y, x);
		wOkno = subwin(stdscr, 20, 100, y+1, x+1);
		cerr << "utworzono instancje klasy cEdytor" << std::endl;
		keypad(wOkno, true);
	}
	//...
};










