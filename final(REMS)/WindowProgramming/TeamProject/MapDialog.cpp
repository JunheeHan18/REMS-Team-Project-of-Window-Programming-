// MapDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "MapDialog.h"
#include "afxdialogex.h"
#include "resource.h"


// CMapDialog ��ȭ �����Դϴ�.

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


// CMapDialog �޽��� ó�����Դϴ�.


BOOL CMapDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_Explorer_Map.Navigate(L"http://map.vworld.kr/map/maps.do", NULL, NULL, NULL, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
