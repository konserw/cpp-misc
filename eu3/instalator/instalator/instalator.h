/*
 * Plik instalator.h
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
#pragma once

#include "resource.h"

typedef DLGPROC (*dlgproc) (HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
typedef std::vector<std::string>::iterator iter;

extern HINSTANCE hInst;
extern HICON hIco;
extern int page, oldpage, wersja;
extern dlgproc procesy[];
extern const char intro[], edit2[], edit3[], edit4[], edit5[];
extern const char radio[4][30], down[];
extern std::string rej_ver, path;
extern bool opcje[4];
extern std::string ver_here, ver_there;

//std.cpp
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
//HFONT czcionka(int wys, BOOL italic, LPCSTR typ);
void explode(const std::string &str, const char *delim, std::vector<std::string> &out);

//funkcje.cpp
bool rejestr();
bool unpack(HWND hDlg);
void download(HWND hDlg);
void exit(HWND hDlg);
void cache(HWND hDlg);
void ustawienia(HWND hDlg);
void manual(HWND hDlg);
void patch(HWND hDlg);
void version(HWND hDlg);
bool kosz(HWND hDlg);

//main.cpp
//int winmain(...);
LRESULT CALLBACK wep(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//instalator.cpp
DLGPROC first(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
DLGPROC second(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
DLGPROC third(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
DLGPROC fourth(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
DLGPROC fifth(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
