#pragma once
#include "Drozdov_OOPP_L4Doc.h" 

// Диалоговое окно dlg_edit

class dlg_edit : public CDialogEx
{
	DECLARE_DYNAMIC(dlg_edit)
private:
	CDrozdovOOPPL4Doc* pDoc;
public:
	dlg_edit(CDrozdovOOPPL4Doc* pDocIni, CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~dlg_edit();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CListBox list_edit;
	CEdit name;
	CEdit year;
	CEdit price;
	CEdit power;
	CEdit torque;
	CString name_txt;
	CString year_txt;
	CString price_txt;
	CString power_txt;
	CString torque_txt;
	CStatic power_txt_const;
	CStatic torque_txt_const;
	afx_msg BOOL OnInitDialog();
	afx_msg void OnEnChange();
	afx_msg void OnBnClickedaddcar();
	afx_msg void OnBnClickedaddsportcar();
	afx_msg void OnBnClickeddelete();
	afx_msg void OnLbnSelchangeList1();
};
