// BaseInfoView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "BaseInfoView.h"

#include "TabEventLog.h"
#include "TabSecurityLog.h"

// CBaseInfoView

IMPLEMENT_DYNCREATE(CBaseInfoView, CFormView)

CBaseInfoView::CBaseInfoView()
	: CFormView(CBaseInfoView::IDD)
{

}

CBaseInfoView::~CBaseInfoView()
{
}

void CBaseInfoView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_BASEINFOVIEW, m_TabBaseInfoView);
}

BEGIN_MESSAGE_MAP(CBaseInfoView, CFormView)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_BASEINFOVIEW, &CBaseInfoView::OnTcnSelchangeTabBaseinfoview)
END_MESSAGE_MAP()


// CBaseInfoView �����Դϴ�.

#ifdef _DEBUG
void CBaseInfoView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CBaseInfoView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CBaseInfoView �޽��� ó�����Դϴ�.


void CBaseInfoView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_TabBaseInfoView.InsertItem(0, _T("�̺�Ʈ �α�"));
	m_TabBaseInfoView.InsertItem(1, _T("���Ժ��� �α�"));

	CRect rect;
	m_TabBaseInfoView.GetWindowRect(&rect);

	pTabEventLog = new CTabEventLog;
	pTabEventLog->Create(IDD_TAB_EVENT_LOG, &m_TabBaseInfoView);
	pTabEventLog->MoveWindow(0, 25, rect.Width(), rect.Height());
	pTabEventLog->ShowWindow(SW_SHOW);

	pTabSecurityLog = new CTabSecurityLog;
	pTabSecurityLog->Create(IDD_TAB_SECURITYLOG, &m_TabBaseInfoView);
	pTabSecurityLog->MoveWindow(0, 25, rect.Width(), rect.Height());
	pTabSecurityLog->ShowWindow(SW_HIDE);
}


void CBaseInfoView::OnTcnSelchangeTabBaseinfoview(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int sel = m_TabBaseInfoView.GetCurSel();

	switch (sel) {
	case 0:
		pTabEventLog->ShowWindow(SW_SHOW);
		pTabSecurityLog->ShowWindow(SW_HIDE);
		break;
	case 1:
		pTabEventLog->ShowWindow(SW_HIDE);
		pTabSecurityLog->ShowWindow(SW_SHOW);
		break;
	}

	*pResult = 0;
}
