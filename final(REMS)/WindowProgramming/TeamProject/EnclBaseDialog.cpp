// EnclBaseDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TeamProject.h"
#include "EnclBaseDialog.h"
#include "afxdialogex.h"
#include "EnclBaseResource.h"
#include "DBs_181127\DataManageDB.h"
#include <iostream>

#ifdef _DEBUG
//#pragma comment(linker,"/entry:wWinMainCRTStartup /subsystem:console")
#endif

void SetListCtrl(CListCtrl& ctrl, CRecordset* set, TCHAR* showAttrNames[], int showAttrWidth[], int showAttrAlign[])
{
	if (set->GetRecordCount() <= 0) return;

	if (ctrl.GetHeaderCtrl()->GetItemCount() <= 0)
		for (int i = 0; showAttrNames[i] != nullptr; i++)
			ctrl.InsertColumn(i + 1, showAttrNames[i], showAttrAlign[i], showAttrWidth[i]);

	set->MoveFirst();
	int recordIndex = 0;
	CString buffer;

	while (!set->IsEOF())
	{
		ctrl.InsertItem(recordIndex, _T(""));

		for (int i = 0; showAttrNames[i] != nullptr; i++)
		{
			set->GetFieldValue(showAttrNames[i], buffer);
			ctrl.SetItemText(recordIndex, i, buffer);
		}

		set->MoveNext();
		recordIndex++;
	}
}

IMPLEMENT_DYNAMIC(EnclBaseDialog, CDialogEx)

EnclBaseDialog::EnclBaseDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_ENCLBASE, pParent)
{

}

EnclBaseDialog::~EnclBaseDialog()
{
}

void EnclBaseDialog::RefreshEnclBaseList()
{
	CRecordset* enclAndBaseSet = DataManageDB::GetAllEquipmentAndEnclosure();
	SetEnclBaseToListCtrl(enclAndBaseSet);
	enclAndBaseSet->Close();
	delete enclAndBaseSet;
}

void EnclBaseDialog::RefreshEquipChangeHistoryList(const CString& enclosureIndexString)
{
	CRecordset* set = DataManageDB::GetChangeEquipHistory(enclosureIndexString);
	SetHistoryToListCtrl(set);
	set->Close();
	delete set;
}

void EnclBaseDialog::RefreshComboBox()
{
	CRecordset* encl = DataManageDB::GetAllEnclosures();
	encl->MoveFirst();
	enclosureComboBox.ResetContent();

	while (!encl->IsEOF())
	{
		CString buf;
		encl->GetFieldValue(_T("InstallLocation"), buf);
		enclosureComboBox.AddString(buf);
		encl->MoveNext();
	}

	CRecordset* base = DataManageDB::GetAllBaseEquipment();
	base->MoveFirst();
	baseEquipComboBox.ResetContent();

	while (!base->IsEOF())
	{
		CString buf;
		base->GetFieldValue(_T("ModelName"), buf);
		baseEquipComboBox.AddString(buf);
		base->MoveNext();
	}
}

void EnclBaseDialog::RefreshBaseEquipComboBoxAsType(CDatabase& db, const CString& type)
{
	CRecordset set(&db);
	
	try
	{
		CString query;
		query.Format(_T("SELECT ModelName FROM BaseEquipmentTable WHERE Type='%s'"), type);
		set.Open(CRecordset::dynaset, query);
	}
	catch (CDBException* e)
	{
	}
	

	set.MoveFirst();
	baseEquipComboBox.ResetContent();

	while (!set.IsEOF())
	{
		CString buf;
		set.GetFieldValue(_T("ModelName"), buf);
		baseEquipComboBox.AddString(buf);
		set.MoveNext();
	}
}

