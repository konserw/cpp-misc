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
Zaimplementuj funkcj� realizuj�c� dzia�anie strcpy
2) Zaimplementuj funkcj� realizuj�c� dzia�anie strlen
3) Zaimplementuj funkcj� realizuj�c� dzia�anie strcmp
4) Zaimplementuj funkcj� realizuj�c� dzia�anie strcat

5) Zaimplementuj funkcj� realizuj�c� dzia�anie myIsupper (sprawdzenie, czy litera jest du�a)
6) Zaimplementuj funkcj� realizuj�c� dzia�anie myIsdigit(sprawdzenie, czy znak jest cyfr�)
7) Zaimplementuj funkcj� realizuj�c� dzia�anie myToupper (zamiana litery na odpowiadaj�c� jej du�� liter�)

8) Zaimplementuj funkcj� realizuj�c� dzia�anie pow (pot�ga)
9) Zaimplementuj funkcj� realizuj�c� dzia�anie floor (cecha)
10) Zaimplementuj funkcj� realizuj�c� dzia�anie ceil (najmniejsza liczba ca�kowita wi�ksza lub r�wna argumentowi)

11) Zaimplementuj funkcj� realizuj�c� dzia�anie mod (reszta z dzielenia)
12) Zaimplementuj funkcj� realizuj�c� dzia�anie abs (warto?� bezwzgl�dna)
13) Zaimplementuj funkcj� realizuj�c� czyszczenie ekranu
14) Zaimplementuj funkcj� obliczaj�c� pole trapezu o zadanych d�ugo?ciach podstaw i wysoko?ci

15) Zaimplementuj funkcj� obliczaj�c� obj�to?� walca o zadanym promieniu podstawy i wysoko?ci
16) Zaimplementuj funkcj� obliczaj�c� pole powierzchni sfery o zadanym promieniu
17) Zaimplementuj funkcj� obliczaj�c� tangens zadanego k�ta

18) Zaimplementuj funkcj� wy?wietlaj�c� na ekran zawarto?� pliku wskazanego w parametrze
19) Zaimplementuj funkcj� sprawdzaj�c� czy podana macierz kwadratowa jest diagonalna 
20) Zaimplementuj funkcj� dodaj�c� macierze dwuwymiarowe

21) Zaimplementuj funkcj� zapisuj�c� do pliku wskazanego w pierwszym parametrze zawarto?� drugiego parametru
22) Zaimplementuj funkcj� zamieniaj�c� warto?ci dw�ch przekazanych przez referencj� argument�w
23) Zaimplementuj funkcj� zwracaj�c� warto?� mniejszego z dw�ch parametr�w liczbowych

24) Zaimplementuj funkcj� zwracaj�c� warto?� zmiennej ?rodowiskowej wskazanej w parametrze
25) Zaimplementuj funkcj� zwracaj�c� warto?� odleg�o?ci euklidesowej mi�dzy punktami o wsp�rz�dnych przekazanych w parametrach

*/