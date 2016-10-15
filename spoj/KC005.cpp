#include <iostream>
#include <string>
#include <vector>
//#include <fstream>
#include <sstream>

using std::cin;
bool sprawdz(const std::string&);
bool spr_data(std::string&);

int main(){
	std::string buff, imie, nazwisko, data;
	std::vector<size_t> poz;
	//std::ifstream cin("data");

	while(getline(cin, buff)){
		poz.clear();
		poz.push_back(buff.find(' '));
		for(int i=0; i<5; ++i)
			poz.push_back(buff.find(' ', ++poz[i]));
	
		imie = buff.substr(poz[0], poz[1]-poz[0]-2);
		nazwisko = buff.substr(poz[2], poz[3]-poz[2]-2);
		data = buff.substr(poz[5], std::string::npos);
		//std::cout << "imie:\t" << imie <<"\nNazwisko:\t" << nazwisko <<"\nData:\t" << data <<"\n\n";	
		if(sprawdz(imie))std::cout << "0\n";
		else if(sprawdz(nazwisko))std::cout << "1\n";
		else if(spr_data(data))std::cout << "2\n";
		else std::cout << "3\n";
	}

	system("pause");

	return 0;
}

bool sprawdz(const std::string& buff){//true jak cos jest nie tak
	char znak;
	znak = buff[0];
	if(!(znak >= 'A' && znak <= 'Z'))
		return true;
	for(unsigned i=1; i<buff.size(); ++i){
		znak = buff[i];
		if(!(znak >= 'a' && znak <= 'z'))
			return true;
	}
	return false;
}
bool spr_data(std::string& buff){
	buff[buff.find('-')] = ' ';
	buff[buff.find('-')] = ' ';
	std::stringstream str(buff);
	int dd, mm, rr;
	str >> rr >> mm >> dd;
	if(!(rr >= 1900 && rr <= 2000)) return true;
	if(!(mm > 0 && mm < 13)) return true;
	if(!(dd > 0 && dd < 32)) return true;
	return false;
}