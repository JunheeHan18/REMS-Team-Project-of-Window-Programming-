// EquipStatusFrm.cpp : 구현 파일입니다.
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



// CEquipStatusFrm 메시지 처리기입니다.




BOOL CEquipStatusFrm::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	cs.style &= ~(LONG)FWS_ADDTOTITLE;
	cs.lpszName = _T("장비 현황");

	return CMDIChildWndEx::PreCreateWindow(cs);
}
