#pragma once
#include "afxwin.h"
#include "afxsplitterwndex.h"
class CCheckFrm :
	public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CCheckFrm)
public:
	CCheckFrm();
	~CCheckFrm();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	DECLARE_MESSAGE_MAP()
	CSplitterWndEx m_wndSplitter;
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	
};

