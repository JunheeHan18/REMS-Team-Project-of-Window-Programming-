
// TeamProjectView.cpp : CTeamProjectView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTeamProjectView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTeamProjectView ����/�Ҹ�

CTeamProjectView::CTeamProjectView()
	: CRecordView(CTeamProjectView::IDD)
	, m_RdSet(NULL)
{
	m_pSet = NULL;
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CTeamProjectView::~CTeamProjectView()
{
}

void CTeamProjectView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// ��Ʈ���� �����ͺ��̽� �ʵ忡 '����'�ϱ� ���� ���⿡ DDX_Field* �Լ��� ������ �� �ֽ��ϴ�. ��:
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �ڼ��� ������ MSDN �� ODBC ������ �����Ͻʽÿ�.
}

BOOL CTeamProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CRecordView::PreCreateWindow(cs);
}

void CTeamProjectView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_TeamProjectSet;
	CRecordView::OnInitialUpdate();

	CTeamProjectSet RdSet(m_pSet->m_pDatabase);
	m_RdSet = &RdSet;
}


// CTeamProjectView �μ�


void CTeamProjectView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTeamProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CTeamProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CTeamProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
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


// CTeamProjectView ����

#ifdef _DEBUG
void CTeamProjectView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CTeamProjectView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CTeamProjectDoc* CTeamProjectView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTeamProjectDoc)));
	return (CTeamProjectDoc*)m_pDocument;
}
#endif //_DEBUG


// CTeamProjectView �����ͺ��̽� ����
CRecordset* CTeamProjectView::OnGetRecordset()
{
	return m_pSet;
}


void CTeamProjectView::MainMessage() {
	AfxMessageBox(_T("Hi"));
}

// CTeamProjectView �޽��� ó����


CTeamProjectSet* CTeamProjectView::GetRdSet()
{
	//CTeamProjectSet RdSet(m_pSet->m_pDatabase);
	OnInitialUpdate();

	return m_RdSet;
}
