#include "stdafx.h"
#include "fip.h"

HINSTANCE hInst;									
HBITMAP hbmp, hbmp2, hbmp3, hbmp4, hbmp5;
BITMAP info_bitmapy, info_bitmapy2, info_bitmapy3, info_bitmapy4, info_bitmapy5;
UINT page = 0, subpage = 0, subpages, subsub = 0;
RECT pola[8], p[8], rectMenu, rectBack[2], rectMarley;
UINT s[5];
std::vector<std::vector<std::vector<std::wstring> > >zbiorowy; 
std::vector<std::vector<std::vector<std::wstring> > >pliki; 
std::vector<std::vector<std::wstring> >menu_items;
UINT cur_x = 0, cur_y = 0;
const UINT srodek = 400, top = 135;
UINT dol;
int act = -1;
bool przejscie = false;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	MSG msg;
	hInst = hInstance;

	MyRegisterClass(hInstance);

	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	while (GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}	
	return (int) msg.wParam;
}

void akcja(int id, HWND hWnd){
	switch(id){//globalne
		case -2:
			przejscie = true;
			page = 0;
			subpage = 0;
			subsub = 0;
			ref(hWnd);
			return;
		case -1:
			przejscie = true;
			page = 1;
			subpage = 0;
			subsub = 0;
			ref(hWnd);
			return;
	}
	if(id >= subpages) return;
	if(page == 3) return;
	if(page > 16)
		ShellExecute(GetDesktopWindow(), L"open", pliki[page-8][0][id].c_str(), NULL, NULL, SW_SHOWDEFAULT);
	else if(page == 0){
		if(id == 4){
			page = 2;
			ref(hWnd);
		}else if(id == 5){
			page++;
			ref(hWnd);
		}else if(id == 6){
			page = 3;
			cur_x = 0;
			cur_y = 0;
			ref(hWnd);	
		}else if(id == 7){
			PROCESS_INFORMATION info;
			STARTUPINFO startup;
			memset(&startup, 0, sizeof(startup));
			startup.cb = sizeof(startup);
//			startup.wShowWindow = SW_HIDE;
		//	wchar_t* buff = new wchar_t[50];
			wchar_t cmd[] = L"7za.exe e kemy.7z -oc:\\kemy -aoa";

			if(CreateProcess(NULL, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &startup, &info))
			{
				DWORD dwExitCode;
//				MessageBox(NULL, L"Instalacja w toku", L"czekaj...", 0);
				while(GetExitCodeProcess(info.hProcess, &dwExitCode) && dwExitCode == STILL_ACTIVE);
				// you may want to show a wait dialog or something like that in the above loop
				// while the exe is running...

				// exe has finished here
			
		//	ShellExecute(hWnd, L"open", L"7za.exe", L"e kemy.7z -oc:\\kemy -aoa", NULL, SW_HIDE);
			MessageBox(hWnd, L"Program Kemy zosta³ zainstalowany w folderze c:\\kemy.\nPo naciœniêciu przycisku Ok nast¹pi jego uruchomienie.", L"Zainstalowano", MB_OK); 
			ShellExecute(GetDesktopWindow(), L"open", L"c:\\kemy\\Kemy.exe", NULL, L"C:\\kemy", SW_SHOWDEFAULT);
			}
			else 
				MessageBox(hWnd, L"Instalacja programu kemy nie powiod³a siê.\n Rozpakuj rêcznie archiwum kemy.7z.", L"Error", MB_OK);
		}else 
			ShellExecute(GetDesktopWindow(), L"open", menu_items[0][id].c_str(), NULL, NULL, SW_SHOWDEFAULT);
	}else if(page == 1){
		page = 11 + id;
		ref(hWnd);
	}else if(page == 2){
		ShellExecute(GetDesktopWindow(), L"open", menu_items[1][id].c_str(), NULL, NULL, SW_SHOWDEFAULT);
	}else{
		if(subpage == 0){
			if((id == 0 && page != 11) || (id == 1 && (page == 13 || page == 15 || page == 16)))// pdf
				ShellExecute(GetDesktopWindow(), L"open", pliki[page-8][id][0].c_str(), NULL, NULL, SW_SHOWDEFAULT);
			else{
				subpage = id+1;
				ref(hWnd);
			}			
		}else{
			if(id == subpages -1){//wróæ
				if(subsub == 0)subpage = 0;
				subsub = 0;
				ref(hWnd);
			}else if(page != 11){
				if(id < pliki[page-8][subpage-1].size())
					ShellExecute(GetDesktopWindow(), L"open", pliki[page-8][subpage-1][id].c_str(), NULL, NULL, SW_SHOWDEFAULT);
				else MessageBox(hWnd, L"ERROR", L"ERROR", MB_ICONERROR);
			}else{
				if(subpage == 3 || subpage == 4)
					ShellExecute(GetDesktopWindow(), L"open", pliki[subpage-1][id][0].c_str(), NULL, NULL, SW_SHOWDEFAULT);
				else if(subsub == 0){
					subsub = id+1;
					ref(hWnd);
				}
				else if(id < pliki[subpage-1][subsub-1].size())//pdf w subie
					ShellExecute(GetDesktopWindow(), L"open", pliki[subpage-1][subsub-1][id].c_str(), NULL, NULL, SW_SHOWDEFAULT);
				else MessageBox(hWnd, L"ERROR", L"ERROR", MB_ICONERROR);
			}					
		}
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc, hdc_pamieciowy;
	HFONT font, font2;
	RECT prostokat;
	HGDIOBJ stara_bitmapa;
	UINT x, y;
	
	switch (message){
		case WM_MOUSEMOVE:
			cur_x = GET_X_LPARAM(lParam);
			cur_y = GET_Y_LPARAM(lParam);
			break;
		case WM_TIMER:
			if(cur_x > rectMenu.left && cur_x < rectMenu.right && cur_y > rectMenu.top && cur_y < rectMenu.bottom && page !=0 && act != 0){
				act = 0;
				ref(hWnd);
				break;
			}
			if(cur_x > rectBack[1].left && cur_x < rectBack[1].right && cur_y > rectBack[1].top && cur_y < rectBack[1].bottom && page > 10 && act != 1){
				act = 1;
				ref(hWnd);
				break;
			}
			if(cur_x > rectBack[0].left && cur_x < rectBack[0].right && cur_y > rectBack[0].top && cur_y < rectBack[0].bottom && page > 10 && act != 2){
				act = 2;
				ref(hWnd);
				break;
			}
			for(int i=0; i<8; i++){
				if(page == 1 && cur_x > p[i].left && cur_x < p[i].right && cur_y > p[i].top && cur_y < p[i].bottom && page != 3 && act != (10+i)){
					act = 10 + i;
					ref(hWnd);
					break;
				}
				else if(page != 1 && cur_x > pola[i].left && cur_x < pola[i].right && cur_y > pola[i].top && cur_y < pola[i].bottom && page != 3 && act != (20 + i)){
					act = 20 + i;
					ref(hWnd);
					break;
				}
			}
			break;
		case WM_CREATE:
			SetTimer(hWnd, 0, 50, NULL);
			//³adowanie bitmap
			//t³o
			hbmp5 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_EW));
			GetObject(hbmp5, sizeof(BITMAP), &info_bitmapy5); 
			//Dolne logo
			hbmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_FIP));
			GetObject(hbmp, sizeof(BITMAP), &info_bitmapy); 
			//górne logo
			hbmp2 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_TOP));
			GetObject(hbmp2, sizeof(BITMAP), &info_bitmapy2); 
			//strza³ka
			hbmp3 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_ARROW));
			GetObject(hbmp3, sizeof(BITMAP), &info_bitmapy3); 
			//copyright
			hbmp4 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_CPY));
			GetObject(hbmp4, sizeof(BITMAP), &info_bitmapy4); 
			//vectory
			vectory(menu_items, zbiorowy, pliki);
			//pola
			for(int i=0; i<8; i++){//prawa
				int skok = 45;
				pola[i].left = 410;
				pola[i].right = 790;
				pola[i].top = top + (i*skok) + (i*2);
				pola[i].bottom = pola[i].top + skok;
			}
			for(int i=0; i<8; i++){//lewa
				int skok = 40;
				p[i].left = 10;
				p[i].right = 300;
				p[i].top = top + (i*skok) + (i*5);
				p[i].bottom = p[i].top + skok;
			}
			for(int i=0; i<2; i++){
				int skok = 40;
				rectBack[i].left = 10;
				rectBack[i].right = 300;
				rectBack[i].top = top + (i*skok) + (i*5);
				rectBack[i].bottom = rectBack[i].top + skok;
			}
			rectMenu.left = 10;
			rectMenu.right = 300;
			rectMenu.top = 550;
			rectMenu.bottom = rectMenu.top + 50;

			rectMarley.left = 635;
			rectMarley.top = 570;
			rectMarley.right = rectMarley.left + 220;
			rectMarley.bottom = rectMarley.top + 45;

			//subpage do 11
			s[0] = 0;
			s[1] = 1;
			s[2] = 5;
			s[3] = 10;
			s[4] = 11;

			//dó³
			GetClientRect(hWnd, &prostokat);
			dol = prostokat.bottom - prostokat.top;
			break;
		case WM_LBUTTONDOWN:
			x = GET_X_LPARAM(lParam);
			y = GET_Y_LPARAM(lParam);

			if(x > rectMenu.left && x < rectMenu.right && y > rectMenu.top && y < rectMenu.bottom && page !=0){
				akcja(-2, hWnd); // menu
				break;
			}
			if(x > rectBack[1].left && x < rectBack[1].right && y > rectBack[1].top && y < rectBack[1].bottom && page > 10){
				akcja(-1, hWnd); //powrót lewy
				break;
			}
			if(x > rectBack[0].left && x < rectBack[0].right && y > rectBack[0].top && y < rectBack[0].bottom && page > 10){
				int pa = page;//tytu³ lewy
				akcja(-1, hWnd); 
				akcja(pa-11, hWnd);
				break;
			}
			if(page != 1){
				for(int i=0; i<8; i++)
					if(x > pola[i].left && x < pola[i].right && y > pola[i].top && y < pola[i].bottom){
						akcja(i, hWnd);
						break;
					}
			}else for(int i=0; i<8; i++)
					if(x > p[i].left && x < p[i].right && y > p[i].top && y < p[i].bottom){
						akcja(i, hWnd);
						break;
					}			
			break;
		case WM_PAINT:	
			if(przejscie){
				przejscie = false;
				go(hWnd);
			}

			hdc = BeginPaint(hWnd, &ps);

			//Bitmapy
			hdc_pamieciowy = CreateCompatibleDC(hdc);

			stara_bitmapa = SelectObject(hdc_pamieciowy, hbmp5);
			BitBlt(hdc, 0, 0, info_bitmapy5.bmWidth, info_bitmapy5.bmHeight, hdc_pamieciowy, 0, 0, SRCCOPY);

			if(page < 17){
				SelectObject(hdc_pamieciowy, hbmp);
				BitBlt(hdc, srodek - 72, dol - info_bitmapy.bmHeight, info_bitmapy.bmWidth, info_bitmapy.bmHeight, hdc_pamieciowy, 0, 0, SRCCOPY);
			}

			SelectObject(hdc_pamieciowy, hbmp2);
			BitBlt(hdc, 0, 0, info_bitmapy2.bmWidth, info_bitmapy2.bmHeight, hdc_pamieciowy, 0, 0, SRCCOPY);

			SelectObject(hdc_pamieciowy, hbmp4);
			BitBlt(hdc, 5, dol - info_bitmapy4.bmHeight - 5, info_bitmapy4.bmWidth, info_bitmapy4.bmHeight, hdc_pamieciowy, 0, 0, SRCCOPY);

			SelectObject(hdc_pamieciowy, hbmp3);

			//Rysowanie Lini
			MoveToEx(hdc, srodek, top, NULL);
			LineTo(hdc, srodek, 520);

			//napisy
			font = czcionka(12, false, L"Impact");
			font2 = czcionka(14, false, L"Impact");
			SetBkMode(hdc, TRANSPARENT);
			SetTextColor(hdc, RGB(0, 0, 0));

			print(hdc, NULL, L"http://www.fipnet.pl\r\nTel.: 22 32 979 15", rectMarley, font);

			if(page != 0){
				print(hdc, hdc_pamieciowy, L"menu", rectMenu, font2);
				if(page > 10){
					std::vector<std::wstring> tmp;
					tmp.push_back(zbiorowy[0][1][page - 11]);
					tmp.push_back(L"powrót");
					print(hdc, hdc_pamieciowy, tmp, rectBack, font2);
				}
			}
			if(page > 11 && page < 17){
				if(subpage == 0)
					print(hdc, hdc_pamieciowy, zbiorowy[page-10][0], pola, font);
				else
					print(hdc, hdc_pamieciowy, zbiorowy[page - 10][subpage-1], pola, font);
			}else switch(page){
				case 0://strona startowa
					print(hdc, hdc_pamieciowy, zbiorowy[0][0], pola, font2);
					break;
				case 1://katalogi menu
					print(hdc, hdc_pamieciowy, zbiorowy[0][1], p, font2);
					break;
				case 11:
					print(hdc, hdc_pamieciowy, zbiorowy[1][s[subpage]+subsub], pola, font);
					break;
				case 17:
					logo(hdc, 2);
					print(hdc, hdc_pamieciowy, zbiorowy[0][3], pola, font);
					break;
				case 18:
					logo(hdc, 1);
					print(hdc, hdc_pamieciowy, zbiorowy[0][4], pola, font);
					break;
				case 2:
					print(hdc, hdc_pamieciowy, zbiorowy[0][2], pola, font);
					break;
				case 3:
					adresy(hdc, font);
					break;					
			}
			//sprz¹tanie
			DeleteObject(font);
			DeleteObject(font2);
			EndPaint(hWnd, &ps);
			SelectObject(hdc_pamieciowy, stara_bitmapa);
			DeleteDC(hdc_pamieciowy);
			break;
		case WM_DESTROY:
			KillTimer(hWnd, 0);
			DeleteObject(hbmp);
			DeleteObject(hbmp2);
			DeleteObject(hbmp3);
			DeleteObject(hbmp4);
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

