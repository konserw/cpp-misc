/*
 * zabawy z techami dla paradygmata by konserw
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

using namespace std;

int main(){
	double szok, fire, b, morale;
	string wej, buff;
	vector<string> vec;
	string plik, pp;
	int wyb;
	std::vector<string> sv;
	vector<double> multi;
	sv.push_back("land_morale");
	sv.push_back("infantry_fire");
	sv.push_back("cavalry_fire");
	sv.push_back("artillery_fire");
	sv.push_back("infantry_shock");
	sv.push_back("cavalry_shock");
	sv.push_back("artillery_shock");

	cout << "Siema Para!\n"
		"Odpowiedni plik musi znajdowac sie w tym samym folderze co program!\n"
		"wybierz:\n\t1: naval\n\t2: land\n";
	cin >> wyb;
	if(wyb == 1){
		plik = "naval.txt";
		cout << "Podaj mnoznik dla fire:\t";
		cin >> fire;
		cout << "Podaj mnoznik dla szok:\t";
		cin >> szok;
		cout << "Podaj mnoznik morali:\t";
		cin >> morale;
		cout << "\n\nPraca w toku\n\n";
	}
	else{
		double b;
		plik = "land.txt";

		cout << "Podaj:\n";
		for(unsigned i=0; i< sv.size(); ++i){
			cout << "\t" << sv[i] <<":\t";
			cin >> b;
			multi.push_back(b);
		}

	}
	pp = plik;
	pp += ".bak";

	ifstream in, bak;
	bak.open(plik.c_str());
	if(!bak.is_open()){
		cout << "nie udalo sie otworzyc pliku\nNastapi zakonczenie programu\n";
		system("pause");
		return 0;
	}
	ofstream out;
	out.open(pp.c_str());
	if(!out.is_open()){
		cout << "nie udalo sie otworzyc pliku\nNastapi zakonczenie programu\n";
		system("pause");
		return 0;
	}
	getline(bak, buff, '\0');
	out << buff << endl;
	out.close();
	bak.close();
	in.open(plik.c_str());
	if(!in.is_open()){
		cout << "nie udalo sie otworzyc pliku\nNastapi zakonczenie programu\n";
		system("pause");
		return 0;
	}

	if(!in.good()){
		cout << "error!\n";
		system("pause");
		return 0;
	}

	if(plik == "naval.txt"){
		in >> buff;
		while(in.good()){
			if(buff.find("fire") != -1){
				stringstream is;
				stringstream os;
				vec.push_back(buff); // wyraz z szukanym slowem
				in >> buff;
				vec.push_back(buff); // '='
				in >> buff;
				is.str(buff);
				is >> b;
				b *= fire;
				os << setprecision(2) << b;
				buff = os.str();
			}
			else if(buff.find("shock") != -1){
				stringstream is;
				stringstream os;
				vec.push_back(buff); // wyraz z szukanym slowem
				in >> buff;
				vec.push_back(buff); // '='
				in >> buff;
				is.str(buff);
				is >> b;
				b *= szok;
				os << setprecision(2) << b;
				buff = os.str();
			}
			else if(buff.find("morale") != -1){
				stringstream is;
				stringstream os;
				vec.push_back(buff); // wyraz z szukanym slowem
				in >> buff;
				vec.push_back(buff); // '='
				in >> buff;
				is.str(buff);
				is >> b;
				b *= morale;
				os << setprecision(2) << b;
				buff = os.str();
			}
			vec.push_back(buff);
			in >> buff;
		}
	}else{
		in >> buff;
		while(in.good()){
			for(unsigned i=0; i < sv.size(); ++i)
				if(buff.find(sv[i]) != -1){
					stringstream is;
					stringstream os;
					vec.push_back(buff); // wyraz z szukanym slowem
					in >> buff;
					vec.push_back(buff); // '='
					in >> buff;
					is.str(buff);
					is >> b;
					b *= multi[i];
					os << setprecision(2) << b;
					buff = os.str();
				}
			vec.push_back(buff);
			in >> buff;
		}
	}

	in.close();
	out.open(plik.c_str());
	if(!out.is_open()){
		cout << "nie udalo sie otworzyc pliku\nNastapi zakonczenie programu\n";
		system("pause");
		return 0;
	}
	for(unsigned i=0; i < vec.size(); ++i){
		out << vec[i] << "\t";
		if(vec[i] == "}")out << endl;
	}
	out.close();
	cout << "Najprawdopodobniej wszystko poszlo dobrze\n";
	system("pause");
	return 0;
}