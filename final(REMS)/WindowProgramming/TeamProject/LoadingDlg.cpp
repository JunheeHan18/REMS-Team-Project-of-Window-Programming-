// LoadingDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "LoadingDlg.h"
#include "afxdialogex.h"


// CLoadingDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CLoadingDlg, CDialog)

CLoadingDlg::CLoadingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_LOADINGDLG, pParent)
{

}

CLoadingDlg::~CLoadingDlg()
{
}

void CLoadingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoadingDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CLoadingDlg 메시지 처리기입니다.


void CLoadingDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
	CDC MemDC;
	BITMAP bmpInfo;

	// 화면 DC와 호환되는 메모리 DC를 생성
	MemDC.CreateCompatibleDC(&dc);

	// 비트맵 리소스 로딩
	CBitmap bmp;
	CBitmap* pOldBmp = NULL;
	bmp.LoadBitmapW(IDB_BITMAP_LOGO);

	// 로딩된 비트맵 정보 확인
	bmp.GetBitmap(&bmpInfo);

	// 메모리 DC에 선택
	pOldBmp = MemDC.SelectObject(&bmp);

	// 메모리 DC에 들어 있는 비트맵을 화면 DC로 복사하여 출력
	dc.BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);

	MemDC.SelectObject(pOldBmp);
}


void CLoadingDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	::SendMessage(this->m_hWnd, WM_CLOSE, NULL, NULL);

	CDialog::OnLButtonDown(nFlags, point);
}
