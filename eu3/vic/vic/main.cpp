#include "head.h"

std::vector<std::string> eng;
std::vector<std::string> desc;
std::vector<std::string> pol;

int main(){
	std::string dir;
	std::vector<std::string> files;

	std::cout << "szukanie plikow\n";
	find(files, dir);
	std::cout << "znaleziono plikow:\t" << files.size() << "\n";
	for(unsigned i=0; i<files.size(); i++){
		std::cout << "przetwarzanie pliku:\t" << files[i] << "\n";
		wczyt_pl(dir, files[i]);
		wczyt_eng(dir, files[i]);
		zapis(dir, files[i]);
	}
	std::cout << "koniec\n";
	system("pause");
	return 0;
}

void explode(const std::string &str, const char *delim, std::vector<std::string> &out){

    std::string::const_iterator i1 = str.begin(); 
    std::string::const_iterator i2 = i1; 
	std::string::const_iterator i3 = str.end(); 

    while(i1 != i3){ 
        while(i2 != i3 && !strchr(delim,*i2))++i2; 
		out.push_back(std::string(i1,i2)); 
        i1 = i2 != i3 ? ++i2 : i2; 
    } 
}
bool find(std::vector<std::string>& files, std::string& dir){
	
	WIN32_FIND_DATAA wfd; 
    std::vector<std::string> pliki; 
	char path[MAX_PATH];
	std::string buff;
	HANDLE uchwyt;

  //  GetModuleFileNameA(NULL, path, sizeof(path));
	buff = std::string(path);

/*	buff = buff.substr(0, buff.find_last_of("\\"));
	dir = buff;*/
	buff = "pl\\*";

	uchwyt = FindFirstFileA(buff.c_str(), &wfd); 
    if (uchwyt != INVALID_HANDLE_VALUE) 
    { 
        do 
            pliki.push_back(static_cast<std::string>(wfd.cFileName)); 
        while (FindNextFileA(uchwyt, &wfd)); 
        FindClose(uchwyt); 
    } 
	for(unsigned j = 0; j < pliki.size(); ++j)
		if(pliki[j].find(".csv") != std::string::npos || pliki[j].find(".CSV") != std::string::npos)
			files.push_back(pliki[j]);
	return true;

}
bool wczyt_pl(const std::string& dir, const std::string& file){

	std::vector<std::string> vec;
	std::string buff;
//	buff = dir;
	buff = "pl\\";
	buff += file;

	pol.clear();
	std::ifstream plik(buff.c_str());
	if(!( plik.is_open() && plik.good())){
		return false;
	}

	while(getline(plik, buff ).good()){
		vec.clear();
		explode(buff, ";", vec);
		pol.push_back(vec[1]);
	}
	return true;
}
bool wczyt_eng(const std::string& dir, const std::string& file){

	std::vector<std::string> vec;
	std::string buff;
	//buff = dir;
	buff = "eng\\";
	buff += file;

	eng.clear();
	desc.clear();
	std::ifstream plik(buff.c_str());
	if(!( plik.is_open() && plik.good())){
		return false;
	}

	while(getline(plik, buff ).good()){
		vec.clear();
		explode(buff, ";", vec);
		desc.push_back(vec[0]);
		eng.push_back(vec[1]);
	}
	return true;
}
bool zapis(const std::string& dir, const std::string& file){
	std::string path;
	//path = dir;
	path = file;

	std::ofstream plik(path.c_str());

	if( plik.is_open() && plik.good())
		for(unsigned long i=0; i<desc.size(); ++i)
			plik << desc[i] << ';' << eng[i] << ";;;" << pol[i] << ";;;;;;;;;;x" << std::endl;		
	else return false;
	return true;
}