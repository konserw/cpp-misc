#include <iostream.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
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
if (!(abs((__int64)((b-c)))<a && a<(b+c))){
	cout<<"Z podanych bokow nie da sie skonstruowac trojkata na plaszczyznie euklidesowej"<<endl;
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
	cerr << "Podales bledny format danych!\n";
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
 cout<<
"           .       .              _______________           .!.        ,/,.
        `omN-    -dMy             ommmmNNNmmmmmh-            sNd-     `:ymo`
       .yMMm.   /NMM+              ``./Nm:/~~~~`             .hMd.  .+ddo.
      .hMMMy  `sNNMm.    ./oyyhs-    `yM+       ./syyhy/      .dMd:odd+`
     :dmomM/ -hm+yMy   :ydy/-/NN/    :Nd`     .ody/^;yMh`      :NMMh:`
   `+Nd--NN:+mh-`dM/ `sNs.  `yN+    `dN/     -dNo;..;s/`     -odmNMs
  `sNy. /MMmNo` -NN- +My`   :Ny`    oMy`    .dMds++;``    `/hdy:`+MN:
 `yMs`  oMMd:   +Mm` hMy-.-+mM+    -Nm.     -NNs:-[...o`-sdh+.   `yMm-
 :h+`   :y+`    +mo  -shhyo+sh-    -o.       -oyhhyo/-`-hs-`      .ym/\n";
cout<<"Czym chcesz sie teraz zajac?"<<endl;
cout<<"(Wpisz odpowiednia liczbe i nacisnij >>enter<<,\n podobnie kiedy program zada innych danych)\n\n"; q=0;	                                                   						q=0;
cout<<q<<": Zakonczenie programu"<<endl;                                                q++;//0
cout<<q<<": Pola powierzchni i obwody figur plaskich"<<endl;							q++;//1
cout<<q<<": Calkowite pola powierzchni i objetosci bryl"<<endl;							q++;//2
cout<<q<<": Pierwiastki trojmianu kwadratowego"<<endl;									q++;//3
cout<<q<<": Rozwiazywanie ukladu I stopnia 2 rownan z 2 niewiadomymi"<<endl;			q++;//4
cout<<q<<": Rozwiazywania ukladu I stopnia 3 rownan z 3 niewiadomymi."<<endl;			q++;//5
cout<<q<<": Znajdywanie pierwiastkow wielomianu dowolnego stopnia"<<endl;				q++;//6
cout<<q<<": Kombinatoryka"<<endl;														q++;//7
cout<<q<<": Ciagi"<<endl;																q++;//8
cout<<q<<": Cechy podzielnosci i l. pierwsze"<<endl;									q++;//9
cout<<q<<": Geometria analityczna"<<endl;													//10
cin>>liczba;
		spr();
		if(s)break;
switch(liczba){														//switch
case 0:{															//quit
    out='t';
    break;
    }
case 1:{                                               				//f. plaskie (case 1)
		cout<<"Wybrales figury plaskie, wybierz typ:"<<endl;	q=0;
		cout<<q<<": powrot do menu glownego."<<endl;			q++;
		cout<<q<<": trojkat"<<endl;								q++;
		cout<<q<<": trojkat rownoboczny"<<endl;					q++;
		cout<<q<<": trojkat - 3 boki"<<endl;					q++;
		cout<<q<<": trojkat - 2 boki i kat"<<endl;				q++;
		cout<<q<<": kwadrat"<<endl;								q++;
		cout<<q<<": kwadrat - przekatnej"<<endl;				q++;
		cout<<q<<": prostokat"<<endl;							q++;
		cout<<q<<": romb"<<endl;								q++;
		cout<<q<<": romb - kat"<<endl;							q++;
		cout<<q<<": romb - przekatna"<<endl;					q++;
		cout<<q<<": rownoleglobok"<<endl;						q++;
		cout<<q<<": rownoleglobok - 2 boki i k¹t"<<endl;		q++;
		cout<<q<<": rownoleglobok - przekatne i kat"<<endl;		q++;
		cout<<q<<": trapez - rozne przypadki"<<endl;			q++;	
		cout<<q<<": deltoid"<<endl;								q++;	  
		cout<<q<<": szesciokat foremny"<<endl;					q++;
		cout<<q<<": kolo"<<endl;
		cin>>liczba;    
		spr();
		if(s)break;	
		switch(liczba){											//wybor figory
		case 0: break;
		case 1:{												//trojkat
			cout<<"Wybrales trojkat, podaj bok oraz wysokosc opuszczona na ten bok"<<endl;
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
				cout<<"Musisz podac liczbe naturalna\n";
				break;
			}
			else cout<<"Pole powierzchni wynosi: "<<trojkat(tablica[0],tablica[1])<<endl;
			break;
		} 															//koniec trojkata
		case 2:{													//Trójk¹t równoboczny
			cout<<"Wybrales trojkat rownoboczny. Podaj dlugosc boku tego trojkata."<<endl;
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
				cout<<"Podales ujemna dlugosc."<<endl;
				break;
			}
				cout<<"Pole powierzchni wynosi: "<<rownoboczny(tablica[0])<<" pierwiastkow z 3"<<endl;
				cout<<"Czyli  wprzyblizeniu: "<<rownoboczny(tablica[0])*sqrt(3)<<endl;
				cout<<"Obwod wynosi: "<<3*tablica[0]<<endl;
			break;
		} 															//koniec trojkata równobocznego				  
		case 3:{                                             	    //heron
        	cout<<"Wybrales wzor herona, podaj boki trojkata."<<endl;
			danych=3;
			long double tablica[danych];
			for(i=0; i<danych; ++i){
				spr();
				if(s)break;
			}
			if(s)break;
			for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
			if (zero) {
				cout<<"Podales jakas ujemna dlugosc."<<endl;
				break;
			}
			heron(tablica[0],tablica[1],tablica[2]);
            if(s) break;
			cout<<"Pole tego trojkata wynosi: "<<pole<<endl;
			cout<<"Obwod wynosi: "<<tablica[1]+tablica[2]+tablica[0]<<endl;
			break;
		} 															//koniec herona
		case 4:{                                                	//trojkatsin
			cout<<"Wybrales trojkat. Podaj dlugosci 2 bokow i miare kata miedzy nimi(w stopniach)."<<endl;
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
				cout<<"Podales jakas ujemna dlugosc."<<endl;
				break;
			}
			tablica[3]=twcos(tablica[0],tablica[1],tablica[2]);
			if (!(abs((__int64)(tablica[1]-tablica[3])<tablica[0] && tablica[0]<(tablica[1]+tablica[3])))){
				cout<<"Z podanych bokow nie da sie skonstruowac trojkata na plaszczyznie euklidesowej"<<endl;
				break;
			}
			cout<<"Pole powierzchni tego trojkata wynosi:"<<trojkatsin(tablica[0],tablica[2],tablica[2])<<endl;
			cout<<"Obwod wynosi: "<<tablica[0]+tablica[1]+tablica[3]<<endl;
			break; 
		}															//koniec trojkatsin 
		case 5:{													//kwadrat
			cout<<"Wybrales kwadrat, podaj dlugosc jego boku."<<endl;
			danych=1;
			long double tablica[danych];
			for(i=0; i<danych; ++i){
				spr();
				if(s)break;
			}
			if(s)break;
			for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
			if (zero) {
				cout<<"Podales jakas ujemna dlugosc."<<endl;
				break;
			}
			cout<<"Pole powierzchni tego kwadratu wynosi: "<<kwadrat(tablica[0])<<endl;
			cout<<"Obwod wynosi: "<<2*tablica[0]<<endl;
			break;
		}          		               		                        //koniec kwadratu
	    case 6:{       	                                       		//kwadrat d
			cout<<"Wybrales kwadrat, podaj dlugosc jego przekatnej."<<endl;
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
				cout<<"Podales jakas zeowa dlugosc."<<endl;
				break;
			}
			cout<<"Pole powierzchni tego kwadratu wynosi: "<<kwadrat_d(tablica[0])<<endl;
			cout<<"Obwod wynosi: "<<2*tablica[0]<<" pierwiastkow z 2"<<endl;
			cout<<"Czyli  w przyblizeniu: "<<2*tablica[0]*sqrt(2)<<endl;
			break; 
		}															//koniec kwadratu d
		case 7:{                                                    //prostokat
			cout<<"Wybrales prostokat, podaj dlugosci jego bokow."<<endl;
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
				cout<<"Podales jakas ujemna dlugosc."<<endl;
				break;
			}
			cout<<"Pole powierzchni tego prostokata wynosi: "<<prostokat(tablica[0], tablica[1])<<endl;
			cout<<"Obwod wynosi: "<<(tablica[1]+tablica[0])*2<<endl;
			break;
		}                                       		       		//koniec prostokata
		case 8:{                                            		//romb
			cout<<"Wybrales romb, podaj dlugosc jego boku i wysokosc"<<endl;
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
				cout<<"Podales jakas ujemna dlugosc."<<endl;
				break;
			}
			cout<<"Pole powierzchni tego rombu wynosi: "<<romb(tablica[0], tablica[1])<<endl;
			cout<<"Obwod wynosi: "<<4*tablica[0]<<endl;
			break;
		} 															//koniec romb 
		case 9:{                                             		//romb sin
			cout<<"Wybrales romb, podaj dlugosc jego boku i miare kata ostrego w stopniach"<<endl;
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
				cout<<"Podales jakas ujemna dlugosc."<<endl;
				break;
			}
			cout<<"Pole powierzchni tego rombu wynosi: "<<rombsin(tablica[0], tablica[1])<<endl;
			cout<<"Obwod wynosi: "<<4*tablica[0]<<endl;
			break;
		} 															//koniec romb sin
		case 10:{                                               	//romb d
			cout<<"Wybrales romb, podaj dlugosci jego przekatnych"<<endl;
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
				cout<<"Podales jakas ujemna dlugosc."<<endl;
				break;
			}
			cout<<"Pole powierzchni tego rombu wynosi: "<<rombd(tablica[0], tablica[1])<<endl;
			cout<<"Obwod wynosi: "<<2*(sqrt(tablica[0] + tablica[1]))<<endl;
			break;
		}															//koniec romb d
		case 11:{													//rownoleglobok
			cout<<"Wybrales rownoleglobok, podaj dlugosc jego boku i wysokosci"<<endl;
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
				cout<<"Podales jakas ujemna dlugosc."<<endl;
				break;
			}
			cout<<"Pole powierzchni tego rownolegloboku wynosi: "<<romb(tablica[0], tablica[1])<<endl;
			break;
		}															//koniec rownoleglobok  	
		case 12:{                                                   //rownoleglobok sin
			cout<<"Wybrales rownoleglobok, podaj dlugosci jego bokow i miare kata ostrego (w stopniach)"<<endl;
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
				cout<<"Podales jakas ujemna dlugosc."<<endl;
				break;
			}
			cout<<"Pole powierzchni tego rownolegloboku wynosi: "<<rownosin(tablica[0], tablica[1], tablica[2])<<endl;
			cout<<"Obwod wynosi: "<<2*(tablica[0] + tablica[1])<<endl;
			break;
		}  															//koniec rowno sin
		case 13:{                                                   //rownoleglobok d
			cout<<"Wybrales rownoleglobok, podaj dlugosci jego przekatnych i miare kata ostrego zawartego miedzy nimi (w stopniach)"<<endl;
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
				cout<<"Podales jakas ujemna dlugosc."<<endl;
				break;
			}
			cout<<"Pole powierzchni tego rownolegloboku wynosi: "<<rownod(tablica[0], tablica[1], tablica[2])<<endl;
			cout<<"obwod wynosi: "<<2*((twcos(tablica[0]/2,tablica[1]/2,tablica[2]))+(twcos(tablica[0]/2,tablica[1]/2,180-tablica[2])))<<endl;
			break;
		} 															//koniec rowno d 		
		case 14:{                                                   //trapez
			cout<<"Wybrales trapez, wybierz typ trapezu:"<<endl;							q=0;
			cout<<q<<": powrot do menu glownego."<<endl;									q++;
			cout<<q<<": trapez - obie podstawy i wysokosc /gotowe"<<endl;					q++;
			cout<<q<<": trapez rownoramienny - wysokosc, ramie i krotsza podstawa"<<endl;	q++;
			cout<<q<<": trapez rownoramienny - ramie i obie podstawy"<<endl;				q++;
			cout<<q<<": trapez rownoramienny - kat ostry, ramie i krotsza podstawa"<<endl;	q++;
			cout<<q<<": trapez rownoramienny - kat ostry, wysokosc i krotsza podstawa"<<endl;q++;
			cout<<q<<": trapez prostokatny - kat ostry, wysokosc i krotsza podstawa"<<endl;	q++;
			cout<<q<<": trapez prostokatny - kat ostry, ramie i krotsza podstawa"<<endl;	q++;
			cout<<q<<": trapez prostokatny - obie podstawy i dluzsza przekatna"<<endl;		q++;
			cout<<q<<": trapez prostokatny - obie podstawy i krotsza przekatna"<<endl;		q++;
			cout<<q<<": trapez prostokatny - krotsza podstawa, krotsza przekatna i ramie"<<endl;		
			cin>>liczba;
			spr();
			if(s)break;
			switch(liczba){											//switch trapezy
			case 0: break;
			case 1:{
				cout<<"Wybrales >zwykly< trapez. Podaj dlugosci obu podstaw i wysokosci"<<endl;
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
					cout<<"Podales jakas ujemna dlugosc."<<endl;
					break;
				}
				cout<<"Pole powierzchni wynosi: "<<trapez(tablica[0], tablica[1], tablica[2])<<endl;
				break;
			}
			case 2:{
				cout<<"Wybrales trapez rownoramienny, podaj wysokosc, ramie i krotsza podstawe"<<endl;
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
					cout<<"Podales jakas ujemna dlugosc."<<endl;
					break;
				}
				tablica[3]=(2*sqrt(pow(tablica[1],2)-pow(tablica[0],2)))+tablica[2]; //d³u¿sza podstawa - b
				cout<<"Pole powierzchni wynosi: "<<trapez(tablica[2], tablica[3], tablica[0])<<endl;
				cout<<"Obwod wynosi: "<<(2*tablica[1])+ tablica[2] + tablica[3]<<endl;
			break;
			}
			case 3:{
				cout<<"Wybrales trapez rownoramienny, podaj ramie i obie podstawy (najpierw krotsza)"<<endl;
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
					cout<<"Podales jakas ujemna dlugosc."<<endl;
					break;
				}
				tablica[3]=sqrt((tablica[0]*tablica[0])-((kwadrat(tablica[2]-tablica[1])/2)));
				cout<<"Pole powierzchni wynosi: "<<trapez(tablica[1],tablica[2],tablica[3])<<endl;
				cout<<"Obwod wynosi: "<<tablica[1]+tablica[2]+tablica[0]+tablica[0]<<endl;
				break;
			}
			case 4:{
				cout<<"Wybrales trapez rownoramienny, podaj miare kata ostrego, ramie i krotsza podstawe"<<endl;
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
					cout<<"Podales jakas ujemna dlugosc."<<endl;
					break;
				}
				tablica[3]=tablica[1]*sin(tablica[0]*PI/180);
				tablica[4]=tablica[2]+(2*tablica[1]*cos(tablica[0]*PI/180));
				cout<<"Pole powierzchni wynosi: "<<trapez(tablica[2],tablica[4],tablica[3])<<endl;
				cout<<"Obwod wynosi: "<<tablica[2]+tablica[4]+tablica[1]+tablica[1]<<endl;
				break;
			}
			case 5:{
				cout<<"Wybrales trapez rownoramienny, podaj miare kata ostrego, wysokosc i krotsza podstawa"<<endl;
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
						cout<<"Podales jakas ujemna dlugosc."<<endl;
						break;
					}
				tablica[3]=tablica[2]+(2*tablica[1]*ctg(tablica[0]));
				cout<<"Pole powierzchni wynosi: "<<trapez(tablica[2],tablica[3],tablica[1])<<endl;
				tablica[4]=tablica[1]/sin(tablica[0]*PI/180);
				cout<<"Obwod wynosi: "<<tablica[2]+tablica[3]+tablica[4]+tablica[4]<<endl;
				break;
			}
			case 6:{
				cout<<"Wybrales trapez prostokatny, podaj miare kat ostrego, wysokosc i krotsza podstawe"<<endl;
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
						cout<<"Podales jakas ujemna dlugosc."<<endl;
						break;
					}
				tablica[3]=tablica[2]+(tablica[1]*ctg(tablica[0]));
				cout<<"Pole powierzchni wynosi: "<<trapez(tablica[2],tablica[3],tablica[1])<<endl;
				tablica[4]=sqrt(pow(tablica[3]-tablica[2],2)+pow(tablica[1],2));
				cout<<"Obwod wynosi: "<<tablica[2]+tablica[3]+tablica[4]+tablica[1]<<endl;
				break;
			}
			case 7:{
				cout<<"Wybrales trapez prostokatny, podaj miare kata ostrego, ramie i krotsza podstawe"<<endl;
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
						cout<<"Podales jakas ujemna dlugosc."<<endl;
						break;
					}
				tablica[3]=tablica[1]*sin(tablica[0]*PI/180);
				tablica[4]=tablica[2]+(2*tablica[1]*cos(tablica[0]*PI/180));
				cout<<"Pole powierzchni wynosi: "<<trapez(tablica[2],tablica[4],tablica[3])<<endl;
				cout<<"Obwod wynosi: "<<tablica[2]+tablica[4]+tablica[1]+tablica[3]<<endl;
				break;
			}
			case 8:{
				cout<<"Wybrales trapez prostokatny, podaj obie podstawy i dluzsza przekatna"<<endl;
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
						cout<<"Podales jakas ujemna dlugosc."<<endl;
						break;
					}
				tablica[3]=sqrt((tablica[2]*tablica[2])-(tablica[1]*tablica[1]));
				cout<<"Pole powierzchni wynosi: "<<trapez(tablica[0],tablica[1],tablica[3])<<endl;
				tablica[4]=sqrt(pow(tablica[1]-tablica[0],2)+pow(tablica[3],2));
				cout<<"Obwod wynosi: "<<tablica[0]+tablica[1]+tablica[4]+tablica[3]<<endl;
				break;
			}
			case 9:{
				cout<<"Wybrales trapez prostokatny, podaj obie podstawy i krotsza przekatna"<<endl;
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
						cout<<"Podales jakas ujemna dlugosc."<<endl;
						break;
					}
				tablica[3]=sqrt((tablica[2]*tablica[2])-(tablica[0]*tablica[0]));
				cout<<"Pole powierzchni wynosi: "<<trapez(tablica[0],tablica[1],tablica[3])<<endl;
				tablica[4]=sqrt(pow(tablica[1]-tablica[0],2)+pow(tablica[3],2));
				cout<<"Obwod wynosi: "<<tablica[0]+tablica[1]+tablica[4]+tablica[3]<<endl;
				break;
			}			
			case 10:{
				cout<<"Wybrales trapez prostokatny, podaj krotsza podstawe, krotsza przekatna i ramie"<<endl;
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
						cout<<"Podales jakas ujemna dlugosc."<<endl;
						break;
					}
				tablica[3]=sqrt((tablica[1]*tablica[1])-(tablica[0]*tablica[0]));
				tablica[4]=tablica[0]+sqrt((tablica[2]*tablica[2])-(tablica[3]*tablica[3]));
				cout<<"Pole powierzchni wynosi: "<<trapez(tablica[0],tablica[4],tablica[3])<<endl;
				tablica[2]=sqrt(pow(tablica[4]-tablica[0],2)+pow(tablica[3],2));
				cout<<"Obwod wynosi: "<<tablica[0]+tablica[4]+tablica[2]+tablica[3]<<endl;
				break;
			}			
		 	default:{											//zly wybor trapezu
				cout<<"Musisz wybrac opcje 1-"<<q<<"!!!"<<endl;
				break;
			}
			}														//koniec switcha trapezy
			break;
		}														//koniec trapezow 
		case 15:{                                               //deltoid
			cout<<"Wybrales deltoid, podaj dlugosci jego przekatnych"<<endl;
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
				cout<<"Podales jakas ujemna dlugosc."<<endl;
				break;
			}
			cout<<"Pole powierzchni wynosi: "<<deltoid(tablica[0],tablica[1])<<endl;
			break;
		}															   
		case 16:{                                       		//szesciokat
			cout<<"Wybrales szesciokat foremny, podaj dlugosc jego boku."<<endl;
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
				cout<<"Podales jakas ujemna dlugosc."<<endl;
				break;
			}
			tablica[1]=szesciokat(tablica[0]);
			cout<<"Pole powierzchni tego szesciokata wynosi: "<<tablica[1]<<" pierwiastkow z 3"<<endl;
			cout<<"Czyli  w przyblizeniu: "<<tablica[1]*sqrt(3)<<endl;
			cout<<"Obwod wynosi: "<<6*tablica[0]<<endl;
			break;
		}                      									//koniec szesciokata
		case 17:{                                    			//kolo
			cout<<"Wybrales kolo, podaj dlugosc jego promienia."<<endl;
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
				cout<<"Podales jakas ujemna dlugosc."<<endl;
				break;
			}
			cout<<"Pole powierzchni tego kola wynosi: "<<pow(tablica[0],2)<<" pi"<<endl;
			cout<<"Czyli  w przyblizeniu: "<<pow(tablica[0],2)*PI<<endl;
			cout<<"Obwod wynosi: "<<2*tablica[0]<<" pi."<<endl;
			cout<<"Czyli w przyblizeniu: "<<2*tablica[0]*PI<<endl;
			break;
		}                      									//koniec kola
		default:{      										    //zly wybor figory
			cout<<"Musisz wybrac opcje 1-"<<q<<"!!!"<<endl;
			break;
		}
		}                                                       //koniec switch plaskich	
		break;		
	}															//koniec plaskich (case 1)
