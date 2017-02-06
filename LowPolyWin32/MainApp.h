#pragma once
#include "PictureManager.h"

class CMainApp
{
public:
	CMainApp(HWND hWnd);
	~CMainApp();
	void onInitDialog(HWND hWnd);
	void onPaint(HWND hWnd, HDC hdc, PAINTSTRUCT ps);
	void onCommand(HWND hWnd, WPARAM wParam, LPARAM lParam);

private:
	void centerWindow(HWND hWnd);
	void maximizeWindow(HWND hWnd);
	void loadAndDrawPicture(HWND hWnd);
	string getPictureFilePath();

	CPictureManager *mAdapter;
};

