/*
MaTeX2 - program matematyczny z lepszym interfejsem :)
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

//------------podstawowe funkcje programu--------------------
#include "PCH.h"
#include "naglowek.h"

//-------------wejscie danych-------------------
bool in (unsigned short danych, eTyp typ){
	tablica.clear();
	double x=0;
	for(unsigned short i=0; i<danych; i++){	
		int g;
		echo();
		if(i==0)printw("\n");
		g=scanw("%lf", &x);
		if(g!=1){
			mvprintw(20, 30, "Wprowadzono nieprawidlowy format danych!");
			return false;
		}
		else if (typ==N && x<0){
			mvprintw(20, 30, "Podales liczbe mniejsza od 0!");
			return false;
		}
		else if (typ==J && x<1){
			mvprintw(20, 30, "musisz podac liczbe wieksza badz rowna 1");
			return false;
		}
		else if (typ==J && (long long)(x)!=x){
			mvprintw(20, 30, "musisz podac liczbe calkowita!");
			return false;
		}
		tablica.push_back(x);
	}
	return true;
}
//-------------silnia------------
unsigned __int64 silnia(__int64 n){ 	//silnia z forum :)
	if(n==0)return 1; 
	else return n*silnia(n-1);
} 
//-----------twierdzenie kosinusow---------------
long double twcos(long double a, long double b, long double alfa){
	return(sqrt((a*a)+(b*b)-(2*a*b*cos(alfa*M_PI/180))));
}
//-------------------Inne-------------------------
long double ctg (long double alfa){
	return(1/tan(alfa*M_PI/180));
}
void stop(){
	mvprintw(40, 20, "Nacisnij dowolny klawisz aby kontynuowac");
	int t;
	refresh();
	noecho();
	t=getchar();
}

void logo(){
	init_pair(2, COLOR_RED, COLOR_BLUE);
	attron(COLOR_PAIR(2));
		mvprintw(1, 25, "          .       .              _______________           .!.        ,/,.");
		mvprintw(2, 25, "       `omN-    -dMy             ommmmNNNmmmmmh-            sNd-     `:ymo`");
		mvprintw(3, 25, "      .yMMm.   /NMM+              ``./Nm:/~~~~`             .hMd.  .+ddo.");
		mvprintw(4, 25, "     .hMMMy  `sNNMm.    ./oyyhs-    `yM+       ./syyhy/      .dMd:odd+`");
		mvprintw(5, 25, "    :dmomM/ -hm+yMy   :ydy/-/NN/    :Nd`     .ody/^;yMh`      :NMMh:`");
		mvprintw(6, 25, "  `+Nd--NN:+mh-`dM/ `sNs.  `yN+    `dN/     -dNo;..;s/`     -odmNMs");
		mvprintw(7, 25, " `sNy. /MMmNo` -NN- +My`   :Ny`    oMy`    .dMds++;``    `/hdy:`+MN:");
		mvprintw(8, 25, "`yMs`  oMMd:   +Mm` hMy-.-+mM+    -Nm.     -NNs:-[...o`-sdh+.   `yMm-");
		mvprintw(9, 25, ":h+`   :y+`    +mo  -shhyo+sh-    -o.       -oyhhyo/-`-hs-`      .ym/");
	attroff(COLOR_PAIR(2));
}