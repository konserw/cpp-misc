//#define make

#if defined make
#include "head.h"

struct pkt{
	double x;
	double y;
};
struct circle{
	struct pkt s;
	double r;
};
struct sqr{
	struct pkt a;
	struct pkt b;
};
double d(struct pkt a, struct pkt b){
	return sqrt(pow(a.x+b.x, 2)+pow(a.y+b.y, 2));
};

int main(){

	struct pkt a, b;
	struct circle kolo;
	struct sqr kwadrat;

	printf("Podaj namiary na 2 pkty:\t");
	scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y);
	printf("Odleglosc miedzy pktami wynosi:\t%lf\n", d(a, b));

	printf("Podaj namiary na srodek okregu i jego promien:\t");
	scanf("%lf %lf %lf", &kolo.s.x, &kolo.s.y, &kolo.r);
	printf("Pole kola wynosi:\t%lf\n", M_PI*pow(kolo.r, 2));

	printf("Podaj namiary na konce przekatnej kwadratu:\t");
	scanf("%lf %lf %lf %lf", &kwadrat.a.x, &kwadrat.a.y, &kwadrat.b.x, &kwadrat.b.y);
	printf("Pole kwadratu wynosi:\t%lf\n", pow(d(kwadrat.a,kwadrat.b), 2)/2);
	
	system("pause");
	return 0;
}
#endif