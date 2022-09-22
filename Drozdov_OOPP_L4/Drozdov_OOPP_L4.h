
// Drozdov_OOPP_L4.h: основной файл заголовка для приложения Drozdov_OOPP_L4
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CDrozdovOOPPL4App:
// Сведения о реализации этого класса: Drozdov_OOPP_L4.cpp
//

class CDrozdovOOPPL4App : public CWinApp
{
public:
	CDrozdovOOPPL4App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrozdovOOPPL4App theApp;
