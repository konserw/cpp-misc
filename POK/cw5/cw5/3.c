//#define make

#if defined make
#include "head.h"

int main(){
	int tab[20], i, min, gdzie;

	for(i=0; i<20; ++i){
		scanf("%d", &tab[i]); 
		if(i==0){
			min = tab[0];
			gdzie = 0;
		}
		else if(tab[i] < min){
			min = tab[i];
			gdzie = i;
		}
	}
	printf("\n\nMinimalna wartosc: %d na miejscu %d\n", min, gdzie+1);

	system("pause");
	return 0;
}
#endif