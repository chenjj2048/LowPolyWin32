#pragma once
#include "Tool.h"
/************************************************************************/
/* GDI+ͷ�ļ�                                                                     */
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

	//ɫ��Hue
	BYTE H;
	//���Ͷ�Saturation
	BYTE S;
	//����V
	BYTE V;
	
	//����RGBתHSB
	void convertRGBToHSB();

	 CTool::HSB hsb;
};

