#pragma once
#include <commdlg.h>

class CTool
{
public:
	CTool();
	~CTool();

	/************************************************************************/
	/* 转成string                                                                     */
	/************************************************************************/
	static string TCHAR2STRING(const TCHAR * str);
	static string WCHAR2STRING(const WCHAR * str);
	static string CHAR2STRING(const CHAR * str);

	/************************************************************************/
	/* 转成char                                                                     */
	/************************************************************************/
	static CHAR* STRING2CHAR(const string & str);
	static CHAR* WCHAR2CHAR_LEAK(const WCHAR* str);

	/************************************************************************/
	/* 转成WCHAR                                                                     */
	/************************************************************************/
	static WCHAR* CHAR2WCHAR_LEAK(const CHAR* str);
	static WCHAR* STRING2WCHAR_LEAK(const string& str);

	/************************************************************************/
	/* 窗口控制                                                                     */
	/************************************************************************/
	static void centerWindow(HWND hWnd);
	static void maximizeWindow(HWND hWnd);

	/************************************************************************/
	/* RGB转HSB(HSV)            
	/* 转换原理
	/* https://zh.wikipedia.org/zh-hans/HSL%E5%92%8CHSV%E8%89%B2%E5%BD%A9%E7%A9%BA%E9%97%B4
	/************************************************************************/
	typedef struct HSB{
		int	 Hue;			//色相(0~360)
		BYTE Saturation;	//饱和度(0~100)
		BYTE Brightness;	//明度(Value)(0~100)
	}HSV;

	static HSB RGB2HSB(BYTE r, BYTE g, BYTE b);
	static HSV RGB2HSV(BYTE r, BYTE g, BYTE b);
};

