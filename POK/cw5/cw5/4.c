//#define make

#if defined make
#include "head.h"

int main(){
	int n, tab[30], i, buff, nn;
	scanf("%d", &n);
	nn = n;

	for(i=0; i<n; ++i)scanf("%d", &tab[i]);
	i=0;
	printf("\n");
	for(;;){
		--n;
		//printf("%d\t%d\n", tab[i], tab[n]);
		//getchar();
		if(n <= i)break;
		buff = tab[i];
		tab[i] = tab[n];
		tab[n] = buff;
		++i;
			
	}

	for(i=0; i<nn; i++)printf("%d ", tab[i]);
	printf("\n\n");

	system("pause");
	return 0;
}
#endif