//#define make
#define _CRT_SECURE_NO_WARNINGS
#if defined make
#include <stdio.h>
#include <stdlib.h>

int main(){
	int tmp, suma=0, ile=0, ile_s=0;
	for(;;){
		scanf("%d", &tmp);
		if(tmp < 0)break;
		ile++;
		if(tmp >= 5 && tmp <= 15){
			ile_s++;
			suma += tmp;
		}
	}
	printf("\nilosc wczytanych liczb:\t%d\n", ile);
	if(ile_s != 0)
		printf("srednia liczb z zakresu [5, 15]:\t%f\n", suma/(float)ile_s);
	else
		printf("nie wpisano zadnej liczby z zakresu [5, 15]\n");
	system("pause");
	return 0;
}
#endif

