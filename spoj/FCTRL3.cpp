#include <iostream>

using namespace std;
int main(){
int ile;
std::cin >> ile;
unsigned long long n;
while(ile--){
std::cin>> n;
if(n > 9) cout << "0 0";
else if(n == 0 || n == 1) cout <<"0 1";
else if(n == 2) cout << "0 2";
else if(n == 3) cout << "0 6";
else if(n == 4) cout << "2 4";
else if(n == 5 || n == 6 || n == 8) cout << "2 0";
else if(n == 7)cout << "4 0";
else if(n == 9) cout << "8 0";
cout << "\n";
}
return 0;
}
