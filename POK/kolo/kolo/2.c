//#define make
#define _CRT_SECURE_NO_WARNINGS
#if defined make
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n, i, min=0, max=0;
	double *tab;

	for(;;){
		printf("podaj n:\t");
		scanf("%d", &n);
		if(n<3)printf("bez sensu liczyc dla n mniejszego od 3 :P\n\n");
		else if(n>30)printf("wg zalozen zadania mialo byc mniej niz 30\n");
		else break;
	}

	tab = malloc(n * sizeof (double));
	if(tab == NULL){
		printf("ERROR! :(\n");
		system("pause");
		return 0;
	}

	tab[0] = 0;
	tab[1] = 0.5;
	for(i=2; i<n; ++i){
		tab[i] = (tab[i-1]*2/3) + cos(tab[i-2]);
	}

	for(i=1; i<n; ++i){
		if(tab[i] < tab[min])min = i;
		else if(tab[i] > tab[max])max = i;
	}

	printf("\n");
	printf("najmniejszy: %d, wartosc %lf\n", min, tab[min]);
	printf("najwiêkszy: %d, wartosc %lf\n", max, tab[max]);	

	system("pause");
	free(tab);
	return 0;
}
#endif

