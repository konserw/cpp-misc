#include <iostream>

int main(){
	double a, b, c;
	std::cin >> a >> b >> c;
	if(a == 0){
		if(b == c) std::cout << "NWR";
		else std::cout << "BR";
	}
	else
		printf("%.2lf", (c - b) / a);
	return 0;
}