// InfoManageFrm.cpp : 구현 파일입니다.
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



// CInfoManageFrm 메시지 처리기입니다.

BOOL CInfoManageFrm::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
	BOOL check = m_wndSplitter.Create(this,
		2, 2,			// TODO: 행 및 열의 개수를 조정합니다.
		CSize(10, 10),	// TODO: 최소 창 크기를 조정합니다.
		pContext);

	return check;
}

BOOL CInfoManageFrm::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서 Window 클래스 또는 스타일을 수정합니다.
	if (!CMDIChildWndEx::PreCreateWindow(cs))
		return FALSE;

	cs.style &= ~(LONG)FWS_ADDTOTITLE;
	cs.lpszName = _T("정보 관리");

	return TRUE;
}
