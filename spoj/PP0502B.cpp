#include <iostream>
#include <vector>

int main()
{
int ile, n, tmp;
std::vector<int> vec;
std::cin >> ile;
while (ile--){
std::cin >> n;
vec.clear();
while(n--){
std::cin >> tmp;
 vec.push_back(tmp);
 }
 for(int i=vec.size(); i>0; --i)
 std::cout<<vec[i-1]<<" ";
 std::cout<<"\n";
}
system("pause");
return 0;
}
