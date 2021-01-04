// TabRegBase.cpp : 구현 파일입니다.
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

int CTabCheckRequest::typeCount[200] = { 0, }; 
int CTabCheckRequest::ArrayCnt=0;

// CTabRegBase 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTabCheckRequest, CDialogEx)


CTabCheckRequest::CTabCheckRequest(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabCheckRequest::IDD, pParent)
	, m_RequestIndex(0)
	, m_EnclosureIndex(0)
	, m_EquipModelName(_T(""))
	, m_CheckType(_T(""))
	, m_RequestDate()
	, m_RequestDescription(_T(""))
	, m_Checked(FALSE)
	, m_CheckedDate()
	, m_strRequest(_T(""))
{

}

CTabCheckRequest::~CTabCheckRequest()
{
}


void CTabCheckRequest::DoDataExchange(CDataExchange* pDX)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST_DATA2, m_ListCtrl);
	DDX_Text(pDX, IDC_EDIT_REQUEST, m_strRequest);
	//DDX_Control(pDX, IDC_LIST_REQUEST, m_LIstRequest);
	DDX_Control(pDX, IDC_COMBO_REQUEST, m_comRequest);
}
BEGIN_MESSAGE_MAP(CTabCheckRequest, CDialogEx)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_DATA, &CTabCheckRequest::OnLvnColumnclickListData)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_DATA, &CTabCheckRequest::OnLvnItemchangedListData)
	//ON_BN_CLICKED(IDC_BUTTON_ADD, &CTabCheckRequest::OnBnClickedButtonAdd)
	//	ON_WM_ACTIVATE()
	//ON_NOTIFY(HDN_ITEMSTATEICONCLICK, 0, &CTabCheckRequest::OnHdnItemStateIconClickListData2)
	ON_CBN_SELCHANGE(IDC_COMBO_VIEW, &CTabCheckRequest::OnCbnSelchangeComboView)
	ON_CBN_SELCHANGE(IDC_COMBO_REQUEST, &CTabCheckRequest::OnCbnSelchangeComboRequest)
	ON_BN_CLICKED(IDC_BUTTON_REQUEST, &CTabCheckRequest::OnBnClickedButtonRequest)
	ON_EN_CHANGE(IDC_EDIT_REQUEST, &CTabCheckRequest::OnEnChangeEditRequest)
	ON_WM_KEYDOWN()
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CTabCheckRequest::OnBnClickedButtonCancel)
	ON_WM_ACTIVATE()
	ON_WM_PAINT()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_DATA2, &CTabCheckRequest::OnLvnItemchangedListData2)
	ON_NOTIFY(NM_CLICK, IDC_LIST_DATA2, &CTabCheckRequest::OnNMClickListData2)
END_MESSAGE_MAP()

void CTabCheckRequest::UpdateList()
{

	m_ListCtrl.DeleteAllItems();

	CDatabase db;
	db.OpenEx(L"DSN=enclosure");
	CRecordset rs(&db);
	CRect rect;
	m_ListCtrl.GetClientRect(&rect);
	short width[] = { 50, 80, 80, 80, 150, 300, 150, 100, };
	int align[] = { LVCFMT_CENTER, LVCFMT_CENTER, LVCFMT_CENTER, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_CENTER, LVCFMT_LEFT, LVCFMT_CENTER };
	LPCTSTR name[] = { _T("구분"), _T("장비번호"), _T("모델명"), _T("종류"), _T("요청일"), _T("요청사항"), _T("요청/점검여부"), _T("점검일") };
	
	if (!m_bCheckList) {
		for (int i = 0; i <= 7; i++)
			m_ListCtrl.InsertColumn(i + 1, name[i], align[i], width[i]);
		m_bCheckList = TRUE;
	}

	rs.m_pDatabase = &db;
	rs.Open(NULL, L"SELECT * FROM EnclosureCheckRequestTable;");
	CString itemStr;
	CString intToCStr;
	int m = 6;
	int idx = 0;
	while (!rs.IsEOF()) {
		intToCStr.Format(_T("%d"), idx);
		m_ListCtrl.InsertItem(idx, intToCStr);
		for (int j = 0; j <=7; j++) {
			rs.GetFieldValue((short)j, itemStr);
			if (j == 2 && !m_typeCheck) {						//점검요청 내역 리스트 업데이트 할 때 장비의 모델명을 typeArray배열에 push
				for (int i = 0; i < 200; i++) {
					if (typeArray[i] == itemStr) {
						break;
					}
					else if (i == 199) {
						typeArray[ArrayCnt++] = itemStr;
					}
				}
			}
			if (j == 6 && itemStr == "1") { // DB의 자료에서 점검상태여부에 따라 반환값을 O,X 형태로 변환
				itemStr.Format(_T("O"));
				CTeamProjectSet::idxArray[CTeamProjectSet::idxArryIndex++] = idx+1;
			}
			else if(j == 6 && itemStr == "0"){
				itemStr.Format(_T("X"));
			}
			m_ListCtrl.SetItemText(idx, j, itemStr);
		}
		idx++;
		rs.MoveNext();
	}
	m_typeCheck =TRUE;
	rs.Close();
	db.Close();
	CountType();
}


