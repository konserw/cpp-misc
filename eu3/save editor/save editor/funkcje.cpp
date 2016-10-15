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
//#include "header.h"
//#include "menu.h"

bool load(const std::string& path, std::string& buff, size_t& indeks){

	std::ifstream plik(path.c_str()); 
	if(!(plik.good() && plik.is_open())){
		log("load", "otworzenie pliku nie powiodlo sie", path.c_str());
		return false;
	}

	logline();	
	log("load", "wczytywanie");

	loading();
	getline(plik, buff, '\0');
	log("load", "Wczytano znakow", buff.size());
	plik.close();

	indeks = buff.find("human=yes");
	indeks -= 10;
	log("load", "hum indeks", indeks);

	border();
	mvprintw(2, 10, "Plik wczytany prawidlowo!");
	mvprintw(4, 10, "Wczytano %lu znakow", buff.size());
	cont();
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
		std::vector<std::string> vOpis;
		vOpis.push_back("Witam w Edytorze Save EU3");
		vOpis.push_back("Wybierz wersje gry z ktorej sejwa chcesz zaladowac:");
		
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
		std::vector<std::string> vOpis;
		vOpis.push_back("Wybierz save do edycji:");
		
		cMenu menu(vOpis, pliki);
		menu.co(5, 5, buff);
		log("wybor_save", "wybrany save", buff.c_str());

		path += buff;
		log("wybor_save", "sciezka", path.c_str());
	}

	log("wybor_save", "Koniec wybierania save");
	return true;
}


