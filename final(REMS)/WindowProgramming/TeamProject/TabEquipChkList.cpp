// TabEquipChkList.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "TabCheckRequest.h"
#include "afxdialogex.h"
#include "TeamProjectSet.h"
#include "TeamProjectDoc.h"
#include "TeamProjectView.h"
#include "MyDB.h"
#include "TabCheckRequestTable.h"
#include "TabEquipChkList.h"
#include "ChartDlg.h"

// TabEquipChkList ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(TabEquipChkList, CDialogEx)

TabEquipChkList::TabEquipChkList(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EQUIPCHECKLIST, pParent)
	, m_Index(0)
	, m_EnclosureIndex(_T(""))
	, m_EquipModelName(_T(""))
	, m_CheckType(_T(""))
	, m_RequestDate(_T(""))
	, m_RequestDescript(_T(""))
	, m_CheckDate(_T(""))
	, m_check(0)
{

}

TabEquipChkList::~TabEquipChkList()
{
}

void TabEquipChkList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
	DDX_Control(pDX, IDC_LIST_BASE, m_ListCtrl);
	DDX_Text(pDX, IDC_HUBNAME, m_EnclosureIndex);
	DDX_Text(pDX, IDC_INSTALLLOC, m_EquipModelName);
	DDX_Text(pDX, IDC_CHECKTYPE, m_CheckType);
	DDX_Text(pDX, IDC_REQUESTDATE, m_RequestDate);
	DDX_Text(pDX, IDC_EQUIPTYPE, m_RequestDescript);
	DDX_Text(pDX, IDC_CHECKDATE, m_CheckDate);

}


BEGIN_MESSAGE_MAP(TabEquipChkList, CDialogEx)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_BASE, &TabEquipChkList::OnLvnColumnclickListBase)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_BASE, &TabEquipChkList::OnLvnItemchangedListBase)
	//ON_BN_CLICKED(IDC_BUTTON_ADD, &TabEquipChkList::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_CheckConfirm, &TabEquipChkList::OnBnClickedCheckconfirm)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &TabEquipChkList::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON_CHARTVIEW, &TabEquipChkList::OnBnClickedButtonChartview)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// TabEquipChkList �޽��� ó�����Դϴ�.


BOOL TabEquipChkList::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	UpdateList();
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}



void TabEquipChkList::UpdateListDevice()
{


}


void TabEquipChkList::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void TabEquipChkList::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void TabEquipChkList::OnLvnItemchangedListBase(NMHDR * pNMHDR, LRESULT * pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	*pResult = 0;

	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	if ((pNMListView->uChanged & LVIF_STATE) &&
		(pNMListView->uNewState & LVIS_SELECTED)) {
		CString ItemData;
		m_nSelected = pNMListView->iItem;
		ItemData = m_ListCtrl.GetItemText(m_nSelected, 0);
		m_Index = _ttoi(ItemData);
		m_EnclosureIndex = m_ListCtrl.GetItemText(m_nSelected, 1);
		m_EquipModelName = m_ListCtrl.GetItemText(m_nSelected, 2);
		m_RequestDescript = m_ListCtrl.GetItemText(m_nSelected, 3);
		//m_Check = m_ListCtrl.GetItemText(m_nSelected, 4);
		m_CheckType = m_ListCtrl.GetItemText(m_nSelected, 4);
		m_RequestDate = m_ListCtrl.GetItemText(m_nSelected, 5);
		//m_CheckDate = m_ListCtrl.GetItemText(m_nSelected, 6);
		UpdateData(false);
	}
}


void TabEquipChkList::OnLvnColumnclickListBase(NMHDR * pNMHDR, LRESULT * pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	*pResult = 0;

	LVCOLUMN Column;
}


void TabEquipChkList::UpdateList()
{
	m_ListCtrl.DeleteAllItems();

	int j;
	CDatabase db;
	db.OpenEx(L"DSN=enclosure");
	CRecordset rs(&db);
	int columnNum = 1;
	CString columnStr;

	short width[] = { 70, 70, 120, 70, 120, 150, 120, };
	int align[] = { LVCFMT_CENTER, LVCFMT_CENTER, LVCFMT_CENTER, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_CENTER, LVCFMT_LEFT, LVCFMT_CENTER };
	LPCTSTR name[] = { _T("����"), _T("����ȣ"), _T("�𵨸�"), _T("��������"), _T("��û�Ͻ�"), _T("���˳���"), _T("�����Ͻ�") };
	if (m_check != 1) {
		for (int i = 0; i <= 6; i++) {
			m_ListCtrl.InsertColumn(i + 1, name[i], align[i], width[i]);
		}
		m_check = 1;
	}
	rs.m_pDatabase = &db;
	rs.Open(NULL, L"SELECT * FROM EnclosureCheckRequestTable");
	short maxRow = rs.GetRecordCount();
	CString itemStr;
	CString intToCStr;
	int idx = 0;
	while (!rs.IsEOF()) {
		rs.GetFieldValue((short)6, itemStr);
		if (itemStr.Compare(_T("1"))) {
			rs.MoveNext();
			continue;
		}
		intToCStr.Format(_T("%d"), idx);
		m_ListCtrl.InsertItem(idx, intToCStr);
		for (j = 0; j < 7; j++) {
			if (j == 0) {
				columnStr.Format(_T("%d"), columnNum);
				m_ListCtrl.SetItemText(idx, j, columnStr);
				columnNum++;
			}
			else if (j != 6) {
				rs.GetFieldValue((short)j, itemStr);
				
				m_ListCtrl.SetItemText(idx, j, itemStr);
			}
			else {
				rs.GetFieldValue((short)7, itemStr);
				m_ListCtrl.SetItemText(idx, 6, itemStr);
				break;
			}

			//if (m_ListCtrl.GetItemText(idx, 6) != "1") {
			//break;
			//      }
			//   continue;
			//}
			//m_ListCtrl.SetItemText(idx, j, itemStr);
		}
		idx++;
		rs.MoveNext();
	}
	rs.Close();
	db.Close();
}


