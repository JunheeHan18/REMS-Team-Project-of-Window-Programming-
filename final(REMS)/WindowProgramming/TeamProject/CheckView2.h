#pragma once

#include "afxcmn.h"
#include "resource.h"
// �� �߰�
class CTabCheckRequest;
class TabEquipChkList;


// CCheckView2 �� ���Դϴ�.

class CCheckView2 : public CFormView
{
	DECLARE_DYNCREATE(CCheckView2)

public:
	CTabCheckRequest *pCheckRequest;
	TabEquipChkList *pCheckRequest2;


protected:
	CCheckView2();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_Tab;
	virtual void OnInitialUpdate();
	afx_msg void OnTcnSelchangeTabCheck2(NMHDR *pNMHDR, LRESULT *pResult);
};


