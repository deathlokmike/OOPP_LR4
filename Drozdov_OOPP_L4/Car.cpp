#include "pch.h"
#include "Car.h"
#include "dlg_edit.h"
IMPLEMENT_SERIAL(vehicleDrozdov, CObject, 0);

void vehicleDrozdov::StrLen(int* aLen, CDC* pDC)
{
	aLen[0] = pDC->GetTextExtent(name).cx;
	aLen[1] = pDC->GetTextExtent((CString)to_string(year).c_str()).cx;
	aLen[2] = pDC->GetTextExtent((CString)to_string(strt_prc).c_str()).cx;
}

void vehicleDrozdov::output(CDC* pDC, int* aLeft, int& top, int lineHeight)
{
	CString buf;
	pDC->TextOut(aLeft[0], top, name);
	pDC->TextOut(aLeft[1], top, (CString)to_string(year).c_str());
	pDC->TextOut(aLeft[2], top, (CString)to_string(strt_prc).c_str());
	top += lineHeight;
}

void vehicleDrozdov::Serialize(CArchive& ar)
{
	if (ar.IsStoring())  
	{
		ar << year;
		ar << strt_prc; 
		ar << name;
	}
	else
	{
		ar >> year;
		ar >> strt_prc;
		ar >> name;
	}
}

CString vehicleDrozdov::GetCName()
{
	return name;
}

void vehicleDrozdov::SetField(dlg_edit* dlg)
{
	dlg->name_txt = name;
	dlg->year_txt = (CString)to_string(year).c_str();
	dlg->price_txt = (CString)to_string(strt_prc).c_str();
	dlg->UpdateData(false);
}

void vehicleDrozdov::UpdateVisibility(dlg_edit* dlg)
{
	dlg->torque.ShowWindow(FALSE);
	dlg->torque_txt_const.ShowWindow(FALSE);
	dlg->power_txt_const.ShowWindow(FALSE);
	dlg->power.ShowWindow(FALSE);
}

void vehicleDrozdov::Save(dlg_edit* dlg)
{
	name = dlg->name_txt;
	year = _ttoi(dlg->year_txt);
	strt_prc =_ttoi(dlg->price_txt);
}

void vehicleDrozdov::Update(dlg_edit* dlg)
{
	name = dlg->name_txt;
	year = _ttoi(dlg->year_txt);
	strt_prc = _ttoi(dlg->price_txt);
}