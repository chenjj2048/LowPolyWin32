// LowPolyWin32.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "LowPolyWin32.h"
#include "MainApp.h"

INT_PTR CALLBACK	DlgProc(HWND, UINT, WPARAM, LPARAM);

CMainApp *mMainApp;
HINSTANCE g_hInstance;

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	MSG msg;
	HWND hWnd;

	g_hInstance = hInstance;
	hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINDIALOG),
		GetDesktopWindow(), (DLGPROC)DlgProc);
	if (!hWnd) return -1;

	mMainApp = new CMainApp(hWnd);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	// 主消息循环: 
	while (GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	SAFE_DELETE(mMainApp);
	return 0;
}


INT_PTR CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_INITDIALOG:
		//加载主菜单
		SetMenu(hWnd, LoadMenu(g_hInstance, MAKEINTRESOURCE(IDR_MENU_MAIN)));
		mMainApp->onInitDialog(hWnd);
		break;

	case WM_SYSCOMMAND:
		if (wParam == SC_CLOSE)
			PostQuitMessage(0);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_COMMAND:
		mMainApp->onCommand(hWnd, wParam, lParam);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		mMainApp->onPaint(hWnd, hdc, ps);
		EndPaint(hWnd, &ps);
		break;

	case WM_CLOSE:
		break;

	default:
		return false;
		//return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
