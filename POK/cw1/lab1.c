#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float oblicz(float x){
      float a = (1.0/3 + sin(x/2.0))*(pow(x, 3)+3);
      if( a >= 0) return pow(a, 1.0/3);
      else{
           a = fabs(a);
           a = - pow(a, 1.0/3);
           return a;
           }
};
            
int main(){
    float y;
    /*const float b=7.5;
    printf("Podaj c:\t");
    scanf("%f", &c);*/
    y = oblicz(5);
    printf("%f\n", y);
    y = oblicz(10);
    printf("%f\n", y);
    system("pause");
    return 0;
}
