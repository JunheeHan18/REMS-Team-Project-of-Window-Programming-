#pragma once
#include "explorer_map.h"
#include "resource.h"


// CMapDialog ��ȭ �����Դϴ�.

class CMapDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMapDialog)

public:
	CMapDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMapDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_MAP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CExplorer_map m_Explorer_Map;
	virtual BOOL OnInitDialog();
};
