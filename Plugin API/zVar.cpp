//#include "StdAfx.h"
#include "zvar.h"
#include "extapi.h"

extern CExtAPI theAPI;

CzVar::CzVar(void) {
	m_hVar = 0;
	m_AutoDelete = false;
}
CzVar::CzVar(ZVAR hVar) {
	m_hVar = hVar;
	m_AutoDelete = false;
}

CzVar::~CzVar(void) {
	if(m_hVar && m_AutoDelete) {
		Delete();
	}
}

bool CzVar::Attach(ZVAR hVar) {

	if(m_hVar && m_AutoDelete) Delete();

	if(!hVar)
		return false;
	
	m_hVar = hVar;
	m_AutoDelete = false;
	return true;
}

ZVAR CzVar::GetZVAR() { return m_hVar; }

bool CzVar::Create(long VarID, const char* lpVarName) {
	if(m_hVar && m_AutoDelete) Delete();

	if(lpVarName)
			m_hVar = theAPI.var_Create(VarID, lpVarName);
	else	m_hVar = theAPI.var_CreateTemp(VarID);

	if(!m_hVar)	return false;

	m_AutoDelete = true;

	return true;
}

bool CzVar::GetByName(const char* lpVarName) {
	if(m_hVar && m_AutoDelete) Delete();

	if(!Attach(theAPI.var_GetVar(lpVarName)))
		return false;

	if(!m_hVar)	
		return false;

	return true;
}

bool CzVar::Delete() {
	if(!m_hVar) return true;

	bool rval = false;
	
	rval = theAPI.var_Delete(m_hVar);
	
	m_hVar = 0;
	return rval;
}
void CzVar::Release() {
	m_hVar = 0;
}

const char* CzVar::GetName() {
	if(!m_hVar)	return 0;

	return theAPI.var_GetName(m_hVar);
}
bool CzVar::Rename(const char* lpNewName) {
	if(!m_hVar)	return false;

	return theAPI.var_Rename(m_hVar, lpNewName);
}

long CzVar::GetTypeID() {
	if(!m_hVar)	return false;

	return theAPI.var_GetTypeID(m_hVar);
}
bool CzVar::GetTypeName(ZVAR hStringVar) {
	if(!m_hVar)	return false;

	return theAPI.type_GetTypeName(GetTypeID(), hStringVar);
}
bool CzVar::IsType(long VarID) {
	if(!m_hVar)	return false;

	return theAPI.var_IsType(m_hVar, VarID);
}

bool CzVar::GetValue(long VarID, void* pValue) {
	if(!m_hVar)	return false;

	return theAPI.var_GetValueEx(m_hVar, VarID, pValue);
}
bool CzVar::SetValue(long VarID, void* pValue) {
	if(!m_hVar)	return false;

	return theAPI.var_SetValueEx(m_hVar, VarID, pValue);
}

bool CzVar::CopyValue(ZVAR hVarSrc) {
	if(!m_hVar)	return false;

	return theAPI.var_CopyValue(m_hVar, hVarSrc);
}

bool CzVar::SetVarRef(ZVAR hSrcVar) {
	if(!m_hVar)	return false;

	return theAPI.var_SetVarRef(m_hVar, hSrcVar);
}

bool CzVar::EditUI(const char* lpPrompt) {
	if(!m_hVar)	return false;

	return theAPI.var_EditUI(m_hVar, lpPrompt);
}