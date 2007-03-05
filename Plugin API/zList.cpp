#include "zlist.h"

#include "extapi.h"
extern CExtAPI theAPI;


CzList::CzList() {
	Create(NULL);
}

CzList::~CzList(void) {
}

bool CzList::Create(const char* lpVarName) {
	return CzVar::Create(VarID_varlist, lpVarName);
}

long CzList::nItems() {
	if(!m_hVar)	return 0;

	return theAPI.list_nItems(m_hVar);
}
ZVAR CzList::CreateItem(long VarID, const char* lpVarName) {
	if(!m_hVar)	return NULL;

	return theAPI.list_CreateItem(m_hVar, VarID, lpVarName);
}
ZVAR CzList::GetOrCreateItem(long VarID, const char* lpVarName) {
	if(!m_hVar)	return NULL;

	ZVAR TempVar = NULL;

	if(TempVar = GetItem(lpVarName)) {
		// var exists, now check type
		if(theAPI.var_IsType(TempVar, VarID))
				return TempVar;
		else	return false;
	}
	
	return CreateItem(VarID, lpVarName);
}
ZVAR CzList::GetItem(long index) {
	if(!m_hVar)	return NULL;

	return theAPI.list_GetItemI(m_hVar, index);
}
ZVAR CzList::GetItem(const char* lpVarName) {
	if(!m_hVar)	return NULL;

	return theAPI.list_GetItemA(m_hVar, lpVarName);
}
bool CzList::DelItem(long index) {
	if(!m_hVar)	return false;

	return theAPI.list_DelItemI(m_hVar, index);
}
bool CzList::DelItem(const char* lpVarName) {
	if(!m_hVar)	return false;

	return theAPI.list_DelItemA(m_hVar, lpVarName);
}
bool CzList::DelAll() {
	if(!m_hVar)	return false;

	return theAPI.list_DelAll(m_hVar);
}

bool CzList::GetItemValue(const char* lpItemName, long VarID, void* pValue) {
	if(!m_hVar)	return false;

	ZVAR hVar;
	if(!(hVar = theAPI.list_GetItemA(m_hVar, lpItemName)))
		return false;

	return theAPI.var_GetValueEx(hVar, VarID, pValue);

}
bool CzList::GetItemValue(long index, long VarID, void* pValue) {
	if(!m_hVar)	return false;

	ZVAR hVar;
	if(!(hVar = theAPI.list_GetItemI(m_hVar, index)))
		return false;

	return theAPI.var_GetValueEx(hVar, VarID, pValue);
}
bool CzList::SetItemValue(const char* lpItemName, long VarID, void* pValue) {
	if(!m_hVar)	return false;

	ZVAR hVar;
	if(!(hVar = theAPI.list_GetItemA(m_hVar, lpItemName))) {
		if(!(hVar = theAPI.list_CreateItem(m_hVar, VarID, lpItemName)))
			return false;
	}

	return theAPI.var_SetValueEx(hVar, VarID, pValue);
}
bool CzList::SetItemValue(long index, long VarID, void* pValue) {
	if(!m_hVar)	return false;

	ZVAR hVar;
	if(!(hVar = theAPI.list_GetItemI(m_hVar, index)))
		return false;

	return theAPI.var_SetValueEx(hVar, VarID, pValue);
}

const char* CzList::GetItemName(int index) {
	if(!m_hVar)	return NULL;

	ZVAR hVar;
	if(!(hVar = theAPI.list_GetItemI(m_hVar, index)))
		return NULL;

	return theAPI.var_GetName(hVar);
}

bool CzList::Sort(long From, long To) {
	if(!m_hVar)	return NULL;

	return theAPI.list_SortI(m_hVar, From, To);
}
bool CzList::Sort(const char* lpItemName, long To) {
	if(!m_hVar)	return NULL;

	return theAPI.list_SortA(m_hVar, lpItemName, To);
}