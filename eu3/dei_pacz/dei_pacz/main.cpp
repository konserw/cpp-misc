/*
 * paczer dla DeI by konserw
 * Copyright (C) 2009 Kamil Strzempowicz
 * Niniejszy program jest wolnym oprogramowaniem; możesz go 
 * rozprowadzać dalej i/lub modyfikować na warunkach Powszechnej
 * Licencji Publicznej GNU, wydanej przez Fundację Wolnego
 * Oprogramowania - według wersji 2-giej tej Licencji lub którejś
 * z późniejszych wersji. 
 * Niniejszy program rozpowszechniany jest z nadzieją, iż będzie on 
 * użyteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyślnej 
 * gwarancji PRZYDATNOŚCI HANDLOWEJ albo PRZYDATNOŚCI DO OKREŚLONYCH 
 * ZASTOSOWAŃ. W celu uzyskania bliższych informacji - Powszechna 
 * Licencja Publiczna GNU. 
 * Z pewnością wraz z niniejszym programem otrzymałeś też egzemplarz 
 * Powszechnej Licencji Publicznej GNU (GNU General Public License);
 * jeśli nie - napisz do Free Software Foundation, Inc., 675 Mass Ave,
 * Cambridge, MA 02139, USA.
 * 
 * Pozdrawiam, konserw.
 * konserw@gmail.com
 */

#include "stdafx.h"
#include "header.h"

int main(){
	init();
	std::string path, pbuff, buff, opcje;
	bool exit=false;
	bool flaga = true;
	int i;

	border();

	if(!(sciezka(path))){
		log("main", "sciezka error");
		error();
		return 0;
	}

	wybor_moda(path);

	opcje = "Zmiana tagu warmii\n"
		"Event dla ksiestw ruskich\n"
		"Wyswietl licencje\n"
		"Wyjscie\n";
	cMenu pa("Wybierz pacz do aplikacji", opcje.c_str());

/*
###############################
###		Właściwy edytor		###
###############################
*/	

	while(exit == false)
		switch(pa.wybor()){
			case 0:
				logline();
				log("main", "Początek właściwego edytora");

				pbuff = path;
				pbuff += "common\\countries.txt";
				flaga = edit(pbuff);

				pbuff = path;
				pbuff += "common\\country_colors.txt";
				edit(pbuff);

				pbuff = path;
				pbuff += "events\\DeI - Unification - Poland.txt";
				for(int j=0; j<2; ++j) flaga = edit(pbuff);

				pbuff = path;
				pbuff += "history\\provinces\\42 - warmia.txt";
				flaga = edit(pbuff);

				pbuff = path;
				pbuff += "localisation\\DeI.csv";
				edit(pbuff, flaga);

				pbuff = path;
				pbuff += "history\\countries\\";
				buff = pbuff;
				pbuff += "WAR - Warmia.txt";
				buff += "WRI - Warmia.txt";
				i = MoveFileExA(pbuff.c_str(), buff.c_str(), MOVEFILE_REPLACE_EXISTING);
				if(i == 0) flaga = false;

				pbuff = path;
				pbuff += "gfx\\flags\\";
				buff = pbuff;
				pbuff += "WAR.tga";
				buff += "WRI.tga";
				i = MoveFileExA(pbuff.c_str(), buff.c_str(), MOVEFILE_REPLACE_EXISTING);
				if(i == 0) flaga = false;
				border();
				if(flaga == true){
					mvprintw(10, 10, "Najprawdopodobniej wszystko poszlo dobrze");
					cont();
				}
				else{
					mvprintw(10, 10, "Cos poszlo nie tak. Wiecej info w error.log");
					cont();
				}
				break;
			case 1:
				flaga = rus(path);
				border();
				if(flaga == true){
					mvprintw(10, 10, "Najprawdopodobniej wszystko poszlo dobrze");
					cont();
				}
				else{
					mvprintw(10, 10, "Cos poszlo nie tak. Wiecej info w error.log");
					cont();
				}
				break;
			case 2:
				system("Licencja.htm");
				break;
			case 3:
				exit = true;
				break;
			default:
				log("mian", "main menu error");
				exit = true;
				error();
				break;
	}

	endwin();
	log("main", "koniec programu");
	return 0;
}


