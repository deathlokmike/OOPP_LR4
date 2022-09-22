#pragma once
#include "framework.h"
class dlg_edit;
class vehicleDrozdov: public CObject
{
protected:
	CString name;
	int year = 0;
	int strt_prc = 0;

public:
	DECLARE_SERIAL(vehicleDrozdov)
	vehicleDrozdov() {}
	virtual ~vehicleDrozdov() {}
	virtual void Serialize(CArchive& ar);
	virtual void StrLen(int* aLen, CDC* pDC);
	virtual void output(CDC* pDC, int* aLeft, int& top, int lineHeight);
	CString GetCName();
	virtual void SetField(dlg_edit* dlg);
	virtual void UpdateVisibility(dlg_edit* dlg);
	virtual void Save(dlg_edit* dlg);
	virtual void Update(dlg_edit* dlg);
};
