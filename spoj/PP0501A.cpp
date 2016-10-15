#include <iostream>

int nwd(int a, int b);

int main(){

	unsigned testow;
	int a, b;

	std::cin>>testow;

	for(unsigned i = 0; i < testow; ++i){
		std::cin >> a >> b;
		std::cout<<nwd(a, b);
	}
	return 0;
}

int nwd(int a, int b){
	if(b == 0) return a;
	return nwd(b, a % b);
}
