#pragma once
#include "afxcmn.h"

#include "TabEquipStatus.h"
#include "TabErrorEquipStatus.h"

// CEquipStatusView 폼 뷰입니다.

class CTabEquipStatus;
class CTabErrorEquipStatus;

class CEquipStatusView : public CFormView
{
	DECLARE_DYNCREATE(CEquipStatusView)

protected:
	CEquipStatusView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CEquipStatusView();

public:
	enum { IDD = IDD_EQUIPSTATUSVIEW };
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
	CTabCtrl m_Tab;
	CTabEquipStatus *pTabEquipStatus;
	CTabErrorEquipStatus *pTabErrorEquipStatus;
	virtual void OnInitialUpdate();
	afx_msg void OnTcnSelchangeTabEquipstatus(NMHDR *pNMHDR, LRESULT *pResult);
};


