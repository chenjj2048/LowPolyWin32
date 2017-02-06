#pragma once
#include <commdlg.h>

class CTool
{
public:
	CTool();
	~CTool();

	/************************************************************************/
	/* ת��string                                                                     */
	/************************************************************************/
	static string TCHAR2STRING(const TCHAR * str);
	static string WCHAR2STRING(const WCHAR * str);
	static string CHAR2STRING(const CHAR * str);

	/************************************************************************/
	/* ת��char                                                                     */
	/************************************************************************/
	static CHAR* STRING2CHAR(const string & str);
	static CHAR* WCHAR2CHAR_LEAK(const WCHAR* str);

	/************************************************************************/
	/* ת��WCHAR                                                                     */
	/************************************************************************/
	static WCHAR* CHAR2WCHAR_LEAK(const CHAR* str);
	static WCHAR* STRING2WCHAR_LEAK(const string& str);

	/************************************************************************/
	/* ���ڿ���                                                                     */
	/************************************************************************/
	static void centerWindow(HWND hWnd);
	static void maximizeWindow(HWND hWnd);

	/************************************************************************/
	/* RGBתHSB(HSV)            
	/* ת��ԭ��
	/* https://zh.wikipedia.org/zh-hans/HSL%E5%92%8CHSV%E8%89%B2%E5%BD%A9%E7%A9%BA%E9%97%B4
	/************************************************************************/
	typedef struct HSB{
		int	 Hue;			//ɫ��(0~360)
		BYTE Saturation;	//���Ͷ�(0~100)
		BYTE Brightness;	//����(Value)(0~100)
	}HSV;

	static HSB RGB2HSB(BYTE r, BYTE g, BYTE b);
	static HSV RGB2HSV(BYTE r, BYTE g, BYTE b);
};

