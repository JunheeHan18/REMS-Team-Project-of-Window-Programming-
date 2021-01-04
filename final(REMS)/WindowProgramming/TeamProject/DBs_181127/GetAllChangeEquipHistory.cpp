// GetAllChangeEquipHistory.h : CGetAllChangeEquipHistory 클래스의 구현입니다.



// CGetAllChangeEquipHistory 구현입니다.

// 코드 생성 위치 2018년 12월 4일 화요일, 오전 1:06

#include "stdafx.h"
#include "GetAllChangeEquipHistory.h"
#include "dbdefine.h"
IMPLEMENT_DYNAMIC(CGetAllChangeEquipHistory, CRecordset)

CGetAllChangeEquipHistory::CGetAllChangeEquipHistory(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Index = 0;
	m_EnclosureIndex = 0;
	m_Type = L"";
	m_PrevEquipModelName = L"";
	m_ChangedEquipModelName = L"";
	m_Description = L"";
	m_ChangeDate;
	m_nFields = 7;
	m_nDefaultType = dynaset;
}

// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
CString CGetAllChangeEquipHistory::GetDefaultConnect()
{
	return ::GetDefaultConnectString();
}

CString CGetAllChangeEquipHistory::GetDefaultSQL()
{
	return _T("[GetAllChangeEquipHistory]");
}

void CGetAllChangeEquipHistory::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Long(pFX, _T("[Index]"), m_Index);
	RFX_Long(pFX, _T("[EnclosureIndex]"), m_EnclosureIndex);
	RFX_Text(pFX, _T("[Type]"), m_Type);
	RFX_Text(pFX, _T("[PrevEquipModelName]"), m_PrevEquipModelName);
	RFX_Text(pFX, _T("[ChangedEquipModelName]"), m_ChangedEquipModelName);
	RFX_Text(pFX, _T("[Description]"), m_Description);
	RFX_Date(pFX, _T("[ChangeDate]"), m_ChangeDate);

}
/////////////////////////////////////////////////////////////////////////////
// CGetAllChangeEquipHistory 진단

#ifdef _DEBUG
void CGetAllChangeEquipHistory::AssertValid() const
{
	CRecordset::AssertValid();
}

void CGetAllChangeEquipHistory::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


