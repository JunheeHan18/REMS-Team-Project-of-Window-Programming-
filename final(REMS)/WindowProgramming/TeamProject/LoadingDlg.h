#pragma once


// CLoadingDlg ��ȭ �����Դϴ�.

class CLoadingDlg : public CDialog
{
	DECLARE_DYNAMIC(CLoadingDlg)

public:
	CLoadingDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CLoadingDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOADINGDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
