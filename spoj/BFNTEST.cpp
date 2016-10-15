/*
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool close(string buff);
bool open(string buff);


int main(){
	string buff;
	size_t found;
	bool koment = false;

	ifstream plik;
	plik.open("pliczek.txt");

	while(getline(plik, buff)){

		if(buff.find("//") != string::npos || buff.find("/*") != string::npos || buff.find("*//*") != string::npos){ 
//BEGIN:
			if(koment == true) koment = !(close(buff));
			if(koment == true) continue;
			if(koment == false) koment = open(buff);
			//if(koment == true) goto BEGIN;
			if(koment == true) koment = !(close(buff));


			found = buff.find("//");
			if(found != string::npos){
				cout << buff.substr(0, --found) << "\n";
				continue;
			}
		}else cout << buff << '\n';

		
	}
	cin.ignore();
	cin.get();
	return 0;
}

bool open(string buff){
	size_t found, quot, quot2;

	found = buff.find("/*");
	if(found != string::npos){
		quot = buff.find('"');
		if( quot != string::npos){
			quot2 = buff.find('"', quot + 1);
			if(quot < found && found < quot2) return false;
		}
		cout << buff.substr(0, --found);
		return true;
	}
	return false;
}
bool close(string buff){
	size_t found, quot, quot2;

	found = buff.find("*//*");
	if(found != string::npos){
		quot = buff.find('"');
		if( quot != string::npos){
			quot2 = buff.find('"', quot + 1);
			if(quot < found && found < quot2) return false;
		}
		cout << buff.substr(++++found, string::npos) << '\n';
		return true;
	}
	return false;
}
*/