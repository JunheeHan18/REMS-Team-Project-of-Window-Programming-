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
// CInfoManageDoc serialization입니다.

void CCheckDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}
#endif


