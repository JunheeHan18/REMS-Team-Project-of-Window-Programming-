// BaseInfoDoc.cpp : ���� �����Դϴ�.
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


// CBaseInfoDoc �����Դϴ�.

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
// CBaseInfoDoc serialization�Դϴ�.

void CBaseInfoDoc::Serialize(CArchive& ar)
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


// CBaseInfoDoc ����Դϴ�.
