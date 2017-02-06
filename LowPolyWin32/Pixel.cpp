#include "stdafx.h"
#include "Pixel.h"
#include "Tool.h"

/************************************************************************/
/* GDI+Í·ÎÄ¼þ                                                                     */
/************************************************************************/
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

CPixel::CPixel()
{
}


CPixel::~CPixel()
{
}

void CPixel::convertRGBToHSB()
{
	BYTE r = this->GetRed();
	BYTE g = this->GetGreen();
	BYTE b = this->GetBlue();

	this->hsb= CTool::RGB2HSB(r, g, b);
}
