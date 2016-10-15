//#define make

#if defined make
#define _CRT_SECURE_NO_WARNINGS
//#include "head.h"
#ifndef head
#define head
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#endif

int main(){
	int liczba, suma=0, ilo=1, ilosc=0;
	float srednia;
	int par=0;
	for(;;){
		scanf("%d", &liczba);
		if(liczba <0)break;
		ilosc++;
		suma += liczba;
		if(liczba%2==0)par++;
		if(liczba <5 && liczba > 10)ilo*=liczba;
	}
	if(ilosc == 0){
		printf("nie podano zadnej liczby spelniajacej warunki\n\n");
	}
	else{
		srednia = suma / (float)ilosc;
		printf("suma liczb:\t%d\nilosc parzystych:\t%d\niloczyn:\t%d\nsrednia:\t%f\n\n", suma, par, ilo, srednia);
	}
	system("pause");
	return 0;
}
#endif