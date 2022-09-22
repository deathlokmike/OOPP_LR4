
// Drozdov_OOPP_L4Doc.cpp: реализация класса CDrozdovOOPPL4Doc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Drozdov_OOPP_L4.h"
#endif

#include "Drozdov_OOPP_L4Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDrozdovOOPPL4Doc

IMPLEMENT_DYNCREATE(CDrozdovOOPPL4Doc, CDocument)

BEGIN_MESSAGE_MAP(CDrozdovOOPPL4Doc, CDocument)
END_MESSAGE_MAP()


// Создание или уничтожение CDrozdovOOPPL4Doc

CDrozdovOOPPL4Doc::CDrozdovOOPPL4Doc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CDrozdovOOPPL4Doc::~CDrozdovOOPPL4Doc()
{
}

BOOL CDrozdovOOPPL4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// Сериализация CDrozdovOOPPL4Doc

void CDrozdovOOPPL4Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		concern.to_file(ar);
	}
	else
	{
		concern.clear();
		concern.from_file(ar);
		AfxGetMainWnd()->Invalidate();
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CDrozdovOOPPL4Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CDrozdovOOPPL4Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CDrozdovOOPPL4Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CDrozdovOOPPL4Doc

#ifdef _DEBUG
void CDrozdovOOPPL4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrozdovOOPPL4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CDrozdovOOPPL4Doc
