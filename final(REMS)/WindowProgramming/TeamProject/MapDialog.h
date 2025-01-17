#pragma once
#include "explorer_map.h"
#include "resource.h"


// CMapDialog 대화 상자입니다.

class CMapDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMapDialog)

public:
	CMapDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMapDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_MAP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CExplorer_map m_Explorer_Map;
	virtual BOOL OnInitDialog();
};
