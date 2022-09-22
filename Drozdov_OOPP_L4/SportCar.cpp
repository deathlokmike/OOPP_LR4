#include "pch.h"
#include "SportCar.h"
#include "dlg_edit.h"
IMPLEMENT_SERIAL(SportCarDrozdov, vehicleDrozdov, VERSIONABLE_SCHEMA | 0);

void SportCarDrozdov::StrLen(int* aLen, CDC* pDC)
{
	vehicleDrozdov::StrLen(aLen, pDC);
	aLen[3] = pDC->GetTextExtent((CString)to_string(engine_power).c_str()).cx;
	aLen[4] = pDC->GetTextExtent((CString)to_string(torque).c_str()).cx;
}

void SportCarDrozdov::output(CDC* pDC, int* aLeft, int& top, int lineHeight)
{
	pDC->TextOut(aLeft[3], top, (CString)to_string(engine_power).c_str());
	pDC->TextOut(aLeft[4], top, (CString)to_string(torque).c_str());
	vehicleDrozdov::output(pDC, aLeft, top, lineHeight);
}

void SportCarDrozdov::Serialize(CArchive& ar)
{
	vehicleDrozdov::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << engine_power;
		ar << torque;
	}
	else
	{
		ar >> engine_power;
		ar >> torque;
	}
}

CString SportCarDrozdov::GetCName()
{
	return vehicleDrozdov::GetCName();
}

void SportCarDrozdov::SetField(dlg_edit* dlg)
{
	dlg->power_txt = (CString)to_string(engine_power).c_str();
	dlg->torque_txt = (CString)to_string(torque).c_str();
	vehicleDrozdov::SetField(dlg);
}

void SportCarDrozdov::UpdateVisibility(dlg_edit* dlg)
{
	dlg->torque.ShowWindow(TRUE);
	dlg->torque_txt_const.ShowWindow(TRUE);
	dlg->power_txt_const.ShowWindow(TRUE);
	dlg->power.ShowWindow(TRUE);
}

void SportCarDrozdov::Save(dlg_edit* dlg)
{
	vehicleDrozdov::Save(dlg);
	engine_power = _ttoi(dlg->power_txt);
	torque = _ttoi(dlg->torque_txt);
}

void SportCarDrozdov::Update(dlg_edit* dlg)
{
	vehicleDrozdov::Update(dlg);
	torque = _ttoi(dlg->torque_txt);
	engine_power = _ttoi(dlg->power_txt);
}