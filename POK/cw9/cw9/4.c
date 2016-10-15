#define TAK
#if defined TAK
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int bool;
typedef struct WSP{
	int i;
	int j;
} wsp;
//typedef struct WSP wsp;

wsp foo(int n, int tab[20][20], int* min, bool pp);


int main(){
	int n, i, j;
	int mac[20][20];
	int *mm;
	int m;
	bool pp;
	wsp gdzie;
	mm = &m;


	scanf("%d", &n);

	for(i=0; i<n; ++i)
		for(j=0; j<n; ++j)
			scanf("%d", &mac[i][j]);

	printf("0/1: min/max\n"
		"0/1: pierwszy/ostatni\n");
	scanf("%d %d", mm, &pp);


	gdzie = foo(n, mac, mm, pp);


	printf("\nmin/max: %d\n gdzie: %d x %d", *mm, gdzie.i+1, gdzie.j+1);

	printf("\n\n");
	system("pause");
	return 0;
}

wsp foo(int n, int tab[20][20], int* min, bool pp){
	bool mm=*min;
	int i, j;
	wsp gdzie;

	gdzie.i = 0;
	gdzie.j = 0;
	*min = tab[0][0];

	for(i=0; i<n; ++i)
		for(j=0; j<n; ++j){
			if(mm==0){
				if(pp==0 && tab[i][j] < *min){
					*min = tab[i][j];
					gdzie.i = i;
					gdzie.j = j;
				}
				else if(pp==1 && tab[i][j] <= *min){
					*min = tab[i][j];
					gdzie.i = i;
					gdzie.j = j;
				}
			}
			else{//mm==1
				if(pp==1 && tab[i][j] >= *min){
					*min = tab[i][j];
					gdzie.i = i;
					gdzie.j = j;
				}
				else if(pp==0 && tab[i][j] > *min){
					*min = tab[i][j];
					gdzie.i = i;
					gdzie.j = j;
				}
			}
		}
	//	printf("%d",*min);
	return gdzie;
}


#endif