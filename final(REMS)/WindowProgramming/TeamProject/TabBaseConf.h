#pragma once
#include "afxcmn.h"


// CTabBaseConf ��ȭ �����Դϴ�.

class CTabBaseConf : public CDialogEx
{
	DECLARE_DYNAMIC(CTabBaseConf)

public:
	CTabBaseConf(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTabBaseConf();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_BASECONF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
