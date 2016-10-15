#include "stdafx.h"
#include "fip.h"

const unsigned wysokosc = 650, szerokosc = 806;

ATOM MyRegisterClass(HINSTANCE hInstance){

	WNDCLASSEX wcex;
	HBRUSH pedzel = CreateSolidBrush(RGB(255, 255, 255));

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= pedzel;
	wcex.lpszMenuName	= 0;
	wcex.lpszClassName	= L"FIPClass";
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

	DeleteObject(pedzel);
	return RegisterClassEx(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;
   unsigned x = CW_USEDEFAULT, y = CW_USEDEFAULT;

   hWnd = CreateWindowEx(NULL, L"FIPClass", L"Marley Polska", WS_OVERLAPPED | WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
      x, y, szerokosc, wysokosc, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

HFONT czcionka(int wys, BOOL italic, LPCWSTR typ){
	return CreateFont( -MulDiv(wys, GetDeviceCaps(GetDC(NULL), LOGPIXELSY), 72), 0, 0, 0, 0, italic, FALSE, FALSE, EASTEUROPE_CHARSET, OUT_TT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, typ);	
}
void print(HDC hdc, HDC hdc_pamieciowy, const std::vector<std::wstring>& vec, RECT* pola, HFONT font){
	HFONT stara;
	stara = (HFONT) SelectObject(hdc, font);
	bool cz=false;
	subpages = vec.size();
	DRAWTEXTPARAMS para;
	ZeroMemory(&para, sizeof(DRAWTEXTPARAMS));
	para.iLeftMargin = 16;
	para.iRightMargin = 0;
	para.iTabLength = 8;
	para.cbSize = sizeof(DRAWTEXTPARAMS);
	
	for(UINT i=0; i < subpages; i++){
		if(cur_x > pola[i].left && cur_x < pola[i].right && cur_y > pola[i].top && cur_y < pola[i].bottom){
			SetTextColor(hdc, RGB(255, 0, 0));
			cz = true;
			if(page == 0 && i == 7){//tooltip
				std::wstring k(L"Program do sprawdzania odpornoœci chemicznej materia³ów i uszczelnieñ");
				RECT r;
				r.top = 475;
				r.bottom = 550;
				r.left = 500;
				r.right = 700;
				HFONT f = czcionka(12, true, L"comic sans ms");
				HFONT st = (HFONT) SelectObject(hdc, f);
				DrawTextEx(hdc, const_cast<wchar_t*>(k.c_str()), k.size(), &r, DT_WORDBREAK, &para);
				SelectObject(hdc, st);
				DeleteObject((HGDIOBJ)f);
			}
		}
		if(hdc_pamieciowy != NULL)BitBlt(hdc, pola[i].left, pola[i].top + 5, info_bitmapy2.bmWidth, info_bitmapy2.bmHeight, hdc_pamieciowy, 0, 0, SRCCOPY);
		DrawTextEx(hdc, const_cast<wchar_t*>(vec[i].c_str()), vec[i].size(), &pola[i], /*DT_SINGLELINE | DT_VCENTER */DT_WORDBREAK, &para);
		if(cz)SetTextColor(hdc, RGB(0, 0, 0));
	}
	SelectObject(hdc, stara);
}

void print(HDC hdc, HDC hdc_pamieciowy, const std::wstring& napis, RECT pole, HFONT font){
	std::vector<std::wstring> x;
	x.push_back(napis);
	print(hdc, hdc_pamieciowy, x, &pole, font);
}
void ref(HWND hWnd){
	RedrawWindow(hWnd, NULL, NULL,  RDW_INVALIDATE | RDW_ERASE | RDW_INTERNALPAINT);
}
void adresy(HDC hdc, HFONT font){
	RECT kw[3];
	std::vector<std::wstring> vec;

	vec.push_back(L"Marley Polska sp. z.o.o\r\n"
		L"ul. Annopol 24\r\n"
		L"03-236 Warszawa\r\n"
		L"tel.: 22 329 79 15\r\n"
		L"fax: 22 329 79 17\r\n\r\n"
		L"http://www.fipnet.pl\r\n"
		L"http://marley.com.pl\r\n"
		L"elzbieta.ciesielska@marley.com.pl");
	vec.push_back(L"Marley Polska sp. z.o.o\r\n"
		L"biuro Szczecin\r\n"
		L"ul. Gdañska 40\r\n"
		L"70-660 Szczecin\r\n"
		L"tel./fax: 91 46 24 987\r\n"
		L"                 91 46 24 669\r\n"
		L"                 91 46 23 245\r\n"
		L"monika.bauza@marley.com.pl");
	vec.push_back(L"Marley Polska sp. z.o.o\r\n"
		L"biuro D¹browa Górnicza\r\n"
		L"ul. £¹czna 39\r\n"
		L"41-303 D¹browa Górnicza\r\n"
		L"tel.: 32 79 28 035\r\n"
		L"         32 79 28 036\r\n"
		L"fax: 32 268 57 08\r\n");

	kw[0].top = 140;
	kw[0].bottom = 320;
	kw[0].left = 10;
	kw[0].right = 300;
	for(UINT i = 0; i < 2; ++i){
		kw[i+1].top = 140 + (i*190);
		kw[i+1].bottom = kw[i+1].top + 180;
		kw[i+1].left = 410;
		kw[i+1].right = 700;
	}
	print(hdc, NULL, vec, kw, font);
	logo(hdc, 0);
}

void logo(HDC hdc, int id){
	HBITMAP stara, mar;
	HDC comp;
	BITMAP info;
	UINT x, y;

	switch(id){
		case 0://marley
			mar = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_MARLEY));
			break;
		case 1://durapipe
			mar = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_DURA));
			break;
		case 2://akaterm/friatec
			mar = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_FRIAKA));
			break;
	}
	GetObject(mar, sizeof(BITMAP), &info);
	y = dol - info.bmHeight;
	if(id == 0) x = 580;
	else x = srodek - (info.bmWidth/2);

	comp = CreateCompatibleDC(hdc);
	stara = (HBITMAP) SelectObject(comp, mar);
	BitBlt(hdc, x, y, info.bmWidth, info.bmHeight, comp, 0, 0, SRCCOPY);
	SelectObject(comp, stara);
	DeleteObject(mar);
	DeleteDC(comp);
}

void go(HWND h){
	RECT rect;
	int x, y, mx, my;
	HDC hdc = GetDC(h);
	GetClientRect(h, &rect);
	srand(static_cast<unsigned int>(time(NULL)));
	mx = rect.right - rect.left;
	my = rect.bottom - rect.top;// - 130;
	bool** tab = new bool*[mx];
	for(int i=0; i<mx; i++)
		tab[i] = new bool[my];
	for(int i = 0; i < mx; ++i)
		for(int j = 0; j < my; ++j)
			tab[i][j] = false;

	for(int s = 0;s < (mx*my);){
		x = rand()%mx;
		y = (rand()%my);// + 130;
		if(tab[x][y])continue;
		SetPixel(hdc, x, y, RGB(255, 255, 255));
		//BitBlt(hdc, x, y, 1, 1, indc, x, y, SRCCOPY);
		tab[x][y] = true;
		s++;
	}
	for(int i=0; i<mx; i++)
		delete [] tab[i];
	delete[] tab;
	DeleteDC(hdc);
}