#pragma once
#include "zvar.h"

// need a windows header for COLORREF
//#ifdef _MSC_VER
//#include <afx.h>
//#else
#include <windows.h>
//#endif

class CzColour :
	public CzVar
{
public:
	CzColour(void);
	~CzColour(void);

	bool Create(const char* lpVarName = 0);

	unsigned char GetR();
	unsigned char GetG();
	unsigned char GetB();

	COLORREF GetCOLORREF();

	bool SetRGB(unsigned char r, unsigned char g, unsigned char b);
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
