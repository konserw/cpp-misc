#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

void torus();
void cube();
void sphere();

int main3(){//usunac 3
	int k;
		
	cout << "wybierz bryle:\n1: torus\n2: szescian\n3: kula\n";
	cin >> k;
	switch(k){
		case 1:
			torus();
			break;
		case 2:
			cube();
			break;
		case 3:
			sphere();
			break;
	}
	//ew. zatrzymanie, np. system("pause")
	return 0;
}
void torus(){
	double r, R, p, v;
	cout << "podaj r i R:\n";
	cin >> r, R;
	p = 4*r*R;
	v = 2*R*pow(r,2);

	cout << "pole powierzchni wynosi:\t" << p << " PI^2\n"
	<< "w przyblizeniu jest to:\t" << p*pow(M_PI,2) << "\n"
	<< "objetosc wynosi:\t" << v << " PI^2\n"
	<< "w przyblizeniu to:\t" << v*pow(M_PI,2) << "\n";
}
void cube(){
	double a, p, v;
	cout << "podaj bok szescianu:\t";
	cin >> a;
	p = 6*pow(a, 2);
	v = pow(a, 3);
	cout << "pole powierzchni wynosi:\t" << p << "\n";
	cout << "objetosc wynosi:\t" << v << "\n";
}
void sphere(){
	double r, p, v;
	cout << "podaj promien kuli:\t";
	cin >> r;
	p = 4*pow(r, 2);
	v = 4/3*pow(r, 3);
	cout << "pole powierzchni wynosi:\t" << p << " PI\n"
	<< "w przyblizeniu jest to:\t" << p*M_PI << "\n"
	<< "objetosc wynosi:\t" << v << " PI\n"
	<< "w przyblizeniu to:\t" << v*M_PI << "\n";
}

