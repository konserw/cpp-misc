#include "pch.h"
/*
using namespace std;

int main(){
	string zrodlo, cel, buff, bb;
	unsigned kk, ks, s, k, i;
	char c;
	bool pisz;

	do{
		cout << "Plik zrodlowy:\t";
		cin >> zrodlo;
		cout << "linie do skopiowania:\n"
			"\tod:\t";
		cin >> ks;
		cout << "\tdo:\t";
		cin >> kk;
		cout << "miejsce wstawienia:\n"
			"\tplik:\t";
		cin >> cel;
		cout << "linie:\n\tod:\t";
		cin >> s;
		cout << "\tdo:\t";
		cin >> k;

		ifstream in(zrodlo.c_str());
		i = 1;
		pisz = false;
		buff.clear();
		while(in.get(c)){
			if(i > kk)break;
			if(i == ks)pisz = true;
			if(pisz)buff += c;
			if(c == '\n')i++;
		}
		ifstream celin(cel.c_str());
		getline(celin, bb, '\0');
		celin.close();
		i = 1;
		k++;
		string::iterator it, its, itk;
		bool sf=true;//, ef=true;
		for(it = bb.begin(); it < bb.end(); ++it){
			if(sf == true && i == s){
				its = it;
				sf = false;
			}
			if (i == k){
				itk = it;
				break;
			}
			if(*it == '\n'){
				i++;
			}

		}
		bb.replace(its, itk, buff);
		ofstream celout(cel.c_str());
		celout << bb << endl;
		cout << bb << endl;
		cout << buff <<  endl;

		cout << "Zakonczono. Koniec programu? [T/N]\t";
		cin >> c;
	}while(c == 'N' || c == 'n');
	return 0;
}

*/