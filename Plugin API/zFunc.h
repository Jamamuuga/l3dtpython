#pragma once
#include "zvar.h"
#include "zlist.h"

class CzFunc :
	public CzVar
{
public:
	CzFunc(void);
	~CzFunc(void);

	virtual bool Attach(ZVAR hVar);

	bool	LoadFunc(const char* lpFnName, long rvalVarID, ZLIST hArgList);
	bool	LoadFuncEx(const char* lpFnName, const char* lpExportName, long rvalVarID, ZLIST hArgList);
	bool	GetArgListPrototype(ZLIST hArgList);
	bool	GetFunc(const char* lpFnName);
	long	GetReturnTypeID();
	ZVAR	Execute(ZLIST hArgList = NULL); // NULL arg list is interpreted as using the m_args member
	bool	ExecuteThreaded(ZLIST hArgList = NULL, bool DeleteArgs = false, long ThreadPriority = THREAD_PRIORITY_BELOW_NORMAL);

	CzList	m_args;
	CzVar	m_rval;
};
