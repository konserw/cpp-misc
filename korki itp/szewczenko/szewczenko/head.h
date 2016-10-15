#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define BOOL short int
#define TRUE 1
#define FALSE 0

//#define _CRT_SECURE_NO_WARNINGS

void myStrcpy(char* src, char* dest);
//int myStrcmp(char* src, char* dest);
//void myStrcat(char* src, char* dest);
unsigned long myStrlen(char* src);

BOOL myIsupper(char c);
BOOL myIsdigit(char c);
char myToupper(char c);

long myPow(long pod, long wykl);
long myFloor(double d);
long myCeil(double d);

long myMod(long liczba, long div);
unsigned long myAbs(long l);
void clr();
double trapez(double a, double b, double h);


/*
Zaimplementuj funkcjê realizujšcš dzia³anie strcpy
2) Zaimplementuj funkcjê realizujšcš dzia³anie strlen
3) Zaimplementuj funkcjê realizujšcš dzia³anie strcmp
4) Zaimplementuj funkcjê realizujšcš dzia³anie strcat

5) Zaimplementuj funkcjê realizujšcš dzia³anie myIsupper (sprawdzenie, czy litera jest du¿a)
6) Zaimplementuj funkcjê realizujšcš dzia³anie myIsdigit(sprawdzenie, czy znak jest cyfrš)
7) Zaimplementuj funkcjê realizujšcš dzia³anie myToupper (zamiana litery na odpowiadajšcš jej du¿š literê)

8) Zaimplementuj funkcjê realizujšcš dzia³anie pow (potêga)
9) Zaimplementuj funkcjê realizujšcš dzia³anie floor (cecha)
10) Zaimplementuj funkcjê realizujšcš dzia³anie ceil (najmniejsza liczba ca³kowita wiêksza lub równa argumentowi)

11) Zaimplementuj funkcjê realizujšcš dzia³anie mod (reszta z dzielenia)
12) Zaimplementuj funkcjê realizujšcš dzia³anie abs (warto?æ bezwzglêdna)
13) Zaimplementuj funkcjê realizujšcš czyszczenie ekranu
14) Zaimplementuj funkcjê obliczajšcš pole trapezu o zadanych d³ugo?ciach podstaw i wysoko?ci

15) Zaimplementuj funkcjê obliczajšcš objêto?æ walca o zadanym promieniu podstawy i wysoko?ci
16) Zaimplementuj funkcjê obliczajšcš pole powierzchni sfery o zadanym promieniu
17) Zaimplementuj funkcjê obliczajšcš tangens zadanego kšta

18) Zaimplementuj funkcjê wy?wietlajšcš na ekran zawarto?æ pliku wskazanego w parametrze
19) Zaimplementuj funkcjê sprawdzajšcš czy podana macierz kwadratowa jest diagonalna 
20) Zaimplementuj funkcjê dodajšcš macierze dwuwymiarowe

21) Zaimplementuj funkcjê zapisujšcš do pliku wskazanego w pierwszym parametrze zawarto?æ drugiego parametru
22) Zaimplementuj funkcjê zamieniajšcš warto?ci dwóch przekazanych przez referencjê argumentów
23) Zaimplementuj funkcjê zwracajšcš warto?æ mniejszego z dwóch parametrów liczbowych

24) Zaimplementuj funkcjê zwracajšcš warto?æ zmiennej ?rodowiskowej wskazanej w parametrze
25) Zaimplementuj funkcjê zwracajšcš warto?æ odleg³o?ci euklidesowej miêdzy punktami o wspó³rzêdnych przekazanych w parametrach

*/