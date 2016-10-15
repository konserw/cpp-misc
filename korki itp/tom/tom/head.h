#pragma once
#define WINDOWS_LEAD_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*moja implementacja typu boolean*/
#ifndef bool
#define bool short int
#define true 1
#define false 0
#endif

char* bin(int in);
int foo(int baza, char* ptr);

INT_PTR CALLBACK DialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);