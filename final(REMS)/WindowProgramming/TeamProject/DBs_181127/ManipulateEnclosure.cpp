// ManipulateEnclosure.h : CManipulateEnclosure Ŭ������ �����Դϴ�.



// CManipulateEnclosure �����Դϴ�.

// �ڵ� ���� ��ġ 2018�� 11�� 21�� ������, ���� 2:56

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

// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
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
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
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
// CManipulateEnclosure ����

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


