/*

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

int main(){
	std::ifstream is("positions.txt");
	std::ofstream os("positions2.txt");
	std::string buff, b2;
	double b;
	std::stringstream ss;

	std::cout << "start\n";

	while(std::getline(is, buff, '\n')){
		if(buff.find("x = ") != -1){
	//		std::cout << buff << "\n";
			b2 = buff.substr(buff.find('=')+1);
	//		std::cout << b2 << '\n';
	//		ss.str(b2);
	//		ss >> b;
			b = atof(b2.c_str());
			b*=3;
	//		std::cout << "b*3 = " << b << "\n";
			ss.str("\0");
			ss << "\t\tx = " << std::setprecision(6) << b;
			buff = ss.str();
	//		std::cout << buff << "\n";
	//		system("pause");
		}else if(buff.find("y = ") != -1 && buff.find("city") == -1 && buff.find("manufactory") == -1){
	//		std::cout << buff << "\n";
			b2 = buff.substr(buff.find('=')+1);
	//		std::cout << b2 << '\n';
		//	ss.str(b2);
			//ss >> b;
			b = atof(b2.c_str());
			b*=3;
	//		std::cout << "b*3 = " << b << "\n";
			ss.str("\0");
			ss << "\t\ty = " << std::setprecision(6) << b;
			buff = ss.str();
	//		std::cout << buff << "\n";
	//		system("pause");
		}
		os << buff << std::endl;
	}

	std::cout << "koniec\n";

	return 0;
}
		
		*/
			