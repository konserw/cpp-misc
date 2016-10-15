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

std::vector<long> horner(std::vector<long>, double);

void algebra(unsigned short ktory2){
	bool out=false;
	double W, wx, wy, wz, Wx, x;
	long reszta, dzielnik, ile=0, stopien, wej;
	int g;
	std::vector<long> pierwiastki;
	std::vector<long> w;
	std::vector<long> wynik;
	double r;

	clear();
	logo();
	switch(ktory2){
		case 0:
			out=true;
			break;
		case 1:
			mvprintw(11, 10, "Szukanie pierwiastkow trojmianu kwadratowego postaci ax^2 + bx + c = 0");
			mvprintw(12, 10, "Podaj wartosci a, b, c");

			if(in(3, R)){
				double delta = pow(tablica[1],2)-(4*tablica[0]*tablica[2]);
				if (delta <= 0){
					if (delta == 0){
						double x0 = -tablica[1] /(2*tablica[0]);
						mvprintw(14, 10, "x0 = %lf", x0);	
					}
					else mvprintw(14, 10, "Dane rownanie nie posiada rozwiazan!");
				}
				else{
					long double x1, x2;
					x1 = (-tablica[1] + sqrt(delta))/(2*tablica[0]);
					x2 = (-tablica[1] - sqrt(delta))/(2*tablica[0]);
					mvprintw(14, 10, "x1 = %lf \t\t x2 = %lf", x1, x2);
				}
			}
			break;
		case 2:
			mvprintw(11, 10, "Wybrales rozwiazywanie ukladu 2 rownan I stopnia z 2 niewiadomymi.");
			mvprintw(12, 10, " ax + by = c");
			mvprintw(13, 10, " dx + ey = f");
			mvprintw(14, 10, "Podaj a, b, c, d, e i f");
		
			if(in(6, R)){
				W=(tablica[0]*tablica[4])-(tablica[1]*tablica[3]);
				wx=(tablica[2]*tablica[4])-(tablica[1]*tablica[5]);
				wy=(tablica[0]*tablica[5])-(tablica[2]*tablica[4]);
				if (W == 0 && wx == 0 && wy == 0)
					mvprintw(16, 10, "Dany uklad rowan jest nieoznaczony (posiada nieskonczenie wiele rozwiazan).");
				else if (W == 0)
					mvprintw(16, 10, "Dany uklad rowan jest sprzeczny (nie posiada rozwiazan).");
				else{
					mvprintw(16, 10, "Rozwiazaniem tego ukladu rownan sa liczby:");
					mvprintw(18, 20, "x = %lf \t\t y = %lf", wx/W, wy/W);
				}	
			}
			break; 
		case 3:
			double a[4][3];
			mvprintw(11, 10, "Wybrales obliczanie ukladu 3 rownan z 3 niewiadomymi.");
			mvprintw(12, 10, "Podaj wspolczynniki wg wzoru:");
			mvprintw(13, 10, "1x + 4y + 7z = 10");
			mvprintw(14, 10, "2x + 5y + 8z = 11");
			mvprintw(15, 10, "3x + 6y +9z = 12");
			mvprintw(16, 10, "Musisz w sumie podac 12 liczb, po kazdej >enter<, jezeli w jakims rownaniu nie wystepuje ktoras niewiadoma wprowadz >0<");
			for(short j=0; j<4; ++j){
				for(short i=0; i<3; ++i){
					echo();
					if(i==0)printw("\n");
					g=scanw("%lf", &x);
					if(g!=1){
						attron(A_BOLD | A_UNDERLINE);
						mvprintw(20, 30, "Wprowadzono nieprawidlowy format danych!");
						attroff(A_BOLD | A_UNDERLINE);
						break;
					}
					a[j][i]=x;
				}
				if(g != 1)break;
			}
			if(g != 1)break;
			W=(a[0][0]*a[1][1]*a[2][2])+(a[1][0]*a[2][1]*a[0][2])+(a[2][0]*a[0][1]*a[1][2])-(a[2][0]*a[1][1]*a[0][2])-(a[0][0]*a[2][1]*a[1][2])-(a[1][0]*a[0][1]*a[2][2]);
			wx=(a[3][0]*a[1][1]*a[2][2])+(a[1][0]*a[2][1]*a[3][2])+(a[2][0]*a[3][1]*a[1][2])-(a[2][0]*a[1][1]*a[3][2])-(a[3][0]*a[2][1]*a[1][2])-(a[1][0]*a[3][1]*a[2][2]);
			wy=(a[0][0]*a[3][1]*a[2][2])+(a[3][0]*a[2][1]*a[0][2])+(a[2][0]*a[0][1]*a[3][2])-(a[2][0]*a[3][1]*a[0][2])-(a[0][0]*a[2][1]*a[3][2])-(a[3][0]*a[0][1]*a[2][2]);
			wz=(a[0][0]*a[1][1]*a[3][2])+(a[1][0]*a[3][1]*a[0][2])+(a[3][0]*a[0][1]*a[1][2])-(a[3][0]*a[1][1]*a[0][2])-(a[0][0]*a[2][1]*a[1][2])-(a[1][0]*a[0][1]*a[2][2]);
			if(W == 0){
				if(wx==0 && wy==0 && wz==0) 
					mvprintw(17, 10, "To rownanie posiada nieskonczenie wiele rozwiazan");
				else
					mvprintw(17, 10, "To rownanie nie posiada rozwiazan");
			}
			else
				mvprintw(17, 10, "X = %lf \t\t Y = %lf \t\t Z = %lf", wx/W, wy/W, wz/W);
			break;
		case 4:
			mvprintw(11, 10, "Wybrales szukanie pierwiastkow wielomianu dowolnego stopnia");
			mvprintw(13, 10, "Podaj wartosc wyrazu wolnego: \t");
			echo();

			g=scanw("%li", &wej);
			if(g != 1){
				mvprintw(15, 10, "Wpisales nieprawidlowy typ danych!");
				break;
			}else 
				w.push_back(wej);
			x = 0;

			for(unsigned i = 1; ; ++i){ 
				mvprintw(14+i, 10, "Podaj wspolczynnik przy x do %u lub litere aby zakonczyc: \t", i); 
				if(scanw("%li", &wej)){ 
					w.push_back(wej); 
					x = 0;
				}
				else{
					stopien = i - 1;
					break;
				}
			} 
			
			clear();
			logo();

			if( w[0] == 0){
				mvprintw(11, 10, "Wyraz wolny rowny 0 wiec wielomian spelnia liczba 0. (Mozesz wyciagnac X przed nawias)");
				break;
			}
			//dzielniki calkowite
			mvprintw(13, 10, "Ten wielomian spelniaja nastepujace liczby calkowite:");
			move(15, 10);
			for(dzielnik = - std::abs( w[0] ); dzielnik <= std::abs( w[0] ); ++dzielnik){
				if (dzielnik!=0){
					Wx=0;
					reszta=w[0]%dzielnik;   // dzielenie modulo, by sprawdzic czy dzielnik jest dzielnikiem wyrazu wolnego
					if (reszta == 0) {
						for(int i=0; i <= stopien; i++) Wx+=pow(static_cast<double>(dzielnik), i) * w[i]; 	// obliczenie W(x) dla danego dzielnika
						if (Wx == 0){		//sprawdzenie czy W(x)=0
							printw("%li, ", dzielnik);
							pierwiastki.push_back(dzielnik);
							ile++;
						}
					}
				}
			}
			if (ile == 0) {
				mvprintw(17, 10, "Ten wielomian nie posiada pierwiastkow calkowitych, szukanie pierwiastkow rzeczywistych zostanie dodane pozniej");
				break;
			}
			mvprintw(17, 10, "Ten wielomian posiada %li pierwiastkow calkowitych.", ile);

			if(ile == stopien){//jezeli tyle pierwiastkow co stopien to rozkladamy
				mvprintw(19, 10, "Ten wielomian mozna zapisac w postaci:");
				mvprintw(21, 10, "%li ", w[stopien]);
				for(int i=0; i<stopien; ++i){
					if (pierwiastki[i]>0) printw("( x - %li ) ", pierwiastki[i]);
					else printw("( x + %li ) ", std::abs(pierwiastki[i]));
				}	
			}
			else{//w przeciwnytm wypadku dzialimy
				std::vector<long> podzielony;
				for(int i=0; i < pierwiastki.size(); ++i){
					podzielony = horner(w, pierwiastki.at(i));
					if(pierwiastki.at(i) < 0) mvprintw(18+i, 10, "Dzielenie przez( x + %li ): ", std::abs(pierwiastki.at(i)));
					else mvprintw(18+i, 10, "Dzielenie przez( x - %li ): ", pierwiastki.at(i));
					w.clear();
					for(int i = 1; i < podzielony.size(); ++i) w.push_back(podzielony.at(i)); //wyraz zerowy pomijamy bo to reszta z dzielenia
					for(int i = w.size() - 1; i >= 0; --i){
						if(w.at(i) == 0) continue;
						else if(w.at(i) > 0){
							if(i == 0) printw(" + %li", w.at(i));
							else if(i == 1) printw(" + %li x", w.at(i));
							else if(i == w.size() - 1) printw(" %li x^%li", w.at(i), i);
							else  printw( " + %li x^%li", w.at(i), i);
						}
						else if(w.at(i) < 0){
							if(i == 0) printw(" - %li", std::abs(w.at(i)));
							else if(i == 1) printw(" - %li x", std::abs(w.at(i)));
							else if(i == w.size() - 1) printw(" - %li x^%li", std::abs(w.at(i)), i);
							else printw(" - %li x^%li", std::abs(w.at(i)), i);
						}
						else printw("ERROR!?!?!");
					}
				}
			}
			break;
		case 5:
			mvprintw(11, 10, "Wybrales dzielenie przez dwumian o postaci ( x - r ). Podaj r:");
			if(in(1, R)) r=tablica[0];
			else break;
			
			mvprintw(13, 10, "Podaj wartosc wyrazu wolnego: \t");
			echo();
			g=scanw("%li", &wej);
			if(g != 1){
				mvprintw(15, 10, "Wpisales nieprawidlowy typ danych!");
				break;
			}else 
				w.push_back(wej);
			wej = 0;

			for(unsigned i = 1; ; ++i){ 
				mvprintw(13+i, 10, "Podaj wspolczynnik przy x do %u lub litere aby zakonczyc: \t", i); 
				if(scanw("%li", &wej)){ 
					w.push_back(wej); 
					wej = 0;
				}
				else break;
			} 
			
			clear();
			logo();

			if( w[0] == 0){
				mvprintw(11, 10, "Wyraz wolny rowny 0 wiec wielomian spelnia liczba 0. (Mozesz wyciagnac X przed nawias)");
				break;
			}
			if(r > 0) mvprintw(11, 10, "Wynik dzielenia podanego wielomianu przez ( x - %lf ) za pomoca schematu hornera:", r);
			else  mvprintw(11, 10, "Wynik dzielenia podanego wielomianu przez ( x + %lf ) za pomoca schematu hornera:", std::abs(r));

			wynik = horner(w, r);
			move(13, 10);
			w.clear();
			for(int i = 1; i < wynik.size(); ++i) w.push_back(wynik.at(i)); //wyraz zerowy pomijamy bo to reszta z dzielenia
			for(int i = w.size() - 1; i >= 0; --i){
				if(w.at(i) == 0) continue;
				else if(w.at(i) > 0){
					if(i == 0) printw(" + %li", w.at(i));
					else if(i == 1) printw(" + %li x", w.at(i));
					else if(i == w.size() - 1) printw(" %li x^%li", w.at(i), i);
					else  printw(" + %li x^%li", w.at(i), i);
				}
				else if(w.at(i) < 0){
					if(i == 0) printw(" - %li", std::abs(w.at(i)));
					else if(i == 1) printw(" - %li x", std::abs(w.at(i)));
					else if(i == w.size() - 1) printw(" - %li x^%li", std::abs(w.at(i)), i);
					else printw( " - %li x^%li", std::abs(w.at(i)), i);
				}
				else printw("ERROR!?!?!");
			}
			if(wynik.at(0) != 0) mvprintw(15, 10, "Reszta z tego dzielenia jest rowna %li", wynik.at(0));
			break;
		}

	if(!out) stop();
}

std::vector<long> horner(std::vector<long> w, double r){
	unsigned stopien = w.size();
	stopien--;
	std::vector<long> p;
	std::vector<long> g;
	
	p.push_back(w.at(stopien)); //p[0] = wspolczynnikowi przy x w najwyzszej potedze
	for(unsigned i=1; i <= stopien; ++i) 
		p.push_back( (r * p.at(i - 1)) + w.at(stopien - i)); //dzielenie
	for(int i=stopien; i >= 0; --i)
		g.push_back(p.at(i)); //odwrocenie wyniku, teraz g[0] to reszta
	return g;
}