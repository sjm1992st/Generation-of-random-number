
// rand.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"	
#include "Cpublic.h"// ������


// CrandApp: 
// �йش����ʵ�֣������ rand.cpp
//

class CrandApp : public CWinApp
{
public:
	CrandApp();
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CrandApp theApp;