// TabRegBase.cpp : ���� �����Դϴ�.
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

// CTabRegBase ��ȭ �����Դϴ�.

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
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

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
	LPCTSTR name[] = { _T("����"), _T("����ȣ"), _T("�𵨸�"), _T("����"), _T("��û��"), _T("��û����"), _T("��û/���˿���"), _T("������") };
	
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
			if (j == 2 && !m_typeCheck) {						//���˿�û ���� ����Ʈ ������Ʈ �� �� ����� �𵨸��� typeArray�迭�� push
				for (int i = 0; i < 200; i++) {
					if (typeArray[i] == itemStr) {
						break;
					}
					else if (i == 199) {
						typeArray[ArrayCnt++] = itemStr;
					}
				}
			}
			if (j == 6 && itemStr == "1") { // DB�� �ڷῡ�� ���˻��¿��ο� ���� ��ȯ���� O,X ���·� ��ȯ
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
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
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

		// �׸��� üũ���� ����

		ListView_SetCheckState(m_ListCtrl, nItem, fChecked);


		// �߰��۾�...


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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
		temp.Format(_T("%s ��° ����Ʈ�� ���õ�"), temp);
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
{// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_RequestDescription.Format(m_strRequest);
	UpdateData(FALSE);
}


void CTabCheckRequest::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
	UpdateData(TRUE);
	m_strRequest.AppendChar(nChar);
	UpdateData(FALSE);
}


void CTabCheckRequest::InsertCheckHeader()
{
	m_ListCtrl.SetExtendedStyle(m_ListCtrl.GetExtendedStyle() // ����Ʈ�� ����� üũ�ڽ� ��� �߰��ڵ�

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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	//m_ListCtrl.SetItemText(getComIdx, 5, m_RequestDescription);
	m_bChecked = m_ListCtrl.GetItemData(getComIdx + 1);
	UpdateData(FALSE);
	if (m_bChecked) {
		m_bChecked = FALSE;
	}
	AfxMessageBox(_T("��û ��� �Ǿ����ϴ�."));
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
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CTabCheckRequest::CountType() // ��û�� ����� ������ ��û�Ǽ� ���ϴ� �Լ� << ��Ʈ�� �����Ϳ� �ʿ�
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
					   // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
					   // �׸��� �޽����� ���ؼ��� CDialogEx::OnPaint()��(��) ȣ������ ���ʽÿ�.
	UpdateList();
}


void CTabCheckRequest::OnLvnItemchangedListData2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}


void CTabCheckRequest::OnNMClickListData2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
