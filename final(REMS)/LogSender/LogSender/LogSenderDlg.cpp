
// LogSenderDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "LogSender.h"
#include "LogSenderDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// �����带 ���� ����
#include <Windows.h>
#include <process.h>
int m_SendFlagGlobal;

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLogSenderDlg ��ȭ ����



CLogSenderDlg::CLogSenderDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLogSenderDlg::IDD, pParent)
	, m_Group1(_T(""))
	, m_Group2(_T(""))
	, m_BaseLoc(_T(""))
	, m_Event(_T(""))
	, m_EventLog(_T(""))
	, m_SendFlag(0)
	, m_pThread(NULL)
	, m_SocketFlag(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLogSenderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_GROUP1, m_Group1);
	DDX_Text(pDX, IDC_EDIT_GROUP2, m_Group2);
	DDX_Text(pDX, IDC_EDIT_BASELOC, m_BaseLoc);
	DDX_Text(pDX, IDC_EDIT_EVENT, m_Event);
	DDX_Text(pDX, IDC_EDIT_EVENTLOG, m_EventLog);
}

BEGIN_MESSAGE_MAP(CLogSenderDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CLogSenderDlg::OnBnClickedButtonSend)
END_MESSAGE_MAP()


// CLogSenderDlg �޽��� ó����

BOOL CLogSenderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CLogSenderDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CLogSenderDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

	CWnd* pB = GetDlgItem(IDC_BUTTON_SEND);
	if (m_SendFlag == 1) {
		pB->SetWindowText(L"����");
	}
	else {
		pB->SetWindowTextW(L"�α� OFF");
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CLogSenderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLogSenderDlg::OnBnClickedButtonSend()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_SendFlag = !m_SendFlag;

	if (m_SendFlag) {
		UpdateData(true);
		m_pThread = AfxBeginThread(ThreadSend, this);
		m_SocketFlag = 0;
		m_SendFlag = 1;
	}
	else {
		exit(1);
		DWORD dwResult;
		::GetExitCodeThread(m_pThread->m_hThread, &dwResult);
		delete m_pThread;
		m_pThread = NULL;
		m_SendFlag = 0;
	}

	Invalidate();
}

UINT CLogSenderDlg::ThreadSend(LPVOID arg) {
	CLogSenderDlg *dlg = NULL;
	dlg = (CLogSenderDlg*)AfxGetApp()->m_pMainWnd;
	TCHAR strBuffer[1024];
	::ZeroMemory(strBuffer, sizeof(strBuffer));

	for (;;) {
		if (!dlg->m_SendFlag) break;

		if (dlg->m_SocketFlag == 0) {
			wcscat(strBuffer, dlg->m_Group1);
			wcscat(strBuffer, L"*");
			wcscat(strBuffer, dlg->m_Group2);
			wcscat(strBuffer, L"*");
			wcscat(strBuffer, dlg->m_BaseLoc);
			wcscat(strBuffer, L"*");
			wcscat(strBuffer, dlg->m_Event);
			wcscat(strBuffer, L"*");
			wcscat(strBuffer, dlg->m_EventLog);
			dlg->m_Client.Create(5001, SOCK_DGRAM);
			dlg->m_SocketFlag = 1;
		}

		dlg->m_Client.SendTo((LPVOID)(LPCTSTR)strBuffer, sizeof(strBuffer), 5000, L"127.0.0.1");

		Sleep(10000);
	}

	return 0;
}