//#define make

#if defined make
#include "head.h"

double funkcja (double x, double krok){
	double y;
	
	if (x<0) return (pow(x, 3)+ pow(x, -1));
	else if (x < 0 + krok/2 && x > 0 - krok/2) return 3*pow(2, 0.5);
	else{
		y=sin(sqrt(x)); 
		if (y<0) return (-pow(fabs(y), 1.0/3.0));
		else return pow(y, 1.0/3.0);
	}
}

int main (){
	double poczatek, koniec, krok, x, y, max, suma, counter;

	printf("Podaj poczatek przedzialu\t");
	scanf("%lf", &poczatek);
	printf("Podaj koniec przedzialu\t");
	scanf("%lf", &koniec);
	printf("Podaj krok zmiany\t");
	scanf("%lf", &krok);
	
	counter = 0;
	suma = 0;
	x = poczatek;
	for (x; x <= koniec; x += krok){
		y = funkcja(x, krok);
		if(counter == 0)max = y;
		counter++;
		suma += y;
		if(y > max)max = y;
		printf("%lf\t", y);
	}
	printf("\nSrednia: %lf\tmax: %lf\n\n", suma/counter, max);
	system("PAUSE");
	return 0;
}
#endif