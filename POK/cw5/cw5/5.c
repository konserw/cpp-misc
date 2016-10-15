#define make

#if defined make
#include "head.h"

int main(){
	char str[] = "The licenses for most software are designed to take away your freedom to share and change it. By contrast, the GNU General Public License is intended to guarantee your freedom to share and change free software--to make sure the software is free for all its users. This General Public License applies to most of the Free Software Foundation's software and to any other program whose authors commit to using it. (Some other Free Software Foundation softwareams, too. ";
	char st[] = "This License applies to any program or other work which contains a notice placed by the copyright holder saying it may be distributed under the terms of this General Public License. The , below, refers to any such program or work, and a means either the Program or any derivative work under copyright law: that is to say, a work containing the Program or a portion of it, either verbatim or with modifications and/or translated into another language";
	unsigned counter[26], c[26], i, inne=0, j=0, x=0, l, in=0;
	WINDOW* win;
	WINDOW* wi;

	//for(i=0; i<26; ++i)counter[i]=0;
	memset(counter, 0, sizeof *counter * 26);
	memset(c, 0, sizeof *counter * 26);

	init(50, 120);
	bord();
	move(12, 30);

	
	//getnstr(str, 1023);
	//printw("%d", strlen(str));
	//cont();
	//l = strlen(str);
	for(i=0; ; ++i){
		//printw("%d\t", (int)str[i]);
		if(str[i] == '\0') break;
		if(str[i] <= 'z' && str[i] >= 'a') counter[str[i]-'a']++;
		else inne++;
	}
	for(i=0; ; ++i){
		//printw("%d\t", (int)str[i]);
		if(st[i] == '\0') break;
		if(st[i] <= 'z' && st[i] >= 'a') c[str[i]-'a']++;
		else in++;
	}
	//printw("\n%d", j);
	//cont();
	bord();

	win = newwin(15, 40, 5, 10);
	waddstr(win, str);
	wrefresh(win);

	wi = newwin(15, 40, 5, 60);
	waddstr(wi, st);
	wrefresh(wi);

	cont();
	delwin(win);
	delwin(wi);
	bord();
	
	for(i=0; i<25; i++){
		//printw("%d\t", counter[i]);
		//if(counter[i] != 0){
			x+=2;
			for(j=0; j<counter[i]; j++)
				mvprintw(48-j, x, "%c", 'a'+i);
		//}
			//printw("%c", 'a'+i);
		//printw("\n");
	}

	x+=2;
	for(j=0; j<inne; ++j)
		mvprintw(48-j, x, "%c", '*');
	x+=4;

	for(i=0; i<25; i++){
		x+=2;
		for(j=0; j<c[i]; j++)
			mvprintw(48-j, x, "%c", 'a'+i);
	}
	x+=2;
	for(j=0; j<in; ++j)
		mvprintw(48-j, x, "%c", '*');

	refresh();
	getch();
	
	bord();
	for(i=0; i<26; ++i)
		if(counter[i]!=0)
		mvprintw(10+1, 10, "%.3d", 100*c[i]/counter[i]);


	cont();
	endwin();
	return 0;
}
#endif