
// TeamProjectView.cpp : CTeamProjectView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "TeamProject.h"
#endif

#include "TeamProjectSet.h"
#include "TeamProjectDoc.h"
#include "TeamProjectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTeamProjectView

IMPLEMENT_DYNCREATE(CTeamProjectView, CRecordView)

BEGIN_MESSAGE_MAP(CTeamProjectView, CRecordView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTeamProjectView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTeamProjectView 생성/소멸

CTeamProjectView::CTeamProjectView()
	: CRecordView(CTeamProjectView::IDD)
	, m_RdSet(NULL)
{
	m_pSet = NULL;
	// TODO: 여기에 생성 코드를 추가합니다.

}

CTeamProjectView::~CTeamProjectView()
{
}

void CTeamProjectView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 컨트롤을 데이터베이스 필드에 '연결'하기 위해 여기에 DDX_Field* 함수를 삽입할 수 있습니다. 예:
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 자세한 내용은 MSDN 및 ODBC 샘플을 참조하십시오.
}

BOOL CTeamProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CRecordView::PreCreateWindow(cs);
}

void CTeamProjectView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_TeamProjectSet;
	CRecordView::OnInitialUpdate();

	CTeamProjectSet RdSet(m_pSet->m_pDatabase);
	m_RdSet = &RdSet;
}


// CTeamProjectView 인쇄


void CTeamProjectView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTeamProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CTeamProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CTeamProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CTeamProjectView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTeamProjectView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTeamProjectView 진단

#ifdef _DEBUG
void CTeamProjectView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CTeamProjectView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CTeamProjectDoc* CTeamProjectView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTeamProjectDoc)));
	return (CTeamProjectDoc*)m_pDocument;
}
#endif //_DEBUG


// CTeamProjectView 데이터베이스 지원
CRecordset* CTeamProjectView::OnGetRecordset()
{
	return m_pSet;
}


void CTeamProjectView::MainMessage() {
	AfxMessageBox(_T("Hi"));
}

// CTeamProjectView 메시지 처리기


CTeamProjectSet* CTeamProjectView::GetRdSet()
{
	//CTeamProjectSet RdSet(m_pSet->m_pDatabase);
	OnInitialUpdate();

	return m_RdSet;
}
