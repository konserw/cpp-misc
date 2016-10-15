//#define TAK
#if defined TAK
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void trans(int n, double** wej, double** wyj);

int main(){
	int n, i, j;
	/*
	double m1[20][20];
	double m2[20][20];
	*/
	double** m1;
	double** m2;

	scanf("%d", &n);

	m1 = malloc(n * sizeof (double*));
	m2 = malloc(n * sizeof (double*));
	for(i=0; i<n; ++i){
		m1[i] = malloc(n * sizeof (double));
		m2[i] = malloc(n * sizeof (double));
	}

	for(i=0; i<n; ++i)
		for(j=0; j<n; ++j)
			scanf("%lf", &m1[i][j]);
	trans(n, m1, m2);

	for(i=0; i<n; ++i){
		printf("\n");
		for(j=0; j<n; ++j)
			printf("%lf ", m2[i][j]);
	}
	printf("\n\n");
	system("pause");
	return 0;
}
void trans(int n, double** wej, double** wyj){
	int i, j;
	for(i=0; i<n; ++i)
		for(j=0; j<n; ++j)
			wyj[i][j] = wej[j][i];
}
#endif