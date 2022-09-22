
// Drozdov_OOPP_L4View.h: интерфейс класса CDrozdovOOPPL4View
//

#pragma once


class CDrozdovOOPPL4View : public CScrollView
{
protected: // создать только из сериализации
	CDrozdovOOPPL4View() noexcept;
	DECLARE_DYNCREATE(CDrozdovOOPPL4View)

// Атрибуты
public:
	CDrozdovOOPPL4Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора

// Реализация
public:
	virtual ~CDrozdovOOPPL4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;

#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEdit();
};

#ifndef _DEBUG  // версия отладки в Drozdov_OOPP_L4View.cpp
inline CDrozdovOOPPL4Doc* CDrozdovOOPPL4View::GetDocument() const
   { return reinterpret_cast<CDrozdovOOPPL4Doc*>(m_pDocument); }
#endif

