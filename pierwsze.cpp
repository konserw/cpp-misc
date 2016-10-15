/*
program sprawdzaj�cy czy dana liczba jest liczb� pierwsz�

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

#include <iostream.h>
#include <stdlib.h>

bool pierwsza(unsigned __int64 liczba);

using std::cin;
using std::cout;
using std::cerr;

int main(){
unsigned __int64 liczba;
for(;;){
cout<<"Wybierz jaka liczbe chcesz sprawdzic"<<endl;
cout<<"wybierz 0 by zamknac program"<<endl;
cin>>liczba;
if (!cin.good()){ 
	cerr << "Podales bledny format danych!\n";
	cin.clear(); 
	cin.ignore();
    continue;
    }
if(liczba==0)break;
if(pierwsza(liczba))cout<<liczba<<" nie jest liczba pierwsza"<<endl;
else cout << liczba << " jest liczba pierwsza"<<endl ;

}
return 0;
}

bool pierwsza(unsigned __int64 liczba){
	unsigned __int64 reszta=1;
	for (unsigned long long i=2;( i<liczba && reszta!=0); i++) reszta=liczba%i;
	if (reszta!=0)return true;
	else return false;
}
