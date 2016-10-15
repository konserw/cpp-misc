/*
 * paczer dla DeI by konserw
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

bool sciezka(std::string& path){
	log("sciezka", "Pocz¹tek szuaknia scie¿ki");

	HKEY hkSoftware, hkParadox, hkEU;
	LONG result;
	char* buf;
	const int rozmiar_bufora = 500;
	DWORD dwBufSize = rozmiar_bufora;
	DWORD typ_klucza = REG_SZ; 

	if(RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE", 0, KEY_ALL_ACCESS, &hkSoftware) == ERROR_SUCCESS)
		log("sciezka", "Udalo sie otworzyc klucz software.");
	else{
		log("sciezka", "nie uda³o siê otworzyæ klucza software");
		return false;
	}	

	result = RegOpenKeyExA(hkSoftware, "Paradox Interactive", 0, KEY_ALL_ACCESS, &hkParadox);
	if(result == ERROR_SUCCESS)
		log("sciezka", "Udalo sie otworzyc klucz Paradox Interactive");
	else{
		log("sciezka", "ERROR! (mozliwe, ze masz niepoprawnie zainstaowana gre, badz nie masz jej wcale)");
		return false;
	}
	result = RegOpenKeyExA(hkParadox, "Europa Universalis III", 0, KEY_ALL_ACCESS, &hkEU);
	if(result == ERROR_SUCCESS)
		log("sciezka", "Udalo sie otworzyc klucz Europa Universalis III");
	else{
		log("sciezka", "ERROR! (mozliwe, ze masz niepoprawnie zainstaowana gre, badz nie masz jej wcale)");
		return false;
	}

	buf = new char [rozmiar_bufora + 1];

    result = RegQueryValueExA(hkEU, "app", NULL, &typ_klucza, (LPBYTE)buf, &dwBufSize);
	if(result == ERROR_SUCCESS){
		buf[rozmiar_bufora] = 0;
	}
	else if(result == ERROR_FILE_NOT_FOUND){
		log("sciezka", "nie odnaleziono wartosci - gra zostala nieprawidlowo zainstalowana");
		delete[] buf;
		return false;
	}
	else{
		log("sciezka", "unknown error");
		delete[] buf;
		return false;
	}
	path = buf;
	delete[] buf;
	size_t pos = path.find_last_of("\\");
	path = path.substr(0, ++pos);
	log("sciezka", "Sciezka instalacyjna gry", path.c_str());
	log("sciezka", "Koniec szukania scie¿ki\n");
	return true;
}

void wybor_moda(std::string& path){
	log("wybor_moda", "Pocz¹tek wyboru moda");


    WIN32_FIND_DATAA wfd; 
	std::vector<std::string> pliki;
	std::string jaki_mod;

	std::string buff = path;
	buff += "mod\\*"; 
	log("wybor_moda", "path + *", buff.c_str());
	pliki.push_back("vanila");
	HANDLE uchwyt = FindFirstFileA(buff.c_str(), &wfd); 
    if (uchwyt != INVALID_HANDLE_VALUE) 
    { 
		do{
			buff = static_cast<std::string>(wfd.cFileName);
			if(buff.find(".mod") != std::string::npos || buff.find(".MOD") != std::string::npos){
				pliki.push_back(buff.substr(0, buff.size()-4));
				log("wybor_moda", "znaleziono plik .mod", buff.c_str());
			}
		}while (FindNextFileA(uchwyt, &wfd)); 
        FindClose(uchwyt); 
    }
	if(pliki.size() == 1)jaki_mod = "vanila";
	else{
		std::string vOpis;
		vOpis = "Witam w paczerze dla DeI\Wybierz swojego moda";
		
		cMenu menu(vOpis, pliki);

		menu.co(5, 5, jaki_mod);
		log("wybor_moda", "wybrana wersja gry", jaki_mod.c_str());

		if(jaki_mod != "vanila"){
			path += "mod\\";
			path += jaki_mod;
			path += "\\";
		}
		log("wybor_moda", "sciezka", path.c_str());
	}
	log("wybor_moda", "koniec wyboru moda");
}

