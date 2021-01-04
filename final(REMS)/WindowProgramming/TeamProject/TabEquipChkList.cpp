// TabEquipChkList.cpp : 구현 파일입니다.
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

// TabEquipChkList 대화 상자입니다.

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


// TabEquipChkList 메시지 처리기입니다.


BOOL TabEquipChkList::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	UpdateList();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}



void TabEquipChkList::UpdateListDevice()
{


}


void TabEquipChkList::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void TabEquipChkList::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	LPCTSTR name[] = { _T("구분"), _T("장비번호"), _T("모델명"), _T("점검유형"), _T("요청일시"), _T("점검내역"), _T("점검일시") };
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
		AfxMessageBox(_T("함체위치명을 입력해주세요!"));
		return;
	}
	if (m_InstallLoc == "") {
		AfxMessageBox(_T("설치장소명을 입력해주세요!"));
		return;
	}
	if (m_EquipType == "") {
		AfxMessageBox(_T("장비 Type을 입력해주세요!"));
		return;
	}
	if (m_CheckType == "") {
		AfxMessageBox(_T("점검유형을 입력해주세요!"));
		return;
	}
	if (m_RequestDate == "") {
		AfxMessageBox(_T("요청일시를 입력해주세요!"));
		return;
	}
	if (m_CheckDate == "") {
		AfxMessageBox(_T("점검일시를 입력해주세요!"));
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 점검 일자 입력
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
	// 점검 내역 테이블에서 점검된 내역 삭제
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_clickIndex = pNMItemActivate->iItem;
	m_ListCtrl.SetItemText(m_clickIndex, 4, 0);
	*pResult = 0;
}


void TabEquipChkList::OnBnClickedButtonChartview()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CChartDlg Dlg;
	Dlg.DoModal();
}


void TabEquipChkList::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
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
