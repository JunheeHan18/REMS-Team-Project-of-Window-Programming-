// TabRegBase.cpp : 구현 파일입니다.

#include "stdafx.h"
#include "TeamProject.h"
#include "TabRegBase.h"
#include "afxdialogex.h"
#include "TeamProjectSet.h"
#include "TeamProjectDoc.h"
#include "TeamProjectView.h"
#include "MyDB.h"
#include "MapDialog.h"

// CTabRegBase 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTabRegBase, CDialogEx)

CTabRegBase::CTabRegBase(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabRegBase::IDD, pParent)
	, m_LocationName(_T(""))
	, m_GropName1(_T(""))
	, m_GropName2(_T(""))
	, m_State(_T(""))
	, m_InstallationClassification(_T(""))
	, m_InstallationAddress(_T(""))
	, m_Etc(_T(""))
	, m_nSelected(0)
	, m_Index(_T(""))
	, m_EnclosureID(_T(""))
	, m_MaintenanceIndex(_T(""))
	, m_Latitude(_T(""))
	, m_Longitude(_T(""))
	, m_IP(_T(""))
	, m_Port(_T(""))
	, m_InstallDate(_T(""))
	, m_InstallCompany(_T(""))
	, m_InstallCompanyCall(_T(""))
	, m_MaintainCompany(_T(""))
	, m_MaintainCompanyCall(_T(""))
	, m_Groups(NULL)
	, m_nGroups(0)
	, m_Groups2(NULL)
	, m_nGroups2(0)
{
	m_Groups = new CString[100];
	m_Groups2 = new CString[100];
}

CTabRegBase::~CTabRegBase()
{
}

void CTabRegBase::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST_BASE, m_ListCtrl);
	DDX_Text(pDX, IDC_COMBO_GROPNAME1, m_GropName1);
	DDX_Control(pDX, IDC_COMBO_GROPNAME1, m_ComboGroup1);
	DDX_Text(pDX, IDC_COMBO_GROPNAME2, m_GropName2);
	DDX_Control(pDX, IDC_COMBO_GROPNAME2, m_ComboGroup2);
	DDX_Text(pDX, IDC_COMBO_STATE, m_State);
	DDX_Text(pDX, IDC_EDIT_LOCATIONNAME, m_LocationName);
	DDX_Text(pDX, IDC_EDIT_INSTALLATIONCLASSIFICATION, m_InstallationClassification);
	DDX_Text(pDX, IDC_EDIT_INSTALLATIONADDRESS, m_InstallationAddress);
	DDX_Text(pDX, IDC_EDIT_BASEID, m_EnclosureID);
	DDX_Text(pDX, IDC_EDIT_MANAGENUM, m_MaintenanceIndex);
	DDX_Text(pDX, IDC_EDIT_LATITUDE, m_Latitude);
	DDX_Text(pDX, IDC_EDIT_LONGITUDE, m_Longitude);
	DDX_Text(pDX, IDC_EDIT_IP, m_IP);
	DDX_Text(pDX, IDC_EDIT_PORT, m_Port);
	DDX_Text(pDX, IDC_COMBO_DATE, m_InstallDate);
	DDX_Text(pDX, IDC_EDIT_INSTCOMPANY, m_InstallCompany);
	DDX_Text(pDX, IDC_EDIT_MAINTCOMPANY, m_MaintainCompany);
	DDX_Text(pDX, IDC_EDIT_PHONE, m_MaintainCompanyCall);
}


BEGIN_MESSAGE_MAP(CTabRegBase, CDialogEx)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_BASE, &CTabRegBase::OnLvnColumnclickListBase)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_BASE, &CTabRegBase::OnLvnItemchangedListBase)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CTabRegBase::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SELECT, &CTabRegBase::OnBnClickedButtonSelect)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CTabRegBase::OnBnClickedButtonDelete)
END_MESSAGE_MAP()


// CTabRegBase 메시지 처리기입니다.


BOOL CTabRegBase::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	short width[] = { 40, 80, 80, 120, 50, 80, 80, 200, 80, 80, 80, 80, 120, 100, 100, 100, 100 };
	int align[] = { LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT };
	LPCTSTR name[] = { _T("번호"), _T("그룹명1"), _T("그룹명2"), _T("함체위치"), _T("ID"), _T("정비번호"), _T("설치구분"), _T("설치주소"), _T("위도"), _T("경도"), _T("IP"), _T("Port"), _T("준공일"), _T("설치업체"), _T("설치업체번호"), _T("유지보수업체"), _T("업체연락처") };
	for (int i = 0; i <= 16; i++)
	{
		m_ListCtrl.InsertColumn(i + 1, name[i], align[i], width[i]);
	}

	UpdateList();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CTabRegBase::OnLvnColumnclickListBase(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	*pResult = 0;

	LVCOLUMN Column;
	
}


