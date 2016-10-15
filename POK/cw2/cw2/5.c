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
	int n, i;
	double* a;
	printf("podaj N:\t");
	scanf("%d", &n);
	if(n >20){
		printf("Wynik bedzie za duzy! ograniczam do 20.\n");
		n = 20;
	}
	putch('\n');
	n += 4;
	a = malloc(n * sizeof *a);
	a[0] = 2;
	a[1] = 1.5;
	a[2] = 1;
	for(i = 3; i < n; ++i){
		a[i] = a[i-1]*sqrt(a[i-2]+a[i-3]);
	}
	for(i = 0; i < n; ++i){
		printf("a[%d] =\t%.3E\n", i-3, a[i]);
	}
	system("pause");
	free(a);
	return 0;
}
#endif