// GetRequestedEnclosureEquipID.h : CGetRequestedEnclosureEquipID Ŭ������ �����Դϴ�.



// CGetRequestedEnclosureEquipID �����Դϴ�.

// �ڵ� ���� ��ġ 2018�� 11�� 21�� ������, ���� 2:06

#include "stdafx.h"
#include "GetRequestedEnclosureEquipID.h"
#include "dbdefine.h"

IMPLEMENT_DYNAMIC(CGetRequestedEnclosureEquipID, CRecordset)

CGetRequestedEnclosureEquipID::CGetRequestedEnclosureEquipID(CDatabase* pdb)
	: CRecordset(pdb)
{
	enclosureIndex = 0;
	equipModelName = L"";
	m_nFields = 2;
	m_nDefaultType = dynaset;
}

// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
CString CGetRequestedEnclosureEquipID::GetDefaultConnect()
{
	return ::GetDefaultConnectString();
}

CString CGetRequestedEnclosureEquipID::GetDefaultSQL()
{
	return _T("[GetRequestedEnclosureEquipID]");
}

void CGetRequestedEnclosureEquipID::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Long(pFX, _T("[Index]"), enclosureIndex);
	RFX_Text(pFX, _T("[ModelName]"), equipModelName);

}
/////////////////////////////////////////////////////////////////////////////
// CGetRequestedEnclosureEquipID ����

#ifdef _DEBUG
void CGetRequestedEnclosureEquipID::AssertValid() const
{
	CRecordset::AssertValid();
}

void CGetRequestedEnclosureEquipID::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


