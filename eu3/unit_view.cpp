// unit_view.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	log();
	log("main", "entry point");
	std::vector<std::string> pliki;
	std::cout << "pliki ktore maja zostac przeskanowane nalezy umiescic w folderze release\n\n";
	system("pause");
	std::cout << "\n\n";
	find_files(pliki);
	log("main", "Znalezionych plikow", pliki.size());
	if(pliki.size() == 0) return 0;
	std::ofstream out("..\\wynik.txt");
	if(out.good() && out.is_open())log("main", "utworzono plik wynik.txt");
	else{
		log("main", "nie uda³o siê utworzyæ pliku wynik.txt");
		return 0;
	}
	for(unsigned i=0; i < pliki.size(); ++i){
		log("main", "przetwarzanie pliku", pliki[i].c_str());
		if(i != 0 ) out << std::endl;
		out << pliki[i].substr(0, pliki[i].find('.')) << ';';
		std::ifstream plik(pliki[i].c_str());
		std::string buff;
		while(std::getline(plik, buff)){
			if(buff.find('\t') != std::string::npos)buff.erase(buff.find('\t'), 1);
			if(buff.find('=') != std::string::npos)
				out << buff.substr(buff.find('=')+2) << ';';
		}
		plik.close();
	}
	log("main", "pozegnanie");
	out.close();
	std::cout << "Program skonczyl dzialania pomyslnie!\nPozdrowienia, konserw.\n\n";
	system("pause");
	log("main", "Koniec!");
	return 0;
}

void find_files(std::vector<std::string>& pliki){
	//char path[255];
	WIN32_FIND_DATAA wfd; 
	/*size_t pos;

	GetModuleFileNameA(NULL, path, sizeof(path)); 
	log("find_files", "c_str path", path);
	std::string spath = static_cast<std::string>(path);
    pos = spath.find_last_of("\\"); 
	spath = spath.substr(0, pos);
    pos = spath.find_last_of("\\");
	spath = spath.substr(0, pos);
	spath += "\\provinces\\*";
	log("find_files", "sciezka (spath)", spath.c_str());
*/
	HANDLE uchwyt = FindFirstFileA("*", &wfd); 
    if (uchwyt != INVALID_HANDLE_VALUE) 
    { 
		std::string buff;
		do{
			buff = static_cast<std::string>(wfd.cFileName);
			if(buff.find(".txt") != std::string::npos || buff.find(".TXT") != std::string::npos){
				log("find_files", "Znaleziono plik .txt", buff.c_str());
				/*std::string wynik;
				wynik = spath;
				wynik.erase(wynik.size()-1);
				wynik += buff;*/
				pliki.push_back(buff); 
			}
			else log("find_files", "Znaleziono inny plik", buff.c_str());
		}while (FindNextFileA(uchwyt, &wfd)); 
        FindClose(uchwyt); 
    } 
	log("find_files", "Koniec dzia³ania funkcji");
}

void log(){//wywolaj na poczatku programu aby wyczyscic log
	std::ofstream cerr("error.log", std::fstream::trunc);
	cerr << "czas\tfunkcja\tdzia³anie" << std::endl;
	cerr.close();
}
void log(const char* fun, const char* info){
	std::ofstream cerr("error.log", std::fstream::app);
	cerr << clock()/* / CLOCKS_PER_SEC*/ << ":\t/" << fun << "/\t" << info << std::endl;
	cerr.close();
}
void log(const char* fun, const char* info, double liczba){
	std::ofstream cerr("error.log", std::fstream::app);
	cerr << clock() /*/ CLOCKS_PER_SEC*/ << ":\t/" << fun << "/\t" << info << ":\t" << liczba << std::endl;
	cerr.close();
}
void log(const char* fun, const char* info, const char* string){
	std::ofstream cerr("error.log", std::fstream::app);
	cerr << clock() /*/ CLOCKS_PER_SEC */<< ":\t/" << fun << "/\t" << info << ":\t" << string << std::endl;
	cerr.close();
}
