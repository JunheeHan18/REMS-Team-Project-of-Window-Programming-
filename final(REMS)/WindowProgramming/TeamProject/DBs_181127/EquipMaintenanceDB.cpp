#include "stdafx.h"
#include "EquipMaintenanceDB.h"
#include "GetRequestedEnclosureEquipID.h"
#include "dbdefine.h"

CGetRequestedEnclosureEquipID * EquipMaintenanceDB::GetUncheckedRequestID()
{
	CGetRequestedEnclosureEquipID* set = new CGetRequestedEnclosureEquipID();

	try
	{
		set->Open();
	}
	catch (CDBException* e)
	{
		TCHAR err[257];
		e->GetErrorMessage(err, 256);
		std::wcout << err << std::endl;
		return nullptr;
	}

	return set;
}

bool EquipMaintenanceDB::AddRequest(const EnclosureEquipCheckRequest & request)
{
	CDatabase db;

	try
	{
		db.OpenEx(_T("DSN=Enclosure_BaseEquipments;"));
	}
	catch (CDBException* e)
	{
		TCHAR err[257];
		e->GetErrorMessage(err, 256);
		std::wcout << err << std::endl;
		return false;
	}

	CString insertQuery = request.ToInsertQuery(_T("EnclosureCheckRequestTable"));

	try
	{
		db.ExecuteSQL(insertQuery);
	}
	catch (CDBException* e)
	{
		TCHAR err[257];
		e->GetErrorMessage(err, 256);
		std::wcout << err << std::endl;
		return false;
	}

	return true;
}

EnclosureEquipCheckRequest::EnclosureEquipCheckRequest()
{
}

EnclosureEquipCheckRequest::EnclosureEquipCheckRequest(long enclosureIndex, LPCTSTR equipModelName)
{
	this->enclosureIndex = enclosureIndex;
	this->equipModelName = equipModelName;
}

EnclosureEquipCheckRequest::EnclosureEquipCheckRequest(const CGetRequestedEnclosureEquipID & set)
{
	enclosureIndex = set.enclosureIndex;
	equipModelName = set.equipModelName;
}

EnclosureEquipCheckRequest::EnclosureEquipCheckRequest(const CGetRequestedEnclosureEquipID * pSet)
{
	enclosureIndex = pSet->enclosureIndex;
	equipModelName = pSet->equipModelName;
}

CString EnclosureEquipCheckRequest::ToInsertQuery(LPCTSTR tableName) const
{
	return CString(_T("INSERT INTO %s(EnclosureIndex, EquipModelName)", tableName));
}