case 2:{ 															//bry³y
		cout<<"Wybrales lizenie calkowitych pol powierzchni i objetosci bryl"<<endl;
		cout<<"wybierz rodzaj bryly:"<<endl;			q=0;
		cout<<q<<": powrot do menu glownego."<<endl;	q++;	
		cout<<q<<": Graniastoslupy /czesc gotowa"<<endl;				q++;
		cout<<q<<": Ostroslupy /czesc gotowa"<<endl;	q++;
		cout<<q<<": Bryly obrotowe /gotowe podstawowe"<<endl;		q++;
		cin>>liczba;
		spr();
		if(s)break;
		switch(liczba){
		case 0: break;
		case 1:{														//graniastoslupy 
			cout<<"Wybrales graniastoslupy. Wybierz typ graniastoslupa:"<<endl;		q=0;
			cout<<q<<": powrot do menu glownego."<<endl;							q++;
			cout<<q<<": szescian"<<endl;											q++;
			cout<<q<<": prostopadloscian"<<endl;									q++;
			cout<<q<<": graniastoslup prosty trojkatny"<<endl;						q++;
			cout<<q<<": graniastoslup prawidlowy trojkatny"<<endl;					q++;
			cout<<q<<": graniastoslup prawidlowy czworokatny // nie gotowe"<<endl;	q++;
			cout<<q<<": graniastoslup prosty czworokatny //nie gotowe"<<endl;		q++;
			cout<<q<<": graniastoslup prawidlowy szesciokatny"<<endl;
			cin>>liczba;
			spr();
			if(s)break;
			switch(liczba){                                              //wybor graniastoslupa
			case 0: break;
			case 1:{                 	                               //szescian
				cout<<"Wybrales szescian. Podaj dlugosc boku."<<endl;
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
					cout<<"Podales jakas ujemna dlugosc."<<endl;
					break;
				}
				cout<<"Calkowite pole powierzchni wynosi: "<<6*kwadrat(tablica[0])<<endl;
				cout<<"Objetosc wynosi: "<<pow(tablica[0],3)<<endl;
				break;
			}                                  			 				//koniec szescianu
			case 2:{                  									//prostopadloscian
				cout<<"Wybrales prostopadloscian. Podaj dlugosci bokow."<<endl;
				danych=3;
				long double tablica[danych];
				for(i=0; i<danych; ++i){
					cin>>tablica[i];
					spr();
					if(s)break;
				
				if(s)break;}
				for(i=0; i<danych; ++i)if (tablica[i]<=0) zero=true;
				if (zero) {
					cout<<"Podales jakas ujemna dlugosc."<<endl;
					break;
				}
				cout<<"Calkowite pole powierzchni wynosi: "<<pole1(tablica[0],tablica[1],tablica[2])<<endl;
				cout<<"Objetosc wynosi: "<<tablica[0]*tablica[1]*tablica[2]<<endl;
				break;
			}                                          					//koniec prostopadloscianu
			case 3:{                                      				//g. trojkatny
				cout<<"Wybrales graniastoslup prosty trojkatny. Wybierz jakie dane posiadasz:."<<endl;
				cout<<"Wysokosc graniastoslupa oraz:"<<endl;						q=0;
				cout<<q<<": powrot do menu glownego."<<endl;						q++;
				cout<<q<<": bok i wysokosc podstawy"<<endl;							q++;
				cout<<q<<": 2 boki podstawy i kat zawarty miedzy nimi."<<endl;		q++;
				cout<<q<<": 3 boki podstawy."<<endl;								q++;
				cout<<q<<": pole powierzchni podstawy."<<endl;
				cin>>liczba;
				spr();
				if(s)break;
				switch(liczba){
					case 0: break;
					case 1:{
						cout<<"Podaj wysokosc graniastoslupa, a nastepnie dlugosc boku podstawy i wysokosci opuszczonej na ten bok"<<endl;
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
							cout<<"Podales jakas ujemna dlugosc."<<endl;
							break;
						}
						cout<<"Objetosc tego graniastoslupa wynosi: "<<tablica[0]*trojkat(tablica[1],tablica[2])<<endl;
						break; 
					}  
					case 2:{
						cout<<"Podaj wysokosc graniastoslupa, a nastepnie dlugosc 2 boków podstawy i miare kata zawartego miedzy nimi."<<endl;
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
							cout<<"Podales jakas ujemna dlugosc."<<endl;
							break;
						}
						cout<<"Objetosc tego grtablica[1]niastoslupa wynosi: "<<tablica[0]*trojkatsin(tablica[1],tablica[2],tablica[3])<<endl;
						cout<<"Calkowite pole powierzchni wynosi: "<<(2*trojkatsin(tablica[1],tablica[2],tablica[3]))+(tablica[1]*tablica[0])+(tablica[2]*tablica[0])+(twcos(tablica[1],tablica[2],tablica[3])*tablica[0])<<endl;
						break; 
					}
					case 3:{
						cout<<"Podaj wysokosc graniastoslupa, a nastepnie dlugosc 3 boków podstawy."<<endl;
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
							cout<<"Podales jakas ujemna dlugosc."<<endl;
							break;
						}
                        heron(tablica[1],tablica[2],tablica[3]);
						if (s) break;
						cout<<"Objetosc tego graniastoslupa wynosi: "<<tablica[0]*pole<<endl;
						cout<<"Calkowite pole powierzchni tego graniastoslupa wynoci "<<(tablica[1]*tablica[0])+(tablica[2]*tablica[0])+(tablica[3]*tablica[0])+(2*pole)<<endl;
						break; 
					}
					case 4:{
						cout<<"Podaj wysokosc graniastoslupa, a nastepnie pole jego podstawy."<<endl;
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
							cout<<"Podales jakas ujemna dlugosc."<<endl;
							break;
						}
						cout<<"Objetosc tego graniastoslupa wynosi: "<<tablica[0]*tablica[1]<<endl;
						break; 
					}
					default:{												//zly wybor g trojkatnego
						cout<<"Musisz wybrac opcje 1-"<<q<<"!!!"<<endl;         					
						break; 
					}
					}														//koniec switcha g. trojkatny
				break;
			}															//koniec case g. trojkatny
			case 4:{													// g. prawidlowy troj
				cout<<"Wybrales graniastoslup prawidlowy trojkatny. Podaj wysokosc tego graniastoslupa oraz dlugosc boku podstawy."<<endl;
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
					cout<<"Podales jakas ujemna dlugosc."<<endl;
					break;
				}
				tablica[2]=2*rownoboczny(tablica[1]);
				tablica[3]=3*prostokat(tablica[0],tablica[1]);
				cout<<"Calkowite pole powierzchni wynosi: "<<tablica[2]<<"+"<<tablica[3]<<" pierwiastkow z 3"<<endl;
				cout<<"Czyli  w przyblizeniu: "<<(tablica[3]*sqrt(3))+tablica[2]<<endl;
				tablica[3]=rownoboczny(tablica[1])*tablica[0];
				cout<<"Objetosc tego graniastoslupa wynosi: "<<tablica[3]<<" pierwiastkow z 3"<<endl;
				cout<<"Czyli  w przyblizeniu: "<<tablica[3]*sqrt(3)<<endl;
				break; 
			}															//koniec prawidlowy trojkatny
			case 5:{													// graniastoslup prawidlowy szesciokatny	
				cout<<"Wybrales graniastoslup prawidlowy szesciokatny. Podaj Jego wysokosc oraz dlugosc krawedzi podstawy"<<endl;
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
					cout<<"Podales jakas ujemna dlugosc."<<endl;
					break;
				}
				tablica[2]=2*szesciokat(tablica[1]);
				tablica[3]=6*prostokat(tablica[1],tablica[0]);
				cout<<"Calkowite pole powierzchni wynosi: "<<tablica[3]<<"+"<<tablica[2]<<" pierwiastkow z 3"<<endl;
				cout<<"Czyli  w przyblizeniu: "<<tablica[3]+(tablica[2]*sqrt(3))<<endl;
				tablica[2]=szesciokat(tablica[1])*tablica[0];
				cout<<"Objetosc tego graniastoslupa wynosi: "<<tablica[2]<<" pierwiastkow z 3"<<endl;
				cout<<"Czyli  w przyblizeniu: "<<tablica[2]*sqrt(3)<<endl;
				break; 
			}															// koniec szesciokatnego	
			default:{ 													//zly wybor graniastoslupa
				cout<<"Musisz podaæ opcje 1-"<<q<<"!!!"<<endl;     		
				break; 
			}		
			}															// koniec swich graniastoslupy
			break;
		}																// koniec case graniastoslupy			
		case 2:{															//ostroslupy 
			cout<<"Wybrales ostroslupy. Wybierz typ ostroslupa:"<<endl;		q=0;
			cout<<q<<": powrot do menu glownego."<<endl;					q++;
			cout<<q<<": czworoscian /gotowy"<<endl;							q++;
			cout<<q<<": ostroslup trojkatny"<<endl;							q++;
			cout<<q<<": ostroslup prawidlowy trojkatny"<<endl;				q++;
			cout<<q<<": ostroslup czworokatny"<<endl;						q++;
			cout<<q<<": ostroslup prawidlowy czworokatny /gotowy"<<endl;	q++;
			cout<<q<<": ostroslup prawidlowy szesciokatny /gotowy"<<endl;
			cin>>liczba;
			spr();
			if(s)break;
			switch(liczba){												//wybor ostroslupa
			case 0: break;
			case 1:{                                                    //czworoscian
				cout<<"Wybrales czworoscian. Podaj dlugosc boku."<<endl;
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
					cout<<"Podales jakas ujemna dlugosc."<<endl;
					break;
				}
				tablica[1]=4*rownoboczny(tablica[0]);
				cout<<"Calkowite pole powierzchni wynosi: "<<tablica[1]<<" pierwiastkow z 3"<<endl;
				cout<<"Czyli  w przyblizeniu: "<<tablica[1]*sqrt(3)<<endl;
				tablica[1]=(tablica[0]*tablica[0]*tablica[0])/12;
				cout<<"Objetosc wynosi: "<<tablica[1]<<" pierwiastkow z 2"<<endl;
				cout<<"Czyli  w przyblizeniu: "<<tablica[1]*sqrt(2)<<endl;
				break; 
			}                                              				//koniec czworoscianu		
			case 5:{													// ostroslup p. czworokatny
				cout<<"Wybrales ostroslup prawidlowy czworokatny. Poadaj Wysokosc tego ostroslupa i dlugosc krawedzi podstawy."<<endl;
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
					cout<<"Podales jakas ujemna dlugosc."<<endl;
					break;
				}
				cout<<"Calkowite pole powierzchni wynosi: "<<4*prostokat(tablica[1],tablica[0])+kwadrat(tablica[1])<<endl;
				cout<<"Objetosc wynosi: "<<kwadrat(tablica[1])*tablica[0]<<endl;
				break; 
			}															// koniec ostroslupa kwadratowego
			case 6:{													// ostroslup p. szesciokatny
				cout<<"Wybrales ostroslup prawidlowy szesciokatny. Poadaj Wysokosc tego ostroslupa i dlugosc krawedzi podstawy."<<endl;
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
					cout<<"Podales jakas ujemna dlugosc."<<endl;
					break;
				}
				tablica[2]=szesciokat(tablica[1]);
				tablica[3]=6*prostokat(tablica[1],tablica[0]);
				cout<<"Calkowite pole powierzchni wynosi: "<<tablica[3]<<"+"<<tablica[2]<<" pierwiastkow z 3"<<endl;
				cout<<"Czyli  w przyblizeniu: "<<tablica[3]+(tablica[2]*sqrt(3))<<endl;
				tablica[2]=szesciokat(tablica[1])*tablica[0];
				cout<<"Objetosc wynosi: "<<tablica[2]<<" pierwiastkow z 3"<<endl;
				cout<<"Czyli  w przyblizeniu: "<<tablica[2]*sqrt(3)<<endl;
				break; 
			}															// koniec ostroslupa szesciokatnego
			default:{ 													//zly wybor ostroslupa
				cout<<"Musisz wybrac opcje 1-"<<q<<"!!!"<<endl;     
				break; 
			}
			}															//koniec switch stroslupow	
			break;
		}																//koniec case ostroslupow (case3)
		case 3:{															//bryly 
			cout<<"Wybrales bryly obrotowe. Wybierz typ bryly."<<endl;	q=0;
			cout<<q<<": powrot do menu glownego."<<endl;				q++;
			cout<<q<<": Walec"<<endl;									q++;
			cout<<q<<": Stozek"<<endl;									q++;
			cout<<q<<": Kula"<<endl;			
			cin>>liczba;
			spr();
			if(s)break;
			switch(liczba) {											//switch bryly
			case 0: break;
			case 1:{													//walec
				cout<<"Wybrales walec. Podaj wysokosc i promien podstawy"<<endl;
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
					cout<<"Podales jakas ujemna dlugosc."<<endl;
					break;
				}
				tablica[2]=2*tablica[1]*(tablica[1]+tablica[0]);
				cout<<"Calkowite pole powierzchni wynosi: "<<tablica[2]<<" pi"<<endl;
				cout<<"czyli w przyblizeniu: "<<tablica[2]*PI<<endl;
				tablica[2]=tablica[1]*tablica[1]*tablica[0];
				cout<<"Objetosc wynosi: "<<tablica[2]<<" pi"<<endl;
				cout<<"czyli w przyblizeniu: "<<tablica[2]*PI<<endl;
				break; 
			}															//koniec walca
			case 2:{													//stozek
				cout<<"Wybrales wstozek. Podaj wysokosc i promien podstawy"<<endl;
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
					cout<<"Podales jakas ujemna dlugosc."<<endl;
					break;
				}
				tablica[3]=sqrt((tablica[1]*tablica[1])+(tablica[0]*tablica[0]));
				tablica[2]=tablica[1]*(tablica[1]+tablica[3]);
				cout<<"Calkowite pole powierzchni wynosi: "<<tablica[2]<<" pi"<<endl;
				cout<<"czyli w przyblizeniu: "<<tablica[2]*PI<<endl;
				tablica[2]=(tablica[1]*tablica[1]*tablica[0])/3;
				cout<<"Objetosc wynosi: "<<tablica[2]<<" pi"<<endl;
				cout<<"czyli w przyblizeniu: "<<tablica[2]*PI<<endl;
				break; 
			}															//koniec stozka	
			case 3:{													//kula
				cout<<"Wybrales kule. Podaj jej promien"<<endl;
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
					cout<<"Podales jakas ujemna dlugosc."<<endl;
					break;
				}
				tablica[0]=4*tablica[0]*tablica[0];
				cout<<"Calkowite pole powierzchni wynosi: "<<tablica[0]<<" pi"<<endl;
				cout<<"czyli w przyblizeniu: "<<tablica[0]*PI<<endl;
				tablica[0]=(4/3)*tablica[0]*tablica[0]*tablica[0];
				cout<<"Objetosc wynosi: "<<tablica[0]<<" pi"<<endl;
				cout<<"czyli w przyblizeniu: "<<tablica[0]*PI<<endl;
				break; 
			}															//koniec kuli
			default:{ 													//zly wybor bryly
				cout<<"Musisz wybrac opcje 1-"<<q<<"!!!"<<endl;     
				break; 
			}
			}															// koniec switch bryl
			break;
		}																//koniec bryl obrotowych (case4)
		default:{ 
			cout<<"Musisz wybrac opcje 1-"<<q<<"!!!"<<endl;         //zly wybor bryly
			break;
		}
		}															//koniec swich bryl
		break;
	}																//koniec case bryly
