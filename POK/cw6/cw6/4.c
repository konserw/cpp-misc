//#define make

#if defined make
#include "head.h"

int main(){
	FILE* in;
	FILE* plus;
	FILE* minus;
	double buff;
	in = fopen("dane.txt", "r");
	plus = fopen("dane1.txt", "w");
	minus = fopen("dane2.txt", "w");
	if(in == NULL || plus == NULL || minus == NULL){
		printf("Error!\n");
	}else{
		while(fscanf(in, "%lf", &buff) == 1){
			if(buff > 0)fprintf(plus, "%lf\n", buff);
			if(buff < 0)fprintf(minus, "%lf\n", buff);
		}
	}
	
	system("pause");
	return 0;
}
#endif