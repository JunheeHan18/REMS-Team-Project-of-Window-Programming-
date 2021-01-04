
// LogSenderDlg.h : ��� ����
//

#pragma once
#include "afxsock.h"


// CLogSenderDlg ��ȭ ����
class CLogSenderDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CLogSenderDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_LOGSENDER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	static UINT ThreadSend(LPVOID arg);

	CString m_Group1;
	CString m_Group2;
	CString m_BaseLoc;
	CString m_Event;
	CString m_EventLog;
	afx_msg void OnBnClickedButtonSend();
	int m_SendFlag;
	CAsyncSocket m_Client;
	CWinThread* m_pThread;
	int m_SocketFlag;
};
