// EquipStatusView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "EquipStatusView.h"
#include "Resource.h"

// CEquipStatusView

IMPLEMENT_DYNCREATE(CEquipStatusView, CFormView)

CEquipStatusView::CEquipStatusView()
	: CFormView(CEquipStatusView::IDD)
{

}

CEquipStatusView::~CEquipStatusView()
{
}

void CEquipStatusView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_EQUIPSTATUS, m_Tab);
}

BEGIN_MESSAGE_MAP(CEquipStatusView, CFormView)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_EQUIPSTATUS, &CEquipStatusView::OnTcnSelchangeTabEquipstatus)
END_MESSAGE_MAP()


// CEquipStatusView �����Դϴ�.

#ifdef _DEBUG
void CEquipStatusView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CEquipStatusView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CEquipStatusView �޽��� ó�����Դϴ�.


void CEquipStatusView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_Tab.InsertItem(0, _T("�����Ȳ"));
	m_Tab.InsertItem(1, _T("��������Ȳ"));
	m_Tab.SetCurSel(0);

	CRect rect;
	m_Tab.GetWindowRect(&rect);
	
	pTabEquipStatus = new CTabEquipStatus;
	pTabEquipStatus->Create(IDD_TAB_EQUIPSTATUS, &m_Tab);
	pTabEquipStatus->MoveWindow(0, 25, rect.Width(), rect.Height());
	pTabEquipStatus->ShowWindow(SW_SHOW);
	
	pTabErrorEquipStatus = new CTabErrorEquipStatus;
	pTabErrorEquipStatus->Create(IDD_TAB_ERROREQUIPSTATUS, &m_Tab);
	pTabErrorEquipStatus->MoveWindow(0, 25, rect.Width(), rect.Height());
	pTabErrorEquipStatus->ShowWindow(SW_HIDE);
}


void CEquipStatusView::OnTcnSelchangeTabEquipstatus(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int sel = m_Tab.GetCurSel();

	switch (sel) {
	case 0:
		pTabEquipStatus->ShowWindow(SW_SHOW);
		pTabErrorEquipStatus->ShowWindow(SW_HIDE);
		break;
	case 1:
		pTabEquipStatus->ShowWindow(SW_HIDE);
		pTabErrorEquipStatus->ShowWindow(SW_SHOW);
		break;
	}

	*pResult = 0;
}