BOOL CTabCheckRequest::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	UpdateList();
	InsertCheckHeader();

	return TRUE; 
}


//void CTabCheckRequest::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
//{
//	CDialogEx::OnActivate(nState, pWndOther, bMinimized);
//
//	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
//}


void CTabCheckRequest::OnHdnItemStateIconClickListData2(NMHDR *pNMHDR, LRESULT *pResult)
{
	/*LPNMHEADER pNMHEADER = (LPNMHEADER)pNMHDR;



	if (pNMHEADER->pitem->mask & HDI_FORMAT && pNMHEADER->pitem->fmt & HDF_CHECKBOX) {

		CheckAllItems(!(pNMHEADER->pitem->fmt & HDF_CHECKED));

		SetHeaderCheckbox();

	}

	*pResult = 0;*/
}
/*
void CTabCheckRequest::CheckAllItems(BOOL fChecked)

{
	for (int nItem = 0; nItem < ListView_GetItemCount(m_ListCtrl); nItem++) {

		// 항목의 체크상태 변경

		ListView_SetCheckState(m_ListCtrl, nItem, fChecked);


		// 추가작업...


	}

}



void CTabCheckRequest::SetHeaderCheckbox(void)

{

	BOOL fChecked = TRUE;
	
	for (int nItem = 0; nItem < ListView_GetItemCount(m_ListCtrl); nItem++) {

		if (!ListView_GetCheckState(m_ListCtrl, nItem)) {
			fChecked = FALSE;
			break;
		}
	}

	HWND header = ListView_GetHeader(m_ListCtrl);
	HDITEM hdi = { 0 };
	hdi.mask = HDI_FORMAT;
	Header_GetItem(header, 0, &hdi);
	if (fChecked) {
		hdi.fmt |= HDF_CHECKED;
	}
	else {
		hdi.fmt &= ~HDF_CHECKED;
	}
	Header_SetItem(header, 0, &hdi);

}
*/
void CTabCheckRequest::OnCbnSelchangeComboView()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int numSel = ((CComboBox*)GetDlgItem(IDC_COMBO_VIEW))->GetCurSel();
	((CComboBox*)GetDlgItem(IDC_COMBO_VIEW))->SetCurSel(1);
	long setStyle;

	setStyle = GetWindowLong(m_ListCtrl.m_hWnd, GWL_STYLE);
	setStyle &= LVS_TYPEMASK;
	switch (numSel)
	{
	case 0:
		setStyle |= LVS_REPORT;
		break;
	case 1:
		setStyle |= LVS_LIST;
		break;
	case 2:
		setStyle |= LVS_SMALLICON;
		break;
	case 3:
		setStyle |= LVS_ICON;
		break;
	}
	SetWindowLong(m_ListCtrl.m_hWnd, GWL_STYLE, setStyle);

}

