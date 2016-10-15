#include <iostream>
#include <cmath>
using namespace std;


int main2(){//usunac 2
	double a, b, c, s, p;
		
	cout << "podaj boki trojkata:\n";
	cin >> a >> b >> c;
	
	s = 0.5*(a+b+c);
	p = sqrt((s-a)*(s-b)*(s-c));

	cout <<"pole powierzchni tego trojkata wynosi:\t" << p;

	//ew. zatrzymanie, np. system("pause")
	return 0;
}
