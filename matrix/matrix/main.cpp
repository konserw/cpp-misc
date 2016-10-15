/* matrix - operacje na macierzach zespolonych by konserw
 * main.cpp - g³ówny kod programu
 *
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


int main(){

	init(25, 80);
/*
	unsigned short wybor;
	std::vector<std::string> opis, opcje;
	opis.push_back("Witam w programie do operacji na macierzach!");
	opis.push_back("Wybierz dzialanie:");
	opcje.push_back("Nowa macierz");
	cMenu glowne(opis, opcje);
	wybor = glowne.wybor(10, 10);
	cMatrix a;
	a.wyswietl(2, 2);
*/
	cMatrix a, b, c;
	a.wymiary(2,2);
	b.wymiary(2,2);
	c.wymiary(2,2);

	std::ifstream plik("a.txt");
	int buf;
	unsigned x=0, y=0;
	std::string buff;
	std::stringstream ss;
	while(getline(plik, buff)){
		x=0;
		ss.str(buff);
		if(y==a.wierszy())++a;
		while(ss >> buf){
			if(x==a.kolumn())a++;
			a[y][x] = buf;
			++x;
		}
		++y;
	}


a[2][2] = 5;
	a.wyswietl(2,2);


	getch();
	endwin();
	return 0;
}