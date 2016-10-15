#define make
#define _CRT_SECURE_NO_WARNINGS
#if defined make
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 20

void foo(int*);

int main(){
	int *tab;
	int i;
	FILE *plik;

	srand((unsigned)time(NULL));

	tab = malloc(N * sizeof *tab);
	if(tab == NULL){
		printf("ERROR tab :(\n");
		system("pause");
		return 0;
	}

	for(i=0; i<N; ++i)
		tab[i] = (rand()%21)-15;

	foo(tab);

	plik = fopen("plik.txt", "w+");
	if(plik == NULL){
		printf("ERROR plik :(\n");
		system("pause");
		return 0;
	}

	for(i=0; i<N; ++i)
		fprintf(plik, "%d\n", tab[i]);

	printf("ok! ;)\n");
	system("pause");
	fclose(plik);
	free(tab);
	return 0;
}

void foo(int *tab){
	int n = N;
	/*while(tab != NULL){*/
	while(n--){
		if(*tab < 0) *tab = 2*abs(*tab);
		tab++;
	}
}

#endif

