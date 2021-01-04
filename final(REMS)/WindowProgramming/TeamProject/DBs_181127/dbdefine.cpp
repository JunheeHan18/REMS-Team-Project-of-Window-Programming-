#include "stdafx.h"
#include "dbdefine.h"


LPCTSTR ODBC_DBName				= _T("enclosure"),
		userDBFilePathFormat	= _T("C:\\USERS\\%s\\DOCUMENTS\\MFC\\enclosure_database.mdb"),	
		fixedDBFilePath			= _T("C:\\USERS\\ZIZON\\DOCUMENTS\\MFC\\enclosure_database.mdb");

BOOL isUserVariated = TRUE;

CString GetUserConnectForEnclosureDB();
CString GetDefaultConnectForEnclosureDB();

CString GetDefaultConnectString()
{
	if (isUserVariated)
		return GetUserConnectForEnclosureDB();
	else
		return GetDefaultConnectForEnclosureDB();
}

/*
������ ODBC DB �̸�, ����� �̸��� �°� ������ DB ��η� ���� ������ �����մϴ�.
*/
CString GetUserConnectForEnclosureDB()
{
	TCHAR userNameBuffer[257];
	DWORD userNameSize = 256;
	GetUserName(userNameBuffer, &userNameSize);

	TCHAR dbFilePathBuffer[257];
	DWORD dbFilePathSize = 256;
	swprintf(dbFilePathBuffer, dbFilePathSize, userDBFilePathFormat, userNameBuffer);

	TCHAR dbConnBuffer[513];
	swprintf(dbConnBuffer, 512, _T("DSN=%s;DBQ=%s;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;"), ODBC_DBName, dbFilePathBuffer);

	return dbConnBuffer;
}

/*
������ ODBC DB �̸�, ������ DB ��η� ���� ������ �����մϴ�.
*/
CString GetDefaultConnectForEnclosureDB()
{
	TCHAR dbConnBuffer[513];
	swprintf(dbConnBuffer, 512, _T("DSN=%s;DBQ=%s;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;"), ODBC_DBName, fixedDBFilePath);

	return dbConnBuffer;
}

