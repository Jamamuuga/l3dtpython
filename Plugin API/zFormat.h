#pragma once
#include "zvar.h"

class CzFormat :
	public CzVar
{
public:
	CzFormat(void);
	~CzFormat(void);

	bool	Create(const char* lpMapName, const char* lpLongName, const char* lpFileExt, const char* lpNativeProgramName);
	bool	CreateGeneric(long MapTypeID, const char* lpLongName, const char* lpFileExt, const char* lpNativeProgramName);
	bool	GetByExt(const char* lpMapName, long MapTypeID, const char* lpFileExt);
	bool	GetByExt2(ZMAP hMap, const char* lpFileExt);
	bool	GetActiveFormat(const char* lpMapName, long MapTypeID);

	bool	SetFlags(bool Native, bool Mosaic);
	bool	SetInfoStr(const char* lpInfoStr);
	const char*	GetExt();
	ZLIST	GetOptionList();
	bool	GetOptionValue(const char* lpOptionName, long VarID, void* pValue);
	bool	SetOptionValue(const char* lpOptionName, long VarID, void* pValue);
	bool	IsMosaic();
	bool	IsNative();
};
