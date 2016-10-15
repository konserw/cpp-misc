//#define make

#if defined make
#include "head.h"

int main(){
	double x, suma=0;
	int i=-5, N;

	printf("Podaj x i N:\t");
	scanf("%lf %d", &x, &N);
	if(x < 0.000000001 && 0 > - 0.000000001){
		printf("Wystepuje symbol nieoznaczony 0 do zerowej\n");
		system("pause");
		return 0;
	}

	for(i; i <= N; ++i)suma += pow(x, i)*sin(i*x);
	printf("Sigma = %lf\n", suma);

	system("pause");
	return 0;
}
#endif