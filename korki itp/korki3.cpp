#include <stdio.h>

typedef struct //struktura reprezentująca warzywo, ewentualnie owoc ;)
{
    char nazwa[16];
    float cena;
} warzywo;

typedef struct //struktura reprezentująca pozycję na rachunku
{
    warzywo* w; //wskaźnik na warzywo którego dotyczy pozycja
    float waga;
    float wartosc;// = w->cena*waga;

} pozycja;

int main()
{
    const int maxPozycji = 15;
    pozycja pozycje[maxPozycji];
    int iloscPozycji = 0, wybor;
    float razem, waga;
    bool run = true;
//    inicjacja warzyw
    const int iloscWarzyw = 5;
    warzywo warzywa[iloscWarzyw] =
    {
        {
            "Marchew",
            1.25
        },
        {
            "Kapusta",
            0.75
        },
        {
            "Jablka",
            2.50
        },
        {
            "Kalafior",
            1.10
        },
        {
            "Szparagi",
            10.50
        }
    };

    while(run)
    {
        if(iloscPozycji >= maxPozycji) // Jeśli paragon ma 15 pozycji, przystepujemy do wypisania paragonu.1
        {
            wybor=3;
            printf("Przekroczono limit pamieci dla paragonu, nastapi jego wydrukowanie\n");
        }
        else
        {
            printf("(Menu)\n"
                "1) Dodaj towar\n"
                "2) Usun ostatni\n"
                "3) Drukuj paragon\n"
                "4) Wyjdz\n");
                //"Wybor: ");
            scanf("%d",&wybor);
        }

        switch(wybor)
        {
        case 1: // Jesli wybrales Dodanie towaru
            printf("(Menu towarow)\n");
            for(int i=0; i<iloscWarzyw; ++i)
                printf("%d:\t%s - %.2f\n", i+1, warzywa[i].nazwa, warzywa[i].cena);
            scanf("%d",&wybor);
            if(wybor <= 0 || wybor > iloscWarzyw) // jesli wybierzesz zly numer produktu, to wywalamy z pętli
            {
                printf("Niepoprawny numer towaru!\n");
                break;
            }
            printf("Waga: ");
            scanf("%f",&waga);

            //zapisanie wybranego warzywa i wagi oraz ceny do pamieci
            pozycje[iloscPozycji].w = &warzywa[wybor-1];
            pozycje[iloscPozycji].waga = waga;
            pozycje[iloscPozycji].wartosc = waga*warzywa[wybor-1].cena;

            printf("Dodano!\n\n");
            iloscPozycji++; // dodałem kolejną pozycję, więc ilość się zwiększa o 1.
            break;
        case 2: // jeśli wybrałeś usuwanie
            if(iloscPozycji)
            {
                iloscPozycji--;
                printf("Usunieto!\n\n");
            }
            else printf("Brak towarow na paragonie!\n\n");
            break;
        case 3://druk paragonu
            if(iloscPozycji == 0)
            {
                printf("Brak towarow na paragonie!\n\n");
                break;
            }

            printf("\n\n===== PARAGON ===========================\n");
            printf("Lp Towar\t| Waga | Cena   | Wartosc\n");

            for(int i=0; i<iloscPozycji; ++i)
            {
                printf("%d) %s\t| %4.1f | %.2fzl | %.2lfzl\n", i+1, pozycje[i].w->nazwa, pozycje[i].waga, pozycje[i].w->cena, pozycje[i].wartosc);
            }
            printf("==========================================\n\n");

            iloscPozycji = 0;
            break;
        case 4:
            run = false;
            break;
        default:
            printf("Wybrano niedozwolona operacje!\n");
        }
    }

    return 0;
}
