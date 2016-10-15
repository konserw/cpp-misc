#include "stdafx.h"
#include "head.h"

void tag(std::vector<std::string>& tagi){
	std::fstream in("countries.txt");
	std::string buf;
	unsigned count=0;
	while(getline(in, buf)){
		if(buf.find('#') != -1 || buf.size() < 3)continue;
		std::stringstream ss(buf);
		buf.clear();
		ss >> buf;
		if(buf.size() == 3 ){
			if(buf == "REB" || buf == "PIR" || buf == "NAT")continue;
			tagi.push_back(buf);
			count++;
		}else cout << "dziwna linia: " << buf << "\n";
	}

	cout << "znalezionych tagow:\t" << count <<"\n";

}
void prototyp(std::vector<std::string>& pro){
	std::ifstream o("o.txt");
	std::string buff;
	while(getline(o, buff, '@')){
		buff.erase(buff.end()-1);
		//cout << buff;
		//buff+="\n";
		///system("pause");

		pro.push_back(buff);
	}
}