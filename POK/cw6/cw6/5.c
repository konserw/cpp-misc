//#define make

#if defined make
#include "head.h"
int bintodec(int decimal);

int main(){
	FILE* in;
	FILE* out;
	int buff;
	in = fopen("dane.txt", "r");
	out = fopen("wynik.txt", "w");
	if(in == NULL || out == NULL){
		printf("Error!\n");
	}else
		while(fscanf(in, "%d", &buff) == 1)
			fprintf(out, "%d\n", bintodec(buff));
	
	system("pause");
	return 0;
}



int bintodec(int decimal)
{
     int total = 0;
     int power = 1;
     
     while(decimal > 0){
          total += decimal % 10 * power;
          decimal = decimal / 10;
          power = power * 2;
      }

     return total;
}
#endif