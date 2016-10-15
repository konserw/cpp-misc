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

double trapez(double a, double b, double h){return(((a+b)*h)/2);}

void trapezy(unsigned short ktory3){
	double x; //bufor
	bool out=false;

	clear();
	logo();
	switch(ktory3){
		case 0:
			out=true;
			break;
		case 1:
			mvprintw(10, 10, "Wybrales >zwykly< trapez. Podaj dlugosci obu podstaw i wysokosci");
			if(in(3, N)){
				x=(tablica[0]+tablica[1])*tablica[2]/2;
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
			}
			break;
		case 2:
			mvprintw(10, 10, "Wybrales trapez rownoramienny, podaj wysokosc, ramie i krotsza podstawe");
			if(in(3, N)){
				tablica.push_back((2*sqrt(pow(tablica[1],2)-pow(tablica[0],2)))+tablica[2]); //d³u¿sza podstawa - b
				x=trapez(tablica[2], tablica[3], tablica[0]);
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
				x=(2*tablica[1])+ tablica[2] + tablica[3];
				mvprintw(13, 10, "Obwod wynosi: %lf", x);
			}
			break;
		case 3:
			mvprintw(10, 10, "Wybrales trapez rownoramienny, podaj ramie i obie podstawy");
			if(in(3, N)){
				x=sqrt((tablica[0]*tablica[0])-(pow((abs(tablica[2]-tablica[1])/2), 2)));
				tablica.push_back(x);
				x=trapez(tablica[1],tablica[2],tablica[3]);
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
				x=tablica[1]+tablica[2]+tablica[0]+tablica[0];
				mvprintw(13, 10, "Obwod wynosi: %lf", x);
			}
			break;
		case 4:
			mvprintw(10, 10, "Wybrales trapez rownoramienny, podaj miare kata ostrego, ramie i krotsza podstawe");
			if(in(3, N)){
				tablica.push_back(tablica[1]*sin(tablica[0]*M_PI/180));
				tablica.push_back(tablica[2]+(2*tablica[1]*cos(tablica[0]*M_PI/180)));
				x=trapez(tablica[2],tablica[4],tablica[3]);
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
				x=tablica[2]+tablica[4]+tablica[1]+tablica[1];
				mvprintw(13, 10, "Obwod wynosi: %lf", x);
			}
			break;
		case 5:
			mvprintw(10, 10, "Wybrales trapez rownoramienny, podaj miare kata ostrego, wysokosc i krotsza podstawa");
			if(in(3, N)){
				tablica.push_back(tablica[2]+(2*tablica[1]*ctg(tablica[0])));
				tablica.push_back(tablica[1]/sin(tablica[0]*M_PI/180));
				x=trapez(tablica[2],tablica[3],tablica[1]);
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
				x=tablica[2]+tablica[3]+tablica[4]+tablica[4];
				mvprintw(13, 10, "Obwod wynosi: %lf", x);
			}
			break;
		case 6:
			mvprintw(10, 10, "Wybrales trapez prostokatny, podaj miare kat ostrego, wysokosc i krotsza podstawe");
			if(in(3, N)){
				tablica.push_back(tablica[2]+(tablica[1]*ctg(tablica[0])));
				tablica.push_back(sqrt(pow(tablica[3]-tablica[2],2)+pow(tablica[1],2)));
				x=trapez(tablica[2],tablica[3],tablica[1]);
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
				x=tablica[2]+tablica[3]+tablica[4]+tablica[1];
				mvprintw(13, 10, "Obwod wynosi: %lf", x);
			}
			break;
		case 7:
			mvprintw(10, 10, "Wybrales trapez prostokatny, podaj miare kata ostrego, ramie i krotsza podstawe");
			if(in(3, N)){
				tablica.push_back(tablica[1]*sin(tablica[0]*M_PI/180));
				tablica.push_back(tablica[2]+(2*tablica[1]*cos(tablica[0]*M_PI/180)));
				x=trapez(tablica[2],tablica[4],tablica[3]);
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
				x=tablica[2]+tablica[4]+tablica[1]+tablica[3];
				mvprintw(13, 10, "Obwod wynosi: %lf", x);
			}
			break;
		case 8:
			mvprintw(10, 10, "Wybrales trapez prostokatny, podaj obie podstawy i dluzsza przekatna");
			if(in(3, N)){
				tablica.push_back(sqrt((tablica[2]*tablica[2])-(tablica[1]*tablica[1])));
				tablica.push_back(sqrt(pow(tablica[1]-tablica[0],2)+pow(tablica[3],2)));
				x=trapez(tablica[0],tablica[1],tablica[3]);
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
				x=tablica[0]+tablica[1]+tablica[4]+tablica[3];
				mvprintw(13, 10, "Obwod wynosi: %lf", x);
			}
			break;
		case 9:
			mvprintw(10, 10, "Wybrales trapez prostokatny, podaj obie podstawy i krotsza przekatna");
			if(in(3, N)){
				tablica.push_back(sqrt((tablica[2]*tablica[2])-(tablica[0]*tablica[0])));
				tablica.push_back(sqrt(pow(tablica[1]-tablica[0],2)+pow(tablica[3],2)));
				x=trapez(tablica[0],tablica[1],tablica[3]);
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
				x=tablica[0]+tablica[1]+tablica[4]+tablica[3];
				mvprintw(13, 10, "Obwod wynosi: %lf", x);
			}
			break;
		}			
	if(out==false)stop();
}
void trojkaty(unsigned short ktory3){
bool out=false;
	double x; //bufor

	clear();
	logo();
	switch(ktory3){
		case 0: 
			out=true;
			break;
		case 1:
			mvprintw(10, 10, "Wybrales typowy trojkat, podaj bok oraz wysokosc opuszczona na ten bok.");
			if(in(2, N)){
				x=tablica[0]*tablica[1]/2;
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
			}
			break;
		case 2:
			mvprintw(10, 10, "Wybrales trojkat rownoboczny. Podaj dlugosc boku tego trojkata.");
			if(in(1, N)){
				x=tablica[0]*tablica[0]/4;
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf pierwiastkow z 3", x);
				x=tablica[0]*tablica[0]*sqrt(3.0)/4;
				mvprintw(13, 10, "Czyli w przyblizeniu: %lf", x);
				x=3*tablica[0];
				mvprintw(14, 10, "Obwod wynosi: %lf", x);
			}
			break;
		case 3:
			mvprintw(10, 10, "Wybrales wzor herona, podaj boki trojkata.");
			if(in(3, N)){
				double p;
				if (!( 
                        abs( tablica[1] - tablica[3] ) < tablica[0] && 
                        tablica[0] < (tablica[1] + tablica[3]) 
                    )){
					mvprintw(12, 10, "Z podanych bokow nie da sie skonstruowac trojkata na plaszczyznie euklidesowej");
					break;
				}
				p=((tablica[0]+tablica[1]+tablica[2])/2);
				x=sqrt(p*(p-tablica[0])*(p-tablica[1])*(p-tablica[2]));
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
			}
			break;
		case 4:
			mvprintw(10, 10, "Wybrales trojkat. Podaj dlugosci 2 bokow i miare kata miedzy nimi(w stopniach).");
			if(in(3, N)){
				tablica.push_back(twcos(tablica[0],tablica[1],tablica[2]));
				if (!( 
                        abs( tablica[1] - tablica[3] ) < tablica[0] && 
                        tablica[0] < (tablica[1] + tablica[3]) 
                    )){
					mvprintw(12, 10, "Z podanych bokow nie da sie skonstruowac trojkata na plaszczyznie euklidesowej");
					break;
				}
				x=tablica[0]*tablica[1]*sin(tablica[2]*M_PI/180);
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
				x=tablica[0]+tablica[1]+tablica[3];
				mvprintw(13, 10, "Obwod wynosi: %lf", x);
			}
			break;
	}
	if(out==false)stop();
}
void kwadraty(unsigned short ktory3){
	bool out=false;
	double x; //bufor

	clear();
	logo();
	switch(ktory3){
		case 0: 
			out=true;
			break;
		case 1:
			mvprintw(10, 10, "Wybrales kwadrat, podaj dlugosc jego boku.");
			if(in(1, N)){
				x=pow(tablica[0], 2);
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
				x=4*tablica[0];
				mvprintw(13, 10, "Obwod wynosi: %lf", x);
			}
			break;
		case 2:
			mvprintw(10, 10, "Wybrales kwadrat, podaj dlugosc jego przekatnej.");
			if(in(1, N)){
				x=pow(tablica[0], 2)/2;
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
				x=2*tablica[0];
				mvprintw(13, 10, "Obwod wynosi: %lf pierwiastkow z 2", x);
				x=2*tablica[0]*sqrt(2.0);
				mvprintw(14, 10, "Czyli  w przyblizeniu: %lf", x);
			}
			break;
	}
	if(!out)stop();
}
void romby(unsigned short ktory3){
	bool out=false;
	double x; //bufor

	clear();
	logo();
	switch(ktory3){
		case 0: 
			out=true;
			break;
		case 1:
			mvprintw(10, 10, "Wybrales typowy romb, podaj dlugosc jego boku i wysokosc.");
			if(in(2, N)){
				x=tablica[0]*tablica[1];
				mvprintw(12, 10, "Pole powierzchni tego rombu wynosi: %lf", x);
				x=4*tablica[0];
				mvprintw(13, 10, "Obwod wynosi: %lf", x);
			}
			break;
		case 2:
			mvprintw(10, 10, "Wybrales romb, podaj dlugosc jego boku i miare kata ostrego w stopniach.");
			if(in(2, N)){
				x=pow(tablica[0], 2)*sin(tablica[1]*M_PI/180);
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
				x=4*tablica[0];
				mvprintw(13, 10, "Obwod wynosi: %lf", x);
			}
			break;
		case 3:
			mvprintw(10, 10, "Wybrales romb, podaj dlugosci jego przekatnych.");
			if(in(2, N)){
				x=tablica[0]*tablica[1]/2;
				mvprintw(12, 10, "Pole powierzchni tego rombu wynosi: %lf", x);
				x=2*(sqrt(tablica[0] + tablica[1]));
				mvprintw(13, 10, "Obwod wynosi: %lf", x);
			}
			break;
	}
	if(!out)stop();
}
void rownolegloboki(unsigned short ktory3){
bool out=false;
	double x; //bufor

	clear();
	logo();
	switch(ktory3){
		case 0: 
			out=true;
			break;
		case 1:
			mvprintw(10, 10, "Wybrales typowy rownoleglobok, podaj dlugosc jego boku i wysokosci.");
			if(in(2, N)){
				x=tablica[0]*tablica[1];
				mvprintw(12, 10, "Pole powierzchni tego rownolegloboku wynosi: %lf", x);
			}
			break;
		case 2:
			mvprintw(10, 10, "Wybrales rownoleglobok, podaj dlugosci jego bokow i miare kata ostrego (w stopniach).");
			if(in(3, N)){
				x=tablica[0]*tablica[1]*sin(tablica[2]*M_PI/180);
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
				x=2*(tablica[0] + tablica[1]);
				mvprintw(13, 10, "Obwod wynosi: %lf", x);
			}
			break;
		case 3:
			mvprintw(10, 10, "Wybrales rownoleglobok, podaj dlugosci jego przekatnych i miare kata ostrego zawartego miedzy nimi (w stopniach).");
			if(in(3, N)){
				x=tablica[0]*tablica[1]*sin(tablica[2]*M_PI/180)/2;
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
				x=2*((twcos(tablica[0]/2,tablica[1]/2,tablica[2]))+(twcos(tablica[0]/2,tablica[1]/2,180-tablica[2])));
				mvprintw(13, 10, "Obwod wynosi: %lf", x);
			}
			break;
	}
	if(!out)stop();
}
void planimetria(unsigned short ktory2){
	bool out=false;
	double x; //bufor

	clear();
	logo();
	switch(ktory2){
		case 0: 
			out=true;
			break;
		case 3:
			mvprintw(10, 10, "Wybrales prostokat, podaj dlugosci jego bokow.");
			if(in(2, N)){
				x=tablica[0]*tablica[1];
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
				x=(tablica[1]+tablica[0])*2;
				mvprintw(13, 10, "Obwod wynosi: %lf", x);
			}
			break;
		case 7:
			mvprintw(10, 10, "Wybrales deltoid, podaj dlugosci jego przekatnych.");
			if(in(2, N)){
				x=(tablica[0]*tablica[1])/2;
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf", x);
			}
			break;
		case 8:
			mvprintw(10, 10, "Wybrales szesciokat foremny, podaj dlugosc jego boku.");
			if(in(1, N)){
				x=3*pow(tablica[0], 2)/2;
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf pierwiastkow z 3", x);
				x*=sqrt(3.0);
				mvprintw(13, 10, "Czyli  w przyblizeniu: %lf", x);
				x=6*tablica[0];
				mvprintw(14, 10, "Obwod wynosi: %lf", x);
			}
			break;
		case 9:
			mvprintw(10, 10, "Wybrales kolo, podaj dlugosc jego promienia.");
			if(in(1, N)){
				x=pow(tablica[0],2);
				mvprintw(12, 10, "Pole powierzchni wynosi: %lf PI", x);
				x=pow(tablica[0],2)*M_PI;
				mvprintw(13, 10, "Czyli  w przyblizeniu: %lf", x);
				x=2*tablica[0];
				mvprintw(14, 10, ".Obwod wynosi: %lf PI", x);
				x=2*tablica[0]*M_PI;
				mvprintw(15, 10, "Czyli w przyblizeniu: %lf", x);
			}
			break;
	}
	if(out==false)stop();
}