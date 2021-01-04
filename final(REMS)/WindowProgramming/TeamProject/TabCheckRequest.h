#pragma once
#include "afxdialogex.h"
#include "TeamProjectSet.h"
#include "afxwin.h"
#include "TabCheckRequestTable.h"
#include "resource.h"
class CTabCheckRequest : public CDialogEx
{
	DECLARE_DYNAMIC(CTabCheckRequest)
public:
	CTeamProjectSet* m_pSet;
	CTabCheckRequest(CWnd* pParent = NULL);
	virtual ~CTabCheckRequest();

	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_CHECK };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListCtrl;
	long	m_RequestIndex;
	long	m_EnclosureIndex;
	CStringW	m_EquipModelName;
	CStringW	m_CheckType;	//��������, ��)����
	CString	m_RequestDate;	//��û�ð�, ��)2014-08-21
	CStringW	m_RequestDescription;
	BOOL	m_Checked;
	CString	m_CheckedDate;	//��û�ð�, ��)2014-08-21
	int m_nSelected;
	int m_Index;
	 CString typeArray[200];  // ��ġ ������ �𵨸� ����
	 static int typeCount[200]; // ��Ʈ�� �� ���Ÿ���� ī��Ʈ�� ��� �迭
	 static int ArrayCnt;
	 int m_bCom=0;
	BOOL m_typeCheck = FALSE;
	void UpdateList();
	CString CheckArray[100];
	CString m_strRequest;
	CListCtrl m_LIstRequest;
	CComboBox m_comRequest;
	virtual BOOL OnInitDialog();
	//	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	void CTabCheckRequest::OnLvnColumnclickListData(NMHDR *pNMHDR, LRESULT *pResult);
	
	void CTabCheckRequest::OnLvnItemchangedListData(NMHDR *pNMHDR, LRESULT *pResult);

	//afx_msg void OnLvnItemchangedListData2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHdnItemStateIconClickListData2(NMHDR *pNMHDR, LRESULT *pResult);
	//void CTabCheckRequest::CheckAllItems(BOOL fChecked);
	//void CTabCheckRequest::SetHeaderCheckbox(void);
	afx_msg void OnCbnSelchangeComboView();
	
	void InputCombo(CString str);
	afx_msg void OnCbnSelchangeComboRequest();
	afx_msg void OnBnClickedButtonRequest();
	CString strArray[500];
	CString Check[500];
	int cnt = 0,getComIdx,getComidx2;
	afx_msg void OnEnChangeEditRequest();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void InsertCheckHeader();
	BOOL m_bChecked = FALSE;
	BOOL m_bCheckList = FALSE;
	afx_msg void OnBnClickedButtonCancel();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	void CountType();
	afx_msg void OnPaint();
	afx_msg void OnLvnItemchangedListData2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickListData2(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
