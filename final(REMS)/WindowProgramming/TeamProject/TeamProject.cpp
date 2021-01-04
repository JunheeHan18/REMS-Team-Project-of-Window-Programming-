
// TeamProject.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "TeamProject.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "TeamProjectSet.h"
#include "TeamProjectDoc.h"
#include "TeamProjectView.h"

// EquipStatus ���� �߰�
#include "EquipStatusDoc.h"
#include "EquipStatusFrm.h"
#include "EquipStatusView.h"

// BaseInfo ���� �߰�
#include "BaseInfoDoc.h"
#include "BaseInfoFrm.h"
#include "BaseInfoView.h"

// InfoManage ���� �߰�
#include "InfoManageDoc.h"
#include "InfoManageFrm.h"
#include "InfoManageView.h"

//Check ���� �߰�
#include "CheckDoc.h"
#include "CheckFrm.h"
#include "CheckView2.h"

// Logo ���� �߰�
#include "LoadingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTeamProjectApp

BEGIN_MESSAGE_MAP(CTeamProjectApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CTeamProjectApp::OnAppAbout)
	// ǥ�� ������ ���ʷ� �ϴ� ���� ����Դϴ�.
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// ǥ�� �μ� ���� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// CTeamProjectApp ����

CTeamProjectApp::CTeamProjectApp()
: m_pDocTemplate(NULL)
, m_pBaseInfoTemplate(NULL)
, m_pInfoManageTemplate(NULL)
, m_pCheckTemplate(NULL)
{
	m_bHiColorIcons = TRUE;

	// �ٽ� ���� ������ ����
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// ���� ���α׷��� ���� ��� ��Ÿ�� ������ ����Ͽ� ������ ���(/clr):
	//     1) �� �߰� ������ �ٽ� ���� ������ ������ ����� �۵��ϴ� �� �ʿ��մϴ�.
	//     2) ������Ʈ���� �����Ϸ��� System.Windows.Forms�� ���� ������ �߰��ؾ� �մϴ�.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: �Ʒ� ���� ���α׷� ID ���ڿ��� ���� ID ���ڿ��� �ٲٽʽÿ�(����).
	// ���ڿ��� ���� ����: CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("TeamProject.AppID.NoVersion"));

	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}

// ������ CTeamProjectApp ��ü�Դϴ�.

CTeamProjectApp theApp;


// CTeamProjectApp �ʱ�ȭ

