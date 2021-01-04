// TabCheckRequestTable.h : CTabCheckRequestTable Ŭ������ �����Դϴ�.



// CTabCheckRequestTable �����Դϴ�.

// �ڵ� ���� ��ġ 2018�� 11�� 22�� �����, ���� 7:52

#include "stdafx.h"
#include "TabCheckRequestTable.h"
IMPLEMENT_DYNAMIC(CTabCheckRequestTable, CRecordset)

CTabCheckRequestTable::CTabCheckRequestTable(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_RequestIndex = 0;
	m_EnclosureIndex = 0;
	m_EquipModelName = L"";
	m_CheckType = L"";
	m_RequestDate;
	m_RequestDescription = L"";
	m_Checked = FALSE;
	m_CheckedDate;
	m_nFields = 8;
	m_nDefaultType = dynaset;
}
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
CString CTabCheckRequestTable::GetDefaultConnect()
{
	return _T("DSN=enclosure;DBQ=C:\\Users\\junhe\\Documents\\MFC\\enclosure_database.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CTabCheckRequestTable::GetDefaultSQL()
{
	return _T("[EnclosureCheckRequestTable]");
}

void CTabCheckRequestTable::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Long(pFX, _T("[RequestIndex]"), m_RequestIndex);
	RFX_Long(pFX, _T("[EnclosureIndex]"), m_EnclosureIndex);
	RFX_Text(pFX, _T("[EquipModelName]"), m_EquipModelName);
	RFX_Text(pFX, _T("[CheckType]"), m_CheckType);
	RFX_Date(pFX, _T("[RequestDate]"), m_RequestDate);
	RFX_Text(pFX, _T("[RequestDescription]"), m_RequestDescription);
	RFX_Bool(pFX, _T("[Checked]"), m_Checked);
	RFX_Date(pFX, _T("[CheckedDate]"), m_CheckedDate);
	//DDX_Control(pDx, IDC_LIST_DATA, m_ListCtrl);

}
/////////////////////////////////////////////////////////////////////////////
// CTabCheckRequestTable ����

#ifdef _DEBUG
void CTabCheckRequestTable::AssertValid() const
{
	CRecordset::AssertValid();
}

void CTabCheckRequestTable::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG




void CTabCheckRequestTable::UpdateList()
{
	m_ListCtrl.DeleteAllItems();

	CDatabase db;
	db.OpenEx(L"DSN=enclosure");
	CRecordset rs(&db);

	short width[] = { 50, 80, 80, 80, 150, 100, 150, 100, };
	int align[] = { LVCFMT_CENTER, LVCFMT_CENTER, LVCFMT_CENTER, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_CENTER, LVCFMT_LEFT, LVCFMT_CENTER };
	LPCTSTR name[] = { _T("����"), _T("����ȣ"), _T("�𵨸�"), _T("����"), _T("��û��"), _T("��û����"), _T("üũ"), _T("������") };
	for (int i = 0; i <= 7; i++)
	{
		m_ListCtrl.InsertColumn(i + 1, name[i], align[i], width[i]);
	}

	rs.m_pDatabase = &db;
	rs.Open(NULL, L"SELECT * FROM EnclosureCheckRequestTable;");
	short maxRow = rs.GetRecordCount();
	CString itemStr;
	CString intToCStr;
	int idx = 0;
	while (!rs.IsEOF()) {
		intToCStr.Format(_T("%d"), idx);
		m_ListCtrl.InsertItem(idx, intToCStr);
		for (int j = 0; j < 7; j++) {
			rs.GetFieldValue((short)j, itemStr);
			m_ListCtrl.SetItemText(idx, j, itemStr);
		}
		idx++;
		rs.MoveNext();
	}
	rs.Close();
	db.Close();
}
