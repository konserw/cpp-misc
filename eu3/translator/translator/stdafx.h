/*
 * Plik stdafx.h
 * CSV Translator - program u�atwiaj�cy t�umaczenie plik�w 
 * lokalizacyjnych gier ParadoxInteractive; wersja kompatybilna z EU3
 * Potrzebujesz wersji pasuj�cej do innej gry paradoxu - pisz na mojego mejla! ;)
 * Zawsze warto te� zajrze� na forum strategiczne wayofwar.pl
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

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN            

#include <windows.h>
#include <string>
#include <fstream>
#include <sstream>
#include <deque>
#include <shellapi.h>
#include <log.h>
#include <commctrl.h>
#include <commdlg.h>
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "comdlg32.lib") 
#pragma comment(lib, "log_rel.lib")
