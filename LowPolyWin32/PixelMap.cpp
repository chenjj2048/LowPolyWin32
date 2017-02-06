#include "stdafx.h"
#include "PixelMap.h"
#include "Pixel.h"

/************************************************************************/
/* GDI+头文件                                                                     */
/************************************************************************/
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;


CPixelMap::CPixelMap()
{
}


CPixelMap::~CPixelMap()
{
	SAFE_DELETE_ARRAY(mPoints);
}

/************************************************************************/
/* 转成数组形式                                                                     */
/************************************************************************/
void CPixelMap::saveDataToArray(Bitmap *bitmap)
{
	SAFE_DELETE_ARRAY(mPoints);

	WIDTH = bitmap->GetWidth();
	HEIGHT = bitmap->GetHeight();

	mPoints = new CPixel[WIDTH*HEIGHT];
	CPixel *mCurrentPoint;

	for (UINT x = 0; x < WIDTH; ++x)
	for (UINT y = 0; y < HEIGHT; ++y){
		mCurrentPoint = &mPoints[y*HEIGHT + x];
		bitmap->GetPixel(x, y, mCurrentPoint);
		mCurrentPoint->convertRGBToHSB();
	}
}
