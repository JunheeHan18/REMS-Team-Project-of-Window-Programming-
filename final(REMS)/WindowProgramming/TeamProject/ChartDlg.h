#pragma once
#include "ChartViewer.h"


// CChartDlg ��ȭ �����Դϴ�.

class CChartDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChartDlg)

public:
	CChartDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CChartDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHART};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CChartViewer m_ChartViewer;
};
