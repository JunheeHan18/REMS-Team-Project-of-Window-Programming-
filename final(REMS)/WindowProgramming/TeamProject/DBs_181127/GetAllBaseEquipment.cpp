// GetAllBaseEquipment.h : CGetAllBaseEquipment 클래스의 구현입니다.



// CGetAllBaseEquipment 구현입니다.

// 코드 생성 위치 2018년 12월 3일 월요일, 오후 9:35

#include "stdafx.h"
#include "GetAllBaseEquipment.h"
#include "dbdefine.h"

IMPLEMENT_DYNAMIC(CGetAllBaseEquipment, CRecordset)

CGetAllBaseEquipment::CGetAllBaseEquipment(CDatabase* pdb)
	: CRecordset(pdb)
{
	modelName = L"";
	type = L"";
	manufacturer = L"";
	revenue = L"";
	price = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}

// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
CString CGetAllBaseEquipment::GetDefaultConnect()
{
	return ::GetDefaultConnectString();
}

CString CGetAllBaseEquipment::GetDefaultSQL()
{
	return _T("[GetAllBaseEquipment]");
}

void CGetAllBaseEquipment::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Text(pFX, _T("[ModelName]"),	modelName);
	RFX_Text(pFX, _T("[Type]"),			type);
	RFX_Text(pFX, _T("[manufacturer]"),	manufacturer);
	RFX_Text(pFX, _T("[revenue]"),		revenue);
	RFX_Text(pFX, _T("[Price]"),		price);

}
/////////////////////////////////////////////////////////////////////////////
// CGetAllBaseEquipment 진단

#ifdef _DEBUG
void CGetAllBaseEquipment::AssertValid() const
{
	CRecordset::AssertValid();
}

void CGetAllBaseEquipment::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


