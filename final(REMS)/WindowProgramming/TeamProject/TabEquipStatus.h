#pragma once


// CTabEquipStatus ��ȭ �����Դϴ�.

class CTabEquipStatus : public CDialogEx
{
	DECLARE_DYNAMIC(CTabEquipStatus)

public:
	CTabEquipStatus(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
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

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TAB_EQUIPSTATUS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedListequipstatus(NMHDR *pNMHDR, LRESULT *pResult);
};
