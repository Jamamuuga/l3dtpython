#pragma once
#include "zvar.h"

class CzList :
	public CzVar
{
public:
	CzList(void);
	~CzList(void);

	bool Create(const char* lpVarName = 0);

	long nItems();
	ZVAR CreateItem(long VarID, const char* lpVarName);
	ZVAR GetOrCreateItem(long VarID, const char* lpVarName);
	ZVAR GetItem(long index);
	ZVAR GetItem(const char* lpVarName);
	bool DelItem(long index);
	bool DelItem(const char* lpVarName);
	bool DelAll();

	bool GetItemValue(const char* lpItemName, long VarID, void* pValue);
	bool SetItemValue(const char* lpItemName, long VarID, void* pValue);

	bool GetItemValue(long index, long VarID, void* pValue);
	bool SetItemValue(long index, long VarID, void* pValue);

	const char* GetItemName(int index);

	bool Sort(long From, long To);
	bool Sort(const char* lpItemName, long To);
};
