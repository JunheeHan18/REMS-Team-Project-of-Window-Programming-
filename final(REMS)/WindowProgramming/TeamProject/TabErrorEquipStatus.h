#pragma once


// CTabErrorEquipStatus ��ȭ �����Դϴ�.

class CTabErrorEquipStatus : public CDialogEx
{
	DECLARE_DYNAMIC(CTabErrorEquipStatus)

public:
	CTabErrorEquipStatus(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
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

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TAB_ERROREQUIPSTATUS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedListErrEquipStatus(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEquipstatus();
};
