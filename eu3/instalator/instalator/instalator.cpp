/*
 * Plik instalator.cpp
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


DLGPROC first(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);

	switch (message){
		case WM_INITDIALOG:
			log("DLGPROC", "Utworzono dialogboxa, page", page);
            SendMessage(hDlg, WM_SETICON, ICON_BIG, (LPARAM)hIco);
			SetDlgItemText(hDlg, IDC_INTRO, intro);
			break;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDC_NEXT:
					oldpage = page;
					page++;
					break;
				case IDCANCEL:
					exit(hDlg);
					break;
				}
			break;
		}
	return false;
}
DLGPROC second(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);

	switch (message){
		case WM_INITDIALOG:
			log("DLGPROC", "Utworzono dialogboxa, page", page);
            SendMessage(hDlg, WM_SETICON, ICON_BIG, (LPARAM)hIco);
			SetDlgItemText(hDlg, IDC_EDIT, edit2);
			if(!rejestr())MessageBox(hDlg, "Nie uda³o siê pobraæ danych z rejestru", "error", MB_OK | MB_ICONERROR);
			log("second", "po rejestrze");

			for(int i=0; i < 4; i++)
				SetDlgItemText(hDlg, 200+i, radio[i]);
			if(wersja < 4 && wersja > -1)
				CheckDlgButton(hDlg, 200 + wersja, 1);
			else{
				log("second", "nie wykryto wersji");
				MessageBox(hDlg, "Nie wykryto wersji gry", "Wersja", MB_OK | MB_ICONWARNING);
				break;
			}
			log("second", "przed MB");
			switch(wersja){
				case 0:
					MessageBox(hDlg, "Wykryto zainstalowany dodatek Hier to the Throne.\r\nWymagany patch to 4.1f, upewnij siê ¿e jest on zainstalowany", "Wersja", MB_OK);
					break;
				case 1:
					if(rej_ver == "3.2")MessageBox(hDlg, "Wykryto zainstalowany dodatek In Nomine i patcha 3.2.\r\nJest to w³aœciwa wersja", "Wersja", MB_OK);
					else MessageBox(hDlg, "Wykryto zainstalowany dodatek In Nomine ze z³ym patchem.\r\nZainstaluj patcha 3.2 i uruchom program ponownie", "Wersja", MB_OK | MB_ICONWARNING);
					break;
				case 2:
					if(rej_ver == "2.2")MessageBox(hDlg, "Wykryto zainstalowany dodatek Napoleon's Ambitions i patcha 2.2.\r\nJest to w³aœciwa wersja", "Wersja", MB_OK);
					else MessageBox(hDlg, "Wykryto zainstalowany dodatek Napoleon's Ambitions ze z³ym patchem.\r\nZainstaluj patcha 2.2 i uruchom program ponownie", "Wersja", MB_OK | MB_ICONWARNING);
					break;
				case 3:
					if(rej_ver == "1.3.1")MessageBox(hDlg, "Wykryto 'czyst¹' wersjê gry i patcha 1.3.1.\r\nJest to w³aœciwa wersja", "Wersja", MB_OK);
					else MessageBox(hDlg, "Wykryto 'czyst¹' wersjê gry ze z³ym patchem.\r\nZainstaluj patcha 1.3.1 i uruchom program ponownie", "Wersja", MB_OK | MB_ICONWARNING);
					break;
			}
			log("second", "po MB");
			break;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDC_NEXT:
					for(int i=0; i<4; i++){
						if(IsDlgButtonChecked(hDlg, 200+i)){
							wersja = i;
							break;
						}
					}
					log("second", "wybrana wersja", wersja);
					oldpage = page;
					page++;
					break;
				case IDCANCEL:
					exit(hDlg);
					break;
				case IDC_PREV:
					oldpage = page;
					page--;
					break;
				}
			break;
		case WM_NOTIFY:
			switch (((LPNMHDR)lParam)->code){
			case NM_CLICK:
			case NM_RETURN:
				log("second", "wyœwietlono stronê pacza");
				ShellExecute(NULL, "open", "http://forum.paradoxplaza.com/forum/showpost.php?p=11070962", NULL, NULL, SW_SHOW);
				break;
			}
			break;
		}

return 0;
}

DLGPROC third(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	char szFile[MAX_PATH];
	BROWSEINFO bi; 
	ITEMIDLIST *pItem;

	switch (message){
		case WM_INITDIALOG:
			log("DLGPROC", "Utworzono dialogboxa, page", page);
            SendMessage(hDlg, WM_SETICON, ICON_BIG, (LPARAM)hIco);
			SetDlgItemText(hDlg, IDC_EDIT, edit3);
			SetDlgItemText(hDlg, IDC_PATH, path.c_str());
			break;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDC_NEXT:
					GetDlgItemText(hDlg, IDC_PATH, szFile, MAX_PATH);
					path = szFile;
					if(*(path.end()-1) != '\\')path += '\\';
					log("third", "wybrana œcie¿ka", path.c_str());
					oldpage = page;
					page++;
					break;
				case IDCANCEL:
					exit(hDlg);
					break;
				case IDC_PREV:
					oldpage = page;
					page--;
					break;
				case IDC_BROWSE:
					log("third", "browser");

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
			}
			break;
	}
	return 0;
}

DLGPROC version_dialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	std::stringstream ss;
	std::string buff;

	switch (message){
		case WM_INITDIALOG:
				if(ver_here == ver_there){
					log("version_dialog", "aktualna wersja, jaka", ver_here.c_str());
					ss << "Posiadasz aktualn¹ wersjê moda\r\nJest to wersja:\t" << ver_here << "\r\n"
						<< "Naciœniêcie OK spowoduje usuniêcie wszystkich plików moda z Twojego komputera\r\n"
						<< "Oraz pobranie ich ponownie z serwera";
				}else{
					log("version_dialog", "rozne wersje");
					log("version_dialog", "wersja na kompie", ver_here.c_str());
					log("version_dialog", "wersja na serwerze", ver_there.c_str());
					ss << "Posiadasz wersjê moda:\t" << ver_here << "\r\n"
						<< "Aktualna wersja moda to:\t" << ver_there << "\r\n"
						"Naciœniêcie OK spowoduje usuniêcie\r\n"
						"wszystkich plików moda z Twojego komputera\r\n"
						"I instalacjê nowej wersji";
				}
				SetDlgItemText(hDlg, IDC_EDIT, ss.str().c_str());
				break;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDCANCEL:
					exit(hDlg);
					break;
				case IDOK:
					EndDialog(hDlg, 0);
					break;
			}
			break;
		}
	return 0;
}

DLGPROC fourth(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);

	switch (message){
		case WM_INITDIALOG:
			log("DLGPROC", "Utworzono dialogboxa, page", page);
            SendMessage(hDlg, WM_SETICON, ICON_BIG, (LPARAM)hIco);
			SetDlgItemText(hDlg, IDC_EDIT, edit4);
			for(int i = 1016; i <= 1019; ++i){
				if(i == 1018)continue;//manual
				if(i == 1019 && wersja < 2){//patch && wersja > IN
					EnableWindow(GetDlgItem(hDlg, i), FALSE);
					continue;
				}
				CheckDlgButton(hDlg, i, 1);
			}
			version(hDlg);
			if(ver_here != "NONE")
				DialogBox(hInst, MAKEINTRESOURCE(IDD_VERSION), hDlg, (DLGPROC)version_dialog);
			break;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDC_NEXT:
					for(int i=0; i<4; i++)
						if(IsDlgButtonChecked(hDlg, 1016+i))
							opcje[i] = true;
						else 
							opcje[i] = false;
					oldpage = page;
					page++;
					break;
				case IDCANCEL:
					exit(hDlg);
					break;
				case IDC_PREV:
					oldpage = page;
					page--;
					break;
			}
			break;
	}
	return 0;
}

DLGPROC download_proc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);
	DWORD id;

	switch (message){
		case WM_INITDIALOG:
			log("download_proc", "Utworzono dialogboxa downloadu");
          //  SendMessage(hDlg, WM_SETICON, ICON_BIG, (LPARAM)hIco);
			SetDlgItemText(hDlg, IDC_EDIT, down);
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) download, (LPVOID)hDlg, 0, &id);
			break;
		case WM_TIMER:
			//MessageBox(hDlg, "Pomyslnie zakonczono pobieranie", "koniec", MB_OK);
			log("download_proc", "koniec download_proc");
			EndDialog(hDlg, 0);
			break;
		case WM_COMMAND:
			if(LOWORD(wParam) == IDCANCEL){
				exit(hDlg);
			}
			break;
	}
	return 0;
}

DLGPROC fifth(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	UNREFERENCED_PARAMETER(lParam);

	switch (message){
		case WM_INITDIALOG:
			log("DLGPROC", "Utworzono dialogboxa, page", page);
            SendMessage(hDlg, WM_SETICON, ICON_BIG, (LPARAM)hIco);
			SetDlgItemText(hDlg, IDC_EDIT, edit5);
			SetTimer(hDlg, 0, 10, 0);
			break;
		case WM_TIMER:
			log("fifth", "timer");
			KillTimer(hDlg, 0);
			SendMessage(GetDlgItem(hDlg, IDC_EDIT1), EM_LIMITTEXT, -1, 0);

			if(ver_here != "NONE")
				if(!kosz(hDlg)){
					log("fifth", "kosz error");
					page = -1;
					EndDialog(hDlg, 0);
					break;
				}					

			DialogBox(hInst, MAKEINTRESOURCE(IDD_DOWNLOAD), hDlg, (DLGPROC)download_proc);
			if(page == -1){
				log("fifth", "download_proc error");
				EndDialog(hDlg, 0);
				break;
			}

			if(!unpack(hDlg)){
				log("fifth", "unpack error");
				page = -1;
				EndDialog(hDlg, 0);
				break;
			}

			SendMessage(GetDlgItem(hDlg, IDC_EDIT1), EM_REPLACESEL, 0, (LPARAM)"\r\n===============================\r\n\r\n");
			if(opcje[0])cache(hDlg);
			if(opcje[1])ustawienia(hDlg);
			if(opcje[2])manual(hDlg);
			if(opcje[3])patch(hDlg);

			EnableWindow(GetDlgItem(hDlg, IDC_FINISH), TRUE);
			EnableWindow(GetDlgItem(hDlg, IDCANCEL), FALSE);
			break;
		case WM_COMMAND:
			if(LOWORD(wParam) == IDCANCEL)
				exit(hDlg);
			else if(LOWORD(wParam) == IDC_FINISH){
				page = -1;
				EndDialog(hDlg, 0);
			}
			break;
		}
	return 0;
}