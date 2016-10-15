#include <iostream>
#include <cmath>

bool pierwsza(unsigned long);

int main(){
	unsigned long liczba, ile;
	std::cin >> ile;

	while(ile != 0){
		std::cin >> liczba;
		if(pierwsza(liczba)) std::cout << "TAK\n";
		else std::cout << "NIE\n";
		--ile;
	}
	return 0;
}

bool pierwsza(unsigned long liczba){
	if (liczba == 1 || liczba == 0) return false;
	for (unsigned long i=2; i <= (unsigned long)sqrt((double)liczba); ++i)
		if(liczba%i == 0) return false;
	return true;
}
