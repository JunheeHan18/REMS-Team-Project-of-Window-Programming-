#pragma once

#include "GetRequestedEnclosureEquipID.h"

struct EnclosureEquipCheckRequest
{
public:

	EnclosureEquipCheckRequest();
	EnclosureEquipCheckRequest(long enclosureIndex, LPCTSTR equipModelName);
	EnclosureEquipCheckRequest(const CGetRequestedEnclosureEquipID& set);
	EnclosureEquipCheckRequest(const CGetRequestedEnclosureEquipID* pSet);

public:

	long enclosureIndex;
	CString equipModelName;
	CString checkType;
	CTime requestDate;
	CString requestDesc;
	BOOL checked;
	CString checkedDate;
	
	CString ToInsertQuery(LPCTSTR tableName) const;

};

class EquipMaintenanceDB
{
public:

	// 요청하였으나 점검안된 함체-장비 레코드셋
	
	CGetRequestedEnclosureEquipID* GetUncheckedRequestID();
	bool AddRequest(const EnclosureEquipCheckRequest& request);
	
};

