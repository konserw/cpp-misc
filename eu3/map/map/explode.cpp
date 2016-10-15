
#include "head.h"

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

RGBApixel ex(const std::string &str){
	RGBApixel px;
	std::vector<std::string> v;
	explode(str, ";", v);
	px.Alpha = 0;
	px.Red = atoi(v[1].c_str());
	px.Green = atoi(v[2].c_str());
	px.Blue = atoi(v[3].c_str());
	return px;
}