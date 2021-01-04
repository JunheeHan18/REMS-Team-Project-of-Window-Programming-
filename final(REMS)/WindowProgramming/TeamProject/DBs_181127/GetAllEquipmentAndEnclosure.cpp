// GetAllEquipmentAndEnclosure.h : CGetAllEquipmentAndEnclosure 클래스의 구현입니다.



// CGetAllEquipmentAndEnclosure 구현입니다.

// 코드 생성 위치 2018년 11월 21일 수요일, 오후 12:22

#include "stdafx.h"
#include "GetAllEquipmentAndEnclosure.h"
#include "dbdefine.h"

IMPLEMENT_DYNAMIC(CGetAllEquipmentAndEnclosure, CRecordset)

CGetAllEquipmentAndEnclosure::CGetAllEquipmentAndEnclosure(CDatabase* pdb)
	: CRecordset(pdb)
{
	index = 0;
	group1 = L"";
	group2 = L"";
	installLocation = L"";
	enclosureID = L"";
	maintenanceIndex = 0;
	instalClassification = L"";
	installAddress = L"";
	latitude = 0.0;
	longitude = 0.0;
	IP = L"";
	port = 0;
	installDate;
	installCompany = L"";
	installCompanyCall = L"";
	maintainCompany = L"";
	maintainCompanyCall = L"";
	enable = FALSE;
	modelName = L"";
	type = L"";
	manufacturer = L"";
	revenue = L"";
	enclosureIndex = 0;
	equipModelName = L"";
	m_nFields = 24;
	m_nDefaultType = dynaset;
}

// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
CString CGetAllEquipmentAndEnclosure::GetDefaultConnect()
{
	return ::GetDefaultConnectString();
}

CString CGetAllEquipmentAndEnclosure::GetDefaultSQL()
{
	return _T("[GetAllEquipmentAndEnclosure]");
}

void CGetAllEquipmentAndEnclosure::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Long(pFX, _T("[Index]"),				index);
	RFX_Text(pFX, _T("[Group1]"),				group1);
	RFX_Text(pFX, _T("[Group2]"),				group2);
	RFX_Text(pFX, _T("[InstallLocation]"),		installLocation);
	RFX_Text(pFX, _T("[EnclosureID]"),			enclosureID);
	RFX_Long(pFX, _T("[MaintenanceIndex]"),		maintenanceIndex);
	RFX_Text(pFX, _T("[InstalClassification]"), instalClassification);
	RFX_Text(pFX, _T("[InstallAddress]"),		installAddress);
	RFX_Double(pFX, _T("[Latitude]"),			latitude);
	RFX_Double(pFX, _T("[Longitude]"),			longitude);
	RFX_Text(pFX, _T("[IP]"),					IP);
	RFX_Long(pFX, _T("[Port]"),					port);
	RFX_Date(pFX, _T("[InstallDate]"),			installDate);
	RFX_Text(pFX, _T("[InstallCompany]"),		installCompany);
	RFX_Text(pFX, _T("[InstallCompanyCall]"),	installCompanyCall);
	RFX_Text(pFX, _T("[MaintainCompany]"),		maintainCompany);
	RFX_Text(pFX, _T("[MaintainCompanyCall]"),	maintainCompanyCall);
	RFX_Bool(pFX, _T("[Enable]"),				enable);
	RFX_Text(pFX, _T("[ModelName]"),			modelName);
	RFX_Text(pFX, _T("[Type]"),					type);
	RFX_Text(pFX, _T("[manufacturer]"),			manufacturer);
	RFX_Text(pFX, _T("[revenue]"),				revenue);
	RFX_Long(pFX, _T("[EnclosureIndex]"),		enclosureIndex);
	RFX_Text(pFX, _T("[EquipModelName]"),		equipModelName);

}
/////////////////////////////////////////////////////////////////////////////
// CGetAllEquipmentAndEnclosure 진단

#ifdef _DEBUG
void CGetAllEquipmentAndEnclosure::AssertValid() const
{
	CRecordset::AssertValid();
}

void CGetAllEquipmentAndEnclosure::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


