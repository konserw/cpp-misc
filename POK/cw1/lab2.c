#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int ok;
float oblicz(float x){
      if(x+2 < 0){
             printf("pierwiastkowana livczba mniejsza niz zero\n");
             ok = 0;
             return 0;
             }
      float mian = 3*x*x - 7*x + 2;
      if(mian == 0){
              ok = 0;
              printf("Dzielenie przez zero!\n");
              return 0;
              }
      ok = 1;
      return sqrt(x+2)/mian;
      }
int main(){
    int x[3] = {-3, 2, 7};
    int i = 0;
    for(i; i<3; ++i){
           float z = oblicz(x[i]);
           if(ok !=0) printf("x%d = %f\n", i, z);
           }
    system("pause");
    return 0;
}
                       