void ustawienia(std::string& linie, WINDOW* wDol, std::string& sReserved, size_t& tReserved){

	logline();
	log("ustawienia", "Poczatek ustawien");

	size_t pomoc, poczatek_gameplayoptions;
	std::string sBuff;
	unsigned short y, x;
	//unsigned long long licz=0;
	short buff[14];
	const unsigned short min_wybor = 0;
	unsigned short max_wybor = 13;
	unsigned ktory = 0;
	char znak;

	pomoc = linie.find("setgameplayoptions={");
	poczatek_gameplayoptions = linie.find('\n', pomoc)+1;
	sBuff = linie.substr(poczatek_gameplayoptions, 28);
	log("ustawienia", "wczytano gameplayoptions, aktualna wartoœæ", sBuff.c_str());
	std::stringstream strin(sBuff);

	for(short i=0; i < 14; ++i){
		strin >> buff[i];
		log("ustawienia", "wartosc", buff[i]);
	}
	
	for(;;){
		//log("ustawienia", "kolejna petla");
		y=3; x=43;			

		border(wDol);
		mvwprintw(wDol,  21, 55, "Ruch: strzalki gora/dol");
		mvwprintw(wDol,  22, 55, "Zmiana wartosci: <= =>");
		mvwprintw(wDol,  23, 55, "Wyjscie: ESC");

		mvwprintw(wDol,  y++, 30, "Ustawienia rozgrywki:");
		mvwprintw(wDol,  ++y, 10, "Wladcy:\t");
		wrefresh(wDol);
		wmove(wDol, y, x);
		switch(buff[0]){
			case 0:
				wprintw(wDol, "normalnie");
				break;
			case 1:
				wprintw(wDol, "historycznie");
				break;
			case 2:
				wprintw(wDol, "losowo");
				break;
		}
		mvwprintw(wDol,  ++y, 10, "Doradcy:\t");
		wmove(wDol, y, x);
		switch(buff[1]){
			case 0:
				wprintw(wDol, "normalnie");
				break;
			case 1:
				wprintw(wDol, "historycznie");
				break;
			case 2:
				wprintw(wDol, "losowo");
				break;
		}
		mvwprintw(wDol,  ++y, 10, "Dowodcy:\t");
		wmove(wDol, y, x);
		switch(buff[2]){
		case 0:
				wprintw(wDol, "normalnie");
				break;
			case 1:
				wprintw(wDol, "historycznie");
				break;
			case 2:
				wprintw(wDol, "losowo");
				break;
		}
		mvwprintw(wDol,  ++y, 10, "Kolonisci:\t");
		wmove(wDol, y, x);
		switch(buff[3]){
			case 0:
				wprintw(wDol, "normalnie");
				break;
			case 1:
				wprintw(wDol, "za darmo");
				break;
		}
		mvwprintw(wDol,  ++y, 10, "Kupcy:\t");
		wmove(wDol, y, x);
		switch(buff[4]){
			case 0:
				wprintw(wDol, "normalnie");
				break;
			case 1:
				wprintw(wDol, "za darmo");
				break;
		}
		mvwprintw(wDol,  ++y, 10, "Misjonarze:\t");
		wmove(wDol, y, x);
		switch(buff[5]){
			case 0:
				wprintw(wDol, "normalnie");
				break;
			case 1:
				wprintw(wDol, "za darmo");
				break;
		}
		mvwprintw(wDol,  ++y, 10, "Inflacja:\t");
		wmove(wDol, y, x);
		switch(buff[6]){
			case 0:
				wprintw(wDol, "normalnie");
				break;
			case 1:
				wprintw(wDol, "brak");
				break;
			case 2:
				wprintw(wDol, "ze zlota");
		}
		mvwprintw(wDol,  ++y, 10, "Wielkosc kolonistow:\t");
		wmove(wDol, y, x);
		switch(buff[7]){
			case 0:
				wprintw(wDol, "normalnie (100)");
				break;
			case 1:
				wprintw(wDol, "200");
				break;
			case 2:
				wprintw(wDol, "300");
				break;
			case 3:
				wprintw(wDol, "400");
				break;
		}
		mvwprintw(wDol,  ++y, 10, "Poziom trudnosci:\t");
		wmove(wDol, y, x);
		switch(buff[8]){
			case 0:
				wprintw(wDol, "bardzo latwy");
				break;
			case 1:
				wprintw(wDol, "latwy");
				break;
			case 2:
				wprintw(wDol, "normalny");
				break;
			case 3:
				wprintw(wDol, "trudny");
				break;
			case 4:
				wprintw(wDol, "bardzo trudny");
				break;
		}
		mvwprintw(wDol,  ++y, 10, "Agresywnosc AI:\t");
		wmove(wDol, y, x);
		switch(buff[9]){
			case 0:
				wprintw(wDol, "mala");
				break;
			case 1:
				wprintw(wDol, "normalna");
				break;
			case 2:
				wprintw(wDol, "wysoka");
				break;
		}
		mvwprintw(wDol,  ++y, 10, "Wiedza o odkryciach ladowych:\t");
		wmove(wDol, y, x);
		switch(buff[10]){
			case 0:
				wprintw(wDol, "25");
				break;
			case 1:
				wprintw(wDol, "50");
				break;
			case 2:
				wprintw(wDol, "75");
				break;
			case 3:
				wprintw(wDol, "100");
				break;
			case 4:
				wprintw(wDol, "200");
				break;
		}
		wprintw(wDol, " lat");
		mvwprintw(wDol,  ++y, 10, "Wiedza o odkryciach morskich:\t");
		wmove(wDol, y, x);
		switch(buff[11]){
			case 0:
				wprintw(wDol, "25");
				break;
			case 1:
				wprintw(wDol, "50");
				break;
			case 2:
				wprintw(wDol, "75");
				break;
			case 3:
				wprintw(wDol, "100");
				break;
			case 4:
				wprintw(wDol, "200");
				break;
		}
		wprintw(wDol, " lat");
		mvwprintw(wDol,  ++y, 10, "Szpiedzy:\t");
		wmove(wDol, y, x);
		switch(buff[12]){
			case 0:
				wprintw(wDol, "normalnie");
				break;
			case 1:
				wprintw(wDol, "za darmo");
				break;
		}
		mvwprintw(wDol,  ++y, 10, "Kraje szczesciarze:\t");
		wmove(wDol, y, x);
		switch(buff[13]){
			case 0:
				wprintw(wDol, "historycznie");
				break;
			case 1:
				wprintw(wDol, "losowo");
				break;
			case 2:
				wprintw(wDol, "brak");
				break;
		}

		wattron(wDol, COLOR_PAIR(2));
		wmove(wDol, 5+ktory, 43);
		if(ktory == 13)
			switch(buff[13]){
				case 0:
					wprintw(wDol, "historycznie");
					break;
				case 1:
					wprintw(wDol, "losowo");
					break;
				case 2:
					wprintw(wDol, "brak");
					break;
			}
		else if(ktory == 0 || ktory == 1 || ktory == 2)
			switch(buff[ktory]){
				case 0:
					wprintw(wDol, "normalnie");
					break;
				case 1:
					wprintw(wDol, "historycznie");
					break;
				case 2:
					wprintw(wDol, "losowo");
					break;
			}
		else if(ktory == 3 || ktory == 4 || ktory == 5 || ktory == 12)
			switch(buff[ktory]){
				case 0:
					wprintw(wDol, "normalnie");
					break;
				case 1:
					wprintw(wDol, "za darmo");
					break;
			}
		else if(ktory == 6)
			switch(buff[ktory]){
				case 0:
					wprintw(wDol, "normalnie");
					break;
				case 1:
					wprintw(wDol, "brak");
					break;
				case 2:
					wprintw(wDol, "ze zlota");
			}
		else if(ktory == 11 || ktory == 10)
			switch(buff[ktory]){
				case 0:
					wprintw(wDol, "25");
					break;
				case 1:
					wprintw(wDol, "50");
					break;
				case 2:
					wprintw(wDol, "75");
					break;
				case 3:
					wprintw(wDol, "100");
					break;
				case 4:
					wprintw(wDol, "200");
					break;
			}
		else if(ktory == 9)
			switch(buff[9]){
				case 0:
					wprintw(wDol, "mala");
					break;
				case 1:
					wprintw(wDol, "normalna");
					break;
				case 2:
					wprintw(wDol, "wysoka");
					break;
			}
		else if(ktory == 8)
			switch(buff[8]){
				case 0:
					wprintw(wDol, "bardzo latwy");
					break;
				case 1:
					wprintw(wDol, "latwy");
					break;
				case 2:
					wprintw(wDol, "normalny");
					break;
				case 3:
					wprintw(wDol, "trudny");
					break;
				case 4:
					wprintw(wDol, "bardzo trudny");
					break;
			}
		else if(ktory == 6)
			switch(buff[6]){
				case 0:
					wprintw(wDol, "normalnie");
					break;
				case 1:
					wprintw(wDol, "brak");
					break;
				case 2:
					wprintw(wDol, "ze zlota");
			}
		else if(ktory == 7)
			switch(buff[7]){
				case 0:
					wprintw(wDol, "normalnie (100)");
					break;
				case 1:
					wprintw(wDol, "200");
					break;
				case 2:
					wprintw(wDol, "300");
					break;
				case 3:
					wprintw(wDol, "400");
					break;
			}
		wattroff(wDol, COLOR_PAIR(2));
		wrefresh(wDol); 
		unsigned short max;

		if(ktory == 0 || ktory == 1 || ktory == 2 || ktory == 6 || ktory == 9 || ktory == 13) max = 3;
		else if(ktory == 3 || ktory == 4 || ktory == 5 || ktory == 12) max = 2;
		else if(ktory == 7) max = 4;
		else max = 5;
		max--;

		znak = getch();
		if (znak == 3){
			if(ktory != min_wybor) ktory--;
			else if(ktory == min_wybor) ktory = max_wybor;
		}
		else if(znak == 2){
			if(ktory != max_wybor) ktory++;
			else if(ktory == max_wybor) ktory = min_wybor;
		}
		else if(znak == 5){
			if(buff[ktory] < max) buff[ktory]++;
			else buff[ktory] = 0;
		}
		else if(znak == 4)
			if(buff[ktory] != 0) buff[ktory]--;
			else buff[ktory] = max;
		else if(znak == 27){
			log("ustawienia", "ESC -> break");
			break;
		}
	}
	for(short i=0; i < 14; i++){
		strin << buff[i] << " ";
		log("ustawienia", "akt. wartoœæ", buff[i]);
	}
//	strin << "}" << std::endl;
	sBuff = strin.str();

	log("ustawienia", "ostatecznie ustawienia(string)", sBuff.c_str());
	linie.replace(poczatek_gameplayoptions, sBuff.size(), sBuff);
	log("ustawienia", "koniec gampleaysettings, zreplacowano");
	log("ustawienia", "koniec ustawien");
	logline();
}

