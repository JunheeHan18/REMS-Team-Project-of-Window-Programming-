// GetEnclosure_All.h : GetAllEnclosure Ŭ������ �����Դϴ�.



// GetAllEnclosure �����Դϴ�.

// �ڵ� ���� ��ġ 2018�� 11�� 21�� ������, ���� 12:38

#include "stdafx.h"
#include "GetAllEnclosure.h"
#include "dbdefine.h"

IMPLEMENT_DYNAMIC(CGetAllEnclosure, CRecordset)

CGetAllEnclosure::CGetAllEnclosure(CDatabase* pdb)
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
	m_nFields = 18;
	m_nDefaultType = dynaset;
}

// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
CString CGetAllEnclosure::GetDefaultConnect()
{
	return ::GetDefaultConnectString();
}

CString CGetAllEnclosure::GetDefaultSQL()
{
	return _T("[GetAllEnclosure]");
}

void CGetAllEnclosure::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Long(pFX, _T("[Index]"), index);
	RFX_Text(pFX, _T("[Group1]"), group1);
	RFX_Text(pFX, _T("[Group2]"), group2);
	RFX_Text(pFX, _T("[InstallLocation]"), installLocation);
	RFX_Text(pFX, _T("[EnclosureID]"), enclosureID);
	RFX_Long(pFX, _T("[MaintenanceIndex]"), maintenanceIndex);
	RFX_Text(pFX, _T("[InstalClassification]"), instalClassification);
	RFX_Text(pFX, _T("[InstallAddress]"), installAddress);
	RFX_Double(pFX, _T("[Latitude]"), latitude);
	RFX_Double(pFX, _T("[Longitude]"), longitude);
	RFX_Text(pFX, _T("[IP]"), IP);
	RFX_Long(pFX, _T("[Port]"), port);
	RFX_Date(pFX, _T("[InstallDate]"), installDate);
	RFX_Text(pFX, _T("[InstallCompany]"), installCompany);
	RFX_Text(pFX, _T("[InstallCompanyCall]"), installCompanyCall);
	RFX_Text(pFX, _T("[MaintainCompany]"), maintainCompany);
	RFX_Text(pFX, _T("[MaintainCompanyCall]"), maintainCompanyCall);
	RFX_Bool(pFX, _T("[Enable]"), enable);

}
/////////////////////////////////////////////////////////////////////////////
// GetAllEnclosure ����

#ifdef _DEBUG
void CGetAllEnclosure::AssertValid() const
{
	CRecordset::AssertValid();
}

void CGetAllEnclosure::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


