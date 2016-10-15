#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

int main(){
    //char e;
   // do{
         float y, a, b;
        printf("Program wyznaczajacy miejsce zerowe funkcji liniowej y = ax + b\n"
                    "Podaj a oraz b:\t");
        scanf("%f %f", &a, &b);
        if(a == 0)
             printf("Funkcja nie posiada miejsc zerowych\n");
        else{
             y = -b/a;
            printf("Miejsce zerowe = %f\n", y);
            }
    //  printf("Wyjsc? [T/N]\t");
  //     scanf("%c", &e);
   //}while(&e == "n" || e == "N");//wkaünik!?
   return 0;
}
