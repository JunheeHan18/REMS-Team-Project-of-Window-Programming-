#include "stdafx.h"
#include "MyDB.h"


CMyDB::CMyDB()
: m_Recordset(NULL)
{
}


CMyDB::~CMyDB()
{
}


CRecordset* CMyDB::GetRecordset(CString query)
{
	if (m_Recordset != NULL)
		m_Recordset->Close();
	if (m_Database != NULL)
		m_Database->Close();

	m_Database = new CDatabase();
	m_Database->OpenEx(L"DSN=enclosure");
	m_Recordset = new CRecordset(m_Database);
	m_Recordset->m_pDatabase = m_Database;
	m_Recordset->Open(NULL, query);

	return m_Recordset;
}


void CMyDB::CloseDB()
{
	m_Recordset->Close();
	m_Database->Close();
}


void CMyDB::OpenDB()
{
}
