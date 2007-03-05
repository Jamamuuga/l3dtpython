#include "zcombosel.h"
#include "extapi.h"

extern CExtAPI theAPI;

CzComboSel::CzComboSel(void) {
	Create(NULL);
}

CzComboSel::~CzComboSel(void) {
}

bool CzComboSel::Create(const char* lpVarName){
	return CzVar::Create(VarID_ComboSelector, lpVarName);
}

bool CzComboSel::SetOptions(const char* lpOptionsStr) {
	if(!m_hVar)	return false;

	return theAPI.combosel_SetOptions(m_hVar, lpOptionsStr);
}
const char* CzComboSel::GetOptions() {
	if(!m_hVar)	return NULL;

	return theAPI.combosel_GetOptions(m_hVar);
}
bool CzComboSel::SetCurSel(const char* lpCurSelStr) {
	if(!m_hVar)	return false;

	return theAPI.combosel_SetCurSel(m_hVar, lpCurSelStr);
}
const char* CzComboSel::GetCurSel() {
	if(!m_hVar)	return NULL;

	return theAPI.combosel_GetCurSel(m_hVar);
}