case 5:{															//uklad 3 rownan
		long double w,wx,wy,wz, a[4][3];	//deklaracja zmiennych 
		cout<<"Wybrales obliczanie ukladu 3 rownan z 3 niewiadomymi."<<endl;
		cout << " Podaj wspolczynniki wg wzoru:"<<endl;
		cout << " 1x + 4y + 7z = 10 \n";
		cout << " 2x + 5y + 8z = 11 \n";
		cout << " 3x + 6y +9z = 12 \n";
		cout<<"Musisz w sumie podac 12 liczb, po kazdej >enter<, jezeli w jakims rownaniu nie wystepuje ktoras niewiadoma wprowadz >0<"<<endl;
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
			if(wx==0 && wy==0 && wz==0) cout<<"to rownanie posiada nieskonczenie wiele rozwiazan"<<endl;
			else cout<<"To rownanie nie posiada rozwiazan"<<endl;
		}
		else{
			cout<<"W="<<w<<endl;
			cout<<"x="<<wx/w<<endl;
			cout<<"y="<<wy/w<<endl;
			cout<<"z="<<wz/w<<endl;
		}
		break;
	}																//koniec ukladu 3 rownan	
case 7:{															//kombinatoryka
		unsigned __int64 j,n,k,z=1;
		cout<<"wybrales kombinatoryke, wybierz ktorym konkretnie zagadnieniem chcesz sie zajac."<<endl;	q=0;
		cout<<q<<": powrot do menu glownego."<<endl;		q++;
		cout<<q<<": Permutacja (obliczanie silni)"<<endl;	q++;
		cout<<q<<": Warjacje bez powtorzen"<<endl;			q++;
		cout<<q<<": Wariacje z powtorzeniami"<<endl;		q++;
		cout<<q<<": Kombinacje"<<endl;
		cin>>liczba;
		spr();
		if(s)break;
		switch(liczba){
		case 0: break;
		case 1:{
			cout<<"Wybrales permutacje. Podaj ilosc elementow zbioru, ktorego permutacje chcesz obliczyc."<<endl;
			cin>>n;
			spr();
			if(s)break;
			if(n<1){
				cout<<"n musi byc wieksze badz rowne 1"<<endl;
				break;
			}
			cout<<n<<" elementow mozna ustawic w ciag na "<<silnia(n)<<" sposobow"<<endl;
			break;
		}
		case 2:{
			cout<<"Wybrales wariacje bez powtorzen. Podaj ilosc elementow w zbiorze (n), oraz ilosc elementow ciagu w ktorym maja zostac umieszczone (k)"<<endl; 
			cin>>n >>k;
			spr();
			if(s)break;
			for(long double i=n-k+1;i<=n;i++)z*=i;
			cout<<"liczba sposobow, w jaki z "<<n<<" elementow mozna utworzyc ciag skladajacy sie z "<<k<<" roznych wyrazow, jest rowna "<<z<<endl;
			break;
		}
		case 3:{
			cout<<"Wybrales wariacje z powtorzeniami. Podaj ilosc elementow w zbiorze (n), oraz ilosc elementow ciagu w ktorym maja zostac umieszczone (k)"<<endl; 
			cin>>n >>k;
			spr();
			if(s)break;
			j=pow(n,k);
			cout<<"liczba sposobow, w jaki z "<<n<<" elementow mozna utworzyc ciag skladajacy sie z "<<k<<" niekoniecznie roznych wyrazow, jest rowna "<<j<<endl;
			break;
		}
		case 4:{
			cout<<"Wybrales kombinacje, podaj ile elementow wybierasz sposrod ilu mozliwych."<<endl; 
			cout<<"Wprowadzona liczba musi oczywiscie nalezec do zbioru N+, w przeciwnym wypadku program zakonczy dzialanie"<<endl;
			cin>>k>>n;
			spr();
			if(s)break;
			if(k>=0 && k<=n){
				for(short int i=0;i<k;i++)z*=((n-k+1+i)/(long double)(i+1));
				cout<<"Liczba sposobow, w jaki sposrod "<<n<<" elementow mozna wybrac "<<k<<" elementow, jest rowna "<<z<<endl;
			}
			else cout<<"k musi byc wieksze lub rowne 1 i mniejsze badz rowne n, oraz obie liczby musza nalezec do N+"<<endl;
			break;
		}
		default:{ 
			cout<<"Musisz wybrac opcje 1-"<<q<<"!!!"<<endl;         //zly wybor kombinatoryka
			break;
		}
		}															//koniec switch kombinatoryka
		break;
	}																//koniec kombinatoryka