void CTabRegBase::OnLvnItemchangedListBase(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;

	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	if ((pNMListView->uChanged & LVIF_STATE) &&
		(pNMListView->uNewState & LVIS_SELECTED))
	{
		m_nSelected = pNMListView->iItem;	
		m_Index = m_ListCtrl.GetItemText(m_nSelected, 0);
		m_GropName1 = m_ListCtrl.GetItemText(m_nSelected, 1);
		m_GropName2 = m_ListCtrl.GetItemText(m_nSelected, 2);
		m_LocationName = m_ListCtrl.GetItemText(m_nSelected, 3);
		m_EnclosureID = m_ListCtrl.GetItemText(m_nSelected, 4);
		m_MaintenanceIndex = m_ListCtrl.GetItemText(m_nSelected, 5);
		m_InstallationClassification = m_ListCtrl.GetItemText(m_nSelected, 6);
		m_InstallationAddress = m_ListCtrl.GetItemText(m_nSelected, 7);
		m_Latitude = m_ListCtrl.GetItemText(m_nSelected, 8);
		m_Longitude = m_ListCtrl.GetItemText(m_nSelected, 9);
		m_IP = m_ListCtrl.GetItemText(m_nSelected, 10);
		m_Port = m_ListCtrl.GetItemText(m_nSelected, 11);
		m_InstallDate = m_ListCtrl.GetItemText(m_nSelected, 12);
		m_InstallCompany = m_ListCtrl.GetItemText(m_nSelected, 13);
		m_InstallCompanyCall = m_ListCtrl.GetItemText(m_nSelected, 14);
		m_MaintainCompany = m_ListCtrl.GetItemText(m_nSelected, 15);
		m_MaintainCompanyCall = m_ListCtrl.GetItemText(m_nSelected, 16);
		UpdateData(false);
	}
}


void CTabRegBase::UpdateList()
{
	m_ListCtrl.DeleteAllItems();

	CDatabase db;
	db.OpenEx(L"DSN=enclosure");
	CRecordset rs(&db);

	int i;

	rs.m_pDatabase = &db;
	rs.Open(NULL, L"SELECT * FROM EnclosureInstallTable;");
	short maxRow = rs.GetRecordCount();
	CString itemStr;
	CString intToCStr;
	int idx = 0;
	while (!rs.IsEOF()) {
		intToCStr.Format(_T("%d"), idx);
		m_ListCtrl.InsertItem(idx, intToCStr);
		for (int j = 0; j <= 16; j++) {
			rs.GetFieldValue((short)j, itemStr);
			m_ListCtrl.SetItemText(idx, j, itemStr);
			if (j == 1) {
				SetGroups(itemStr);
			}
			if (j == 2) {
				SetGroups2(itemStr);
			}
		}
		idx++;
		rs.MoveNext();
	}
	rs.Close();
	db.Close();

	m_ComboGroup1.ResetContent();
	m_ComboGroup2.ResetContent();
	for (i = 0; i < m_nGroups; i++) {
		m_ComboGroup1.AddString(m_Groups[i]);
	}
	for (i = 0; i < m_nGroups2; i++) {
		m_ComboGroup2.AddString(m_Groups2[i]);
	}
	UpdateData(false);
}

void CTabRegBase::OnBnClickedButtonAdd()
{
	CMyDB mydb;
	CRecordset *pRecordset = mydb.GetRecordset(_T("Select * from EnclosureInstallTable"));

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);
	if (m_GropName1 == "") {
		AfxMessageBox(_T("그룹명1을 입력해주세요!"));
		return;
	}
	if (m_GropName2 == "") {
		AfxMessageBox(_T("그룹명2을 입력해주세요!"));
		return;
	}
	if (m_LocationName == "") {
		AfxMessageBox(_T("함체위치를 입력해주세요!"));
		return;
	}
	if (m_InstallationClassification == "") {
		AfxMessageBox(_T("설치구분을 입력해주세요!"));
		return;
	}
	if (m_InstallationAddress == "") {
		AfxMessageBox(_T("설치주소를 입력해주세요!"));
		return;
	}

	CDatabase db;
	db.OpenEx(L"DSN=enclosure");
	CRecordset rs(&db);

	rs.m_pDatabase = &db;
	CString command;
	command.Format(_T("insert into EnclosureInstallTable(Group1, Group2, InstallLocation, EnclosureID, MaintenanceIndex, InstalClassification, InstallAddress, Latitude, Longitude, IP, Port, InstallDate, InstallCompany, InstallCompanyCall, MaintainCompany, MaintainCompanyCall) values ('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s', '%s', '%s', '%s', '%s', '%s', '%s');")
		, m_GropName1, m_GropName2, m_LocationName, m_EnclosureID, m_MaintenanceIndex, m_InstallationClassification, m_InstallationAddress, m_Latitude, m_Longitude, m_IP, m_Port, m_InstallDate, m_InstallCompany, m_InstallCompanyCall, m_MaintainCompany, m_MaintainCompanyCall);
	db.ExecuteSQL(command);
	rs.Close();
	db.Close();

	UpdateList();
}

void CTabRegBase::SetGroups(CString str)
{
	int i;

	for (i = 0; i < m_nGroups; i++) {
		if (!m_Groups[i].Compare(str)) {
			return;
		}
	}

	m_Groups[m_nGroups++] = str;
}


void CTabRegBase::SetGroups2(CString str)
{
	int i;

	for (i = 0; i < m_nGroups2; i++) {
		if (!m_Groups2[i].Compare(str)) {
			return;
		}
	}

	m_Groups2[m_nGroups2++] = str;
}


void CTabRegBase::OnBnClickedButtonSelect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMapDialog dlg;
	dlg.DoModal();
}


BOOL CTabRegBase::PreTranslateMessage(MSG* pMsg)
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


void CTabRegBase::OnBnClickedButtonDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDatabase db;
	db.OpenEx(L"DSN=enclosure");
	CRecordset rs(&db);

	rs.m_pDatabase = &db;
	CString command;
	command.Format(_T("delete from EnclosureInstallTable where Index = %s;"), m_Index);
	db.ExecuteSQL(command);
	rs.Close();
	db.Close();

	UpdateList();
}
