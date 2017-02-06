#pragma once
#include "Tool.h"
/************************************************************************/
/* GDI+头文件                                                                     */
/************************************************************************/
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

class CPixel:public Gdiplus::Color
{
public:
	CPixel();
	~CPixel();

	//色相Hue
	BYTE H;
	//饱和度Saturation
	BYTE S;
	//亮度V
	BYTE V;
	
	//根据RGB转HSB
	void convertRGBToHSB();

	 CTool::HSB hsb;
};

