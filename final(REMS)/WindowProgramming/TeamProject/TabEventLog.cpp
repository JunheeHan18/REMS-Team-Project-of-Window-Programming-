// TabEventLog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "TabEventLog.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "UDPServer.h"
#include  <time.h.>

// CTabEventLog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTabEventLog, CDialogEx)

CTabEventLog::CTabEventLog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTabEventLog::IDD, pParent)
	, m_GroupName1(_T(""))
	, m_GroupName2(_T(""))
	, m_EnclosureLocate(_T(""))
	, m_Event(_T(""))
	, m_EventInfo(_T(""))
	, m_OccurDate(_T(""))
	, m_Date1(_T(""))
	, m_Date2(_T(""))
	, m_pThis(NULL)
	, m_ColumnFlag(0)
{
	m_pThis = (CTabEventLog*)this;
}

CTabEventLog::~CTabEventLog()
{
}

void CTabEventLog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_EVENTLIST, m_ListCtrl);
	DDX_Text(pDX, IDC_LOCATENAME, m_EnclosureLocate);
	DDX_Text(pDX, IDC_INOUTNAME, m_InOutName);
	DDX_Text(pDX, IDC_EVENTCONTEXT, m_Event);
	DDX_Text(pDX, IDC_OCCURDATE, m_EventInfo);
}


BEGIN_MESSAGE_MAP(CTabEventLog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTabEventLog::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_TAB_BASEINFOVIEW, &CTabEventLog::OnLbnSelchangeList2)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_EVENTLIST, &CTabEventLog::OnLvnItemchangedEventlist)
END_MESSAGE_MAP()


// CTabEventLog �޽��� ó�����Դϴ�.


void CTabEventLog::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	
}


void CTabEventLog::OnLbnSelchangeList2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CTabEventLog::OnLvnItemchangedEventlist(NMHDR *pNMHDR, LRESULT *pResult)
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
		m_GroupName1 = m_ListCtrl.GetItemText(m_nSelected, 1);
		m_GroupName2 = m_ListCtrl.GetItemText(m_nSelected, 2);
		m_EnclosureLocate = m_ListCtrl.GetItemText(m_nSelected, 3);
		m_InOutName = m_ListCtrl.GetItemText(m_nSelected, 4);
		m_Event = m_ListCtrl.GetItemText(m_nSelected, 5);
		m_EventInfo = m_ListCtrl.GetItemText(m_nSelected, 6);
		m_OccurDate = m_ListCtrl.GetItemText(m_nSelected, 7);
		UpdateData(false);

	}
}

void CTabEventLog::UpdateList() {
	m_ListCtrl.DeleteAllItems();
	CDatabase db;
	db.OpenEx(L"DSN=enclosure");
	CRecordset rs(&db);
	CRect rect;
	m_ListCtrl.GetClientRect(rect);
	short width[] = {70, 70, 80, 90, 70, 220, 180};
	int align[] = { LVCFMT_CENTER, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT  };
	LPCTSTR name[] = {_T("��ȣ"), _T("�׷��1"), _T("�׷��2"), _T("��ü��ġ��"), _T("�̺�Ʈ"), _T("�̺�Ʈ����"),_T("�߻��Ͻ�") };

	if (m_ColumnFlag == 0) {
		for (int i = 0; i <= 6; i++) {
			m_ListCtrl.InsertColumn(i + 1, name[i], align[i], width[i]);
		}
		m_ColumnFlag = !m_ColumnFlag;
	}
	rs.m_pDatabase = &db;
	rs.Open(NULL, L"SELECT * FROM EnclosureEventLogTable;");
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

BOOL CTabEventLog::OnInitDialog() {
	CDialogEx::OnInitDialog();

	UpdateList();
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_Server = new CUDPServer();
	m_Server->Create(5000, SOCK_DGRAM);
	m_Server->GetDialog(m_pThis);

	return TRUE;
}



void CTabEventLog::ReceiveUpdate(CString ReceiveBuf)
{
	int pos = 0;
	CString GroupName1 = ReceiveBuf.Tokenize(L"*", pos);
	CString GroupName2 = ReceiveBuf.Tokenize(L"*", pos);
	CString BaseLoc = ReceiveBuf.Tokenize(L"*", pos);
	CString Event = ReceiveBuf.Tokenize(L"*", pos);
	CString EventLog = ReceiveBuf.Tokenize(L"*", pos);
	CTime cTime = CTime::GetCurrentTime();
	CString strDate;

	strDate.Format(_T("%04d-%02d-%02d %02d:%02d:%02d"), cTime.GetYear(), 
		cTime.GetMonth(), // ���� �� ��ȯ
		cTime.GetDay(),
		cTime.GetHour(),
		cTime.GetMinute(),
		cTime.GetSecond()
	); // ���� �� ��ȯ

	CDatabase db;
	db.OpenEx(L"DSN=enclosure");
	CRecordset rs(&db);
	
	rs.m_pDatabase = &db;
	CString command;
	command.Format(_T("insert into EnclosureEventLogTable(�׷��1, �׷��2, ��ü��ġ��, �̺�Ʈ, �̺�Ʈ����, �߻��Ͻ�) values ('%s','%s','%s','%s','%s', '%s');")
		, GroupName1, GroupName2, BaseLoc, Event, EventLog, strDate );
	db.ExecuteSQL(command);
	rs.Close();
	db.Close();

	UpdateList();
}
