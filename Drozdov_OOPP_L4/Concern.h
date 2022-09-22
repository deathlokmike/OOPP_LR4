#pragma once
#include "Car.h"
#include "SportCar.h"
class dlg_edit;

class ConcernDrozdov
{
public:
	vector<shared_ptr<vehicleDrozdov>> motorshow;
	void to_file(CArchive& ar);
	void from_file(CArchive& ar);
	void clear();
	CSize out(CDC* pDC);
	int OutToListBox(dlg_edit* dlg);
	void SetFields(dlg_edit* dlg, int selected);
	void AddCar(dlg_edit* dlg);
	void AddSportCar(dlg_edit* dlg);
	void DeleteItem(int index);
	virtual ~ConcernDrozdov()
	{
		motorshow.clear();
	}
};
