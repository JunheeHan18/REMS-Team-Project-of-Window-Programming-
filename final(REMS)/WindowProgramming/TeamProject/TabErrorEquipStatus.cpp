// TabErrorEquipStatus.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "TabErrorEquipStatus.h"
#include "afxdialogex.h"


// CTabErrorEquipStatus ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTabErrorEquipStatus, CDialogEx)

CTabErrorEquipStatus::CTabErrorEquipStatus(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabErrorEquipStatus::IDD, pParent)
	, m_EquipStatus(_T(""))
	, m_CheckStatus(_T(""))
	, m_EquipType(_T(""))
	, m_InstallLocate(_T(""))
	, m_IP(_T(""))
	, m_ErrorDate(_T(""))
	, m_ErrorReason(_T(""))
	, m_nSelected(0)
{

}

CTabErrorEquipStatus::~CTabErrorEquipStatus()
{
}

void CTabErrorEquipStatus::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ERR_EQUIP_STATUS, m_ListCtrl);
	DDX_Text(pDX, IDC_EQUIPSTATUS, m_CheckStatus);
	DDX_Text(pDX, IDC_INSTALLLOCNAME, m_InstallLocate);
	DDX_Text(pDX, IDC_ERRORREASON, m_ErrorReason);
}


BEGIN_MESSAGE_MAP(CTabErrorEquipStatus, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CTabErrorEquipStatus::OnEnChangeEdit1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CTabErrorEquipStatus::OnLvnItemchangedList1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_ERR_EQUIP_STATUS, &CTabErrorEquipStatus::OnLvnItemchangedListErrEquipStatus)
	ON_EN_CHANGE(IDC_EQUIPSTATUS, &CTabErrorEquipStatus::OnEnChangeEquipstatus)
END_MESSAGE_MAP()


// CTabErrorEquipStatus �޽��� ó�����Դϴ�.


void CTabErrorEquipStatus::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CTabErrorEquipStatus::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}

void CTabErrorEquipStatus::UpdateListDevice()
{
	m_ListCtrl.DeleteAllItems();

	CDatabase db;
	db.OpenEx(L"DSN=enclosure");
	CRecordset rs(&db);

	short width[] = { 50, 80, 100, 100, 120, 100, 100 };
	int align[] = { LVCFMT_CENTER, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT };
	LPCTSTR name[] = { _T("��ȣ"), _T("���˻���"), _T("���Type"), _T("��ġ��Ҹ�"), _T("IP"), _T("�����"), _T("��ֻ���") };
	for (int i = 0; i <= 6; i++)
	{
		m_ListCtrl.InsertColumn(i + 1, name[i], align[i], width[i]);
	}

	rs.m_pDatabase = &db;
	rs.Open(NULL, L"SELECT * FROM EnclosureErrorEquipStatusTable;");
	short maxRow = rs.GetRecordCount();
	CString itemStr;
	CString intToCStr;
	int idx = 0;
	while (!rs.IsEOF()) {
		intToCStr.Format(_T("%d"), idx);
		m_ListCtrl.InsertItem(idx, intToCStr);
		for (int j = 0; j <= 6; j++) {
			rs.GetFieldValue((short)j, itemStr);
			m_ListCtrl.SetItemText(idx, j, itemStr);
		}
		idx++;
		rs.MoveNext();
	}
	rs.Close();
	db.Close();
}

BOOL CTabErrorEquipStatus::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	UpdateListDevice();
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CTabErrorEquipStatus::OnLvnItemchangedListErrEquipStatus(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;

	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	if ((pNMListView->uChanged & LVIF_STATE) &&
		(pNMListView->uNewState & LVIS_SELECTED))
	{
		CString ItemData;
		m_nSelected = pNMListView->iItem;
		ItemData = m_ListCtrl.GetItemText(m_nSelected, 0);
		m_CheckStatus = m_ListCtrl.GetItemText(m_nSelected, 1);
		m_EquipType = m_ListCtrl.GetItemText(m_nSelected, 2);
		m_InstallLocate = m_ListCtrl.GetItemText(m_nSelected, 3);
		m_IP = m_ListCtrl.GetItemText(m_nSelected, 4);
		m_ErrorDate = m_ListCtrl.GetItemText(m_nSelected, 5);
		m_ErrorReason = m_ListCtrl.GetItemText(m_nSelected, 6);
		UpdateData(false);
	}
}


void CTabErrorEquipStatus::OnEnChangeEquipstatus()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
