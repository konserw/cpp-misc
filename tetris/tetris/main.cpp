

#include "stdafx.h"
#include "tetris.h"

UINT dim_x, dim_y;
const UINT wx = 300, wy = 600;
const int dim = 20;

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	MSG msg;
	HWND hWnd;
	WNDCLASSEX wcex;

	ZeroMemory(&wcex, sizeof(WNDCLASSEX));
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICO));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= CreateSolidBrush(RGB(255, 255, 255));
	wcex.lpszClassName	= "klasaTetris";
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICO));
	RegisterClassEx(&wcex);

	hWnd = CreateWindow("klasaTetris", "Tetris by konserw", WS_OVERLAPPEDWINDOW,
	  CW_USEDEFAULT, CW_USEDEFAULT, wx, wy, NULL, NULL, hInstance, NULL);

	if(hWnd == NULL)return 1;

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, NULL, 0, 0)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
	}
	return (int) msg.wParam;
}

cKlocek* klocek = NULL;
bot* bot_block = NULL;


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rc;

	switch (message){
		case WM_CREATE:
			srand ( time(NULL) );
			GetClientRect(hWnd, &rc);
			dim_x = (rc.right - rc.left)/dim;
			dim_y = (rc.bottom - rc.top)/dim;
			klocek = new sqb;
			bot_block = new bot;
			SetTimer(hWnd, 0, 500, NULL);
			break;
		case WM_TIMER:
			time(klocek, bot_block);
			break;
		case WM_CHAR:
			klocek->move(wParam, bot_block);
			ref(hWnd);
			break;
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			klocek->draw(hdc);
			bot_block->draw(hdc);

			EndPaint(hWnd, &ps);
			break;
		case WM_DESTROY:
			delete klocek;
			delete bot_block;
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


