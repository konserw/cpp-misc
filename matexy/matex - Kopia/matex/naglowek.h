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

enum eTyp {N, R, J};//R- whatever; N > 0; J >= 1 i ca³kowite

extern std::vector<double> tablica;

//--------------------------------------------
//----------------prototypy funkcji----------
//-------------------------------------------
void stop();

long double ctg (long double alfa);

unsigned __int64 silnia(__int64);

long double twcos(long double, long double, long double);

bool in (unsigned short, eTyp); 

void logo ();

//----------------wybory----------------
void geometria(unsigned short);
void algebra(unsigned short);
void kombinatoryka(unsigned short);
void ciagi(unsigned short);
void teoria(unsigned short);
//stereometria
void graniastoslupy(unsigned short);
	void grantroj(unsigned short);
void ostroslupy(unsigned short);
void obrotowe(unsigned short);
//planimetria
void planimetria(unsigned short);
void trapezy(unsigned short);
void trojkaty(unsigned short);
void kwadraty(unsigned short);
void romby(unsigned short);
void rownolegloboki(unsigned short);
void trapezy(unsigned short);