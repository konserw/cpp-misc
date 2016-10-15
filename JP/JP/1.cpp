#include <iostream>
#include <cmath>
using namespace std;

struct point{
	double x;
	double y;
	double z;
};

int main1(){//usunac 1
	point p1, p2;
	double l;
	
	cout << "podaj wspolzedne pierwszego punktu\n";
	cin >> p1.x >> p1.y >> p1.z;
	cout << "podaj wspolzedne drugiego punktu\n";
	cin >> p2.x >> p2.y >> p2.z;

	l = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));

	cout <<"odleglosc pomiedzy tymi 2 punktami wynosi:\t" << l;

	//ew. zatrzymanie, np. system("pause")
	return 0;
}
