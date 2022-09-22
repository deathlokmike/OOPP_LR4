
// Drozdov_OOPP_L4Doc.h: интерфейс класса CDrozdovOOPPL4Doc 
//


#pragma once
#include "Concern.h"

class CDrozdovOOPPL4Doc : public CDocument
{
protected: // создать только из сериализации
	CDrozdovOOPPL4Doc() noexcept;
	DECLARE_DYNCREATE(CDrozdovOOPPL4Doc)

// Атрибуты
public:
	ConcernDrozdov concern;
// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CDrozdovOOPPL4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
