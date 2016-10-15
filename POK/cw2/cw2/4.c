#define make

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
	int poczatek, koniec, i, ile, najmniejszy=0, naj=0, np, nk;
	int* a;
	printf("podaj Np i Nk:\t");
	scanf("%d %d", &poczatek, &koniec);
	np = poczatek; nk = koniec;
	/*ile = koniec - poczatek+1;
	a = malloc(ile * sizeof *a);

	for(i=0; i < ile; ++i){
		a[i] = -pow(i, 2) + 15*i + 50;
		printf("a[%d]:\t%d\n", i+poczatek, a[i]);
		if(a[i]<a[najmniejszy])najmniejszy = i;
	}*/
	a = malloc((1+koniec) * sizeof * a);
	for(i = 0; i <= nk; ++i){
		a[i] = -pow(i, 2) + 15*i + 50;
		if(i>=np)printf("a[%d]:\t%d\n", i, a[i]);
		if(i >= np){
			if(i == np)najmniejszy = np;
			else if(a[i]<a[najmniejszy])najmniejszy = i;
		}
		if(a[i] < a[naj])naj = i;
	}	



	printf("\nNajmniejszy z tego przedzialu jest %d wyraz i ma wartosc %d\nnajmniejszy od pierwszego jest %d wyraz i ma wartosc %d\n", najmniejszy, a[najmniejszy], naj, a[naj]);
	system("pause");
	free(a);
	return 0;
}
#endif