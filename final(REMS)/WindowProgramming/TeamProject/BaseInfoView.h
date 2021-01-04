#pragma once
#include "afxcmn.h"

class CTabEventLog;
class CTabSecurityLog;

// CBaseInfoView 폼 뷰입니다.

class CBaseInfoView : public CFormView
{
	DECLARE_DYNCREATE(CBaseInfoView)

protected:
	CBaseInfoView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CBaseInfoView();

public:
	enum { IDD = IDD_BASEINFOVIEW };
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
	CTabCtrl m_TabBaseInfoView;
	virtual void OnInitialUpdate();

	CTabEventLog *pTabEventLog;
	CTabSecurityLog *pTabSecurityLog;
	afx_msg void OnTcnSelchangeTabBaseinfoview(NMHDR *pNMHDR, LRESULT *pResult);
};


