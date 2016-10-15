#include <iostream>

using namespace std;

int main(){
	unsigned long long t, n, x, y;
	cin>>t;
	while(t--){
		cin >> n >> x >> y;
		
		for(unsigned long long i = x; i < n; ++i){
			if(i%x == 0) if(i%y != 0) cout << i <<'\n';
		}
	}
	return 0;
}
