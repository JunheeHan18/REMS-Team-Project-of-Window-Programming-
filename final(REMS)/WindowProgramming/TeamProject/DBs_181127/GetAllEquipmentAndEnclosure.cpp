// GetAllEquipmentAndEnclosure.h : CGetAllEquipmentAndEnclosure Ŭ������ �����Դϴ�.



// CGetAllEquipmentAndEnclosure �����Դϴ�.

// �ڵ� ���� ��ġ 2018�� 11�� 21�� ������, ���� 12:22

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

// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
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
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
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
// CGetAllEquipmentAndEnclosure ����

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


