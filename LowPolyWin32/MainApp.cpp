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
/* �ַ��ĵ����Ϣ                                                                     */
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
/* ���ػ���ͼƬ                                                                    */
/************************************************************************/
void CMainApp::loadAndDrawPicture(HWND hWnd)
{
	//ѡ���ļ�
	string strFile = getPictureFilePath();
	if (strFile.empty()) return;
	
	//���ء���ʾ�ļ�
	mAdapter->loadFile(strFile);
	mAdapter->show();
}

/************************************************************************/
/* ��ϵͳ��ѡ��һ��ͼƬ�ļ�                                                                      */
/************************************************************************/
string CMainApp::getPictureFilePath()
{
	return "R:\\a.jpg";
	TCHAR strFileName[MAX_PATH] = { 0 };
	OPENFILENAME ofn = { 0 };
	ofn.lStructSize = sizeof(OPENFILENAME);//�ṹ���С  
	ofn.hwndOwner = NULL;//ӵ���Ŵ��ھ����ΪNULL��ʾ�Ի����Ƿ�ģ̬�ģ�ʵ��Ӧ����һ�㶼Ҫ��������  
	ofn.lpstrFilter = TEXT("All Files\0*.*\0ͼ���ļ�(*.bmp;*.jpg)\0* .bmp; *.jpg\0\0");//���ù���  
	ofn.nFilterIndex = 2;//����������  
	ofn.lpstrFile = strFileName;//���շ��ص��ļ�����ע���һ���ַ���ҪΪNULL  
	ofn.nMaxFile = sizeof(strFileName);//����������  
	ofn.lpstrInitialDir = TEXT("R:\\");//��ʼĿ¼ΪĬ��  
	ofn.lpstrTitle = TEXT("��ѡ��һ���ļ�");//ʹ��ϵͳĬ�ϱ������ռ���  
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;//�ļ���Ŀ¼������ڣ�����ֻ��ѡ��  

	if (GetOpenFileName(&ofn))
		return CTool::TCHAR2STRING(strFileName);
	else
		return "";
}


