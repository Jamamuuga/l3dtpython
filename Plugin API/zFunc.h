#pragma once
#include "zvar.h"
#include "zlist.h"
#include "ExtAPI_defines.h"


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
	ZVAR	Execute(ZLIST hArgList = 0); // 0 arg list is interpreted as using the m_args member
	bool	Execute2(ZLIST hArgList = 0, ZVAR* ppRval = 0);
	bool	ExecuteThreaded(ZLIST hArgList = 0, bool DeleteArgs = false, long ThreadPriority = THREAD_PRIORITY_NORMAL);

	CzList	m_args;
	CzVar	m_rval;
};
