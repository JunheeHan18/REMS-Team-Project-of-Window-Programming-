// TabBaseConf.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "TabBaseConf.h"
#include "afxdialogex.h"


// CTabBaseConf ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTabBaseConf, CDialogEx) 

CTabBaseConf::CTabBaseConf(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabBaseConf::IDD, pParent)
	, m_Index(0)
	, m_Equipment(_T(""))
	, m_State(_T(""))
	, m_Manufacturer(_T(""))
	, m_ModelName(_T(""))
	, m_IPAddress(_T(""))
	, m_Password(_T(""))
	, m_Etc(_T(""))
	, m_nSelected(0)
{

}

CTabBaseConf::~CTabBaseConf()
{
}

void CTabBaseConf::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DEVICE, m_ListDevice);
	DDX_Control(pDX, IDC_LIST_HISTORY, m_ListHistory);
	DDX_Text(pDX, IDC_EDIT_LOCATIONNAME, m_LocationName);
	DDX_Text(pDX, IDC_EDIT_EQUIPMENT, m_Equipment);
	DDX_Text(pDX, IDC_COMBO_STATE, m_State);
	DDX_Text(pDX, IDC_EDIT_MANUFACTURER, m_Manufacturer);
	DDX_Text(pDX, IDC_EDIT_MODELNAME, m_ModelName);
	DDX_Text(pDX, IDC_EDIT_IP, m_IPAddress);
}


BEGIN_MESSAGE_MAP(CTabBaseConf, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_DEVICE, &CTabBaseConf::OnLvnItemchangedListDevice)
END_MESSAGE_MAP()


// CTabBaseConf �޽��� ó�����Դϴ�.


void CTabBaseConf::UpdateListDevice()
{
	m_ListDevice.DeleteAllItems();

	CDatabase db;
	db.OpenEx(L"DSN=enclosure");
	CRecordset rs(&db);

	short width[] = { 50, 80, 80, 80, 80, 100, 90, 100, 100 };
	int align[] = { LVCFMT_CENTER, LVCFMT_LEFT, LVCFMT_CENTER, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_CENTER, LVCFMT_LEFT, LVCFMT_CENTER, LVCFMT_CENTER };
	LPCTSTR name[] = { _T("��ȣ"), _T("��ü��ġ"), _T("��񱸺�"), _T("�������"), _T("������"), _T("�⺻���"), _T("IP"), _T("��й�ȣ"), _T("��Ÿ") };
	for (int i = 0; i <= 8; i++)
	{
		m_ListDevice.InsertColumn(i + 1, name[i], align[i], width[i]);
	}

	rs.m_pDatabase = &db;
	rs.Open(NULL, L"SELECT * FROM EnclosureInstallTable;");
	short maxRow = rs.GetRecordCount();
	CString itemStr;
	CString intToCStr;
	int idx = 0;
	while (!rs.IsEOF()) {
		intToCStr.Format(_T("%d"), idx);
		m_ListDevice.InsertItem(idx, intToCStr);
		for (int j = 0; j <= 8; j++) {
			rs.GetFieldValue((short)j, itemStr);
			m_ListDevice.SetItemText(idx, j, itemStr);
		}
		idx++;
		rs.MoveNext();
	}
	rs.Close();
	db.Close();
}


BOOL CTabBaseConf::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	UpdateListDevice();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CTabBaseConf::OnLvnItemchangedListDevice(NMHDR *pNMHDR, LRESULT *pResult)
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
		ItemData = m_ListDevice.GetItemText(m_nSelected, 0);
		m_Index = _ttoi(ItemData);
		m_LocationName = m_ListDevice.GetItemText(m_nSelected, 1);
		m_Equipment = m_ListDevice.GetItemText(m_nSelected, 2);
		m_State = m_ListDevice.GetItemText(m_nSelected, 3);
		m_Manufacturer = m_ListDevice.GetItemText(m_nSelected, 4);
		m_ModelName = m_ListDevice.GetItemText(m_nSelected, 5);
		m_IPAddress = m_ListDevice.GetItemText(m_nSelected, 6);
		m_Password = m_ListDevice.GetItemText(m_nSelected, 7);
		m_Etc = m_ListDevice.GetItemText(m_nSelected, 8);
		UpdateData(false);
	}
}