void EnclBaseDialog::RefreshBaseEquipComboBoxAsModelName(CDatabase & db, const CString & currentModelName)
{
	CRecordset set(&db);

	try
	{
		CString query;
		query.Format(_T("SELECT ModelName FROM BaseEquipmentTable WHERE Type in (SELECT Type FROM BaseEquipmentTable WHERE ModelName='%s')"), currentModelName);
		set.Open(CRecordset::dynaset, query);
	}
	catch (CDBException* e)
	{
	}


	set.MoveFirst();
	baseEquipComboBox.ResetContent();

	while (!set.IsEOF())
	{
		CString buf;
		set.GetFieldValue(_T("ModelName"), buf);
		baseEquipComboBox.AddString(buf);
		set.MoveNext();
	}
}

void EnclBaseDialog::ClearInputField()
{
	enclosureComboBox.SetCurSel(-1);
	baseEquipComboBox.SetCurSel(-1);
}

void EnclBaseDialog::SetHistoryToListCtrl(CRecordset * set)
{
	static TCHAR* showAttrNames[] = { _T("InstallLocation"), _T("PrevEquipModelName"), _T("ChangedEquipModelName"), _T("Description"), _T("ChangeDate"), nullptr };
	static int showAttrWidth[] = { 70, 150, 100, 100, 150 };
	static int showAttrAlign[] = { LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT };

	equipChangeHistoryListCtrl.DeleteAllItems();
	SetListCtrl(equipChangeHistoryListCtrl, set, showAttrNames, showAttrWidth, showAttrAlign);
}

void EnclBaseDialog::SetEnclBaseToListCtrl(CRecordset * set)
{
	static TCHAR* showAttrNames[] = { _T("Type"), _T("InstallLocation") , _T("ModelName"), nullptr };
	static int showAttrWidth[] = { 70, 250, 240 };
	static int showAttrAlign[] = { LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_LEFT };

	enclBaseListCtrl.DeleteAllItems();
	SetListCtrl(enclBaseListCtrl, set, showAttrNames, showAttrWidth, showAttrAlign);
}

int EnclBaseDialog::FindEnclBaseInList(const CString& findEnclIndexString, const CString& findModelNameString)
{
	int itemIndex = 0;
	CString indexString, modelNameString;

	CRecordset* enclAndBaseSet = DataManageDB::GetAllEquipmentAndEnclosure();
	enclAndBaseSet->MoveFirst();
	while (!enclAndBaseSet->IsEOF())
	{
		enclAndBaseSet->GetFieldValue(_T("EnclosureIndex"), indexString);
		enclAndBaseSet->GetFieldValue(_T("EquipModelName"), modelNameString);

		if (indexString.Compare(findEnclIndexString) == 0 && 
			modelNameString.Compare(findModelNameString) == 0)
			break;

		itemIndex++;
		enclAndBaseSet->MoveNext();
	}

	int returnValue = enclAndBaseSet->IsEOF() ? -1: itemIndex;

	enclAndBaseSet->Close();
	delete enclAndBaseSet;

	return returnValue;
}

void EnclBaseDialog::SetSelectionMode(BOOL selectionMode)
{
	isSelectionMode = selectionMode;

	searchButton.EnableWindow(!selectionMode);
	saveButton.EnableWindow(!selectionMode);
	modifyButton.EnableWindow(selectionMode);
	cancelButton.EnableWindow(selectionMode);
	//copyButton.EnableWindow(selectionMode);

	enclosureComboBox.EnableWindow(!selectionMode);
	selectionWarningStatic.ShowWindow(selectionMode);
}

