// GetAllChangeEquipHistory.h : CGetAllChangeEquipHistory�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2018�� 12�� 4�� ȭ����, ���� 1:06

class CGetAllChangeEquipHistory : public CRecordset
{
public:
	CGetAllChangeEquipHistory(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CGetAllChangeEquipHistory)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA:ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.  // ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

	long	m_Index;
	long	m_EnclosureIndex;
	CStringW	m_Type;
	CStringW	m_PrevEquipModelName;
	CStringW	m_ChangedEquipModelName;
	CStringW	m_Description;
	CTime	m_ChangeDate;

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


