
// TeamProjectView.h : CTeamProjectView Ŭ������ �������̽�
//

#pragma once

class CTeamProjectSet;

class CTeamProjectView : public CRecordView
{
protected: // serialization������ ��������ϴ�.
	CTeamProjectView();
	DECLARE_DYNCREATE(CTeamProjectView)

public:
	enum{ IDD = IDD_TEAMPROJECT_FORM };
	CTeamProjectSet* m_pSet;

// Ư���Դϴ�.
public:
	CTeamProjectDoc* GetDocument() const;

// �۾��Դϴ�.
public:
	void MainMessage();

// �������Դϴ�.
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CTeamProjectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CTeamProjectSet* GetRdSet();
	CTeamProjectSet* m_RdSet;
};

#ifndef _DEBUG  // TeamProjectView.cpp�� ����� ����
inline CTeamProjectDoc* CTeamProjectView::GetDocument() const
   { return reinterpret_cast<CTeamProjectDoc*>(m_pDocument); }
#endif

