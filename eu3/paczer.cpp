/*
paczer - program s³u¿¹cy do zmieniania plików tekstowych, 
zaprojektowany zosta³ dla ekipy tworz¹cej moda do EU3 
Divide et Impera!
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
#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

bool dopisz (std::string, std::string);
bool linia (std::string sciezka, std::string tekst, unsigned n_linii);

int main(int argc, char *argv[])
{
//------zmienne-----------------------
	std::string sciezka, tekst;
	unsigned n_linii;
//--------koniec zmiennych------------
//---------poczatkowa gatka :P--------
	std::cout<<"Witamy w paczerze moda Divide et Impera!\n"
		"Najambitniejszy i najwiekszy polski mod do EU3\n"
		"Ten plik powinien zostac uruchomiony w katalogu gry\n"
		"np. c:/program files/paradox interactive/europa universalis 3\n"
		"Nacisnij dowolny klawisz aby rozpoczac proces paczowania moda\n";
	getchar();
//--------------------------------------------------------------------------
//czêœæ interesuj¹ca Was:
	sciezka="mod\\Divide et Impera\\common\\event_modifiers2.txt";//sciezka do pliku Was interesujacego
	tekst = "\n"	//"\n" nie nalezy usuwac!		//tekst jaki zostanie dopisany na koncu pliku
		"DeIrevolution = {\n"						//kazda linia musi byc ujeta w ""
		"\tglobal_revolt_risk = 7\n"					//na koncu kazdej linii nalezy dac /n
		"\tstability_cost_modifier = 0.25\n"			//jak widac w przykladzie
		"\tgovernment_tech_cost_modifier = -0.1\n"	
		"\ticon = 2\n" 
		"}"; 
//-----------dopisanie na koncu pliku
	if (dopisz (sciezka, tekst))
		std::cout<<"zapis wykonany prawidlowo\n";
	else std::cout<<"cos sie nie udalo ;/\n";
//koniec dopisania
	//tu nalezy skopiowac kolejne instrukcje
	//czyli znowu sciezka="costam", tekst="costam" + ew. n_linii
	//i "dopisanie" lub "zmiana linii" skopiowac bez zmian
	
	sciezka="mod\\costam\\whatever.txt";	//sciezka do pliku w jakim maja zostac wprowadzone zmiany
	n_linii=3;						//nr. linii ktora chcecie zmienic
	n_linii--;
	tekst="whatever";				//caly takst jaki ma byc w tejze linii
	
//zmiana linii
	if(linia(sciezka, tekst, n_linii)) std::cout<<"zapis sie powiodl\n";
	else std::cout<<"cos poszlo zle\n";
//koniec zmiany linii

	//miejsce na dalsze instrukcje zrobione metoda ctrl+c, ctrl+v :D

//-----------------------------------------------------------------------
//Koniec czesci Was interesujacej :)
	std::cout<<"\n"
	"Mod tworzony przez Netzacha, Einfalla i Piotera.\n"
	"Paczer i manual zaprojektowane przez  Konserwa\n"	
	"copyleft konserw\n"
	"nacisnij dowolny klawisz aby zakonczyc dzialanie programu\n";
	getchar();
	return 0;

}
//---------------------- funkcje ----------------------------------------
bool dopisz(std::string sciezka, std::string tekst){
std::ofstream plik;
plik.open(sciezka.c_str(),std::ios::app);
if(plik.is_open() && plik.good()){
	std::cout<<"Uzyskano dostep do pliku:\n"<<sciezka<<"\n";
	plik<<tekst<<std::endl;
	if (plik.fail()){
		std::cerr<<"error! zapis do  pliku nie powiodl sie!\n";
		plik.close();
		return false;
	}else{
		std::cout<<"Zapis poprawny :D\n";
		plik.close();
		return true;
	};
}else {
		std::cout<<"Dostep do pliku:\n"
			<<sciezka<<"\n"
			"zostal zabroniony!\n";
		plik.close();
		return false;
	};
};
bool linia (std::string sciezka, std::string tekst, unsigned n_linii){
	unsigned __int64 nolines=0;
	//------utworzenie vectora i jego wyczyszczenie------
	std::vector<std::string> linia;
	linia.clear();
	//---------wczytanie linia po linii---------
	std::ifstream plik;
	plik.open(sciezka.c_str());
	if (plik.is_open() && plik.good()){
		std::string buff;
		while(!plik.eof()){
			getline(plik, buff);
			linia.push_back(buff);
		}
		std::cout<< "wczytano wszystkie: "<<linia.size()<<" linii pliku: "<<sciezka<<"\n";
		plik.close();
	}else{
		std::cout<<"wczytanie pliku nie powiodlo sie\n";
		plik.close();
		return false;
	};

	//----Zapis---------

	std::ofstream zplik;
	zplik.open(sciezka.c_str());

	//-----------diagnostyka----------
	/*
	std::cout<<linia.size()<<"\n";
	std::cout<<"tekst: "<<tekst<<"\n";
	for (unsigned i=1; i<linia.size(); ++i){
		std::cout<<i<<": "<<linia[i]<<"\n";
	};
	getchar();
	*/
	//---------koniec diagnostyki-------
	
	for (unsigned i=0; i<linia.size(); ++i){
		if(i==n_linii){
			zplik<<tekst<<std::endl;
		}else{
			zplik<<linia[i]<<std::endl;
		};
	};
	zplik.close();
	return true;
};

