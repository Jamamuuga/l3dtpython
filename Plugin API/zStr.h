#pragma once
#include "zvar.h"

class CzStr :
	public CzVar
{
public:
	CzStr(void);
	~CzStr(void);

	bool Create(const char* lpVarName = 0);

	const char* GetText();
	bool SetText(const char* lpTextStr);

	int GetLength();
	int Compare(const char* lpText);
	int CompareNoCase(const char* lpText);

	char GetAt(int index);

	//Cast-to-const char* operator
	operator const char* () {
		return GetText();
	}
	//Cast-to-char* operator
	operator char* () {
		return (char*)GetText();
	}

	// assignment operator
	bool operator = (const char* lpTextStr) {
		return SetText(lpTextStr);
	}

	// index operator
    char operator [] (int index) {
        return GetAt(index);
    } 
};
