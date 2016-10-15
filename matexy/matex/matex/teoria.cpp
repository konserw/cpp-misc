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

void teoria(unsigned short ktory2){
	bool out=false;
	unsigned long reszta=1;

	clear();
	logo();
	switch(ktory2){
		case 0:
			out=true;
			break;
		case 1:{
			unsigned long liczba;
			mvprintw(10, 10, "Wybierz jaka liczbe chcesz sprawdzic");
			mvprintw(11, 10, "(musi to byc oczywiscie liczba naturalna)");
			if(in(1, J)){
				liczba=static_cast<unsigned long>(tablica[0]);
				for (unsigned long i=2;( i<liczba && reszta!=0); i++) reszta=liczba%i;
				if (reszta!=0) mvprintw(13, 10, "Liczba %lu jest liczba pierwsza", liczba);
				else mvprintw(13, 10, "Liczba %lu jest liczba zlozona", liczba);
			}
			break;
		}
		case 2:{
			unsigned long liczba;
			bool podzielna=false;
			unsigned long liczb=0;
			mvprintw(10, 10, "Wybrales szukanie liczb pierwszych. Jaka najwieksza liczbe chcesz sprawdzic?");
			mvprintw(11, 10, "(musi to byc oczywiscie liczba naturalna)");
			if(in(1, J)){
				unsigned long zadana=static_cast<unsigned long>(tablica[0]);
				liczba=2;
				clear();
				mvprintw(13, 10, "Liczby pierwsze: ");
				refresh();
				do{
					podzielna=false;
					reszta=1;
					liczba++;
					for (unsigned long i=2; (i<liczba && reszta!=0); ++i){
						reszta=liczba%i;
						if (reszta==0) podzielna=true;
					}
					if (!podzielna){
						printw("%lu; ", liczba);
						liczb++;
					}
					if(liczb%10==0) refresh();
				}while (liczba<zadana);
				printw("\n Istnieje %lu liczb pierwszych mniejszych od %lu", liczb, zadana);
			}
			break;
		}
		case 3:{
			long liczba;
			mvprintw(10, 10, "Wybierz jaka liczbe chcesz sprawdzic");
			mvprintw(11, 10, "(musi to byc oczywiscie liczba calkowita)");
			if(in(1, R)){
				if(!(tablica[0]==(long)(tablica[0]))){
					mvprintw(12, 20, "Podales liczbe zmiennoprzecinkowa!");
					break;
				}
				else liczba=static_cast<long>(tablica[0]);
				mvprintw(13, 10, "Dzielniki liczby %li to:", liczba);
				move(14, 10);
				for (long i=-(abs(liczba));i<=abs(liczba); ++i){
					if(i==0) continue;
					reszta=liczba%i;
					if (reszta==0) printw("%li; ", i);
				}
			}
			break;
		}
	}
	if(!out)stop();
}