/*
matex - program matematyczny
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

#include <iostream.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265	//definicja PI
//deklaracja zmiennych globalnych
bool s,zero;
long double pole;
char out;
unsigned short i, danych, liczba=0, q;
//deklaracja funkcji pól
long double trojkat(long double a,long double h){
return((a*h)/2);}
long double kwadrat(long double a){
return(a*a);}
long double szesciokat(long double a){
return((6*a*a)/4);}
void heron(long double a, long double b, long double c){
long double p;
if (!(abs(b-c)<a && a<(b+c))){
	mvprintw(11, 10, "Z podanych bokow nie da sie skonstruowac trojkata na plaszczyznie euklidesowej");
	s=true;
	}
else{
p=((a+b+c)/2);
pole=(sqrt(p*(p-a)*(p-b)*(p-c)));}
}
long double rownoboczny(long double a){
return(a*a/4);}
long double prostokat(long double a, long double b){
return(a*b);}
long double trojkatsin(long double a, long double b, long double alfa){
return((a*b*sin(alfa*PI/180))/2);}
long double kwadrat_d(long double d){
return((d*d)/2);}
long double romb(long double a, long double h){
return(a*h);}
long double rombsin(long double a, long double alfa){
return(a*a*sin(alfa*PI/180));}
long double rombd(long double d1, long double d2){
return((d1*d2)/2);}
long double rownosin(long double a, long double b, long double alfa){
return(a*b*sin(alfa*PI/180));}
long double rownod(long double d1, long double d2, long double alfa){
return((d1*d2*sin(alfa*PI/180))/2);}
long double deltoid(long double d1, long double d2){
return((d1*d2)/2);}
long double trapez(long double a, long double b, long double h){
return(((a+b)*h)/2);}
long double pole1(long double a, long double b, long double c){
return(2*(prostokat(a,b)+prostokat(b,c)+prostokat(a,c)));}
//koniec funkcji pól
long double twcos(long double a, long double b, long double alfa){
return(sqrt((a*a)+(b*b)-(2*a*b*cos(alfa*PI/180))));}
long double tg(long double alfa){
if (cos(alfa)!=0)return(sin(alfa*PI/180)/cos(alfa*PI/180));
else return(0);}
long double ctg(long double alfa){
return(1/tg(alfa));}
unsigned long long silnia(__int64 n){ 								//silnia z forum :)
if(n==0)return 1; 
else return n*silnia(n-1);
} 
void spr(){
if (!cin.good()){ 
	cerr   "Podales bledny format danych!\n";
	cin.clear(); 
	cin.ignore();
	s=true;
}
else s=false;
}			
//koniec deklaracji funkcji
using namespace std; 
int main(int argc, char *argv[]){								//poczatek main
do {														//pocz¹tek pêtli
zero=false;
 mvprintw(11, 10, 
"           .       .              _______________           .!.        ,/,.
        `omN-    -dMy             ommmmNNNmmmmmh-            sNd-     `:ymo`
       .yMMm.   /NMM+              ``./Nm:/~~~~`             .hMd.  .+ddo.
      .hMMMy  `sNNMm.    ./oyyhs-    `yM+       ./syyhy/      .dMd:odd+`
     :dmomM/ -hm+yMy   :ydy/-/NN/    :Nd`     .ody/^;yMh`      :NMMh:`
   `+Nd--NN:+mh-`dM/ `sNs.  `yN+    `dN/     -dNo;..;s/`     -odmNMs
  `sNy. /MMmNo` -NN- +My`   :Ny`    oMy`    .dMds++;``    `/hdy:`+MN:
 `yMs`  oMMd:   +Mm` hMy-.-+mM+    -Nm.     -NNs:-[...o`-sdh+.   `yMm-
 :h+`   :y+`    +mo  -shhyo+sh-    -o.       -oyhhyo/-`-hs-`      .ym/\n";
mvprintw(11, 10, "Czym chcesz sie teraz zajac?");
mvprintw(11, 10, "(Wpisz odpowiednia liczbe i nacisnij >>enter ,\n podobnie kiedy program zada innych danych)\n\n"; q=0;	                                                   						q=0;
mvprintw(11, 10, q ": Zakonczenie programu");                                                q++;//0
mvprintw(11, 10, q ": Pola powierzchni i obwody figur plaskich");							q++;//1
mvprintw(11, 10, q ": Calkowite pola powierzchni i objetosci bryl");							q++;//2
mvprintw(11, 10, q ": Pierwiastki trojmianu kwadratowego");									q++;//3
mvprintw(11, 10, q ": Rozwiazywanie ukladu I stopnia 2 rownan z 2 niewiadomymi");			q++;//4
mvprintw(11, 10, q ": Rozwiazywania ukladu I stopnia 3 rownan z 3 niewiadomymi.");			q++;//5
mvprintw(11, 10, q ": Znajdywanie pierwiastkow wielomianu dowolnego stopnia");				q++;//6
mvprintw(11, 10, q ": Kombinatoryka");														q++;//7
mvprintw(11, 10, q ": Ciagi");																q++;//8
mvprintw(11, 10, q ": Cechy podzielnosci i l. pierwsze");									q++;//9
mvprintw(11, 10, q ": Geometria analityczna");													//10
cin>>liczba;
		spr();
		if(s)break;
switch(liczba){														//switch
case 0:{															//quit
    out='t';
    break;
    }
case 1:{         //zrobione :D                                      				//f. plaskie (case 1)
		mvprintw(11, 10, "Wybrales figury plaskie, wybierz typ:");	q=0;
		mvprintw(11, 10, q ": powrot do menu glownego.");			q++;
		mvprintw(11, 10, q ": trojkat");								q++;
		mvprintw(11, 10, q ": trojkat rownoboczny");					q++;
		mvprintw(11, 10, q ": trojkat - 3 boki");					q++;
		mvprintw(11, 10, q ": trojkat - 2 boki i kat");				q++;
		mvprintw(11, 10, q ": kwadrat");								q++;
		mvprintw(11, 10, q ": kwadrat - przekatnej");				q++;
		mvprintw(11, 10, q ": prostokat");							q++;
		mvprintw(11, 10, q ": romb");								q++;
		mvprintw(11, 10, q ": romb - kat");							q++;
		mvprintw(11, 10, q ": romb - przekatna");					q++;
		mvprintw(11, 10, q ": rownoleglobok");						q++;
		mvprintw(11, 10, q ": rownoleglobok - 2 boki i k¹t");		q++;
		mvprintw(11, 10, q ": rownoleglobok - przekatne i kat");		q++;
		mvprintw(11, 10, q ": trapez - rozne przypadki");			q++;	
		mvprintw(11, 10, q ": deltoid");								q++;	  
		mvprintw(11, 10, q ": szesciokat foremny");					q++;
		mvprintw(11, 10, q ": kolo");
		cin>>liczba;    
		spr();
		if(s)break;	
		switch(liczba){											//wybor figory
		case 0: break;
		case 1:{												//trojkat
			mvprintw(11, 10, "Wybrales trojkat, podaj bok oraz wysokosc opuszczona na ten bok");
			danych=2;
			long double tablica[danych+1];
			for(i=0; i<danych; ++i){
				cin>>tablica[i];
				spr();
				if(s)break;
			}
			if(s)break;
			for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
			if (zero) {
				mvprintw(11, 10, "Musisz podac liczbe naturalna\n";
				break;
			}
			else mvprintw(11, 10, "Pole powierzchni wynosi: " trojkat(tablica[0],tablica[1]));
			break;
		} 															//koniec trojkata
		case 2:{													//Trójk¹t równoboczny
			mvprintw(11, 10, "Wybrales trojkat rownoboczny. Podaj dlugosc boku tego trojkata.");
			danych=1;
			long double tablica[danych+1];
			for(i=0; i<danych; ++i){
				cin>>tablica[i];
				spr();
				if(s)break;
			}
			if(s)break;
			for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
			if (zero) {
				mvprintw(11, 10, "Podales ujemna dlugosc.");
				break;
			}
				mvprintw(11, 10, "Pole powierzchni wynosi: " rownoboczny(tablica[0]) " pierwiastkow z 3");
				mvprintw(11, 10, "Czyli  wprzyblizeniu: " rownoboczny(tablica[0])*sqrt(3));
				mvprintw(11, 10, "Obwod wynosi: " 3*tablica[0]);
			break;
		} 															//koniec trojkata równobocznego				  
		case 3:{                                             	    //heron
        	mvprintw(11, 10, "Wybrales wzor herona, podaj boki trojkata.");
			danych=3;
			long double tablica[danych];
			for(i=0; i<danych; ++i){
				spr();
				if(s)break;
			}
			if(s)break;
			for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
			if (zero) {
				mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
				break;
			}
			heron(tablica[0],tablica[1],tablica[2]);
            if(s) break;
			mvprintw(11, 10, "Pole tego trojkata wynosi: " pole);
			mvprintw(11, 10, "Obwod wynosi: " tablica[1]+tablica[2]+tablica[0]);
			break;
		} 															//koniec herona
		case 4:{                                                	//trojkatsin
			mvprintw(11, 10, "Wybrales trojkat. Podaj dlugosci 2 bokow i miare kata miedzy nimi(w stopniach).");
			danych=3;
			long double tablica[danych+1];
			for(i=0; i<danych; ++i){
				cin>>tablica[i];
				spr();
				if(s)break;
			}
			if(s)break;
			for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
			if (zero) {
				mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
				break;
			}
			tablica[3]=twcos(tablica[0],tablica[1],tablica[2]);
			if (!(abs((__int64)(tablica[1]-tablica[3])<tablica[0] && tablica[0]<(tablica[1]+tablica[3])))){
				mvprintw(11, 10, "Z podanych bokow nie da sie skonstruowac trojkata na plaszczyznie euklidesowej");
				break;
			}
			mvprintw(11, 10, "Pole powierzchni tego trojkata wynosi:" trojkatsin(tablica[0],tablica[2],tablica[2]));
			mvprintw(11, 10, "Obwod wynosi: " tablica[0]+tablica[1]+tablica[3]);
			break; 
		}															//koniec trojkatsin 
		case 5:{													//kwadrat
			mvprintw(11, 10, "Wybrales kwadrat, podaj dlugosc jego boku.");
			danych=1;
			long double tablica[danych];
			for(i=0; i<danych; ++i){
				spr();
				if(s)break;
			}
			if(s)break;
			for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
			if (zero) {
				mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
				break;
			}
			mvprintw(11, 10, "Pole powierzchni tego kwadratu wynosi: " kwadrat(tablica[0]));
			mvprintw(11, 10, "Obwod wynosi: " 2*tablica[0]);
			break;
		}          		               		                        //koniec kwadratu
	    case 6:{       	                                       		//kwadrat d
			mvprintw(11, 10, "Wybrales kwadrat, podaj dlugosc jego przekatnej.");
			danych=1;
			long double tablica[danych];
			for(i=0; i<danych; ++i){
				cin>>tablica[i];
				spr();
				if(s)break;
			}
			if(s)break;
			for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
			if (zero) {
				mvprintw(11, 10, "Podales jakas zeowa dlugosc.");
				break;
			}
			mvprintw(11, 10, "Pole powierzchni tego kwadratu wynosi: " kwadrat_d(tablica[0]));
			mvprintw(11, 10, "Obwod wynosi: " 2*tablica[0] " pierwiastkow z 2");
			mvprintw(11, 10, "Czyli  w przyblizeniu: " 2*tablica[0]*sqrt(2));
			break; 
		}															//koniec kwadratu d
		case 7:{                                                    //prostokat
			mvprintw(11, 10, "Wybrales prostokat, podaj dlugosci jego bokow.");
			danych=2;
			long double tablica[danych];
			for(i=0; i<danych; ++i){
				cin>>tablica[i];
				spr();
				if(s)break;
			}
			if(s)break;
			for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
			if (zero) {
				mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
				break;
			}
			mvprintw(11, 10, "Pole powierzchni tego prostokata wynosi: " prostokat(tablica[0], tablica[1]));
			mvprintw(11, 10, "Obwod wynosi: " (tablica[1]+tablica[0])*2);
			break;
		}                                       		       		//koniec prostokata
		case 8:{                                            		//romb
			mvprintw(11, 10, "Wybrales romb, podaj dlugosc jego boku i wysokosc");
			danych=2;
			long double tablica[danych];
			for(i=0; i<danych; ++i){
				cin>>tablica[i];
				spr();
				if(s)break;
			}
			if(s)break;
			for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
			if (zero) {
				mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
				break;
			}
			mvprintw(11, 10, "Pole powierzchni tego rombu wynosi: " romb(tablica[0], tablica[1]));
			mvprintw(11, 10, "Obwod wynosi: " 4*tablica[0]);
			break;
		} 															//koniec romb 
		case 9:{                                             		//romb sin
			mvprintw(11, 10, "Wybrales romb, podaj dlugosc jego boku i miare kata ostrego w stopniach");
			danych=2;
			long double tablica[danych];
			for(i=0; i<danych; ++i){
				cin>>tablica[i];
				spr();
				if(s)break;
			}
			if(s)break;
			for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
			if (zero) {
				mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
				break;
			}
			mvprintw(11, 10, "Pole powierzchni tego rombu wynosi: " rombsin(tablica[0], tablica[1]));
			mvprintw(11, 10, "Obwod wynosi: " 4*tablica[0]);
			break;
		} 															//koniec romb sin
		case 10:{                                               	//romb d
			mvprintw(11, 10, "Wybrales romb, podaj dlugosci jego przekatnych");
			danych=2;
			long double tablica[danych];
			for(i=0; i<danych; ++i){
				cin>>tablica[i];
				spr();
				if(s)break;
			}
			if(s)break;
			for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
			if (zero) {
				mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
				break;
			}
			mvprintw(11, 10, "Pole powierzchni tego rombu wynosi: " rombd(tablica[0], tablica[1]));
			mvprintw(11, 10, "Obwod wynosi: " 2*(sqrt(tablica[0] + tablica[1])));
			break;
		}															//koniec romb d
		case 11:{													//rownoleglobok
			mvprintw(11, 10, "Wybrales rownoleglobok, podaj dlugosc jego boku i wysokosci");
			danych=2;
			long double tablica[danych];
			for(i=0; i<danych; ++i){
				cin>>tablica[i];
				spr();
				if(s)break;
			}
			if(s)break;
			for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
			if (zero) {
				mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
				break;
			}
			mvprintw(11, 10, "Pole powierzchni tego rownolegloboku wynosi: " romb(tablica[0], tablica[1]));
			break;
		}															//koniec rownoleglobok  	
		case 12:{                                                   //rownoleglobok sin
			mvprintw(11, 10, "Wybrales rownoleglobok, podaj dlugosci jego bokow i miare kata ostrego (w stopniach)");
			danych=3;
			long double tablica[danych];
			for(i=0; i<danych; ++i){
				cin>>tablica[i];
				spr();
				if(s)break;
			}
			if(s)break;
			for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
			if (zero) {
				mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
				break;
			}
			mvprintw(11, 10, "Pole powierzchni tego rownolegloboku wynosi: " rownosin(tablica[0], tablica[1], tablica[2]));
			mvprintw(11, 10, "Obwod wynosi: " 2*(tablica[0] + tablica[1]));
			break;
		}  															//koniec rowno sin
		case 13:{                                                   //rownoleglobok d
			mvprintw(11, 10, "Wybrales rownoleglobok, podaj dlugosci jego przekatnych i miare kata ostrego zawartego miedzy nimi (w stopniach)");
			danych=3;
			long double tablica[danych];
			for(i=0; i<danych; ++i){
				cin>>tablica[i];
				spr();
				if(s)break;
			}
			if(s)break;
			for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
			if (zero) {
				mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
				break;
			}
			mvprintw(11, 10, "Pole powierzchni tego rownolegloboku wynosi: " rownod(tablica[0], tablica[1], tablica[2]));
			mvprintw(11, 10, "obwod wynosi: " 2*((twcos(tablica[0]/2,tablica[1]/2,tablica[2]))+(twcos(tablica[0]/2,tablica[1]/2,180-tablica[2]))));
			break;
		} 															//koniec rowno d 		
		case 14:{                                                   //trapez
			mvprintw(11, 10, "Wybrales trapez, wybierz typ trapezu:");							q=0;
			mvprintw(11, 10, q ": powrot do menu glownego.");									q++;
			mvprintw(11, 10, q ": trapez - obie podstawy i wysokosc");					q++;
			mvprintw(11, 10, q ": trapez rownoramienny - wysokosc, ramie i krotsza podstawa");	q++;
			mvprintw(11, 10, q ": trapez rownoramienny - ramie i obie podstawy");				q++;
			mvprintw(11, 10, q ": trapez rownoramienny - kat ostry, ramie i krotsza podstawa");	q++;
			mvprintw(11, 10, q ": trapez rownoramienny - kat ostry, wysokosc i krotsza podstawa");q++;
			mvprintw(11, 10, q ": trapez prostokatny - kat ostry, wysokosc i krotsza podstawa");	q++;
			mvprintw(11, 10, q ": trapez prostokatny - kat ostry, ramie i krotsza podstawa");	q++;
			mvprintw(11, 10, q ": trapez prostokatny - obie podstawy i dluzsza przekatna");		q++;
			mvprintw(11, 10, q ": trapez prostokatny - obie podstawy i krotsza przekatna");		q++;
			mvprintw(11, 10, q ": trapez prostokatny - krotsza podstawa, krotsza przekatna i ramie");		
			cin>>liczba;
			spr();
			if(s)break;
			switch(liczba){											//switch trapezy
			case 0: break;
			case 1:{
				mvprintw(11, 10, "Wybrales >zwykly< trapez. Podaj dlugosci obu podstaw i wysokosci");
				danych=3;
				long double tablica[danych];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
				if (zero) {
					mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
					break;
				}
				mvprintw(11, 10, "Pole powierzchni wynosi: " trapez(tablica[0], tablica[1], tablica[2]));
				break;
			}
			case 2:{
				mvprintw(11, 10, "Wybrales trapez rownoramienny, podaj wysokosc, ramie i krotsza podstawe");
				danych=3;
				long double tablica[danych+1];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
				if (zero) {
					mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
					break;
				}
				tablica[3]=(2*sqrt(pow(tablica[1],2)-pow(tablica[0],2)))+tablica[2]; //d³u¿sza podstawa - b
				mvprintw(11, 10, "Pole powierzchni wynosi: " trapez(tablica[2], tablica[3], tablica[0]));
				mvprintw(11, 10, "Obwod wynosi: " (2*tablica[1])+ tablica[2] + tablica[3]);
			break;
			}
			case 3:{
				mvprintw(11, 10, "Wybrales trapez rownoramienny, podaj ramie i obie podstawy (najpierw krotsza)");
				danych=3;
				long double tablica[danych+1];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
				if (zero) {
					mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
					break;
				}
				tablica[3]=sqrt((tablica[0]*tablica[0])-((kwadrat(tablica[2]-tablica[1])/2)));
				mvprintw(11, 10, "Pole powierzchni wynosi: " trapez(tablica[1],tablica[2],tablica[3]));
				mvprintw(11, 10, "Obwod wynosi: " tablica[1]+tablica[2]+tablica[0]+tablica[0]);
				break;
			}
			case 4:{
				mvprintw(11, 10, "Wybrales trapez rownoramienny, podaj miare kata ostrego, ramie i krotsza podstawe");
				danych=3;
				long double tablica[danych+2];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if(tablica[i]<1){
					zero=true;
					break;
				}
				if (zero) {
					mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
					break;
				}
				tablica[3]=tablica[1]*sin(tablica[0]*PI/180);
				tablica[4]=tablica[2]+(2*tablica[1]*cos(tablica[0]*PI/180));
				mvprintw(11, 10, "Pole powierzchni wynosi: " trapez(tablica[2],tablica[4],tablica[3]));
				mvprintw(11, 10, "Obwod wynosi: " tablica[2]+tablica[4]+tablica[1]+tablica[1]);
				break;
			}
			case 5:{
				mvprintw(11, 10, "Wybrales trapez rownoramienny, podaj miare kata ostrego, wysokosc i krotsza podstawa");
				danych=3;
				long double tablica[danych+2];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
					if (zero) {
						mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
						break;
					}
				tablica[3]=tablica[2]+(2*tablica[1]*ctg(tablica[0]));
				mvprintw(11, 10, "Pole powierzchni wynosi: " trapez(tablica[2],tablica[3],tablica[1]));
				tablica[4]=tablica[1]/sin(tablica[0]*PI/180);
				mvprintw(11, 10, "Obwod wynosi: " tablica[2]+tablica[3]+tablica[4]+tablica[4]);
				break;
			}
			case 6:{
				mvprintw(11, 10, "Wybrales trapez prostokatny, podaj miare kat ostrego, wysokosc i krotsza podstawe");
				danych=3;
				long double tablica[danych+2];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
					if (zero) {
						mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
						break;
					}
				tablica[3]=tablica[2]+(tablica[1]*ctg(tablica[0]));
				mvprintw(11, 10, "Pole powierzchni wynosi: " trapez(tablica[2],tablica[3],tablica[1]));
				tablica[4]=sqrt(pow(tablica[3]-tablica[2],2)+pow(tablica[1],2));
				mvprintw(11, 10, "Obwod wynosi: " tablica[2]+tablica[3]+tablica[4]+tablica[1]);
				break;
			}
			case 7:{
				mvprintw(11, 10, "Wybrales trapez prostokatny, podaj miare kata ostrego, ramie i krotsza podstawe");
				danych=3;
				long double tablica[danych+2];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
					if (zero) {
						mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
						break;
					}
				tablica[3]=tablica[1]*sin(tablica[0]*PI/180);
				tablica[4]=tablica[2]+(2*tablica[1]*cos(tablica[0]*PI/180));
				mvprintw(11, 10, "Pole powierzchni wynosi: " trapez(tablica[2],tablica[4],tablica[3]));
				mvprintw(11, 10, "Obwod wynosi: " tablica[2]+tablica[4]+tablica[1]+tablica[3]);
				break;
			}
			case 8:{
				mvprintw(11, 10, "Wybrales trapez prostokatny, podaj obie podstawy i dluzsza przekatna");
				danych=3;
				long double tablica[danych+2];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
					if (zero) {
						mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
						break;
					}
				tablica[3]=sqrt((tablica[2]*tablica[2])-(tablica[1]*tablica[1]));
				mvprintw(11, 10, "Pole powierzchni wynosi: " trapez(tablica[0],tablica[1],tablica[3]));
				tablica[4]=sqrt(pow(tablica[1]-tablica[0],2)+pow(tablica[3],2));
				mvprintw(11, 10, "Obwod wynosi: " tablica[0]+tablica[1]+tablica[4]+tablica[3]);
				break;
			}
			case 9:{
				mvprintw(11, 10, "Wybrales trapez prostokatny, podaj obie podstawy i krotsza przekatna");
				danych=3;
				long double tablica[danych+2];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
					if (zero) {
						mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
						break;
					}
				tablica[3]=sqrt((tablica[2]*tablica[2])-(tablica[0]*tablica[0]));
				mvprintw(11, 10, "Pole powierzchni wynosi: " trapez(tablica[0],tablica[1],tablica[3]));
				tablica[4]=sqrt(pow(tablica[1]-tablica[0],2)+pow(tablica[3],2));
				mvprintw(11, 10, "Obwod wynosi: " tablica[0]+tablica[1]+tablica[4]+tablica[3]);
				break;
			}			
			case 10:{
				mvprintw(11, 10, "Wybrales trapez prostokatny, podaj krotsza podstawe, krotsza przekatna i ramie");
				danych=3;
				long double tablica[danych+2];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
					if (zero) {
						mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
						break;
					}
				tablica[3]=sqrt((tablica[1]*tablica[1])-(tablica[0]*tablica[0]));
				tablica[4]=tablica[0]+sqrt((tablica[2]*tablica[2])-(tablica[3]*tablica[3]));
				mvprintw(11, 10, "Pole powierzchni wynosi: " trapez(tablica[0],tablica[4],tablica[3]));
				tablica[2]=sqrt(pow(tablica[4]-tablica[0],2)+pow(tablica[3],2));
				mvprintw(11, 10, "Obwod wynosi: " tablica[0]+tablica[4]+tablica[2]+tablica[3]);
				break;
			}			
		 	default:{											//zly wybor trapezu
				mvprintw(11, 10, "Musisz wybrac opcje 1-" q "!!!");
				break;
			}
			}														//koniec switcha trapezy
			break;
		}														//koniec trapezow 
		case 15:{                                               //deltoid
			mvprintw(11, 10, "Wybrales deltoid, podaj dlugosci jego przekatnych");
			danych=2;
			long double tablica[danych];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
			for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
			if (zero) {
				mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
				break;
			}
			mvprintw(11, 10, "Pole powierzchni wynosi: " deltoid(tablica[0],tablica[1]));
			break;
		}															   
		case 16:{                                       		//szesciokat
			mvprintw(11, 10, "Wybrales szesciokat foremny, podaj dlugosc jego boku.");
			danych=1;
			long double tablica[danych+1];
			for(i=0; i<danych; ++i){
				cin>>tablica[i];
				spr();
				if(s)break;
			}
			if(s)break;
			for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
			if (zero) {
				mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
				break;
			}
			tablica[1]=szesciokat(tablica[0]);
			mvprintw(11, 10, "Pole powierzchni tego szesciokata wynosi: " tablica[1] " pierwiastkow z 3");
			mvprintw(11, 10, "Czyli  w przyblizeniu: " tablica[1]*sqrt(3));
			mvprintw(11, 10, "Obwod wynosi: " 6*tablica[0]);
			break;
		}                      									//koniec szesciokata
		case 17:{                                    			//kolo
			mvprintw(11, 10, "Wybrales kolo, podaj dlugosc jego promienia.");
			danych=1;
			long double tablica[danych];
							for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
			for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
			if (zero) {
				mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
				break;
			}
			mvprintw(11, 10, "Pole powierzchni tego kola wynosi: " pow(tablica[0],2) " pi");
			mvprintw(11, 10, "Czyli  w przyblizeniu: " pow(tablica[0],2)*PI);
			mvprintw(11, 10, "Obwod wynosi: " 2*tablica[0] " pi.");
			mvprintw(11, 10, "Czyli w przyblizeniu: " 2*tablica[0]*PI);
			break;
		}                      									//koniec kola
		default:{      										    //zly wybor figory
			mvprintw(11, 10, "Musisz wybrac opcje 1-" q "!!!");
			break;
		}
		}                                                       //koniec switch plaskich	
		break;		
	}															//koniec plaskich (case 1)
case 2:{ 															//bry³y
		mvprintw(11, 10, "Wybrales lizenie calkowitych pol powierzchni i objetosci bryl");
		mvprintw(11, 10, "wybierz rodzaj bryly:");			q=0;
		mvprintw(11, 10, q ": powrot do menu glownego.");	q++;	
		mvprintw(11, 10, q ": Graniastoslupy /czesc gotowa");				q++;
		mvprintw(11, 10, q ": Ostroslupy /czesc gotowa");	q++;
		mvprintw(11, 10, q ": Bryly obrotowe /gotowe podstawowe");		q++;
		cin>>liczba;
		spr();
		if(s)break;
		switch(liczba){
		case 0: break;
		case 1:{														//graniastoslupy 
			mvprintw(11, 10, "Wybrales graniastoslupy. Wybierz typ graniastoslupa:");		q=0;
			mvprintw(11, 10, q ": powrot do menu glownego.");							q++;
			mvprintw(11, 10, q ": szescian");											q++;
			mvprintw(11, 10, q ": prostopadloscian");									q++;
			mvprintw(11, 10, q ": graniastoslup prosty trojkatny");						q++;
			mvprintw(11, 10, q ": graniastoslup prawidlowy trojkatny");					q++;
			mvprintw(11, 10, q ": graniastoslup prawidlowy czworokatny // nie gotowe");	q++;
			mvprintw(11, 10, q ": graniastoslup prosty czworokatny //nie gotowe");		q++;
			mvprintw(11, 10, q ": graniastoslup prawidlowy szesciokatny");
			cin>>liczba;
			spr();
			if(s)break;
			switch(liczba){                                              //wybor graniastoslupa
			case 0: break;
			case 1:{                 	                               //szescian
				mvprintw(11, 10, "Wybrales szescian. Podaj dlugosc boku.");
				danych=1;
				long double tablica[danych];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
				if (zero) {
					mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
					break;
				}
				mvprintw(11, 10, "Calkowite pole powierzchni wynosi: " 6*kwadrat(tablica[0]));
				mvprintw(11, 10, "Objetosc wynosi: " pow(tablica[0],3));
				break;
			}                                  			 				//koniec szescianu
			case 2:{                  									//prostopadloscian
				mvprintw(11, 10, "Wybrales prostopadloscian. Podaj dlugosci bokow.");
				danych=3;
				long double tablica[danych];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
				if (zero) {
					mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
					break;
				}
				mvprintw(11, 10, "Calkowite pole powierzchni wynosi: " pole1(tablica[0],tablica[1],tablica[2]));
				mvprintw(11, 10, "Objetosc wynosi: " tablica[0]*tablica[1]*tablica[2]);
				break;
			}                                          					//koniec prostopadloscianu
			case 3:{                                      				//g. trojkatny
				mvprintw(11, 10, "Wybrales graniastoslup prosty trojkatny. Wybierz jakie dane posiadasz:.");
				mvprintw(11, 10, "Wysokosc graniastoslupa oraz:");						q=0;
				mvprintw(11, 10, q ": powrot do menu glownego.");						q++;
				mvprintw(11, 10, q ": bok i wysokosc podstawy");							q++;
				mvprintw(11, 10, q ": 2 boki podstawy i kat zawarty miedzy nimi.");		q++;
				mvprintw(11, 10, q ": 3 boki podstawy.");								q++;
				mvprintw(11, 10, q ": pole powierzchni podstawy.");
				cin>>liczba;
				spr();
				if(s)break;
				switch(liczba){
					case 0: break;
					case 1:{
						mvprintw(11, 10, "Podaj wysokosc graniastoslupa, a nastepnie dlugosc boku podstawy i wysokosci opuszczonej na ten bok");
						danych=3;
						long double tablica[danych];
						for(i=0; i<danych; ++i){
							cin>>tablica[i];
							spr();
							if(s)break;
						}
						if(s)break;
						for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
						if (zero) {
							mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
							break;
						}
						mvprintw(11, 10, "Objetosc tego graniastoslupa wynosi: " tablica[0]*trojkat(tablica[1],tablica[2]));
						break; 
					}  
					case 2:{
						mvprintw(11, 10, "Podaj wysokosc graniastoslupa, a nastepnie dlugosc 2 boków podstawy i miare kata zawartego miedzy nimi.");
						danych=4;
						long double tablica[danych];
						for( i=0; i<danych; ++i){
							cin>>tablica[i];
							spr();
							if(s)break;
						}
						if(s)break;
						for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
						if (zero) {
							mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
							break;
						}
						mvprintw(11, 10, "Objetosc tego grtablica[1]niastoslupa wynosi: " tablica[0]*trojkatsin(tablica[1],tablica[2],tablica[3]));
						mvprintw(11, 10, "Calkowite pole powierzchni wynosi: " (2*trojkatsin(tablica[1],tablica[2],tablica[3]))+(tablica[1]*tablica[0])+(tablica[2]*tablica[0])+(twcos(tablica[1],tablica[2],tablica[3])*tablica[0]));
						break; 
					}
					case 3:{
						mvprintw(11, 10, "Podaj wysokosc graniastoslupa, a nastepnie dlugosc 3 boków podstawy.");
						danych=4;
						long double tablica[danych];
						for(i=0; i<danych; ++i){
							cin>>tablica[i];
							spr();
							if(s)break;
						}
						if(s)break;
						for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
						if (zero) {
							mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
							break;
						}
                        heron(tablica[1],tablica[2],tablica[3]);
						if (s) break;
						mvprintw(11, 10, "Objetosc tego graniastoslupa wynosi: " tablica[0]*pole);
						mvprintw(11, 10, "Calkowite pole powierzchni tego graniastoslupa wynoci " (tablica[1]*tablica[0])+(tablica[2]*tablica[0])+(tablica[3]*tablica[0])+(2*pole));
						break; 
					}
					case 4:{
						mvprintw(11, 10, "Podaj wysokosc graniastoslupa, a nastepnie pole jego podstawy.");
						danych=2;
						long double tablica[danych];
						for( i=0; i<danych; ++i){
							cin>>tablica[i];
							spr();
							if(s)break;
						}
						if(s)break;
						for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
						if (zero) {
							mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
							break;
						}
						mvprintw(11, 10, "Objetosc tego graniastoslupa wynosi: " tablica[0]*tablica[1]);
						break; 
					}
					default:{												//zly wybor g trojkatnego
						mvprintw(11, 10, "Musisz wybrac opcje 1-" q "!!!");         					
						break; 
					}
					}														//koniec switcha g. trojkatny
				break;
			}															//koniec case g. trojkatny
			case 4:{													// g. prawidlowy troj
				mvprintw(11, 10, "Wybrales graniastoslup prawidlowy trojkatny. Podaj wysokosc tego graniastoslupa oraz dlugosc boku podstawy.");
				danych=2;
				long double tablica[danych+2];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
				if (zero) {
					mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
					break;
				}
				tablica[2]=2*rownoboczny(tablica[1]);
				tablica[3]=3*prostokat(tablica[0],tablica[1]);
				mvprintw(11, 10, "Calkowite pole powierzchni wynosi: " tablica[2] "+" tablica[3] " pierwiastkow z 3");
				mvprintw(11, 10, "Czyli  w przyblizeniu: " (tablica[3]*sqrt(3))+tablica[2]);
				tablica[3]=rownoboczny(tablica[1])*tablica[0];
				mvprintw(11, 10, "Objetosc tego graniastoslupa wynosi: " tablica[3] " pierwiastkow z 3");
				mvprintw(11, 10, "Czyli  w przyblizeniu: " tablica[3]*sqrt(3));
				break; 
			}															//koniec prawidlowy trojkatny
			case 5:{													// graniastoslup prawidlowy szesciokatny	
				mvprintw(11, 10, "Wybrales graniastoslup prawidlowy szesciokatny. Podaj Jego wysokosc oraz dlugosc krawedzi podstawy");
				danych=2;
				long double tablica[danych+2];
				for( i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
				if (zero) {
					mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
					break;
				}
				tablica[2]=2*szesciokat(tablica[1]);
				tablica[3]=6*prostokat(tablica[1],tablica[0]);
				mvprintw(11, 10, "Calkowite pole powierzchni wynosi: " tablica[3] "+" tablica[2] " pierwiastkow z 3");
				mvprintw(11, 10, "Czyli  w przyblizeniu: " tablica[3]+(tablica[2]*sqrt(3)));
				tablica[2]=szesciokat(tablica[1])*tablica[0];
				mvprintw(11, 10, "Objetosc tego graniastoslupa wynosi: " tablica[2] " pierwiastkow z 3");
				mvprintw(11, 10, "Czyli  w przyblizeniu: " tablica[2]*sqrt(3));
				break; 
			}															// koniec szesciokatnego	
			default:{ 													//zly wybor graniastoslupa
				mvprintw(11, 10, "Musisz podaæ opcje 1-" q "!!!");     		
				break; 
			}		
			}															// koniec swich graniastoslupy
			break;
		}																// koniec case graniastoslupy			
		case 2:{															//ostroslupy 
			mvprintw(11, 10, "Wybrales ostroslupy. Wybierz typ ostroslupa:");		q=0;
			mvprintw(11, 10, q ": powrot do menu glownego.");					q++;
			mvprintw(11, 10, q ": czworoscian /gotowy");							q++;
			mvprintw(11, 10, q ": ostroslup trojkatny");							q++;
			mvprintw(11, 10, q ": ostroslup prawidlowy trojkatny");				q++;
			mvprintw(11, 10, q ": ostroslup czworokatny");						q++;
			mvprintw(11, 10, q ": ostroslup prawidlowy czworokatny /gotowy");	q++;
			mvprintw(11, 10, q ": ostroslup prawidlowy szesciokatny /gotowy");
			cin>>liczba;
			spr();
			if(s)break;
			switch(liczba){												//wybor ostroslupa
			case 0: break;
			case 1:{                                                    //czworoscian
				mvprintw(11, 10, "Wybrales czworoscian. Podaj dlugosc boku.");
				danych=1;
				long double tablica[danych+1];
				for( i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
				if (zero) {
					mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
					break;
				}
				tablica[1]=4*rownoboczny(tablica[0]);
				mvprintw(11, 10, "Calkowite pole powierzchni wynosi: " tablica[1] " pierwiastkow z 3");
				mvprintw(11, 10, "Czyli  w przyblizeniu: " tablica[1]*sqrt(3));
				tablica[1]=(tablica[0]*tablica[0]*tablica[0])/12;
				mvprintw(11, 10, "Objetosc wynosi: " tablica[1] " pierwiastkow z 2");
				mvprintw(11, 10, "Czyli  w przyblizeniu: " tablica[1]*sqrt(2));
				break; 
			}                                              				//koniec czworoscianu		
			case 5:{													// ostroslup p. czworokatny
				mvprintw(11, 10, "Wybrales ostroslup prawidlowy czworokatny. Poadaj Wysokosc tego ostroslupa i dlugosc krawedzi podstawy.");
				danych=2;
				long double tablica[danych];
				for( i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
				if (zero) {
					mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
					break;
				}
				mvprintw(11, 10, "Calkowite pole powierzchni wynosi: " 4*prostokat(tablica[1],tablica[0])+kwadrat(tablica[1]));
				mvprintw(11, 10, "Objetosc wynosi: " kwadrat(tablica[1])*tablica[0]);
				break; 
			}															// koniec ostroslupa kwadratowego
			case 6:{													// ostroslup p. szesciokatny
				mvprintw(11, 10, "Wybrales ostroslup prawidlowy szesciokatny. Poadaj Wysokosc tego ostroslupa i dlugosc krawedzi podstawy.");
				danych=2;
				long double tablica[danych+2];
				for( i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
				if (zero) {
					mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
					break;
				}
				tablica[2]=szesciokat(tablica[1]);
				tablica[3]=6*prostokat(tablica[1],tablica[0]);
				mvprintw(11, 10, "Calkowite pole powierzchni wynosi: " tablica[3] "+" tablica[2] " pierwiastkow z 3");
				mvprintw(11, 10, "Czyli  w przyblizeniu: " tablica[3]+(tablica[2]*sqrt(3)));
				tablica[2]=szesciokat(tablica[1])*tablica[0];
				mvprintw(11, 10, "Objetosc wynosi: " tablica[2] " pierwiastkow z 3");
				mvprintw(11, 10, "Czyli  w przyblizeniu: " tablica[2]*sqrt(3));
				break; 
			}															// koniec ostroslupa szesciokatnego
			default:{ 													//zly wybor ostroslupa
				mvprintw(11, 10, "Musisz wybrac opcje 1-" q "!!!");     
				break; 
			}
			}															//koniec switch stroslupow	
			break;
		}																//koniec case ostroslupow (case3)
		case 3:{															//bryly 
			mvprintw(11, 10, "Wybrales bryly obrotowe. Wybierz typ bryly.");	q=0;
			mvprintw(11, 10, q ": powrot do menu glownego.");				q++;
			mvprintw(11, 10, q ": Walec");									q++;
			mvprintw(11, 10, q ": Stozek");									q++;
			mvprintw(11, 10, q ": Kula");			
			cin>>liczba;
			spr();
			if(s)break;
			switch(liczba) {											//switch bryly
			case 0: break;
			case 1:{													//walec
				mvprintw(11, 10, "Wybrales walec. Podaj wysokosc i promien podstawy");
				danych=2;
				long double tablica[danych+1];
				for( i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
				if (zero) {
					mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
					break;
				}
				tablica[2]=2*tablica[1]*(tablica[1]+tablica[0]);
				mvprintw(11, 10, "Calkowite pole powierzchni wynosi: " tablica[2] " pi");
				mvprintw(11, 10, "czyli w przyblizeniu: " tablica[2]*PI);
				tablica[2]=tablica[1]*tablica[1]*tablica[0];
				mvprintw(11, 10, "Objetosc wynosi: " tablica[2] " pi");
				mvprintw(11, 10, "czyli w przyblizeniu: " tablica[2]*PI);
				break; 
			}															//koniec walca
			case 2:{													//stozek
				mvprintw(11, 10, "Wybrales wstozek. Podaj wysokosc i promien podstawy");
				danych=2;
				long double tablica[danych+2];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
				if (zero) {
					mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
					break;
				}
				tablica[3]=sqrt((tablica[1]*tablica[1])+(tablica[0]*tablica[0]));
				tablica[2]=tablica[1]*(tablica[1]+tablica[3]);
				mvprintw(11, 10, "Calkowite pole powierzchni wynosi: " tablica[2] " pi");
				mvprintw(11, 10, "czyli w przyblizeniu: " tablica[2]*PI);
				tablica[2]=(tablica[1]*tablica[1]*tablica[0])/3;
				mvprintw(11, 10, "Objetosc wynosi: " tablica[2] " pi");
				mvprintw(11, 10, "czyli w przyblizeniu: " tablica[2]*PI);
				break; 
			}															//koniec stozka	
			case 3:{													//kula
				mvprintw(11, 10, "Wybrales kule. Podaj jej promien");
				danych=1;
				long double tablica[danych+1];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
				if (zero) {
					mvprintw(11, 10, "Podales jakas ujemna dlugosc.");
					break;
				}
				tablica[0]=4*tablica[0]*tablica[0];
				mvprintw(11, 10, "Calkowite pole powierzchni wynosi: " tablica[0] " pi");
				mvprintw(11, 10, "czyli w przyblizeniu: " tablica[0]*PI);
				tablica[0]=(4/3)*tablica[0]*tablica[0]*tablica[0];
				mvprintw(11, 10, "Objetosc wynosi: " tablica[0] " pi");
				mvprintw(11, 10, "czyli w przyblizeniu: " tablica[0]*PI);
				break; 
			}															//koniec kuli
			default:{ 													//zly wybor bryly
				mvprintw(11, 10, "Musisz wybrac opcje 1-" q "!!!");     
				break; 
			}
			}															// koniec switch bryl
			break;
		}																//koniec bryl obrotowych (case4)
		default:{ 
			mvprintw(11, 10, "Musisz wybrac opcje 1-" q "!!!");         //zly wybor bryly
			break;
		}
		}															//koniec swich bryl
		break;
	}																//koniec case bryly
case 5:{		//zrobione													//uklad 3 rownan
		long double w,wx,wy,wz, a[4][3];	//deklaracja zmiennych 
		mvprintw(11, 10, "Wybrales obliczanie ukladu 3 rownan z 3 niewiadomymi.");
		cout   " Podaj wspolczynniki wg wzoru:");
		cout   " 1x + 4y + 7z = 10 \n";
		cout   " 2x + 5y + 8z = 11 \n";
		cout   " 3x + 6y +9z = 12 \n";
		mvprintw(11, 10, "Musisz w sumie podac 12 liczb, po kazdej >enter<, jezeli w jakims rownaniu nie wystepuje ktoras niewiadoma wprowadz >0<");
		for(short j=0; j<4; ++j){
			for(short i=0; i<3; ++i){
				cin>>a[j][i];
				spr();
				if(s)break;
			}
			if(s)break;
		}	
		w=(a[0][0]*a[1][1]*a[2][2])+(a[1][0]*a[2][1]*a[0][2])+(a[2][0]*a[0][1]*a[1][2])-(a[2][0]*a[1][1]*a[0][2])-(a[0][0]*a[2][1]*a[1][2])-(a[1][0]*a[0][1]*a[2][2]);
		wx=(a[3][0]*a[1][1]*a[2][2])+(a[1][0]*a[2][1]*a[3][2])+(a[2][0]*a[3][1]*a[1][2])-(a[2][0]*a[1][1]*a[3][2])-(a[3][0]*a[2][1]*a[1][2])-(a[1][0]*a[3][1]*a[2][2]);
		wy=(a[0][0]*a[3][1]*a[2][2])+(a[3][0]*a[2][1]*a[0][2])+(a[2][0]*a[0][1]*a[3][2])-(a[2][0]*a[3][1]*a[0][2])-(a[0][0]*a[2][1]*a[3][2])-(a[3][0]*a[0][1]*a[2][2]);
		wz=(a[0][0]*a[1][1]*a[3][2])+(a[1][0]*a[3][1]*a[0][2])+(a[3][0]*a[0][1]*a[1][2])-(a[3][0]*a[1][1]*a[0][2])-(a[0][0]*a[2][1]*a[1][2])-(a[1][0]*a[0][1]*a[2][2]);
		if(w==0){
			if(wx==0 && wy==0 && wz==0) mvprintw(11, 10, "to rownanie posiada nieskonczenie wiele rozwiazan");
			else mvprintw(11, 10, "To rownanie nie posiada rozwiazan");
		}
		else{
			mvprintw(11, 10, "W=" w);
			mvprintw(11, 10, "x=" wx/w);
			mvprintw(11, 10, "y=" wy/w);
			mvprintw(11, 10, "z=" wz/w);
		}
		break;
	}																//koniec ukladu 3 rownan	
case 7:{		//zrobione :D													//kombinatoryka
		unsigned __int64 j,n,k,z=1;
		mvprintw(11, 10, "wybrales kombinatoryke, wybierz ktorym konkretnie zagadnieniem chcesz sie zajac.");	q=0;
		mvprintw(11, 10, q ": powrot do menu glownego.");		q++;
		mvprintw(11, 10, q ": Permutacja (obliczanie silni)");	q++;
		mvprintw(11, 10, q ": Warjacje bez powtorzen");			q++;
		mvprintw(11, 10, q ": Wariacje z powtorzeniami");		q++;
		mvprintw(11, 10, q ": Kombinacje");
		cin>>liczba;
		spr();
		if(s)break;
		switch(liczba){
		case 0: break;
		case 1:{
			mvprintw(11, 10, "Wybrales permutacje. Podaj ilosc elementow zbioru, ktorego permutacje chcesz obliczyc.");
			cin>>n;
			spr();
			if(s)break;
			if(n<1){
				mvprintw(11, 10, "n musi byc wieksze badz rowne 1");
				break;
			}
			mvprintw(11, 10, n " elementow mozna ustawic w ciag na " silnia(n) " sposobow");
			break;
		}
		case 2:{
			mvprintw(11, 10, "Wybrales wariacje bez powtorzen. Podaj ilosc elementow w zbiorze (n), oraz ilosc elementow ciagu w ktorym maja zostac umieszczone (k)"); 
			cin>>n >>k;
			spr();
			if(s)break;
			for(long double i=n-k+1;i<=n;i++)z*=i;
			mvprintw(11, 10, "liczba sposobow, w jaki z " n " elementow mozna utworzyc ciag skladajacy sie z " k " roznych wyrazow, jest rowna " z);
			break;
		}
		case 3:{
			mvprintw(11, 10, "Wybrales wariacje z powtorzeniami. Podaj ilosc elementow w zbiorze (n), oraz ilosc elementow ciagu w ktorym maja zostac umieszczone (k)"); 
			cin>>n >>k;
			spr();
			if(s)break;
			j=pow(n,k);
			mvprintw(11, 10, "liczba sposobow, w jaki z " n " elementow mozna utworzyc ciag skladajacy sie z " k " niekoniecznie roznych wyrazow, jest rowna " j);
			break;
		}
		case 4:{
			mvprintw(11, 10, "Wybrales kombinacje, podaj ile elementow wybierasz sposrod ilu mozliwych."); 
			mvprintw(11, 10, "Wprowadzona liczba musi oczywiscie nalezec do zbioru N+, w przeciwnym wypadku program zakonczy dzialanie");
			cin>>k>>n;
			spr();
			if(s)break;
			if(k>=0 && k<=n){
				for(short int i=0;i<k;i++)z*=((n-k+1+i)/(long double)(i+1));
				mvprintw(11, 10, "Liczba sposobow, w jaki sposrod " n " elementow mozna wybrac " k " elementow, jest rowna " z);
			}
			else mvprintw(11, 10, "k musi byc wieksze lub rowne 1 i mniejsze badz rowne n, oraz obie liczby musza nalezec do N+");
			break;
		}
		default:{ 
			mvprintw(11, 10, "Musisz wybrac opcje 1-" q "!!!");         //zly wybor kombinatoryka
			break;
		}
		}															//koniec switch kombinatoryka
		break;
	}																//koniec kombinatoryka
case 8:{			//zrobione											//ci¹gi
		long double a1,Sn,r,a3,an;
		unsigned __int64 n;
		mvprintw(11, 10, "Wybrales ciagi. Wybierz czym konkretnie chcesz sie zajac:");
		mvprintw(11, 10, "Ciag arytmetyczny:");																q=0;
		mvprintw(11, 10, q ": powrot do menu glownego.");													q++;
		mvprintw(11, 10, q ": obliczanie n-tego wyrazu za pomoca pierwszego wyrazu ciagu i roznicy");		q++;
		mvprintw(11, 10, q ": obliczanie n-tego wyrazu za pomoca sumy czesciowej n pierwszych wyrazow oraz pierwszego wyrazu ciagu");	q++;
		mvprintw(11, 10, q ": obliczanie wyrazu za pomoca wyrazu poprzedniego i wyrazu nastepnego");			q++;
		mvprintw(11, 10, q ": oblicznie sumy czesciowej n pierwszych wyrazow");								q++;
		mvprintw(11, 10, "Ciag geometryczny:");
		mvprintw(11, 10, q ": obliczanie n-tego wyrazu za pomoca pierwszego wyrazu i ilorazu");				q++;
		mvprintw(11, 10, q ": obliczanie wyrazu za pomoca wyrazu poprzedniego i wyrazu nastepnego");			q++;
		mvprintw(11, 10, q ": obliczanie sumy czesciowej n pierwszych wyrazow");
		cin>>liczba;
		spr();
		if(s)break;
		switch(liczba){
		case 0: break;
		case 1:{
			mvprintw(11, 10, "Ktory wyraz ciagu chcesz wyliczyc?");
			mvprintw(11, 10, "(musisz oczywiscie wprowadzic liczbe nalezaca do N+, inaczej nastapi zakonczenie programu)");
			cin>>n;
			spr();
			if(s)break;
			mvprintw(11, 10, "Podaj pierwszy wyraz ciagu i roznice");
			cin>>a1 >>r;
			spr();
			if(s)break;
			mvprintw(11, 10, "an=" a1+((n-1)*r));
			break;
		}	
		case 2:{
			mvprintw(11, 10, "Ktory wyraz ciagu chcesz wyliczyc?");
			mvprintw(11, 10, "(musisz oczywiscie wprowadzic liczbe nalezaca do N+, inaczej nastapi zakonczenie programu)");
			cin>>n;
			spr();
			if(s)break;
			mvprintw(11, 10, "Podaj sume czesciowa n pierwszych wyrazow oraz a1");
			cin>>Sn;
			cin>>a1;
			spr();
			if(s)break;
			mvprintw(11, 10, "an=" ((2*Sn)/n)-a1);
			break;
		}
		case 3:{
			mvprintw(11, 10, "Podaj wyraz poprzedni i wyraz nastepny");
			cin>>a1>>a3;
			spr();
			if(s)break;
			mvprintw(11, 10, "Srodkowy wyraz jest rowny: " (a1+a3)/2);
			break;
		}	
		case 4:{
			mvprintw(11, 10, "Sume czesciowa ilu pierwszych wyrazow chcesz obliczyc?");
			mvprintw(11, 10, "(musisz oczywiscie wprowadzic liczbe nalezaca do N+, inaczej nastapi zakonczenie programu)");
			cin>>n;
			spr();
			if(s)break;
			mvprintw(11, 10, "Podaj pierwszy wyraz ciagu i roznice");
			cin>>a1>>r;
			spr();
			if(s)break;
			an=a1+((n-1)*r);
			mvprintw(11, 10, "Suma " n " pierwszych wyrazow jest rowna " n*(a1+an)/2);
			break;
		}
		case 5:{
			mvprintw(11, 10, "Ktory wyraz ciagu chcesz wyliczyc?");
			mvprintw(11, 10, "(musisz oczywiscie wprowadzic liczbe nalezaca do N+, inaczej nastapi zakonczenie programu)");
			cin>>n;
			spr();
			if(s)break;
			mvprintw(11, 10, "Podaj pierwszy wyraz ciagu i iloraz");
			cin>>a1>>r;
			spr();
			if(s)break;
			mvprintw(11, 10, "an=" a1*pow(r,n-1));
			break;
		}		
		case 6:{
			mvprintw(11, 10, "Podaj wyraz poprzedni i wyraz nastepny");
			cin>>a1>>a3;
			spr();
			if(s)break;
			mvprintw(11, 10, "Srodkowy wyraz jest rowny: " sqrt(a1*a3));
			break;
		}		
		case 7:{
			mvprintw(11, 10, "Sume czesciowa ilu pierwszych wyrazow chcesz obliczyc?");
			mvprintw(11, 10, "(musisz oczywiscie wprowadzic liczbe nalezaca do N+, inaczej nastapi zakonczenie programu)");
			cin>>n;
			spr();
			if(s)break;
			mvprintw(11, 10, "Podaj pierwszy wyraz ciagu i iloraz");
			cin>>a1>>r;
			spr();
			if(s)break;
			if(r==1) mvprintw(11, 10, "Suma " n " pierwszych wyrazow jest rowna " n*a1);
			else mvprintw(11, 10, "Suma " n " pierwszych wyrazow jest rowna " a1*((1-pow(r,n))/(1-r)));
			break;
		}			
		default:{ 													//zly wybor ciagu
			mvprintw(11, 10, "Musisz wybrac opcje 1-" q "!!!");     
			break; 
		}
		}															// koniec switch ciagi
		break;
    }																//koniec case 7 - ciagi
case 9:{				//zrobione											//lpodzielnosc
		unsigned long long liczba=1, reszta=1, zadana, liczb=0;
		unsigned short int wybor;
		mvprintw(11, 10, "Wybrales cechy podzielnosci, co chcesz zrobic:");	q=0;
		mvprintw(11, 10, q ": Wyjsc\n";											q++;
		mvprintw(11, 10, q ": Sprawdzic dana liczbe czy jest pierwsza\n";			q++;
		mvprintw(11, 10, q ": Znalezc wszystkie liczby pierwsze (i ich ilosc) nie wieksze niz podana\n";q++;
		mvprintw(11, 10, q ": Znalexc wszystkie dzielniki danej liczby.\n";
		cin>>wybor;
		spr();
		if(s)break;
		switch(wybor){
		case 0: break;
		case 1: {
			mvprintw(11, 10, "Wybierz jaka liczbe chcesz sprawdzic");
			mvprintw(11, 10, "wybierz 0 by zamknac program");
			cin>>liczba;
			spr();
			if(s || liczba==0)break;
			for (unsigned long long i=2;( i<liczba && reszta!=0); i++) reszta=liczba%i;
			if (reszta!=0) cout   liczba   " jest liczba pierwsza" endl ;
			else mvprintw(11, 10, liczba " nie jest liczba pierwsza");
			break;
		}
		case 2:{
			bool podzielna=false;
			mvprintw(11, 10, "Wybrales szukanie liczb pierwszych
			wybierz jaka najwieksza liczbe chcesz sprawdzic
			wpisz 0 aby zakonczyc\n";
			cin>>zadana;
			spr();
			if(s || zadana==0)break;
			mvprintw(11, 10, "Liczby pierwsze:");
			do{
				podzielna=false;
				reszta=1;
				liczba++;
				for (unsigned __int64 i=2; (i<liczba && reszta!=0); ++i){
					reszta=liczba%i;
					if (reszta==0) podzielna=true;
				}
				if (!podzielna){
					mvprintw(11, 10, liczba "; ";
	                liczb++;
				}	
			}while (liczba<zadana);
			mvprintw(11, 10, "\n Istnieje " liczb " liczb pierwszych mniejszych od " zadana);		
			break;
		}
		case 3:{
			mvprintw(11, 10, "Wybierz jaka liczbe chcesz sprawdzic");
			mvprintw(11, 10, "wpisz 0 by zamknac program");
			cin>>liczba;
			spr();
			if(s || liczba==0)break;
			mvprintw(11, 10, "Dzielniki liczby " liczba " to:\n";
			for (unsigned __int64 i=1;( i<=liczba); ++i){
				reszta=liczba%i;
				if (reszta==0) cout   i   ", ";
			}
			mvprintw(11, 10, "\n";
			break;
		}
		default:{ 
			mvprintw(11, 10, "Musisz wybrac opcje 0-" q "!!!");         //zly wybor kombinatoryka
			break;
		}
		}
		break;
	}
case 4:{								//zropbione							//uklad 2 rownan by Dyziu
		long double w, wx, wy, x, y; 
		cout   "Wybrales rozwiazywanie ukladu 2 rownan I stopnia z 2 niewiadomymi.");
		cout   "Ta czesc programu zostala napisana przez Dyzia.");
		cout   " ax + by = c \n";
		cout   " dx + ey = f \n";
		cout   "Podaj a, b, c, d, e i f \n";
		danych=6;
		long double tablica[danych];
		for( i=0; i<danych; ++i){
			cin>>tablica[i];
			spr();
			if(s)break;
		}			
		if(s)break;
		w=(tablica[0]*tablica[4])-(tablica[1]*tablica[3]);
		wx=(tablica[2]*tablica[4])-(tablica[1]*tablica[5]);
		wy=(tablica[0]*tablica[5])-(tablica[2]*tablica[4]);
		if (w==0 && wx==0 && wy==0) cout   "Dany uklad rowan jest nieoznaczony (posiada nieskonczenie wiele rozwiazan). \n";
		else if (w==0 && (wx!=0 || wy!=0)) cout   "Dany uklad rowan jest sprzeczny(nie posiada rozwiazan). \n";
		else{
		cout   "Rozwiazaniem tego rowania sa liczby: \n";
		cout   "x = "   wx/w   endl;
		cout   "y = "   wy/w   endl;
		}	
		break; 
	}
case 3:{					//zrobione										//pierwiastki trojmianu by dyziu
		cout   "Wybrales obliczanie pierwiastkow trojmianu kwadratowego.\n";
		cout   " a*x^2 + b*x + c = 0 \n"   endl;
		cout   "Podaj a, b i c ";
		danych=3;
		long double tablica[danych];
		for( i=0; i<danych; ++i){
			cin>>tablica[i];
			spr();
			if(s)break;
		}
		if(s)break;
		long double delta = pow(tablica[1],2)-(4*tablica[0]*tablica[2]);
		if (delta <= 0){
			if (delta == 0){
				long double x0 = -tablica[1] /(2*tablica[0]);
				cout   "x0 = "   x0   endl;	
			}
			else cout   "Dane rownanie nie posiada rozwiazan!"   endl;
		}
		else{
			long double x1, x2;
			x1 = (-tablica[1] + sqrt(delta))/(2*tablica[0]);
			x2 = (-tablica[1] - sqrt(delta))/(2*tablica[0]);
			cout   "x1 = "   x1   endl;
			cout   "x2 = "   x2   endl;
		}
		break; 
	}	
case 6:{		//przeniesiono zakomentowane													//Wielomiany
		unsigned long long n,nn, whatever=0;
		__int64 roznica, dzielnik;
		__int64 i;
		long double Wx=0;
		q=0;
		mvprintw(11, 10, q ": Wyjscie\n";								q++;
		mvprintw(11, 10, q ": Szukanie pierwiastkow wielomianu\n";	q++;
		mvprintw(11, 10, q ": dzielenie przez dwumian (schemat hornera)\n";
		cin>>liczba;
		spr();
		if(s)break;
	switch(liczba){
		case 0: break;
		case 1:{
	        mvprintw(11, 10, "Podaj stopien wielomianu");
			cin>>n;
			spr();
			if(s)break;
			nn=n;
			__int64 h[n], w[n];
			do{																//wczytanie wartosci wspolczynnikow do tablicy
				if(n!=0) mvprintw(11, 10, "podaj wspolczynnik (calkowity) przy X w potedze " n);
				else mvprintw(11, 10, "podaj wartosc wyrazu wolnego \n";
				cin>>w[n];
				spr();
				if(s)break;
				--n;
			}while(n!=-1);
			if(s)break;
			if (w[0]==0){
				mvprintw(11, 10, "wyraz wolny = 0, wiec wielomian spelnia liczba 0 - mozna wylaczyc x przed nawias");
				break;
			}
			mvprintw(11, 10, "Ten wielomian spelniaja liczby:\n";
			for(dzielnik=-abs(w[0]); dzielnik<=abs(w[0]); ++dzielnik){
				if (dzielnik!=0){
					Wx=0;
					roznica=w[0]%dzielnik;   									// dzielenie module, by sprawdzic czy dzielnik jest dzielnikiem wyrazu wolnego :D
					if (roznica==0) {
						for(long long i=0; i<=nn; i++) Wx+=pow(dzielnik,i)*w[i]; 		// obliczenie W(x) dla danego dzielnika
						if (Wx==0){												//sprawdzenie czy W(x)=0
							mvprintw(11, 10, dzielnik ", ";
							whatever++;
						}
					}
				}
			}
			if (whatever==0) {
				mvprintw(11, 10, "Ten wielomian nie posiada pierwiastkow calkowitych, szukanie pierwiastkow rzeczywistych zostanie dodane pozniej\n";
				break;
			}
			mvprintw(11, 10, "\n \n
			Ten wielomian posiada " whatever " pierwiastkow calkowitych.\n";
			if(whatever==nn){
				__int64 r[whatever];
				whatever=0;
				for(dzielnik=-abs(w[0]); dzielnik<=abs(w[0]); ++dzielnik){
					if (dzielnik!=0){
						Wx=0;
						roznica=w[0]%dzielnik;     									// dzielenie modulo, by sprawdzic czy dzielnik jest dzielnikiem wyrazu wolnego :D 
						if (roznica==0) {
							for(long long i=0; i<=nn; ++i) Wx+=pow(dzielnik,i)*w[i]; 		// obliczenie W(x) dla danego dzielnika
							if (Wx==0){												//sprawdzenie czy W(x)=0
								r[whatever]=dzielnik;
								whatever++;
							}
						}
					}
				}
				mvprintw(11, 10, "Ten wielomian mozna zapisac w postaci: " w[nn];
				for(i=0;i<whatever;++i){
					if (r[i]>0) mvprintw(11, 10, "( x - " r[i] " )";
					else mvprintw(11, 10, "( x + " abs(r[i]) " )";
				}	
			}
			mvprintw(11, 10, "\n";
			break;
		}
		case 2:{
			long double r;
			mvprintw(11, 10, "Podaj stopien wielomianu");
			cin>>n;
			spr();
			if(s)break;
			nn=n;
			__int64 h[n], w[n];
			do{																//wczytanie wartosci wspolczynnikow do tablicy
				if(n!=0) mvprintw(11, 10, "podaj wspolczynnik (calkowity) przy X w potedze " n);
				else mvprintw(11, 10, "podaj wartosc wyrazu wolnego \n";
				cin>>w[n];
				spr();
				if(s)break;
				--n;
			}while(n!=-1);
			if(s)break;
			mvprintw(11, 10, "Wybrales dzielenie przez dwumian o postaci (x-r). Podaj r:\n";
			cin>>r;
			spr();
			if(s)break;
			mvprintw(11, 10, "Wynik dzielenia podanego wielomianu przez "  r  " za pomoca schematu hornera:\n";
			mvprintw(11, 10, w[nn] "x^" nn-1 " + ";
			h[nn]=w[nn];
			for(i=1;i<=nn;++i){
				h[nn-i]=w[nn-i]+(r*h[nn-i+1]);
				if (nn-1==i) mvprintw(11, 10, h[nn-i]);
				if (nn==i){
					mvprintw(11, 10, "reszta jest rowna: " h[0]);
					break;
				}
				if (!(nn-1==i || nn==i)) mvprintw(11, 10, h[nn-i] "x^" nn-(1+i) " + ";
			}
			break;
		}
		default:{ 
			mvprintw(11, 10, "Musisz wybrac opcje 1-" q "!!!"); 			//zly wybor case
			break; 
		}	
	}
	break;
}
case 10:{		//zrobione													//geometria analityczna
		mvprintw(11, 10, "Wybrales geometrie analityczna");
		mvprintw(11, 10, "Wybierz czym konkretnie chcesz sie zajac");	q=0;
		mvprintw(11, 10, "0: Wyjscie do menu glownego");				q++;
		mvprintw(11, 10, "1: Odleglosc punktu od prostej");			q++;
		mvprintw(11, 10, "2: Odleglosc miedzy dwoma punktami");
		cin>>liczba;
		spr();
		if(s)break;
		switch(liczba){
			case 0: break;
			case 1:{
				cout   "odleglosc punktu o wpolrzednych (a;b) od prostej o rownaniu cx + dy + e = 0"   endl;
				cout   "podaj wspolrzedna a,b,c,d,e:"   endl;
				danych=5;
				long double tablica[danych+3];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				tablica[6]=(tablica[2]*tablica[0])+(tablica[3]*tablica[1])+tablica[4];
				tablica[7]=sqrt((tablica[2]*tablica[2])+(tablica[3]*tablica[3]));
				if (tablica[6]>0) tablica[5]=tablica[6]/tablica[7];
				else tablica[5]=(-tablica[6])/tablica[7];
				cout   "Odleglosc punktu o wspolrzednych ("   tablica[0]   ";"   tablica[1]   ") od prostej o rownaniu "   tablica[2]   "x + "   tablica[3]   "y + "   tablica[4]   " = 0 wynosi: "   tablica[5]   endl;
				break;
			}
			case 2:{
				cout   "Obliczanie odleglosci dwoch punktow A i B o wspolrzednych A=(a;b) i B=(c;d)"   endl;
				long double a,b,c,d,w;
				danych=4;
				long double tablica[danych+1];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				}
				if(s)break;
				tablica[4]=sqrt((tablica[2]-tablica[0])*(tablica[2]-tablica[0])+(tablica[3]-tablica[1])*(tablica[3]-tablica[1]));
				cout   "Odleglosc puntu A=("   tablica[0]   ";"   tablica[1]   ") i B=("   tablica[2]   ";"   tablica[3]   ") wynosi: "   tablica[4]   endl;
				break;				
			}
			default:{ 
				mvprintw(11, 10, "Musisz wybrac opcje 1-" q "!!!"); 			//zly wybor case geometria
				break; 
			}
		}
		break;
	}
case 666:{			//niepotrzebne												//haksy :P
		cout   "szatan cie kocha... buahaha...\n";
		break; 
	}
default:{ //te¿
		mvprintw(11, 10, "Musisz wybrac opcje 1-" q "!!!"); 			//zly wybor case
		break; 
	}	
}                                                           		//koniec switch
mvprintw(11, 10, "\nChcesz wyjsc? t/n\n");
cin>>out;
#if windows
system("cls");														//czysc ekran
#endif
} while(out!='t');													//koniec pêtli
//koñcówka
mvprintw(11, 10, "Dziekujemy za korzystanie z naszego programu :)");
mvprintw(11, 10, "copyright Konsi & Dyziu :D");
mvprintw(11, 10, "specjalne podziekowania dla ludzi z forum programuj.com oraz wszystkich wylapujacych bugi :)");
#if windows
system("pause");
#endif
return 0;
}																	//koniec main	
