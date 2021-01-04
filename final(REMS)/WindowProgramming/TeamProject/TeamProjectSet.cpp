
// TeamProjectSet.cpp : CTeamProjectSet Ŭ������ ����
//

#include "stdafx.h"
#include "TeamProject.h"
#include "TeamProjectSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTeamProjectSet ����

// �ڵ� ���� ��ġ 2018�� 11�� 16�� �ݿ���, ���� 3:46

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
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
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
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
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
// CTeamProjectSet ����

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

