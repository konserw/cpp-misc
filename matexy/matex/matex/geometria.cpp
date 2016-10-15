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

void geometria(unsigned short ktory2){
	bool out=false;
	clear();
	logo();
	switch(ktory2){
		case 0:
			out=true;
			break;
		case 1:
			mvprintw(11, 10, "Odleglosc punktu o wpolrzednych (x;y) od prostej o rownaniu ax + by + c = 0");
			mvprintw(12, 10, "Podaj wartosci x, y, a, b, c");

			if(in(5, R)){
				tablica.push_back(
					std::abs(
						(tablica[2]*tablica[0])
						+(tablica[3]*tablica[1])
						+tablica[4]
				));
				tablica.push_back(
					sqrt(
						pow (tablica[2], 2)
						+ pow (tablica[3], 2)
					));

				mvprintw(14, 10, "Odleglosc punktu o wspolrzednych ( %lf ; %lf )", tablica[0], tablica[1]);
				mvprintw(15, 10, "od prostej o rownaniu f(x) = %lfx + %lfy + %lf = 0", tablica[2], tablica[3], tablica[4]);
				mvprintw(16, 20, "wynosi %lf", tablica[5]/tablica[6]);
			}
			break;

		case 2:
			mvprintw(11, 10, "Obliczanie odleglosci pomiedzy punktami A i B o wspolrzednych A = (a;b) i B = (c;d)");
			mvprintw(12, 10, "Podaj wartosci a, b, c, d");

			if(in(4, R)){
				tablica.push_back(
					sqrt(
					pow( (tablica[2]-tablica[0]), 2)
					+ pow( (tablica[3]-tablica[1]), 2)
					));
				mvprintw(13, 10, "Odleglosc pomiedzy puntami A = ( %lf ; %lf ) i B = ( %lf ; %lf ) wynosi %lf",
					tablica[0], tablica[1], tablica[2], tablica[3], tablica[4]);
				tablica.push_back((tablica[0] + tablica[2])/2);
				tablica.push_back((tablica[1] + tablica[3])/2);
				mvprintw(15, 10, "Srodek odcina AB znajduje sie w punkcie ( %lf ; %lf )", tablica[5], tablica[6]);
			}
			break;

		case 3:
			mvprintw(11, 10, "Zaleznosci pomiedzy prostymi ax + by + c = 0 i dx + ey + f = 0");
			mvprintw(12, 10, "Podaj wartosci a, b, c, d, e, f");
			
			if(in(6, R)){
				if( (
					(tablica[0] * tablica[4])
					- (tablica[3] * tablica[1])
					)== 0)
					mvprintw(14, 10, "Podane proste sa do siebie rownolegle");
				else if((
					(tablica[0] * tablica[3])
					+ (tablica[1] * tablica[4])
					) == 0 )
					mvprintw(14, 10, "Podane proste sa do siebie prostopadle");
				else{
					tablica.push_back( std::abs(
						(
							(tablica[0] * tablica[4])
							- (tablica[3] * tablica[1])
						)/(
							(tablica[0] * tablica[3])
							+ (tablica[1] * tablica[4])
						)));
					mvprintw(14, 10, "Podane proste tworza kat %lf", tablica[6]*180/M_PI);

					double wx, wy, w;
					tablica[2]=-tablica[2];
					tablica[5]=-tablica[5];
					w=(tablica[0]*tablica[4])-(tablica[1]*tablica[3]);
					wx=(tablica[2]*tablica[4])-(tablica[1]*tablica[5]);
					wy=(tablica[0]*tablica[5])-(tablica[2]*tablica[4]);

					mvprintw(16, 10, "I przecinaja sie w punkcie ( %lf ; %lf )", wx/w, wy/w);
				}
			}
			break;
	}
	if(!out)stop();
}