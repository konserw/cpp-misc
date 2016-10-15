/*
 * Plik main.cpp
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

HBITMAP hbmp;
BITMAP info_bitmapy;
HINSTANCE hInst;

LRESULT CALLBACK wep(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){ /*T³o*/
	HDC kontekst;
	PAINTSTRUCT ps;	
	HDC hdc_pamieciowy;
	RECT prostokat;
	HGDIOBJ oldbmp;
	char buff[MAX_PATH];
	const char* point;
	std::stringstream ss;
	std::string sbuff;

	switch (uMsg){
		case WM_CREATE:
			log("wep", "tworzenie okna t³a");
			hbmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_TLO));
			GetObject(hbmp, sizeof(BITMAP), &info_bitmapy); 
			
	//		sndPlaySound("music", SND_FILENAME | SND_ASYNC | SND_NODEFAULT | SND_LOOP);
	/*		GetCurrentDirectory(MAX_PATH, buff);
			ss << "open \"" << buff << "\\music.mp3\" alias 666 shareable";
			sbuff = ss.str();
			log("wep", "komenda mci", sbuff.c_str());
			*/
			mciSendString("open \"c:\\Programowanie\\instalator\\instalator\\music.mp3\" alias 666 shareable", NULL, 0, 0);//(sbuff.c_str(), buff, 1023, hWnd);
	//		log("wep", "odpowiedŸ mci", buff);
			point = "play 666 repeat";
			log("wep", "komenda mci", point);
			mciSendString(point, buff, MAX_PATH, hWnd);
			log("wep", "odpowiedŸ mci", buff);
//MessageBox(NULL, "X", "X", MB_OK);
			SetTimer(hWnd, 0, 10, NULL);
			log("wep", "koniec tworzenia okna t³a");
			break;
		case WM_TIMER:
			if(page == -1){
				log("wep", "koñczenie pracy programu");
				DestroyWindow(hWnd);
				return 0;
			}
			if(oldpage != page){
				log("wep", "zmiana dialogboxa");
				oldpage = page;
				EndDialog(GetWindow(hWnd, GW_ENABLEDPOPUP), 0);
				DialogBox(hInst, MAKEINTRESOURCE(131+page), hWnd, (DLGPROC)procesy[page]);
			}
			return 0;
		case WM_PAINT:
			log("wep", "rysowanie");
			kontekst = BeginPaint(hWnd, &ps);

			GetClientRect(hWnd, &prostokat);
			hdc_pamieciowy = CreateCompatibleDC(kontekst);
			oldbmp = SelectObject(hdc_pamieciowy, hbmp);
			//BitBlt(kontekst,0,0,info_bitmapy.bmWidth,info_bitmapy.bmHeight,hdc_pamieciowy,0,0,SRCCOPY);
			StretchBlt(kontekst, 0, 0, prostokat.right - prostokat.left, prostokat.bottom - prostokat.top, hdc_pamieciowy, 0, 0, info_bitmapy.bmWidth, info_bitmapy.bmHeight, SRCCOPY);
			
			//sprz¹tanie
			log("wep", "sprz¹tanie po rysowaniu");
			SelectObject(hdc_pamieciowy, oldbmp);
			DeleteDC(hdc_pamieciowy);
			EndPaint(hWnd, &ps);
			log("wep", "koniec rysowania");
			return 0;
		case WM_CLOSE:
			DestroyWindow(hWnd);
		case WM_DESTROY:
			log("wep", "wyrzucanie œmieci");
		//	sndPlaySound(NULL, NULL);
			mciSendString("close 666", NULL, 0, 0);
			DeleteObject(hIco);
			DeleteObject(hbmp);
			log("wep", "œmieci wyrzucono");
			PostQuitMessage (0);
			return 0;
	 }
	 return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	czyszczenie_loga();
	log("START");
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	MSG msg;
	hInst = hInstance; 
	InitCommonControls();
	MyRegisterClass(hInstance);

	INITCOMMONCONTROLSEX st;
	ZeroMemory(&st, sizeof(INITCOMMONCONTROLSEX));
	st.dwSize = sizeof(INITCOMMONCONTROLSEX);
	st.dwICC = ICC_BAR_CLASSES | ICC_PROGRESS_CLASS | ICC_LINK_CLASS | ICC_STANDARD_CLASSES;
	InitCommonControlsEx(&st);


	if (!InitInstance (hInstance)){
		return FALSE;
	}
	log("przed pêtl¹ komunikatów");
	while (GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	log("wyjscie z pêtli komunikatów");
	return (int) msg.wParam;
}
