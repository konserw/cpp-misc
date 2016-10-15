#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
/*#define M_E		2.7182818284590452354 */

int main(){
    float x;
    float f[4];
    printf("Podaj x:\t");
    scanf("%f", &x);

	if(x < 0) f[1] = sqrt(fabs(2+x));
    else if(x==0) f[1] = 2;
    else if(x > 0) f[1] = pow(x, 2) + pow(M_E, 2*x);

	if(x <= -5)f[2] = (2*x) + (10.0/3);
	else if(x < 7) f[2] = sqrt(fabs(x)) + pow(M_E, (x/2.0)+1);
	else{
		float tmp = sin(2*x)+pow(x, 2);
		if(tmp < 0){
			tmp = fabs(tmp);
			f[2] = -pow(tmp, 1/3.0);
		}
		else f[2] = pow(tmp, 1/3.0);
}

	if(x >= 1 && x <= 7) f[3] = pow((2*x) + (1.0/4), 1.0/4);
	else f[3] = cos(pow(M_E, 2*x));
    
    
    
    
    printf("f1 = %f\nf2 = %f\nf3 = %f\n", f[1], f[2], f[3]);
    system("pause");
    return 0;
}