void CTabCheckRequest::OnLvnColumnclickListData(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	NM_LISTVIEW*pNMListView = (NM_LISTVIEW*)pNMHDR;

	if ((pNMListView->uChanged & LVIF_STATE) &&
		(pNMListView->uNewState & LVIS_SELECTED))
	{
		CString ItemData;
		m_nSelected = pNMListView->iItem;
		ItemData = m_ListCtrl.GetItemText(m_nSelected, 0);
		m_RequestIndex = _ttoi(ItemData);
		ItemData = m_ListCtrl.GetItemText(m_nSelected, 1);
		m_EnclosureIndex = _ttoi(ItemData);
		m_EquipModelName = m_ListCtrl.GetItemText(m_nSelected, 2);
		m_CheckType = m_ListCtrl.GetItemText(m_nSelected, 3);
		m_RequestDate = m_ListCtrl.GetItemText(m_nSelected, 4);
		m_RequestDescription = m_ListCtrl.GetItemText(m_nSelected, 5);
		m_Checked = m_ListCtrl.GetItemData(6);
		m_CheckedDate = m_ListCtrl.GetItemText(m_nSelected, 7);
		m_strRequest.Format(m_EquipModelName);
		GetDlgItem(IDC_EDIT_REQUEST)->SetWindowText(m_strRequest);
		UpdateData(false);
	}
	*pResult = true;
}
void CTabCheckRequest::OnLvnItemchangedListData(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(FALSE);
	for (int j = 0; j <= m_comRequest.GetCount(); j++) {
		m_comRequest.DeleteString(0);
	}

	*pResult = 0;
	NM_LISTVIEW*pNMListView = (NM_LISTVIEW*)pNMHDR;
	int nCount = m_ListCtrl.GetItemCount();
	for (int i = 0; i<nCount; i = i++)
	{
		BOOL a = m_ListCtrl.GetCheck(i);
		/*if (a == TRUE)
		{
		CString temp = m_ListCtrl.GetItemText(i, 0);
		temp.Format(_T("%s 번째 리스트가 선택됨"), temp);
		AfxMessageBox(temp);
		}*/

	}

	for (int i = 0; i < nCount; i++) {
		if (m_ListCtrl.GetCheck(i))
			Check[i] = m_ListCtrl.GetItemText(i, 0);
		else
			Check[i] = "";
	}
	for (int i = 0; i <m_ListCtrl.GetItemCount(); i++) {
		if (!Check[i].IsEmpty()) {
			InputCombo(Check[i]);
			getComIdx = i;
		}
	}
	if ((pNMListView->uChanged & LVIF_STATE) &&
		(pNMListView->uNewState & LVIS_SELECTED))
	{
		CString ItemData;
		m_nSelected = pNMListView->iItem;
		ItemData = m_ListCtrl.GetItemText(m_nSelected, 0);
		m_RequestIndex = _ttoi(ItemData);
		ItemData = m_ListCtrl.GetItemText(m_nSelected, 1);
		m_EnclosureIndex = _ttoi(ItemData);
		m_EquipModelName = m_ListCtrl.GetItemText(m_nSelected, 2);
		m_CheckType = m_ListCtrl.GetItemText(m_nSelected, 3);
		m_RequestDate = m_ListCtrl.GetItemText(m_nSelected, 4);
		m_RequestDescription = m_ListCtrl.GetItemText(m_nSelected, 5);
		ItemData = m_ListCtrl.GetItemText(m_nSelected, 6);
		m_Checked = _ttoi(ItemData);
		m_CheckedDate = m_ListCtrl.GetItemText(m_nSelected, 7);
		UpdateData(false);
	}

	*pResult = true;
}



void CTabCheckRequest::InputCombo(CString str)
{
	UpdateData(TRUE);
	m_comRequest.AddString(str);
	UpdateData(FALSE);
}


void CTabCheckRequest::OnCbnSelchangeComboRequest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	cnt = 0;
	//for (int i = 0; i < m_ListCtrl.GetItemCount(); i++) {
		//if (m_ListCtrl.GetCheck(i));
			//getComIdx = i;
	//}
	cnt = m_comRequest.GetCurSel();
	UpdateData(FALSE);
}


void CTabCheckRequest::OnBnClickedButtonRequest()
{// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_ListCtrl.SetItemText(getComIdx, 5, m_RequestDescription);
	m_bChecked = m_ListCtrl.GetItemData(getComIdx + 1);
	UpdateData(FALSE);
	if (!m_bChecked) {
		m_bChecked = TRUE;
	}
	m_strRequest.Format(_T(""));
	CDatabase db;
	db.OpenEx(L"DSN=enclosure");
	CRecordset rs(&db);

	rs.m_pDatabase = &db;
	CString command, command2;
	command.Format(_T("UPDATE EnclosureCheckRequestTable SET RequestDescription='%s' WHERE RequestIndex=%d"), m_RequestDescription, getComIdx + 1);
	command2.Format(_T("UPDATE EnclosureCheckRequestTable SET Checked=%d WHERE RequestIndex=%d"), m_bChecked, getComIdx + 1);
	db.ExecuteSQL(command);
	db.ExecuteSQL(command2);
	rs.Close();
	db.Close();
	UpdateList();

}


