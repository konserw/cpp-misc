#include "stdafx.h"
#include "head.h"

int main()
{
	std::vector<std::string> tagi, pro;
	std::ofstream f("event.txt");
	std::string buff;
	bool petla = false;

	tag(tagi);
	system("pause");
/*
	f <<
		"country_event = {\n"
		"\tid =  15017\n"
		"\ttrigger = {\n"
		"\t\tOR = {" << std::endl;

	cout << "przetwarzanie: \n";
	for(iter i = tagi.begin(); i < tagi.end(); ++i){
		cout << *i << "\n";
		f <<
			"\t\t\tAND = {\n"
			"\t\t\t\ttrade_embargo_by = " << *i << "\n"
			"\t\t\t\tNOT = { has_country_flag = embargoby" << *i << "flag }\n"
			"\t\t\t}" << std::endl;
	}
	cout << "finalizowanie\n";
	f << "\t\t}\n\t}\n"
		"\tmean_time_to_happen = {\n"
		"\t\tdays = 1\n"
		"\t}\n"
		"\ttitle = " << '"' << "EVTNAME15017" << '"' << "\n"
		"\tdesc =  " << '"' << "EVTDESC15017" << '"' << "\n"
		"\toption = {\n"
		"\t\tname = " << '"' << "EVTOPTA15017" << '"' << std::endl;
	cout << "przetwarzanie: \n";
	for(iter i = tagi.begin(); i < tagi.end(); ++i){
		cout << *i << "\n";
		f << 
			"\t\tany_country = { limit = { \n"
			"\t\t\ttrade_embargo_by = " << *i << "\n"
			"\t\t\tNOT = { has_country_flag = embargoby" << *i << "flag }}\n"
			"\t\t\tset_country_flag = embargoby" << *i << "flag\n"
			"\t\t\tset_variable = {\n"
			"\t\t\t\twhich = embargoby" << *i << "variable\n"
			"\t\t\t\tvalue = 1\n"
			"\t\t\t}\n\t\t}" << std::endl;
	}
	f << "\t}\n}" << std::endl;
	*/
	/*
	std::ifstream f("event.txt");
	getline(f, buff, '\0');
	size_t s;
	while(1){
		s = buff.find("HAB");
		if(s == -1)break;
		buff.replace(s, 3, "$");
	}

	f.close();
	std::ofstream o("o.txt");
	o << buff << std::endl;
	o.close();
	*/
	cout << "wczytywanie prototypu (plik o.txt)\n";
	prototyp(pro);
	cout << "wczytywanie prototypu ukonczone\n";
	system("pause");
	cout << "\nprzetwarzam tag:\n";
	
	for(iter i=pro.begin(); i<pro.end(); ++i){
		if(petla == false){
			petla = true;
			f << *i;
			continue;
		}
		petla = false;
		for(iter k = tagi.begin(); k < tagi.end(); ++k){
			cout << *k << '\n';
			for(std::string::iterator j = (*i).begin(); j < (*i).end(); ++j){
				if(*j == '$') f << *k;
				else f << *j;
			}
		}
	}
	cout << "koniec pracy\n";
	system("pause");
	return 0;
}

