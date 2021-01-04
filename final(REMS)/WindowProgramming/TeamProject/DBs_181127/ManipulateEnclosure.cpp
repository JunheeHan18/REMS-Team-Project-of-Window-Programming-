// ManipulateEnclosure.h : CManipulateEnclosure 클래스의 구현입니다.



// CManipulateEnclosure 구현입니다.

// 코드 생성 위치 2018년 11월 21일 수요일, 오후 2:56

#include "stdafx.h"
#include "ManipulateEnclosure.h"
#include "dbdefine.h"

IMPLEMENT_DYNAMIC(CManipulateEnclosure, CRecordset)

CManipulateEnclosure::CManipulateEnclosure(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Index = 0;
	m_Group1 = L"";
	m_Group2 = L"";
	m_InstallLocation = L"";
	m_EnclosureID = L"";
	m_MaintenanceIndex = 0;
	m_InstalClassification = L"";
	m_InstallAddress = L"";
	m_Latitude = 0.0;
	m_Longitude = 0.0;
	m_IP = L"";
	m_Port = 0;
	m_InstallDate;
	m_InstallCompany = L"";
	m_InstallCompanyCall = L"";
	m_MaintainCompany = L"";
	m_MaintainCompanyCall = L"";
	m_Enable = FALSE;
	m_nFields = 18;
	m_nDefaultType = dynaset;
}

// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
CString CManipulateEnclosure::GetDefaultConnect()
{
	return _T("DSN=Enclosure_BaseEquipments;DBQ=C:\\Users\\ZiZoN\\Documents\\MFC\\enclosure_database.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CManipulateEnclosure::GetDefaultSQL()
{
	return _T("[EnclosureInstallTable]");
}

void CManipulateEnclosure::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Long(pFX, _T("[Index]"), m_Index);
	RFX_Text(pFX, _T("[Group1]"), m_Group1);
	RFX_Text(pFX, _T("[Group2]"), m_Group2);
	RFX_Text(pFX, _T("[InstallLocation]"), m_InstallLocation);
	RFX_Text(pFX, _T("[EnclosureID]"), m_EnclosureID);
	RFX_Long(pFX, _T("[MaintenanceIndex]"), m_MaintenanceIndex);
	RFX_Text(pFX, _T("[InstalClassification]"), m_InstalClassification);
	RFX_Text(pFX, _T("[InstallAddress]"), m_InstallAddress);
	RFX_Double(pFX, _T("[Latitude]"), m_Latitude);
	RFX_Double(pFX, _T("[Longitude]"), m_Longitude);
	RFX_Text(pFX, _T("[IP]"), m_IP);
	RFX_Long(pFX, _T("[Port]"), m_Port);
	RFX_Date(pFX, _T("[InstallDate]"), m_InstallDate);
	RFX_Text(pFX, _T("[InstallCompany]"), m_InstallCompany);
	RFX_Text(pFX, _T("[InstallCompanyCall]"), m_InstallCompanyCall);
	RFX_Text(pFX, _T("[MaintainCompany]"), m_MaintainCompany);
	RFX_Text(pFX, _T("[MaintainCompanyCall]"), m_MaintainCompanyCall);
	RFX_Bool(pFX, _T("[Enable]"), m_Enable);

}
/////////////////////////////////////////////////////////////////////////////
// CManipulateEnclosure 진단

#ifdef _DEBUG
void CManipulateEnclosure::AssertValid() const
{
	CRecordset::AssertValid();
}

void CManipulateEnclosure::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


