#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    long* h;
    long n, x, p, pmin, imin, i, j, hi;

    scanf("%ld", &n);
    h = (long*) malloc(n*sizeof(long));

    for(i=0; i<n; ++i)
        scanf("%ld", &h[i]);

    for(i=0; i<n; ++i)
    {
        p = 1;
        j=0;
        hi = h[i];
        while(j<n)
        {
            if(hi+p-sqrt(abs(i-j)) < h[j])
                p++;
            else j++;
        }
        printf("%ld\n", p);
    }
    free(h);
    return 0;
}
