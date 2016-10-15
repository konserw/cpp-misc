/* plik klasa.cpp
 * einfall - program stworzony dla einfalla tworz¹cy heirów atomtycznie
 * na podstawie monarchów by konserw
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

#include "pch.h"
#include "klasy.h"

monarch::monarch(
	const std::string& _date,
	const std::string& _name, 
	const std::string& _dynasty,
	ability _DIP,
	ability _ADM,
	ability _MIL,
	bool _female):
		date(_date),
		monarch_name(_name),
		dynasty(_dynasty),
		DIP(_DIP),
		ADM(_ADM),
		MIL(_MIL),
		female(_female){
			leader = false;
}
monarch::monarch(
	const std::string& _date,
	const std::string& _name, 
	const std::string& _dynasty,
	ability _DIP,
	ability _ADM,
	ability _MIL,
	bool _female,
	lead _leader):
		date(_date),
		monarch_name(_name),
		dynasty(_dynasty),
		DIP(_DIP),
		ADM(_ADM),
		MIL(_MIL),
		female(_female),
		lead(_leader){
			leader = true;
}

heir::heir(iterator ten, iterator end): monarch(*ten){
	std::istringstream ss((*ten).imie());
	ss >> name;
	if(female)
		claim = (rand()%20) + 51;
	else 
		claim = (rand()%25) + 71;
	nowy = true;
	date = (*(ten-1)).data();

	std::stringstream iss(date);
	std::stringstream oss;
	int dat;

	iss >> dat;
	dat -= rand()%16;
	oss << dat << ".1.1";
	birth_date = oss.str();

	if(ten == end - 1){
		std::stringstream oss;
		std::stringstream iss(date);
		int dat;

		iss >> dat;
		dat += rand()%35;
		dat += 5;
		oss << dat << ".1.1";
		death_date = oss.str();
	}else
		death_date = (*(ten+1)).data();
}
	
void load(const std::string& it, std::vector<std::string>& kraj){
	std::string poczatek;
	std::string buff;
	std::ifstream plik_in(it.c_str());
	unsigned prawy=0, lewy=0;

	while(getline(plik_in, buff)){
		poczatek += buff;
		poczatek += '\n';
		if(buff.find("capital") != -1){
			kraj.push_back(poczatek);
			poczatek.clear();
			break;
		}
	}

	while(getline(plik_in, buff)){
		std::istringstream ss(buff);
		while(ss >> buff){
			poczatek += buff;
			poczatek += ' ';
			if(buff == "{")lewy++;
			else if(buff == "}")prawy++;
		}
		poczatek += '\n';
		if(lewy == prawy && lewy != 0){
			lewy = 0;
			prawy = 0;
			kraj.push_back(poczatek);
			poczatek.clear();
		}
	}
}

bool compare(const std::string& first, const std::string& second){
	std::istringstream s1(first);
	std::istringstream s2(second);
	std::string ss1, ss2;
	s1 >> ss1;
	s2 >> ss2;
	if(ss1 == ss2){
		if(first.find("heir") != -1)return false;
		else return true;
	}
	else if(ss1 < ss2) return true;
	else return false;
}

void save(const std::string& it, std::vector<std::string>& historia){
	std::ofstream plik(it.c_str());

	sort(historia.begin()+1, historia.end(), compare);

	for(std::vector<std::string>::iterator i = historia.begin(); i < historia.end(); ++i)
		plik << *i << std::endl;
}

std::string heir::print() const{
	std::stringstream ss;
	ss << date << " = {\n"
		"    heir = {\n"
		"        name = " << name;
	if(name[name.size()-1] != '"') ss << '"';
	ss << "\n"
		"        monarch_name = " << monarch_name << "\n"
		"        dynasty = " << dynasty << "\n"
		"        birth_date = " << birth_date << "\n"
		"        death_date = " << death_date << "\n"
		"        claim = " << claim << "\n"
		"        adm = " << ADM << "\n"
		"        dip = " << DIP << "\n"
		"        mil = " << MIL << "\n";
	if(female) ss << "        female = yes\n";
	if(leader)
		ss << "        leader = {\n"
			"            name = " << monarch_name << "\n"
			"            type = general\n"
			"            rank = 0\n"
			"            fire = " << fire << "\n"
			"            shock = " << shock << "\n"
			"            manuever = " << manuever << "\n"
			"            siege = " << siege << "\n        }\n";
	ss << "   }\n}\n";
	std::string out;
	out = ss.str();
	return out;
}