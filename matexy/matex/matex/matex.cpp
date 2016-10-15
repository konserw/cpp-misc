#include "PCH.h"
/*
 * Matex 2 - program o zastosowaniu ogólnomatematycznym
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
 

#include "PCH.h"
#include "naglowek.h"

std::vector<double> tablica;

void info();
unsigned short mymenu(eJakie_menu, unsigned short);

int main(){

	bool out=false;
	int znak=1;

	initscr();  
	keypad(stdscr, true);
	resize_term(50, 130);
	raw();

	if(has_colors() == TRUE) start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	bkgd(COLOR_PAIR(1));	attron(COLOR_PAIR(1));	attron(A_BOLD);
	border(0, 0, 0, 0, 0, 0, 0, 0);

	
	do{	
		unsigned short ktore, ktore2;
		ktore = mymenu(menu_glowne, 0);
		switch(ktore){
			case 0: 
				out=true;
				break;
			case 1:
				ktore2 = mymenu(menu_pierwsze, ktore);
				switch(ktore2){
					case 1:
						trojkaty(mymenu(menu_planimetria, ktore2));
						break;
					case 2:
						kwadraty(mymenu(menu_planimetria, ktore2));
						break;
					case 4:
						romby(mymenu(menu_planimetria, ktore2));
						break;
					case 5:
						rownolegloboki(mymenu(menu_planimetria, ktore2));
						break;
					case 6:
						trapezy(mymenu(menu_planimetria, ktore2));
						break;
					default:
						planimetria(ktore2);
				}
				break;
			case 2:
				switch(mymenu(menu_pierwsze, ktore)){
					case 1:
						graniastoslupy(mymenu(menu_stereometria, 1));
						break;
					case 2:
						ostroslupy(mymenu(menu_stereometria, 2));
						break;
					case 3:
						obrotowe(mymenu(menu_stereometria, 3));
						break;
				}
				break;
			case 3:
				geometria(mymenu(menu_pierwsze, ktore));
				break;
			case 4:
				algebra(mymenu(menu_pierwsze, ktore));
				break;
			case 5:
				kombinatoryka(mymenu(menu_pierwsze, ktore));
				break;
			case 6:
				ciagi(mymenu(menu_pierwsze, ktore));
				break ;
			case 7:
				teoria(mymenu(menu_pierwsze, ktore));
				break;
			case 8:
				system("readme.txt");
				break;
			case 9:
				system("licencja.htm");
				break;
		}





	}while(out!=true);

	//--------------pozegnanie------------------
	clear();
	mvprintw(20, 20, "Dziekuje za korzystanie z mojego programu :)");
	mvprintw(22, 20, "coptleft Kamil 'konserw' Strzempowicz");
	mvprintw(24, 20, "W programie wykorzystano biblioteke PDCurses");
	mvprintw(26, 20, "Specjalne podziekowania dla:");
	mvprintw(28, 30, "# Dyzia, za podrzucenie kawalka kodu");
	mvprintw(29, 30, "# ludzi z forum programuj.com za nieoceniona wielokrotna pomoc");
	mvprintw(30, 30, "# wszystkich wylapujacych bugi (szczegolnie Wator!)");

	stop();
	endwin();
	return 0;
}

void info(){
	attroff(A_BOLD);
	mvprintw(10, 95, "Strzalki w gore i w dol - kursor");
	mvprintw(11, 95, "Enter lub => aby wybor");
	mvprintw(12, 95, "Esc lub <= - poprzednie menu");
	attron(A_BOLD);
}

unsigned short mymenu(eJakie_menu jakie, unsigned short ktore){
	menu glowne(jakie, ktore);
	int znak = 1;
	for(;;){
		//obs³uga klawiszy
		if (znak == 259) --glowne;	//strzalka w dó³
		else if(znak == 258) ++glowne;	//strza³ka w górê
		else if(znak == 13 || znak==261)	//enter lub strza³ka w prawo
			return glowne;
		else if(znak == 260 || znak == 27){ //esc lub stra³ka w lewo
			if(jakie == menu_glowne)
				return 0;
			else
				mymenu(static_cast<eJakie_menu>(jakie - 1), jakie);
		}
		//obs³uga ekranu
		clear();
		logo();
		info();
		glowne.wyswietl();

		//kursr w rog i oczekiwanie na klawisz
		noecho();
		move(0,0);
		znak = getch();
	}
}
*/