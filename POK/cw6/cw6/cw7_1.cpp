#define make

#if defined make
#include "head.h"
  
int main()  {  

	FILE* in;
	FILE* out;
	FILE* nd;
	double x=0, o=0, tmp;
	int n=0, p1=0, p2=0, p3=0;
	in = fopen("dane.txt", "r");
	out = fopen("raport.txt", "wt");
	nd = fopen("ndane.txt", "wt");
	if(in == NULL || out == NULL || nd==NULL){
		printf("Error!\n");
		system("pause");
		return 0;
	}
	while(fscanf(in, "%lf", &tmp) == 1){
		n++;
		x+=tmp;
	}

	x/=n;
	fseek(in, 0, 0);
	while(fscanf(in, "%lf", &tmp) == 1)
		o+=pow(x-tmp, 2);

	o /= n-1;
	o = sqrt(o);

	fseek(in, 0, 0);

	while(fscanf(in, "%lf", &tmp) == 1){
		if(tmp >= x-o && tmp <= x+o){
			fprintf(nd, "%lf\n", tmp);
 			p1++;
		}
		if(tmp >= x-(2*o) && tmp <= x+(2*o))
			p2++;
		if(tmp >= x-(3*o) && tmp <= x+(3*o))
			p3++;
	}

	fprintf(out, "srednia:\t%lf\nodchylenie:\t%lf\np1:\t%d\np2:\t%d\np3:\t%d\n\n", x, o, p1, p2, p3);
	printf("srednia:\t%lf\nodchylenie:\t%lf\np1:\t%d\np2:\t%d\np3:\t%d\n\n", x, o, p1, p2, p3);
	system("pause");
	return 0;
	}

#endif