
// TeamProject.h : TeamProject ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CTeamProjectApp:
// �� Ŭ������ ������ ���ؼ��� TeamProject.cpp�� �����Ͻʽÿ�.
//

class CTeamProjectApp : public CWinAppEx
{
public:
	CTeamProjectApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	CMultiDocTemplate* m_pDocTemplate;
	CMultiDocTemplate* m_pBaseInfoTemplate;
	CMultiDocTemplate* m_pInfoManageTemplate;
	CMultiDocTemplate* m_pCheckTemplate;
};

extern CTeamProjectApp theApp;
