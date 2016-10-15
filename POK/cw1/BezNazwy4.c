#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mvprintw(int a, int b, const char* ch){
     /*printf(ch);*/
     printf("%s\n", ch);
     }

int main(){
    float tablica[6];
    float W, wx, wy;
    
	printf("Szukanie pierwiastkow trojmianu kwadratowego postaci ax^2 + bx + c = 0\n");
	printf("Podaj wartosci a, b, c:\t");

	scanf("%f %f %f", &tablica[0], &tablica[1], &tablica[2]);
	double delta = pow(tablica[1],2)-(4*tablica[0]*tablica[2]);
	if (delta <= 0){
		if (delta == 0){
			double x0 = -tablica[1] /(2*tablica[0]);
			printf("x0 = %lf\n", x0);
		}
		else printf("Dane rownanie nie posiada rozwiazan!\n");
	}
	else{
		long double x1, x2;
		x1 = (-tablica[1] + sqrt(delta))/(2*tablica[0]);
		x2 = (-tablica[1] - sqrt(delta))/(2*tablica[0]);
		printf("x1 = %lf \t\t x2 = %lf\n", x1, x2);
	}

	mvprintw(11, 10, "Wybrales rozwiazywanie ukladu 2 rownan I stopnia z 2 niewiadomymi.");
	mvprintw(12, 10, " ax + by = c");
	mvprintw(13, 10, " dx + ey = f");
	mvprintw(14, 10, "Podaj a, b, c, d, e i f");
	scanf("%f %f %f %f %f %f", &tablica[0], &tablica[1], &tablica[2], &tablica[3], &tablica[4], &tablica[5]);

	W=(tablica[0]*tablica[4])-(tablica[1]*tablica[3]);
	wx=(tablica[2]*tablica[4])-(tablica[1]*tablica[5]);
	wy=(tablica[0]*tablica[5])-(tablica[2]*tablica[4]);
	
	if (W == 0){
    	if (wx == 0 && wy == 0)
    		mvprintw(16, 10, "Dany uklad rowan jest nieoznaczony (posiada nieskonczenie wiele rozwiazan).");
    	else
	    	mvprintw(16, 10, "Dany uklad rowan jest sprzeczny (nie posiada rozwiazan).");
         }
	else{
		mvprintw(16, 10, "Rozwiazaniem tego ukladu rownan sa liczby:");
		printf("x = %lf \t\t y = %lf\n", wx/W, wy/W);
    }
    system("pause");
    return 0;
	}
