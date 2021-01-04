#pragma once

#include "TeamProjectSet.h"
#include "afxwin.h"
// CTabRegBase 대화 상자입니다.

class CTabRegBase : public CDialogEx
{
	DECLARE_DYNAMIC(CTabRegBase)

public:
	CTeamProjectSet* m_pSet;
	CTabRegBase(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTabRegBase();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_INFOMANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListCtrl;
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnColumnclickListBase(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_LocationName; // InstallLocation
	afx_msg void OnLvnItemchangedListBase(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_GropName1;
	CString m_GropName2;
	CString m_State;
	CString m_InstallationClassification; // InstallClassification
	CString m_InstallationAddress; // InstallAddress
	CString m_Etc;
	int m_nSelected;
	CString m_Index;
	void UpdateList();
	afx_msg void OnBnClickedButtonAdd();
	CString m_EnclosureID;
	CString m_MaintenanceIndex;
	CString m_Latitude;
	CString m_Longitude;
	CString m_IP;
	CString m_Port;
	CString m_InstallDate;
	CString m_InstallCompany;
	CString m_InstallCompanyCall;
	CString m_MaintainCompany;
	CString m_MaintainCompanyCall;
	void SetGroups(CString str);
	CString* m_Groups;
	int m_nGroups;
	CComboBox m_ComboGroup1;
	void SetGroups2(CString str);
	CComboBox m_ComboGroup2;
	CString* m_Groups2;
	int m_nGroups2;
	afx_msg void OnBnClickedButtonSelect();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonDelete();
};
