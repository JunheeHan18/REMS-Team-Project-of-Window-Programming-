
// LogSender.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CLogSenderApp:
// �� Ŭ������ ������ ���ؼ��� LogSender.cpp�� �����Ͻʽÿ�.
//

class CLogSenderApp : public CWinApp
{
public:
	CLogSenderApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CLogSenderApp theApp;