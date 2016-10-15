//#define make

#if defined make
#include "head.h"
int los();
int main(){
	int** tab;
	int n, i, j, m;

	srand(time(NULL));

	printf("podaj wymiary:\t");
	scanf("%d %d", &n, &m);
	tab = malloc(n * sizeof *tab); 
	for (i = 0; i<n; ++i) {
		tab[i] = malloc(m * sizeof **tab);
	}

	for(i=0; i<n; ++i)
		tab[i][0] = los();
	for(j=0; j<m; ++j)
		tab[0][j] = los();

	for(i=1; i<n; ++i)
		for(j=1; j<m; ++j)
			tab[i][j] = (tab[i][j-1]+tab[i-1][j])/2;

	for(i=1; i<n; ++i){
		for(j=1; j<m; ++j)
			printf("%d ", tab[i][j]);
		printf("\n");
	}
			

	system("pause");
	return 0;
}

int los(){
	int l;
	l = rand()%10+1;
	return l;
}

#endif