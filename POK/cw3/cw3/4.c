//#define make

#if defined make
#include "head.h"
//unsigned 
double silnia(int liczba ){
	double silnia=1;
	int i=2;
	for(i;i<=liczba;i++) 
		silnia *= i;
	return silnia;
}

int main(){
	double q, e, L, a, b, c, podst, arg;
	int n, i;

	printf("Podaj q, E, n:\t");
	scanf("%lf %lf %u", &q, &e, &n);

	for(i = 0; ;++i){
		if((n - q) > -0.1 && (n-q) < 0.1 && i <= 1){
			//printf("zle argumenty");
			//break;
			i = 2;
		}
		//L = (1.0/silnia(i))*pow(n-q, i-1)*pow(M_E, n*q);
		a = (1.0/silnia(i));
		podst = n-q;
		arg = i-1;
		b = pow(podst, arg);
		//c = pow(M_E, n*q);
		c = exp(n*q);
		L = a*b*c;
		if(L < e){
			printf("%d jest najmniejszym p spelniajacym nierownosc. Lewa strona ma wartosc: %lf\n", i, L);
			break;
		}
	}
	system("pause");
	return 0;
}
#endif