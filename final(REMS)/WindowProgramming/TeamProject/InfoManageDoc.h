#pragma once

// CInfoManageDoc �����Դϴ�.

class CInfoManageDoc : public CDocument
{
	DECLARE_DYNCREATE(CInfoManageDoc)

public:
	CInfoManageDoc();
	virtual ~CInfoManageDoc();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // ���� ��/����� ���� �����ǵǾ����ϴ�.
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual BOOL OnNewDocument();
	DECLARE_MESSAGE_MAP()
};
