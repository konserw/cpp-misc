//#define make

#if defined make
#include "head.h"

int main(){
	double x, suma, sumap, sumaj, sumak;
	long n1, n2, i, j, p, k, wejsc;
for(wejsc = 1; wejsc <= 24; ++wejsc){
	//printf("Podaj x, N1, N2:\t");
	scanf("%lf %d %d", &x, &n1, &n2);
	suma = 0;
	//printf("\n%d zestaw danych:\t%lf %d %d\n", wejsc, x, n1, n2);

	for(i=1; i <= n1; ++i){
		//printf("i = %ld\n", i);
		sumaj = 0;
		for(j=-2; j <= i+3; ++j){
			sumaj += sin(j*x);
			//printf("j:\t%ld\tsumaj:\t%lf\n", j, sumaj);
		}
		sumap = 0;
		for(p = 1; p <= 10; ++p){
			sumak = 1;
			for(k = 1; k <= p+n2; ++k)
				sumak *= cos(k*(2+p-x));			
			sumap += sumak;
		}
		suma += sumaj;
		suma += sumap;
		//printf("sumaj:\t%lf\tsumap:%lf\n\t\taktualna suma:\t%lf\n", sumaj, sumap, suma);
		//printf("%lf\n", suma);
		//if(i <= -10000 || i >= 1000000)break;
	}

	printf("%lf\n", suma);
}
	//system("pause");
	return 0;
}
#endif