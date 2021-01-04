// TabEquipStatus.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "TabEquipStatus.h"
#include "afxdialogex.h"


// CTabEquipStatus ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTabEquipStatus, CDialogEx)

CTabEquipStatus::CTabEquipStatus(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabEquipStatus::IDD, pParent)
	, m_EquipStatus(_T(""))
	, m_EquipType(_T(""))
	, m_InstallLocate(_T(""))
	, m_ManuCorporation(_T(""))
	, m_ModelName(_T(""))
	, m_IP(_T(""))
	, m_InstallPurpose(_T(""))
	, m_nSelected(0)
{

}

CTabEquipStatus::~CTabEquipStatus()
{
}

void CTabEquipStatus::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTEQUIPSTATUS, m_ListCtrl);
	DDX_Text(pDX, IDC_EQUIPSTATUS, m_EquipStatus);
	DDX_Text(pDX, IDC_INSTALLLOCNAME, m_InstallLocate);
	DDX_Text(pDX, IDC_EQUIPTYPE, m_EquipType);
}


BEGIN_MESSAGE_MAP(CTabEquipStatus, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LISTEQUIPSTATUS, &CTabEquipStatus::OnLvnItemchangedListequipstatus)
END_MESSAGE_MAP()


// CTabEquipStatus �޽��� ó�����Դϴ�.

void CTabEquipStatus::UpdateListCtrl()
{
	m_ListCtrl.DeleteAllItems();

	CDatabase db;
	db.OpenEx(L"DSN=enclosure");
	CRecordset rs(&db);

	short width[] = { 50, 80, 80, 80, 80, 80, 120, 100};
	int align[] = { LVCFMT_CENTER, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT};
	LPCTSTR name[] = { _T("��ȣ"), _T("������"), _T("���Type"), _T("��ġ��Ҹ�"), _T("������"), _T("�𵨸�"), _T("IP"), _T("��ġ����")};
	for (int i = 0; i <= 7; i++)
	{
		m_ListCtrl.InsertColumn(i + 1, name[i], align[i], width[i]);
	}

	rs.m_pDatabase = &db;
	rs.Open(NULL, L"SELECT * FROM EnclosureEquipStatusTable;");
	short maxRow = rs.GetRecordCount();
	CString itemStr;
	CString intToCStr;
	int idx = 0;
	while (!rs.IsEOF()) {
		intToCStr.Format(_T("%d"), idx);
		m_ListCtrl.InsertItem(idx, intToCStr);
		for (int j = 0; j <= 7; j++) {
			rs.GetFieldValue((short)j, itemStr);
			m_ListCtrl.SetItemText(idx, j, itemStr);
		}
		idx++;
		rs.MoveNext();
	}
	rs.Close();
	db.Close();
}


BOOL CTabEquipStatus::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	UpdateListCtrl();
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}



void CTabEquipStatus::OnLvnItemchangedListequipstatus(NMHDR *pNMHDR, LRESULT *pResult)
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
		m_EquipStatus = m_ListCtrl.GetItemText(m_nSelected, 1);
		m_EquipType = m_ListCtrl.GetItemText(m_nSelected, 2);
		m_InstallLocate = m_ListCtrl.GetItemText(m_nSelected, 3);
		m_ManuCorporation = m_ListCtrl.GetItemText(m_nSelected, 4);
		m_ModelName = m_ListCtrl.GetItemText(m_nSelected, 5);
		m_IP = m_ListCtrl.GetItemText(m_nSelected, 6);
		m_InstallPurpose = m_ListCtrl.GetItemText(m_nSelected, 7);
		UpdateData(false);
	}
}
