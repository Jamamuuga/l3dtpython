#include "zprogbox.h"
#include "extapi.h"

extern CExtAPI theAPI;

CzProgBox::CzProgBox(void) {
	Create(NULL);
}

CzProgBox::~CzProgBox(void) {
}

bool CzProgBox::Create(const char* lpVarName){
	return CzVar::Create(VarID_ProgBox, lpVarName);
}

bool CzProgBox::ShowWnd() {
	if(!m_hVar)	return false;

	return theAPI.progbox_ShowWnd(m_hVar);
}
bool CzProgBox::HideWnd() {
	if(!m_hVar)	return false;

	return theAPI.progbox_HideWnd(m_hVar);
}
bool CzProgBox::SetTitle(const char* lpTitleText) {
	if(!m_hVar)	return false;

	return theAPI.progbox_SetTitle(m_hVar, lpTitleText);
}
bool CzProgBox::SetProgress(__int64 p, __int64 pmax) {
	if(!m_hVar)	return false;

	return theAPI.progbox_SetProgress(m_hVar, p, pmax);
}