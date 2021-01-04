#pragma once


// CInfoManageFrm

class CInfoManageFrm : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CInfoManageFrm)

public:
	CInfoManageFrm();
	virtual ~CInfoManageFrm();
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	DECLARE_MESSAGE_MAP()
	CSplitterWndEx m_wndSplitter;
};