case 8:{															//ci¹gi
		long double a1,Sn,r,a3,an;
		unsigned __int64 n;
		cout<<"Wybrales ciagi. Wybierz czym konkretnie chcesz sie zajac:"<<endl;
		cout<<"Ciag arytmetyczny:"<<endl;																q=0;
		cout<<q<<": powrot do menu glownego."<<endl;													q++;
		cout<<q<<": obliczanie n-tego wyrazu za pomoca pierwszego wyrazu ciagu i roznicy"<<endl;		q++;
		cout<<q<<": obliczanie n-tego wyrazu za pomoca sumy czesciowej n pierwszych wyrazow oraz pierwszego wyrazu ciagu"<<endl;	q++;
		cout<<q<<": obliczanie wyrazu za pomoca wyrazu poprzedniego i wyrazu nastepnego"<<endl;			q++;
		cout<<q<<": oblicznie sumy czesciowej n pierwszych wyrazow"<<endl;								q++;
		cout<<"Ciag geometryczny:"<<endl;
		cout<<q<<": obliczanie n-tego wyrazu za pomoca pierwszego wyrazu i ilorazu"<<endl;				q++;
		cout<<q<<": obliczanie wyrazu za pomoca wyrazu poprzedniego i wyrazu nastepnego"<<endl;			q++;
		cout<<q<<": obliczanie sumy czesciowej n pierwszych wyrazow"<<endl;
		cin>>liczba;
		spr();
		if(s)break;
		switch(liczba){
		case 0: break;
		case 1:{
			cout<<"Ktory wyraz ciagu chcesz wyliczyc?"<<endl;
			cout<<"(musisz oczywiscie wprowadzic liczbe nalezaca do N+, inaczej nastapi zakonczenie programu)"<<endl;
			cin>>n;
			spr();
			if(s)break;
			cout<<"Podaj pierwszy wyraz ciagu i roznice"<<endl;
			cin>>a1 >>r;
			spr();
			if(s)break;
			cout<<"an="<<a1+((n-1)*r)<<endl;
			break;
		}	
		case 2:{
			cout<<"Ktory wyraz ciagu chcesz wyliczyc?"<<endl;
			cout<<"(musisz oczywiscie wprowadzic liczbe nalezaca do N+, inaczej nastapi zakonczenie programu)"<<endl;
			cin>>n;
			spr();
			if(s)break;
			cout<<"Podaj sume czesciowa n pierwszych wyrazow oraz a1"<<endl;
			cin>>Sn;
			cin>>a1;
			spr();
			if(s)break;
			cout<<"an="<<((2*Sn)/n)-a1<<endl;
			break;
		}
		case 3:{
			cout<<"Podaj wyraz poprzedni i wyraz nastepny"<<endl;
			cin>>a1>>a3;
			spr();
			if(s)break;
			cout<<"Srodkowy wyraz jest rowny: "<<(a1+a3)/2<<endl;
			break;
		}	
		case 4:{
			cout<<"Sume czesciowa ilu pierwszych wyrazow chcesz obliczyc?"<<endl;
			cout<<"(musisz oczywiscie wprowadzic liczbe nalezaca do N+, inaczej nastapi zakonczenie programu)"<<endl;
			cin>>n;
			spr();
			if(s)break;
			cout<<"Podaj pierwszy wyraz ciagu i roznice"<<endl;
			cin>>a1>>r;
			spr();
			if(s)break;
			an=a1+((n-1)*r);
			cout<<"Suma "<<n<<" pierwszych wyrazow jest rowna "<<n*(a1+an)/2<<endl;
			break;
		}
		case 5:{
			cout<<"Ktory wyraz ciagu chcesz wyliczyc?"<<endl;
			cout<<"(musisz oczywiscie wprowadzic liczbe nalezaca do N+, inaczej nastapi zakonczenie programu)"<<endl;
			cin>>n;
			spr();
			if(s)break;
			cout<<"Podaj pierwszy wyraz ciagu i iloraz"<<endl;
			cin>>a1>>r;
			spr();
			if(s)break;
			cout<<"an="<<a1*pow(r,n-1)<<endl;
			break;
		}		
		case 6:{
			cout<<"Podaj wyraz poprzedni i wyraz nastepny"<<endl;
			cin>>a1>>a3;
			spr();
			if(s)break;
			cout<<"Srodkowy wyraz jest rowny: "<<sqrt(a1*a3)<<endl;
			break;
		}		
		case 7:{
			cout<<"Sume czesciowa ilu pierwszych wyrazow chcesz obliczyc?"<<endl;
			cout<<"(musisz oczywiscie wprowadzic liczbe nalezaca do N+, inaczej nastapi zakonczenie programu)"<<endl;
			cin>>n;
			spr();
			if(s)break;
			cout<<"Podaj pierwszy wyraz ciagu i iloraz"<<endl;
			cin>>a1>>r;
			spr();
			if(s)break;
			if(r==1) cout<<"Suma "<<n<<" pierwszych wyrazow jest rowna "<<n*a1<<endl;
			else cout<<"Suma "<<n<<" pierwszych wyrazow jest rowna "<<a1*((1-pow(r,n))/(1-r))<<endl;
			break;
		}			
		default:{ 													//zly wybor ciagu
			cout<<"Musisz wybrac opcje 1-"<<q<<"!!!"<<endl;     
			break; 
		}
		}															// koniec switch ciagi
		break;
    }																//koniec case 7 - ciagi
