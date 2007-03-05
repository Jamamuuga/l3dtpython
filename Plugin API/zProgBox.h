#pragma once
#include "zvar.h"

class CzProgBox :
	public CzVar
{
public:
	CzProgBox(void);
	~CzProgBox(void);

	bool Create(const char* lpVarName = 0);

	bool ShowWnd();
	bool HideWnd();
	bool SetTitle(const char* lpTitleText);
	bool SetProgress(__int64 p, __int64 pmax);
};
