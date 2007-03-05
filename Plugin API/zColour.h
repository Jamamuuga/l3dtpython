#pragma once
#include "zvar.h"

class CzColour :
	public CzVar
{
public:
	CzColour(void);
	~CzColour(void);

	bool Create(const char* lpVarName = NULL);

	BYTE GetR();
	BYTE GetG();
	BYTE GetB();

	COLORREF GetCOLORREF();

	bool SetRGB(BYTE r, BYTE g, BYTE b);
	bool SetRGB(COLORREF ColRef);

	//Cast-to-COlORREF operator
	operator COLORREF () {
		return GetCOLORREF();
	}

	// assignment operator
	bool operator = (COLORREF ColRef) {
		return SetRGB(ColRef);
	}
};
