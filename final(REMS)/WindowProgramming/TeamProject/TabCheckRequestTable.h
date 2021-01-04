// TabCheckRequestTable.h : CTabCheckRequestTable�� �����Դϴ�.

#pragma once
#include "afxcmn.h"

// �ڵ� ���� ��ġ 2018�� 11�� 22�� �����, ���� 7:52

class CTabCheckRequestTable : public CRecordset
{
public:
	CTabCheckRequestTable(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CTabCheckRequestTable)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA:
//ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.  // ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

	long	m_RequestIndex;
	long	m_EnclosureIndex;
	CStringW	m_EquipModelName;
	CStringW	m_CheckType;	//��������, ��)����
	CTime	m_RequestDate;	//��û�ð�, ��)2014-08-21
	CStringW	m_RequestDescription;
	BOOL	m_Checked;
	CTime	m_CheckedDate;	//��û�ð�, ��)2014-08-21

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

	void UpdateList();
	CListCtrl m_ListCtrl;
};


