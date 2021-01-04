#pragma once

class EnclBaseDialog : public CDialogEx
{
	DECLARE_DYNAMIC(EnclBaseDialog)

public:
	EnclBaseDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~EnclBaseDialog();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ENCLBASE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

private:
	void RefreshEnclBaseList();
	void RefreshEquipChangeHistoryList(const CString& enclosureIndexString);
	void RefreshComboBox();
	void RefreshBaseEquipComboBoxAsType(CDatabase& db, const CString& type);
	void RefreshBaseEquipComboBoxAsModelName(CDatabase& db, const CString& currentModelName);

	void ClearInputField();

	void SetHistoryToListCtrl(CRecordset* set);
	void SetEnclBaseToListCtrl(CRecordset *set);

	int FindEnclBaseInList(const CString& findEnclIndexString, const CString& findModelNameString);

public:
	BOOL			isSelectionMode;

	void SetSelectionMode(BOOL selectionMode);

public:
	void InsertHistoryAsInsert(CDatabase& db, const CString& installLocation, const CString& equipModelName);
	void InsertHistoryAsDelete(CDatabase& db, const CString& installLocation, const CString& equipModelName);
	void InsertHistoryAsUpdate(CDatabase& db, const CString& installLocation, const CString& prevEquipModelName, const CString& nextEquipModelName);

public:
	int				enclBaseSelectIndex;
	CString			selectedEnclosureIndex;
	CString			selectedInstallLocation;
	CString			selectedEquipModelName;

public:
	CListCtrl		enclBaseListCtrl;
	CListCtrl		equipChangeHistoryListCtrl;

	CComboBox		enclosureComboBox;
	CComboBox		baseEquipComboBox;

	CButton			searchButton;
	CButton			saveButton;
	CButton			modifyButton;
	CButton			cancelButton;
	CButton			copyButton;

	CStatic			selectionWarningStatic;

public:
	virtual BOOL OnInitDialog();
	virtual BOOL DestroyWindow();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnLvnItemActivateEnbaListctrlEnclbase(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeEnbaComboEnclosure();
	afx_msg void OnCbnSelchangeEbbaComboBaseEquip();
	afx_msg void OnBnClickedEnbaButtonSearch();
	afx_msg void OnBnClickedEnbaButtonCopy();
	afx_msg void OnBnClickedEnbaButtonSave();
	afx_msg void OnBnClickedEnbaButtonModify();
	afx_msg void OnBnClickedEnbaButtonCancel();
	afx_msg void OnNMClickEnbaListctrlEnclbase(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
