#pragma once


// CEquipStatusFrm

class CEquipStatusFrm : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CEquipStatusFrm)

public:
	CEquipStatusFrm();
	virtual ~CEquipStatusFrm();

protected:
	DECLARE_MESSAGE_MAP()
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};


