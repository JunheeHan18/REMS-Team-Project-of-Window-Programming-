// EquipStatusDoc.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "EquipStatusDoc.h"


// CEquipStatusDoc

IMPLEMENT_DYNCREATE(CEquipStatusDoc, CDocument)

CEquipStatusDoc::CEquipStatusDoc()
{
}

BOOL CEquipStatusDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CEquipStatusDoc::~CEquipStatusDoc()
{
}


BEGIN_MESSAGE_MAP(CEquipStatusDoc, CDocument)
END_MESSAGE_MAP()


// CEquipStatusDoc �����Դϴ�.

#ifdef _DEBUG
void CEquipStatusDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CEquipStatusDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CEquipStatusDoc serialization�Դϴ�.

void CEquipStatusDoc::Serialize(CArchive& ar)
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


// CEquipStatusDoc ����Դϴ�.
