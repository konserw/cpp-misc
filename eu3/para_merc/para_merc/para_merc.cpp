#include <fstream>
#include <iostream>
#include <string>

int main(){
	std::ifstream is("game.eu3");
	std::ofstream of("bez.eu3");
	std::string buff;
	bool flag = false;
	std::cout << "przetwarzanie pliku...\n";
	while(getline(is, buff)){
		if(buff.find("mercenary=") != -1 && buff.find("mercenary=yes") == -1)flag = true;
		if(flag == false) of << buff << "\n";
		if(flag == true && buff.find("}") != -1)flag = false;
	}
	of << std::endl;
	std::cout << "koniec\n";
	return 0;
}
	