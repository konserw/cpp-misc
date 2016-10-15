//#define make

#if defined make
#include "head.h"

int main(){
	int** tab;
	int** tab2;
	int n, i, j, buff;

	scanf("%d", &n);
	tab = malloc(n * sizeof *tab); 
	for (i = 0; i<n; ++i) {
		tab[i] = malloc(n * sizeof **tab);
	}
	for(i=0; i<n; ++i)
		for(j=0; j<n; ++j)scanf("%d", &tab[i][j]);

#if defined a
	tab2 = malloc(n * sizeof *tab2); 
	for (i = 0; i<n; ++i) {
		tab2[i] = malloc(n * sizeof **tab2);
	}

	
	for(i=0; i<n; ++i)
		for(j=0; j<n; ++j)
			tab2[j][i] = tab[i][j];

	for(i=0; i<n; ++i){
		printf("\n");
		for(j=0; j<n; ++j)
			printf("%d\t", tab2[i][j]);
	}
#endif
#ifndef a


	for(i=0; i<n; ++i)
		for(j=0; j<i; ++j){
			buff = tab[j][i];
			tab[j][i] = tab[i][j];
			tab[i][j] = buff;
		}

	for(i=0; i<n; ++i){
		printf("\n");
		for(j=0; j<n; ++j)
			printf("%d\t", tab[i][j]);
	}





#endif
	printf("\n");
	for (i = 0; i<n; ++i) {
		free(tab[i]);
	}
	free(tab);
	//system("pause");
	return 0;
}
#endif