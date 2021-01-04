// ManipulateEnclosure.h : CManipulateEnclosure의 선언입니다.

#pragma once

// 코드 생성 위치 2018년 11월 21일 수요일, 오후 2:56
#include <afxdb.h>

class CManipulateEnclosure : public CRecordset
{
public:
	CManipulateEnclosure(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CManipulateEnclosure)

// 필드/매개 변수 데이터

// 아래의 문자열 형식(있을 경우)은 데이터베이스 필드의 실제 데이터 형식을
// 나타냅니다(CStringA:ANSI 데이터 형식, CStringW: 유니코드 데이터 형식).
// 이것은 ODBC 드라이버에서 불필요한 변환을 수행할 수 없도록 합니다.  // 원할 경우 이들 멤버를 CString 형식으로 변환할 수 있으며
// 그럴 경우 ODBC 드라이버에서 모든 필요한 변환을 수행합니다.
// (참고: 유니코드와 이들 변환을 모두 지원하려면  ODBC 드라이버
// 버전 3.5 이상을 사용해야 합니다).

	long	m_Index;
	CStringW	m_Group1;	//그룹1, 예)안양시
	CStringW	m_Group2;	//그룹2, 예)브릴링스
	CStringW	m_InstallLocation;	//함체위치명, 예)관양2동 복지센터앞
	CStringW	m_EnclosureID;	//함체ID, 예)8F62
	long	m_MaintenanceIndex;	//관리번호
	CStringW	m_InstalClassification;	//설치구분, 예)방범2차
	CStringW	m_InstallAddress;	//설치주소, 예)동안구 시민대로38
	double	m_Latitude;	//위도, 예)37.39682437753123
	double	m_Longitude;	//경도, 예)126.97314648448451
	CStringW	m_IP;	//예)255.255.0.1
	long	m_Port;	//포트번호
	CTime	m_InstallDate;	//준공일, 예)2014-08-21
	CStringW	m_InstallCompany;	//설치업체, 예)브릴링스
	CStringW	m_InstallCompanyCall;	//설치업체연락처(pt에없음)
	CStringW	m_MaintainCompany;	//유지보수업체, 예)브릴링스
	CStringW	m_MaintainCompanyCall;	//유지보수업체연락처(pt에없음)
	BOOL	m_Enable;	//사용여부

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


