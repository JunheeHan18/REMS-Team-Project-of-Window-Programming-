#pragma once
#include "afxdialogex.h"
#include "TeamProjectSet.h"
#include "afxwin.h"
#include "TabCheckRequestTable.h"
#include "TabCheckRequest.h"

// TabEquipChkList 대화 상자입니다.

class TabEquipChkList : public CDialogEx
{
	DECLARE_DYNAMIC(TabEquipChkList)

public:
	TabEquipChkList(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~TabEquipChkList();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EQUIPCHECKLIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	bool m_check;
	CListCtrl m_ListCtrl;
	virtual BOOL OnInitDialog();
	void UpdateListDevice();
	int m_Index;
	int m_nSelected;
	CString m_EnclosureIndex;
	CString m_EquipModelName;
	CString m_CheckType;
	CString m_RequestDate;
	CString m_RequestDescript;
	CString m_CheckDate;
	int m_clickIndex;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	void OnLvnItemchangedListBase(NMHDR * pNMHDR, LRESULT * pResult);
	void OnLvnColumnclickListBase(NMHDR * pNMHDR, LRESULT * pResult);
	void UpdateList();
	void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedCheckconfirm();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonChartview();


	afx_msg void OnPaint();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