case 9:{															//lpodzielnosc
		unsigned long long liczba=1, reszta=1, zadana, liczb=0;
		unsigned short int wybor;
		cout<<"Wybrales cechy podzielnosci, co chcesz zrobic:"<<endl;	q=0;
		cout<<q<<": Wyjsc\n";											q++;
		cout<<q<<": Sprawdzic dana liczbe czy jest pierwsza\n";			q++;
		cout<<q<<": Znalezc wszystkie liczby pierwsze (i ich ilosc) nie wieksze niz podana\n";q++;
		cout<<q<<": Znalexc wszystkie dzielniki danej liczby.\n";
		cin>>wybor;
		spr();
		if(s)break;
		switch(wybor){
		case 0: break;
		case 1: {
			cout<<"Wybierz jaka liczbe chcesz sprawdzic"<<endl;
			cout<<"wybierz 0 by zamknac program"<<endl;
			cin>>liczba;
			spr();
			if(s || liczba==0)break;
			for (unsigned long long i=2;( i<liczba && reszta!=0); i++) reszta=liczba%i;
			if (reszta!=0) cout << liczba << " jest liczba pierwsza"<<endl ;
			else cout<<liczba<<" nie jest liczba pierwsza"<<endl;
			break;
		}
		case 2:{
			bool podzielna=false;
			cout<<"Wybrales szukanie liczb pierwszych
			wybierz jaka najwieksza liczbe chcesz sprawdzic
			wpisz 0 aby zakonczyc\n";
			cin>>zadana;
			spr();
			if(s || zadana==0)break;
			cout<<"Liczby pierwsze:"<<endl;
			do{
				podzielna=false;
				reszta=1;
				liczba++;
				for (unsigned __int64 i=2; (i<liczba && reszta!=0); ++i){
					reszta=liczba%i;
					if (reszta==0) podzielna=true;
				}
				if (!podzielna){
					cout<<liczba<<"; ";
	                liczb++;
				}	
			}while (liczba<zadana);
			cout<<"\n Istnieje "<<liczb<<" liczb pierwszych mniejszych od "<<zadana<<endl;		
			break;
		}
		case 3:{
			cout<<"Wybierz jaka liczbe chcesz sprawdzic"<<endl;
			cout<<"wpisz 0 by zamknac program"<<endl;
			cin>>liczba;
			spr();
			if(s || liczba==0)break;
			cout<<"Dzielniki liczby "<<liczba<<" to:\n";
			for (unsigned __int64 i=1;( i<=liczba); ++i){
				reszta=liczba%i;
				if (reszta==0) cout << i << ", ";
			}
			cout<<"\n";
			break;
		}
		default:{ 
			cout<<"Musisz wybrac opcje 0-"<<q<<"!!!"<<endl;         //zly wybor kombinatoryka
			break;
		}
		}
		break;
	}
