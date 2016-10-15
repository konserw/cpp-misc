#pragma once
#include "stdafx.h"

void explode(const std::string &str, const char *delim, std::deque<std::string> &out);

class cWers{
private:
	static const int lang = 3;
	//std::string sDesc, sEng, sPol;
	std::deque<std::string> vec;
public:
	cWers(const std::string& linia){
		explode(linia, ";", vec);
	}
	cWers(){}
/*		vec.push_back("#ID");
		vec.push_back("ENGLISH");
		vec.push_back("FRENCH");
		vec.push_back("GERMAN");
		vec.push_back("POLSKI");
		vec.push_back("SPANISH");
		vec.push_back("ITALIAN");
		vec.push_back("SWEDISH");
		vec.push_back("CZECH");
		vec.push_back("HUNGARIAN");
		vec.push_back("DUTCH");
		vec.push_back("PORTUGESE");
		vec.push_back("RUSSIAN");
		vec.push_back("FINNISH");
	//	vec.push_back("x");
	};*/
	const char* eng()const{
		return vec[1].c_str();//sEng;
	}
	const char* pol()const{
		return vec[lang+1].c_str();//sPol;
	}
	const char* desc()const{
		return vec[0].c_str();//sDesc;
	}
//	std::string print()const;

	void set_desc(char* text){
		vec[0] = static_cast<std::string>(text);
	}
	void set_eng(char* text){
		vec[1] = static_cast<std::string>(text);
	}
	void set_pol(char* text){
		vec[lang+1] = static_cast<std::string>(text);
	}


	int operator< (cWers& q){
		return vec[0] < q.vec[0];
	}
	friend std::ostream& operator<< (std::ostream& os, const cWers& w);
	bool find(const char* co){
		if(vec[0].find(co) != -1)return true;
		return false;
	}
	const std::string& sdesc(){
		return vec[0];
	}

};