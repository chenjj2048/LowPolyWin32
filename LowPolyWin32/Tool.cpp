#include "stdafx.h"
#include "Tool.h"

CTool::CTool()
{
}


CTool::~CTool()
{
}

/************************************************************************/
/* 转成string                                                                     */
/************************************************************************/
std::string CTool::TCHAR2STRING(const TCHAR * str)
{
#ifdef UNICODE
	return CTool::WCHAR2STRING(str);
#else
	return CTool::CHAR2STRING(str);
#endif
}

std::string CTool::WCHAR2STRING(const WCHAR * str)
{
	if (str == NULL)
		return "";

	int iLen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	char* chRtn = new char[iLen*sizeof(char)];
	WideCharToMultiByte(CP_ACP, 0, str, -1, chRtn, iLen, NULL, NULL);

	string result(chRtn);
	delete[] chRtn;
	return result;
}

std::string CTool::CHAR2STRING(const CHAR * str)
{
	if (str == NULL)
		return "";
	return string(str);
}

/************************************************************************/
/* 转成char                                                                     */
/************************************************************************/
CHAR* CTool::STRING2CHAR(const string & str)
{
	return (CHAR*)str.c_str();
}

CHAR* CTool::WCHAR2CHAR_LEAK(const WCHAR* str)
{
	int nLen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	if (nLen == 0)
	{
		return NULL;
	}

	//这里没有delete，稍后delete
	char* pResult = new char[nLen];
	WideCharToMultiByte(CP_ACP, 0, str, -1, pResult, nLen, NULL, NULL);
	return pResult;
}

/************************************************************************/
/* 转成WCHAR                                                                     */
/************************************************************************/
WCHAR* CTool::CHAR2WCHAR_LEAK(const CHAR* str)
{
	int nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str, -1, NULL, 0);
	if (nLen == 0)
	{
		return NULL;
	}
	wchar_t* pResult = new wchar_t[nLen];
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str, -1, pResult, nLen);
	return pResult;
}

WCHAR* CTool::STRING2WCHAR_LEAK(const string& str)
{
	if (str.empty())
		return NULL;
	return CTool::CHAR2WCHAR_LEAK(str.c_str());
}


/************************************************************************/
/* 窗口控制                                                                     */
/************************************************************************/
void CTool::centerWindow(HWND hWnd)
{
	RECT mRect;

	GetWindowRect(hWnd, &mRect);
	int	mWidth = GetSystemMetrics(SM_CXSCREEN);
	int	mHeight = GetSystemMetrics(SM_CYSCREEN);

	int left = (mWidth - mRect.right) / 2;
	int top = (mHeight - mRect.bottom) / 2;

	MoveWindow(hWnd, left, top, mRect.right, mRect.bottom, TRUE);
}

void CTool::maximizeWindow(HWND hWnd)
{
	int	mWidth = GetSystemMetrics(SM_CXSCREEN);
	int	mHeight = GetSystemMetrics(SM_CYSCREEN);

	MoveWindow(hWnd, 0, 0, mWidth, mHeight, TRUE);
}

CTool::HSB CTool::RGB2HSB(BYTE r, BYTE g, BYTE b)
{
	return RGB2HSV(r, g, b);
}

CTool::HSV CTool::RGB2HSV(BYTE r, BYTE g, BYTE b)
{
	int maxV = max(r, max(g, b));
	int minV = min(r, min(g, b));

	HSB hsb;

	//色相
	if (maxV == minV){
		hsb.Hue = 0;
	}
	else if (maxV == r && g >= b){
		hsb.Hue = 60 * (g - b) / (maxV - minV) + 0;
	}
	else if (maxV == r && g < b){
		hsb.Hue = 60 * (g - b) / (maxV - minV) + 360;
	}
	else if (maxV == g){
		hsb.Hue = 60 * (b - r) / (maxV - minV) + 120;
	}
	else if (maxV == b){
		hsb.Hue = 60 * (r - g) / (maxV - minV) + 240;
	}
	hsb.Hue = (BYTE)(hsb.Hue + 0.5);

	//饱和度
	if (maxV == 0){
		hsb.Saturation = 0;
	}
	else{
		hsb.Saturation = (BYTE)(100 - 100.0 * minV / maxV + 0.5);
	}

	//明度
	hsb.Brightness = (BYTE)(maxV / 255.0 * 100 + 0.5);
	return hsb;
}
