
// TeamProjectSet.h: CTeamProjectSet 클래스의 인터페이스
//


#pragma once

// 코드 생성 위치 2018년 11월 16일 금요일, 오후 3:46

class CTeamProjectSet : public CRecordset
{
public:
	CTeamProjectSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CTeamProjectSet)

// 필드/매개 변수 데이터

// 아래의 문자열 형식(있을 경우)은 데이터베이스 필드의 실제 데이터 형식을
// 나타냅니다(CStringA:
//ANSI 데이터 형식, CStringW: 유니코드 데이터 형식).
// 이것은 ODBC 드라이버에서 불필요한 변환을 수행할 수 없도록 합니다.  // 원할 경우 이들 멤버를 CString 형식으로 변환할 수 있으며
// 그럴 경우 ODBC 드라이버에서 모든 필요한 변환을 수행합니다.
// (참고: 유니코드와 이들 변환을 모두 지원하려면  ODBC 드라이버
// 버전 3.5 이상을 사용해야 합니다).

	long	m_Index;
	CStringW	m_GropName1;	//그룹명1, 예)안양시
	CStringW	m_GropName2;	//그룹명2, 예)방범용
	CStringW	m_State;	//상태, 예)정상동작
	CStringW	m_LocationName;	//함체위치 명, 예)관양2동 복지센터앞
	CStringW	m_InstallationClassification;	//설치구분, 예)방범2차
	CStringW	m_InstallationAddress;	//설치주소, 예)동안구 시민대로38
	CStringW	m_Etc;	//기타

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
	static int idxArray[200];
	static int idxArryIndex;
};

