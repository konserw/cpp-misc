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
	int n, n_mniej = 0;
	float x, suma = 0, suma_wiekszych = 0, suma_mniejszych = 0;

	printf("podaj n:\t");
	scanf("%d", &n);
	//float x[n];
	while(--n){
		printf("Podaj wyraz:\t");
		scanf("%f", &x);
		suma += x;
		if(x > 0)suma_wiekszych += x;
		else{
			suma_mniejszych += x;
			n_mniej++;
		}
	}
	printf("suma wszystkich:\t%f\nsuma wiekszych od 0:\t\nsrednia aryt. wszystkich:\t%f\nsrednia mniejszych od 0:\t%f\n",
		suma, suma_wiekszych, suma/n, suma_mniejszych/n_mniej);
	system("pause");
	return 0;
}

#endif