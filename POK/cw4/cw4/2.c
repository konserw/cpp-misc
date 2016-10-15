#define make
#if defined make
#define c


#include "head.h"

int main(){
	short jedynki = 0;
	int i, tmp, xa, xb, xc;
#if defined a
	for(i=0; ;++i){
		scanf("%d", &tmp);
		if(tmp == 1)jedynki++;
		if(jedynki == 3)break;
	}
#endif
#if defined b
	i = 0;
	for(;;){
		jedynki = 0;
		++i;
		scanf("%d", &tmp);
		while(tmp == 1){
			++i;
			jedynki++;
			if(jedynki == 3)break;
			scanf("%d", &tmp);
		}
		if(jedynki == 3)break;
	}
#endif
#if defined c
	printf("podaj sekwencje liczb (rozdziel spacjami):\t");
	scanf("%d %d %d", &xa, &xb, &xc);
	i = -1;
	for(;;){
		scanf("%d", &tmp);
		++i;
		if(tmp == xa){
			scanf("%d", &tmp);
			++i;
			if(tmp == xb){
				scanf("%d", &tmp);
				++i;
				if(tmp == xc)break;
			}
		}
	}
#endif

	printf("liczb:\t%d\n", i);
	system("pause");
	return 0;
}
#endif
