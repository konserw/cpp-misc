//#define TAK
#if defined TAK
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int licz(char*, char*);

int main(){
	char s1[255], s2[255];
	int ile;
	gets(s1);
	gets(s2);
	ile=licz(s1, s2);
	printf("%d\n", ile);

	system("pause");
	return 0;
}

int licz(char* s1, char* s2){
	int c=0;
	char *p;
	while( (p = strstr(s1, s2)) != NULL){
		++c;
		if(*p != ' ')*p = ' ';
		else *p = 'a';
	}

	return c;
}

#endif