void EnclBaseDialog::InsertHistoryAsInsert(CDatabase& db, const CString& installLocation, const CString& equipModelName)
{
	CString query;
	CString enclIndex, equipType;

	{
		query.Format(_T("SELECT Index FROM EnclosureInstallTable WHERE InstallLocation='%s'"), installLocation);
		CRecordset indexSet(&db);

		try
		{
			indexSet.Open(CRecordset::dynaset, query);
		}
		catch (CDBException *e)
		{
			TCHAR arr[256];
			e->GetErrorMessage(arr, 256);
			std::wcout << arr << std::endl;
		}

		indexSet.GetFieldValue(_T("Index"), enclIndex);
		indexSet.Close();
	}

	{
		query.Format(_T("SELECT Type FROM BaseEquipmentTable WHERE ModelName='%s'"), equipModelName);

		CRecordset modelNameSet(&db);

		try
		{
			modelNameSet.Open(CRecordset::dynaset, query);
		}
		catch (CDBException *e)
		{
			TCHAR arr[256];
			e->GetErrorMessage(arr, 256);
			std::wcout << arr << std::endl;
		}

		modelNameSet.GetFieldValue(_T("Type"), equipType);
		modelNameSet.Close();
	}


	query.Format(_T(
		"INSERT INTO EnclosureChangeEquipHistoryTable(EnclosureIndex, Type, PrevEquipModelName, ChangedEquipModelName, Description, ChangeDate) VALUES(%s, '%s', Null, '%s', '장비 추가', '%s')"), enclIndex, equipType, equipModelName, CTime::GetCurrentTime().Format("%Y-%m-%d"));
	try
	{
		db.ExecuteSQL(query);
	}
	catch (CDBException *e)
	{
		TCHAR arr[256];
		e->GetErrorMessage(arr, 256);
		std::wcout << arr << std::endl;
	}
}

void EnclBaseDialog::InsertHistoryAsDelete(CDatabase& db, const CString& installLocation, const CString& equipModelName)
{
	CString query;
	CString enclIndex, equipType;

	{
		query.Format(_T("SELECT Index FROM EnclosureInstallTable WHERE InstallLocation='%s'"), installLocation);
		CRecordset indexSet(&db);

		try
		{
			indexSet.Open(CRecordset::dynaset, query);
		}
		catch (CDBException *e)
		{
			TCHAR arr[256];
			e->GetErrorMessage(arr, 256);
			std::wcout << arr << std::endl;
		}

		indexSet.GetFieldValue(_T("Index"), enclIndex);
		indexSet.Close();
	}

	{
		query.Format(_T("SELECT Type FROM BaseEquipmentTable WHERE ModelName='%s'"), equipModelName);

		CRecordset modelNameSet(&db);

		try
		{
			modelNameSet.Open(CRecordset::dynaset, query);
		}
		catch (CDBException *e)
		{
			TCHAR arr[256];
			e->GetErrorMessage(arr, 256);
			std::wcout << arr << std::endl;
		}

		modelNameSet.GetFieldValue(_T("Type"), equipType);
		modelNameSet.Close();
	}


	query.Format(_T(
		"INSERT INTO EnclosureChangeEquipHistoryTable(EnclosureIndex, Type, PrevEquipModelName, ChangedEquipModelName, Description, ChangeDate) VALUES(%s, '%s', '%s', Null, '장비 제거', '%s')"), enclIndex, equipType, equipModelName, CTime::GetCurrentTime().Format("%Y-%m-%d"));
	try
	{
		db.ExecuteSQL(query);
	}
	catch (CDBException *e)
	{
		TCHAR arr[256];
		e->GetErrorMessage(arr, 256);
		std::wcout << arr << std::endl;
	}
}

