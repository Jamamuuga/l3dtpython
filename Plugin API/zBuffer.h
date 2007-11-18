#pragma once
#include "zvar.h"

class CzBuffer :
	public CzVar
{
public:
	CzBuffer(void);
	~CzBuffer(void);

	bool Create(const char* lpVarName = 0);

	bool	Init(long nItems, long ItemSize);
	bool	Free();
	long	nItems();
	long	MemSize();
	long	ItemSize();
	void*	GetPtr();
	bool	GetValue(long index, void* pValue);
	bool	SetValue(long index, void* pValue);
};
