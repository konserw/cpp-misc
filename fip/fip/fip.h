#pragma once

#include "resource.h"
#include "targetver.h"

ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

HFONT czcionka(int wys, BOOL italic, LPCWSTR typ);
void ref(HWND hWnd);
void print(HDC hdc, HDC hdc_pamieciowy, const std::vector<std::wstring>& vec, RECT* pola, HFONT font);
void print(HDC hdc, HDC hdc_pamieciowy, const std::wstring& vec, RECT pole, HFONT font);
void vectory(std::vector<std::vector<std::wstring> >& menu_items,
			 std::vector<std::vector<std::vector<std::wstring> > >& div,
			 std::vector<std::vector<std::vector<std::wstring> > >& pliki);
void adresy(HDC hdc, HFONT font);
void logo(HDC hdc, int id);

extern HINSTANCE hInst;
extern HBITMAP hbmp, hbmp2, hbmp3; 
extern BITMAP info_bitmapy, info_bitmapy2, info_bitmapy3;
extern UINT page, subpage, subpages, subsub, cur_x, cur_y;
extern const UINT srodek, top;
extern UINT dol;
//void go(HWND h, HDC indc);
void go(HWND);