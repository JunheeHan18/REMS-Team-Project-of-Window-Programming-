#pragma once
#include "afxcmn.h"

// �� �߰�
class CTabRegBase;
class CTabBaseConf;
class EnclBaseDialog;

// CInfoManageView �� ���Դϴ�.

class CInfoManageView : public CFormView
{
	DECLARE_DYNCREATE(CInfoManageView)

public:
	CTabRegBase *pRegBase;
	EnclBaseDialog *pEnclBase;

protected:
	CInfoManageView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CInfoManageView();

public:
	enum { IDD = IDD_INFOMANAGEVIEW };
	
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	CTabCtrl m_Tab;
	virtual void OnInitialUpdate();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	
};


