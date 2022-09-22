#include "pch.h"
#include "Concern.h"
#include "dlg_edit.h"


void ConcernDrozdov::to_file(CArchive& ar)
{
	if (motorshow.size() != 0) 
	{
		ar << this->motorshow.size();
		for (auto& vhcl : motorshow)
		{
			ar << vhcl.get();
		}
	}
}

void ConcernDrozdov::from_file(CArchive& ar)
{
	int count_str;
	ar >> count_str;
	for (int i = 0; i < count_str; ++i)
	{
		vehicleDrozdov* vhcl;
		ar >> vhcl;
		motorshow.push_back(shared_ptr<vehicleDrozdov>(vhcl));
	}
}

CSize ConcernDrozdov::out(CDC* pDC)
{
	POINT sizeAll;
	sizeAll.x = 0;
	sizeAll.y = 0;

	// Отсутпы Горизонтальные отсупы м/у словами Высота линий
	const int wordSpacing = 5;
	const int horizontalPadding = 15;
	const int lineHeight = 30;
	const int count_column = 5;

	// Шапка
	CString m_header[count_column];
	m_header[0] = "Auto";
	m_header[1] = "Year";
	m_header[2] = "Start price";
	m_header[3] = "Power engine";
	m_header[4] = "Torque";


	// Формируем массив максимальных длинн текста в px, за основу берётся шапка
	int aLen[count_column];
	for (int i = 0; i < count_column; ++i)
		aLen[i] = pDC->GetTextExtent(m_header[i]).cx;

	if (motorshow.size() != 0)
	{
		// расширяеем массив, вычисляя длины элементов
		for (auto student : motorshow)
		{
			int memLen[count_column];
			student->StrLen(memLen, pDC);
			for (int i = 0; i < count_column; ++i)
				if (memLen[i] > aLen[i])
					aLen[i] = memLen[i];
		}

		// Превращаем массив длинн в массив координат
		aLen[0] += wordSpacing;
		for (int i = 1; i < count_column; ++i)
		{
			aLen[i - 1] += horizontalPadding;
			aLen[i] += aLen[i - 1];
		}

		int aLeft[count_column];
		aLeft[0] = wordSpacing;
		for (int i = 1; i < count_column; ++i)
			aLeft[i] = aLen[i - 1];

		// Выводим шапку
		int top = wordSpacing;
		for (int i = 0; i < count_column; ++i)
		{
			pDC->TextOutW(aLeft[i], top, m_header[i]);
		}
		top += lineHeight;

		for_each(motorshow.begin(), motorshow.end(), bind(&vehicleDrozdov::output, placeholders::_1, pDC, aLeft, ref(top), lineHeight));

		// Размер рабочей области
		sizeAll.x = aLen[4] + wordSpacing;
		sizeAll.y = top;

		// Разделительные линии
		pDC->MoveTo(0, 0);
		pDC->LineTo(sizeAll.x, 0);
		pDC->LineTo(sizeAll);
		pDC->LineTo(0, sizeAll.y);
		pDC->LineTo(0, 0);

		for (int i = 1; i < count_column; ++i)
		{
			pDC->MoveTo(aLeft[i] - horizontalPadding / 2, 0);
			pDC->LineTo(aLeft[i] - horizontalPadding / 2, sizeAll.y);
		}
		pDC->MoveTo(0, wordSpacing + lineHeight * 0.8);
		pDC->LineTo(sizeAll.x, wordSpacing + lineHeight * 0.8);
	}

	return sizeAll;
}

void ConcernDrozdov::clear()
{
	motorshow.clear();
}


int ConcernDrozdov::OutToListBox(dlg_edit* dlg)
{
	dlg->list_edit.ResetContent();
	if (motorshow.empty()) return 0;
	int i = 0;
	for_each(motorshow.begin(), motorshow.end(), [&](shared_ptr<vehicleDrozdov> vhcl)
		{
			dlg->list_edit.AddString(vhcl->GetCName());
		});
	return motorshow.size();
}

void ConcernDrozdov::SetFields(dlg_edit* dlg, int selected)
{
	motorshow[selected]->SetField(dlg);
	motorshow[selected]->UpdateVisibility(dlg);
}

void ConcernDrozdov::AddCar(dlg_edit* dlg)
{
	shared_ptr<vehicleDrozdov> buf;
	buf = make_shared<vehicleDrozdov>();
	buf->Save(dlg);
	motorshow.push_back(buf);
}

void ConcernDrozdov::AddSportCar(dlg_edit* dlg)
{
	shared_ptr<vehicleDrozdov> buf;
	buf = make_shared<SportCarDrozdov>();
	buf->Save(dlg);
	motorshow.push_back(buf);
}

void ConcernDrozdov::DeleteItem(int index)
{
	if (motorshow.size() != 0)
		motorshow.erase(motorshow.begin() + index);
}