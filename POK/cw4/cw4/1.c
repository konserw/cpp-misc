//#define make

#if defined make
#include "head.h"

int main(){
	double e, suma, x, dodawany;
	int nmax, i;

	do{
		printf("Podaj x, Nmax  i E:\t");
		scanf("%lf %d %lf", &x, &nmax, &e);
	}while(fabs(x) >= 1);
	
	suma = x;
	for(i = 1; i <= nmax; ++i){
		dodawany = pow(x, i+1)/(i+1);
		if(i % 2 == 0) suma += dodawany;
		else suma -= dodawany;
		if(dodawany <= e)break;
	}

	printf("ln(1+x) = %lf\nz sumy = %lf\nroznica: %lf\n\n",log(1+x), suma, fabs(log(1+x) - suma));

	system("pause");
	return 0;
}
#endif