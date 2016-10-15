#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#define WIN32_LEAN_AND_MEAN 
#include <windows.h>

void explode(const std::string &str, const char *delim, std::vector<std::string> &out);

bool zapis(const std::string& dir, const std::string& file);
bool wczyt_eng(const std::string& dir, const std::string& file);
bool wczyt_pl(const std::string& dir, const std::string& file);
bool find(std::vector<std::string>& files, std::string& dir);