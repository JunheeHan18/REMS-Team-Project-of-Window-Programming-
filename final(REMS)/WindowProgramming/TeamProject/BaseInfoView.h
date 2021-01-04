#pragma once
#include "afxcmn.h"

class CTabEventLog;
class CTabSecurityLog;

// CBaseInfoView �� ���Դϴ�.

class CBaseInfoView : public CFormView
{
	DECLARE_DYNCREATE(CBaseInfoView)

protected:
	CBaseInfoView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_TabBaseInfoView;
	virtual void OnInitialUpdate();

	CTabEventLog *pTabEventLog;
	CTabSecurityLog *pTabSecurityLog;
	afx_msg void OnTcnSelchangeTabBaseinfoview(NMHDR *pNMHDR, LRESULT *pResult);
};


