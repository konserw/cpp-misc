#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    //a:
    float a, c, x, y, z;
    const float b = 7.5;
    printf("Podaj c:\t");
    scanf("%f", &c);
    a = sqrt((c*c)+(b*b));
    printf("a = %f\n", a);
    //b:


    //c:
    y = pow(((1/3) + sin(x/2))*(pow(x, 3) + 3) ,1/3);
    
    //d:
    z = sqrt(x + 2)/((3*pow(x, 2)) - (7 * x) + 2);
    
    return 0;
}