void save(std::string& linie, WINDOW* wDol, std::string& path, size_t& tReserved){

	logline();
	log("save", "Poczatek zapisywania");

	std::vector<std::string> opis;
	opis.push_back("Nadpisac plik save?");
	std::vector<std::string> opcje;
	opcje.push_back("Nadpisz stary plik");
	opcje.push_back("Zapisz pod nazwa editor.eu3");
	opcje.push_back("Nie zapisuj");
	cMenu nad(wDol, opis, opcje);
	short wybor = nad.wybor(10, 20);

	if(wybor == 1){
		path = path.substr(0, path.find_last_of('\\'));
		path += "\\editor.eu3";
	}		
	if(wybor == 2) return;

	std::ofstream plik(path.c_str());
	if(!(plik.is_open() && plik.good())){
		log("save", "nie udalo sie otworzyc pliku");
		border(wDol);
		mvwprintw(wDol, 10, 10, "Nie udalo sie otworzyc pliku do zapisu");
		cont();
		return;
	}
	border(wDol);
	mvwprintw(wDol, 12, 25, "zapisywanie, prosze czekac...");
	wrefresh(wDol);
	plik << linie << /*std::endl <<*/ '\0';
	plik.close();
	log("save", "koniec zapisywania");
	border(wDol);
	mvwprintw(wDol, 10, 26, "Pomyslnie zapisano!");
	cont(wDol);
}

