// BaseInfoFrm.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "BaseInfoFrm.h"


// CBaseInfoFrm

IMPLEMENT_DYNCREATE(CBaseInfoFrm, CMDIChildWndEx)

CBaseInfoFrm::CBaseInfoFrm()
{

}

CBaseInfoFrm::~CBaseInfoFrm()
{
}


BEGIN_MESSAGE_MAP(CBaseInfoFrm, CMDIChildWndEx)
END_MESSAGE_MAP()



// CBaseInfoFrm �޽��� ó�����Դϴ�.




BOOL CBaseInfoFrm::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	cs.style &= ~(LONG)FWS_ADDTOTITLE;
	cs.lpszName = _T("��ü ��Ȳ");

	return CMDIChildWndEx::PreCreateWindow(cs);
}
