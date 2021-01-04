#pragma once
#include "afxwin.h"
class CCheckDoc :
	public CDocument
{
	DECLARE_DYNCREATE(CCheckDoc)
public:
	CCheckDoc();
	~CCheckDoc();
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
protected:
	DECLARE_MESSAGE_MAP()
};

