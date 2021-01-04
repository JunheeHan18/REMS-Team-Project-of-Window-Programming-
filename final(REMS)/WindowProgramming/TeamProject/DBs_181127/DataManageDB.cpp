#include "stdafx.h"
#include "DataManageDB.h"
#include "dbdefine.h"
#include <afxdb.h>

CRecordset * DataManageDB::GetAllEnclosures()
{
	CGetAllEnclosure* set = new CGetAllEnclosure();

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

bool DataManageDB::AddEnclosure(const EnclosureInform & inform)
{
	CDatabase db;

	try
	{
		db.OpenEx(::GetDefaultConnectString());
	}
	catch (CDBException* e)
	{
		TCHAR err[257];
		e->GetErrorMessage(err, 256);
		std::wcout << err << std::endl;
		return false;
	}

	CString insertQuery = inform.ToInsertQuery(_T("EnclosureInstallTable"));

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

bool DataManageDB::UpdateEnclosure(long enclosureIndex, const EnclosureInform & inform)
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

	CString updateQuery = inform.ToUpdateQuery(_T("EnclosureInstallTable"), enclosureIndex);

	try
	{
		db.ExecuteSQL(updateQuery);
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

bool DataManageDB::DeleteEnclosure(long enclosureIndex)
{
	CDatabase db;

	try
	{
		db.OpenEx(GetDefaultConnectString().GetString());
	}
	catch (CDBException* e)
	{
		TCHAR err[257];
		e->GetErrorMessage(err, 256);
		std::wcout << err << std::endl;
		return false;
	}

	CString deleteQuery;
	deleteQuery.Format(_T("delete from EnclosureInstallTable where Index = %d"), enclosureIndex);

	try
	{
		db.ExecuteSQL(deleteQuery.GetString());
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

CRecordset * DataManageDB::GetAllEquipmentAndEnclosure()
{
	CGetAllEquipmentAndEnclosure* set = new CGetAllEquipmentAndEnclosure();

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

CRecordset * DataManageDB::GetAllBaseEquipment()
{
	CGetAllBaseEquipment* set = new CGetAllBaseEquipment();

	try
	{
		set->Open(CRecordset::dynaset, _T("SELECT * FROM BaseEquipmentTable"));
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

CRecordset * DataManageDB::GetChangeEquipHistory(CString enclosureIndexString)
{
	CGetAllChangeEquipHistory* set = new CGetAllChangeEquipHistory();

	CString query;
	query.Format(_T("SELECT * FROM EnclosureChangeEquipHistoryTable, EnclosureInstallTable WHERE EnclosureChangeEquipHistoryTable.EnclosureIndex=EnclosureInstallTable.Index AND EnclosureChangeEquipHistoryTable.EnclosureIndex=%s"), enclosureIndexString);

	try
	{
		set->Open(CRecordset::dynaset, query);
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


EnclosureInform::EnclosureInform()
{
	index					= -1;
	group1					= _T(" ");
	group2					= _T(" ");
	installLocation			= _T(" ");
	enclosureID				= _T(" ");
	maintenanceIndex		= -1;
	installClassification	= _T(" ");
	installAddress			= _T(" ");
	latitude				= 0;
	longitude				= 0;
	IP						= _T(" ");
	port					= -1;
	installDate				= 0;
	installCompany			= _T(" ");
	installCompanyCall		= _T(" ");
	maintainCompany			= _T(" ");
	maintainCompanyCall		= _T(" ");
	enable					= false;
}

EnclosureInform::EnclosureInform(const CGetAllEnclosure & enclDataset)
{
	index = enclDataset.index;
	group1.SetString(enclDataset.group1.GetString());
	group2.SetString(enclDataset.group2.GetString());
	installLocation.SetString(enclDataset.installLocation.GetString());
	enclosureID.SetString(enclDataset.enclosureID.GetString());
	maintenanceIndex = enclDataset.maintenanceIndex;
	installClassification.SetString(enclDataset.instalClassification.GetString());
	installAddress.SetString(enclDataset.installAddress.GetString());
	latitude = enclDataset.latitude;
	longitude = enclDataset.longitude;
	IP.SetString(enclDataset.IP.GetString());
	port = enclDataset.port;
	installDate = enclDataset.installDate;
	installCompany.SetString(enclDataset.installCompany.GetString());
	installCompanyCall.SetString(enclDataset.installCompanyCall.GetString());
	maintainCompany.SetString(enclDataset.maintainCompany.GetString());
	maintainCompanyCall.SetString(enclDataset.maintainCompanyCall.GetString());
	enable = enclDataset.enable;
}

EnclosureInform::EnclosureInform(const CGetAllEnclosure * enclDataset)
{
	index = enclDataset->index;
	group1.SetString(enclDataset->group1.GetString());
	group2.SetString(enclDataset->group2.GetString());
	installLocation.SetString(enclDataset->installLocation.GetString());
	enclosureID.SetString(enclDataset->enclosureID.GetString());
	maintenanceIndex = enclDataset->maintenanceIndex;
	installClassification.SetString(enclDataset->instalClassification.GetString());
	installAddress.SetString(enclDataset->installAddress.GetString());
	latitude = enclDataset->latitude;
	longitude = enclDataset->longitude;
	IP.SetString(enclDataset->IP.GetString());
	port = enclDataset->port;
	installDate = enclDataset->installDate;
	installCompany.SetString(enclDataset->installCompany.GetString());
	installCompanyCall.SetString(enclDataset->installCompanyCall.GetString());
	maintainCompany.SetString(enclDataset->maintainCompany.GetString());
	maintainCompanyCall.SetString(enclDataset->maintainCompanyCall.GetString());
	enable = enclDataset->enable;
}

CStringW EnclosureInform::ToInsertQuery(LPCTSTR tableName) const
{
	CStringW values;

	values.Format(
		_T("INSERT INTO %s( Group1, Group2, InstallLocation, EnclosureID, MaintenanceIndex, InstalClassification, InstallAddress, Latitude, Longitude, IP, Port, InstallDate, InstallCompany, InstallCompanyCall, MaintainCompany, MaintainCompanyCall, Enable ) VALUES( \'%s\', \'%s\', \'%s\', \'%s\', %d, \'%s\', \'%s\', %.15f, %.15f, \'%s\', %d, \'%s\', \'%s\', \'%s\', \'%s\', \'%s\', %s )"),
		tableName,
		group1.GetString(),
		group2.GetString(),
		installLocation.GetString(),
		enclosureID.GetString(),
		maintenanceIndex,
		installClassification.GetString(),
		installAddress.GetString(),
		latitude,
		longitude,
		IP.GetString(),
		port,
		installDate.Format(_T("2018-11-20")).GetString(),
		installCompany.GetString(),
		installCompanyCall.GetString(),
		maintainCompany.GetString(),
		maintainCompanyCall.GetString(),
		enable ? _T("True") : _T("False")
	);


	return values;
}

CStringW EnclosureInform::ToUpdateQuery(LPCTSTR tableName, long enclosureIndex) const
{
	CStringW q;

	q.Format(
		_T("UPDATE %s SET Group1 = \'%s\', Group2 = \'%s\', InstallLocation = \'%s\', EnclosureID = \'%s\', MaintenanceIndex = %d, InstalClassification = \'%s\', InstallAddress = \'%s\', Latitude = %.15f, Longitude = %.15f, IP = \'%s\', Port = %d, InstallDate = \'%s\', InstallCompany = \'%s\', InstallCompanyCall = \'%s\', MaintainCompany = \'%s\', MaintainCompanyCall = \'%s\', Enable = %s WHERE Index = %d;"),
		tableName,
		group1.GetString(),
		group2.GetString(),
		installLocation.GetString(),
		enclosureID.GetString(),
		maintenanceIndex,
		installClassification.GetString(),
		installAddress.GetString(),
		latitude,
		longitude,
		IP.GetString(),
		port,
		installDate.Format(_T("2018-11-20")).GetString(),
		installCompany.GetString(),
		installCompanyCall.GetString(),
		maintainCompany.GetString(),
		maintainCompanyCall.GetString(),
		enable ? _T("True") : _T("False"),
		enclosureIndex);

	return q;
}

EnclEquipInform::EnclEquipInform()
{
}

EnclEquipInform::EnclEquipInform(const CGetAllEquipmentAndEnclosure & enclDataset)
{
}

EnclEquipInform::EnclEquipInform(const CGetAllEquipmentAndEnclosure * pEnclDataset)
{
}

CStringW EnclEquipInform::ToInsertQuery(LPCTSTR tableName) const
{
	return CStringW();
}

CStringW EnclEquipInform::ToUpdateQuery(LPCTSTR tableName, long enclosureIndex) const
{
	return CStringW();
}
