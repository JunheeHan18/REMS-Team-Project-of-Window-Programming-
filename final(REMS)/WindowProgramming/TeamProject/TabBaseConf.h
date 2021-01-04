#pragma once
#include "afxcmn.h"


// CTabBaseConf 대화 상자입니다.

class CTabBaseConf : public CDialogEx
{
	DECLARE_DYNAMIC(CTabBaseConf)

public:
	CTabBaseConf(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTabBaseConf();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_BASECONF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListDevice;
	CListCtrl m_ListHistory;
	long m_Index;
	CString m_LocationName;
	CString m_Equipment;
	CString m_State;
	CString m_Manufacturer;
	CString m_ModelName;
	CString m_IPAddress;
	CString m_Password;
	CString m_Etc;
	void UpdateListDevice();
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedListDevice(NMHDR *pNMHDR, LRESULT *pResult);
	int m_nSelected;
};