void EnclBaseDialog::InsertHistoryAsUpdate(CDatabase& db, const CString& installLocation, const CString& prevEquipModelName, const CString& nextEquipModelName)
{
	CString query;
	CString enclIndex, equipType;

	{
		query.Format(_T("SELECT Index FROM EnclosureInstallTable WHERE InstallLocation='%s'"), installLocation);
		CRecordset indexSet(&db);

		try
		{
			indexSet.Open(CRecordset::dynaset, query);
		}
		catch (CDBException *e)
		{
			TCHAR arr[256];
			e->GetErrorMessage(arr, 256);
			std::wcout << arr << std::endl;
		}

		indexSet.GetFieldValue(_T("Index"), enclIndex);
		indexSet.Close();
	}

	{
		query.Format(_T("SELECT Type FROM BaseEquipmentTable WHERE ModelName='%s'"), prevEquipModelName);

		CRecordset modelNameSet(&db);

		try
		{
			modelNameSet.Open(CRecordset::dynaset, query);
		}
		catch (CDBException *e)
		{
			TCHAR arr[256];
			e->GetErrorMessage(arr, 256);
			std::wcout << arr << std::endl;
		}

		modelNameSet.GetFieldValue(_T("Type"), equipType);
		modelNameSet.Close();
	}


	query.Format(_T(
		"INSERT INTO EnclosureChangeEquipHistoryTable(EnclosureIndex, Type, PrevEquipModelName, ChangedEquipModelName, Description, ChangeDate) VALUES(%s, '%s', '%s', '%s', '장비 변경', '%s')"), enclIndex, equipType, prevEquipModelName, nextEquipModelName, CTime::GetCurrentTime().Format("%Y-%m-%d"));
	try
	{
		db.ExecuteSQL(query);
	}
	catch (CDBException *e)
	{
		TCHAR arr[256];
		e->GetErrorMessage(arr, 256);
		std::wcout << arr << std::endl;
	}
}

void EnclBaseDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_ENBA_LISTCTRL_ENCLBASE				, enclBaseListCtrl);
	DDX_Control(pDX, IDC_ENBA_LISTCTRL_BASE_CHANGE_HISTORY	, equipChangeHistoryListCtrl);

	DDX_Control(pDX, IDC_ENBA_COMBO_ENCLOSURE				, enclosureComboBox);
	DDX_Control(pDX, IDC_ENBA_COMBO_BASEEQUIP				, baseEquipComboBox);

	DDX_Control(pDX, IDC_ENBA_BUTTON_SEARCH					, searchButton);
	DDX_Control(pDX, IDC_ENBA_BUTTON_SAVE					, saveButton);
	DDX_Control(pDX, IDC_ENBA_BUTTON_MODIFY					, modifyButton);
	DDX_Control(pDX, IDC_ENBA_BUTTON_CANCEL					, cancelButton);
	DDX_Control(pDX, IDC_ENBA_BUTTON_COPY					, copyButton);

	DDX_Control(pDX, IDC_ENBA_STATIC_SELECTION_MODE_WARNING	, selectionWarningStatic);
}


BEGIN_MESSAGE_MAP(EnclBaseDialog, CDialogEx)
	ON_NOTIFY(LVN_ITEMACTIVATE, IDC_ENBA_LISTCTRL_ENCLBASE, &EnclBaseDialog::OnLvnItemActivateEnbaListctrlEnclbase)
	ON_CBN_SELCHANGE(IDC_ENBA_COMBO_ENCLOSURE, &EnclBaseDialog::OnCbnSelchangeEnbaComboEnclosure)
	ON_CBN_SELCHANGE(IDC_ENBA_COMBO_BASEEQUIP, &EnclBaseDialog::OnCbnSelchangeEbbaComboBaseEquip)
	ON_BN_CLICKED(IDC_ENBA_BUTTON_SEARCH, &EnclBaseDialog::OnBnClickedEnbaButtonSearch)
	ON_BN_CLICKED(IDC_ENBA_BUTTON_COPY, &EnclBaseDialog::OnBnClickedEnbaButtonCopy)
	ON_BN_CLICKED(IDC_ENBA_BUTTON_SAVE, &EnclBaseDialog::OnBnClickedEnbaButtonSave)
	ON_BN_CLICKED(IDC_ENBA_BUTTON_MODIFY, &EnclBaseDialog::OnBnClickedEnbaButtonModify)
	ON_BN_CLICKED(IDC_ENBA_BUTTON_CANCEL, &EnclBaseDialog::OnBnClickedEnbaButtonCancel)
	ON_NOTIFY(NM_CLICK, IDC_ENBA_LISTCTRL_ENCLBASE, &EnclBaseDialog::OnNMClickEnbaListctrlEnclbase)
	ON_WM_KEYDOWN()
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// EnclBaseDialog 메시지 처리기입니다.


