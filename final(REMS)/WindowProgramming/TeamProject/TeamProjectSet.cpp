
// TeamProjectSet.cpp : CTeamProjectSet 클래스의 구현
//

#include "stdafx.h"
#include "TeamProject.h"
#include "TeamProjectSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTeamProjectSet 구현

// 코드 생성 위치 2018년 11월 16일 금요일, 오후 3:46

int CTeamProjectSet::idxArray[200] = { 0, };
int CTeamProjectSet::idxArryIndex = 0;

IMPLEMENT_DYNAMIC(CTeamProjectSet, CRecordset)

CTeamProjectSet::CTeamProjectSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Index = 0;
	m_GropName1 = L"";
	m_GropName2 = L"";
	m_State = L"";
	m_LocationName = L"";
	m_InstallationClassification = L"";
	m_InstallationAddress = L"";
	m_Etc = L"";
	m_nFields = 8;
	m_nDefaultType = dynaset;
}
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
CString CTeamProjectSet::GetDefaultConnect()
{
	return _T("DSN=enclosure;DBQ=C:\\Users\\junhe\\Documents\\MFC\\enclosure_database.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CTeamProjectSet::GetDefaultSQL()
{
	return _T("[EnclosureInstallTable]");
}

void CTeamProjectSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Long(pFX, _T("[Index]"), m_Index);
	RFX_Text(pFX, _T("[GropName1]"), m_GropName1);
	RFX_Text(pFX, _T("[GropName2]"), m_GropName2);
	RFX_Text(pFX, _T("[State]"), m_State);
	RFX_Text(pFX, _T("[LocationName]"), m_LocationName);
	RFX_Text(pFX, _T("[InstallationClassification]"), m_InstallationClassification);
	RFX_Text(pFX, _T("[InstallationAddress]"), m_InstallationAddress);
	RFX_Text(pFX, _T("[Etc]"), m_Etc);

}
/////////////////////////////////////////////////////////////////////////////
// CTeamProjectSet 진단

#ifdef _DEBUG
void CTeamProjectSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTeamProjectSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

