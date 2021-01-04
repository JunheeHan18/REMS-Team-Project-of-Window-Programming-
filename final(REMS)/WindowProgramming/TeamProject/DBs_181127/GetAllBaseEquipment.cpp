// GetAllBaseEquipment.h : CGetAllBaseEquipment Ŭ������ �����Դϴ�.



// CGetAllBaseEquipment �����Դϴ�.

// �ڵ� ���� ��ġ 2018�� 12�� 3�� ������, ���� 9:35

#include "stdafx.h"
#include "GetAllBaseEquipment.h"
#include "dbdefine.h"

IMPLEMENT_DYNAMIC(CGetAllBaseEquipment, CRecordset)

CGetAllBaseEquipment::CGetAllBaseEquipment(CDatabase* pdb)
	: CRecordset(pdb)
{
	modelName = L"";
	type = L"";
	manufacturer = L"";
	revenue = L"";
	price = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}

// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
CString CGetAllBaseEquipment::GetDefaultConnect()
{
	return ::GetDefaultConnectString();
}

CString CGetAllBaseEquipment::GetDefaultSQL()
{
	return _T("[GetAllBaseEquipment]");
}

void CGetAllBaseEquipment::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Text(pFX, _T("[ModelName]"),	modelName);
	RFX_Text(pFX, _T("[Type]"),			type);
	RFX_Text(pFX, _T("[manufacturer]"),	manufacturer);
	RFX_Text(pFX, _T("[revenue]"),		revenue);
	RFX_Text(pFX, _T("[Price]"),		price);

}
/////////////////////////////////////////////////////////////////////////////
// CGetAllBaseEquipment ����

#ifdef _DEBUG
void CGetAllBaseEquipment::AssertValid() const
{
	CRecordset::AssertValid();
}

void CGetAllBaseEquipment::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


