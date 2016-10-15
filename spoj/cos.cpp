#include <iostream>
#include <cmath>

using namespace std;

int main(){
	unsigned testow, x, y, zap;
	double max;

	cin >> testow >> x >> y;
	max = sqrt((double)(x*x+y*y));

	while(testow--){
		cin >> zap;
		if(zap <= max)cout << "TAK\n";
		else cout << "NIE\n";
	}
	return 0;
}

