#include "stdafx.h"
#include "head.h"

HINSTANCE hInst;
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
int dlgMain(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	hInst = hInstance;
	InitCommonControls();

	czyszczenie_loga();
	log("przed dialogiem");
	return (int) DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN), NULL, (DLGPROC)dlgMain);
}




int dlgMain(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);

	BROWSEINFO bi;
	ITEMIDLIST *pItem;
	char buff[100], start[100], koniec[100];
	char szFile[MAX_PATH];
	UINT tech;
	HICON hIcon;

	const char* head = "Witaj w\r\n"
		"No Time Limit Patch 4 H3T by konserw";  
	const char* bro = "Wska¿ œcie¿kê do folderu gry";
	const char* edit = "Data pocz¹tku rozgrywki:\r\n\r\n\r\n"
		"Data koñca rozgrywki:\r\n\r\n\r\n"
		"Max poziom technologiczny:";
	//const char* dat = "dd-mm-yyyy";
	
	switch (message){
		case WM_INITDIALOG:
			log("initdialog");
			SetDlgItemText(hDlg, IDC_HEADER, head);
			SetDlgItemText(hDlg, IDC_PATH, bro);
			SetDlgItemText(hDlg, IDC_EDIT, edit);
			SetDlgItemText(hDlg, IDC_START, "1399.10.14");
			SetDlgItemText(hDlg, IDC_END, "1821.1.1");
			SetDlgItemText(hDlg, IDC_TECH, "72");
			hIcon = (HICON)LoadImage(hInst, MAKEINTRESOURCE(IDI_ICO), IMAGE_ICON, 32, 32, 0);
			SendMessage(hDlg, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
			break;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDC_BROWSE:
					log("browser");

					memset(&bi, 0, sizeof(BROWSEINFO)); 
					bi.hwndOwner = hDlg; 
					bi.pszDisplayName = szFile; 
					bi.lpszTitle = "Wybierz folder g³ówny gry";      

					pItem = SHBrowseForFolder(&bi); 
					if(pItem){
						SHGetPathFromIDList(pItem, szFile);
						SetDlgItemText(hDlg, IDC_PATH, szFile);
						log("third", "browser -> œcie¿ka", szFile);
					}
					break;
				case IDC_ABOUT:
					DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hDlg, About);
					break;
				case IDCANCEL:
					EndDialog(hDlg, 0);
					break;
				case IDOK:
					GetDlgItemText(hDlg, IDC_PATH, szFile, 100);

					GetDlgItemText(hDlg, IDC_START, start, 100);
					log("main", "start", start);
					GetDlgItemText(hDlg, IDC_END, koniec, 100);
					log("main", "koniec", koniec);
					GetDlgItemText(hDlg, IDC_TECH, buff, 100);
					tech = atoi(buff);
					log("main", "tech", tech);

					if(szFile == "Wska¿ œcie¿kê do folderu gry\0"){
						MessageBox(hDlg, "Nie wskazano œcie¿ki!", "Error", MB_ICONWARNING);
						break;
					}
					if(tech > 72)techy(tech, szFile);
					data(szFile, start, koniec);
					MessageBox(hDlg, "Zakoñczono operacje na plikach", "Koniec", MB_OK);
					break;
			}
	}
	return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	switch (message){
	case WM_INITDIALOG:
		SetDlgItemText(hDlg, IDC_EDIT, 
			"No Time Limit Patch 4 H3T by konserw\r\n"
			"Patch zmieniaj¹cy daty pocz¹tku i koñca rozgrywki\r\n"
			"dodaj¹cy tak¿e dodatkowe poziomy technologii dla EU3:H3T\r\n" 
			"Polecam forum strategiczne wayofwar.pl\r\n\r\n"
			"Copyright (C) 2010 Kamil Strzempowicz\r\n"
			"Niniejszy program jest wolnym oprogramowaniem; mo¿esz go "
			"rozprowadzaæ dalej i/lub modyfikowaæ na warunkach Powszechnej "
			"Licencji Publicznej GNU, wydanej przez Fundacjê Wolnego "
			"Oprogramowania - wed³ug wersji 2-giej tej Licencji lub którejœ "
			"z póŸniejszych wersji. \r\n"
			"Niniejszy program rozpowszechniany jest z nadziej¹, i¿ bêdzie on "
			"u¿yteczny - jednak BEZ JAKIEJKOLWIEK GWARANCJI, nawet domyœlnej "
			"gwarancji PRZYDATNOŒCI HANDLOWEJ albo PRZYDATNOŒCI DO OKREŒLONYCH "
			"ZASTOSOWAÑ. W celu uzyskania bli¿szych informacji - Powszechna "
			"Licencja Publiczna GNU. \r\n"
			"Z pewnoœci¹ wraz z niniejszym programem otrzyma³eœ te¿ egzemplarz "
			"Powszechnej Licencji Publicznej GNU (GNU General Public License); "
			"jeœli nie - napisz do Free Software Foundation, Inc., 675 Mass Ave, "
			"Cambridge, MA 02139, USA.\r\n\r\n"
			"Pozdrawiam, konserw.\r\n"
			"konserw@gmail.com\r\n");
		return (INT_PTR)TRUE;
	case WM_COMMAND:
		switch(LOWORD(wParam)){
			case IDC_GNU:
				ShellExecute(GetDesktopWindow(), "open", "licencja.htm", NULL, NULL, SW_SHOWDEFAULT);
				break;
			case IDOK:
				EndDialog(hDlg, LOWORD(wParam));
		}
		break;
	}
	return (INT_PTR)FALSE;
}