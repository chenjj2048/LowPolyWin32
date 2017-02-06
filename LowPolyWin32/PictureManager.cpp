#include "stdafx.h"
#include "PictureManager.h"
#include <assert.h>
#include "Tool.h"

/************************************************************************/
/* GDI+头文件                                                                     */
/************************************************************************/
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

CPictureManager::CPictureManager(HWND hWnd)
{
	Gdiplus::GdiplusStartup(&gdiToken, &gdiStartupInput, NULL);
	graphics = new Gdiplus::Graphics(hWnd);

	//根据窗口大小设置图片显示大小
	RECT rect;
	GetClientRect(hWnd, &rect);
	const double SHOW_XY_RATIO = 0.6;
	maxClientWidth = rect.right * SHOW_XY_RATIO;
	maxClientHeight = rect.bottom * SHOW_XY_RATIO;
}

CPictureManager::~CPictureManager()
{
	SAFE_DELETE(strSavePath);
	SAFE_DELETE(graphics);
	Gdiplus::GdiplusShutdown(gdiToken);
}

void CPictureManager::loadFile(string &strFile)
{
	SAFE_DELETE(strSavePath);
	SAFE_DELETE(rawBitmap);

	strSavePath = CTool::STRING2WCHAR_LEAK(strFile);

	//加载原始图片
	rawBitmap = new Gdiplus::Bitmap(strSavePath);
	rawBitmap->FromFile(strSavePath);
	
	//以数组形式保存
	mPixelData.saveDataToArray(rawBitmap);
}

void CPictureManager::show()
{
	if (!rawBitmap || !graphics) return;

	UINT cx = rawBitmap->GetWidth();
	UINT cy = rawBitmap->GetHeight();

	/************************************************************************/
	/* 设定一定显示比例                                                               */
	/************************************************************************/
	float ratio = max(1.0*cx / maxClientWidth, 1.0*cy / maxClientHeight);
	if (ratio < 1)
		ratio = 1;

	graphics->ResetTransform();
	graphics->ScaleTransform(1/ratio, 1/ratio);
	graphics->SetCompositingQuality(CompositingQualityHighQuality);
	graphics->DrawImage(rawBitmap, 20, 20);
}

