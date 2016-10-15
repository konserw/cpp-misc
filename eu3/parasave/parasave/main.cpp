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
#include "header.h"
#include "menu.h"

bool eng;

int main(){
	std::string path, linie, b1, b2, wyj;
	init();

	cMenu lang("Please choose your language\nProsze wybrac jezyk", "English\nPolish");
	switch(lang.wybor()){
		case 0:
			eng = true;
			break;
		case 1:
			eng = false;
			break;
		default:
			log("lang", "error");
			break;
	}
	if(eng){
		b1 = "Welcome in >parasave< application\nChoose action:";
		b2 = "Show the license (GNU/GPL)\nperform semi-conversion to h3t\nConvert brackets from h3t-style to IN-style\nbrack IN -> h3t\nExit";
	}
	else{
		b1 = "Witam w programie >parasave< dla EU3\nWybierz zadanie:";
		b2 = "Licencja (GNU/GPL)\nKonwersja do h3t\nPrzerabianie nawiasow h3t -> IN\nnawiasy IN->h3t\nWyjscie";
	}
	cMenu menu(b1, b2);
	bool exit = false;
	logline();
	do{
		switch(menu.wybor()){
			case 0:
				system("licencja.htm");
				break;
			case 1:
				exit = beg(path, linie);
				if(exit)break;
				log("main", "konwersja");
				historia(linie);
				log("main", "po historii");
				logline();
				flag(linie);
				log("main", "po flagach");
				latin(linie);
				log("main", "po westernizacji");
				sz_id(linie);
				log("main", "po sz id");
				mag(linie);
				log("main", "po magistratech");
				save(linie, path);
				system("id.txt");
				break;
			case 2:
				exit = beg(path, linie);
				if(exit) break;
				log("main", "nawiasy h3t->in");
				nawiasy(linie);
				save(linie, path);
				break;
			case 3:
				exit = beg(path, linie);
				if(exit) break;
				log("main", "nawiasy in->h3t");
				rev_nawiasy(linie);
				save(linie, path);
				break;
			case 4:
				exit = true;
				break;
		}
	}while(exit == false);

	log("main", "exiting");
	logline();
	endwin();
	return 0;
}
