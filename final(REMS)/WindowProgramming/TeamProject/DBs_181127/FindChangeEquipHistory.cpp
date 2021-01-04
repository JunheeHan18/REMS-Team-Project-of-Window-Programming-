// FindChangeEquipHistory.h : CFindChangeEquipHistory Ŭ������ �����Դϴ�.



// CFindChangeEquipHistory �����Դϴ�.

// �ڵ� ���� ��ġ 2018�� 11�� 21�� ������, ���� 2:32

#include "stdafx.h"
#include "FindChangeEquipHistory.h"
#include "dbdefine.h"

IMPLEMENT_DYNAMIC(CFindChangeEquipHistory, CRecordset)

CFindChangeEquipHistory::CFindChangeEquipHistory(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_InstallLocation = L"";
	m_Type = L"";
	m_PrevEquipModelName = L"";
	m_ChangedEquipModelName = L"";
	m_Description = L"";
	m_Expr1;
	m_nFields = 6;
	m_nDefaultType = dynaset;
}

// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
CString CFindChangeEquipHistory::GetDefaultConnect()
{
	return ::GetDefaultConnectString();
}

CString CFindChangeEquipHistory::GetDefaultSQL()
{
	return _T("[FindChangeEquipHistory_By_Index&EquipType]");
}

void CFindChangeEquipHistory::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Text(pFX, _T("[InstallLocation]"), m_InstallLocation);
	RFX_Text(pFX, _T("[Type]"), m_Type);
	RFX_Text(pFX, _T("[PrevEquipModelName]"), m_PrevEquipModelName);
	RFX_Text(pFX, _T("[ChangedEquipModelName]"), m_ChangedEquipModelName);
	RFX_Text(pFX, _T("[Description]"), m_Description);
	RFX_Date(pFX, _T("[Expr1]"), m_Expr1);

}
void CFindChangeEquipHistory::SetFindData(long EnclosureIndex, CStringW EquipType)
{
	findEnclosureIndex = EnclosureIndex;
	findEquipType = EquipType;
}
BOOL CFindChangeEquipHistory::OpenWith(long EnclosureIndex, CStringW EquipType)
{
	findEnclosureIndex = EnclosureIndex;
	findEquipType = EquipType;

	CString query;
	query.Format(
		_T("SELECT * \
		FROM EnclosureChangeEquipHistoryTable AS changeEquips, EnclosureInstallTable AS encl \
		WHERE changeEquips.Type = %s AND encl.Index = changeEquips.EnclosureIndex And encl.Index = %d;"),
		EquipType, EnclosureIndex
	);

	std::wcout << query.GetString() << std::endl;

	try
	{
		if (!Open(m_nDefaultType, query.GetString()))
		{
			return FALSE;
		}
	}
	catch (CDBException * ex)
	{
	}

	return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
// CFindChangeEquipHistory ����

#ifdef _DEBUG
void CFindChangeEquipHistory::AssertValid() const
{
	CRecordset::AssertValid();
}

void CFindChangeEquipHistory::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