void flagi(std::string& linie, WINDOW* wDol, std::string& sReserved, size_t& indeks){

	logline();
	log("flagi", "Pocz¹tek flag");

	size_t pomoc, koniec, ile, wpoczatek, poczatek, wile;
	std::string sIn, buff;
	const unsigned short min_wybor = 0;
	unsigned short max_wybor, ktory = 0;
	char znak;
	short y, x;
	std::stringstream oss;
	std::vector<std::string> var, flagi;

	pomoc = linie.find("flags={", indeks);
	pomoc = linie.find('\n', pomoc) +1;
	koniec = linie.find('}', pomoc);
	ile = koniec - pomoc;
	poczatek = pomoc;
	sIn = linie.substr(pomoc, ile);
	log("flagi", "aktualne flagi\n", sIn.c_str());

	flagi.push_back("[dodaj flage]");
	explode(sIn, "\n", flagi);
	for(int i=flagi.size()-1; i >=0 ; --i){
		while(flagi[i].find(' ') != -1)
			flagi[i].erase(flagi[i].find(' '), 1);
		if(flagi[i].empty() == true && i == flagi.size() - 1)flagi.pop_back();
	}


	pomoc = linie.find("variables={", koniec);
	wpoczatek = linie.find('\n', pomoc) +1;
	pomoc = linie.find('}', wpoczatek);
	wile = pomoc - wpoczatek;
	sIn.clear();
	sIn = linie.substr(wpoczatek, wile);
	log("flagi", "aktualne variables\n", sIn.c_str());

	var.push_back("[dodaj zmienna]");
	explode(sIn, "\n", var);

	for(int i=var.size()-1; i >=0 ; --i){
		while(var[i].find(' ') != -1)
			var[i].erase(var[i].find(' '), 1);
		if(var[i].empty() == true && i == var.size() - 1)var.pop_back();
	}

	const short cy = 5;

	for(;;){
		max_wybor = flagi.size() + var.size() -1;
		y=3, x=4;

		border(wDol);
		mvwprintw(wDol, y++, x+20, "Flagi twojego panstwa:");
		for(unsigned i=0; i<flagi.size(); ++i) 
			mvwprintw(wDol, ++y, x, "%s", flagi[i].c_str());

		y++;
		mvwprintw(wDol, y++, x+20, "Zmienne twojego panstwa:");
		for(unsigned i=0; i<var.size(); ++i)
			mvwprintw(wDol, ++y, x, "%s", var[i].c_str());

		wattron(wDol, COLOR_PAIR(2));
		std::string s;
		if(ktory < flagi.size()){
			s = flagi[ktory];
			mvwprintw(wDol, ktory + cy, x, "%s", s.c_str());
		}
		else{
			s = var[ktory-flagi.size()];
			mvwprintw(wDol, cy + 2 + ktory, x, "%s", s.c_str());
		}
		wattroff(wDol, COLOR_PAIR(2));

		mvwprintw(wDol, 20, 55, "Ruch: strzalki gora/dol");
		mvwprintw(wDol, 21, 55, "Nowa flaga/edycja: enter");
		mvwprintw(wDol, 22, 55, "Usuniecie flagi: del");
		mvwprintw(wDol, 23, 55, "Wyjscie: ESC");
		wrefresh(wDol);

		noecho();
		znak = getch();
		if (znak == 3){
			if(ktory != min_wybor) ktory--;
			else if(ktory == min_wybor) ktory = max_wybor;
		}
		else if(znak == 2){
			if(ktory != max_wybor) ktory++;
			else if(ktory == max_wybor) ktory = min_wybor;
		}
		/*Enter na fladze*/
		else if(znak == 13 && ktory < flagi.size()){
			if(ktory == 0){//dodanie falgi
				log("flag", "Dodaje flage");
				std::string flag;
				WINDOW* win;
				char* ch = new char[256];

				border(wDol);
				win = newwin(5, 40, 15, 20);
				border(win);

				echo();
				wattron(win, A_BOLD);
				mvwgetstr(win, 2, 2, ch);
				noecho();

				flag = ch;
				flagi.push_back(flag);
				log("flag", "Dodano flage", flag.c_str());

				delete[] ch;
				delwin(win);
			} 
			else{//edycja flagi
				std::string flag = flagi[ktory];
				log("flag", "Edytuje flage", flag.c_str());
				border(wDol);
				WINDOW* win;
				win = newwin(5, 40, 15, 20);
				wattron(win, A_BOLD);
				for(;;){
					border(win);
					mvwprintw(win, 2, 2, "%s", flag.c_str());
					wrefresh(win);
					znak = getch();
					if(znak == 13)break;
					else if(znak == 27){
						flag = flagi[ktory];
						break;
					}
					else if((znak >= 'a' && znak <= 'z') || (znak >= 'A' && znak <= 'Z')) flag += znak;
					else if(znak == 8 && flag.size() != 0)flag.erase(flag.size()-1);
				}
				delwin(win);
				flagi[ktory] = flag;
				log("flag", "Wyedytowana flaga", flag.c_str());
			}
		}
		else if(znak == 74){//del
			if(ktory != 0){
				log("flag", "Usunieto flage", flagi[ktory].c_str());
				flagi.erase(flagi.begin() + ktory);
				ktory--;
			}
		}
		else if(znak == 27)break;
		/*enter jak var*/
		else if(znak == 13){
			if(0 == ktory - flagi.size()){//dodanie var
				log("flag", "Dodaje var");
				std::string flag;
				WINDOW* win;
				char* ch = new char[256];

				border(wDol);
				win = newwin(5, 40, 15, 20);
				border(win);

				echo();
				wattron(win, A_BOLD);
				mvwgetstr(win, 2, 2, ch);
				noecho();

				flag = ch;
				var.push_back(flag);
				log("flag", "Dodano var", flag.c_str());

				delete[] ch;
				delwin(win);
			} 
			else{//edycja flagi
				std::string flag = var[ktory - flagi.size()];
				log("flag", "Edytuje var", flag.c_str());
				border(wDol);
				WINDOW* win;
				win = newwin(5, 40, 15, 20);
				wattron(win, A_BOLD);
				for(;;){
					border(win);
					mvwprintw(win, 2, 2, "%s", flag.c_str());
					wrefresh(win);
					znak = getch();
					if(znak == 13)break;
					else if(znak == 27){
						flag = var[ktory];
						break;
					}
					else if(
						(znak >= 'a' && znak <= 'z')//male litery
						|| (znak >= 'A' && znak <= 'Z')//wielkie litety
						//|| znak == ' ' || znak == '='// rozne takie
						//|| (znak >= '0' && znak <= '9')//cyfry
						) flag += znak;
					else if(znak == 8 && flag.size() != 0)flag.erase(flag.size()-1);
				}
				delwin(win);
				var[ktory - flagi.size()] = flag;
				log("flag", "Wyedytowana flaga", flag.c_str());
			}
		}
		else if(znak == 74){//del
			if(ktory != 0){
				log("flag", "Usunieto var", var[ktory - flagi.size()].c_str());
				var.erase(var.begin() + ktory - flagi.size());
				ktory--;
			}
		}
		else if(znak == 27)break;
	}

	for(unsigned i=1; i < flagi.size(); ++i)//bo zerowe jest dod. flage
		oss <<"        " << flagi[i] << "\n";
	sIn = oss.str();
	log("flagi", "Flagi koncowe\n", sIn.c_str());
	linie.replace(poczatek, ile, sIn);

	oss.clear();

	for(unsigned i=1; i < var.size(); ++i)//bo zerowe jest dod. var
		oss <<"        " << var[i] << "\n";
	sIn = oss.str();
	log("flagi", "Zmienne koncowe\n", sIn.c_str());
	linie.replace(wpoczatek, wile, sIn);

	log("flagi", "Koniec Falg");
}

