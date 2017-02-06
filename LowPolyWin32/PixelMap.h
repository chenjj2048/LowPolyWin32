#pragma once
#include "Pixel.h"
/************************************************************************/
/* GDI+ͷ�ļ�                                                                     */
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
	//ͼƬ����
	CPixel *mPoints;

	//ͼƬ���
	UINT WIDTH;
	UINT HEIGHT;
};

