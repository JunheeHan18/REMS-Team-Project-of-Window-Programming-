#pragma once

class CUDPServer;
// CTabEventLog ��ȭ �����Դϴ�.

class CTabEventLog : public CDialogEx
{
	DECLARE_DYNAMIC(CTabEventLog)

public:
	CListCtrl m_ListCtrl;
	CString m_GroupName1;	// �׷��1
	CString m_GroupName2;	// �׷��2
	CString m_EnclosureLocate;	// ��ü��ġ��
	CString m_Event;		// �̺�Ʈ
	CString m_EventInfo;	// �̺�Ʈ ����
	CString m_OccurDate;			// �߻� �Ͻ�
	CString m_Date1;			// �Ⱓ1
	CString m_Date2;			// �Ⱓ2
	CString m_InOutName;		// �����ڸ�
	int m_nSelected;

	CTabEventLog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTabEventLog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TAB_EVENT_LOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	void UpdateList();
	BOOL OnInitDialog();
	
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLbnSelchangeList2();
	afx_msg void OnLvnItemchangedEventlist(NMHDR *pNMHDR, LRESULT *pResult);
	void ReceiveUpdate(CString ReceiveBuf);
	CUDPServer* m_Server;
	CTabEventLog* m_pThis;
	int m_ColumnFlag;
};
