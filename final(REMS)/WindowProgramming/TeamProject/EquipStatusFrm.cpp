// EquipStatusFrm.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "EquipStatusFrm.h"


// CEquipStatusFrm

IMPLEMENT_DYNCREATE(CEquipStatusFrm, CMDIChildWndEx)

CEquipStatusFrm::CEquipStatusFrm()
{

}

CEquipStatusFrm::~CEquipStatusFrm()
{
}


BEGIN_MESSAGE_MAP(CEquipStatusFrm, CMDIChildWndEx)
END_MESSAGE_MAP()



// CEquipStatusFrm �޽��� ó�����Դϴ�.




BOOL CEquipStatusFrm::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	cs.style &= ~(LONG)FWS_ADDTOTITLE;
	cs.lpszName = _T("��� ��Ȳ");

	return CMDIChildWndEx::PreCreateWindow(cs);
}
