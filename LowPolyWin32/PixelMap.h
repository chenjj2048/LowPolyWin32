#pragma once
#include "Pixel.h"
/************************************************************************/
/* GDI+头文件                                                                     */
/************************************************************************/
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;

class CPixelMap
{
public:
	CPixelMap();
	~CPixelMap();
	void saveDataToArray(Bitmap *bitmap);

private:
	//图片数组
	CPixel *mPoints;

	//图片宽高
	UINT WIDTH;
	UINT HEIGHT;
};

