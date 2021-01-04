
// TeamProjectSet.h: CTeamProjectSet Ŭ������ �������̽�
//


#pragma once

// �ڵ� ���� ��ġ 2018�� 11�� 16�� �ݿ���, ���� 3:46

class CTeamProjectSet : public CRecordset
{
public:
	CTeamProjectSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CTeamProjectSet)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA:
//ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.  // ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

	long	m_Index;
	CStringW	m_GropName1;	//�׷��1, ��)�Ⱦ��
	CStringW	m_GropName2;	//�׷��2, ��)�����
	CStringW	m_State;	//����, ��)������
	CStringW	m_LocationName;	//��ü��ġ ��, ��)����2�� �������;�
	CStringW	m_InstallationClassification;	//��ġ����, ��)���2��
	CStringW	m_InstallationAddress;	//��ġ�ּ�, ��)���ȱ� �ùδ��38
	CStringW	m_Etc;	//��Ÿ

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
	static int idxArray[200];
	static int idxArryIndex;
};

