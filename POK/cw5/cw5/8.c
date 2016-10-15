//#define make

#if defined make
#include "head.h"

int main(){
	int** tab;
	int n, i, j, max, m, gdzie;

	scanf("%d %d", &n, &m);
	tab = malloc(n * sizeof *tab); 
	for (i = 0; i<n; ++i) {
		tab[i] = malloc(m * sizeof **tab);
	}
	for(i=0; i<n; ++i){
		for(j=0; j<m; ++j){
			scanf("%d", &tab[i][j]);
			if(j==0 && i == 0){
				max = tab[i][j];
				gdzie = 0;
			}
			else if(tab[i][j] >= max){
				max = tab[i][j];
				gdzie = i;
			}
		}
	}

	printf("\nMax:\t%d\ngdzie:\t%d\n\n", max, gdzie);
	
	for (i = 0; i<n; ++i) {
		free(tab[i]);
	}
	free(tab);
	//system("pause");
	return 0;
}
#endif