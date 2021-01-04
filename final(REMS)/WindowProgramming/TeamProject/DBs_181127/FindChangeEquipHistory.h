// FindChangeEquipHistory.h : CFindChangeEquipHistory�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2018�� 11�� 21�� ������, ���� 2:32
#include <afxdb.h>

class CFindChangeEquipHistory : public CRecordset
{
public:
	CFindChangeEquipHistory(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CFindChangeEquipHistory)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA:ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.  // ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

	CStringW	m_InstallLocation;
	CStringW	m_Type;
	CStringW	m_PrevEquipModelName;
	CStringW	m_ChangedEquipModelName;
	CStringW	m_Description;
	CTime	m_Expr1;

// ������
	// �����翡�� ������ ���� �Լ� ������
	public:
	virtual CString GetDefaultConnect();	// �⺻ ���� ���ڿ�

	virtual CString GetDefaultSQL(); 	// ���ڵ� ������ �⺻ SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ����

protected:

	long findEnclosureIndex;
	CStringW findEquipType;

public:

	void SetFindData(long EnclosureIndex, CStringW EquipType);
	BOOL OpenWith(long EnclosureIndex, CStringW EquipType);

// ����
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


