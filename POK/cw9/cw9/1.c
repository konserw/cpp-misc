//#define TAK
#if defined TAK
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct PKT{
	float x;
	float y;
};
typedef struct PKT pkt;

pkt wierzcholek(float a, float b, float c);

int main(){
	pkt w;
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	w = wierzcholek(a, b, c);
	printf("\n%f %f\n", w.x, w.y);

	system("pause");
	return 0;
}

pkt wierzcholek(float a, float b, float c){
	pkt w;
	w.x = -b/(2*a);
	w.y = -(b*b-4*a*c)/(4*a);
	return w;
}
#endif