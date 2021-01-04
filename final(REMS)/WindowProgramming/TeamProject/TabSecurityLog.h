#pragma once


// CTabSecurityLog ��ȭ �����Դϴ�.

class CTabSecurityLog : public CDialogEx
{
	DECLARE_DYNAMIC(CTabSecurityLog)

public:
	CTabSecurityLog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTabSecurityLog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TAB_SECURITYLOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

public:
	CListCtrl m_ListCtrl;
	CString m_GroupName1;	// �׷�� 1
	CString	m_GroupName2;	// �׷�� 2
	CString m_EnclosureLocate;	// ��ü��ġ��
	CString m_EnteringTime;		// ����ð�
	CString m_GetOutTime;	// ����ð�
	CString m_OccurDate;	// �߻� �Ͻ�
	CString m_Date1;		// �Ⱓ 1
	CString m_Date2;		// �Ⱓ2
	CString m_InOutName;	// �����ڸ�
	int m_nSelected;

	void UpdateList();
	BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	afx_msg void OnLvnItemchangedSecuritylist(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEntertime();
};
