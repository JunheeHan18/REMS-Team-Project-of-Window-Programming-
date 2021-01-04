// FindChangeEquipHistory.h : CFindChangeEquipHistory 클래스의 구현입니다.



// CFindChangeEquipHistory 구현입니다.

// 코드 생성 위치 2018년 11월 21일 수요일, 오후 2:32

#include "stdafx.h"
#include "FindChangeEquipHistory.h"
#include "dbdefine.h"

IMPLEMENT_DYNAMIC(CFindChangeEquipHistory, CRecordset)

CFindChangeEquipHistory::CFindChangeEquipHistory(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_InstallLocation = L"";
	m_Type = L"";
	m_PrevEquipModelName = L"";
	m_ChangedEquipModelName = L"";
	m_Description = L"";
	m_Expr1;
	m_nFields = 6;
	m_nDefaultType = dynaset;
}

// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
CString CFindChangeEquipHistory::GetDefaultConnect()
{
	return ::GetDefaultConnectString();
}

CString CFindChangeEquipHistory::GetDefaultSQL()
{
	return _T("[FindChangeEquipHistory_By_Index&EquipType]");
}

void CFindChangeEquipHistory::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Text(pFX, _T("[InstallLocation]"), m_InstallLocation);
	RFX_Text(pFX, _T("[Type]"), m_Type);
	RFX_Text(pFX, _T("[PrevEquipModelName]"), m_PrevEquipModelName);
	RFX_Text(pFX, _T("[ChangedEquipModelName]"), m_ChangedEquipModelName);
	RFX_Text(pFX, _T("[Description]"), m_Description);
	RFX_Date(pFX, _T("[Expr1]"), m_Expr1);

}
void CFindChangeEquipHistory::SetFindData(long EnclosureIndex, CStringW EquipType)
{
	findEnclosureIndex = EnclosureIndex;
	findEquipType = EquipType;
}
BOOL CFindChangeEquipHistory::OpenWith(long EnclosureIndex, CStringW EquipType)
{
	findEnclosureIndex = EnclosureIndex;
	findEquipType = EquipType;

	CString query;
	query.Format(
		_T("SELECT * \
		FROM EnclosureChangeEquipHistoryTable AS changeEquips, EnclosureInstallTable AS encl \
		WHERE changeEquips.Type = %s AND encl.Index = changeEquips.EnclosureIndex And encl.Index = %d;"),
		EquipType, EnclosureIndex
	);

	std::wcout << query.GetString() << std::endl;

	try
	{
		if (!Open(m_nDefaultType, query.GetString()))
		{
			return FALSE;
		}
	}
	catch (CDBException * ex)
	{
	}

	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
// CFindChangeEquipHistory 진단

#ifdef _DEBUG
void CFindChangeEquipHistory::AssertValid() const
{
	CRecordset::AssertValid();
}

void CFindChangeEquipHistory::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


