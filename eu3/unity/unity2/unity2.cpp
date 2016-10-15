/*
 * Program do tworzenia jednostek wojskowych
 * drugiej generacji :)
 * dla gry Europa Universalis 3 (In Nomine)
 *
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


int main()
{
	system("chcp 1250");

	std::fstream lokal("konserw.csv", std::fstream::out | std::fstream::app);
	std::string nazwa_pl, nazwa_eng, nazwa_pliku, desc_eng, desc_pl, nazwa;
	char exit;
	unsigned short wybor1, wybor2, buff;
	std::vector<std::string> wektor2, wektor, vUnit, vLand;
	size_t spacja;

	wektor2.push_back("latin");
	wektor2.push_back("eastern");
	wektor2.push_back("muslim");
	wektor2.push_back("indian");
	wektor2.push_back("chinese");
	wektor2.push_back("ordu");
	wektor2.push_back("sahel");
	wektor2.push_back("african");
	wektor2.push_back("new_world");
	wektor2.push_back("pacific");

	wektor.push_back("offensive_fire");
	wektor.push_back("defensive_fire");
	wektor.push_back("offensive_shock");
	wektor.push_back("defensive_shock");
	wektor.push_back("offensive_morale");
	wektor.push_back("defensive_morale");

	std::ifstream land("land.txt");
	std::string buf;
	std::vector<unsigned> vLT;
	while(getline(land, buf)){
		vLand.push_back(buf);
	}
	land.close();

	do{
		std::cout<<"Witam w programie do tworzenia jednostek!\n"
			"Prosze uzwyac jako nazwy tylko liter alfabetu lacinskiego\n"
			"Wybierz do jakiej grupy technologicznej jednostki chcesz stworzyc:\n"
			"(sehel i ordu wystepuja tylko w DeI)\n";
		for(unsigned short i = 0; i < 10; ++i)
			std::cout << i << ": " << wektor2[i] << "\n";
		std::cin >> wybor1;
		if(wybor1 > 9){
			std::cerr << "error, podaj liczbe z zakresu 0 - 9\n"
				"nastapi zakonczenie programu\n";
			system("pause");
			lokal.close();
			return 0;
		}

		std::cout << "Wybierz typ jednostki jaki chcesz stworzyc:\n"
			"1: jazda\n"
			"2: piechota\n"
			"3: artyleria\n";
		std::cin >> wybor2;

		std::ofstream plik;

		std::cin.ignore();
		std::cout<<"Podaj angielsk¹ nazwe swojej jednostki:\t";
		std::getline(std::cin, nazwa_eng);
		nazwa_pliku = nazwa_eng;
		for(;;){
			spacja = nazwa_pliku.find(' ');
			if(spacja == std::string.npos) break;
			nazwa_pliku[spacja]='_';
		}
		std::cout<<"Podaj polsk¹ nazwe swojej jednostki:\t";
		//std::cin.ignore();
		std::getline(std::cin, nazwa_pl);

		//lokalizacja

		std::cout << "Podaj angielski opis swojej jednostki:\n";
		//std::cin.ignore();
		std::getline(std::cin, desc_eng);
		std::cout << "Podaj polski opis swojej jednostki:\n";
		//std::cin.ignore();
		std::getline(std::cin, desc_pl);
		
		lokal << nazwa_pliku << ";" << nazwa_eng << ";;;" << nazwa_pl << ";;;;;;;;;x" << std::endl 
			<< nazwa_pliku << "DESCR;" << desc_eng << ";;;" << desc_pl << ";;;;;;;;;x" << std::endl;
		
		//koniec lokalizacji
		nazwa = nazwa_pliku;
		nazwa_pliku += ".txt";
		plik.open(nazwa_pliku.c_str());
		plik<<"#"<<nazwa_eng<<"\n#" << nazwa_pl <<"\n\n"
			"unit_type = " << wektor2[wybor1] << "\n"
			"type = ";
		switch(wybor2){
			case 1:
				plik << "cavalry"
					"\n\nmaneuver = 2";
				break;
			case 2:
				plik << "infantry"
					"\n\nmaneuver = 1";
				break;
			case 3:
				plik << "artillery"
					"\n\nmaneuver = 2";
				break;
			default:
				std::cerr << "error\n";
				break;
		}
		plik << std::endl;

		//statsy

		for(unsigned short i = 0; i < 6; ++i){
			std::cout << "Podaj " << wektor[i] << ":\t";
			std::cin >> buff;
			plik << wektor[i] << " = " << buff << std::endl;
		}
		plik.close();

		std::cout << "Podaj poziom LT:\t";
		unsigned lt;
		std::cin >> lt;
		vLT.push_back(lt);
		vUnit.push_back(nazwa);

		std::cout<< "Twoja jednostka zostala zapisana w folderze release w pliku " <<nazwa_pliku<<"\n"
			"Chcesz stworzyc kolejna jednostke? [T/N]\n";
		std::cin>>exit;
		std::cout<<"\n=============================================================================\n";
	}while(exit != 'N' && exit != 'n');
	std::cout << "\n\n\tProsze czekac...";
	lokal.close();
	for(unsigned i=0; i < vLT.size(); ++i){
		std::string buff;
		buff = vLand[vLT[i]];
		buff.erase(buff.find('}'));
		buff += " enable = ";
		buff += vUnit[vLT[i]];
		buff += "\t}";
		vLand[vLT[i]] = buff;
	}
	std::ofstream of("land.txt");
	for(unsigned i = 0; i < vLand.size(); ++i)
		of << vLand[i] << std::endl;
	of.close();
	return 0;
}

