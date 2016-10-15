/*
 * Plik std.cpp
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

char clas[] = "konserw_background";

void exit(HWND hDlg){
	log("exit", "wy�wietlenie MB");
	if(MessageBox(hDlg, "Na pewno chcesz zako�czy� instalacj�?",
		"Wyj�cie?", MB_YESNO | MB_ICONWARNING) == IDYES){
			log("exit", "IDYES");
			EndDialog(hDlg, 0);
			page = -1;
	}
}

HFONT czcionka(int wys, BOOL italic, LPCSTR typ){
	int w;
	HFONT wynik;
	w = -MulDiv(wys, GetDeviceCaps(GetDC(NULL), LOGPIXELSY), 72);
	wynik = CreateFont(w, 0, 0, 0, 0, italic, FALSE, FALSE, EASTEUROPE_CHARSET, OUT_TT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, typ);
	return wynik;
}

void explode(const std::string &str, const char *delim, std::vector<std::string> &out){

    std::string::const_iterator i1 = str.begin(); 
    std::string::const_iterator i2 = i1; 
	std::string::const_iterator i3 = str.end(); 

    while(i1 != i3){ 
        while(i2 != i3 && !strchr(delim,*i2))++i2; 
		out.push_back(std::string(i1,i2)); 
        i1 = i2 != i3 ? ++i2 : i2; 
    } 
}

ATOM MyRegisterClass(HINSTANCE hInstance){
	log("MyRegisterClass");
	hIco = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICO));
	WNDCLASSEX KlasaTla;

	ZeroMemory(&KlasaTla, sizeof(WNDCLASSEX));
	KlasaTla.cbSize = sizeof(WNDCLASSEX);
	KlasaTla.hInstance = hInstance;
	KlasaTla.lpfnWndProc = wep;
	KlasaTla.lpszClassName = clas;
	KlasaTla.hCursor = NULL;
	KlasaTla.hIcon = hIco;
	KlasaTla.hbrBackground = NULL;
	RegisterClassEx (&KlasaTla);

	return RegisterClassEx(&KlasaTla);
}

BOOL InitInstance(HINSTANCE hInstance){
	log("InitInstance");
	HWND hWnd = CreateWindowEx(NULL, clas, NULL,
		~WS_CAPTION & ~WS_VSCROLL & ~WS_HSCROLL,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL); 

	if (!hWnd){
		log("InitInstance", "error");
		return FALSE;
	}

	ShowWindow(hWnd, SW_MAXIMIZE);
	UpdateWindow(hWnd);

	return TRUE;
}