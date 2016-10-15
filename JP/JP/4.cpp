#include "curses.h" // nag³ówek pdcurses - biblioteka obs³ugi terminalu
#pragma comment(lib, "pdcurses.lib") // do³¹czenie biblioteki, jak na devie nie zadzia³a trzeba do³¹czyæ w opcjach linkera

int main4(){//usunac 4
	initscr();
	noraw();
	noecho();
	if(has_colors() == TRUE)
		start_color();

	resize_term(120, 60);
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
    bkgd(COLOR_PAIR(1));
	attron(COLOR_PAIR(1));
	attron(A_BOLD);
	border(0, 0, 0, 0, 0, 0, 0, 0);
	refresh();






	getch();
	endwin();
	return 0;
	
}
