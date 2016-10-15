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

#include "PCH.h"
#include "naglowek.h"
//unsigned short menuk();
bool komb (unsigned short danych);
unsigned long tab[2];

void kombinatoryka(unsigned short ktory2){
	bool out=false;

	clear();
	logo();
	switch(ktory2){
		case 0:
			out=true;
			break;
		case 1:
			mvprintw(10, 10, "Wybrales permutacje. Podaj ilosc elementow zbioru, ktorego permutacje chcesz obliczyc");
			if(komb(1)){
				unsigned long x=666;
				unsigned long bla=666;
				x=static_cast<unsigned long>(silnia(tab[0]));
				bla=static_cast<unsigned long>(tab[0]);
				mvprintw(15, 10, "%lu elementow mozna ustawic w ciag na %lu sposobow", bla, x);
			}
			break;
		case 2:
			mvprintw(10, 10, "Wybrales wariacje bez powtorzen.");
			mvprintw(11, 10, "Podaj ilosc elementow w zbiorze (n), oraz ilosc elementow ciagu w ktorym maja zostac umieszczone (k)");
			if(komb(2)){
				unsigned long z=1;
				for(double i=tab[0]-tab[1]+1; i<=tab[0]; i++)z*=i;
				mvprintw(15, 10, "liczba sposobow, w jaki z %lu elementow"
					"mozna utworzyc ciag skladajacy sie z %lu roznych wyrazow, jest rowna %lu",
					tab[0], tab[1], z);
			}
			break;
		case 3:
			mvprintw(10, 10, "Wybrales wariacje z powtorzeniami.");
			mvprintw(11, 10, "Podaj ilosc elementow w zbiorze (n), oraz ilosc elementow ciagu w ktorym maja zostac umieszczone (k)");
			if(komb(2)){
				unsigned long z=0;
				z=static_cast<unsigned long>(pow((double)(tab[0]), (double)(tab[1])));
				mvprintw(15, 10, "liczba sposobow, w jaki z %lu elementow"
					"mozna utworzyc ciag skladajacy sie z %lu niekoniecznie roznych wyrazow, jest rowna %lu",
					tab[0], tab[1], z);
			}
			break;
		case 4:
			mvprintw(10, 10, "Wybrales kombinacje, podaj ile elementow wybierasz sposrod ilu mozliwych.");
			if(komb(2)){
				unsigned long z=1, bla=0;
				if(tab[0]>=tab[1]){
					mvprintw(15, 10, "Pierwsza liczba musi byc mniejsza badz rowna drugiej");
					break;
				}
				for(unsigned int i=0; i<tab[0]; i++)
					z*=((tab[1]-tab[0]+1+i)/(long double)(i+1));
				bla=static_cast<unsigned long>(z);
				mvprintw(15, 10, "liczba sposobow, w jaki sposrod %lu elementow"
					"mozna wybrac %lu elementow, jest rowna %lu",
					tab[0], tab[1], z);
			}
			break;
	}
	if(out==false)stop();
}
bool komb (unsigned short danych){
	long double x=0;
	for(unsigned short i=0; i<danych; i++){	
		int g;
		echo();
		if(i==0)printw("\n");
		g=scanw("%lf", &x);
		if(g!=1){
			attron(A_BOLD | A_UNDERLINE);
			mvprintw(20, 30, "Wprowadzono nieprawidlowy format danych!");
			attroff(A_BOLD | A_UNDERLINE);
			return false;
		}
		else if (x<1){
			attron(A_BOLD | A_UNDERLINE);
			mvprintw(20, 30, "musisz podac liczbe wieksza badz rowna 1");
			attroff(A_BOLD | A_UNDERLINE);
			return false;
		}
		else if ((long long)(x)!=x){
			attron(A_BOLD | A_UNDERLINE);
			mvprintw(20, 30, "musisz podac liczbe calkowita!");
			attroff(A_BOLD | A_UNDERLINE);
			return false;
		}
		tab[i]=static_cast<unsigned long>(x);
	}
	return true;
}