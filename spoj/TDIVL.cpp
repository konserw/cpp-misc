#include <iostream>
using namespace std;


int main()
{
	int t;
	cin >> t;
	unsigned long long a, b;
	while(t--){
		cin >> a;
		cin >> b;
		if(a % b == 0)cout << "TAK";
		else cout << "NIE";
		cout << "\n";
	}
	return 0;
}

