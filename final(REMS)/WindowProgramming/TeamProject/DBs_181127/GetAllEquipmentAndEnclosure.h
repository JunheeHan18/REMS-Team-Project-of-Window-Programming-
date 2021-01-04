// GetAllEquipmentAndEnclosure.h : CGetAllEquipmentAndEnclosure의 선언입니다.

#pragma once

// 코드 생성 위치 2018년 11월 21일 수요일, 오후 12:22
#include <afxdb.h>

class CGetAllEquipmentAndEnclosure : public CRecordset
{
public:
	CGetAllEquipmentAndEnclosure(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CGetAllEquipmentAndEnclosure)

// 필드/매개 변수 데이터

// 아래의 문자열 형식(있을 경우)은 데이터베이스 필드의 실제 데이터 형식을
// 나타냅니다(CStringA:ANSI 데이터 형식, CStringW: 유니코드 데이터 형식).
// 이것은 ODBC 드라이버에서 불필요한 변환을 수행할 수 없도록 합니다.  // 원할 경우 이들 멤버를 CString 형식으로 변환할 수 있으며
// 그럴 경우 ODBC 드라이버에서 모든 필요한 변환을 수행합니다.
// (참고: 유니코드와 이들 변환을 모두 지원하려면  ODBC 드라이버
// 버전 3.5 이상을 사용해야 합니다).

	long		index;
	long		enclosureIndex;
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
	CStringW	equipModelName;

// 재정의
	// 마법사에서 생성한 가상 함수 재정의
	public:
	virtual CString GetDefaultConnect();	// 기본 연결 문자열

	virtual CString GetDefaultSQL(); 	// 레코드 집합의 기본 SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX 지원

// 구현
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


