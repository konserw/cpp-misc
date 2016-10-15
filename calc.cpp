/*
 * Prosty kalkulator...
 *
 * Copyright (C) 2009 Kamil Strzempowicz
 * Niniejszy program jest wolnym oprogramowaniem; mo¿esz go 
 * rozprowadzaæ dalej i/lub modyfikowaæ na warunkach Powszechnej
 * Licencji Publicznej GNU, wydanej przez Fundacjê Wolnego
 * Oprogramowania - wed³ug wersji 2-giej tej Licencji lub którejœ
 * z póŸniejszych wersji. 
 * Niniejszy program rozpowszechniany jest z nadziej¹, i¿ bêdzie on 
 * u¿yteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyœlnej 
 * gwarancji PRZYDATNOŒCI HANDLOWEJ albo PRZYDATNOŒCI DO OKREŒLONYCH 
 * ZASTOSOWAÑ. W celu uzyskania bli¿szych informacji - Powszechna 
 * Licencja Publiczna GNU. 
 * Z pewnoœci¹ wraz z niniejszym programem otrzyma³eœ te¿ egzemplarz 
 * Powszechnej Licencji Publicznej GNU (GNU General Public License);
 * jeœli nie - napisz do Free Software Foundation, Inc., 675 Mass Ave,
 * Cambridge, MA 02139, USA.
 * 
 * Pozdrawiam, konserw.
 * konserw@gmail.com
 */

#include <iostream.h>
#include <stdlib.h>
double dodawanie ( double a, double b ){
return ( a + b );}
double odejmowanie ( double a, double b ){
return ( a - b );}
double mnozenie ( double a, double b ){
return ( a * b );}
double dzielenie ( double a, double b ){
if (b) return ( a / b );
else cout<<"nie dziel przez 0! \n";}

int main()
{
double a, b;
unsigned op;
char cokolwiek;
do{
cout<<"podaj liczbe na ktorej chcesz wykonac operacje: ";
cin>>a;
cout<<
"Co chcesz zrobic?\n"
"1: dodac\n"
"2: odjac\n"
"3: pomnozyc\n"
"4: podzielic \n";
cin>>op;
cout<<"podaj druga liczbe: ";
cin>>b;
switch(op){
	case 1: {
		cout<<"Wynik twojego dzialania to: "<<dodawanie ( a, b )<<endl;
		break;
	}
	case 2: {
		cout<<"Wynik twojego dzialania to: "<<odejmowanie ( a, b )<<endl;
		break;
	}
	case 3: {
		cout<<"Wynik twojego dzialania to: "<<mnozenie ( a, b )<<endl;
		break;
	}
	case 4: {
		cout<<"Wynik twojego dzialania to: "<<dzielenie( a, b )<<endl;
		break;
	}
}
cout<<"aby zakonczyc nacisnij X; aby kontynuowac nacisnij dowolna litere i enter\n";
cin>>cokolwiek;
}while ( cokolwiek != 'x' && cokolwiek != 'X' );
return 0;
}
