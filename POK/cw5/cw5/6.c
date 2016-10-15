//#define make

#define true 0
#define false 1
#define bool short

#if defined make
#include "head.h"

int main(){
	int** tab;
	int n, i, j;
	bool a=true,//symetryczna
		b=true,//diagonalna
		c=true;//górnotrójk¹tna
	scanf("%d", &n);
	tab = malloc(n * sizeof *tab); 
	for (i = 0; i<n; ++i) {
		tab[i] = malloc(n * sizeof **tab);
	}
	for(i=0; i<n; ++i)
		for(j=0; j<n; ++j)scanf("%d", &tab[i][j]);

	for(i=0; i<n; ++i)
		for(j=0; j<n; ++j){
			if(a==true)//jak nie to nie ma sensu sprawdzac dalej
				if(!(tab[i][j] == tab[j][i])) a=false;

			if(i<j && c==true)//górno trójk¹tna
				if(tab[i][j] != 0) c=false;

			if(a!=true && c!=true) b=false;//tylko symetryczna moze byc diagonalna, musi tez byc trojkatna
			if(b == true && i != j)//nie sprawdzamy przekatnej
					if(tab[i][j] != 0) b=false;
			

		}

	printf("\n\na:\t%d\nb:\t%d\nc:\t%d\n", a, b, c);




	for (i = 0; i<n; ++i) {
		free(tab[i]);
	}
	free(tab);

	//system("pause");
	return 0;
}
#endif