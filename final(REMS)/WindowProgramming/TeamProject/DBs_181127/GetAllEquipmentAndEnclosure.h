// GetAllEquipmentAndEnclosure.h : CGetAllEquipmentAndEnclosure�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2018�� 11�� 21�� ������, ���� 12:22
#include <afxdb.h>

class CGetAllEquipmentAndEnclosure : public CRecordset
{
public:
	CGetAllEquipmentAndEnclosure(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CGetAllEquipmentAndEnclosure)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA:ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.  // ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

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

// ������
	// �����翡�� ������ ���� �Լ� ������
	public:
	virtual CString GetDefaultConnect();	// �⺻ ���� ���ڿ�

	virtual CString GetDefaultSQL(); 	// ���ڵ� ������ �⺻ SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ����

// ����
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


