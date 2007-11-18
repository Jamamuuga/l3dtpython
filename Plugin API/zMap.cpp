#include "zmap.h"
#include "extapi.h"
extern CExtAPI theAPI;

CzMap::CzMap(void) {
	Create(0);
}

CzMap::~CzMap(void) {
}

bool CzMap::Create(const char* lpVarName){
	return CzVar::Create(VarID_map, lpVarName);
}

bool CzMap::Init(long nx, long ny, long MapTypeID, float HorizScale, bool WrapFlag) {
	if(!m_hVar)	return false;

	return theAPI.map_Init(m_hVar, nx, ny, MapTypeID, HorizScale, WrapFlag);
}
bool CzMap::Free() {
	if(!m_hVar)	return false;

	return theAPI.map_Free(m_hVar);
}
long CzMap::GetMapType() {
	if(!m_hVar)	return 0;

	return theAPI.map_GetMapType(m_hVar);
}
long CzMap::GetPixelSize() {
	if(!m_hVar)	return 0;

	return theAPI.map_GetPixelSize(m_hVar);
}
bool CzMap::GetWrapFlag() {
	if(!m_hVar)	return false;

	return theAPI.map_GetWrapFlag(m_hVar);
}
bool CzMap::SetWrapFlag(bool WrapFlag) {
	if(!m_hVar)	return false;

	return theAPI.map_SetWrapFlag(m_hVar, WrapFlag);
}
bool CzMap::GetBusyFlag() {
	if(!m_hVar)	return false;

	return theAPI.map_GetBusyFlag(m_hVar);
}
bool CzMap::SetBusyFlag(bool BusyFlag) {
	if(!m_hVar)	return false;

	return theAPI.map_SetBusyFlag(m_hVar, BusyFlag);
}
long CzMap::nx() {
	if(!m_hVar)	return 0;

	return theAPI.map_GetWidth(m_hVar);
}
long CzMap::ny() {
	if(!m_hVar)	return 0;

	return theAPI.map_GetHeight(m_hVar);
}
__int64 CzMap::nPixels() {
	if(!m_hVar)	return 0;

	return (__int64)nx() * (__int64)ny();
}
bool CzMap::GetPixel(long x, long y, void* pValue) {
	if(!m_hVar)	return false;

	return theAPI.map_GetPixel(m_hVar, x, y, pValue);
}
bool CzMap::GetPixel(__int64 k, void* pValue) {
	if(!m_hVar)	return false;
	
	long tnx = nx();
	if(tnx<=0)	return false;
	long x = (long)(k%(__int64)tnx);
	long y = (long)(k/(__int64)tnx);

	return GetPixel(x, y, pValue);
}
bool CzMap::SetPixel(long x, long y, void* pValue) {
	if(!m_hVar)	return false;

	return theAPI.map_SetPixel(m_hVar, x, y, pValue);
}
bool CzMap::SetPixel(__int64 k, void* pValue) {
	if(!m_hVar)	return false;
	
	long tnx = nx();
	if(tnx<=0)	return false;
	long x = (long)(k%(__int64)tnx);
	long y = (long)(k/(__int64)tnx);

	return SetPixel(x, y, pValue);
}
bool CzMap::GetMinMaxAlt(float& minval, float& maxval) {
	if(!m_hVar)	return false;

	return theAPI.map_GetMinMaxAlt(m_hVar, minval, maxval);
}
bool CzMap::SetMinMaxAlt(float& minval, float& maxval) {
	if(!m_hVar)	return false;

	return theAPI.map_SetMinMaxAlt(m_hVar, minval, maxval);
}
float CzMap::GetHorizScale() {
	if(!m_hVar)	return 1.0; // safe value, avoids div by zerp

	return theAPI.map_GetHorizScale(m_hVar);
}
bool CzMap::GetMosaicFlag() {
	if(!m_hVar)	return false;

	return theAPI.map_GetMosaicFlag(m_hVar);
}
long CzMap::GetMosaicTileSize() {
	if(!m_hVar)	return 0;

	return theAPI.map_GetMosaicTileSize(m_hVar);
}
long CzMap::GetMosaicTilesX() {
	if(!m_hVar)	return 0;

	return theAPI.map_GetMosaicTilesX(m_hVar);
}
long CzMap::GetMosaicTilesY() {
	if(!m_hVar)	return 0;

	return theAPI.map_GetMosaicTilesY(m_hVar);
}
bool CzMap::GetFlag(long FlagID) {
	if(!m_hVar)	return false;

	return theAPI.map_GetFlag(m_hVar, FlagID);
}
bool CzMap::SetFlag(long FlagID, bool FlagValue) {
	if(!m_hVar)	return false;

	return theAPI.map_SetFlag(m_hVar, FlagID, FlagValue);
}
ZLIST CzMap::GetSettingsList() {
	if(!m_hVar)	return 0;

	return theAPI.map_GetSettingsList(m_hVar);
}
bool CzMap::SaveFile(const char* lpFileName, ZFORMAT hFormat, bool SetFlags, bool ShowProgress) {
	if(!m_hVar)	return false;

	return theAPI.map_SaveFile(m_hVar, lpFileName, hFormat, SetFlags, ShowProgress);
}
bool CzMap::LoadFile(const char* lpFileName, long MapTypeID, ZFORMAT hFormat, bool SetFlags, bool ShowProgress) {
	if(!m_hVar)	return false;

	return theAPI.map_LoadFile(m_hVar, lpFileName, MapTypeID, hFormat, SetFlags, ShowProgress);
}
bool CzMap::GetNameInProject(ZVAR hStr) {
	if(!m_hVar)	return false;

	return theAPI.map_GetNameInProject(m_hVar, hStr);
}

