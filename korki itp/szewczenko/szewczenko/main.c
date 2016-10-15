#include "head.h"

int main(){
	int i=-1;
	char s1[100], s2[100];
	double a, b;
	long c, d;

	while(1){
		puts("Wybierz funkcje:\n"
			"0: EXIT\n"
			"1: strcpy\n"
			"2: strcmp /nie ma\n"
			"3: strcat /nie ma\n"
			"4: strlen\n"
			"5: myIsupper\n"
			"6: myIsdigit\n"
			"7: myToupper\n"
			"8: pow\n"
			"9: floor\n"
			"10: ceil\n"
			"11: mod\n"
			"12: abs\n"
			"13: clr\n"
			"14: trapez\n");
		scanf_s("%i", &i);
		switch(i){
			case 0:
				break;
			case 1:
				puts("Wprowadz napis (max 99 znakow)\n");
				gets_s(s1, 100);
				myStrcpy(s1, s2);
				puts("oto skopiowany napis:\n");
				puts(s2);
				break;
			case 2:
//int myStrcmp(char* src, char* dest);
				break;
			case 3:
//void myStrcat(char* src, char* dest);
				break;

			default:
				puts("wprowadzono zly numer!\n");
				break;
		}
		if(i == 0)break;
		system("pause");
		clr();
	}

/*

unsigned long myStrlen(char* src);

BOOL myIsupper(char c);
BOOL myIsdigit(char c);
char myToupper(char c);

long myPow(long pod, long wykl);
long myFloor(double d);
long myCeil(double d);

//long myMod(long liczba, long div);
unsigned long myAbs(long l);
void clr();
double trapez(double a, double b, double h);
*/
	return 0;
}