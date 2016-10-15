#include "head.h"

void myStrcpy(char* src, char* dest){
	char* i = src;
	char* j = dest;
	while(*i != 0){
		*j = *i;
		i++;
		j++;
	}
	j++;
	*j = 0;
}
unsigned long myStrlen(char* src){
	char* i = src;
	unsigned long l = 0;
	while(i != 0)l++;
	return l;
}

BOOL myIsupper(char c){
	if(c >= 'A' && c <= 'Z')return TRUE;
	return FALSE;
}
BOOL myIsdigit(char c){
	if(c >= '0' && c <= '9')return TRUE;
	return FALSE;
}
char myToupper(char c){
	int r = 'A' - 'a';
	if(!myIsupper(c)){
		c += r;
	}
	return c;
}
long myPow(long pod, long wykl){
	long y=1;  //zmienna, która stanowiæ bêdzie wynik potêgowania
	while(pod != 0){ 
		if(myMod(wykl, 2)==1) y=y*pod; 
		wykl=wykl/2;
		pod=pod*pod;
	}
	return y;
}

long myFloor(double d){
	long i = 0;
	if(d >= 0){
		while(i <= d)i++;
	}else{
		while(i >= d)i--;
	}
	return i;	
}
long myCeil(double d){
	if(d  == 0)return 0;
	else if(d > 0)return myFloor(d)+1;
	else return myFloor(d)-1;
}
long myMod(long liczba, long div){
	return 1;
}
unsigned long myAbs(long l){
	if(l <= 0)return -l;
	return l;
}
void clr(){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD s = GetLargestConsoleWindowSize(h);
	COORD poz = {0,0};
	DWORD nn;
	FillConsoleOutputCharacter(h, ' ', s.X*s.Y, poz, &nn);
	SetConsoleCursorPosition(h, poz);       
}
double trapez(double a, double b, double h){
	return (a+b)*h/2;
}