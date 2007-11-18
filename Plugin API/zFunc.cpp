#include "zfunc.h"
#include "ExtAPI.h"

extern CExtAPI theAPI;

CzFunc::CzFunc(void) {
}

CzFunc::~CzFunc(void) {
}

bool CzFunc::LoadFunc(const char* lpFnName, long rvalVarID, ZLIST hArgList) {
	return Attach(theAPI.zeofunc_LoadFunc(lpFnName, rvalVarID, hArgList));
}
bool CzFunc::LoadFuncEx(const char* lpFnName, const char* lpExportName, long rvalVarID, ZLIST hArgList) {
	return Attach(theAPI.zeofunc_LoadFuncEx(lpFnName, lpExportName, rvalVarID, hArgList));
}
bool CzFunc::GetFunc(const char* lpFnName) {
	return Attach(theAPI.zeofunc_GetFunc(lpFnName));
}
long CzFunc::GetReturnTypeID() {
	if(!m_hVar)	return 0;

	return theAPI.zeofunc_GetReturnTypeID(m_hVar);
}
bool CzFunc::GetArgListPrototype(ZLIST hArgList) {
	if(!m_hVar)	return false;

	return theAPI.zeofunc_GetArgListPrototype(m_hVar, hArgList);
}
ZVAR CzFunc::Execute(ZLIST hArgList) {
	if(!m_hVar)	return 0;

	bool rval = false;

	if(!hArgList)
		hArgList = m_args.GetZVAR();

	ZVAR hRval = m_rval.GetZVAR();

	if(!theAPI.zeofunc_Execute2(m_hVar, hArgList, &hRval)) {
		return false;
	}
	
	return hRval;
}
bool CzFunc::Execute2(ZLIST hArgList, ZVAR* ppRval) {

	if(!m_hVar)	
		return false;

	bool rval = false;

	if(!hArgList)
		hArgList = m_args.GetZVAR();

	ZVAR hRval = m_rval.GetZVAR();

	if(!theAPI.zeofunc_Execute2(m_hVar, hArgList, &hRval)) {
		return false;
	}

	if(ppRval) {
		*ppRval = hRval;
	}
	
	return true;
}
bool CzFunc::ExecuteThreaded(ZLIST hArgList, bool DeleteArgs, long ThreadPriority) {
	if(!m_hVar)	return false;

	if(!hArgList)
			return theAPI.zeofunc_ExecuteThreaded(m_hVar, m_args.GetZVAR(), false, ThreadPriority);
	else	return theAPI.zeofunc_ExecuteThreaded(m_hVar, hArgList, DeleteArgs, ThreadPriority);
}

bool CzFunc::Attach(ZVAR hVar) {
	if(!CzVar::Attach(hVar))	return false;

	if(!IsType(VarID_ZeoFunc)) {
		Delete();
		return false;
	}

	if(!GetArgListPrototype(m_args.GetZVAR())) {
		Delete();
		return false;
	}

	return true;
}