// InfoManageDoc.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "InfoManageDoc.h"


IMPLEMENT_DYNCREATE(CInfoManageDoc, CDocument)

CInfoManageDoc::CInfoManageDoc()
{
}

BOOL CInfoManageDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CInfoManageDoc::~CInfoManageDoc()
{
}


BEGIN_MESSAGE_MAP(CInfoManageDoc, CDocument)
END_MESSAGE_MAP()


// CInfoManageDoc �����Դϴ�.

#ifdef _DEBUG
void CInfoManageDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CInfoManageDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CInfoManageDoc serialization�Դϴ�.

void CInfoManageDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}
#endif


// CInfoManageDoc ����Դϴ�.
