// BaseInfoDoc.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "BaseInfoDoc.h"


// CBaseInfoDoc

IMPLEMENT_DYNCREATE(CBaseInfoDoc, CDocument)

CBaseInfoDoc::CBaseInfoDoc()
{
}

BOOL CBaseInfoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CBaseInfoDoc::~CBaseInfoDoc()
{
}


BEGIN_MESSAGE_MAP(CBaseInfoDoc, CDocument)
END_MESSAGE_MAP()


// CBaseInfoDoc 진단입니다.

#ifdef _DEBUG
void CBaseInfoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CBaseInfoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CBaseInfoDoc serialization입니다.

void CBaseInfoDoc::Serialize(CArchive& ar)
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


// CBaseInfoDoc 명령입니다.
