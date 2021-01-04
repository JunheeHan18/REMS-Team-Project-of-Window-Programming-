
// LogSenderDlg.h : 헤더 파일
//

#pragma once
#include "afxsock.h"


// CLogSenderDlg 대화 상자
class CLogSenderDlg : public CDialogEx
{
// 생성입니다.
public:
	CLogSenderDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_LOGSENDER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
