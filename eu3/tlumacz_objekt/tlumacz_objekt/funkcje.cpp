/*
 * T³umacz - program s³u¿¹cy do t³umaczenia plików .CSV w EU3
 * Wersja objektowa ;)
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

unsigned short cMenu::wybor(unsigned y, unsigned x){

	max_wybor = vOpcje.size()-1;
	ktory = 0;
	char znak;

	for(;;){
		wclear(wOkno);
		wborder(wOkno, '|', '|', '-', '-', '+', '+', '+', '+');
		for(unsigned i = 0; i < vOpcje.size(); ++i) mvwprintw(wOkno, y+i, x, "%s", vOpcje[i].c_str()); 
		mvprintw(y+ktory, x-2, "=>");
		wrefresh(wOkno); 
        znak = getch();
		if (znak == 3 && ktory != min_wybor) ktory--;
		else if(znak == 2 && ktory != max_wybor) ktory++;
		else if(znak ==2 && ktory == max_wybor) ktory = min_wybor;
		else if(znak ==3 && ktory == min_wybor) ktory = max_wybor; 
		else if(znak == 13)	return ktory;
	}
}
unsigned short cMenu::wybor(unsigned y, unsigned x, std::vector<std::string>& wstep){

	max_wybor = vOpcje.size()-1;
	ktory = 0;
	char znak;
	short ny = y + wstep.size() +1;

	for(;;){
		wclear(wOkno);
		wborder(wOkno, '|', '|', '-', '-', '+', '+', '+', '+');
		//wstep
		for(unsigned short i=0; i < wstep.size(); ++i) mvwprintw(wOkno, y+i, x, "%s", wstep[i].c_str()); 
		//opcje
		for(unsigned short i = 0; i < vOpcje.size(); ++i) mvwprintw(wOkno, ny+i, x, "%s", vOpcje[i].c_str()); 
		mvprintw(ny+ktory, x-2, "=>");
		wrefresh(wOkno); 
		//kontrola
        znak = getch();
		if (znak == 3 && ktory != min_wybor) ktory--;
		else if(znak == 2 && ktory != max_wybor) ktory++;
		else if(znak ==2 && ktory == max_wybor) ktory = min_wybor;
		else if(znak ==3 && ktory == min_wybor) ktory = max_wybor; 
		else if(znak == 13)	return ktory;
	}
}

std::string wybor_pliku(){

    WIN32_FIND_DATAA wfd; 
    std::string pliki; 
	std::vector<std::string> csv;

	/*
    char path[255]; 
	GetModuleFileNameA(NULL, path, sizeof(path)); 
	int pos = std::string(path).find_last_of("\\"); 
    path[pos + 1] = '*'; 
    path[pos + 2] = 0; 
	*/
    HANDLE uchwyt = FindFirstFileA("*", &wfd); 
    if (uchwyt != INVALID_HANDLE_VALUE) 
    { 
		do{
			pliki = static_cast<std::string>(wfd.cFileName);
			if(pliki.find(".csv") != std::string::npos || pliki.find(".CSV") != std::string::npos){
				csv.push_back(pliki);
				cerr << "znaleziono plik .csv:\t" << pliki << std::endl;
			}
		}while (FindNextFileA(uchwyt, &wfd)); 
        FindClose(uchwyt); 
    } 

	if(csv.size() == 0){
		cerr << "brak plików csv w folderze programu" << std::endl;
		return "ERR";
	}

	cMenu menu(csv, stdscr);
	std::vector<std::string> vec;
	vec.push_back("Witaj w programie do tlumaczenia plikow .CSV!");
	vec.push_back("Je¿eli widzisz krzaczki zamiast polskich znaków");
	vec.push_back("Zmieñ czcionkê na lucida console we w³aœciwoœciach swojej konsoli.");
	vec.push_back("Wybierz plik z lokalizacj¹:");
	return csv[menu.wybor(8, 10, vec)];
}

