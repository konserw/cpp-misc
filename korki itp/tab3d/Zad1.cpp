#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;

const int X = 20, Y = 10, Z = 8, W = 3;
//int tab[X][Y][Z];
//int wyn[W][W][W];
int*** tab;
int*** wyn;


int sum(int*** t)
{
    int s=0;

    for(int i=0; i<W; ++i)
        for(int j=0; j<W; ++j)
            for(int k=0; k<W; ++k)
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
void nowa(int*** &t, int w)
{
    t = new int**[W];
    for(int i=0; i<W; ++i)
    {
        t[i] = new int*[W];
        for(int j=0; j<W; ++j)
            t[i][j] = new int[W];
    }
}

void find()
{
    int max, s;
   // int t[W][W][W];
    int ox, oy, oz;
    int*** t;

    nowa(t, W);//alokacja pamieci
    nowa(wyn, W);

    for(int i=0; i<X-W; ++i)//te 3 petle szukają "rogu" naszej macierzy 3x3
        for(int j=0; j<Y-W; ++j)
            for(int k=0; k<Z-W; ++k)
            {
                 for(int ii=0; ii<W; ++ii)//te 3 pętle kopiują elementy od "rogu" w każdą stronę po 3 elementy, czyli tworzą naszą tablicę 3x3
                    for(int jj=0; jj<W; ++jj)
                        for(int kk=0; kk<W; ++kk)
                        {
                            t[ii][jj][kk] = tab[i+ii][j+jj][k+kk];
                        }
                s = sum(t);//do s zapisujemy sume elementów tab. 3x3
                if((i == 0 && j == 0 && k == 0) || s > max)//jeżeli to pierwszy przebiueg petli, albo suma jest większa od aktualnego max, to:
                {
                    max = s;//ustawiamy max na sume
                    ox = i;//zapisujemy "wspolrzedne rogu
                    oy = j;
                    oz = k;
                }
            }

    for(int ii=0; ii<W; ++ii)//przepisujemy do wynikowej tablicy te maxymalna, czyli ta zaczynajaca sie od rogu ox, oy, oz
       for(int jj=0; jj<W; ++jj)
           for(int kk=0; kk<W; ++kk)
           {
               wyn[ii][jj][kk] = tab[ox+ii][oy+jj][oz+kk];
           }
    del(t, W, W, W);//usuniecie tab. tymczasowej
}


int main()
{
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
    //losowanie i wyświetlenie
    srand(time(NULL));
    for(int i=0; i<X; ++i)
        for(int j=0; j<Y; ++j)
            for(int k=0; k<Z; ++k)
                tab[i][j][k] = (rand()%201) - 100;

    cout << "Macierz z wylosowanymi liczbami:\n\n";
    for(int i=0; i<X; ++i)
    {
        for(int j=0; j<Y; ++j)
        {
            for(int k=0; k<Z; ++k)
            {
                cout << "tab[" << i << "][" << j << "][" << k << "] = " << tab[i][j][k] << "\n";
            }
//            cout << "\n";
        }
//        cout << "\n\n";
    }

    find();
    cout << "\n\nWynik poszukiwania:\n"
        << "suma wynosi:\t" << sum(wyn) << "\n"
        << "Podmacierz natomiast:\n";
    for(int i=0; i<W; ++i)
    {
        for(int j=0; j<W; ++j)
        {
            for(int k=0; k<W; ++k)
            {
                cout << "tab[" << i << "][" << j << "][" << k << "] = " << wyn[i][j][k] << "\n";
  //              cout << wyn[i][j][k] << "\t";
            }
    //        cout << "\n";
        }
      //  cout << "\n\n";
    }


    del(tab, X, Y, Z);
    del(wyn, W, W, W);
    return 0;
}
