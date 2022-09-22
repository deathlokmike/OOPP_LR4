// dlg_edit.cpp: файл реализации
//

#include "pch.h"
#include "Drozdov_OOPP_L4.h"
#include "dlg_edit.h"
#include "afxdialogex.h"
#include "Drozdov_OOPP_L4Doc.h"
#include "Drozdov_OOPP_L4View.h"

// Диалоговое окно dlg_edit

IMPLEMENT_DYNAMIC(dlg_edit, CDialogEx)

dlg_edit::dlg_edit(CDrozdovOOPPL4Doc* pDocIni, CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
	this->pDoc = pDocIni;
}

dlg_edit::~dlg_edit()
{
}

void dlg_edit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, edit_name, name);
	DDX_Control(pDX, IDC_LIST1, list_edit);
	DDX_Control(pDX, edit_year, year);
	DDX_Control(pDX, edit_price, price);
	DDX_Control(pDX, edit_power,  power);
	DDX_Control(pDX, edit_torque, torque);
	DDX_Control(pDX, lbl_power, power_txt_const);
	DDX_Control(pDX, lbl_torque, torque_txt_const);
	DDX_Text(pDX, edit_name, name_txt);
	DDX_Text(pDX, edit_year, year_txt);
	DDX_Text(pDX, edit_price, price_txt);
	DDX_Text(pDX, edit_power, power_txt);
	DDX_Text(pDX, edit_torque, torque_txt);
}


BEGIN_MESSAGE_MAP(dlg_edit, CDialogEx)
	ON_EN_CHANGE(edit_name, &dlg_edit::OnEnChange)
	ON_EN_CHANGE(edit_year, &dlg_edit::OnEnChange)
	ON_EN_CHANGE(edit_price, &dlg_edit::OnEnChange)
	ON_EN_CHANGE(edit_power, &dlg_edit::OnEnChange)
	ON_EN_CHANGE(edit_torque, &dlg_edit::OnEnChange)
	ON_BN_CLICKED(btn_add_car, &dlg_edit::OnBnClickedaddcar)
	ON_BN_CLICKED(btn_add_sportcar, &dlg_edit::OnBnClickedaddsportcar)
	ON_BN_CLICKED(btn_delete, &dlg_edit::OnBnClickeddelete)
	ON_LBN_SELCHANGE(IDC_LIST1, &dlg_edit::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// Обработчики сообщений dlg_edit

BOOL dlg_edit::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	pDoc->concern.OutToListBox(this);
	return TRUE;
}

void dlg_edit::OnEnChange()
{
	int index = list_edit.GetCurSel();
	UpdateData();
	if (index > 0) 
	{
		pDoc->concern.motorshow[index]->Update(this);
		pDoc->concern.OutToListBox(this);
		list_edit.SetCurSel(index);
	}
	
}

void dlg_edit::OnBnClickedaddcar()
{
	UpdateData();
	pDoc->concern.AddCar(this);
	pDoc->concern.OutToListBox(this);
	this->UpdateData();
}


void dlg_edit::OnBnClickedaddsportcar()
{
	UpdateData();
	pDoc->concern.AddSportCar(this);
	pDoc->concern.OutToListBox(this);
	this->UpdateData();
}


void dlg_edit::OnBnClickeddelete()
{
	int index = list_edit.GetCurSel();
	pDoc->concern.DeleteItem(index);
	pDoc->concern.OutToListBox(this);
	if (pDoc->concern.motorshow.size() > 0)
	{
		if (index == 0)
			pDoc->concern.motorshow[index];
		else
			pDoc->concern.motorshow[index - 1];
		if ((index) != pDoc->concern.motorshow.size())
		{
			list_edit.SetCurSel(index);
			pDoc->concern.SetFields(this, index);
		}
		else
		{
			list_edit.SetCurSel(index - 1);
			pDoc->concern.SetFields(this, index - 1);
		}
	}
}


void dlg_edit::OnLbnSelchangeList1()
{
	int selected = list_edit.GetCurSel();
	if (selected != -1)
		pDoc->concern.SetFields(this, selected);
}