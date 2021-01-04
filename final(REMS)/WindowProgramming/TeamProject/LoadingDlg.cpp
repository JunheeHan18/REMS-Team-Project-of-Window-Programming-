// LoadingDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "LoadingDlg.h"
#include "afxdialogex.h"


// CLoadingDlg ��ȭ �����Դϴ�.

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


// CLoadingDlg �޽��� ó�����Դϴ�.


void CLoadingDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
					   // �׸��� �޽����� ���ؼ��� CDialog::OnPaint()��(��) ȣ������ ���ʽÿ�.
	CDC MemDC;
	BITMAP bmpInfo;

	// ȭ�� DC�� ȣȯ�Ǵ� �޸� DC�� ����
	MemDC.CreateCompatibleDC(&dc);

	// ��Ʈ�� ���ҽ� �ε�
	CBitmap bmp;
	CBitmap* pOldBmp = NULL;
	bmp.LoadBitmapW(IDB_BITMAP_LOGO);

	// �ε��� ��Ʈ�� ���� Ȯ��
	bmp.GetBitmap(&bmpInfo);

	// �޸� DC�� ����
	pOldBmp = MemDC.SelectObject(&bmp);

	// �޸� DC�� ��� �ִ� ��Ʈ���� ȭ�� DC�� �����Ͽ� ���
	dc.BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);

	MemDC.SelectObject(pOldBmp);
}


void CLoadingDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	::SendMessage(this->m_hWnd, WM_CLOSE, NULL, NULL);

	CDialog::OnLButtonDown(nFlags, point);
}
