
// TeamProjectView.h : CTeamProjectView 클래스의 인터페이스
//

#pragma once

class CTeamProjectSet;

class CTeamProjectView : public CRecordView
{
protected: // serialization에서만 만들어집니다.
	CTeamProjectView();
	DECLARE_DYNCREATE(CTeamProjectView)

public:
	enum{ IDD = IDD_TEAMPROJECT_FORM };
	CTeamProjectSet* m_pSet;

// 특성입니다.
public:
	CTeamProjectDoc* GetDocument() const;

// 작업입니다.
public:
	void MainMessage();

// 재정의입니다.
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CTeamProjectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CTeamProjectSet* GetRdSet();
	CTeamProjectSet* m_RdSet;
};

#ifndef _DEBUG  // TeamProjectView.cpp의 디버그 버전
inline CTeamProjectDoc* CTeamProjectView::GetDocument() const
   { return reinterpret_cast<CTeamProjectDoc*>(m_pDocument); }
#endif

