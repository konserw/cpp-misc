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
/*
1 for
2 while
3 do while
*/

int main(){
	float x, xk, dx;
	int m;
	
	printf("Podaj xp, xk i dx:\t");
	scanf("%f %f %f", &x, &xk, &dx);
	printf("podaj metode:\n1:for\n2:while\n3:do while\n");
	scanf("%d", &m);
	switch(m){
		case 1:
			for(x; x <= xk; x+=dx)
				printf("x = %f\nx2 = %f\nx3 = %f\n\n", x, x*x, pow(x, 3));
			break;
		case 2:
			while(x <= xk){
				printf("x = %f\nx2 = %f\nx3 = %f\n\n", x, x*x, pow(x, 3));
				x += dx;
			}
			break;
		case 3:
			do{
				printf("x = %f\nx2 = %f\nx3 = %f\n\n", x, x*x, pow(x, 3));
				x += dx;
			}while(x <= xk);
	}




system("pause");
return 0;
}
#endif