void data(std::string& linie, WINDOW* win, std::string& sReserved, size_t& tReserved){

	log("data", "Pokazuje datê");

	size_t pierwsza, druga;
	std::string buff;
	short y;

	buff = linie.substr(0, linie.find('\n'));
	pierwsza = buff.find('.');
	druga = buff.find_last_of('.');
	y = 8;

	border(win);
	mvwprintw(win, y++, 10, "Data sejwa: dzien: %s", buff.substr(++druga, buff.size() - druga - 1).c_str());
	mvwprintw(win, y++, 22, "miesiac: %s", buff.substr(++pierwsza, druga - pierwsza-1).c_str());
	mvwprintw(win, y++, 22, "rok: %s", buff.substr(6, 4).c_str());
	cont(win);

	log("data", "koniec daty");
}

void wybor_tag(std::string& linie, WINDOW* win, std::string& sReserved, size_t& indeks){
	
	logline();
	log("wybor_tag", "Poczatek wyboru tag");

	unsigned max_x, max_y;
	getmaxyx(win, max_y, max_x);
	
	border(win);
	std::string s = "Podaj TAG panstwa ktore chcesz edytowac:";
	mvprintw(max_y/2 - 3, (max_x - s.size())/2, "%s", s.c_str());
	echo();
	move(max_y/2, max_x/2 - 1);
	char cTag[4];
	scanw("%3s", cTag);
	noecho();
	log("wybor_tag", "Wpisano", cTag);

//wielkie lit
	for(unsigned i=0; i < 3; ++i){
		if(cTag[i] >= 'a' && cTag[i] <= 'z') cTag[i] -= 32;
	}

	s = cTag;
	s += "={\n    history={";
	log("wybor_tag", "szukana fraza", s.c_str());

	size_t nindeks;
	nindeks = linie.find(s);
	log("wybor_tag", "Nowy indeks", indeks);

	if(nindeks == std::string::npos){
		log("zmiana_taga", "Nie znaleziono metoda history, szukanie z humanem");
		s = cTag;
		s += "={\n    human=yes";
		log("wybor_tag", "szukana fraza", s.c_str());
		nindeks = linie.find(s);
	}
	if(nindeks == std::string::npos){
		s = "Nie znaleziono takiego taga";
		log("wybor_tag", s.c_str());
		border(win);
		mvprintw(max_y/2, (max_x - s.size()) / 2, "%s", s.c_str());
		cont();
	}
	else if(nindeks > linie.size()){
		s = "Nowy indeks przekracza rozmiar pliku ?!";
		log("wybor_tag", s.c_str());
		border(win);
		mvprintw(max_y/2, (max_x - s.size()) / 2, "%s", s.c_str());
		cont();
	}
	else{
		indeks = nindeks;
		log("zmiana_tag", "zast¹piono oryginalny indeks, aktualny", indeks);
	}
	//delete[] cTag;
	log("wybor_tag", "Koniec wyboru tag");
}

