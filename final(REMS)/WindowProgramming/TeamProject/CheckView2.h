#pragma once

#include "afxcmn.h"
#include "resource.h"
// 탭 추가
class CTabCheckRequest;
class TabEquipChkList;


// CCheckView2 폼 뷰입니다.

class CCheckView2 : public CFormView
{
	DECLARE_DYNCREATE(CCheckView2)

public:
	CTabCheckRequest *pCheckRequest;
	TabEquipChkList *pCheckRequest2;


protected:
	CCheckView2();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CCheckView2();

public:
	enum { IDD = IDD_CHECKVIEW };

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
	virtual void OnInitialUpdate();
	afx_msg void OnTcnSelchangeTabCheck2(NMHDR *pNMHDR, LRESULT *pResult);
};


