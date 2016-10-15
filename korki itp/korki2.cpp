#include <cstdio>

 int main()
 {
     const int wysokosc=5;
     const int szerokosc=(wysokosc-1)*2+1;
     const int ile=1;
     int przesypalo=0;
     int x;
     const int wszystkie=wysokosc*(1.0+szerokosc)/2.0;
   //  printf("%d", wszystkie);

while(przesypalo<=wszystkie)
{
    x=0;
    for(int i=0; i<30 ; i++)
    {
        printf("\n");
    }

     for(int i=0; i<wysokosc; i++)
     {
         for(int j=0; j<i+1; j++)
         {
             printf(" ");
         }
         for(int j=0; j<szerokosc-(2*i) ; j++)
         {
             if(x<przesypalo)
             {
                 printf(".");
                 x++;
             }else printf("#");
         }
         printf("\n");
     }
     x=wszystkie-1;
     for(int i=wysokosc-1 ; i>=0; i--)
     {
         for(int j=0; j<i+1; j++)
         {
             printf(" ");
         }
         for(int j=0; j<szerokosc-(2*i) ; j++)
         {
             if(x<przesypalo)
             {
                 printf("#");

             }else
             {
                 printf(".");
                 x--;
             }
         }
         printf("\n");
     }
     przesypalo+=ile;
     getchar();
}
     return 0;

 }
