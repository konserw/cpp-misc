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

long double trojkatsin(double a, double b, double alfa){
return((a*b*sin(alfa*M_PI/180))/2);}

void grantroj(unsigned short ktory4){
	bool out=false;
	double p, pole;

	clear();
	logo();

	switch(ktory4){
		case 0:
			out=true;
			break;
		case 1:
			mvprintw(11, 10, "Podaj wysokosc graniastoslupa, a nastepnie dlugosc boku podstawy i wysokosci opuszczonej na ten bok");
			if(in(3, N))
				mvprintw(13, 10, "Objetosc tego graniastoslupa wynosi %lf", (tablica[0] * tablica[1] * tablica[2])/2);
			break;
		case 2:
			mvprintw(11, 10, "Podaj wysokosc graniastoslupa, a nastepnie dlugosc 2 boków podstawy i miare kata zawartego miedzy nimi.");
			if (in(4, N)) {
				mvprintw(13, 10, "Objetosc tego graniastoslupa wynosi: %lf",
					tablica[0]*trojkatsin(tablica[1],tablica[2],tablica[3]));
				mvprintw(14, 10, "Calkowite pole powierzchni wynosi: %lf",
					(2*trojkatsin(tablica[1],tablica[2],tablica[3]))+(tablica[1]*tablica[0])+(tablica[2]*tablica[0])+(twcos(tablica[1],tablica[2],tablica[3])*tablica[0]));
			}
			break; 
		case 3:
			mvprintw(11, 10, "Podaj wysokosc graniastoslupa, a nastepnie dlugosc 3 boków podstawy.");
			if (in(4, N)) {
				if (!( 
                        abs( tablica[1] - tablica[3] ) < tablica[0] && 
                        tablica[0] < (tablica[1] + tablica[3]) 
                    )){
					mvprintw(12, 10, "Z podanych bokow nie da sie skonstruowac trojkata na plaszczyznie euklidesowej");
					break;
				}
				p=((tablica[0]+tablica[1]+tablica[2])/2);
				pole=sqrt(p*(p-tablica[0])*(p-tablica[1])*(p-tablica[2]));
				mvprintw(13, 10, "Objetosc tego graniastoslupa wynosi: ", tablica[0]*pole);
				mvprintw(14, 10, "Calkowite pole powierzchni tego graniastoslupa wynoci ",
					(tablica[1]*tablica[0])+(tablica[2]*tablica[0])+(tablica[3]*tablica[0])+(2*pole));
			}
			break;
		case 4:
			mvprintw(11, 10, "Podaj wysokosc graniastoslupa, a nastepnie pole jego podstawy.");
			if (in(2, N)) 
				mvprintw(11, 10, "Objetosc tego graniastoslupa wynosi %lf", tablica[0]*tablica[1]);
			break;
	}
	if(!out)stop();
}
void graniastoslupy(unsigned short ktory3){
	bool out=false;

	clear();
	logo();

	switch(ktory3){
		case 0:
			out=true;
			break;
		case 1:
			mvprintw(11, 10, "Wybrales szescian. Podaj dlugosc krawedzi.");
			if(in(1, N)){
				mvprintw(13, 10, "Calkowite pole powierzchni wynosi: %lf", 6*pow(tablica[0], 2));
				mvprintw(14, 10, "Objetosc wynosi: %lf", pow(tablica[0],3));
			}
			break;
		case 2:
			mvprintw(11, 10, "Wybrales prostopadloscian. Podaj dlugosci krawedzi.");
			if(in(3, N)){
				tablica.push_back(2*(
					(tablica[0]*tablica[1])
					+ (tablica[2]*tablica[1])
					+ (tablica[0]*tablica[2])
				));
				mvprintw(13, 10, "Calkowite pole powierzchni wynosi: %lf", tablica[3]);
				mvprintw(14, 10, "Objetosc wynosi: %lf", tablica[0]*tablica[1]*tablica[2]);
			}
			break;
		case 4:
			mvprintw(11, 10, "Wybrales graniastoslup prawidlowy trojkatny. Podaj wysokosc tego graniastoslupa oraz dlugosc boku podstawy.");
			if(in(2, N)){
				tablica.push_back(
					pow(tablica[1], 2)/2
				);
				tablica.push_back(3*tablica[0]*tablica[1]);
				mvprintw(13, 10, "Calkowite pole powierzchni wynosi: %lf + %lf pierwiastkow z 3", tablica[2], tablica[3]);
				mvprintw(15, 10, "Czyli  w przyblizeniu: %lf", (tablica[3]*sqrt(3.0))+tablica[2]);
				tablica[3]=(pow(tablica[1], 2)/4)*tablica[0];
				mvprintw(17, 10, "Objetosc tego graniastoslupa wynosi: %lf pierwiastkow z 3", tablica[3]);
				mvprintw(19, 10, "Czyli  w przyblizeniu: %lf", tablica[3]*sqrt(3.0));
			}
			break;
		case 5:
			mvprintw(20, 20, "sorry, ta czesc jest niegotowa");
			break;
		case 6:
			mvprintw(20, 20, "sorry, ta czesc jest niegotowa");
			break;
		case 7:													// graniastoslup prawidlowy szesciokatny	
			mvprintw(11, 10, "Wybrales graniastoslup prawidlowy szesciokatny. Podaj Jego wysokosc oraz dlugosc krawedzi podstawy");
			if(in(2, N)){
				tablica.push_back(3*tablica[1]*tablica[1]);
				tablica.push_back(6*tablica[1]*tablica[0]);
				mvprintw(13, 10, "Calkowite pole powierzchni wynosi %lf + %lf pierwiastkow z 3", tablica[3], tablica[2]);
				mvprintw(15, 10, "Czyli  w przyblizeniu %lf", tablica[3]+(tablica[2]*sqrt(3.0)));
				tablica[2]=(pow(tablica[1], 2)*tablica[0])/4;
				mvprintw(17, 10, "Objetosc tego graniastoslupa wynosi %lf pierwiastkow z 3", tablica[2]);
				mvprintw(19, 10, "Czyli  w przyblizeniu %lf", tablica[2]*sqrt(3.0));
			}
			break; 
	}
	if(!out)stop();
}
void ostroslupy(unsigned short ktory3){
	bool out=false;

	clear();
	logo();

	switch(ktory3){
		case 0:
			out=true;
			break;
		case 1:
			mvprintw(11, 10, "Wybrales czworoscian. Podaj dlugosc boku.");
			if (in(1, N)) {
				tablica.push_back(pow(tablica[0], 2));
				mvprintw(13, 10, "Calkowite pole powierzchni wynosi %lf pierwiastkow z 3", tablica[1]);
				mvprintw(15, 10, "Czyli  w przyblizeniu %lf ", tablica[1]*sqrt(3.0));
				tablica[1]=(tablica[0]*tablica[0]*tablica[0])/12;
				mvprintw(17, 10, "Objetosc wynosi %lf pierwiastkow z 2", tablica[1]);
				mvprintw(19, 10, "Czyli  w przyblizeniu %lf", tablica[1]*sqrt(2.0));
			}
			break; 	
		default:
			mvprintw(20, 20, "sorry, ta czesc jest niegotowa");
			break;
		case 5:
			mvprintw(11, 10, "Wybrales ostroslup prawidlowy czworokatny. Poadaj Wysokosc tego ostroslupa i dlugosc krawedzi podstawy.");
			if (in(2, N)) {
				mvprintw(13, 10, "Calkowite pole powierzchni wynosi %lf",
					(4 * tablica[1] * tablica[0]) + pow(tablica[1], 2));
				mvprintw(15, 10, "Objetosc wynosi %lf", pow(tablica[1], 2)*tablica[0]);
			}
			break; 
		case 6:
			mvprintw(11, 10, "Wybrales ostroslup prawidlowy szesciokatny. Poadaj Wysokosc tego ostroslupa i dlugosc krawedzi podstawy.");
			if (in(2, N)) {
				tablica.push_back(3*pow(tablica[1], 2));
				tablica.push_back(6 * tablica[1] * tablica[0]);
				mvprintw(13, 10, "Calkowite pole powierzchni wynosi %lf + %lf pierwiastkow z 3", tablica[3], tablica[2]);
				mvprintw(15, 10, "Czyli  w przyblizeniu %lf", tablica[3]+(tablica[2]*sqrt(3.0)));
				tablica[2]*=tablica[0];
				tablica[2]/=2;
				mvprintw(17, 10, "Objetosc wynosi %lf pierwiastkow z 3", tablica[2]);
				mvprintw(19, 10, "Czyli  w przyblizeniu %lf", tablica[2]*sqrt(3.0));
			}
			break; 
	}
	if(!out)stop();
}
void obrotowe(unsigned short ktory3){
	bool out=false;

	clear();
	logo();

	switch(ktory3){
		case 0:
			out=true;
			break;
		case 1:
			mvprintw(11, 10, "Wybrales walec. Podaj wysokosc i promien podstawy");
			if (in(2, N)) {
				tablica.push_back(2 * tablica[1] * (tablica[1] + tablica[0]));
				mvprintw(13, 10, "Calkowite pole powierzchni wynosi %lf pi", tablica[2]);
				mvprintw(15, 10, "czyli w przyblizeniu %lf", tablica[2] * M_PI);
				tablica[2]=tablica[1]*tablica[1]*tablica[0];
				mvprintw(17, 10, "Objetosc wynosi %lf pi", tablica[2]);
				mvprintw(19, 10, "czyli w przyblizeniu %lf", tablica[2] * M_PI);	
			}
			break;
		case 2:
			mvprintw(11, 10, "Wybrales wstozek. Podaj wysokosc i promien podstawy");
			if (in(2, N)) {		
				tablica.push_back(tablica[1]*(tablica[1]+tablica[3]));
				tablica.push_back(sqrt((tablica[1]*tablica[1])+(tablica[0]*tablica[0])));
				mvprintw(13, 10, "Calkowite pole powierzchni wynosi %lf pi", tablica[2]);
				mvprintw(15, 10, "czyli w przyblizeniu %lf", tablica[2] * M_PI);
				tablica[2]=(tablica[1]*tablica[1]*tablica[0])/3;
				mvprintw(17, 10, "Objetosc wynosi %lf pi", tablica[2]);
				mvprintw(19, 10, "czyli w przyblizeniu %lf", tablica[2] * M_PI);
			}
			break; 
		case 3:
			mvprintw(11, 10, "Wybrales kule. Podaj jej promien");
			if (in(1, N)) {
				tablica[0]=4*tablica[0]*tablica[0];
				mvprintw(13, 10, "Calkowite pole powierzchni wynosi %lf pi", tablica[0]);
				mvprintw(15, 10, "czyli w przyblizeniu %lf", tablica[0] * M_PI);
				tablica[0]=(4/3)*tablica[0]*tablica[0]*tablica[0];
				mvprintw(17, 10, "Objetosc wynosi %lf pi", tablica[0]);
				mvprintw(19, 10, "czyli w przyblizeniu %lf", tablica[0] * M_PI);
			}
			break; 
	}
	if(!out)stop();
}