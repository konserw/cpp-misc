/*
exercse - program do nauki s³ów jêzyków obcych, szczególnie agielskiego.
Copyright (C) 2009 Kamil Strzempowicz
Niniejszy program jest wolnym oprogramowaniem; mo¿esz go 
rozprowadzaæ dalej i/lub modyfikowaæ na warunkach Powszechnej
Licencji Publicznej GNU, wydanej przez Fundacjê Wolnego
Oprogramowania - wed³ug wersji 2-giej tej Licencji lub którejœ
z póŸniejszych wersji. 
Niniejszy program rozpowszechniany jest z nadziej¹, i¿ bêdzie on 
u¿yteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyœlnej 
gwarancji PRZYDATNOŒCI HANDLOWEJ albo PRZYDATNOŒCI DO OKREŒLONYCH 
ZASTOSOWAÑ. W celu uzyskania bli¿szych informacji - Powszechna 
Licencja Publiczna GNU. 
Z pewnoœci¹ wraz z niniejszym programem otrzyma³eœ te¿ egzemplarz 
Powszechnej Licencji Publicznej GNU (GNU General Public License);
jeœli nie - napisz do Free Software Foundation, Inc., 675 Mass Ave,
Cambridge, MA 02139, USA.

Pozdrawiam, konserw.
konserw@gmail.com
*/

#include "naglowek.h"

vector<string> word;
vector<string> slowo;

//wczytanie bazy
bool load(string edzial, string pdzial){
	word.clear();
	slowo.clear();

	std::ifstream eplik;
	eplik.open(edzial.c_str());
	if (eplik.is_open() && eplik.good()){
		std::string buff;
		while(getline(eplik, buff).good()) 
        word.push_back(buff);
	}else return false;
	eplik.close();

	std::ifstream pplik;
	pplik.open(pdzial.c_str());
	if (pplik.is_open() && pplik.good()){
		std::string buff;
		while(getline(pplik, buff).good()) 
        slowo.push_back(buff);
	}else return false;
	pplik.close();

	return true;
}


//pytanie + (ocena)
void ex(char jezyk, string edzial, string pdzial){

if(load(edzial, pdzial)){
	unsigned i, ocena=0, wszystkie=0;
	//string x;
	char x[40];
	int t=22;
	srand(static_cast<unsigned int>(time(NULL)));

	vector<bool> bylo;
	for(unsigned j=0; j<word.size(); j++) bylo.push_back(false);

	while(t!=27){
		i=rand()%word.size();
		if (bylo[i]) continue;
		clear();
		echo();
			if (jezyk=='p'){
				mvprintw(10, 10, "Przetlumacz na Angielski:");
				attron(A_BOLD);
				mvprintw(12, 6, slowo[i].c_str());
				printw("\t");
				attroff(A_BOLD);
				refresh();
				echo();
				getnstr(x, 40);
				wszystkie++;
				if (x==word[i]){
					attron(A_BOLD);
					mvprintw(14, 6, "Ok!");
					attroff(A_BOLD);
					ocena++;
					bylo[i]=true;
				}else {
					attron(A_BOLD);
					mvprintw(14, 6, "WRONG!");
					attroff(A_BOLD);
					mvprintw(16, 6, "pawidlowa odpowiedz to:");
					mvprintw(17, 6, word[i].c_str());
				}
			}
			else if (jezyk=='e'){
				mvprintw(10, 10, "Przetlumacz na Polski:");
				attron(A_BOLD);
				mvprintw(12, 6, word[i].c_str());
				attroff(A_BOLD);
				refresh();
				echo();
				getnstr(x, 40);
				wszystkie++;
				if (x==slowo[i]){
					attron(A_BOLD);
					mvprintw(13, 6, "Ok!");
					attroff(A_BOLD);
					ocena++;
					bylo[i]=true;
				}else{
					attron(A_BOLD);
					mvprintw(14, 6, "WRONG!");
					attroff(A_BOLD);
					mvprintw(16, 6, "pawidlowa odpowiedz to:");
					mvprintw(17, 6, slowo[i].c_str());
				}
			}
			refresh();
			bool koniec=true;
			for(unsigned j=0; j<word.size(); j++) if (bylo[j]==false) koniec=false;
			if(koniec){
				mvprintw(20, 15, "znasz juz wszystie slowa z tej bazy");
				refresh();
				noecho();
				t=getch();
				break;
			}
			mvprintw(20, 15, "nacisnij cokolwiek aby kontynuowac lub ESC aby wyjsc do menu");
			refresh();
			noecho();
			t=getch();
	}
	clear();
	mvprintw(10, 10, "twoj wynik to %i", ocena);
	printw(" prawidlowych slow na wszystkich: %i", wszystkie);
	unsigned wynik=100*ocena/wszystkie;
	mvprintw(11, 10, "Czyli %i procent", wynik);
	
}else printw("ladowanie pliku bazy slow nieudane :(\n");

mvprintw(14, 14, "nacisnij klawisz aby kontynuowac");
refresh();
noecho();
getch();
}

