// InfoManageDoc.cpp : 구현 파일입니다.
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


// CInfoManageDoc 진단입니다.

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
// CInfoManageDoc serialization입니다.

void CInfoManageDoc::Serialize(CArchive& ar)
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


// CInfoManageDoc 명령입니다.