bool CzMap::InitMosaic(long nx, long ny, long MapTypeID, float HorizScale, bool WrapFlag, const char* lpMosaicFileName, long TileSize, ZFORMAT hFormat, const char* lpProjMapName) {
	if(!m_hVar)	return false;

	return theAPI.map_InitMosaic(m_hVar, nx, ny, MapTypeID, HorizScale, WrapFlag, lpMosaicFileName, TileSize, hFormat, lpProjMapName);
}
bool CzMap::LoadMosaic(const char* lpMosaicFileName) {
	if(!m_hVar)	return false;

	return theAPI.map_LoadMosaic(m_hVar, lpMosaicFileName);
}
bool CzMap::SaveMosaic() {
	if(!m_hVar)	return false;

	return theAPI.map_SaveMosaic(m_hVar);
}

ZFORMAT CzMap::GetFormat() {
	if(!m_hVar)	return 0;

	return theAPI.map_GetFormat(m_hVar);
}
bool CzMap::SetFormat(ZFORMAT hFormat) {
	if(!m_hVar)	return false;

	return theAPI.map_SetFormat(m_hVar, hFormat);
}
const char* CzMap::GetFilename() {
	if(!m_hVar)	return 0;

	return theAPI.map_GetFilename(m_hVar);
}
bool CzMap::CombineMosaic() {
	if(!m_hVar)	return 0;

	return theAPI.map_CombineMosaic(m_hVar);
}
bool CzMap::SplitToMosaic(const char* lpMosaicFileName, long TileSize, ZFORMAT hFormat, const char* lpProjMapName) {
	if(!m_hVar)	return 0;

	return theAPI.map_SplitToMosaic(m_hVar, lpMosaicFileName, TileSize, hFormat, lpProjMapName);
}
bool CzMap::SaveMosaicAs(const char* lpFileName) {
	if(!m_hVar)	return 0;

	return theAPI.map_SaveMosaicAs(m_hVar, lpFileName);
}
bool CzMap::ExportMap(const char* lpFileName, ZFORMAT hFormat, long nx, long ny) {
	if(!m_hVar)	return 0;

	return theAPI.map_ExportMap(m_hVar, lpFileName, hFormat, nx, ny);
}
bool CzMap::ExportMosaic(const char* lpFileName, ZFORMAT hFormat, long nx, long ny, long TileSize, const char* lpProjMapName) {
	if(!m_hVar)	return 0;

	return theAPI.map_ExportMosaic(m_hVar, lpFileName, hFormat, nx, ny, TileSize, lpProjMapName);
}
void* CzMap::GetDataPtr() {
	if(!m_hVar)	return 0;

	return theAPI.map_GetDataPtr(m_hVar);
}
bool CzMap::LinInterp(double dx, double dy, void* pValue) {
	if(!m_hVar)	return 0;

	return theAPI.map_LinInterp(m_hVar, dx, dy, pValue);
}

bool CzMap::GenMipmaps(long ResStep, long MaxLevel, long TileSize) {
	if(!m_hVar)	return false;

	return theAPI.map_GenMipmaps2(m_hVar, ResStep, MaxLevel, TileSize);
}
bool CzMap::ClearMipmaps() {
	if(!m_hVar)	return false;

	return theAPI.map_ClearMipmaps(m_hVar);
}
ZMAP CzMap::GetMipmapLevel(long MipLevel) {
	if(!m_hVar)	return 0;

	return theAPI.map_GetMipmapLevel(m_hVar, MipLevel);
}
long CzMap::GetMipmapResStep() {
	if(!m_hVar)	return 0;

	return theAPI.map_GetMipmapResStep(m_hVar);
}
long CzMap::GetMipmapMaxLevel() {
	if(!m_hVar)	return 0;

	return theAPI.map_GetMipmapMaxLevel(m_hVar);
}