//menu
unsigned short menu(){
	initscr();  
	keypad(stdscr, true);
	resize_term(45, 100);
	noecho();
	//opcje
	const char o0[]="Uruchom!";
	const char o1[]="wyswietl baze slow";
	const char o2[]="Pol => Eng";
	const char o3[]="Eng => Pol";
	const char o4[]="Szkola / Zdrowie";
	const char o5[]="Dom / zycie rodzinne i towarzyskie";
	const char o6[]="Praca / Podrozowanie i turystyka";
	const char o7[]="Zywienie / zakupy i uslugi / Czlowiek (b.b.)";
	const char o8[]="Sport / Kultura / Nauka i technika (b.b.)";
	const char o9[]="Swiat przyrody / Panstwo i spoleczenstwo (b.b.)";
	const char o10[]="Licencja";
	const char o11[]="Zakonczenie programu";

  unsigned short ktory = 0;
  int znak=2;
  const short int min_wybor = 0;
  const short int max_wybor = 11;
  for(;;)
  {
	clear();
	//test polskich zanków printw("¥Ó³Ÿ¿Œ");
    if (znak == 259 && ktory != min_wybor) ktory--;
    else if(znak == 258 && ktory != max_wybor) ktory++;
	else if(znak == 258 && ktory == max_wybor) ktory = min_wybor;
	else if(znak == 259 && ktory == min_wybor) ktory = max_wybor;
               
	if(znak == 13) return ktory;

	//wyswietlanie menu
	mvprintw(4, 35,"uzywaj strzalek w gore i w dol aby przemiescic wskaznik\n");
	mvprintw(5, 35,"oraz enter aby wybrac\n");
	attron(A_BOLD);
	mvprintw(10, 10,"Wybierz tryb oraz dzial:\n");
	attroff(A_BOLD);
		//tu menu
	mvprintw(24, 5, "(b.b.) - brak bazy. Aby korzystac z tych opcji nalezy najpierw samemu dopisac slowa");
	attron(A_BOLD);
	mvprintw(26, 15, "Wybrane opcje:\n");
	attroff(A_BOLD);
	switch(jezyk){
	  case 'p': 
		  mvprintw(27, 15, "Program wyswietli slowo po polsku, nalezy wpisac angielskie tluamczenie");
		  break;
	  case 'e':
		  mvprintw(27, 15, "Program wyswietli slowo po angielsku, nalzy wpisac polskie tluamczenie");
		  break;
	}
	mvprintw(28, 15, "Wybrany dzial z ktorego pochodza slowka:\t");
		 if(edzial=="e1.txt") printw(o4);
	else if( edzial=="e2.txt") printw(o5);
	else if( edzial=="e3.txt") printw(o6);
	else if( edzial=="e4.txt") printw(o7);
	else if( edzial=="e5.txt") printw(o8);
	else if( edzial=="e6.txt") printw(o9);

	attron(A_BOLD);
	mvprintw(30, 15, "Dodawanie wlasnych slow:");
	attroff(A_BOLD);
	mvprintw(31, 15, "nalezy wpisywaæ po 1 wyrazeniu w 1 linii");
	mvprintw(32, 15, "Nalezy wpisac angielskie slowo w pliku e i jego polskie tlumacznie w pliku p");
	mvprintw(33, 15, "Pliki te wybiera siê z poziomu menu i zatwierdza opcja >wyswietl baze slow<");
	mvprintw(34, 15, "nie nalezy uzywac polskich znakow diakrytycznych!");

	mvprintw(38, 5, "copyleft konserw");
	mvprintw(40, 5, "podziekowania dla wszystkich z programuj.com, za nieoceniona pomoc");

//opcje menu w aleznosci od wybranej opcji:
   switch(ktory)
    {
	  case 0:
		attron(A_REVERSE);
		mvprintw(11,10, o0);
		attroff(A_REVERSE);
		mvprintw(12,10, o1);
		mvprintw(13,10, o2);
		mvprintw(14,10, o3);
		mvprintw(15,10, o4);
		mvprintw(16,10, o5);
		mvprintw(17,10, o6);
		mvprintw(18,10, o7);
		mvprintw(19,10, o8);
		mvprintw(20,10, o9);
		mvprintw(21,10, o10);
		mvprintw(22,10, o11);
		break;

	  case 1:
		mvprintw(11,10, o0);
		attron(A_REVERSE);
		mvprintw(12,10, o1);
		attroff(A_REVERSE);
		mvprintw(13,10, o2);
		mvprintw(14,10, o3);
		mvprintw(15,10, o4);
		mvprintw(16,10, o5);
		mvprintw(17,10, o6);
		mvprintw(18,10, o7);
		mvprintw(19,10, o8);
		mvprintw(20,10, o9);
		mvprintw(21,10, o10);
		mvprintw(22,10, o11);
		break;

	  case 2:
		mvprintw(11,10, o0);
		mvprintw(12,10, o1);
		attron(A_REVERSE);
		mvprintw(13,10, o2);
		attroff(A_REVERSE);
		mvprintw(14,10, o3);
		mvprintw(15,10, o4);
		mvprintw(16,10, o5);
		mvprintw(17,10, o6);
		mvprintw(18,10, o7);
		mvprintw(19,10, o8);
		mvprintw(20,10, o9);
		mvprintw(21,10, o10);
		mvprintw(22,10, o11);
		break;

	  case 3:
		mvprintw(11,10, o0);
		mvprintw(12,10, o1);
		mvprintw(13,10, o2);
		attron(A_REVERSE);
		mvprintw(14,10, o3);
		attroff(A_REVERSE);
		mvprintw(15,10, o4);
		mvprintw(16,10, o5);
		mvprintw(17,10, o6);
		mvprintw(18,10, o7);
		mvprintw(19,10, o8);
		mvprintw(20,10, o9);
		mvprintw(21,10, o10);
		mvprintw(22,10, o11);
		break;

	  case 4:
		mvprintw(11,10, o0);
		mvprintw(12,10, o1);
		mvprintw(13,10, o2);
		mvprintw(14,10, o3);
		attron(A_REVERSE);
		mvprintw(15,10, o4);
		attroff(A_REVERSE);
		mvprintw(16,10, o5);
		mvprintw(17,10, o6);
		mvprintw(18,10, o7);
		mvprintw(19,10, o8);
		mvprintw(20,10, o9);
		mvprintw(21,10, o10);
		mvprintw(22,10, o11);
		break;

	  case 5:
		mvprintw(11,10, o0);
		mvprintw(12,10, o1);
		mvprintw(13,10, o2);
		mvprintw(14,10, o3);
		mvprintw(15,10, o4);
		attron(A_REVERSE);
		mvprintw(16,10, o5);
		attroff(A_REVERSE);
		mvprintw(17,10, o6);
		mvprintw(18,10, o7);
		mvprintw(19,10, o8);
		mvprintw(20,10, o9);
		mvprintw(21,10, o10);
		mvprintw(22,10, o11);
		break;

	  case 6:
		mvprintw(11,10, o0);
		mvprintw(12,10, o1);
		mvprintw(13,10, o2);
		mvprintw(14,10, o3);
		mvprintw(15,10, o4);
		mvprintw(16,10, o5);
		attron(A_REVERSE);
		mvprintw(17,10, o6);
		attroff(A_REVERSE);
		mvprintw(18,10, o7);
		mvprintw(19,10, o8);
		mvprintw(20,10, o9);
		mvprintw(21,10, o10);
		mvprintw(22,10, o11);
		break;

	  case 7:
		mvprintw(11,10, o0);
		mvprintw(12,10, o1);
		mvprintw(13,10, o2);
		mvprintw(14,10, o3);
		mvprintw(15,10, o4);
		mvprintw(16,10, o5);
		mvprintw(17,10, o6);
		attron(A_REVERSE);
		mvprintw(18,10, o7);
		attroff(A_REVERSE);
		mvprintw(19,10, o8);
		mvprintw(20,10, o9);
		mvprintw(21,10, o10);
		mvprintw(22,10, o11);
		break;
	  case 8:
		mvprintw(11,10, o0);
		mvprintw(12,10, o1);
		mvprintw(13,10, o2);
		mvprintw(14,10, o3);
		mvprintw(15,10, o4);
		mvprintw(16,10, o5);
		mvprintw(17,10, o6);
		mvprintw(18,10, o7);
		attron(A_REVERSE);
		mvprintw(19,10, o8);
		attroff(A_REVERSE);
		mvprintw(20,10, o9);
		mvprintw(21,10, o10);
		mvprintw(22,10, o11);
		break;
	  case 9:
		mvprintw(11,10, o0);
		mvprintw(12,10, o1);
		mvprintw(13,10, o2);
		mvprintw(14,10, o3);
		mvprintw(15,10, o4);
		mvprintw(16,10, o5);
		mvprintw(17,10, o6);
		mvprintw(18,10, o7);
		mvprintw(19,10, o8);
		attron(A_REVERSE);
		mvprintw(20,10, o9);
		attroff(A_REVERSE);
		mvprintw(21,10, o10);
		mvprintw(22,10, o11);
		break;
	  case 10:
		mvprintw(11,10, o0);
		mvprintw(12,10, o1);
		mvprintw(13,10, o2);
		mvprintw(14,10, o3);
		mvprintw(15,10, o4);
		mvprintw(16,10, o5);
		mvprintw(17,10, o6);
		mvprintw(18,10, o7);
		mvprintw(19,10, o8);
		mvprintw(20,10, o9);
		attron(A_REVERSE);
		mvprintw(21,10, o10);
		attroff(A_REVERSE);
		mvprintw(22,10, o11);
		break;
	  case 11:
		mvprintw(11,10, o0);
		mvprintw(12,10, o1);
		mvprintw(13,10, o2);
		mvprintw(14,10, o3);
		mvprintw(15,10, o4);
		mvprintw(16,10, o5);
		mvprintw(17,10, o6);
		mvprintw(18,10, o7);
		mvprintw(19,10, o8);
		mvprintw(20,10, o9);
		mvprintw(21,10, o10);
		attron(A_REVERSE);
		mvprintw(22,10, o11);
		attroff(A_REVERSE);
		break;
		}
		refresh();
		noecho();
		move(0,0);
		znak=getch();
		}
		}