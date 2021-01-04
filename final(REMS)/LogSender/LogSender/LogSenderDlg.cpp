
// LogSenderDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "LogSender.h"
#include "LogSenderDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 쓰레드를 위한 정보
#include <Windows.h>
#include <process.h>
int m_SendFlagGlobal;

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CLogSenderDlg 대화 상자



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


// CLogSenderDlg 메시지 처리기

BOOL CLogSenderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CLogSenderDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

	CWnd* pB = GetDlgItem(IDC_BUTTON_SEND);
	if (m_SendFlag == 1) {
		pB->SetWindowText(L"종료");
	}
	else {
		pB->SetWindowTextW(L"로그 OFF");
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CLogSenderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLogSenderDlg::OnBnClickedButtonSend()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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