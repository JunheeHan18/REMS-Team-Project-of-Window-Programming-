#pragma once
#include "afxdb.h"
class CMyDB
{
public:
	CMyDB();
	~CMyDB();
	CRecordset* GetRecordset(CString query);
	CRecordset* m_Recordset;
	void CloseDB();
	CDatabase* m_Database;
	void OpenDB();
};