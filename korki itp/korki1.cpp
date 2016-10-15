#include <cstdio>
#include <cstdlib>

int main ()
{
    const int szerokosc=25;
    const int wysokosc=10;
    int x=0, y=0;
    char c;

while(1)
{
for(int i=0; i<30 ; i++)
    {
        printf("\n");
    }

    for (int i=0 ; i<szerokosc ; i++)
    {
        printf("#");

    }
    printf("\n");
//    serokosc=30;
    for (int i=0 ; i<wysokosc ; i++ )
    {
     /*    if(i==y)
        {
           printf("#");
            for(int j=0 ; j<x ; j++)
            {
                printf(" ");
            }
            printf("*");
            for(int j=0 ; j<szerokosc-3-x; j++)
            {
                printf(" ");
            }
            */
            for(int j=-1; j<szerokosc-1; j++)
            {
                if(j==-1 || j==szerokosc-2)c='#';
                else if(j==x && i == y)c='*';
                else c=' ';
                printf("%c", c);
            }
            printf("\n");

        }
  /*      else
        {
            printf("#");
            for(int j=0 ; j<(szerokosc-2) ; j++)
            {
                printf(" ");
            }
            printf("#\n");
        }
   }
*/
    for (int i=0 ; i<szerokosc ; i++)
    {
        printf("#");

    }
if(x<szerokosc-2)
{
    if(y==0)x++;
    else if(y==wysokosc-1)x--;

}
if(y>=0 && y<=wysokosc-1)
{
    if(x==0)y--;
    else if(x==szerokosc-3)y++;
}

getchar();
}
    return 0;
}
