#pragma once
#include "PixelMap.h"
/************************************************************************/
/* GDI+ͷ�ļ�                                                                     */
/************************************************************************/
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;

class CPictureManager
{
public:
	CPictureManager(HWND hWnd);
	~CPictureManager();
	void loadFile(string &strFile);
	void show();
private:
	WCHAR *strSavePath;

	Gdiplus::Bitmap *rawBitmap;
	Gdiplus::Graphics *graphics;

	//GDI+��ʼ����������
	struct GdiplusStartupInput gdiStartupInput;
	ULONG_PTR gdiToken;

	//ͼƬ�����ʾ�ķ�Χ
	UINT maxClientWidth;
	UINT maxClientHeight;

	//��������
	CPixelMap mPixelData;
};