bool wczyt(const std::string& path, std::vector<cWers>& vWersy){

	//size_t poz, poz2, poz3, poz4, poz5, poz6, poz7;
	std::string buff, eng, pol, desc;
	char hasz;
	unsigned linia = 0;
	std::vector<size_t> poz;

	std::ifstream plik(path.c_str(), std::ios::binary);
	if(!( plik.is_open() && plik.good())){
		cerr << "brak dostêpu do pliku wejœciowego";
		return false;
	}

	if(sGra == EU3){ //eu3
		while(getline( plik, buff ).good()){
			//usuwanie znaku sub
			std::string::iterator i = buff.begin(); 
			while(i != buff.end()){
			  if (*i == 0x1a) 
				i = buff.erase(i); 
			  else 
				++i;
			}

			poz.clear();
			poz.push_back(buff.find(';'));
			for(unsigned i=0; i<5; ++i)	poz.push_back(buff.find(';', poz.at(i)+1));
			desc = buff.substr(0, poz[0]);
			eng = buff.substr(++poz[0], poz[1]-poz[0]);
			pol = buff.substr(++poz[3], poz[4]-poz[3]);
			hasz = buff[poz[4]+3]; //szukanie oznaczenia wprowadzonego prze pirexusa
			
			if (hasz == '#' || hasz == '@'){
				cWers wBuff(desc, eng, pol, hasz);
				vWersy.push_back(wBuff);
			}
			else{
				cWers wBuff(desc, eng, pol);
				vWersy.push_back(wBuff);
			}

			cerr << "wczytano " << linia++ << " liniê" << "\t/EU3/" << std::endl;
		}
	}
	else if(sGra == hoi2){ //HoI2
		while(getline( plik, buff ).good()){
			//usuwanie znaku sub
			std::string::iterator i = buff.begin(); 
			while(i != buff.end()) 
			  if (*i == 0x1a) 
				i = buff.erase(i); 
			  else 
				++i;

			poz.push_back(buff.find(';'));
			for(unsigned i=0; i<7; ++i)	poz.push_back(buff.find(';', poz.at(i)+1));
			desc = buff.substr(0, poz[0]);
			eng = buff.substr(++poz[0], poz[1]-poz[0]);
			pol = buff.substr(++poz[5], poz[6]-poz[5]);

			cWers wBuff(desc, eng, pol);
			vWersy.push_back(wBuff);

			cerr << "wczytano " << linia++ << " liniê" << "\t/HoI2/" << std::endl;
		}
	}
	plik.close();
	cerr << "zamkniêcie pliku wczytania" << std::endl;
	return true;
}

bool zapis(std::string& path, const std::vector<cWers>& vWersy){

	std::fstream plik(path.c_str(), std::fstream::out | std::fstream::app | std::fstream::trunc);
	bool bFlag;

	if( plik.is_open() && plik.good())
		for(unsigned long i=0; i < vWersy.size(); ++i){
			bFlag = vWersy[i].zapis(plik);
			if (bFlag == false){
				cerr << "cos poszlo nie tak podczas zapisu (!?)" << std::endl;
				return false;
			}
		}
	else{
		cerr << "brak dostêpu do pliku na wyjœciu" << std::endl;
		return false;
	}
	return true;
}

bool cWers::zapis(std::fstream &plik) const {
	if(sGra == EU3){
		plik << sDesc << ';' << sEng << ';' << sEng << ';' << sEng << ';' << sPol << ";;;";
		if(bHasz) plik<<cHasz;
		plik << ";;;;;;;x" << std::endl;
	}
	else if(sGra == hoi2)
		plik << sDesc << ';' << sEng << ";;;;;" << sPol << ";;;;;X" << std::endl;
	cerr << "zapisano do pliku" << std::endl;
	return true;
}

void cOkno::wyswietl(const std::string& sTekst){
	wborder(wRamka, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(wRamka);
	mvwprintw(wOkno, 0, 0, sTekst.c_str());
	wrefresh(wOkno);
}