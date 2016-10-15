#include <windows.h>
#if defined WIN32 && defined MOUSE_MOVED 
    #undef MOUSE_MOVED 
#endif

#include <curses.h>
#include <cctype>
#include <sstream>
#include "menu.h"

bool beg(std::string& path, std::string& linie);

bool sciezka(std::string& path);
void wybor_moda(std::string& path);
bool load(const std::string& path, std::string& buff);
bool wybor_save(std::string& path);
void save(std::string& linie, std::string& path);
void historia(std::string&);



bool eng = false;

int main(){
	std::string path, linie;
	init();

	
	logline();
	beg(path, linie);
	historia(linie);
	log("main", "po historii");
	save(linie, path);

	//cont();
	log("main", "exiting");
	logline();
	endwin();
	return 0;
}





bool load(const std::string& path, std::string& buff){

	std::ifstream plik(path.c_str()); 
	if(!(plik.good() && plik.is_open())){
		log("load", "otworzenie pliku nie powiodlo sie", path.c_str());
		return false;
	}

	logline();	
	log("load", "wczytywanie");

	loading(eng);
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
		cont(eng);
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
	cont(eng);
}
void historia(std::string& wejscie){

	log("historia", "poczatek historii");

	size_t pomoc, koniec, start, exit;
	std::string hista;
	std::string s;
	cMenu m("historia + flagi\nhistroia bez falg");
	if(m.wybor() == 0)s = "variables=\n";
	else s = "flags=\n";

	border();
	mvprintw(10, 20, "Usuwanie: %s", s.c_str());
	mvprintw(12, 20, "Deleting history and flags");
	refresh();

	pomoc = wejscie.find("REB=\n"); //poczatek karjow
	exit = wejscie.find("active_advisors="); //koniec karjow

	hista = "history=\n    {\n        aristocracy_plutocracy=0\n        centralization_decentralization=0\n        innovative_narrowminded=0\n        mercantilism_freetrade=0\n        offensive_defensive=0\n        land_naval=0\n        quality_quantity=0\n        serfdom_freesubjects=0\n        technology_group=latin\n    }\n    flags=\n    {\n    }\n    ";
	koniec = 0;
	while(1){
		if(koniec == 0)start = wejscie.find("history=\n", pomoc);
		else start = wejscie.find("history=\n", koniec);
		exit = wejscie.find("active_advisors=");
		if(start == -1)break;
		if(start > exit)break;

		koniec = wejscie.find(s, start);
		wejscie.replace(start, koniec - start, hista);
		//log("histroia", "zreplacowano histe");

		koniec = wejscie.find(s, start);
	}
}
bool beg(std::string& path, std::string& linie){
	if(!(sciezka(path))){
		log("main", "sciezka error");
		error(eng);
		return true;
	}

	wybor_moda(path);

	if(!(wybor_save(path))){
		log("main", "wybor save error");
		error(eng);
		return true;
	}

	if(!(load(path, linie))){
		log("main", "load error");
		error(eng);
		return true;
	}

	return false;
}
