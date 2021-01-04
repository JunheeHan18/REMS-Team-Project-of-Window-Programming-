// EquipStatusView.cpp : 구현 파일입니다.
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


// CEquipStatusView 진단입니다.

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


// CEquipStatusView 메시지 처리기입니다.


void CEquipStatusView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_Tab.InsertItem(0, _T("장비현황"));
	m_Tab.InsertItem(1, _T("장애장비현황"));
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