case 4:{															//uklad 2 rownan by Dyziu
		long double w, wx, wy, x, y; 
		cout << "Wybrales rozwiazywanie ukladu 2 rownan I stopnia z 2 niewiadomymi."<<endl;
		cout << "Ta czesc programu zostala napisana przez Dyzia."<<endl;
		cout << " ax + by = c \n";
		cout << " dx + ey = f \n";
		cout << "Podaj a, b, c, d, e i f \n";
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
		if (w==0 && wx==0 && wy==0) cout << "Dany uklad rowan jest nieoznaczony (posiada nieskonczenie wiele rozwiazan). \n";
		else if (w==0 && (wx!=0 || wy!=0)) cout << "Dany uklad rowan jest sprzeczny(nie posiada rozwiazan). \n";
		else{
		cout << "Rozwiazaniem tego rowania sa liczby: \n";
		cout << "x = " << wx/w << endl;
		cout << "y = " << wy/w << endl;
		}	
		break; 
	}
case 3:{															//pierwiastki trojmianu by dyziu
		cout << "Wybrales obliczanie pierwiastkow trojmianu kwadratowego.\n";
		cout << " a*x^2 + b*x + c = 0 \n" << endl;
		cout << "Podaj a, b i c ";
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
				cout << "x0 = " << x0 << endl;	
			}
			else cout << "Dane rownanie nie posiada rozwiazan!" << endl;
		}
		else{
			long double x1, x2;
			x1 = (-tablica[1] + sqrt(delta))/(2*tablica[0]);
			x2 = (-tablica[1] - sqrt(delta))/(2*tablica[0]);
			cout << "x1 = " << x1 << endl;
			cout << "x2 = " << x2 << endl;
		}
		break; 
	}	
