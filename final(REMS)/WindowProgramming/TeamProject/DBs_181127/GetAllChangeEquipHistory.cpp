// GetAllChangeEquipHistory.h : CGetAllChangeEquipHistory Ŭ������ �����Դϴ�.



// CGetAllChangeEquipHistory �����Դϴ�.

// �ڵ� ���� ��ġ 2018�� 12�� 4�� ȭ����, ���� 1:06

#include "stdafx.h"
#include "GetAllChangeEquipHistory.h"
#include "dbdefine.h"
IMPLEMENT_DYNAMIC(CGetAllChangeEquipHistory, CRecordset)

CGetAllChangeEquipHistory::CGetAllChangeEquipHistory(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Index = 0;
	m_EnclosureIndex = 0;
	m_Type = L"";
	m_PrevEquipModelName = L"";
	m_ChangedEquipModelName = L"";
	m_Description = L"";
	m_ChangeDate;
	m_nFields = 7;
	m_nDefaultType = dynaset;
}

// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
CString CGetAllChangeEquipHistory::GetDefaultConnect()
{
	return ::GetDefaultConnectString();
}

CString CGetAllChangeEquipHistory::GetDefaultSQL()
{
	return _T("[GetAllChangeEquipHistory]");
}

void CGetAllChangeEquipHistory::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Long(pFX, _T("[Index]"), m_Index);
	RFX_Long(pFX, _T("[EnclosureIndex]"), m_EnclosureIndex);
	RFX_Text(pFX, _T("[Type]"), m_Type);
	RFX_Text(pFX, _T("[PrevEquipModelName]"), m_PrevEquipModelName);
	RFX_Text(pFX, _T("[ChangedEquipModelName]"), m_ChangedEquipModelName);
	RFX_Text(pFX, _T("[Description]"), m_Description);
	RFX_Date(pFX, _T("[ChangeDate]"), m_ChangeDate);

}
/////////////////////////////////////////////////////////////////////////////
// CGetAllChangeEquipHistory ����

#ifdef _DEBUG
void CGetAllChangeEquipHistory::AssertValid() const
{
	CRecordset::AssertValid();
}

void CGetAllChangeEquipHistory::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


