/*
 * no time limit patch 4 EU III by konserw
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
#include "menu.h"
#include "header.h"

eVer ver;

bool sciezka(std::string& path){
	logline();
	log("sciezka", "Pocz¹tek szuaknia scie¿ki");

	HKEY hkSoftware, hkParadox, hkEU;
	LONG result;
	char* buf;
	const int rozmiar_bufora = 500;
	DWORD dwBufSize = rozmiar_bufora;
	DWORD typ_klucza = REG_SZ; 
	buf = new char [rozmiar_bufora + 1];
	std::string patch;

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

    result = RegQueryValueExA(hkEU, "path", NULL, &typ_klucza, (LPBYTE)buf, &dwBufSize);
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
	path += '\\';
	delete[] buf;

	log("sciezka", "Sciezka instalacyjna gry", path.c_str());

	if(wersja("HeirToTheThrone", hkEU, patch) == ERROR_SUCCESS){
		log("sciezka", "wersja: heir to the throne");
		ver = h3t;
	}
	else if(wersja("InNomine", hkEU, patch) == ERROR_SUCCESS){
		if(patch != "3.2"){
			log("sciezka", "wersja: IN bez pacza 3.2");
			return false;
		}
		log("sciezka", "wersja: In nomine 3.2");
		ver = in;
	}
	else{
		log("sciezka", "zla wersja");
		return false;
	}


	log("sciezka", "Koniec szukania scie¿ki\n");
	return true;
}

void wybor_moda(std::string& path){
	logline();
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
	if(pliki.size() == 1){
		log("wybor_moda", "vanila");
		jaki_mod = "vanila";
	}
	else{
		std::vector<std::string> vOpis;
		vOpis.push_back("Wybierz wersje gry na ktorej chcesz operowac:");
		
		cMenu menu(vOpis, pliki);

		menu.co(5, 5, jaki_mod);
		log("wybor_moda", "wybrana wersja gry", jaki_mod.c_str());

		path += "mod\\";
		path += jaki_mod;
		path += "\\";

		log("wybor_moda", "sciezka", path.c_str());
	}

	log("wybor_moda", "koniec wyboru moda");
	logline();
}

bool techy(unsigned zadana, std::string& sciezka){
	logline();
	log("techy", "Pocz¹tek");

		
	std::ofstream plik;
	std::vector<std::string> pliki;
	std::string buff;
	std::vector<std::string> linie;
	unsigned licz = 0;
	float tac = 4;
	const std::string path = sciezka + "common\\technologies";

	log("techy", "path", path.c_str());

	pliki.push_back(path + "\\government.txt");
	pliki.push_back(path + "\\land.txt");
	pliki.push_back(path + "\\naval.txt");
	pliki.push_back(path + "\\production.txt");
	pliki.push_back(path + "\\trade.txt");
	
	for(unsigned i = 0; i < pliki.size(); ++i){	
		linie.clear();
		std::ifstream wczyt;
		wczyt.open(pliki[i].c_str());

		if(!(wczyt.good() && wczyt.is_open())){
			log("techy", "nie udalo sie otworzyc pliku", pliki[i].c_str());
			wczyt.close();
			return false;
		}

		while(getline(wczyt, buff)){
			bool flag = false;
			for(std::string::iterator i = buff.begin(); i < buff.end(); ++i){
				if(isspace(*i) == false){
					flag = true;
					break;
				}
			}
			if(flag == true)linie.push_back(buff);
		}
		
		wczyt.close();
		log("techy", "wczytanie do pamieci >starych< linii powiodlo sie");

		std::ofstream bak;
		std::string cos = pliki[i];
		cos += ".bak";
		bak.open(cos.c_str());

		if(!(bak.good() && bak.is_open())){
			log("techy", "nie udalo sie otworzyc pliku do zapisu bakapa");
			bak.close();
			return false;
		}

		for(unsigned j = 0; j < linie.size(); ++j)
			bak << linie[j] << std::endl;
		bak.close();
		log("techy", "backup zapisany poprawnie");

		for(unsigned j = linie.size(); j < zadana; ++j){
			licz++;
			std::stringstream out;
			
			buff.clear();
			buff = "technology = { id = ";
			out << j;
			buff += out.str();
			buff += "\taverage_year = ";
			out.str("\0");
			out << 1890 + (10 * licz);
			buff += out.str();
			out.str("\0");
			if(i != 0) buff += "\t";
			if(i == 1){//land
				if(ver == h3t){//military tactics tylko w h3t
					buff += "military_tactics = ";
					if(licz%10 == 0) tac += 0.5;
					out << tac;
					buff += out.str();
					out.str("\0");
				}

				buff += "supply_limit = ";
				out << 3.25 + (0.05 * licz);
				buff += out.str();
				buff += "\tland_morale = 4.0\t"
					"infantry_fire = 2.75\t"
					"cavalry_fire = 0.6\t"
					"artillery_fire = ";
				out << 8.8 + (0.1 * licz);
				buff += out.str();
				out.str("\0");
				buff += "\tinfantry_shock = 2\t"
					"cavalry_shock = 4.5\t"
					"artillery_shock = 1.2";
			}
			else if(i == 2){//naval
				buff += "range = ";
				out << 850 + (10 * licz);
				buff += out.str();
				out.str("\0");
				buff += "\tnaval_morale = 4.0\t"
					"bigship_fire = 3.0\t"
					"lightship_fire = 3.0\t"
					"galley_fire = 0.5\t"
					"transport_fire = 2.7\t"
					"bigship_shock = 2.9\t"
					"lightship_shock = 2.3\t"
					"galley_shock = 1.7\t"
					"transport_shock = 2.3";
			}
			else if(i == 3){//produkcja
				buff += "production_efficiency = ";
				out << 1.05 + (licz * 0.01);
				buff += out.str();
				out.str("\0");
			}
			else if(i == 4){//trade
				buff += "trade_efficiency = ";
				out << 1.05 + (licz * 0.01);
				buff += out.str();
				out.str("\0");
			}
			buff += "\t}";
			linie.push_back(buff);
		}
		log("techy", "Dodano dodatkowe linie w pamieci");

		plik.open(pliki[i].c_str());
		if(!(plik.good() && plik.is_open())){
			log("techy", "nie udalo sie otworzyc pliku", pliki[i].c_str());
			plik.close();
			return false;
		}
		for(unsigned j=0; j<linie.size(); ++j)
			plik<<linie.at(j)<<std::endl;
		plik.close();
		log("techy", "zakonczono zapis pliku", pliki[i].c_str());
	}
	log("techy", "koniec techów");
	logline();
	return true;
}

bool data(const std::string& sciezka, const std::string& start, const std::string& koniec){
	logline();
	log("data", "Poczatek daty");

	unsigned long long nolines=0;
	std::vector<std::string> linie;
	std::string buff;
	std::ifstream plik;
	std::ofstream zplik;
	std::ofstream bak;
	std::stringstream ss;
	std::string path = sciezka + "common\\defines.txt";
	log("data", "sciezka do zmiany daty", path.c_str());

	plik.open(path.c_str());
	if(!(plik.is_open() && plik.good())){
		log("data", "nie udalo sie otworzyc pliku defines (odczyt)");
		plik.close();
		return false;
	}

	while(getline(plik, buff))	
		linie.push_back(buff);
	
	log("data", "wczytano linii", linie.size());
	plik.close();

	//bakap
	std::string cos = path;
	cos += ".bak";
	bak.open(cos.c_str());
	if(!(bak.good() && bak.is_open())){
		log("techy", "nie udalo sie otworzyc pliku do zapisu bakapa");
		bak.close();
		return false;
	}
	for(unsigned j = 0; j < linie.size(); ++j)
		bak << linie[j] << std::endl;
	bak.close();
	log("techy", "backup zapisany poprawnie");


	linie[0] = "start_date = " + start;
	linie[1] = "end_date = " + koniec;

	zplik.open(path.c_str());
	if(!(zplik.is_open() && zplik.good())){
		log("data", "nie udalo sie otworzyc pliku defines (zapis)");
		zplik.close();
		return false;
	}

	for (unsigned i=0; i<linie.size(); ++i)
		zplik << linie[i] << std::endl;

	log("data", "koniec zmiany daty");
	logline();
	return true;
}
