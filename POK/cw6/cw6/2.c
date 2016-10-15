//#define make

#if defined make
#include "head.h"

int main(){
	float x, xk, dx;
	FILE* out;
	out = fopen("wynik.txt", "w");
	if(out == NULL){
		printf("Error!\n");
	}else{

		printf("Podaj xp, xk i dx:\t");
		scanf("%f %f %f", &x, &xk, &dx);

		for(x; x <= xk; x+=dx)
			fprintf(out, "x = %f\nx2 = %f\nx3 = %f\n\n", x, x*x, pow(x, 3));

		fclose(out);
	}
	system("pause");
	return 0;
}
#endif