void explode(const std::string &str,const char *delim, std::vector<std::string> &out){

    std::string::const_iterator i1 = str.begin(); 
    std::string::const_iterator i2 = i1; 
	std::string::const_iterator i3 = str.end(); 

    while(i1 != i3){ 
        while(i2 != i3 && !strchr(delim,*i2))++i2; 
		out.push_back(std::string(i1,i2)); 
        i1 = i2 != i3 ? ++i2 : i2; 
    } 
}
#if defined xxx
void kraj(std::string& linie, WINDOW* wDol, std::string& sReserved, size_t& indeks){

	size_t poczatek;//, dziura, koniecdziury, koniec;
	poczatek = linie.find("variables={", indeks);
	logline();
	log("kraj", "poczatek kraju");
	log("kraj", "indeks poczatku", poczatek);
	//poczatek = linie.find("capital=", poczatek);
	/*
	dizura = linie.find("distribution={", poczatek);
	koniecdziury = linie.find("cancelled_loans=", dziura);
	koniec = linie.find("cancelled_loans=", koniecdziury);
	*/
	std::vector<std::string> szukane;

	szukane.push_back("capital");
	szukane.push_back("primary_culture");
    /*
	accepted_culture=normand
    accepted_culture=gascon
	*/
    szukane.push_back("religion");
    szukane.push_back("technology_group");
    szukane.push_back("unit_type");
	//auto_send_merchants=yes
    szukane.push_back("prestige");
    szukane.push_back("stability");
    szukane.push_back("stability_investment");
    szukane.push_back("treasury");
    szukane.push_back("current_income");
    szukane.push_back("estimated_monthly_income");
    szukane.push_back("inflation");
	szukane.push_back("war_exhaustion");
    szukane.push_back("land_maintenance");
    szukane.push_back("naval_maintenance");
    szukane.push_back("colonial_maintenance");
    szukane.push_back("missionary_maintenance");
    szukane.push_back("army_tradition");
    szukane.push_back("navy_tradition");
	szukane.push_back("loan_size");
	szukane.push_back("badboy");
	szukane.push_back("government");
	szukane.push_back("colonists");
	szukane.push_back("merchants");
	szukane.push_back("missionaries");
	szukane.push_back("spies");
	szukane.push_back("diplomats");
	szukane.push_back("centralization_decentralization");
	szukane.push_back("aristocracy_plutocracy");
	szukane.push_back("serfdom_freesubjects");
	szukane.push_back("innovative_narrowminded");
	szukane.push_back("secularism_theocracy");
	szukane.push_back("mercantilism_freetrade");
	szukane.push_back("offensive_defensive");
	szukane.push_back("land_naval");
	szukane.push_back("quality_quantity");
	szukane.push_back("manpower");

	log("kraj", "szukanych", szukane.size());

	std::vector<cDana> dane;

	for(unsigned i=0; i < szukane.size(); ++i){
		cDana dana(linie, szukane[i], indeks);
		if(dana.good()) dane.push_back(dana);
	}


	log("kraj", "danych", dane.size());
	short x, y, cy=2;
	unsigned short max_wybor;
	char znak;


	for(;;){
		max_wybor = dane.size() -1;
		y=cy, x=4;

		border(wDol);
		mvwprintw(wDol, y++, x+20, "Wlasciwosci kraju:");
		for(unsigned i=0; i<dane.size(); ++i) 
			mvwprintw(wDol, ++y, x, "%s = %s", dane[i].chco(), dane[i].chwartosc());

		wattron(wDol, COLOR_PAIR(2));
		mvwprintw(wDol, ktory + cy, x, "%s = %s", dane[ktory].chco(), dane[i].chwartosc());
		wattroff(wDol, COLOR_PAIR(2));

		mvwprintw(wDol, 40, 55, "Ruch: strzalki gora/dol");
		mvwprintw(wDol, 41, 55, "Nowa flaga/edycja: enter");
		mvwprintw(wDol, 42, 55, "Usuniecie flagi: del");
		mvwprintw(wDol, 43, 55, "Wyjscie: ESC");
		wrefresh(wDol);

		noecho();
		znak = getch();
		if (znak == 3){
			if(ktory != min_wybor) ktory--;
			else if(ktory == min_wybor) ktory = max_wybor;
		}
		else if(znak == 2){
			if(ktory != max_wybor) ktory++;
			else if(ktory == max_wybor) ktory = min_wybor;
		}

		else if(znak == 13){//enter
			std::string flag;
			dane[ktory].strwartosc(flag);
			log("flag", "Edytuje flage", flag.c_str());
			border(wDol);
			WINDOW* win;
			win = newwin(5, 60, 15, 20);
			wattron(win, A_BOLD);
			for(;;){
				border(win);
				mvwprintw(win, 2, 2, "%s", );
				wrefresh(win);
				znak = getch();
				if(znak == 13)break;
				else if(znak == 27){
					flag = flagi[ktory];
					break;
				}
				else if((znak >= 'a' && znak <= 'z') || (znak >= 'A' && znak <= 'Z')) flag += znak;
				else if(znak == 8 && flag.size() != 0)flag.erase(flag.size()-1);
			}
			delwin(win);
			flagi[ktory] = flag;
			log("flag", "Wyedytowana flaga", flag.c_str());
		}
		else if(znak == 74){//del
			if(ktory != 0){
				log("flag", "Usunieto flage", flagi[ktory].c_str());
				flagi.erase(flagi.begin() + ktory);
				ktory--;
			}
		}
		else if(znak == 27)break;
		/*enter jak var*/
		else if(znak == 13){
			if(0 == ktory - flagi.size()){//dodanie var
				log("flag", "Dodaje var");
				std::string flag;
				WINDOW* win;
				char* ch = new char[256];

				border(wDol);
				win = newwin(5, 40, 15, 20);
				border(win);

				echo();
				wattron(win, A_BOLD);
				mvwgetstr(win, 2, 2, ch);
				noecho();

				flag = ch;
				var.push_back(flag);
				log("flag", "Dodano var", flag.c_str());

				delete[] ch;
				delwin(win);
			} 
			else{//edycja flagi
				std::string flag = var[ktory - flagi.size()];
				log("flag", "Edytuje var", flag.c_str());
				border(wDol);
				WINDOW* win;
				win = newwin(5, 40, 15, 20);
				wattron(win, A_BOLD);
				for(;;){
					border(win);
					mvwprintw(win, 2, 2, "%s", flag.c_str());
					wrefresh(win);
					znak = getch();
					if(znak == 13)break;
					else if(znak == 27){
						flag = var[ktory];
						break;
					}
					else if(
						(znak >= 'a' && znak <= 'z')//male litery
						|| (znak >= 'A' && znak <= 'Z')//wielkie litety
						//|| znak == ' ' || znak == '='// rozne takie
						//|| (znak >= '0' && znak <= '9')//cyfry
						) flag += znak;
					else if(znak == 8 && flag.size() != 0)flag.erase(flag.size()-1);
				}
				delwin(win);
				var[ktory - flagi.size()] = flag;
				log("flag", "Wyedytowana flaga", flag.c_str());
			}
		}
		else if(znak == 74){//del
			if(ktory != 0){
				log("flag", "Usunieto var", var[ktory - flagi.size()].c_str());
				var.erase(var.begin() + ktory - flagi.size());
				ktory--;
			}
		}
		else if(znak == 27)break;
	}
	

}
#endif
cDana::cDana(const std::string& linie, const std::string& nazwa, size_t indeks){

	poczatek = linie.find(nazwa, indeks);
	koniec = linie.find('\n', poczatek);
	rown = linie.find('=')+1;
	co = nazwa;
	wartosc = linie.substr(rown, koniec);
	if(poczatek == -1 || koniec == -1 || rown == -1){
		log("cDana", "czegos nie znaleziono dla nazwy", nazwa.c_str());
		ok = false;
	}
	else{
		log("cDana", "utworzono instancje nazwy", nazwa.c_str());
		ok = true;
	}
}

void cDana::zapis(std::string& linie){
	std::string buff = co;
	buff += '=';
	buff += wartosc;
	buff += "\n";
	linie.replace(poczatek, koniec, buff);
	log("cDana", "zreplacowano", co.c_str());
}
