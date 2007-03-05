#pragma once

#include "ExtAPI_defines.h"

class CzVar
{
public:

	CzVar(void);
	CzVar(ZVAR hVar);
	~CzVar(void);

	virtual bool Attach(ZVAR hVar);
	ZVAR GetZVAR();

	bool Create(long VarID, const char* lpVarName = 0);

	bool GetByName(const char* lpVarName);
	
	bool Delete();
	void Release();

	const char* GetName();
	bool Rename(const char* lpNewName);

	long GetTypeID();
	bool GetTypeName(ZVAR hStringVar);
	bool IsType(long VarID);

	bool GetValue(long VarID, void* pValue);
	bool SetValue(long VarID, void* pValue);
	
	bool CopyValue(ZVAR hVarSrc);
	
	bool SetVarRef(ZVAR hSrcVar);
	
	bool EditUI(const char* lpPrompt);

	//Cast-to-ZVAR operator
	operator ZVAR () {
		return GetZVAR();
	}

protected:

	ZVAR m_hVar;
	bool m_AutoDelete;
};
