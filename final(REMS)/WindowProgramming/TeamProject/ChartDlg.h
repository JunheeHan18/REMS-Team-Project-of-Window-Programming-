#pragma once
#include "ChartViewer.h"


// CChartDlg 대화 상자입니다.

class CChartDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChartDlg)

public:
	CChartDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CChartDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHART};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CChartViewer m_ChartViewer;
};
