/* plik main.cpp
 * einfall - program stworzony dla einfalla tworz¹cy heirów atomtycznie
 * na podstawie monarchów by konserw
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

#include "pch.h"
#include "klasy.h"

using std::cout;
using std::cin;

int main(){
	WIN32_FIND_DATAA wfd; 
	std::vector<std::string> pliki;
	std::string buff;

	srand(static_cast<unsigned>(time(0)));

	HANDLE uchwyt = FindFirstFileA("*", &wfd);//spath.c_str(), &wfd); 
    if (uchwyt != INVALID_HANDLE_VALUE){ 
		do{
			buff = static_cast<std::string>(wfd.cFileName);
			if(buff.find(".txt") != -1 || buff.find(".TXT") != -1)
				pliki.push_back(buff);
		}while (FindNextFileA(uchwyt, &wfd)); 
        FindClose(uchwyt); 
    }
	else{
		std::cerr << "uchwyt error\n";
		system("pause");
		return 0;
	}
	for(std::vector<std::string>::iterator it = pliki.begin(); it < pliki.end(); ++it){
		char c;
		std::vector<std::string> historia;
		std::vector<monarch> wladcy;
		std::vector<heir> dziedzice;

		cout << "\n======================================================"
			"\n\n\t\t\tPrzetwarzany plik:\t" << *it << "\n"
			"Pminac go?[T/N]\t\t";
		cin >> c;
		if(c == 't' || c == 'T')continue;

		load(*it, historia);

		for(std::vector<std::string>::iterator i = historia.begin(); i < historia.end(); ++i){
			if((*i).find("monarch = {") != -1){
				//sprawdzamy czy nie republika
				if((*i).find("dynasty") == -1){
					cout << "nie znaleziono wpisu dynastii u monarchy,\n"
						"prawdopodobnie jest wladca republikanskim. pomijam.\n";
						continue;
				}

				std::string monarch_name;
				std::string dynasty;
				ability DIP, ADM, MIL;
				bool female = false;
				bool leader = false;
				bool bn = false;
				std::string date;
				ability shock, siege, manuever, fire;

				if((*i).find("female") != -1)female = true;
				if((*i).find("leader") != -1)leader = true;

				std::istringstream ss(*i);
				ss >> date;
				while(ss >> buff){
					if(buff == "name" && bn == false){
						ss >> buff; // =
						getline(ss, monarch_name);
						bn = true;
					}
					else if(buff == "dynasty"){
						ss >> buff; // =
						getline(ss, dynasty);
					}
					else if(buff == "adm"){
						ss >> buff; // =
						ss >> ADM;
					}
					else if(buff == "dip"){
						ss >> buff; // =
						ss >> DIP;
					}
					else if(buff == "mil"){
						ss >> buff; // =
						ss >> MIL;
					}
					if(leader){
						if(buff == "fire"){
							ss >> buff; // =
							ss >> fire;
						}
						else if(buff == "shock"){
							ss >> buff; // =
							ss >> shock;
						}
						else if(buff == "siege"){
							ss >> buff; // =
							ss >> siege;
						}
						else if(buff == "manuever"){
							ss >> buff; // =
							ss >> manuever;
						}
					}
				}
				if(leader){
					lead l(fire, shock, manuever, siege);
					monarch mon(date, monarch_name, dynasty, DIP, ADM, MIL, female, l);
					wladcy.push_back(mon);
				}else{
					monarch mon(date, monarch_name, dynasty, DIP, ADM, MIL, female);
					wladcy.push_back(mon);
				}
			}
			if((*i).find("heir") != -1){ // wpis nastêpcy
				std::string monarch_name;
				std::string dynasty;

				std::istringstream ss(*i);
				while(ss >> buff){
					if(buff == "monarch_name"){
						ss >> buff; // =
						getline(ss, monarch_name);
					}
					else if(buff == "dynasty"){
						ss >> buff; // =
						getline(ss, dynasty);
					}
				}
				heir h(monarch_name, dynasty);
				dziedzice.push_back(h);
			}
		}

		std::vector<monarch>::iterator koniec = wladcy.end();
		for(std::vector<monarch>::iterator i = wladcy.begin(); i < koniec; ++i){
			if(i == wladcy.begin()){
				cout << "Pierwszy wladca nie potrzebuje odpowiadajacego mu wpisu potomka, kontunuuje\n";
				continue;
			}

			bool powt = false;
			//spr. czy nie istnieje odpowiedni wpis
			for(std::vector<heir>::iterator j = dziedzice.begin(); j < dziedzice.end(); ++j){
				if(*i == *j){
					powt = true;
					break;
				}
			}
			if(powt){
			cout << "\n==========================================================\n\n"
				"monarcha:\t" << (*i).imie() << " " << (*i).dynastia() << "\n"
				"POSIADA odpowiedni wpis potomka\n";
				continue;
			}
			//pytamy czy utworzyc
			cout << "\n===========================================================\n\n"
				"monarcha:\t" << (*i).imie() << " " << (*i).dynastia() << "\n"
				"NIE posiada odpowiedniego wpisu potomka, utworzyc odpowiedni wpis?\t";
			cin >> c;
			if(c == 'n' || c == 'N')continue;
			heir h(i, koniec);
			dziedzice.push_back(h);
		}
		for(std::vector<heir>::iterator  i = dziedzice.begin(); i < dziedzice.end(); ++i){
			if((*i).jest_nowy())
				historia.push_back((*i).print());
		}
		save(*it, historia);
	}
	cout << "Dziekujemy za skorzystanie z uslug firmy konserw i synowkie s-ka z.o.o :P\n\n";
	system("pause");
	return 0;
}
