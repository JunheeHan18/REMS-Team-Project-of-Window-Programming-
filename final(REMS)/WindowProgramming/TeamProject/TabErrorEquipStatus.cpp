// TabErrorEquipStatus.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "TabErrorEquipStatus.h"
#include "afxdialogex.h"


// CTabErrorEquipStatus 대화 상자입니다.

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


// CTabErrorEquipStatus 메시지 처리기입니다.


void CTabErrorEquipStatus::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTabErrorEquipStatus::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	LPCTSTR name[] = { _T("번호"), _T("점검상태"), _T("장비Type"), _T("설치장소명"), _T("IP"), _T("장애일"), _T("장애사유") };
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

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	UpdateListDevice();
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CTabErrorEquipStatus::OnLvnItemchangedListErrEquipStatus(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
