#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float f_min(double *tab, int n);
double f_max(double *tab, int n);
/*moja implementacja typu boolean*/
#ifndef bool
#define bool short int
#define true 1
#define false 0
#endif



int my_atoi(char*);
char* bin(int in);
int foo(int baza, char* ptr);
double** mno(double** m1, double** m2, int m1wierszy, int m1kolumn, int m2wierszy, int m2kolumn);
void bar(double *tab, int n);


int main(){

	int co;
	printf("1: atoi\n"
		"2: dec to bin\n"
		"3: dowolny system na dziesietny\n"
		"4: mnozenie macierzy\n"
		"5: histogram\n"
		);



	scanf("%d", &co);
	switch(co){
		case 1:
			{
				char liczba[10];
				while(1){
					gets(liczba);
					printf("%s\t%d\n", liczba, my_atoi(liczba));
				}
			}
			break;
		case 2:
			{
				char *str;
				int licz;
				while(1){
					scanf("%d", &licz);
					if(licz==0)break;
					str = bin(licz);
					printf("%d:\t%s\n", licz, str);
					free(str);
				}
			}
			break;
		case 3:
			{
				char liczba[256];
				int baza;
				while(1){
					scanf("%d", &baza);
					gets(liczba);
					printf("liczba\tsystem\tdziesietna\n");
					printf("%s\t%d\t%d\n", liczba, baza, foo(baza, liczba));
				}
			}
			break;
		case 4:
			{
				int i, j, n, m;				
				double** m3, **pt1, **pt2;

				n = 10; m = 10;
				pt1 = malloc(n * sizeof *pt1);
				for(i=0; i<n; ++i) pt1[i] = malloc(m * sizeof **pt1);
				pt2 = malloc(n * sizeof *pt1);
				for(i=0; i<n; ++i) pt2[i] = malloc(m * sizeof **pt1);

				for(i=0; i<n; ++i)
					for(j=0; j<n; ++j){
						pt1[i][j] = i*j;
						pt2[i][j] = i+j;
					}
				m3 = mno(pt2, pt1, n, m, n, m); 
				for(i=0; i<n; ++i){
					for(j=0; j<n; ++j)
						printf("%.1lf ", m3[i][j]);
					printf("\n");
				}
				free(m3);
				free(pt1);
				free(pt2);
				system("pause>NULL");
			}
			break;
		case 5:
			{
				int i;
				double n[100];
				for(i=0; i<100; ++i)n[i] = pow(2, 1/3.0)*(double)(rand()%(i+2));
				bar(n, 100);
				system("pause>NULL");
			}
			break;
	}
	
	//system("pause");
	return 0;
}

int my_atoi(char* in){
	int ile, liczba=0, i=0;
	ile = strlen(in);

	while(ile--){
		liczba += (in[ile]-'0')*pow(10, i);
		i++;
	}
	return liczba;
}

char* bin(int in){
	char *str;
	int reszta, n, i;//, k;
    char *ptr;
	bool neg;
	n=0;
	i=0;
	ptr = malloc(1*sizeof(char));

	if(in < 0){
		in = -in;
		neg = true;
	}
	else neg = false;

	while(1){
		reszta = in%2;
		if(reszta == 0) ptr[n] = '0';
		else{
			ptr[n] = '1';
			in--;
		}
		if(in == 0)break;
		in /= 2;
		ptr = realloc(ptr, (++n+2) * sizeof *ptr); /*n - ilosc liczb +1 na \0 +1 na znak*/
	}
	if(neg == true)	ptr[++n] = '-';
	else ptr[++n] = ' ';

	str = malloc((++n+1) * sizeof (char));
	while (n >= 0)
		str[i++] = ptr[--n];
	free(ptr);
	str[--i] = 0;
	return str;
}

int foo(int baza, char* ptr){
	int i, ile, licz=0;
	ile = strlen(ptr);
	for(i=0; i<ile; ++i){
		int tmp;
		tmp = ptr[ile-i]-'a';
		printf("%d ", tmp);
		licz += tmp * pow(baza, i);
	}
	return licz;
}

double** mno(double** m1, double** m2, int m1wierszy, int m1kolumn, int m2wierszy, int m2kolumn){

	int i, j, k;
	double suma=0;
	double** nowa;
	
	if(m1kolumn == m2wierszy){
		nowa = malloc(m1wierszy * sizeof*nowa);
		for(i=0; i<m1wierszy; ++i)nowa[i] = malloc(m2kolumn* sizeof **nowa);

		for(i=0; i<m1wierszy; ++i)
			for(j=0; j<m1kolumn; ++j){
				for(k=0; k<m1kolumn; ++k)suma += m1[i][k] * m2[k][j];
				nowa[i][j] = suma;
			}
		return nowa;
	}

	printf("z³e wymiary mno¿enie");
	return NULL;
}

double f_max(double* tab, int n){
	int i=0, tmp = tab[0];
	for(i; i<n; ++i)
		if(tab[i] > tmp)
			tmp = tab[i];
	return tmp;
}
float f_min(double* tab, int n){
	int i=0;
	float tmp = tab[0];
	for(i; i<n; ++i)
		if(tab[i] < tmp)
			tmp = tab[i];
	return tmp;
}
void bar(double* tab, int n){
	int p, i, j;
	double ma, mi, ile;
	int w[10];
	for(i=0; i<10; ++i)w[i]=0;
	scanf("%d", &p);
	ma=f_max(tab, n);
	mi = f_min(tab, n);
	ile = (ma-mi)/p;
	for(i=0; i<n; ++i)
		for(j=0; j<n; ++j)
			if(tab[i] >= mi+(j*ile) && tab[i] < mi+((j+1)*ile))
				w[j]++;
	for(i=0; i<p; ++i){
		for(j=0; j<w[i]; j++)
			printf("|");
		printf("\n");
	}
}
