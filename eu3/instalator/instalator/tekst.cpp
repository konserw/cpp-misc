/*
 * Plik tekst.cpp
 * Instalator - program instalacyjny moda Divide et Impera
 * wi�cej informacji: http://wayofwar.org/showthread.php?t=34092
 * 
 * Copyright (C) 2010 Kamil Strzempowicz
 * Niniejszy program jest wolnym oprogramowaniem; mo�esz go 
 * rozprowadza� dalej i/lub modyfikowa� na warunkach Powszechnej 
 * Licencji Publicznej GNU, wydanej przez Fundacj� Wolnego 
 * Oprogramowania - wed�ug wersji 2-giej tej Licencji lub kt�rej� 
 * z p�niejszych wersji. 
 * Niniejszy program rozpowszechniany jest z nadziej�, i� b�dzie on 
 * u�yteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domy�lnej 
 * gwarancji PRZYDATNO�CI HANDLOWEJ albo PRZYDATNO�CI DO OKRE�LONYCH 
 * ZASTOSOWA�. W celu uzyskania bli�szych informacji - Powszechna 
 * Licencja Publiczna GNU. 
 * Z pewno�ci� wraz z niniejszym programem otrzyma�e� te� egzemplarz 
 * Powszechnej Licencji Publicznej GNU (GNU General Public License); 
 * je�li nie - napisz do Free Software Foundation, Inc., 675 Mass Ave, 
 * Cambridge, MA 02139, USA.
 * 
 * Pozdrawiam, konserw.
 * konserw@gmail.com
 */

#include "stdafx.h"
#include "instalator.h"

const char intro[] = 
	"Witam w instalatorze moda\r\nDivide et Impera\r\n"
	"Tw�rcy:\r\n* Netzach\r\n* Einfall\r\n"
	"Przy wsp�pracy z forum WayOfWar.pl\r\n"
	"Tw�rca tego instalatora: Konserw\r\n"
	"DeI Team Members:\r\n"
	"Izqyehr, Paradygmat, Freon, Andronik,\r\n"
	"Konserw, BlindKitty, mrdie, Tleilaxu,\r\n"
	"Az-Zahir Bajbars, Marcho, Altaran, Maciej";
const char edit2[] = "Instalator automatycznie sprawdza w rejestrze\r\n"
	"zainstalowan� wersj� gry.\r\n"
	"Je�eli si� z nim nie zgadzasz, wybierz inn� wersj� gry:";
const char radio[4][30] = {
	"Heir to the Throne 4.1f",
	"In Nomine 3.2",
	"Napoleon's Ambitions 2.2",
	"Vanila 1.3"
};
const char edit3[] = "Wybierz �cie�k� instalacyjn� gry Europa Universallis III";
const char edit4[] = "Wybierz ustawienia instalacji:";
const char edit5[] = "Instalacja w toku...";
const char down[] = "Pobieranie odpowiedniej wersji moda...";

