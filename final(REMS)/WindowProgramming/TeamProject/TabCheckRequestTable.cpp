// TabCheckRequestTable.h : CTabCheckRequestTable 클래스의 구현입니다.



// CTabCheckRequestTable 구현입니다.

// 코드 생성 위치 2018년 11월 22일 목요일, 오후 7:52

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
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
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
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
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
// CTabCheckRequestTable 진단

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
	LPCTSTR name[] = { _T("구분"), _T("장비번호"), _T("모델명"), _T("종류"), _T("요청일"), _T("요청사항"), _T("체크"), _T("점검일") };
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