/*void TabEquipChkList::OnBnClickedButtonAdd()
{
	CMyDB mydb;
	CRecordset *pRecordset = mydb.GetRecordset(_T("Select *from EquipCheckListTable"));
	CString str;
	pRecordset->GetFieldValue(3, str);

	AfxMessageBox(str);

	UpdateData(true);
	if (m_HubName == "") {
		AfxMessageBox(_T("��ü��ġ���� �Է����ּ���!"));
		return;
	}
	if (m_InstallLoc == "") {
		AfxMessageBox(_T("��ġ��Ҹ��� �Է����ּ���!"));
		return;
	}
	if (m_EquipType == "") {
		AfxMessageBox(_T("��� Type�� �Է����ּ���!"));
		return;
	}
	if (m_CheckType == "") {
		AfxMessageBox(_T("���������� �Է����ּ���!"));
		return;
	}
	if (m_RequestDate == "") {
		AfxMessageBox(_T("��û�Ͻø� �Է����ּ���!"));
		return;
	}
	if (m_CheckDate == "") {
		AfxMessageBox(_T("�����Ͻø� �Է����ּ���!"));
	}

	CDatabase db;
	db.OpenEx(L"DSN=HubManage");
	CRecordset rs(&db);

	rs.m_pDatabase = &db;
	CString command;
	command.Format(_T("insert into EquipCheckListTable(HubLocName, InstallLocName, EquipType, CheckType, RequestDate, CheckDate) values('%s', '%s', '%s', '%s', '%s', '%s'); "), m_HubName, m_InstallLoc, m_EquipType, m_CheckType, m_RequestDate, m_CheckDate);
	db.ExecuteSQL(command);
	rs.Close();
	db.Close();

	UpdateList();
}
*/

void TabEquipChkList::OnBnClickedCheckconfirm()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ���� ���� �Է�
	CTime timer = CTime::GetCurrentTime();

	//COleDateTime curTime = COleDateTime::GetCurrentTime();
	CString strDate;
	CString command, command2;
	if (m_CheckDate.IsEmpty()) {
		strDate.Format(_T("%d-%02d-%02d"), timer.GetYear(), timer.GetMonth(), timer.GetDay());
		command2.Format(_T("UPDATE EnclosureCheckRequestTable SET CheckedDate='%s' WHERE RequestIndex=%d"), strDate, CTeamProjectSet::idxArray[m_clickIndex]);
	}
	else
	{
		strDate=m_CheckDate;
		AfxMessageBox(m_CheckDate);
		command2.Format(_T("UPDATE EnclosureCheckRequestTable SET CheckedDate='%s' WHERE RequestIndex=%d"), strDate, CTeamProjectSet::idxArray[m_clickIndex]);
	}
	
	//int index = m_ListCtrl.GetNextItem(-1, LVNI_SELECTED);
	//AfxMessageBox(str);
	// ���� ���� ���̺��� ���˵� ���� ����
		if (LVIS_SELECTED == m_ListCtrl.GetItemState(m_clickIndex, LVIS_SELECTED))
	{
		//m_ListCtrl.SetItemText(m_clickIndex, 6, strDate);
		//TabEquipChkList::UpdateList();
	}
		
		CDatabase db;
		db.OpenEx(L"DSN=enclosure");
		CRecordset rs(&db);

		rs.m_pDatabase = &db;
		command.Format(_T("UPDATE EnclosureCheckRequestTable SET Checked=%d WHERE RequestIndex=%d"), 0, CTeamProjectSet::idxArray[m_clickIndex]);
		db.ExecuteSQL(command);
		db.ExecuteSQL(command2);
		rs.Close();
		db.Close();
		TabEquipChkList::UpdateList();
}




void TabEquipChkList::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_clickIndex = pNMItemActivate->iItem;
	m_ListCtrl.SetItemText(m_clickIndex, 4, 0);
	*pResult = 0;
}


void TabEquipChkList::OnBnClickedButtonChartview()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CChartDlg Dlg;
	Dlg.DoModal();
}


void TabEquipChkList::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
					   // �׸��� �޽����� ���ؼ��� CDialogEx::OnPaint()��(��) ȣ������ ���ʽÿ�.
	UpdateList();
}


BOOL TabEquipChkList::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN)
		{
			return TRUE;
		}
		else if (pMsg->wParam == VK_ESCAPE)
		{
			return TRUE;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
