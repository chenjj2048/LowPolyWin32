#include "stdafx.h"
#include "MainApp.h"
#include "resource.h"
#include <commdlg.h>
#include "PictureManager.h"
#include "Tool.h"

CMainApp::CMainApp(HWND hWnd)
{
	mAdapter = new CPictureManager(hWnd);
}

CMainApp::~CMainApp()
{
	SAFE_DELETE(mAdapter);
}

/************************************************************************/
/* 分发的点击消息                                                                     */
/************************************************************************/
void CMainApp::onCommand(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	int lo = LOWORD(wParam);
	switch (lo)
	{
	case IDC_BTN_LOAD_PIC:
		loadAndDrawPicture(hWnd);
		break;
	case IDC_BTN_EXIT:
		PostMessage(hWnd, WM_DESTROY, NULL, NULL);
		break;
	}
}

void CMainApp::onInitDialog(HWND hWnd)
{
	CTool::maximizeWindow(hWnd);
}

void CMainApp::onPaint(HWND hWnd, HDC hdc, PAINTSTRUCT ps)
{
	mAdapter->show();
}


/************************************************************************/
/* 加载绘制图片                                                                    */
/************************************************************************/
void CMainApp::loadAndDrawPicture(HWND hWnd)
{
	//选择文件
	string strFile = getPictureFilePath();
	if (strFile.empty()) return;
	
	//加载、显示文件
	mAdapter->loadFile(strFile);
	mAdapter->show();
}

/************************************************************************/
/* 从系统中选择一个图片文件                                                                      */
/************************************************************************/
string CMainApp::getPictureFilePath()
{
	return "R:\\a.jpg";
	TCHAR strFileName[MAX_PATH] = { 0 };
	OPENFILENAME ofn = { 0 };
	ofn.lStructSize = sizeof(OPENFILENAME);//结构体大小  
	ofn.hwndOwner = NULL;//拥有着窗口句柄，为NULL表示对话框是非模态的，实际应用中一般都要有这个句柄  
	ofn.lpstrFilter = TEXT("All Files\0*.*\0图像文件(*.bmp;*.jpg)\0* .bmp; *.jpg\0\0");//设置过滤  
	ofn.nFilterIndex = 2;//过滤器索引  
	ofn.lpstrFile = strFileName;//接收返回的文件名，注意第一个字符需要为NULL  
	ofn.nMaxFile = sizeof(strFileName);//缓冲区长度  
	ofn.lpstrInitialDir = TEXT("R:\\");//初始目录为默认  
	ofn.lpstrTitle = TEXT("请选择一个文件");//使用系统默认标题留空即可  
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;//文件、目录必须存在，隐藏只读选项  

	if (GetOpenFileName(&ofn))
		return CTool::TCHAR2STRING(strFileName);
	else
		return "";
}


