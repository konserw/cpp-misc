//#define make

#if defined make
#include "head.h"

int main(){
	int ile, min, max, i;
	double ran;
	FILE* out;
	out = fopen("dane.txt", "w");
	if(out == NULL){
		printf("Error!\n");
	}else{
		srand(time(NULL));
		scanf("%d %d %d", &min, &max, &ile);
		for(i=0; i<ile; ++i){
			ran = rand()%((max-min)*1000);
			ran = (double)(ran/1000.0);
			ran += min;
			fprintf(out, "%lf\n", ran);
		}
	}	
	system("pause");
	return 0;
}
#endif