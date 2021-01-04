// ChartDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "ChartDlg.h"
#include "afxdialogex.h"
#include "ChartViewer.h"


// CChartDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CChartDlg, CDialogEx)

CChartDlg::CChartDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CHART, pParent)
{

}

CChartDlg::~CChartDlg()
{
}

void CChartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHART, m_ChartViewer);
}


BEGIN_MESSAGE_MAP(CChartDlg, CDialogEx)
END_MESSAGE_MAP()


// CChartDlg 메시지 처리기입니다.
