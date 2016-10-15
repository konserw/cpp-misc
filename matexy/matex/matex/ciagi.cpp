/*
MaTeX2 - program matematyczny z lepszym interfejsem :)
Copyright (C) 2009 Kamil Strzempowicz
Niniejszy program jest wolnym oprogramowaniem; mo�esz go 
rozprowadza� dalej i/lub modyfikowa� na warunkach Powszechnej
Licencji Publicznej GNU, wydanej przez Fundacj� Wolnego
Oprogramowania - wed�ug wersji 2-giej tej Licencji lub kt�rej�
z p�niejszych wersji. 
Niniejszy program rozpowszechniany jest z nadziej�, i� b�dzie on 
u�yteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domy�lnej 
gwarancji PRZYDATNO�CI HANDLOWEJ albo PRZYDATNO�CI DO OKRE�LONYCH 
ZASTOSOWA�. W celu uzyskania bli�szych informacji - Powszechna 
Licencja Publiczna GNU. 
Z pewno�ci� wraz z niniejszym programem otrzyma�e� te� egzemplarz 
Powszechnej Licencji Publicznej GNU (GNU General Public License);
je�li nie - napisz do Free Software Foundation, Inc., 675 Mass Ave,
Cambridge, MA 02139, USA.

Pozdrawiam, konserw.
konserw@gmail.com
*/

#include "PCH.h"
#include "naglowek.h"

//unsigned short menuc();

void ciagi(unsigned short ktory2){
	bool out=false;
	int n;
	double x;

	clear();
	logo();
	switch(ktory2){
		case 0:
			out=true;
			break;
		case 1:
			mvprintw(10, 10, "Ktory wyraz ciagu chcesz wyliczyc?");
			mvprintw(11, 10, "(musisz oczywiscie wprowadzic liczbe nalezaca do N+, inaczej nastapi zakonczenie programu)");
			if(in(1, J)) n=static_cast<int>(tablica[0]);
			else break;
			//clear();
			mvprintw(13, 10, "Podaj pierwszy wyraz ciagu i roznice");
			if(in(2, R)){
				x=tablica[0]+((n-1)*tablica[1]);
				mvprintw(17, 10, "a%lu = %lf", n, x);
			}
			break;
		case 2:
			mvprintw(10, 10, "Ktory wyraz ciagu chcesz wyliczyc?");
			mvprintw(11, 10, "(musisz oczywiscie wprowadzic liczbe nalezaca do N+, inaczej nastapi zakonczenie programu)");
			if(in(1, J)) n=static_cast<int>(tablica[0]);
			else break;
			clear();
			mvprintw(12, 10, "Podaj sume czesciowa n pierwszych wyrazow oraz a1");
			if(in(2, R)){
				x=((2*tablica[0])/n)-tablica[1];
				mvprintw(14, 10, "a%lu = %lf", n, x);
			}
			break;
		case 3:
			mvprintw(10, 10, "Podaj wyraz poprzedni i wyraz nastepny");
			if(in(2, R))
				mvprintw(12, 10, "Srodkowy wyraz jest rowny: %lf", (tablica[0]+tablica[1])/2);
			break;
		case 4:
			mvprintw(10, 10, "Sume czesciowa ilu pierwszych wyrazow chcesz obliczyc?");
			mvprintw(11, 10, "(musisz oczywiscie wprowadzic liczbe nalezaca do N+, inaczej nastapi zakonczenie programu)");
			if(in(1, J)) n=static_cast<int>(tablica[0]);
			else break;
			clear();
			mvprintw(12, 10, "Podaj pierwszy wyraz ciagu i roznice");
			if(in(2, R)){
				x=tablica[0]+((n-1)*tablica[1]);
				mvprintw(14, 10, "Suma %lu pierwszych wyrazow jest rowna %lf", n, x);
			}
			break;
		case 5:
			mvprintw(10, 10, "Ktory wyraz ciagu chcesz wyliczyc?");
			mvprintw(11, 10, "(musisz oczywiscie wprowadzic liczbe nalezaca do N+, inaczej nastapi zakonczenie programu)");
			if(in(1, J)) n=static_cast<int>(tablica[0]);
			else break;
			clear();
			mvprintw(12, 10, "Podaj pierwszy wyraz ciagu i iloraz");
			if(in(2, R)){
				x=tablica[0]*pow(tablica[1], n-1);
				mvprintw(14, 10, "a%lu = %lf", n, x);
			}
			break;
		case 6:
			mvprintw(10, 10, "Podaj wyraz poprzedni i wyraz nastepny");
			if(in(2, R))
				mvprintw(12, 10, "Srodkowy wyraz jest rowny: %lf", sqrt(tablica[0]*tablica[1]));
			break;
		case 7:
			mvprintw(10, 10, "Sume czesciowa ilu pierwszych wyrazow chcesz obliczyc?");
			mvprintw(11, 10, "(musisz oczywiscie wprowadzic liczbe nalezaca do N+, inaczej nastapi zakonczenie programu)");
			if(in(1, J)) n=static_cast<int>(tablica[0]);
			else break;
			clear();
			mvprintw(12, 10, "Podaj pierwszy wyraz ciagu i iloraz");
			if(in(2, R)){
				if(tablica[1]==1) x=n*tablica[0];
				else x=tablica[0]*((1-pow(tablica[1], n))/(1-tablica[1]));
				mvprintw(14, 10, "Suma %lu pierwszych wyrazow jest rowna %lf", n, x);
			}
			break;
	}
	if(!out)stop();
}