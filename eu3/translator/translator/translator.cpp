/*
 * Plik translator.cpp
 * CSV Translator - program u³atwiaj¹cy t³umaczenie plików 
 * lokalizacyjnych gier ParadoxInteractive; wersja kompatybilna z:
 * EU3, vicky2
 * Potrzebujesz wersji pasuj¹cej do innej gry paradoxu - pisz na mojego mejla! ;)
 * Zawsze warto te¿ zajrzeæ na forum strategiczne wayofwar.pl
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
#include "translator.h"

std::deque<cWers> wersy;
int wers = 0, byl = -1, lang = -1;
const char chLang[13][20] = {
	"ENGLISH",
	"FRENCH",
	"GERMAN",
	"POLSKI",
	"SPANISH",
	"ITALIAN",
	"SWEDISH",
	"CZECH",
	"HUNGARIAN",
	"DUTCH",
	"PORTUGESE",
	"RUSSIAN",
	"FINNISH"
};
//eJaka_gra gra;

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	InitCommonControls();
						
/*
	INITCOMMONCONTROLSEX st;
	st.dwSize = sizeof(INITCOMMONCONTROLSEX );
	st.dwICC = ICC_BAR_CLASSES | ICC_PROGRESS_CLASS;
	InitCommonControlsEx(&st);
*/
	czyszczenie_loga();
//	hInst = hInstance;

/*
	DialogBox(hInst, MAKEINTRESOURCE(IDD_GRA), NULL, (DLGPROC)GraProc);
	if(wyjscie)return 0;
*/
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_LANG), NULL, (DLGPROC)LangProc);
	if(lang == -1)return 0;

	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN), NULL, (DLGPROC)MainProc);
}

BOOL CALLBACK LangProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	int id;
//EnableWindow(GetDlgItem(hDlg, IDC_LIST), true);
	switch (message){
		case WM_INITDIALOG:
			log("Utworzono dialogboxa LANG");
			for(int i=0; i < 13; i++)
				SendMessage(GetDlgItem(hDlg, IDC_LIST), LB_INSERTSTRING, (WPARAM) -1, (LPARAM) chLang[i]);
			break;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDCANCEL:
					lang = -1;
					EndDialog(hDlg, 0);
					break;
				case IDOK:
					id = SendMessage(GetDlgItem(hDlg, IDC_LIST), LB_GETCURSEL, 0, 0);
					if(id != LB_ERR){
						lang = id;
						EndDialog(hDlg, 0);
					}
					else MessageBox(NULL, "Choose language first!", "ERROR", MB_OK | MB_ICONERROR);
					break;
				case IDC_ABOUT:
					log("About");
					DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_ABOUTBOX), hDlg, About);
					break;
			}
	}
	return 0;
}
/*
BOOL CALLBACK GraProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	int id;
//EnableWindow(GetDlgItem(hDlg, IDC_LIST), true);

	switch (message){
		case WM_INITDIALOG:
			log("Utworzono dialogboxa GRA");
			SendMessage(GetDlgItem(hDlg, IDC_LIST), LB_INSERTSTRING, (WPARAM) -1, (LPARAM) "Europa Universallis III");
			SendMessage(GetDlgItem(hDlg, IDC_LIST), LB_INSERTSTRING, (WPARAM) -1, (LPARAM) "Victoria II");
			break;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDCANCEL:
					wyjscie = true;
					EndDialog(hDlg, 0);
					break;
				case IDOK:
					id = SendMessage(GetDlgItem(hDlg, IDC_LIST), LB_GETCURSEL, 0, 0);
					if(id != LB_ERR){
						gra = (eJaka_gra) id;
						EndDialog(hDlg, 0);
					}
					else MessageBox(NULL, "Napierw wybierz gre!", "ERROR", MB_OK | MB_ICONERROR);
					break;
			}
	}
	return 0;
}
*/
BOOL CALLBACK MainProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	HICON hIcon;
	int mb;
	const int max = 6;
	char buff[max];
	char szFile[MAX_PATH] = {0};

	switch (message){
		case WM_INITDIALOG:
			log("Utworzono dialogboxa main");
            hIcon = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICO), IMAGE_ICON, 32, 32, 0);
            SendMessage(hDlg, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
			SetDlgItemText(hDlg, IDC_LANG, chLang[lang]);
			break;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDC_NEXT:
					update(hDlg, wersy);
					wers++;
					refresh(hDlg, wersy);
					break;
				case IDC_PREV:
					update(hDlg, wersy);
					wers--;
					refresh(hDlg, wersy);
					break;
				case IDC_GO:
					GetDlgItemText(hDlg, IDC_SKOK, buff, max);
					mb = atoi(buff);
					if(mb <= wersy.size()){
						update(hDlg, wersy);
						wers = mb;
						refresh(hDlg, wersy);
					}
					break;
				case IDC_DEL:
					wersy.erase(wersy.begin()+wers);
					wers--;
					refresh(hDlg, wersy);
					break;
				case IDM_EXIT:
					EndDialog(hDlg, 0);
					break;
				case IDM_ABOUT:
					log("About");
					DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_ABOUTBOX), hDlg, About);
					break;
				case ID_FILE_OPEN:
					log("Open");
					if(byl != -1){
						log("zapis przed wczytaniem?");
						mb = MessageBox(hDlg, "Do you want to save your work before loading another file?", "Save", MB_ICONQUESTION | MB_YESNOCANCEL);
						if(mb == IDYES) zapis(wersy, hDlg, szFile);
						else if(mb == IDCANCEL)break;
					}
					wczyt(wersy, hDlg, szFile);
					refresh(hDlg, wersy);
					break;
				case ID_FILE_SAVE:
					log("Save");
				//	update(hDlg, wersy);
					zapis(wersy, hDlg, szFile);
					break;
				case ID_FILE_NEW:
					log("New");
					if(byl != -1){
						log("zapis przed nowym?");
						mb = MessageBox(hDlg, "Do you want to save your work before creating another file?", "Save", MB_ICONQUESTION | MB_YESNOCANCEL);
						if(mb == IDYES) zapis(wersy, hDlg, szFile);
						else if(mb == IDCANCEL)break;
					}
					wersy.clear();
					wersy.push_back(cWers());
					wers = 0;
					refresh(hDlg, wersy);
					SetWindowText(hDlg, "CSV Translator - New File");
					break;
				}
			break;
		case WM_CLOSE:
			if(byl != -1){
				log("zapis przed wyjsciem?");
				mb = MessageBox(hDlg, "Do you want to save your work before closing?", "Save", MB_ICONQUESTION | MB_YESNOCANCEL);
				if(mb == IDYES) zapis(wersy, hDlg, szFile);
				if(mb == IDCANCEL)break;
			}
			EndDialog(hDlg, 0);
		}
	return false;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		SetDlgItemText(hDlg, IDC_EDIT, 
			"CSV Translator - program u³atwiaj¹cy t³umaczenie plików "
			"lokalizacyjnych gier ParadoxInteractive; wersja kompatybilna z:\r\n"
			"* Europa Universallis III\r\n"
			"* Victoria II\r\n"
			"Potrzebujesz wersji pasuj¹cej do innej gry paradoxu - pisz na mojego mejla! ;)\r\n"
			"Zawsze warto te¿ zajrzeæ na forum strategiczne wayofwar.pl\r\n\r\n"
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