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
 vec.push_back(vec[0]);
 for(int i=1; i<vec.size(); ++i)
 std::cout<<vec[i]<<" ";
 std::cout<<"\n";
}
system("pause");
return 0;
}
