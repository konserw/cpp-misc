//#define make

#if defined make
#include "head.h"

int main(){
	char wej[1024];
	char wyj[1024];
	unsigned i, j=0;
	char spacja = ' ';
	//scanf("%s1023", wej);
	//gets(wej);
	fgets(wej, sizeof wej, stdin);
	for(i=0; i<1024; ++i){
		if(wej[i] == spacja)continue;
		else if(wej[i] == '\0'){
			wyj[j] = '\0';
			break;
		}
		else wyj[j++] = wej[i];
	}
	printf("\n\n%s\n\n", wyj);
	
	system("pause");
	return 0;
}
#endif