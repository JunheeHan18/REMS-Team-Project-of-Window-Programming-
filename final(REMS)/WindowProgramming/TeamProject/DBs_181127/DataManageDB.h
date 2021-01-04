#pragma once
#include "GetAllEnclosure.h"
#include "GetAllEquipmentAndEnclosure.h"
#include "GetAllBaseEquipment.h"
#include "GetAllChangeEquipHistory.h"

struct EnclosureInform
{
public:

	EnclosureInform();
	EnclosureInform(const CGetAllEnclosure& enclDataset);
	EnclosureInform(const CGetAllEnclosure* pEnclDataset);

public:

	long		index;
	CStringW	group1;
	CStringW	group2;
	CStringW	installLocation;
	CStringW	enclosureID;
	long		maintenanceIndex;
	CStringW	installClassification;
	CStringW	installAddress;
	double		latitude;
	double		longitude;
	CStringW	IP;
	long		port;
	CTime		installDate;
	CStringW	installCompany;
	CStringW	installCompanyCall;
	CStringW	maintainCompany;
	CStringW	maintainCompanyCall;
	BOOL		enable;

public:

	CStringW ToInsertQuery(LPCTSTR tableName) const;
	CStringW ToUpdateQuery(LPCTSTR tableName, long enclosureIndex) const;

};

struct EnclEquipInform
{
public:

	EnclEquipInform();
	EnclEquipInform(const CGetAllEquipmentAndEnclosure& enclDataset);
	EnclEquipInform(const CGetAllEquipmentAndEnclosure* pEnclDataset);

public:

	long		index;
	CStringW	equipModelName;
	CStringW	group1;
	CStringW	group2;
	CStringW	installLocation;
	CStringW	enclosureID;
	long		maintenanceIndex;
	CStringW	instalClassification;
	CStringW	installAddress;
	double		latitude;
	double		longitude;
	CStringW	IP;
	long		port;
	CTime		installDate;
	CStringW	installCompany;
	CStringW	installCompanyCall;
	CStringW	maintainCompany;
	CStringW	maintainCompanyCall;
	BOOL		enable;
	CStringW	modelName;
	CStringW	type;
	CStringW	manufacturer;
	CStringW	revenue;
	long		enclosureIndex;

public:

	CStringW ToInsertQuery(LPCTSTR tableName) const;
	CStringW ToUpdateQuery(LPCTSTR tableName, long enclosureIndex) const;

};

class DataManageDB
{
public:

	// 함체 정보 : 설치된 각 함체에 대한 정보
	static CRecordset* GetAllEnclosures();
	static bool AddEnclosure(const EnclosureInform& inform);
	static bool UpdateEnclosure(long index, const EnclosureInform& inform);
	static bool DeleteEnclosure(long index);

	// 함체-장비 연결 정보
	static CRecordset* GetAllEquipmentAndEnclosure();
	static CRecordset* GetAllBaseEquipment();
	static CRecordset* GetChangeEquipHistory(CString enclosureIndexString);
};

