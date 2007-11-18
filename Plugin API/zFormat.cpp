#include "zformat.h"
#include "extapi.h"
extern CExtAPI theAPI;

CzFormat::CzFormat(void) {
}

CzFormat::~CzFormat(void) {
}

bool CzFormat::Create(const char* lpMapName, const char* lpLongName, const char* lpFileExt, const char* lpNativeProgramName) {
	return Attach(theAPI.format_Create(lpMapName, lpLongName, lpFileExt, lpNativeProgramName));
}
bool CzFormat::CreateGeneric(long MapTypeID, const char* lpLongName, const char* lpFileExt, const char* lpNativeProgramName) {
	return Attach(theAPI.format_CreateGeneric(MapTypeID, lpLongName, lpFileExt, lpNativeProgramName));
}
bool CzFormat::GetByExt(const char* lpMapName, long MapTypeID, const char* lpFileExt) {
	return Attach(theAPI.format_GetFormatByExt(lpMapName, MapTypeID, lpFileExt));
}
bool CzFormat::GetByExt2(ZMAP hMap, const char* lpFileExt) {
	return Attach(theAPI.format_GetFormatByExt2(hMap, lpFileExt));
}
bool CzFormat::GetActiveFormat(const char* lpMapName, long MapTypeID) {
	return Attach(theAPI.format_GetActiveFormat(lpMapName, MapTypeID));
}
bool CzFormat::SetFlags(bool Native, bool Mosaic) {
	if(!IsType(VarID_format))	return false;

	return theAPI.format_SetFlags(m_hVar, Native, Mosaic);
}
bool CzFormat::SetInfoStr(const char* lpInfoStr) {
	if(!IsType(VarID_format))	return false;

	return theAPI.format_SetInfoStr(m_hVar, lpInfoStr);
}
const char* CzFormat::GetExt() {
	if(!IsType(VarID_format))	return 0;

	return theAPI.format_GetExt(m_hVar);

}
ZLIST CzFormat::GetOptionList() {
	if(!IsType(VarID_format))	return 0;

	return theAPI.format_GetOptionList(m_hVar);

}
bool CzFormat::GetOptionValue(const char* lpOptionName, long VarID, void* pValue) {
	if(!IsType(VarID_format))	return false;

	return theAPI.format_GetOptionValue(m_hVar, lpOptionName, VarID, pValue);

}
bool CzFormat::SetOptionValue(const char* lpOptionName, long VarID, void* pValue) {
	if(!IsType(VarID_format))	return false;

	return theAPI.format_SetOptionValue(m_hVar, lpOptionName, VarID, pValue);

}
bool CzFormat::IsMosaic() {
	if(!IsType(VarID_format))	return false;

	return theAPI.format_IsMosaic(m_hVar);

}
bool CzFormat::IsNative() {
	if(!IsType(VarID_format))	return false;

	return theAPI.format_IsNative(m_hVar);

}