
// ChildFrm.cpp : CChildFrame 클래스의 구현
//

#include "stdafx.h"
#include "TeamProject.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndEx)
//	ON_WM_SYSCOMMAND()
END_MESSAGE_MAP()

// CChildFrame 생성/소멸

CChildFrame::CChildFrame()
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
}

CChildFrame::~CChildFrame()
{
}

BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
	return m_wndSplitter.Create(this,
		2, 2,			// TODO: 행 및 열의 개수를 조정합니다.
		CSize(10, 10),	// TODO: 최소 창 크기를 조정합니다.
		pContext);
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서 Window 클래스 또는 스타일을 수정합니다.
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	cs.style &= ~(LONG)FWS_ADDTOTITLE;
	cs.lpszName = _T("프로그램");
	return TRUE;
}

// CChildFrame 진단

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// CChildFrame 메시지 처리기


//void CChildFrame::OnSysCommand(UINT nID, LPARAM lParam)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	AfxMessageBox(_T("Hi"));
//	
//	if (nID == SC_CLOSE)
//	{
//		AfxMessageBox(_T("닫지마"));
//	}
//
//	CMDIChildWndEx::OnSysCommand(nID, lParam);
//}
