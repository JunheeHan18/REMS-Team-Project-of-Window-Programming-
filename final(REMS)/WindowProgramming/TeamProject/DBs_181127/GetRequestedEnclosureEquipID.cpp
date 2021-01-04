// GetRequestedEnclosureEquipID.h : CGetRequestedEnclosureEquipID 클래스의 구현입니다.



// CGetRequestedEnclosureEquipID 구현입니다.

// 코드 생성 위치 2018년 11월 21일 수요일, 오후 2:06

#include "stdafx.h"
#include "GetRequestedEnclosureEquipID.h"
#include "dbdefine.h"

IMPLEMENT_DYNAMIC(CGetRequestedEnclosureEquipID, CRecordset)

CGetRequestedEnclosureEquipID::CGetRequestedEnclosureEquipID(CDatabase* pdb)
	: CRecordset(pdb)
{
	enclosureIndex = 0;
	equipModelName = L"";
	m_nFields = 2;
	m_nDefaultType = dynaset;
}

// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
CString CGetRequestedEnclosureEquipID::GetDefaultConnect()
{
	return ::GetDefaultConnectString();
}

CString CGetRequestedEnclosureEquipID::GetDefaultSQL()
{
	return _T("[GetRequestedEnclosureEquipID]");
}

void CGetRequestedEnclosureEquipID::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Long(pFX, _T("[Index]"), enclosureIndex);
	RFX_Text(pFX, _T("[ModelName]"), equipModelName);

}
/////////////////////////////////////////////////////////////////////////////
// CGetRequestedEnclosureEquipID 진단

#ifdef _DEBUG
void CGetRequestedEnclosureEquipID::AssertValid() const
{
	CRecordset::AssertValid();
}

void CGetRequestedEnclosureEquipID::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


