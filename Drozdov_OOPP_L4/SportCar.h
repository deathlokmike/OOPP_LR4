#pragma once
#include "Car.h"

class SportCarDrozdov : public vehicleDrozdov
{
	int engine_power = 0;
	int torque = 0;
public:
	DECLARE_SERIAL(SportCarDrozdov)
	SportCarDrozdov() {};
	virtual ~SportCarDrozdov() {};

	virtual void StrLen(int* aLen, CDC* pDC) override;
	virtual void output(CDC* pDC, int* aLeft, int& top, int lineHeight);
	virtual void Serialize(CArchive& ar);
	CString GetCName();
	virtual void SetField(dlg_edit* dlg);
	virtual void UpdateVisibility(dlg_edit* dlg);
	virtual void Save(dlg_edit* dlg);
	virtual void Update(dlg_edit* dlg);
};

