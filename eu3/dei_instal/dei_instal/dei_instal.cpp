/*
 * dei_instal - zautomatzowany instalator moda Divide et Impera
 * do gry Europa Universalis III
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

#include "stdafx.h"
using namespace std;

std::string wersja(std::string, HKEY);
enum Egame_ver{
	eVanila,
	eNA,
	eIN,
	eERR
};

HRESULT download (Egame_ver);

int main()
{
	HKEY hkSoftware, hkParadox, hkEU;
	LONG result;
	char* buf;
	std::string NA, in, vanila;
	Egame_ver game_ver;
	char znak = 'o';

	cout << "Witam w instalatorze moda DeI!\n"
		"Mod powstaje na forum EUFI.org\n"
		"Jest on tworzony przez Einfalla, Netzacha i Piotera\n"
		"Przy skromnej wspolpracy m.in. z mojej strony ;)\n"
		"i wsparciu calej spolecznosci EUFI\n"
		"Pozdrtawiam, konserw.\n"
		"Ten program korzysta z open surcowego programu 7zip\n"
		"Aby zobaczyc licencje wcisnij 'L'\n"
		"UWAGA! Jezeli nie jestes polaczony z internetem program moze sie posypac\n"
		"Czy chcesz rozpoczac instalacje? [T/N/L]\t";

	while(znak != 't' && znak != 'T'){
		cin >> znak;
		if(znak == 'L' || znak == 'l') system("licencja.htm");
		else if(znak == 'n' || znak == 'N')	return 0;
	}

	if(RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE", 0, KEY_ALL_ACCESS, &hkSoftware) == ERROR_SUCCESS)
		cout<<"Udalo sie otworzyc klucz software.\n";
	

	result = RegOpenKeyExA(hkSoftware, "Paradox Interactive", 0, KEY_ALL_ACCESS, &hkParadox);
	if(result == ERROR_SUCCESS)
		cout<<"Udalo sie otworzyc klucz Paradox Interactive\n";
	else{
		cout << "ERROR! (mozliwe, ze masz niepoprawnie zainstaowana gre, badz nie masz jej wcale)\n";
	}
	result = RegOpenKeyExA(hkParadox, "Europa Universalis III", 0, KEY_ALL_ACCESS, &hkEU);
	if(result == ERROR_SUCCESS)
		cout<<"Udalo sie otworzyc klucz Europa Universalis III\n";
	else{
		cout << "ERROR! (mozliwe, ze masz niepoprawnie zainstaowana gre, badz nie masz jej wcale)\n";
	}

	int rozmiar_bufora = 500;
	buf = new char [rozmiar_bufora + 1];
	DWORD dwBufSize = rozmiar_bufora;
	DWORD typ_klucza = REG_SZ; 
    result = RegQueryValueExA(hkEU, "app", NULL, &typ_klucza, (LPBYTE)buf, &dwBufSize);
	if(result == ERROR_SUCCESS)
	{
	 buf[rozmiar_bufora] = 0;
	}
	else if(result == ERROR_FILE_NOT_FOUND){
		cout<<"nie odnaleziono wartosci - gra zostala nieprawidlowo zainstalowana\n";
	}
	else{
		cout<<"unknown error!\n";
	}
	std::string path = buf;
	delete[] buf;
	size_t pos = path.find_last_of("\\");
	path = path.substr(0, ++pos);
	cout<<"Sciezka instalacyjna gry:\t"<<path<<"\n\n";

	NA = wersja("napoleon", hkEU);
	in = wersja("InNomine", hkEU);
	vanila = wersja("version", hkEU);
	if(NA != "error" && NA != "not_found"){//NA
		if(in != "error" && in != "not_found"){//IN
			if(in == "3.2"){
				game_ver = eIN;
			}
			else{
				cout << "Masz zainstalowany dodatek In Nomine, lecz mod wymaga bys zainstalowal pacz do niego\n"
					"Zainstaluj najpierw oficjalny pacz 3.2\n"
					"Nastepnie uruchom ponownie ten program\n";
			}
		}
		else if(NA == "2.2") game_ver = eNA;
		else{
			cout << "Masz zainstalowany dodatek Napoleon's Ambitions, lecz mod wymaga bys zainstalowal pacz do niego\n"
				"Zainstaluj pacz 2.2 i uruchom ponownie ten program\n";	
		}
	}
	else if(vanila != "error" && vanila != "not_found"){
		if(vanila == "1.03.01"){//?
			game_ver = eVanila;
		}
		else if(vanila == "1.03.00"){
			cout << "Masz zainstalowany pacz 1.3\n"
				"Zainstaluj pacz 1.3.1 ze strony wydawcy i uruchom ponownie ten program\n";
		}
		else if(vanila == "1.00.00"){
			cout << "MAsz zainstalowane 'gole' EU lecz mod wymaga bys zainstalowal pacz do niego\n"
				"Zainstaluj najpierw oficjalny pacz 1.3, potem pacz 1.3.1 ze strony wydawcy i uruchom ponownie ten program\n";
		}
	}
	else{
		cout << "masz niepoprawnie zainstalowana gre!\n";
	}
	if(game_ver != eIN && game_ver != eNA && game_ver != eVanila){
		cout<<"nastapi zakonczenie programu\n";
		system("pause");
		return 0;
	}
	HRESULT res = download(game_ver);
	if(res == S_OK) cout << "Pobieranie zakonczone pomyslnie!\n";
	else if(res == E_OUTOFMEMORY){
		cout <<"The buffer length is invalid, or there is insufficient memory to complete the operation.\n"
			"nastapi zakonczenie programu\n";
		system("pause");
		return 0;
	}
	else if(res == INET_E_DOWNLOAD_FAILURE){
		cout << "The specified resource or callback interface was invalid.\n"
			"nastapi zakonczenie programu\n";
		system("pause");
		return 0;
	}			

	std::vector<std::string> vec;
	vec.push_back("@echo off");
	std::string buff;
	buff = "7za x dei.7z -o";
	buff += '"';
	buff += path;
	buff += "mod\\";
	buff += '"';
	vec.push_back(buff);

	cout <<	"Wyczyscic cache? (zalecane) [T/N]\t";
	cin >> znak;
	if(znak == 'T' || znak == 't'){
		buff.clear();
		buff = "del ";
		buff += "/Q ";
		buff += '"';
		buff += path;
		buff += "map\\cache\\";
		buff += '"';
		vec.push_back(buff);
	}
	
	cout <<	"Zmienic ustawienia na zalecane? (gameplaysettings i settings) [T/N]\t";
	cin >> znak;
	if(znak == 'T' || znak == 't'){
		vector<string> set;
		set.push_back("gameplaysettings={");
		set.push_back("setgameplayoptions={");
		set.push_back("0 0 0 0 0 0 0 0 3 0 4 4 0 2    }");
		set.push_back("}");

		buff = path;
		buff += "gameplaysettings.txt";

		ofstream ofile;
		ofile.open(buff.c_str());
		for(unsigned short i=0; i < set.size(); ++i)
			ofile << set.at(i) << endl;
		ofile.close();

		set.clear();
		buff = path;
		buff += "settings.txt";

		ifstream ifile;
		ifile.open(buff.c_str());
		while(getline(ifile, buff))
			set.push_back(buff);
		ifile.close();

		cout << "\n\nbuff: " << buff <<"\n\n";

		set.at(1) = "language=l_polish";
		set.at(11) = "multisampling=0";
		set.at(12) = "anisotropicFiltering=0";
		set.at(26) = "renderTrees=no";
		set.at(27) = "onmap=no";
		set.at(28) = "simpleWater=yes";

		buff = path;
		buff += "settings.txt";

		ofile.open(buff.c_str());
		for(unsigned short i=0; i < set.size(); ++i)
			ofile << set.at(i) << endl;
		ofile.close();

	}
/*	
	cout << "wyswietlic manuala po zakonczeniu instalacji?\n"
		"(wymagany jakis pdf reader)[T/N]\t";
	cin >> znak;
	if(znak == 'T' || znak == 't'){
		buff.clear();
		buff = '"';
		buff += path;
		buff += "mod\\manual.pdf";
		buff += '"';
		vec.push_back(buff);	
	}
*/	
	if(game_ver != eIN){
		cout << "Po rozpakowaniu zostanie uruchomiony paczer, ktory zmieni date startu gry.\n"
			"Nalezy wskazac mu sciezke do pliku eu3game.exe w folderze glownym gry.\n";
		buff.clear();
		buff = '"';
		buff += path;
		buff += "mod\\pacz.exe";
		buff += '"';
		vec.push_back(buff);
	}

	ofstream plik;
	plik.open("instal.bat");
	for(unsigned i = 0; i < vec.size(); ++i)
		plik<<vec.at(i)<<endl;
	plik.close();

	cout << "Teraz nastapi instalacja\n";
	system("pause");
	system("instal.bat");

	cout << "Instalacja zakonczona (mam nadzieje) pomyslnie!\n";
	cout << "Zalecam przeczytanie manuala dostepnego na EUFI.org przed gra\n"
		"zostal stworzony dla wersji 1.6, lecz i tak warto przejrzec\n"
		"have fun! [konserw]\n";
	system("pause");	
	return 0;
}

