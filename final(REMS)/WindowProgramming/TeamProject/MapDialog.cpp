// MapDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "MapDialog.h"
#include "afxdialogex.h"
#include "resource.h"


// CMapDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMapDialog, CDialogEx)

CMapDialog::CMapDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMapDialog::IDD, pParent)
{

}

CMapDialog::~CMapDialog()
{
}

void CMapDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER_MAP, m_Explorer_Map);
}


BEGIN_MESSAGE_MAP(CMapDialog, CDialogEx)
END_MESSAGE_MAP()


// CMapDialog 메시지 처리기입니다.


BOOL CMapDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_Explorer_Map.Navigate(L"http://map.vworld.kr/map/maps.do", NULL, NULL, NULL, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
