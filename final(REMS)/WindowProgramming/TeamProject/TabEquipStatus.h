#pragma once


// CTabEquipStatus 대화 상자입니다.

class CTabEquipStatus : public CDialogEx
{
	DECLARE_DYNAMIC(CTabEquipStatus)

public:
	CTabEquipStatus(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTabEquipStatus();
	CListCtrl m_ListCtrl;
	CString m_EquipStatus;
	CString m_EquipType;
	CString m_InstallLocate;
	CString m_ManuCorporation;
	CString m_ModelName;
	CString m_IP;
	CString m_InstallPurpose;
	int m_nSelected;
	void UpdateListCtrl();

	BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_TAB_EQUIPSTATUS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedListequipstatus(NMHDR *pNMHDR, LRESULT *pResult);
};
