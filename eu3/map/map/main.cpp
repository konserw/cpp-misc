#include "head.h"

int main(){
	unsigned max_x, max_y, max_v, licz=0, col;
	RGBApixel px, pxb;
	std::string buff;
	std::vector<RGBApixel> v;
	bool flag;
	std::ifstream is("definition.csv");

	while(getline(is, buff))
		v.push_back(ex(buff));
	max_v = v.size();

	BMP bmp;
	bmp.ReadFromFile("provinces5.bmp");

	max_x = bmp.TellWidth();
	max_y = bmp.TellHeight();
/*	col = bmp.TellNumberOfColors();

	pxb.Alpha = 0;
	pxb.Blue = 0;
	pxb.Green = 0;
	pxb.Red = 0;

	RGBApixel old;
	old.Alpha = 0;
	old.Blue = 1;
	old.Green = 1;
	old.Red = 1;

	for(unsigned i=0; i < max_y; i++){
		for(unsigned j=0; j<max_x; j++){
			px = bmp.GetPixel(j, i);
			flag = false;
			for(unsigned k=0; k < max_v; k++){
				if(px.Blue == v[k].Blue && px.Green == v[k].Green && px.Red == v[k].Red){// && px.Alpha == v[k].Alpha){
					flag = true;
					break;
				}
			}
		//	flag = true;
		//	if(px.Blue == 1 && px.Green == 1 && px.Red == 1)flag = false;
			if(flag == false){
				licz++;
				bmp.SetPixel(j, i, old);
			}else{
				old = px;
			}
		}
		if(i%250 == 0)std::cout << i << "\t" << licz << "\n";
//		std::cout << "linia: " << i << "\tpoprawionych px: " << licz << "\n";
	}
	std::cout << "koniec\nZmieniono pixeli: " << licz << "\nLiczba kolorow: " << col << " -> " << bmp.TellNumberOfColors() << "\n\n";

	bmp.WriteToFile("provinces6.bmp");
*/

	std::ofstream os("x.txt");
	for(unsigned k=0; k < max_v; k++){
		flag = false;
		for(unsigned i=0; i < max_y; i++){
			for(unsigned j=0; j<max_x; j++){
				px = bmp.GetPixel(j, i);
				if(px.Blue == v[k].Blue && px.Green == v[k].Green && px.Red == v[k].Red){
					flag = true;
					break;
				}
			}
			if(flag)break;
		}
		if(flag == false)os << k << "\t( " << (int)v[k].Red << ", " << (int)v[k].Green << ", " << (int)v[k].Blue << " )\n";
		if(k%100==0)std::cout << k << "\n";
	}





	system("pause");
	return 0;
}







		