BOOL CTeamProjectApp::InitInstance()
{	
	CLoadingDlg dlg;
	dlg.DoModal();

	if (!AfxSocketInit()) {
		AfxMessageBox(L"����");
		return FALSE;
	}

	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControlsEx()�� �ʿ��մϴ�. 
	// InitCommonControlsEx()�� ������� ������ â�� ���� �� �����ϴ�.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ���� ���α׷����� ����� ��� ���� ��Ʈ�� Ŭ������ �����ϵ���
	// �� �׸��� �����Ͻʽÿ�.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// OLE ���̺귯���� �ʱ�ȭ�մϴ�.
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction();

	// RichEdit ��Ʈ���� ����Ϸ���  AfxInitRichEdit2()�� �־�� �մϴ�.	
	// AfxInitRichEdit2();

	// ǥ�� �ʱ�ȭ
	// �̵� ����� ������� �ʰ� ���� ���� ������ ũ�⸦ ���̷���
	// �Ʒ����� �ʿ� ���� Ư�� �ʱ�ȭ
	// ��ƾ�� �����ؾ� �մϴ�.
	// �ش� ������ ����� ������Ʈ�� Ű�� �����Ͻʽÿ�.
	// TODO: �� ���ڿ��� ȸ�� �Ǵ� ������ �̸��� ����
	// ������ �������� �����ؾ� �մϴ�.
	SetRegistryKey(_T("���� ���� ���α׷� �����翡�� ������ ���� ���α׷�"));
	LoadStdProfileSettings(4);  // MRU�� �����Ͽ� ǥ�� INI ���� �ɼ��� �ε��մϴ�.


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// ���� ���α׷��� ���� ���ø��� ����մϴ�.  ���� ���ø���
	//  ����, ������ â �� �� ������ ���� ������ �մϴ�.
	/*CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_TeamProjectTYPE,
		RUNTIME_CLASS(CTeamProjectDoc),
		RUNTIME_CLASS(CChildFrame), // ����� ���� MDI �ڽ� �������Դϴ�.
		RUNTIME_CLASS(CTeamProjectView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);*/

	// 1: IDR_XXXTYPE : ���ҽ� ID
	// 2: ���ϵ� �������� ��ť��Ʈ Ŭ����
	// 3: ���ϵ� �������� ������ Ŭ����
	// 4: ���ϵ� �������� �� Ŭ����
	
	/*
	m_pDocTemplate = new CMultiDocTemplate(IDR_TeamProjectTYPE,
		RUNTIME_CLASS(CTeamProjectDoc),
		RUNTIME_CLASS(CChildFrame),
		RUNTIME_CLASS(CTeamProjectView));
	if (!m_pDocTemplate)
		return FALSE;
	AddDocTemplate(m_pDocTemplate);
	*/

	m_pDocTemplate = new CMultiDocTemplate(IDR_TeamProjectTYPE,
		RUNTIME_CLASS(CEquipStatusDoc),
		RUNTIME_CLASS(CEquipStatusFrm),
		RUNTIME_CLASS(CEquipStatusView));
	if (!m_pDocTemplate)
		return FALSE;
	AddDocTemplate(m_pDocTemplate);

	m_pBaseInfoTemplate = new CMultiDocTemplate(IDR_TeamProjectTYPE,
		RUNTIME_CLASS(CBaseInfoDoc),
		RUNTIME_CLASS(CBaseInfoFrm),
		RUNTIME_CLASS(CBaseInfoView));
	if (!m_pBaseInfoTemplate)
		return FALSE;
	AddDocTemplate(m_pBaseInfoTemplate);

	m_pInfoManageTemplate = new CMultiDocTemplate(IDR_TeamProjectTYPE,
		RUNTIME_CLASS(CInfoManageDoc),
		RUNTIME_CLASS(CInfoManageFrm),
		RUNTIME_CLASS(CInfoManageView));
	if (!m_pInfoManageTemplate)
		return FALSE;
	AddDocTemplate(m_pInfoManageTemplate);

	m_pCheckTemplate = new CMultiDocTemplate(IDR_TeamProjectTYPE,
		RUNTIME_CLASS(CCheckDoc),
		RUNTIME_CLASS(CCheckFrm),
		RUNTIME_CLASS(CCheckView2));
	if (!m_pCheckTemplate)
		return FALSE;
	AddDocTemplate(m_pCheckTemplate);

	// �� MDI ������ â�� ����ϴ�.
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;

	

	// ǥ�� �� ���, DDE, ���� ���⿡ ���� ������� ���� �м��մϴ�.
	//CCommandLineInfo cmdInfo;
	//ParseCommandLine(cmdInfo);



	// ����ٿ� ������ ����� ����ġ�մϴ�.
	// ���� ���α׷��� /RegServer, /Register, /Unregserver �Ǵ� /Unregister�� ���۵� ��� FALSE�� ��ȯ�մϴ�.
	
	//if (!ProcessShellCommand(cmdInfo))
	//	return FALSE;

	// �� â�� �ʱ�ȭ�Ǿ����Ƿ� �̸� ǥ���ϰ� ������Ʈ�մϴ�.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	CWinApp* pApp = AfxGetApp();
	POSITION pos = pApp->GetFirstDocTemplatePosition();
	while (pos != NULL) {
		CDocTemplate* pDoc = pApp->GetNextDocTemplate(pos);
		pDoc->OpenDocumentFile(NULL);
	}

	return TRUE;
}

int CTeamProjectApp::ExitInstance()
{
	//TODO: �߰��� �߰� ���ҽ��� ó���մϴ�.
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CTeamProjectApp �޽��� ó����


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
public:
	afx_msg void OnBnClickedButtonDelete();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CAboutDlg::OnBnClickedButtonDelete)
END_MESSAGE_MAP()

// ��ȭ ���ڸ� �����ϱ� ���� ���� ���α׷� ����Դϴ�.
void CTeamProjectApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CTeamProjectApp ����� ���� �ε�/���� �޼���

void CTeamProjectApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void CTeamProjectApp::LoadCustomState()
{
}

void CTeamProjectApp::SaveCustomState()
{
}

// CTeamProjectApp �޽��� ó����

void CAboutDlg::OnBnClickedButtonDelete()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

}