std::string wersja(std::string dodatek, HKEY hkEU){
	DWORD typ_klucza = REG_SZ; 
	const int rozmiar_bufora = 10;
	DWORD dwBufSize = rozmiar_bufora;
	char buf [rozmiar_bufora + 1];
    LONG result = RegQueryValueExA(hkEU, dodatek.c_str(), NULL, &typ_klucza, (LPBYTE)buf, &dwBufSize);
	if(result == ERROR_SUCCESS){
		buf[rozmiar_bufora] = 0;
		std::string str = buf;
		delete[] buf;
		return str;
	}
	else if(result == ERROR_FILE_NOT_FOUND){
		delete[] buf;
		return "not_found";
	}
	else{
		delete[] buf;
		return "error";
	}
}

HRESULT download (Egame_ver wersja){
	HRESULT result;
	string url;

	switch(wersja){
		case eVanila:
			cout<<"pobieram moda pod vanile. Prosze czekac...\n";
			url = "http://konserw.eufi.org.pl/dei/vanila.7z";
			break;
		case eNA:
			cout<<"pobieram moda pod NA. Prosze czekac...\n";
			url = "http://konserw.eufi.org.pl/dei/NA.7z";
			break;
		case eIN:
			cout<<"pobieram moda pod IN. Prosze czekac...\n";
			url = "http://konserw.eufi.org.pl/dei/IN.7z";
			break;
	}
	cout << "moze to zajac nawet kilka minut, a program bedzie wygladal na zwieszony!\n";
	cout.flush();
	result = URLDownloadToFileA(      
		NULL,
		url.c_str(),
		"dei.7z",
		NULL,
		NULL);
	return result;
}