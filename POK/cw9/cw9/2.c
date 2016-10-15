//#define TAK
#if defined TAK
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double wielo(int n, double x, double *tab);

int main(){
	double x, w, tab[20];
	int n, i;
	scanf("%d %lf", &n, &x);
	for(i=0; i<n; ++i)
		scanf("%lf", &tab[i]);
	w = wielo(n, x, tab);
	printf("\n%lf\n", w);
	system("pause");
	return 0;
}

double wielo(int n, double x, double *tab){
	double w;
	int i;

	w = tab[0];
	for(i=1; i<n; ++i)
		w = w*x + tab[i];		

	return w;
}

#endif