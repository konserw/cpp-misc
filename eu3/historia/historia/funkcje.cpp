/*
 * historia - program do grzebania w plikach historii EU3
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

void find_files(std::vector<std::string>& pliki){
	char path[255];
	WIN32_FIND_DATAA wfd; 
	size_t pos;

	GetModuleFileNameA(NULL, path, sizeof(path)); 
	log("find_files", "c_str path", path);
	std::string spath = static_cast<std::string>(path);
    pos = spath.find_last_of("\\"); 
	spath = spath.substr(0, pos);
    pos = spath.find_last_of("\\");
	spath = spath.substr(0, pos);
	spath += "\\provinces\\*";
	log("find_files", "sciezka (spath)", spath.c_str());

	HANDLE uchwyt = FindFirstFileA(spath.c_str(), &wfd); 
    if (uchwyt != INVALID_HANDLE_VALUE) 
    { 
		std::string buff;
		do{
			buff = static_cast<std::string>(wfd.cFileName);
			if(buff.find(".txt") != std::string::npos || buff.find(".TXT") != std::string::npos){
				log("find_files", "Znaleziono plik .txt", buff.c_str());
				std::string wynik;
				wynik = spath;
				wynik.erase(wynik.size()-1);
				wynik += buff;
				pliki.push_back(wynik); 
			}
			else log("find_files", "Znaleziono inny plik", buff.c_str());
		}while (FindNextFileA(uchwyt, &wfd)); 
        FindClose(uchwyt); 
    } 
	log("find_files", "Koniec dzia³ania funkcji");
}

cProv::cProv(std::string& path){
	sPath = path;
	std::ifstream plik(sPath.c_str());
	if(plik.is_open() && plik.good())
		log("konstr. prov", "Poprawnie otworzono plik", sPath.substr(sPath.find_last_of('\\')+1, std::string::npos).c_str());
	else log("konstr. prov", "Niepoprawne otwarcie pliku", sPath.substr(sPath.find_last_of('\\')+1, std::string::npos).c_str());
	std::string buff;
	while(getline(plik, buff)) linie.push_back(buff);
	plik.close();
}

void cProv::zmien(std::string& co, bool dodaj, float ile){
	float val;

	std::ofstream plik(sPath.c_str());
	if(plik.is_open() && plik.good())
		log("prov::zmien", "Poprawnie otworzono plik", sPath.substr(sPath.find_last_of('\\')+1, std::string::npos).c_str());
	else log("prov::zmien", "Niepoprawne otwarcie pliku", sPath.substr(sPath.find_last_of('\\')+1, std::string::npos).c_str());

	bool flag = false;
	for(unsigned i=0; i < linie.size(); ++i){
		if(linie[i].find(co) != std::string::npos && flag == false){
			log("prov::zmien", "znaleziono szukan¹ liniê", i);
			std::istringstream iss(linie[i]); 
			std::ostringstream oss; 

			iss.ignore(256, '='); 
			//float ile; 
			iss >> val;
			log("prov::zmien", "Wartosc pierwotna", val);
			if(dodaj == true) val += ile;
			else val *= ile; 
			log("prov::zmien", "Wartoœæ ostateczna", val);

			oss << co << " = " << val ;
			linie[i] = oss.str();
			flag = true;			
		}
		plik << linie[i] << std::endl;
	}

	
	
}
/*
wybory:
0	all,
1	tag,
2	cul,
3	hre
*/
void ktore_pliki(unsigned short filtr, std::vector<std::string>& pliki, std::vector<std::string>& nowe_pliki){

	loading();
	std::string wybor;
	nowe_pliki.clear();

	switch(filtr){
		case 0:
			log("ktore_pliki", "Wybrano brak filtru(all)");	
			nowe_pliki = pliki;
			return;
		case 1:{
			log("ktore_pliki", "Wybrano filtr TAG");
			clear();
			border('|', '|', '-', '-', '+', '+', '+', '+');
			mvprintw(10, 10, "Podaj tag kraju wielkimi literami:\t");
			echo();
			refresh();
			char cBuf[5];
			getnstr(cBuf, 3);
			noecho();
			wybor = cBuf;
			log("ktore_pliki", "Wybrny tag", cBuf);
			break;}
		case 2:{
			log("ktore_pliki", "Wybrano filtr kultura");
			clear();
			border('|', '|', '-', '-', '+', '+', '+', '+');
			mvprintw(10, 10, "Podaj kulture malymi literami:\t");
			echo();
			refresh();
			char* cBuf = new char[256];
			getnstr(cBuf, 254);
			noecho();
			wybor = cBuf;
			log("ktore_pliki", "Wybrna kultura", cBuf);
			delete[] cBuf;
			break;}
	}
	for(unsigned long i=0; i < pliki.size(); ++i){
		std::string buff;
		std::ifstream plik(pliki[i].c_str());
		if(plik.is_open() && plik.good())
			log("ktore_pliki", "Poprawnie otworzono plik", pliki[i].substr(pliki[i].find_last_of('\\')+1, std::string::npos).c_str());
		else{
			log("ktore_pliki", "Otwarcie pliku nie powiodlo sie", pliki[i].substr(pliki[i].find_last_of('\\')+1, std::string::npos).c_str());
			continue;
		}
		bool ex = false;
		while(getline(plik, buff)){
			switch(filtr){
				case 1: //tag
					if(buff.find("owner = ") != std::string::npos && buff.find("{") == std::string::npos){
						log("ktore_pliki", "Znaleziono linie kryterium");
						if(wybor == buff.substr(buff.find('=')+2, std::string::npos)){
							nowe_pliki.push_back(pliki[i]);
							log("ktore_pliki", "Plik pasuje do kryteriow!");
						}
						ex = true;
					}
					break;
				case 2://cult
					if(buff.find("culture = ") != std::string::npos && buff.find("{") == std::string::npos){
						log("ktore_pliki", "Znaleziono linie kryterium");
						if(wybor == buff.substr(buff.find('=')+2, std::string::npos)){
							nowe_pliki.push_back(pliki[i]);
							log("ktore_pliki", "Plik pasuje do kryteriow!");
						}
						ex = true;
					}
					break;
				case 3:
					if(buff.find("hre = ") != std::string::npos && buff.find("{") == std::string::npos){
						log("ktore_pliki", "Znaleziono linie kryterium");
						if("yes" == buff.substr(buff.find('=')+2, std::string::npos)){
							nowe_pliki.push_back(pliki[i]);
							log("ktore_pliki", "Plik pasuje do kryteriow!");
						}
						ex = true;
					}
					break;
			}
			if(ex == true)break;
		}
	}
}