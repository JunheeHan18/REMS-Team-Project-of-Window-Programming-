// GetRequestedEnclosureEquipID.h : CGetRequestedEnclosureEquipID�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2018�� 11�� 21�� ������, ���� 2:06
#include <afxdb.h>

class CGetRequestedEnclosureEquipID : public CRecordset
{
public:
	CGetRequestedEnclosureEquipID(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CGetRequestedEnclosureEquipID)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA:ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.  // ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

	long		enclosureIndex;
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