case 6:{															//Wielomiany
		unsigned long long n,nn, whatever=0;
		__int64 roznica, dzielnik;
		__int64 i;
		long double Wx=0;
		q=0;
		cout<<q<<": Wyjscie\n";								q++;
		cout<<q<<": Szukanie pierwiastkow wielomianu\n";	q++;
		cout<<q<<": dzielenie przez dwumian (schemat hornera)\n";
		cin>>liczba;
		spr();
		if(s)break;
	switch(liczba){
		case 0: break;
		case 1:{
	        cout<<"Podaj stopien wielomianu"<<endl;
			cin>>n;
			spr();
			if(s)break;
			nn=n;
			__int64 h[n], w[n];
			do{																//wczytanie wartosci wspolczynnikow do tablicy
				if(n!=0) cout<<"podaj wspolczynnik (calkowity) przy X w potedze "<<n<<endl;
				else cout<<"podaj wartosc wyrazu wolnego \n";
				cin>>w[n];
				spr();
				if(s)break;
				--n;
			}while(n!=-1);
			if(s)break;
			if (w[0]==0){
				cout<<"wyraz wolny = 0, wiec wielomian spelnia liczba 0 - mozna wylaczyc x przed nawias"<<endl;
				break;
			}
			cout<<"Ten wielomian spelniaja liczby:\n";
			for(dzielnik=-abs(w[0]); dzielnik<=abs(w[0]); ++dzielnik){
				if (dzielnik!=0){
					Wx=0;
					roznica=w[0]%dzielnik;   									// dzielenie module, by sprawdzic czy dzielnik jest dzielnikiem wyrazu wolnego :D
					if (roznica==0) {
						for(long long i=0; i<=nn; i++) Wx+=pow(dzielnik,i)*w[i]; 		// obliczenie W(x) dla danego dzielnika
						if (Wx==0){												//sprawdzenie czy W(x)=0
							cout<<dzielnik<<", ";
							whatever++;
						}
					}
				}
			}
			if (whatever==0) {
				cout<<"Ten wielomian nie posiada pierwiastkow calkowitych, szukanie pierwiastkow rzeczywistych zostanie dodane pozniej\n";
				break;
			}
			cout<<"\n \n
			Ten wielomian posiada "<<whatever<<" pierwiastkow calkowitych.\n";
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
				cout<<"Ten wielomian mozna zapisac w postaci: "<<w[nn];
				for(i=0;i<whatever;++i){
					if (r[i]>0) cout<<"( x - "<<r[i]<<" )";
					else cout<<"( x + "<<abs(r[i])<<" )";
				}	
			}
			cout<<"\n";
			break;
		}
		case 2:{
			long double r;
			cout<<"Podaj stopien wielomianu"<<endl;
			cin>>n;
			spr();
			if(s)break;
			nn=n;
			__int64 h[n], w[n];
			do{																//wczytanie wartosci wspolczynnikow do tablicy
				if(n!=0) cout<<"podaj wspolczynnik (calkowity) przy X w potedze "<<n<<endl;
				else cout<<"podaj wartosc wyrazu wolnego \n";
				cin>>w[n];
				spr();
				if(s)break;
				--n;
			}while(n!=-1);
			if(s)break;
			cout<<"Wybrales dzielenie przez dwumian o postaci (x-r). Podaj r:\n";
			cin>>r;
			spr();
			if(s)break;
			cout<<"Wynik dzielenia podanego wielomianu przez "<< r <<" za pomoca schematu hornera:\n";
			cout<<w[nn]<<"x^"<<nn-1<<" + ";
			h[nn]=w[nn];
			for(i=1;i<=nn;++i){
				h[nn-i]=w[nn-i]+(r*h[nn-i+1]);
				if (nn-1==i) cout<<h[nn-i]<<endl;
				if (nn==i){
					cout<<"reszta jest rowna: "<<h[0]<<endl;
					break;
				}
				if (!(nn-1==i || nn==i)) cout<<h[nn-i]<<"x^"<<nn-(1+i)<<" + ";
			}
			break;
		}
		default:{ 
			cout<<"Musisz wybrac opcje 1-"<<q<<"!!!"<<endl; 			//zly wybor case
			break; 
		}	
	}
	break;
}
case 10:{															//geometria analityczna
		cout<<"Wybrales geometrie analityczna"<<endl;
		cout<<"Wybierz czym konkretnie chcesz sie zajac"<<endl;	q=0;
		cout<<"0: Wyjscie do menu glownego"<<endl;				q++;
		cout<<"1: Odleglosc punktu od prostej"<<endl;			q++;
		cout<<"2: Odleglosc miedzy dwoma punktami"<<endl;
		cin>>liczba;
		spr();
		if(s)break;
		switch(liczba){
			case 0: break;
			case 1:{
				cout << "odleglosc punktu o wpolrzednych (a;b) od prostej o rownaniu cx + dy + e = 0" << endl;
				cout << "podaj wspolrzedna a,b,c,d,e:" << endl;
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
				cout << "Odleglosc punktu o wspolrzednych (" << tablica[0] << ";" << tablica[1] << ") od prostej o rownaniu " << tablica[2] << "x + " << tablica[3] << "y + " << tablica[4] << " = 0 wynosi: " << tablica[5] << endl;
				break;
			}
			case 2:{
				cout << "Obliczanie odleglosci dwoch punktow A i B o wspolrzednych A=(a;b) i B=(c;d)" << endl;
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
				cout << "Odleglosc puntu A=(" << tablica[0] << ";" << tablica[1] << ") i B=(" << tablica[2] << ";" << tablica[3] << ") wynosi: " << tablica[4] << endl;
				break;				
			}
			default:{ 
				cout<<"Musisz wybrac opcje 1-"<<q<<"!!!"<<endl; 			//zly wybor case geometria
				break; 
			}
		}
		break;
	}
case 666:{															//haksy :P
		cout << "szatan cie kocha... buahaha...\n";
		break; 
	}
default:{ 
		cout<<"Musisz wybrac opcje 1-"<<q<<"!!!"<<endl; 			//zly wybor case
		break; 
	}	
}                                                           		//koniec switch
cout<<"\nChcesz wyjsc? t/n\n"<<endl;
cin>>out;
system("cls");														//czysc ekran
} while(out!='t');													//koniec pêtli
//koñcówka
cout<<"Dziekujemy za korzystanie z naszego programu :)"<<endl;
cout<<"copyright Konsi & Dyziu :D"<<endl;
cout<<"specjalne podziekowania dla ludzi z forum programuj.com oraz wszystkich wylapujacych bugi :)"<<endl;
system("pause");
return 0;
}																	//koniec main	