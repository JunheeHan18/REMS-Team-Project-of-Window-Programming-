// CheckView2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "CheckView2.h"

//탭추가
#include "TabCheckRequest.h"
#include "TabEquipChkList.h"

// CCheckView2

IMPLEMENT_DYNCREATE(CCheckView2, CFormView)

CCheckView2::CCheckView2()
	: CFormView(CCheckView2::IDD)
{

}

CCheckView2::~CCheckView2()
{
}

void CCheckView2::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_CHECK_2, m_Tab);
}

BEGIN_MESSAGE_MAP(CCheckView2, CFormView)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_CHECK_2, &CCheckView2::OnTcnSelchangeTabCheck2)
END_MESSAGE_MAP()


// CCheckView2 진단입니다.

#ifdef _DEBUG
void CCheckView2::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CCheckView2::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CCheckView2 메시지 처리기입니다.

void CCheckView2::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_Tab.InsertItem(0, _T("점검 요청"));
	m_Tab.InsertItem(1, _T("점검요청 내역관리"));

	m_Tab.SetCurSel(0);

	CRect rect;
	m_Tab.GetWindowRect(&rect);

	pCheckRequest = new CTabCheckRequest;
	pCheckRequest->Create(IDD_DIALOG_CHECK, &m_Tab);
	pCheckRequest->MoveWindow(0, 25, rect.Width(), rect.Height());
	pCheckRequest->ShowWindow(SW_SHOW);

	pCheckRequest2 = new TabEquipChkList;
	pCheckRequest2->Create(IDD_EQUIPCHECKLIST, &m_Tab);
	pCheckRequest2->MoveWindow(0, 25, rect.Width(), rect.Height());
	pCheckRequest2->ShowWindow(SW_HIDE);
}
void CCheckView2::OnTcnSelchangeTabCheck2(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int sel = m_Tab.GetCurSel();

	switch (sel) {
	case 0:
		pCheckRequest->ShowWindow(SW_SHOW);
		pCheckRequest2->ShowWindow(SW_HIDE);
		pCheckRequest->UpdateList();
		break;
	case 1:
		pCheckRequest->ShowWindow(SW_HIDE);
		pCheckRequest2->ShowWindow(SW_SHOW);
		pCheckRequest2->UpdateList();

		break;
	}
	
	*pResult = 0;
}
