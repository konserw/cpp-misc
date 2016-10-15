#include <iostream>
#include "head.h"
fun majny[] = {
		main1,
		main2,
		main3,
		main4,
};

int main(){
	int n;
	std::cout << "wybierz nr cwiczenia:\t";
	std::cin >> n;
	majny[n-1]();
	std::cout << "\n";
	system("pause");
	return 0;
}

