
// MFCLiveClient.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCLiveClientApp: 
// �йش����ʵ�֣������ MFCLiveClient.cpp
//

class CMFCLiveClientApp : public CWinApp
{
public:
	CMFCLiveClientApp();

// ��д
public:
	virtual BOOL InitInstance();
// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCLiveClientApp theApp;