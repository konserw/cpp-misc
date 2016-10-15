#include "head.h"


char* bin(int in){
	char *str;
	int reszta, n, i;//, k;
    char *ptr;
	bool neg;
	n=0;
	i=0;
	ptr = malloc(1*sizeof(char));

	if(in < 0){
		in = -in;
		neg = true;
	}
	else neg = false;

	while(1){
		reszta = in%2;
		if(reszta == 0) ptr[n] = '0';
		else{
			ptr[n] = '1';
			in--;
		}
		if(in == 0)break;
		in /= 2;
		ptr = realloc(ptr, (++n+2) * sizeof *ptr); /*n - ilosc liczb +1 na \0 +1 na znak*/
	}
	if(neg == true)	ptr[++n] = '-';
	else ptr[++n] = ' ';

	str = malloc((++n+1) * sizeof (char));
	while (n >= 0)
		str[i++] = ptr[--n];
	free(ptr);
	str[--i] = 0;
	return str;
}

int foo(int baza, char* ptr){
	int i, ile, licz=0;
	ile = strlen(ptr);
	for(i=0; i<ile; ++i){
		int tmp;
		tmp = ptr[ile-i]-'a';
	//	printf("%d ", tmp);
		licz += tmp * pow(baza, i);
	}
	return licz;
}