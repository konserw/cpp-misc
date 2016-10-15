//#define make

#if defined make
#include "head.h"

struct pkt{
	double x;
	double y;
};

double d(struct pkt a, struct pkt b){
	return sqrt(pow(a.x+b.x, 2)+pow(a.y+b.y, 2));
};

struct vec{
	struct pkt a;
	struct pkt b;
	double dlugosc;
};

int main(){
	FILE* pierwszy;
	FILE* drugi;
	int ile[2]={-1,-1};
	struct vec* wec[2];
	/*struct vec* wec1;
	struct vec* wec2;*/
	struct vec wektory;
	int i, j, ktory, powt, dr;

	/*wec1 = malloc(sizeof *wec1);
	wec2 = malloc(sizeof *wec2);
	*/
	wec[0] = malloc(sizeof *wec[0]);
	wec[1] = malloc(sizeof *wec[1]);

	for(i=0; i<2; ++i){
		while(fscanf(drugi, "%lf %lf %lf %lf",&wektory.a.x, &wektory.a.y, &wektory.b.x, &wektory.b.y) == 4){
			ile[i]++;
			wec[i] = realloc(wec[1], ile[i] * sizeof *wec[i]);
			wektory.dlugosc = d(wektory.a, wektory.b);
			wec[i][ile[i]] = wektory;
		}
	}

	if(ile[0] >= ile[1]){
		ktory = 1;
		dr = 0;
		ile[0] = ile[1];
	}
	else{
		ktory=0;
		dr = 1;
		ile[i]= ile[0];
	}

	wec[0] = realloc(wec[0], ile[ktory] * sizeof *wec[1]);
	wec[1] = realloc(wec[1], ile[ktory] * sizeof *wec[1]);

	for(i=0; i<ile[0]; ++i){
		for(j=0; j<ile[0]; ++j){
			if(wec[ktory][i].dlugosc == wec[dr][j].dlugosc)powt++;
		}
	}





		
	system("pause");
	return 0;
}
#endif