/*
exercse - program do nauki s³ów jêzyków obcych, szczególnie agielskiego.
Copyright (C) 2009 Kamil Strzempowicz
Niniejszy program jest wolnym oprogramowaniem; mo¿esz go 
rozprowadzaæ dalej i/lub modyfikowaæ na warunkach Powszechnej
Licencji Publicznej GNU, wydanej przez Fundacjê Wolnego
Oprogramowania - wed³ug wersji 2-giej tej Licencji lub którejœ
z póŸniejszych wersji. 
Niniejszy program rozpowszechniany jest z nadziej¹, i¿ bêdzie on 
u¿yteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyœlnej 
gwarancji PRZYDATNOŒCI HANDLOWEJ albo PRZYDATNOŒCI DO OKREŒLONYCH 
ZASTOSOWAÑ. W celu uzyskania bli¿szych informacji - Powszechna 
Licencja Publiczna GNU. 
Z pewnoœci¹ wraz z niniejszym programem otrzyma³eœ te¿ egzemplarz 
Powszechnej Licencji Publicznej GNU (GNU General Public License);
jeœli nie - napisz do Free Software Foundation, Inc., 675 Mass Ave,
Cambridge, MA 02139, USA.

Pozdrawiam, konserw.
konserw@gmail.com
*/
#include "naglowek.h"

char jezyk='p';
string edzial="e3.txt", pdzial="p3.txt";

int main()
{
bool out=false;
	initscr();  
	keypad(stdscr, true);
	resize_term(45, 100);
	raw();
	start_colors();
	init_pair(0, COLOR_BLACK, COLOR_WHITE);
	//init_pair(0);
	attron(COLOR_PAIR(0);


while(!out){
	switch(menu()){
		case 0:
			ex(jezyk, edzial, pdzial);
			break;
		case 1:
			system(edzial.c_str());
			system(pdzial.c_str());
			break;
		case 2:
			jezyk='p';
			break;
		case 3:
			jezyk='e';
			break;
		case 4:
			edzial="e1.txt";
			pdzial="p1.txt";
			break;
		case 5:
			edzial="e2.txt";
			pdzial="p2.txt";
			break;
		case 6:
			edzial="e3.txt";
			pdzial="p3.txt";
			break;
		case 7:
			edzial="e4.txt";
			pdzial="p4.txt";
			break;
		case 8:
			edzial="e5.txt";
			pdzial="p5.txt";
			break;
		case 9:
			edzial="e6.txt";
			pdzial="p6.txt";
			break;
		case 10:
			system("licencja.htm");
			break;
		case 11:
			out=true;
			break;
	}
}//koniec while
endwin();
return 0;
}