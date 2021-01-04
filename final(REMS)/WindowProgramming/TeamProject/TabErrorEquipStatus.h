#pragma once


// CTabErrorEquipStatus 대화 상자입니다.

class CTabErrorEquipStatus : public CDialogEx
{
	DECLARE_DYNAMIC(CTabErrorEquipStatus)

public:
	CTabErrorEquipStatus(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTabErrorEquipStatus();
	CListCtrl m_ListCtrl;
	CString m_EquipStatus;
	CString m_CheckStatus;
	CString m_EquipType;
	CString m_InstallLocate;
	CString m_IP;
	CString m_ErrorDate;
	CString m_ErrorReason;
	int m_nSelected;
	void UpdateListDevice();
	virtual BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_TAB_ERROREQUIPSTATUS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedListErrEquipStatus(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEquipstatus();
};
