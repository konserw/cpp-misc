#include "wers.h"
#include "stdafx.h"
/*
std::string cWers::print()const{
	std::stringstream ss;
	for(std::deque<std::string>::const_iterator i = vec.begin(); i < vec.end()-1; i++)
		ss << *i << ';';
	ss << 'x';
	return ss.str();
}
*/
void explode(const std::string &str, const char *delim, std::deque<std::string> &out){

    std::string::const_iterator i1 = str.begin(); 
    std::string::const_iterator i2 = i1; 
	std::string::const_iterator i3 = str.end(); 

    while(i1 != i3){ 
        while(i2 != i3 && !strchr(delim,*i2))++i2; 
		out.push_back(std::string(i1,i2)); 
        i1 = i2 != i3 ? ++i2 : i2; 
    } 
}	

std::ostream& operator<< (std::ostream& os, const cWers& w){
	/*for(std::deque<std::string>::const_iterator i = w.vec.begin(); i < w.vec.end()-1; i++)
		os << *i << ';';
	os << 'x';*/
	if(w.vec.size() > 3)
		os << w.vec[0] << ";" << w.vec[1] << ";;;" << w.vec[4] << ";;;;;;;;;;x\n";
	return os;
}