BOOL EnclBaseDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	DWORD 
	dwListExtStyle = enclBaseListCtrl.GetExtendedStyle();
	enclBaseListCtrl.SetExtendedStyle(dwListExtStyle | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	dwListExtStyle = equipChangeHistoryListCtrl.GetExtendedStyle();
	equipChangeHistoryListCtrl.SetExtendedStyle(dwListExtStyle | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	return TRUE;  
}


BOOL EnclBaseDialog::DestroyWindow()
{
	return CDialogEx::DestroyWindow();
}


void EnclBaseDialog::OnLvnItemActivateEnbaListctrlEnclbase(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMIA = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	*pResult = 0;

	SetSelectionMode(TRUE);

	enclBaseSelectIndex = pNMIA->iItem;
	std::cout << "activated " << pNMIA->iItem << ", " << pNMIA->iSubItem << std::endl;

	{		
		CRecordset* enclAndEquip = DataManageDB::GetAllEquipmentAndEnclosure();
		enclAndEquip->MoveFirst();
		enclAndEquip->Move(enclBaseSelectIndex);

		enclAndEquip->GetFieldValue(_T("EnclosureIndex"), selectedEnclosureIndex);
		enclAndEquip->GetFieldValue(_T("InstallLocation"), selectedInstallLocation);
		enclAndEquip->GetFieldValue(_T("EquipModelName"), selectedEquipModelName);

		for (int index = 0; index < enclosureComboBox.GetCount(); index++)
		{
			CString encl;
			enclosureComboBox.GetLBText(index, encl);
			if (encl.Compare(selectedInstallLocation) == 0)
			{
				enclosureComboBox.SetCurSel(index);
				break;
			}
		}


		RefreshBaseEquipComboBoxAsModelName(*enclAndEquip->m_pDatabase, selectedEquipModelName);

		for (int index = 0; index < baseEquipComboBox.GetCount(); index++)
		{
			CString equip;
			baseEquipComboBox.GetLBText(index, equip);
			if (equip.Compare(selectedEquipModelName) == 0)
			{
				baseEquipComboBox.SetCurSel(index);
				break;
			}
		}

		enclAndEquip->Close();
		delete enclAndEquip;
	}
}


void EnclBaseDialog::OnCbnSelchangeEnbaComboEnclosure()
{
}


void EnclBaseDialog::OnCbnSelchangeEbbaComboBaseEquip()
{
}


// 확인안됨
void EnclBaseDialog::OnBnClickedEnbaButtonSearch()
{
	int baseCurSel = baseEquipComboBox.GetCurSel(), enclCurSel = enclosureComboBox.GetCurSel();

	if (baseCurSel < 0 || enclCurSel < 0)
	{
		AfxMessageBox(_T("콤보 박스가 선택되지 않았습니다."));
		return;
	}

	if (enclosureComboBox.GetCount() == 0 || baseEquipComboBox.GetCount() == 0)
		return;
	
	CString findEnclIndexString, findModelNameString, findInstallLocation;

	{
		baseEquipComboBox.GetLBText(baseCurSel, findModelNameString);
		enclosureComboBox.GetLBText(enclCurSel, findInstallLocation);

		CRecordset* encl = DataManageDB::GetAllEnclosures();
		encl->MoveFirst();
		while (!encl->IsEOF())
		{
			CString installLocation;
			encl->GetFieldValue(_T("InstallLocation"), installLocation);

			if (installLocation.Compare(findInstallLocation) == 0)
			{
				encl->GetFieldValue(_T("Index"), findEnclIndexString);
				break;
			}

			encl->MoveNext();
		}
		encl->Close();
		delete encl;
	}

	int itemIndex = FindEnclBaseInList(findEnclIndexString, findModelNameString);

	if (itemIndex >= 0)
	{
		enclBaseListCtrl.SetItemState(itemIndex, LVIS_SELECTED, LVIS_SELECTED);
		enclBaseListCtrl.SetFocus();
	}
	else
	{
		CString msg;
		msg.Format(_T("함체위치=%s,장비이름=\'%s\'를 찾지 못했습니다."), findInstallLocation, findModelNameString);
		AfxMessageBox(msg);
	}
}


void EnclBaseDialog::OnBnClickedEnbaButtonCopy()
{
	if (enclBaseListCtrl.GetSelectedCount() <= 0) return;

	CDatabase db;
	try
	{
		db.OpenEx(_T("DSN=enclosure"));
	}
	catch (CDBException* e)
	{
		AfxMessageBox(_T("데이터베이스를 연결할 수 없습니다."));
		return;
	}

	POSITION pos = enclBaseListCtrl.GetFirstSelectedItemPosition();

	while (pos)
	{
		int index = enclBaseListCtrl.GetNextSelectedItem(pos);
		std::cout << index << std::endl;

		CString installLocation = enclBaseListCtrl.GetItemText(index, 1),
				equipModelName = enclBaseListCtrl.GetItemText(index, 2);

		{
			CString query;
			query.Format(_T("DELETE FROM InstalledEquipInEnclosureTable WHERE EnclosureIndex in (SELECT Index FROM EnclosureInstallTable WHERE InstallLocation='%s') AND EquipModelName='%s'"), installLocation, equipModelName);
			db.ExecuteSQL(query);
		}

		InsertHistoryAsDelete(db, installLocation, equipModelName);
	}

	db.Close();

	RefreshEnclBaseList();

	if (isSelectionMode)
	{
		SetSelectionMode(FALSE);
		RefreshComboBox();
	}
}


void EnclBaseDialog::OnBnClickedEnbaButtonSave()
{
	int baseCurSel = baseEquipComboBox.GetCurSel(), enclCurSel = enclosureComboBox.GetCurSel();

	if (baseCurSel < 0 || enclCurSel < 0)
	{
		AfxMessageBox(_T("콤보 박스가 선택되지 않았습니다."));
		return;
	}

	CString findEnclIndexString, findModelNameString, findInstallLocation;

	{
		baseEquipComboBox.GetLBText(baseCurSel, findModelNameString);
		enclosureComboBox.GetLBText(enclCurSel, findInstallLocation);

		CRecordset* encl = DataManageDB::GetAllEnclosures();
		encl->MoveFirst();
		while (!encl->IsEOF())
		{
			CString installLocation;
			encl->MoveNext();
			encl->GetFieldValue(_T("InstallLocation"), installLocation);

			if (installLocation.Compare(findInstallLocation) == 0)
			{
				encl->GetFieldValue(_T("Index"), findEnclIndexString);
				break;
			}
		}
		encl->Close();
		delete encl;
	}

	int itemIndex = FindEnclBaseInList(findEnclIndexString, findModelNameString);

	if (itemIndex < 0)
	{
		CRecordset* enclAndEquip = DataManageDB::GetAllEquipmentAndEnclosure();
		enclAndEquip->MoveFirst();
		enclAndEquip->Move(itemIndex);

		CString query;
		query.Format(
			_T("INSERT INTO InstalledEquipInEnclosureTable(EnclosureIndex, EquipModelName) VALUES(%s, '%s')"), 
			findEnclIndexString, findModelNameString
			);
		enclAndEquip->m_pDatabase->ExecuteSQL(query);

		InsertHistoryAsInsert(*enclAndEquip->m_pDatabase, findInstallLocation, findModelNameString);

		enclAndEquip->Close();
		delete enclAndEquip;

		RefreshEnclBaseList();
	}
	else
	{
		CString msg;
		msg.Format(_T("함체위치=%s,장비이름=\'%s\'가 이미 존재합니다."), findInstallLocation, findModelNameString);
		AfxMessageBox(msg);

		enclBaseListCtrl.SetItemState(itemIndex, LVIS_SELECTED, LVIS_SELECTED);
		enclBaseListCtrl.SetFocus();
	}
}


void EnclBaseDialog::OnBnClickedEnbaButtonModify()
{
	int baseCurSel = baseEquipComboBox.GetCurSel(), enclCurSel = enclosureComboBox.GetCurSel();

	if (baseCurSel < 0 || enclCurSel < 0)
	{
		AfxMessageBox(_T("콤보 박스가 선택되지 않았습니다."));
		return;
	}

	if (enclosureComboBox.GetCount() == 0 || baseEquipComboBox.GetCount() == 0)
		return;

	CString updateEnclIndexString, updateModelNameString, updateInstallLocation;

	{
		baseEquipComboBox.GetLBText(baseCurSel, updateModelNameString);
		enclosureComboBox.GetLBText(enclCurSel, updateInstallLocation);

		CRecordset* encl = DataManageDB::GetAllEnclosures();
		encl->MoveFirst();
		while (!encl->IsEOF())
		{
			CString installLocation;
			encl->MoveNext();
			encl->GetFieldValue(_T("InstallLocation"), installLocation);
			if (installLocation.Compare(updateInstallLocation) == 0)
			{
				encl->GetFieldValue(_T("Index"), updateEnclIndexString);
				break;
			}
		}
		encl->Close();
		delete encl;
	}

	if (FindEnclBaseInList(updateEnclIndexString, updateModelNameString) < 0)
	{
		CDatabase db;
		db.OpenEx(_T("DSN=enclosure;"));

		CString query;
		query.Format(
			_T("UPDATE InstalledEquipInEnclosureTable SET EnclosureIndex=%s, EquipModelName=\'%s\' WHERE EnclosureIndex=%s AND EquipModelName=\'%s\'"), 
			updateEnclIndexString.GetString(), updateModelNameString.GetString(),
			selectedEnclosureIndex.GetString(), selectedEquipModelName.GetString()
		);
		try
		{
			db.ExecuteSQL(query);
		}
		catch (CDBException* e)
		{
			TCHAR err[257];
			e->GetErrorMessage(err, 256);
			std::wcout << err << std::endl;
		}

		InsertHistoryAsUpdate(db, updateInstallLocation, selectedEquipModelName, updateModelNameString);

		db.Close();

		SetSelectionMode(FALSE);
		RefreshComboBox();

		RefreshEnclBaseList();

		enclBaseListCtrl.SetItemState(enclBaseSelectIndex, LVIS_SELECTED, LVIS_SELECTED);
		enclBaseListCtrl.SetFocus();

		ClearInputField();
	}
	else
	{
		CString msg;
		msg.Format(_T("함체위치=%s,장비이름=\'%s\'가 이미 존재합니다."), updateInstallLocation, updateModelNameString);
		AfxMessageBox(msg);
	}
}


void EnclBaseDialog::OnBnClickedEnbaButtonCancel()
{
	if (isSelectionMode)
	{
		SetSelectionMode(FALSE);
		RefreshComboBox();
		ClearInputField();
	}
}


void EnclBaseDialog::OnNMClickEnbaListctrlEnclbase(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;

	if (pNMItemActivate->iItem >= 0)
	{
		CRecordset* set = DataManageDB::GetAllEquipmentAndEnclosure();
		set->Move(pNMItemActivate->iItem);
		CString indexString;
		set->GetFieldValue(_T("EnclosureIndex"), indexString);
		RefreshEquipChangeHistoryList(indexString);
		set->Close();
		delete set;
	}
	else
	{
		equipChangeHistoryListCtrl.DeleteAllItems();
	}
}


void EnclBaseDialog::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	if (bShow)
	{
		RefreshEnclBaseList();
		RefreshComboBox();

		SetSelectionMode(FALSE);
	}
}


BOOL EnclBaseDialog::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN)
		{
			return FALSE;
		}
		else if (pMsg->wParam == VK_ESCAPE)
		{
			if (isSelectionMode)
			{
				SetSelectionMode(FALSE);
				RefreshComboBox();
			}
			return TRUE;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
