#include "stdafx.h"
#include "CheckDoc.h"
#include "TeamProject.h"
IMPLEMENT_DYNCREATE(CCheckDoc, CDocument)

CCheckDoc::CCheckDoc()
{
}
BOOL CCheckDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CCheckDoc::~CCheckDoc()
{
}



BEGIN_MESSAGE_MAP(CCheckDoc, CDocument)
END_MESSAGE_MAP()



#ifdef _DEBUG
void CCheckDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CCheckDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CInfoManageDoc serialization�Դϴ�.

void CCheckDoc::Serialize(CArchive& ar)
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


