/*
 * paczer dla DeI by konserw
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
//#include "header.h"

bool edit(const std::string& path){
	std::string buff, tmp;
	std::fstream plik;
	size_t gdzie;

	plik.open(path.c_str(), std::fstream::in);
	if(!plik.is_open()){
		log("edit", "nie udalo sie otworzyc pliku do odczytu", path.c_str());
		return false;
	}
	getline(plik, buff, '\0');
	plik.close();
	gdzie = buff.find("WAR");
	if(gdzie == -1){
		tmp = "nie odnaleziono WAR w ";
		tmp += path;
		log("edit", tmp.c_str());
		return false;
	}
	tmp = "znaleziono WAR w ";
	tmp += path;
	log("edit", tmp.c_str(), gdzie);
	buff.replace(gdzie, 3, "WRI");
	/*plik.open(path.c_str(), std::fstream::out);
	if(!plik.is_open()){
		log("edit", "nie udalo sie otworzyc pliku do zapisu", path.c_str());
		return false;
	}
	plik << buff << std::endl;
	plik.close();
	*/
	std::ofstream pl(path.c_str());

	if(!pl.good() || !pl.is_open()){
		log("edit", "nie udalo sie otworzyc pliku do zapisu", path.c_str());
//		flag = false;
		return false;
	}
	pl << buff << std::endl;
	pl.close();
	return true;
}
void edit(const std::string& path, bool& flag){
	std::string buff, tmp;
	std::fstream plik;
	size_t gdzie;
	std::vector<std::string> v, v2;

	v.push_back("WAR;Warmia;;;Warmia;;;;;;;;;;x");
	v.push_back("WAR_ADJ2;Warmian;;;Warmiñski;;;;;;;;;;x");
	v.push_back("WAR_ADJ;Warmian;;;Warmiñska;;;;;;;;;;x");

	v2.push_back("WRI;Warmia;;;Warmia;;;;;;;;;;x");
	v2.push_back("WRI_ADJ2;Warmian;;;Warmiñski;;;;;;;;;;x");
	v2.push_back("WRI_ADJ;Warmian;;;Warmiñska;;;;;;;;;;x");

	plik.open(path.c_str(), std::fstream::in);
	if(!plik.is_open()){
		log("edit", "nie udalo sie otworzyc pliku do odczytu", path.c_str());
		flag = false;
		return;
	}
	getline(plik, buff, '\0');
	plik.close();
//bakap
	std::string p;
	p = path;
	p += ".bak";

	std::ofstream ppl(p.c_str());

	if(!ppl.good() || !ppl.is_open()){
		log("edit", "nie udalo sie otworzyc pliku do zapisu", p.c_str());
		flag = false;
		//return;
	}
	ppl << buff << std::endl;
	ppl.close();
//koniec

	for(int i=0; i<3; i++){
		gdzie = buff.find(v[i]);
		if(gdzie == -1){
			tmp = "nie odnaleziono czegos w localization ";
			log("edit", tmp.c_str(), i);
			flag = false;
		}
		else{
			tmp = "znaleziono w lokalization ";
			log("edit", tmp.c_str(), gdzie);
			buff.replace(gdzie, v[i].size(), v2[i]);
		}
	}
	//plik.open(path.c_str(), std::fstream::out);
	std::ofstream pl(path.c_str());

	if(!pl.good() || !pl.is_open()){
		log("edit", "nie udalo sie otworzyc pliku do zapisu", path.c_str());
		flag = false;
		return;
	}
	pl << buff << std::endl;
	pl.close();
}

bool rus(const std::string& path){
	log("rus", "poczatek rus");
	std::string p, buff, b;
	size_t poz;

	p = path;
	p += "decisions\\(DeI) Rus & Golden Horde.txt";
	log("rus", "path", p.c_str());

	std::ifstream is(p.c_str());
	if(!is.good() || !is.is_open()){
		log("rus", "nie udalo sie otworzyc pliku do odczytu", p.c_str());
		return false;
	}

	getline(is, buff, '\0');
	log("rus", "wczytano znakow", buff.size());

	std::string bb;
	bb = p;
	bb += ".bak";
	std::ofstream bak(bb.c_str());
	bak << buff << std::endl;
	log("rus", "zapisany bakap");
	bak.close();

	b = "religion_group = eastern";
	poz = buff.find(b);
	if(poz == -1){
		log("rus", "nie znaleziono", b.c_str());
		return false;
	}
	log("rus", "znaleziono odpowiedni tekst na poz", poz);
	buff.replace(poz, b.size(), "religion_group = eastern_christian");
	is.close();

	std::ofstream of(p.c_str());
	if(!of.is_open() || !of.good()){
		log("rus", "nie udalo sie otworzyc pliku do zapisu", p.c_str());
		return false;
	}
	of << buff << std::endl;
	log("rus", "zapisano");
	return true;
}


