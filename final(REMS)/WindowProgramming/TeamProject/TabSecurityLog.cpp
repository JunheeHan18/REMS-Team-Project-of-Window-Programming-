// TabSecurityLog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "TabSecurityLog.h"
#include "afxdialogex.h"

// CTabSecurityLog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTabSecurityLog, CDialogEx)

CTabSecurityLog::CTabSecurityLog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabSecurityLog::IDD, pParent)
	,m_GroupName1(_T(""))
	,m_GroupName2(_T(""))
	,m_EnclosureLocate(_T(""))
	,m_InOutName(_T(""))
	,m_EnteringTime(_T(""))
	,m_GetOutTime(_T(""))
	,m_Date1(_T(""))
	,m_Date2(_T(""))
{

}

CTabSecurityLog::~CTabSecurityLog()
{
}

void CTabSecurityLog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_SECURITYLIST, m_ListCtrl);
	DDX_Text(pDX, IDC_LOCATENAME, m_EnclosureLocate);
	DDX_Text(pDX, IDC_INOUTNAME, m_InOutName);
	DDX_Text(pDX, IDC_ENTERTIME, m_EnteringTime);
	DDX_Text(pDX, IDC_OUTTIME, m_GetOutTime);
}


BEGIN_MESSAGE_MAP(CTabSecurityLog, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_SECURITYLIST, &CTabSecurityLog::OnLvnItemchangedSecuritylist)
	ON_EN_CHANGE(IDC_ENTERTIME, &CTabSecurityLog::OnEnChangeEntertime)
END_MESSAGE_MAP()


// CTabSecurityLog 메시지 처리기입니다.
void CTabSecurityLog::UpdateList() {
	m_ListCtrl.DeleteAllItems();
	CDatabase db;
	db.OpenEx(L"DSN=enclosure");
	CRecordset rs(&db);
	CRect rect;
	m_ListCtrl.GetClientRect(rect);
	short width[] = { 60, 80, 80, 90, 70, 180, 180};
	int align[] = { LVCFMT_CENTER, LVCFMT_LEFT, LVCFMT_LEFT, 
		LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT };
	LPCTSTR name[] = { _T("번호"), _T("그룹명1"), _T("그룹명2"), 
		_T("함체위치명"), _T("출입자명"), _T("입장시간"),_T("퇴장시간") };

	for (int i = 0; i <= 6; i++) {
		m_ListCtrl.InsertColumn(i + 1, name[i], align[i], width[i]);
	}
	rs.m_pDatabase = &db;
	rs.Open(NULL, L"SELECT * FROM EnclosureSecurityLogTable;");
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



void CTabSecurityLog::OnLvnItemchangedSecuritylist(NMHDR *pNMHDR, LRESULT *pResult)
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
		m_GroupName1 = m_ListCtrl.GetItemText(m_nSelected, 1);
		m_GroupName2 = m_ListCtrl.GetItemText(m_nSelected, 2);
		m_EnclosureLocate = m_ListCtrl.GetItemText(m_nSelected, 3);
		m_InOutName = m_ListCtrl.GetItemText(m_nSelected, 4);
		m_EnteringTime = m_ListCtrl.GetItemText(m_nSelected, 5);
		m_GetOutTime = m_ListCtrl.GetItemText(m_nSelected, 6);
		UpdateData(false);

	}
}

BOOL CTabSecurityLog::OnInitDialog() {
	CDialogEx::OnInitDialog();

	UpdateList();
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;
}

void CTabSecurityLog::OnEnChangeEntertime()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
