#pragma once

// CBaseInfoDoc �����Դϴ�.

class CBaseInfoDoc : public CDocument
{
	DECLARE_DYNCREATE(CBaseInfoDoc)

public:
	CBaseInfoDoc();
	virtual ~CBaseInfoDoc();
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
