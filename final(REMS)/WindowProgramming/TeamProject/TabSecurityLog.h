#pragma once


// CTabSecurityLog 대화 상자입니다.

class CTabSecurityLog : public CDialogEx
{
	DECLARE_DYNAMIC(CTabSecurityLog)

public:
	CTabSecurityLog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTabSecurityLog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_TAB_SECURITYLOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

public:
	CListCtrl m_ListCtrl;
	CString m_GroupName1;	// 그룹명 1
	CString	m_GroupName2;	// 그룹명 2
	CString m_EnclosureLocate;	// 함체위치명
	CString m_EnteringTime;		// 입장시간
	CString m_GetOutTime;	// 퇴장시간
	CString m_OccurDate;	// 발생 일시
	CString m_Date1;		// 기간 1
	CString m_Date2;		// 기간2
	CString m_InOutName;	// 출입자명
	int m_nSelected;

	void UpdateList();
	BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	afx_msg void OnLvnItemchangedSecuritylist(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEntertime();
};
