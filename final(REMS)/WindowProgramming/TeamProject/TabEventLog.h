#pragma once

class CUDPServer;
// CTabEventLog 대화 상자입니다.

class CTabEventLog : public CDialogEx
{
	DECLARE_DYNAMIC(CTabEventLog)

public:
	CListCtrl m_ListCtrl;
	CString m_GroupName1;	// 그룹명1
	CString m_GroupName2;	// 그룹명2
	CString m_EnclosureLocate;	// 함체위치명
	CString m_Event;		// 이벤트
	CString m_EventInfo;	// 이벤트 내용
	CString m_OccurDate;			// 발생 일시
	CString m_Date1;			// 기간1
	CString m_Date2;			// 기간2
	CString m_InOutName;		// 출입자명
	int m_nSelected;

	CTabEventLog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTabEventLog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_TAB_EVENT_LOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
