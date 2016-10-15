//#define make

#if defined make
#include "head.h"
  
int main()  
{  
   FILE *in;     
   float min, max,  temp;
   int n, nprzedzialu, i, a[10];  
     float rozmiar ;

   in = fopen("dane.txt", "r");  
     
   fscanf(in, "%f", &temp);  
   min = temp;  
   max = temp;     
     
   scanf("%d", &n);  
     
   while (fscanf(in, "%f", &temp) == 1)  
   {  
      if (temp < min)  
         min = temp;  
      if (temp > max)  
         max = temp;           
   }  
     
	rozmiar = (max - min) / (float)n;  
  
   fseek(in, 0, 0);  
     
 
   for (i = 0; i < 10; i++)  
      a[i] = 0;  
        
 
   while (fscanf(in, "%f", &temp) == 1)  
   {  
      if (temp == max)  
         nprzedzialu = n - 1;  
      else  
         nprzedzialu = (temp - min) / rozmiar;  
      a[nprzedzialu]++;        
   }  
     
   for (i=0; i < n-1; i++)  
      printf("<%f; %f): %d\n", min+i*rozmiar, min+(i+1)*rozmiar, a[i]);     
   printf("<%f; %f>: %d\n", min+i*rozmiar, min+(i+1)*rozmiar, a[i]);     
   system("PAUSE");  
     
   return 0;     
} 
#endif