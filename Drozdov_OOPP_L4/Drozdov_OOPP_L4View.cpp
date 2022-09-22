
// Drozdov_OOPP_L4View.cpp: реализация класса CDrozdovOOPPL4View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Drozdov_OOPP_L4.h"
#endif

#include "Drozdov_OOPP_L4Doc.h"
#include "Drozdov_OOPP_L4View.h"
#include "dlg_edit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrozdovOOPPL4View

IMPLEMENT_DYNCREATE(CDrozdovOOPPL4View, CScrollView)

BEGIN_MESSAGE_MAP(CDrozdovOOPPL4View, CScrollView)
	ON_COMMAND(ID_APP_ED, &CDrozdovOOPPL4View::OnEdit)
END_MESSAGE_MAP()

// Создание или уничтожение CDrozdovOOPPL4View

CDrozdovOOPPL4View::CDrozdovOOPPL4View() noexcept
{
	// TODO: добавьте код создания

}

CDrozdovOOPPL4View::~CDrozdovOOPPL4View()
{
}

BOOL CDrozdovOOPPL4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// Рисование CDrozdovOOPPL4View

void CDrozdovOOPPL4View::OnDraw(CDC* pDC)
{
	CDrozdovOOPPL4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CSize sizeTotal = pDoc->concern.out(pDC);
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CDrozdovOOPPL4View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: рассчитайте полный размер этого представления
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Диагностика CDrozdovOOPPL4View

#ifdef _DEBUG
void CDrozdovOOPPL4View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDrozdovOOPPL4View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDrozdovOOPPL4Doc* CDrozdovOOPPL4View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrozdovOOPPL4Doc)));
	return (CDrozdovOOPPL4Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CDrozdovOOPPL4View
void CDrozdovOOPPL4View::OnEdit()
{
	dlg_edit dial(GetDocument());
	dial.DoModal();
	Invalidate();
}