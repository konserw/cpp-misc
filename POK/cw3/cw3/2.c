#define make

#if defined make
#include "head.h"

int main(){
	
	double dokladnosc, L, d;
	//double* y;
	unsigned long size, i;
	int ch;
	double stare, nowe;
		
	for(;;){
		//size = 5;
		printf("podaj L i dokladnosc, lub zero by zakonczyc:\t");
		scanf("%lf", &L);
		if(L <= 0.0000001)break;
		scanf("%lf", &dokladnosc);
		/*y = malloc(size * sizeof *y);
		if(y == NULL)return 1;
		y[0] = L/2.0;
		for(i=0; ;i++){
			if(i == size - 1){
				size += 2;
				y = (double*) realloc(y, size * sizeof *y);
				if(y == NULL)return 1;
			}
			y[i+1] = (y[i] + (L/y[i]))/2.0;
			d = fabs(y[i+1] - y[i]);
			if(d < dokladnosc)break;
		}*/
		stare = L/2.0;
		for(;;){
			nowe = (stare + (L/stare))/2.0;
			d = fabs(nowe - stare);
			if(d < dokladnosc)break;
			stare = nowe;
		}
		printf("pierwiastek z %lf wynosi z dokladnoscia do %lf:\t%lf\n\n", L, dokladnosc, nowe);
		//free(y);
	}
	return 0;
}
#endif