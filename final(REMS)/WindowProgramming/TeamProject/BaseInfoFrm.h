#pragma once


// CBaseInfoFrm

class CBaseInfoFrm : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CBaseInfoFrm)

public:
	CBaseInfoFrm();
	virtual ~CBaseInfoFrm();

protected:
	DECLARE_MESSAGE_MAP()
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};


