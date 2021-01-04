// InfoManageView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "InfoManageView.h"

// �� �߰�
#include "TabRegBase.h"
#include "TabBaseConf.h"

#include "EnclBaseDialog.h"
#include "EnclBaseResource.h"

// CInfoManageView

IMPLEMENT_DYNCREATE(CInfoManageView, CFormView)

CInfoManageView::CInfoManageView()
	: CFormView(CInfoManageView::IDD)
{

}

CInfoManageView::~CInfoManageView()
{
}

void CInfoManageView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_Tab);
}

BEGIN_MESSAGE_MAP(CInfoManageView, CFormView)
//	ON_WM_LBUTTONDOWN()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CInfoManageView::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CInfoManageView �����Դϴ�.

#ifdef _DEBUG
void CInfoManageView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CInfoManageView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CInfoManageView �޽��� ó�����Դϴ�.


//void CInfoManageView::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
//
//	CFormView::OnLButtonDown(nFlags, point);
//}


//BOOL CInfoManageView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
//{
//	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
//
//	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
//}


void CInfoManageView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_Tab.InsertItem(0, _T("��ü ���"));
	m_Tab.InsertItem(1, _T("��ü ��� ����"));

	m_Tab.SetCurSel(0);

	CRect rect;
	m_Tab.GetWindowRect(&rect);

	pRegBase = new CTabRegBase;
	pRegBase->Create(IDD_DIALOG_REGBASE, &m_Tab);
	pRegBase->MoveWindow(0, 25, rect.Width(), rect.Height());
	pRegBase->ShowWindow(SW_SHOW);

	pEnclBase = new EnclBaseDialog;
	pEnclBase->Create(IDD_DIALOG_ENCLBASE, &m_Tab);
	pEnclBase->MoveWindow(0, 25, rect.Width(), rect.Height());
	pEnclBase->ShowWindow(SW_HIDE);
}

void CInfoManageView::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int sel = m_Tab.GetCurSel();

	switch (sel) {
	case 0:
		pRegBase->ShowWindow(SW_SHOW);
		pEnclBase->ShowWindow(SW_HIDE);
		break;
	case 1:
		pRegBase->ShowWindow(SW_HIDE);
		pEnclBase->ShowWindow(SW_SHOW);
		break;
	}
	
	*pResult = 0;
}

