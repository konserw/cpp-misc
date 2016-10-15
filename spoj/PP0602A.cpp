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
vec.push_back(0);
while(n--){
std::cin >> tmp;
 vec.push_back(tmp);
 }

 for(int i=1; i<vec.size(); ++i)
 if(i%2 == 0)std::cout<<vec[i]<<" ";
  for(int i=1; i<vec.size(); ++i)
 if(i%2 != 0)std::cout<<vec[i]<<" ";
 std::cout<<"\n";
}
  system("pause");
return 0;
}
