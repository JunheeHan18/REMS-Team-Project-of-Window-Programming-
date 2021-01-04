// EquipStatusDoc.cpp : 구현 파일입니다.
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


// CEquipStatusDoc 진단입니다.

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
// CEquipStatusDoc serialization입니다.

void CEquipStatusDoc::Serialize(CArchive& ar)
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


// CEquipStatusDoc 명령입니다.
