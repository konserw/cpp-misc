/*
 * Edytor save dla EU3 by konserw
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
#include "header.h"
#include "menu.h"



bool load(const std::string& path, std::string& buff){

	std::ifstream plik(path.c_str()); 
	if(!(plik.good() && plik.is_open())){
		log("load", "otworzenie pliku nie powiodlo sie", path.c_str());
		return false;
	}

	logline();	
	log("load", "wczytywanie");

	loading(stdscr, eng);
	getline(plik, buff, '\0');
	log("load", "Wczytano znakow", buff.size());
	plik.close();

	log("load", "Koniec loadu\n");
	return true;
}

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
		if(eng)
			vOpis = "Choose game version from which savegame will be loaded:";
		else
			vOpis = "Wybierz wersje gry z ktorej jest save:";
		
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

bool wybor_save(std::string& path){

	logline();
	log("wybor_save", "Poczatek wybierania save");

    WIN32_FIND_DATAA wfd; 
	std::vector<std::string> pliki;
	path += "save games\\";

	std::string buff = path;
	buff += "*";
	log("wybor_save", "sciezka", buff.c_str());

	HANDLE uchwyt = FindFirstFileA(buff.c_str(), &wfd); 
    if (uchwyt != INVALID_HANDLE_VALUE) 
    { 
		do{
			buff = static_cast<std::string>(wfd.cFileName);
			if(buff.find(".eu3") != std::string::npos || buff.find(".EU3") != std::string::npos){
				pliki.push_back(buff);
				log("wybor_save", "znaleziono plik .eu3", buff.c_str());
			}
		}while (FindNextFileA(uchwyt, &wfd)); 
        FindClose(uchwyt); 
    }
	log("wybor_save", "znalezionych save'ów", pliki.size());
	if(pliki.size() == 0) return false;
	else{
		std::string vOpis;
		if(eng)
			vOpis = "Choose savegame which will be edited:";
		else 
			vOpis = "Wybierz save do edycji:";
		
		cMenu menu(vOpis, pliki);
		menu.co(5, 5, buff);
		log("wybor_save", "wybrany save", buff.c_str());

		path += buff;
		log("wybor_save", "sciezka", path.c_str());
	}

	log("wybor_save", "Koniec wybierania save");
	return true;
}

void save(std::string& linie, std::string& path){

	logline();
	log("save", "Poczatek zapisywania");
	std::string opis;
	std::vector<std::string> opcje;
	if(eng){
		opis = "Overwrite savegame file?";
		opcje.push_back("Yes, overwrite");
		opcje.push_back("Save as game.eu3");
		opcje.push_back("Don't save");
	}else{
		opis = "Nadpisac plik save?";
		opcje.push_back("Nadpisz stary plik");
		opcje.push_back("Zapisz pod nazwa game.eu3");
		opcje.push_back("Nie zapisuj");
	}
	cMenu nad(opis, opcje);
	short wybor = nad.wybor(10, 20);

	if(wybor == 1){
		path = path.substr(0, path.find_last_of('\\'));
		path += "\\game.eu3";
	}		
	if(wybor == 2) return;

	std::ofstream plik(path.c_str());
	if(!(plik.is_open() && plik.good())){
		log("save", "nie udalo sie otworzyc pliku");
		border();
		mvprintw(10, 10, "Nie udalo sie otworzyc pliku do zapisu");
		mvprintw(10, 10, "Unable to save");
		cont(stdscr, eng);
		return;
	}
	border();
	mvprintw(12, 25, "zapisywanie, prosze czekac...");
	refresh();
	plik << linie <<std::endl;
	plik.close();
	log("save", "koniec zapisywania");
	border();
	mvprintw(10, 26, "Pomyslnie zapisano!");
	mvprintw(12, 26, "Saving succesfull!");
	cont(stdscr, eng);
}
void historia(std::string& wejscie){

	log("historia", "poczatek historii");

	size_t pomoc, koniec, start, exit;
	std::string hista;

	border();
	mvprintw(10, 20, "Usuwanie historii i flag krajow...");
	mvprintw(12, 20, "Deleting history and flags");
	refresh();

	pomoc = wejscie.find("REB=\n"); //poczatek karjow
	exit = wejscie.find("active_advisors"); //koniec karjow

	hista = "history=\n    {\n        aristocracy_plutocracy=0\n        centralization_decentralization=0\n        innovative_narrowminded=0\n        mercantilism_freetrade=0\n        offensive_defensive=0\n        land_naval=0\n        quality_quantity=0\n        serfdom_freesubjects=0\n        technology_group=latin\n    }\n    flags=\n    {\n    }\n    ";
	koniec = 0;
	while(1){
		if(koniec == 0)start = wejscie.find("history=\n", pomoc);
		else start = wejscie.find("history=\n", koniec);
		if(start == -1)break;
		if(start > exit)break;

		koniec = wejscie.find("variables=\n", start);
		wejscie.replace(start, koniec - start, hista);
		//log("histroia", "zreplacowano histe");

		koniec = wejscie.find("variables=\n", start);
	}
}
void flag(std::string& wejscie){

	log("flag", "poczatek flag");
	size_t pomoc, start, koniec;
	std::string hista;

	border();
	mvprintw(10, 30, "Usuwanie flag prowow...");
	mvprintw(12, 30, "Deleting province flags...");
	refresh();

	pomoc = wejscie.find("REB=\n"); //poczatek karjow

	hista = "flags=\n    {\n    }\n";
	koniec = wejscie.find("gameplaysettings=");
	while(1){
		start = wejscie.find("flags=\n", koniec);
		koniec = wejscie.find("variables=\n", start);

		if(start == -1)break;//raczej nie powienno sie zdarezyc
		if(start >= pomoc)break; // nie wlazic w panstwa

		wejscie.replace(start, koniec - start, hista);
		//log("flag", "zreplacowano flagi");

		koniec = wejscie.find("variables=\n", start);
	}
}

void latin(std::string& wejscie){

	log("latin", "poczatek");
	size_t pomoc, start, koniec;
	std::string hista;

	border();
	mvprintw(10, 20, "Zamiana tech grupy latin na western...");
	mvprintw(12, 20, "Changing latin techgrup to western...");
	refresh();

	pomoc = wejscie.find("REB=\n"); //poczatek karjow
    
    
	hista = "technology_group=western";

	while(1){
		start = wejscie.find("technology_group=latin\n");
		koniec = wejscie.find("\n", start);

		if(start == -1)break;

		wejscie.replace(start, koniec - start, hista);
	}

	border();
	mvprintw(10, 20, "zamiana unit_type latin na western...");
	refresh();

	hista = "unit_type=western";
	while(1){
		start = wejscie.find("unit_type=latin\n");
		koniec = wejscie.find("\n", start);

		if(start == -1)break;

		wejscie.replace(start, koniec - start, hista);
	}
}


void mag(std::string& wejscie){

	log("magistrates", "poczatek");
	size_t pomoc;
	std::string text;

	border();
	mvprintw(10, 20, "Dodawanie magistratow...");
	mvprintw(12, 20, "Adding magistrates...");
	refresh();

	text = "officials=5.000\n    ";
	pomoc = 0;
	while(1){
		pomoc = wejscie.find("last_policy_change", pomoc);
		if(pomoc == -1)break;
		wejscie.insert(pomoc, text);	
		pomoc += text.size()+5;
	}


	border();
	mvprintw(10, 20, "Dodawanie tradycji kulturalnej...");
	mvprintw(12, 20, "Ading cultural tradition...");
	refresh();

	text = "cultural_tradition=0.200\n    ";
	pomoc = 0;
	while(1){
		pomoc = wejscie.find("distribution=", pomoc);
		if(pomoc == -1)break;
		wejscie.insert(pomoc, text);	
		pomoc += text.size()+5;
	}
}

void sz_id(const std::string& wej){
	size_t start, koniec;
	std::string buff;
	std::stringstream ss;
	int i, t;
	std::vector<int> vec;
	std::vector<int>::iterator it;
	bool flag;
	std::ofstream out;
	out.open("id.txt");

	border();
	mvprintw(10, 20, "Szukanie powtarzajacych sie id...");
	mvprintw(12, 20, "Searching for multiole ids...");
	refresh();

	koniec = 0;
	while(1){
		start = wej.find("id=\n", koniec);
		if(start == -1)	break;
		koniec = wej.find("}", start);
		
		start = wej.find("id=", ++start);
		buff = wej.substr(start+3, wej.find("\n", start) - start);
		ss.str(buff);
		ss >> i;
		flag = false;
		for(it = vec.begin(); it < vec.end(); ++it){
			if(*it == i){
				flag = true;
				start = wej.find("type=", start);
				buff = wej.substr(start+5, wej.find("\n", start) - start);
				ss.str(buff);
				ss >> t;
				id nowe(i, t);
				out << nowe.print() << std::endl;
				break;
			}
		}
		if(flag == false)vec.push_back(i);
	}
}

void nawiasy(std::string& wej){
	log("nawiasy", "poczatek nawiasow h3t -> in");
	std::string::iterator it, end;
	bool flag=false;
	std::string wyj;

	border();
	if(eng)
		mvprintw(10, 30, "Editing sevegame");		
	else
		mvprintw(10, 30, "Edytowanie sejwa");
	refresh();

	it = wej.begin();
	end = wej.end();
	wyj.clear();

	for(it; it < end; ++it){
		if(flag){
			if(isspace(*it))continue;
			else flag = false;
		}
		if(*it == '=')
			flag = true;
		wyj += *it;
	}
	wej = wyj;
	log("nawiasy", "koniec nawiasow");
}
bool beg(std::string& path, std::string& linie){
	if(!(sciezka(path))){
		log("main", "sciezka error");
		error(stdscr, eng);
		return true;
	}

	wybor_moda(path);

	if(!(wybor_save(path))){
		log("main", "wybor save error");
		error(stdscr, eng);
		return true;
	}

	if(!(load(path, linie))){
		log("main", "load error");
		error(stdscr, eng);
		return true;
	}

	return false;
}

void rev_nawiasy(std::string& wej){
	log("rev_nawiasy", "poczatek nawiasow in -> h3t");
	std::string::iterator it, end;
	std::string wyj;

	border();
	if(eng)
		mvprintw(10, 30, "Editing sevegame");		
	else
		mvprintw(10, 30, "Edytowanie sejwa");
	refresh();

	it = wej.begin();
	end = wej.end();
	wyj.clear();

	for(it; it < end; ++it){
		if(*it == '='){
			wyj += *it;
			it++;
			if(*it == '{'){
				wyj += "\n    ";
			}
		}
		wyj += *it;
	}
	wej = wyj;
	log("nawiasy", "koniec nawiasow");
}

void 