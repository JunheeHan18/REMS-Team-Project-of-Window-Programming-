#pragma once
#include "afxcmn.h"

// 탭 추가
class CTabRegBase;
class CTabBaseConf;
class EnclBaseDialog;

// CInfoManageView 폼 뷰입니다.

class CInfoManageView : public CFormView
{
	DECLARE_DYNCREATE(CInfoManageView)

public:
	CTabRegBase *pRegBase;
	EnclBaseDialog *pEnclBase;

protected:
	CInfoManageView();           // 동적 만들기에 사용되는 protected 생성자입니다.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	CTabCtrl m_Tab;
	virtual void OnInitialUpdate();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	
};


