#include "stdafx.h"
#include "head.h"

const unsigned LOAD = 72;

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


bool techy(unsigned zadana, const char* sciezka){
	logline();
	log("techy", "Pocz¹tek");
		
	std::ofstream plik;
	std::vector<std::string> pliki;
	std::string buff;
	std::vector<std::string> linie;
	unsigned licz = 0;
	float tac = 4;
	std::string path = sciezka;
	path += "\\common\\technologies";

	log("techy", "path", path.c_str());

	pliki.push_back(path + "\\government.txt");
	pliki.push_back(path + "\\land.txt");
	pliki.push_back(path + "\\naval.txt");
	pliki.push_back(path + "\\production.txt");
	pliki.push_back(path + "\\trade.txt");
	
	for(unsigned i = 0; i < pliki.size(); ++i){	
	//	licz = 0;
		linie.clear();
		std::ifstream wczyt;
		wczyt.open(pliki[i].c_str());

		if(!(wczyt.good() && wczyt.is_open())){
			log("techy", "nie udalo sie otworzyc pliku", pliki[i].c_str());
			wczyt.close();
			return false;
		}

		for(unsigned j = 0; j < LOAD; ++j){
			getline(wczyt, buff);
			linie.push_back(buff);
		}

		wczyt.close();
		log("techy", "wczytanie do pamieci >starych< linii powiodlo sie");

		std::ofstream bak;
		std::string cos = pliki[i];
		cos += ".bak";
		bak.open(cos.c_str());

		if(!(bak.good() && bak.is_open())){
			log("techy", "nie udalo sie otworzyc pliku do zapisu bakapa");
			bak.close();
			return false;
		}

		for(unsigned j = 0; j < linie.size(); ++j)
			bak << linie[j] << std::endl;
		bak.close();
		log("techy", "backup zapisany poprawnie");

		unsigned base = linie.size();
		licz = 0;
		for(unsigned j = base; j <= zadana; ++j){
			++licz;
			std::stringstream out;

			out << "technology = { id = " << j;
			out << "\taverage_year = ";
			out << 1880 + (10 * licz) << "\t";

			if(i == 1){//land
				out << "military_tactics = ";
				if(licz%10 == 0) tac += 0.5;
				out << tac << "\t";
				out << "supply_limit = ";
				out << 3.25 + (0.05 * licz);
				out << "\tland_morale = 4.0\t"
					"infantry_fire = 2.75\t"
					"cavalry_fire = 0.6\t"
					"artillery_fire = ";
				out << 8.8 + (0.1 * licz);
				out << "\tinfantry_shock = 2\t"
					"cavalry_shock = 4.5\t"
					"artillery_shock = 1.2";
			}
			else if(i == 2){//naval
				out << "range = ";
				out << 850 + (10 * licz);
				out << "\tnaval_morale = 4.0\t"
					"bigship_fire = 3.0\t"
					"lightship_fire = 3.0\t"
					"galley_fire = 0.5\t"
					"transport_fire = 2.7\t"
					"bigship_shock = 2.9\t"
					"lightship_shock = 2.3\t"
					"galley_shock = 1.7\t"
					"transport_shock = 2.3";
			}
			else if(i == 3){//produkcja
				out << "production_efficiency = ";
				out << 1.05 + (licz * 0.01);
			}
			else if(i == 4){//trade
				out << "trade_efficiency = ";
				out << 1.05 + (licz * 0.01);
			}
			out << "\t}";
			linie.push_back(out.str());
		}
		log("techy", "Dodano dodatkowe linie w pamieci");

		plik.open(pliki[i].c_str());
		if(!(plik.good() && plik.is_open())){
			log("techy", "nie udalo sie otworzyc pliku", pliki[i].c_str());
			plik.close();
			return false;
		}
		for(unsigned j=0; j<linie.size(); ++j)
			plik<<linie.at(j)<<std::endl;
		plik.close();
		log("techy", "zakonczono zapis pliku", pliki[i].c_str());
	}
	log("techy", "koniec techów");
	logline();
	return true;
}

bool data(const char* sciezka, const char* start, const char* koniec){
	logline();
	log("data", "Poczatek daty");

	unsigned long long nolines=0;
	std::vector<std::string> linie;
	std::string buff;
	std::ifstream plik;
	std::ofstream zplik;
	std::ofstream bak;
	std::stringstream ss;
	std::string path = sciezka;
	path += "\\common\\defines.txt";
	log("data", "sciezka do zmiany daty", path.c_str());

	plik.open(path.c_str());
	if(!(plik.is_open() && plik.good())){
		log("data", "nie udalo sie otworzyc pliku defines (odczyt)");
		plik.close();
		return false;
	}

	while(getline(plik, buff))	
		linie.push_back(buff);
	
	log("data", "wczytano linii", linie.size());
	plik.close();

	//bakap
	std::string cos = path;
	cos += ".bak";
	bak.open(cos.c_str());
	if(!(bak.good() && bak.is_open())){
		log("techy", "nie udalo sie otworzyc pliku do zapisu bakapa");
		bak.close();
		return false;
	}
	for(unsigned j = 0; j < linie.size(); ++j)
		bak << linie[j] << std::endl;
	bak.close();
	log("techy", "backup zapisany poprawnie");


	linie[0] = "start_date = ";
	linie[0] += start;
	linie[1] = "end_date = ";
	linie[1] += koniec;

	zplik.open(path.c_str());
	if(!(zplik.is_open() && zplik.good())){
		log("data", "nie udalo sie otworzyc pliku defines (zapis)");
		zplik.close();
		return false;
	}

	for (unsigned i=0; i<linie.size(); ++i)
		zplik << linie[i] << std::endl;

	log("data", "koniec zmiany daty");
	logline();
	return true;
}
