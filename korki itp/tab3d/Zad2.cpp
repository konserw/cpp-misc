#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;

int sum(int*** t, int w)
{
    int s=0;

    for(int i=0; i<w; ++i)
        for(int j=0; j<w; ++j)
            for(int k=0; k<w; ++k)
                s += t[i][j][k];
    return s;
}

void del(int ***t, int X, int Y, int Z)
{
    for(int i=0; i<Y; ++i)
    {
        for(int j=0; j<Z; ++j)
            delete[] t[i][j];
        delete[] t[i];
    }
    delete[] t;
}
void nowa(int*** &t, int W)
{
    t = new int**[W];
    for(int i=0; i<W; ++i)
    {
        t[i] = new int*[W];
        for(int j=0; j<W; ++j)
            t[i][j] = new int[W];
    }
}
int*** find(int*** tab, int X, int Y, int Z, int W)
{
    int max, s;
    int ***t, ***wyn;
    int ox, oy, oz;

    nowa(t, 4);
    nowa(wyn, 4);

    for(int i=0; i<X-W; ++i)
        for(int j=0; j<Y-W; ++j)
            for(int k=0; k<Z-W; ++k)
            {
                 for(int ii=0; ii<W; ++ii)
                    for(int jj=0; jj<W; ++jj)
                        for(int kk=0; kk<W; ++kk)
                        {
                            t[ii][jj][kk] = tab[i+ii][j+jj][k+kk];
                        }
                s = sum(t, W);
                if((i == 0 && j == 0 && k == 0) || s > max)
                {
                    max = s;
                    ox = i;
                    oy = j;
                    oz = k;
                }
            }
    for(int ii=0; ii<W; ++ii)
       for(int jj=0; jj<W; ++jj)
           for(int kk=0; kk<W; ++kk)
           {
               wyn[ii][jj][kk] = tab[ox+ii][oy+jj][oz+kk];
           }
    del(t, W, W, W);
    return wyn;
}

void wyswietl(int ***t, int x, int y, int z)
{
    for(int i=0; i<x; ++i)
    {
        for(int j=0; j<y; ++j)
        {
            for(int k=0; k<z; ++k)
            {
                cout << t[i][j][k] << "\t";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }
}

int main()
{
    int X = 20, Y = 10, Z = 8, W = 3;
    int ***tab;
    int ***wyn;

    srand(time(NULL));
    tab = new int**[X];
    for(int i=0; i<X; ++i)
    {
        tab[i] = new int*[Y];
        for(int j=0; j<Y; ++j)
        {
            tab[i][j] = new int[Z];
            for(int k=0; k<Z; ++k)
                tab[i][j][k] = (rand()%201) - 100;
        }
    }
    cout << "Macierz z wylosowanymi liczbami:\n\n";
    wyswietl(tab, X, Y, Z);

    wyn = find(tab, X, Y, Z, W);
        cout << "\n\nWynik poszukiwania:\n"
        << "suma wynosi:\t" << sum(wyn, W) << "\n"
        << "Podmacierz natomiast:\n";
    wyswietl(wyn, W, W, W);

    del(tab, X, Y, Z);
    del(wyn, W, W, W);
    return 0;
}
