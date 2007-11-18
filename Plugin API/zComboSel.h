#pragma once
#include "zvar.h"

class CzComboSel :
	public CzVar
{
public:
	CzComboSel(void);
	~CzComboSel(void);

	bool Create(const char* lpVarName = 0);

	bool		SetOptions(const char* lpOptionsStr);
	const char*	GetOptions();
	bool		SetCurSel(const char* lpCurSelStr);
	const char*	GetCurSel();
};
