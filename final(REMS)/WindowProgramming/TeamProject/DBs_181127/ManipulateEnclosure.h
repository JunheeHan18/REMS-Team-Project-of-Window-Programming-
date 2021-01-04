// ManipulateEnclosure.h : CManipulateEnclosure�� �����Դϴ�.

#pragma once

// �ڵ� ���� ��ġ 2018�� 11�� 21�� ������, ���� 2:56
#include <afxdb.h>

class CManipulateEnclosure : public CRecordset
{
public:
	CManipulateEnclosure(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CManipulateEnclosure)

// �ʵ�/�Ű� ���� ������

// �Ʒ��� ���ڿ� ����(���� ���)�� �����ͺ��̽� �ʵ��� ���� ������ ������
// ��Ÿ���ϴ�(CStringA:ANSI ������ ����, CStringW: �����ڵ� ������ ����).
// �̰��� ODBC ����̹����� ���ʿ��� ��ȯ�� ������ �� ������ �մϴ�.  // ���� ��� �̵� ����� CString �������� ��ȯ�� �� ������
// �׷� ��� ODBC ����̹����� ��� �ʿ��� ��ȯ�� �����մϴ�.
// (����: �����ڵ�� �̵� ��ȯ�� ��� �����Ϸ���  ODBC ����̹�
// ���� 3.5 �̻��� ����ؾ� �մϴ�).

	long	m_Index;
	CStringW	m_Group1;	//�׷�1, ��)�Ⱦ��
	CStringW	m_Group2;	//�׷�2, ��)�긱����
	CStringW	m_InstallLocation;	//��ü��ġ��, ��)����2�� �������;�
	CStringW	m_EnclosureID;	//��üID, ��)8F62
	long	m_MaintenanceIndex;	//������ȣ
	CStringW	m_InstalClassification;	//��ġ����, ��)���2��
	CStringW	m_InstallAddress;	//��ġ�ּ�, ��)���ȱ� �ùδ��38
	double	m_Latitude;	//����, ��)37.39682437753123
	double	m_Longitude;	//�浵, ��)126.97314648448451
	CStringW	m_IP;	//��)255.255.0.1
	long	m_Port;	//��Ʈ��ȣ
	CTime	m_InstallDate;	//�ذ���, ��)2014-08-21
	CStringW	m_InstallCompany;	//��ġ��ü, ��)�긱����
	CStringW	m_InstallCompanyCall;	//��ġ��ü����ó(pt������)
	CStringW	m_MaintainCompany;	//����������ü, ��)�긱����
	CStringW	m_MaintainCompanyCall;	//����������ü����ó(pt������)
	BOOL	m_Enable;	//��뿩��

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


