// InfoManageFrm.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "InfoManageFrm.h"


// CInfoManageFrm

IMPLEMENT_DYNCREATE(CInfoManageFrm, CMDIChildWndEx)

CInfoManageFrm::CInfoManageFrm()
{

}

CInfoManageFrm::~CInfoManageFrm()
{
}


BEGIN_MESSAGE_MAP(CInfoManageFrm, CMDIChildWndEx)
END_MESSAGE_MAP()



// CInfoManageFrm �޽��� ó�����Դϴ�.

BOOL CInfoManageFrm::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
	BOOL check = m_wndSplitter.Create(this,
		2, 2,			// TODO: �� �� ���� ������ �����մϴ�.
		CSize(10, 10),	// TODO: �ּ� â ũ�⸦ �����մϴ�.
		pContext);

	return check;
}

BOOL CInfoManageFrm::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡�� Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.
	if (!CMDIChildWndEx::PreCreateWindow(cs))
		return FALSE;

	cs.style &= ~(LONG)FWS_ADDTOTITLE;
	cs.lpszName = _T("���� ����");

	return TRUE;
}
