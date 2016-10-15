#include <iostream>
#include <stdio.h>
#include <string>

using std::cin; 
using std::cout; 


int main(){
	char c;
	std::string buff, buff2;
	bool koment = false, quot = false, qq = false;

	while( (c = getchar()) != EOF){
		

		if(koment == true){
			if(c == '*'){
				c = getchar();
				if(c == '/') koment = false;
			}
			continue;
		}

		if(koment == false){
			if(c == 39 && quot == false) qq = !qq;
			if(c == '"' && qq == false) quot = !quot;
			if(quot || qq){
				//cout << c;
				buff += c;
				continue;
			}

			if(c == '/'){
				c = getchar();
				if(c == '/'){
					while(c != '\n') c = getchar();
					//cout << '\n';
					buff += c;
				}
				else if(c == '*') koment = true;
				else{ //cout << '/' << c;
					buff += '/';
					buff += c;
				}
			}
			else //cout << c;
				buff += c;
		}
		if(buff != "\n" && c == '\n'){
			cout << buff ;
			buff.clear();
		}
	}
	return 0;
}
