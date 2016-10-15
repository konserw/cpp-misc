#pragma once
#include "resource.h"

void explode(const std::string &str, const char *delim, std::vector<std::string> &out);
bool techy(unsigned zadana, const char* sciezka);
bool data(const char* sciezka, const char* start, const char* koniec);


/*
class data{
	private
public:
	UINT d, m, r;
	data(){};
	data(const char* ptr){
		std::string buf(ptr);
		std::vector<std::string> vec;
		explode(buf, ".", vec);
		d = atoi(vec[2].c_str());
		m = atoi(vec[1].c_str());
		y = atoi(vec[0].c_str());
	}

};
*/