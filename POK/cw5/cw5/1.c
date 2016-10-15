//#define make
#define cur
#include "head.h"

#if defined make




int main(){
	int counter[11];
	//unsigned short n[1000], i, j;
	unsigned suma = 0, ran, i;
	char znak;

	srand((unsigned)time(NULL));
	init(30, 80);
	noecho();
	
	do{
		for(i=0; i<11; i++)counter[i] = 0;
		suma = 0;
		bord();
		for(i=0; i < 1000; ++i){
			/*
			n[i] = (rand()%11) + 10;
			for(j=10; j<=20; ++j)
				if(n[i]%j==0){
					if(j==10){
						if(n[i]==10)counter[0]++;
						else counter[10]++;
					}
					else counter[j-10]++;
					break;
				}
				*/
			ran = (rand()%11) + 10;
			counter[ran-10]++;
		}

		for(i=0; i<11; i++){
			mvprintw(2+i, 4, "%u: %u", i+10, counter[i]);
			suma += counter[i];
		}
		mvprintw(20,40, "suma: %u", suma);
		mvprintw(22, 40, "nacisnij esc aby zakonczyc");
		refresh();
		znak = getch();
	}while(znak != 27);


	//cont();
	return 0;
}


#endif
#if defined cur
void init(unsigned y_term_size, unsigned x_term_size){

	initscr();  
	keypad(stdscr, TRUE);
	raw();
	resize_term(y_term_size, x_term_size);
	if(has_colors() == TRUE){
		start_color();
		init_pair(1, COLOR_WHITE, COLOR_BLUE);
		wbkgd(stdscr, COLOR_PAIR(1));
		attron(COLOR_PAIR(1));
		init_pair(2, COLOR_YELLOW, COLOR_BLUE);
		//init_pair(3, COLOR_WHITE, COLOR_BLACK);
	}

	attron(A_BOLD);

}
void cont(){
	mvprintw(22, 37, "Nacisnij dowolny klawisz aby kontynuowac.");
	refresh();
	getch();
}
void bord(){
	clear();
	border(0, 0, 0, 0, 0, 0, 0, 0);
	refresh();
}
#endif