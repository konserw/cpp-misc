/*
 * Plik tekst.cpp
 * Instalator - program instalacyjny moda Divide et Impera
 * wiêcej informacji: http://wayofwar.org/showthread.php?t=34092
 * 
 * Copyright (C) 2010 Kamil Strzempowicz
 * Niniejszy program jest wolnym oprogramowaniem; mo¿esz go 
 * rozprowadzaæ dalej i/lub modyfikowaæ na warunkach Powszechnej 
 * Licencji Publicznej GNU, wydanej przez Fundacjê Wolnego 
 * Oprogramowania - wed³ug wersji 2-giej tej Licencji lub którejœ 
 * z póŸniejszych wersji. 
 * Niniejszy program rozpowszechniany jest z nadziej¹, i¿ bêdzie on 
 * u¿yteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyœlnej 
 * gwarancji PRZYDATNOŒCI HANDLOWEJ albo PRZYDATNOŒCI DO OKREŒLONYCH 
 * ZASTOSOWAÑ. W celu uzyskania bli¿szych informacji - Powszechna 
 * Licencja Publiczna GNU. 
 * Z pewnoœci¹ wraz z niniejszym programem otrzyma³eœ te¿ egzemplarz 
 * Powszechnej Licencji Publicznej GNU (GNU General Public License); 
 * jeœli nie - napisz do Free Software Foundation, Inc., 675 Mass Ave, 
 * Cambridge, MA 02139, USA.
 * 
 * Pozdrawiam, konserw.
 * konserw@gmail.com
 */

#include "stdafx.h"
#include "instalator.h"

const char intro[] = 
	"Witam w instalatorze moda\r\nDivide et Impera\r\n"
	"Twórcy:\r\n* Netzach\r\n* Einfall\r\n"
	"Przy wspó³pracy z forum WayOfWar.pl\r\n"
	"Twórca tego instalatora: Konserw\r\n"
	"DeI Team Members:\r\n"
	"Izqyehr, Paradygmat, Freon, Andronik,\r\n"
	"Konserw, BlindKitty, mrdie, Tleilaxu,\r\n"
	"Az-Zahir Bajbars, Marcho, Altaran, Maciej";
const char edit2[] = "Instalator automatycznie sprawdza w rejestrze\r\n"
	"zainstalowan¹ wersjê gry.\r\n"
	"Je¿eli siê z nim nie zgadzasz, wybierz inn¹ wersjê gry:";
const char radio[4][30] = {
	"Heir to the Throne 4.1f",
	"In Nomine 3.2",
	"Napoleon's Ambitions 2.2",
	"Vanila 1.3"
};
const char edit3[] = "Wybierz œcie¿kê instalacyjn¹ gry Europa Universallis III";
const char edit4[] = "Wybierz ustawienia instalacji:";
const char edit5[] = "Instalacja w toku...";
const char down[] = "Pobieranie odpowiedniej wersji moda...";