void CTabCheckRequest::OnEnChangeEditRequest()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_RequestDescription.Format(m_strRequest);
	UpdateData(FALSE);
}


void CTabCheckRequest::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
	UpdateData(TRUE);
	m_strRequest.AppendChar(nChar);
	UpdateData(FALSE);
}


void CTabCheckRequest::InsertCheckHeader()
{
	m_ListCtrl.SetExtendedStyle(m_ListCtrl.GetExtendedStyle() // 리스트의 헤더에 체크박스 기능 추가코드

		| LVS_EX_FULLROWSELECT

		| LVS_EX_GRIDLINES

		| LVS_EX_DOUBLEBUFFER

		| LVS_EX_CHECKBOXES

		| LVS_EX_SUBITEMIMAGES);
	HWND header = ListView_GetHeader(m_ListCtrl);

	DWORD dwHeaderStyle = ::GetWindowLong(header, GWL_STYLE);

	dwHeaderStyle |= HDS_CHECKBOXES;

	::SetWindowLong(header, GWL_STYLE, dwHeaderStyle);

	HDITEM hdi = { 0 };

	hdi.mask = HDI_FORMAT;

	Header_GetItem(header, 0, &hdi);

	hdi.fmt |= HDF_CHECKBOX | HDF_FIXEDWIDTH;

	Header_SetItem(header, 0, &hdi);
}


void CTabCheckRequest::OnBnClickedButtonCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	//m_ListCtrl.SetItemText(getComIdx, 5, m_RequestDescription);
	m_bChecked = m_ListCtrl.GetItemData(getComIdx + 1);
	UpdateData(FALSE);
	if (m_bChecked) {
		m_bChecked = FALSE;
	}
	AfxMessageBox(_T("요청 취소 되었습니다."));
	m_strRequest.Format(_T(""));
	CDatabase db;
	db.OpenEx(L"DSN=enclosure");
	CRecordset rs(&db);

	rs.m_pDatabase = &db;
	CString command, command2;
	command.Format(_T("UPDATE EnclosureCheckRequestTable SET RequestDescription='%s' WHERE RequestIndex=%d"), "", getComIdx + 1);
	command2.Format(_T("UPDATE EnclosureCheckRequestTable SET Checked=%d WHERE RequestIndex=%d"), m_bChecked, getComIdx + 1);
	db.ExecuteSQL(command);
	db.ExecuteSQL(command2);
	rs.Close();
	db.Close();
	UpdateList();

}


void CTabCheckRequest::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CDialogEx::OnActivate(nState, pWndOther, bMinimized);
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CTabCheckRequest::CountType() // 요청된 장비의 종류별 요청건수 구하는 함수 << 차트의 데이터에 필요
{
	CDatabase db;
	db.OpenEx(L"DSN=enclosure");
	CRecordset rs(&db);
	CRect rect;
	rs.m_pDatabase = &db;
	rs.Open(NULL, L"SELECT * FROM EnclosureCheckRequestTable;");
	CString itemStr;
	CString CheckStr;
	int j = 2;
	int m = 6;
	while (!rs.IsEOF()) {
			rs.GetFieldValue((short)m, itemStr);
			CheckStr = itemStr;
			rs.GetFieldValue((short)j, itemStr);
			if (j == 2 && CheckStr=="1") {			
				for (int i = 0; i < ArrayCnt; i++) {
					if (typeArray[i] == itemStr) {
						typeCount[i] += 1;
						break;
					}
				}
			}
			
		
		rs.MoveNext();
	}
	rs.Close();
	db.Close();
}


void CTabCheckRequest::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	UpdateList();
}


void CTabCheckRequest::OnLvnItemchangedListData2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CTabCheckRequest::OnNMClickListData2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	int idx = pNMListView -> iItem;
	*pResult = 0;
}


BOOL CTabCheckRequest::PreTranslateMessage(MSG* pMsg)
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
