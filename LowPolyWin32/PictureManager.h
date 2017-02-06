#pragma once
#include "PixelMap.h"
/************************************************************************/
/* GDI+头文件                                                                     */
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

	//GDI+初始化参数两个
	struct GdiplusStartupInput gdiStartupInput;
	ULONG_PTR gdiToken;

	//图片最大显示的范围
	UINT maxClientWidth;
	UINT maxClientHeight;

	//像素数据
	CPixelMap mPixelData;
};

