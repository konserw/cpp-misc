// eu3tool.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "wers.h"

unsigned save(const std::deque<cWers>& wersy, const char* plik){
	unsigned j=0;
	std::ofstream of(plik);

	for(std::deque<cWers>::const_iterator i = wersy.begin(); i < wersy.end(); ++i){
		of << *i;
		++j;
	}
	of << std::endl;
	return j;
}

int main(){
	std::string buff;
	WIN32_FIND_DATAA wfd; 
	std::deque<std::string> pliki;
	int max;

	HANDLE uchwyt = FindFirstFileA("localisation\\*", &wfd); 
    if (uchwyt != INVALID_HANDLE_VALUE) 
    { 
		do{
			pliki.push_back(static_cast<std::string>(wfd.cFileName));
		}while (FindNextFileA(uchwyt, &wfd)); 
        FindClose(uchwyt); 
    }
	max = pliki.size();
	for(int i=2; i<max; i++){
		std::cout << pliki[i] <<"\n";
		buff = "localisation\\";
		buff += pliki[i];
		std::ifstream is(buff.c_str());
		buff = "loc\\";
		buff += pliki[i];
		std::ofstream os(buff.c_str());

		while(getline(is, buff)){
			cWers wers(buff);
			os << wers;
		}
		os << std::endl;
	}
	return 0;
}
/*
void u_pliki(std::deque<std::string>& pliki){
	pliki.push_back("localisation\\2nd_inn.csv");
	pliki.push_back("localisation\\bak.csv");
	pliki.push_back("localisation\\BKaddings.csv");
	pliki.push_back("localisation\\DeI - IN.csv");
	pliki.push_back("localisation\\DeI 1.8a.csv");
	pliki.push_back("localisation\\DeI 2.0.csv");
	pliki.push_back("localisation\\DeI.csv");
	pliki.push_back("localisation\\dw_gold.csv");
	pliki.push_back("localisation\\extra.csv");
	pliki.push_back("localisation\\httt.csv");
	pliki.push_back("localisation\\in_nomine_text.csv");
	//pliki.push_back("localisation\\loadingtips.csv");
	pliki.push_back("localisation\\napoleontext.csv");
	//pliki.push_back("localisation\\national army.csv");
	pliki.push_back("localisation\\newtext.csv");
	pliki.push_back("localisation\\new_mac.csv");
	pliki.push_back("localisation\\rotw.csv");
	pliki.push_back("localisation\\temp.csv");
	pliki.push_back("localisation\\text.csv");
	pliki.push_back("localisation\\text112.csv");
	pliki.push_back("localisation\\text21.csv");
	//pliki.push_back("localisation\\UpdatedNavalUnits.csv");
	pliki.push_back("localisation\\v3.csv");
	pliki.push_back("localisation\\v41.csv");
	pliki.push_back("localisation\\v51.csv");
}

int main(){
	std::deque<std::string> pliki;
	int max;
	std::string buff;
	std::deque<cWers> prov, eventy, mis_dec, other, cb, ruler, flag, country, alert, units, res, tut, region, lower;

	u_pliki(pliki);
	max = pliki.size();

	for(int j=0; j<max; ++j){
		std::cout << "przetwarzanie pliku:\t" << pliki[j] << "\n";
		std::ifstream is(pliki[j].c_str());
		while(getline(is, buff)){
			cWers wers(buff);
			
			if(wers.desc()[0] == '#')continue;
			else if(wers.find("PROV") && !wers.find("PROVDECISION"))				
				prov.push_back(wers);
			else if(wers.find("EVTNAME") || wers.find("EVTDESC") || wers.find("EVTOPT"))
				eventy.push_back(wers);
			else if(wers.find("cb_") || wers.find("nocasusbelli") || wers.find("CB_"))
				cb.push_back(wers);
			else if(wers.find("_title") || wers.find("_desc"))
				mis_dec.push_back(wers);
			else if(wers.find("desc_")){
				std::string b(wers.desc());
				b = b.substr(b.find("_")+1, -1);
				for(std::deque<cWers>::reverse_iterator i = other.rbegin(); i < other.rend(); ++i){
					if(i->find(b.c_str())){
						flag.push_back(*i);
						other.erase(i.base()-1);
						break;
					}
				}
				flag.push_back(wers);
			}
			else if(wers.find("DESCR")){
				std::string b(wers.desc());
				b = b.substr(0, b.find("D"));
				for(std::deque<cWers>::reverse_iterator i = other.rbegin(); i < other.rend(); ++i){
					if(i->find(b.c_str())){
						units.push_back(*i);
						other.erase(i.base()-1);
						break;
					}
				}
				units.push_back(wers);
			}
			else if(wers.find("DESC")){
				std::string b(wers.desc());
				b = b.substr(0, b.find("D"));
				for(std::deque<cWers>::reverse_iterator i = other.rbegin(); i < other.rend(); ++i){
					if(i->find(b.c_str())){
						res.push_back(*i);
						other.erase(i.base()-1);
						break;
					}
				}
				res.push_back(wers);
			}
			else if(wers.find("_ADJ") && !wers.find("_ADJ2"))
				country.push_back(wers);
			else if(wers.find("_ADJ2")){
				std::string b(wers.desc());
				b = b.substr(0, 3);
				for(std::deque<cWers>::reverse_iterator i = other.rbegin(); i < other.rend(); ++i){
					if(i->find(b.c_str())){
						country.push_back(*i);
						other.erase(i.base()-1);
						break;
					}
				}
				country.push_back(wers);
			}
			else if(wers.find("_ruler_"))
				ruler.push_back(wers);
			else if(wers.find("alert_"))
				alert.push_back(wers);
			else if(wers.find("tut_") || wers.find("tutorial"))
				tut.push_back(wers);
			else if(wers.find("_region"))
				region.push_back(wers);
			else if(islower(wers.desc()[0]))
				lower.push_back(wers);
			else 
				other.push_back(wers);
		}
	}

	std::cout << "zapisywanie:\t" << "loc\\missions_decisions.csv\tlini: " <<  save(mis_dec, "loc\\missions_decisions.csv") << "\n";
	std::cout << "zapisywanie:\t" << "loc\\events.csv\tlini: " << save(eventy, "loc\\events.csv") << "\n";
	std::sort(prov.begin(), prov.end());
	std::cout << "zapisywanie:\t" << "loc\\provinces.csv\tlini: " << save(prov, "loc\\provinces.csv") <<"\n";
	std::sort(cb.begin(), cb.end());
	std::cout << "zapisywanie:\t" << "loc\\cb.csv\tlini: " << save(cb, "loc\\cb.csv") << "\n";
	std::sort(ruler.begin(), ruler.end());
	std::cout << "zapisywanie:\t" << "loc\\ruler_titles.csv\tlini: " << save(ruler, "loc\\ruler_titles.csv") << "\n";
	std::sort(flag.begin(), flag.end());
	std::cout << "zapisywanie:\t" << "loc\\flags.csv\tlini: " << save(flag, "loc\\flags.csv") << "\n";
	std::sort(country.begin(), country.end());
	std::cout << "zapisywanie:\t" << "loc\\countries.csv\tlini: " << save(country, "loc\\countries.csv") << "\n";
	std::sort(alert.begin(), alert.end());
	std::cout << "zapisywanie:\t" << "loc\\alerts.csv\tlini: " << save(alert, "loc\\alerts.csv") << "\n";
	std::sort(units.begin(), units.end());
	std::cout << "zapisywanie:\t" << "loc\\units.csv\tlini: " << save(units, "loc\\units.csv") << "\n";
	std::sort(res.begin(), res.end());
	std::cout << "zapisywanie:\t" << "loc\\resources.csv\tlini: " << save(res, "loc\\resources.csv") << "\n";
	std::sort(tut.begin(), tut.end());
	std::cout << "zapisywanie:\t" << "loc\\tutorial.csv\tlini: " << save(tut, "loc\\tutorial.csv") << "\n";
	std::sort(region.begin(), region.end());
	std::cout << "zapisywanie:\t" << "loc\\regions.csv\tlini: " << save(region, "loc\\regions.csv") << "\n";
	std::sort(lower.begin(), lower.end());
	std::cout << "zapisywanie:\t" << "loc\\lower.csv\tlini: " << save(lower, "loc\\lower.csv") << "\n";
	std::sort(other.begin(), other.end());
	std::cout << "zapisywanie:\t" << "loc\\other.csv\tlini: " << save(other, "loc\\other.csv") << "\n";
//system("pause");
	return 0;
}

*/





