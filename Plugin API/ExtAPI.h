#pragma once


//#ifdef _MSC_VER
//	#include "afx.h"
//#else
//	#include "windows.h"
//#endif

#include "extapi_defines.h"

// app function handle defs

typedef FARPROC (__stdcall* LPFNAPI_app_GetFuncHandle)(void* hID, const char* lpFuncHandle);
typedef void (__stdcall* LPFNAPI_app_ReportError)(void* hID, const char* lpErrorStr);

// var function handle defs

typedef ZVAR (__stdcall* LPFNAPI_var_Create)(void* hID, long VarID, const char* lpVarName);
typedef ZVAR (__stdcall* LPFNAPI_var_CreateTemp)(void* hID, long VarID);
typedef bool (__stdcall* LPFNAPI_var_Delete)(void* hID, ZVAR hVar);
typedef bool (__stdcall* LPFNAPI_var_Rename)(void* hID, ZVAR hVar, const char* lpNewName);
typedef ZVAR (__stdcall* LPFNAPI_var_GetVar)(void* hID, const char* lpVarName);
typedef const char* (__stdcall* LPFNAPI_var_GetName)(void* hID, ZVAR hVar);
typedef long (__stdcall* LPFNAPI_var_GetTypeID)(void* hID, ZVAR hVar);
typedef bool (__stdcall* LPFNAPI_var_IsType)(void* hID, ZVAR hVar, long VarID);
typedef bool (__stdcall* LPFNAPI_var_GetValue)(void* hID, ZVAR hVar, void* pValue);
typedef bool (__stdcall* LPFNAPI_var_SetValue)(void* hID, ZVAR hVar, void* pValue);
typedef bool (__stdcall* LPFNAPI_var_GetValueEx)(void* hID, ZVAR hVar, long VarID, void* pValue);
typedef bool (__stdcall* LPFNAPI_var_SetValueEx)(void* hID, ZVAR hVar, long VarID, void* pValue);
typedef bool (__stdcall* LPFNAPI_var_CopyValue)(void* hID, ZVAR hVarDest, ZVAR hVarSrc);
typedef bool (__stdcall* LPFNAPI_var_SetVarRef)(void* hID, ZVAR hPtrVar, ZVAR hSrcVar);
typedef bool (__stdcall* LPFNAPI_var_EditUI)(void* hID, ZVAR hVar, const char* lpPrompt);
typedef void* (__stdcall* LPFNAPI_var_GetDataPtr)(void* hID, ZVAR hVar);

// type function handle defs

typedef long (__stdcall* LPFNAPI_type_GetTypeID)(void* hID, const char* lpTypeName);
typedef bool (__stdcall* LPFNAPI_type_GetTypeName)(void* hID, long VarID, ZVAR hStringVar);

// string function handle defs

typedef const char* (__stdcall* LPFNAPI_str_GetText)(void* hID, ZVAR hStr);
typedef bool (__stdcall* LPFNAPI_str_SetText)(void* hID, ZVAR hStr, const char* lpText);

// list function handle defs

typedef long (__stdcall* LPFNAPI_list_nItems)(void* hID, ZLIST hList);
typedef ZVAR (__stdcall* LPFNAPI_list_CreateItem)(void* hID, ZLIST hList, long VarID, const char* lpVarName);
typedef ZVAR (__stdcall* LPFNAPI_list_GetItemI)(void* hID, ZLIST hList, long index);
typedef ZVAR (__stdcall* LPFNAPI_list_GetItemA)(void* hID, ZLIST hList, const char* lpVarName);
typedef bool (__stdcall* LPFNAPI_list_DelItemI)(void* hID, ZLIST hList, long index);
typedef bool (__stdcall* LPFNAPI_list_DelItemA)(void* hID, ZLIST hList, const char* lpVarName);
typedef bool (__stdcall* LPFNAPI_list_DelAll)(void* hID, ZLIST hList);
typedef bool (__stdcall* LPFNAPI_list_SortI)(void* hID, ZLIST hList, long From, long To);
typedef bool (__stdcall* LPFNAPI_list_SortA)(void* hID, ZLIST hList, const char* lpItemName, long To);

// map function handle defs

typedef bool (__stdcall* LPFNAPI_map_Init)(void* hID, ZMAP hMap, long nx, long ny, long MapTypeID, float HorizScale, bool WrapFlag);
typedef bool (__stdcall* LPFNAPI_map_Free)(void* hID, ZMAP hMap);
typedef long (__stdcall* LPFNAPI_map_GetPixelSize)(void* hID, ZMAP hMap);
typedef bool (__stdcall* LPFNAPI_map_GetWrapFlag)(void* hID, ZMAP hMap);
typedef bool (__stdcall* LPFNAPI_map_SetWrapFlag)(void* hID, ZMAP hMap, bool WrapFlag);
typedef bool (__stdcall* LPFNAPI_map_GetBusyFlag)(void* hID, ZMAP hMap);
typedef bool (__stdcall* LPFNAPI_map_SetBusyFlag)(void* hID, ZMAP hMap, bool BusyFlag);
typedef long (__stdcall* LPFNAPI_map_GetMapType)(void* hID, ZMAP hMap);
typedef long (__stdcall* LPFNAPI_map_GetWidth)(void* hID, ZMAP hMap);
typedef long (__stdcall* LPFNAPI_map_GetHeight)(void* hID, ZMAP hMap);
typedef bool (__stdcall* LPFNAPI_map_GetPixel)(void* hID, ZMAP hMap, long x, long y, void* pValue);
typedef bool (__stdcall* LPFNAPI_map_SetPixel)(void* hID, ZMAP hMap, long x, long y, void* pValue);
typedef bool (__stdcall* LPFNAPI_map_GetMinMaxAlt)(void* hID, ZMAP hMap, float& minval, float& maxval);
typedef bool (__stdcall* LPFNAPI_map_SetMinMaxAlt)(void* hID, ZMAP hMap, float& minval, float& maxval);
typedef float (__stdcall* LPFNAPI_map_GetHorizScale)(void* hID, ZMAP hMap);
typedef bool (__stdcall* LPFNAPI_map_GetMosaicFlag)(void* hID, ZMAP hMap);
typedef long (__stdcall* LPFNAPI_map_GetMosaicTileSize)(void* hID, ZMAP hMap);
typedef long (__stdcall* LPFNAPI_map_GetMosaicTilesX)(void* hID, ZMAP hMap);
typedef long (__stdcall* LPFNAPI_map_GetMosaicTilesY)(void* hID, ZMAP hMap);
typedef bool (__stdcall* LPFNAPI_map_GetFlag)(void* hID, ZMAP hMap, long FlagID);
typedef bool (__stdcall* LPFNAPI_map_SetFlag)(void* hID, ZMAP hMap, long FlagID, bool FlagValue);
typedef ZLIST (__stdcall* LPFNAPI_map_GetSettingsList)(void* hID, ZMAP hMap);
typedef bool (__stdcall* LPFNAPI_map_SaveFile)(void* hID, ZMAP hMap, const char* lpFileName, ZFORMAT hFormat, bool SetFlags, bool ShowProgress);
typedef bool (__stdcall* LPFNAPI_map_LoadFile)(void* hID, ZMAP hMap, const char* lpFileName, long MapTypeID, ZFORMAT hFormat, bool SetFlags, bool ShowProgress);
typedef bool (__stdcall* LPFNAPI_map_GetNameInProject)(void* hID, ZMAP hMap, ZVAR hStr);
typedef bool (__stdcall* LPFNAPI_map_InitMosaic)(void* hID, ZMAP hMap, long nx, long ny, long MapTypeID, float HorizScale, bool WrapFlag, const char* lpMosaicFileName, long TileSize, ZFORMAT hFormat, const char* lpProjMapName);
typedef bool (__stdcall* LPFNAPI_map_LoadMosaic)(void* hID, ZMAP hMap, const char* lpMosaicFileName);
typedef bool (__stdcall* LPFNAPI_map_SaveMosaic)(void* hID, ZMAP hMap);
typedef ZFORMAT (__stdcall* LPFNAPI_map_GetFormat)(void* hID, ZMAP hMap);
typedef bool  (__stdcall* LPFNAPI_map_SetFormat)(void* hID, ZMAP hMap, ZFORMAT hFormat);
typedef const char* (__stdcall* LPFNAPI_map_GetFilename)(void* hID, ZMAP hMap);
typedef bool (__stdcall* LPFNAPI_map_CombineMosaic)(void* hID, ZMAP hMap);
typedef bool (__stdcall* LPFNAPI_map_SplitToMosaic)(void* hID, ZMAP hMap, const char* lpMosaicFileName, long TileSize, ZFORMAT hFormat, const char* lpProjMapName);
typedef bool (__stdcall* LPFNAPI_map_SaveMosaicAs)(void* hID, ZMAP hMap, const char* lpFileName);
typedef bool (__stdcall* LPFNAPI_map_ExportMap)(void* hID, ZMAP hMap, const char* lpFileName, ZFORMAT hFormat, long nx, long ny);
typedef bool (__stdcall* LPFNAPI_map_ExportMosaic)(void* hID, ZMAP hMap, const char* lpFileName, ZFORMAT hFormat, long nx, long ny, long TileSize, const char* lpProjMapName);
typedef void*	(__stdcall* LPFNAPI_map_GetDataPtr)(void* hID, ZMAP hMap);
typedef void*	(__stdcall* LPFNAPI_map_GetMosaicTile)(void* hID, ZMAP hMap, long tx, long ty);

// mosaic tile function defs

typedef bool (__stdcall* LPFNAPI_tile_GetMinMaxAlt)(void* hID, void* hTile, float& minval, float& maxval);
typedef bool (__stdcall* LPFNAPI_tile_GetPixel)(void* hID, void* hTile, long x, long y, void* pValue);
typedef bool (__stdcall* LPFNAPI_tile_SetPixel)(void* hID, void* hTile, long x, long y, void* pValue);
typedef bool (__stdcall* LPFNAPI_tile_GetTileCoords)(void* hID, void* hTile, long& x, long& y);
typedef bool (__stdcall* LPFNAPI_tile_SetLock)(void* hID, void* hTile, bool LockState);
typedef void* (__stdcall* LPFNAPI_tile_GetDataPtr)(void* hID, void* hTile);

// format function handle defs

typedef ZFORMAT (__stdcall* LPFNAPI_format_Create)(void* hID, const char* lpMapName, const char* lpLongName, const char* lpFileExt, const char* lpNativeProgramName);
typedef ZFORMAT (__stdcall* LPFNAPI_format_CreateGeneric)(void* hID, long MapTypeID, const char* lpLongName, const char* lpFileExt, const char* lpNativeProgramName);
typedef bool (__stdcall* LPFNAPI_format_SetFlags)(void* hID, ZFORMAT hFormat, bool Native, bool Mosaic);
typedef bool (__stdcall* LPFNAPI_format_SetInfoStr)(void* hID, ZFORMAT hFormat, const char* lpInfoStr);
typedef const char* (__stdcall* LPFNAPI_format_GetExt)(void* hID, ZFORMAT hFormat);
typedef ZLIST (__stdcall* LPFNAPI_format_GetOptionList)(void* hID, ZFORMAT hFormat);
typedef bool (__stdcall* LPFNAPI_format_GetOptionValue)(void* hID, ZFORMAT hFormat, const char* lpOptionName, long VarID, void* pValue);
typedef bool (__stdcall* LPFNAPI_format_SetOptionValue)(void* hID, ZFORMAT hFormat, const char* lpOptionName, long VarID, void* pValue);
typedef ZFORMAT (__stdcall* LPFNAPI_format_GetFormatByExt)(void* hID, const char* lpMapName, long MapTypeID, const char* lpFileExt);
typedef ZLIST (__stdcall* LPFNAPI_format_GetFormatList)(void* hID, const char* lpMapName, long MapTypeID);
typedef bool (__stdcall* LPFNAPI_format_IsMosaic)(void* hID, ZFORMAT hFormat);
typedef bool (__stdcall* LPFNAPI_format_IsNative)(void* hID, ZFORMAT hFormat);


// prog box function handle defs

typedef bool (__stdcall* LPFNAPI_progbox_ShowWnd)(void* hID, ZVAR hProgWnd);
typedef bool (__stdcall* LPFNAPI_progbox_HideWnd)(void* hID, ZVAR hProgWnd);
typedef bool (__stdcall* LPFNAPI_progbox_SetTitle)(void* hID, ZVAR hProgWnd, const char* lpTitleText);
typedef bool (__stdcall* LPFNAPI_progbox_SetProgress)(void* hID, ZVAR hProgWnd, __int64 p, __int64 pmax);

// combo box function handle defs

typedef bool (__stdcall* LPFNAPI_combosel_SetOptions)(void* hID, ZVAR hComboSel, const char* lpOptionsStr);
typedef const char* (__stdcall* LPFNAPI_combosel_GetOptions)(void* hID, ZVAR hComboSel);
typedef bool (__stdcall* LPFNAPI_combosel_SetCurSel)(void* hID, ZVAR hComboSel, const char* lpCurSelStr);
typedef const char* (__stdcall* LPFNAPI_combosel_GetCurSel)(void* hID, ZVAR hComboSel);

// buffer function handle defs

typedef bool (__stdcall* LPFNAPI_buffer_Init)(void* hID, ZVAR hBuf, long nItems, long ItemSize);
typedef bool (__stdcall* LPFNAPI_buffer_Free)(void* hID, ZVAR hBuf);
typedef long (__stdcall* LPFNAPI_buffer_nItems)(void* hID, ZVAR hBuf);
typedef long (__stdcall* LPFNAPI_buffer_MemSize)(void* hID, ZVAR hBuf);
typedef long (__stdcall* LPFNAPI_buffer_ItemSize)(void* hID, ZVAR hBuf);
typedef void* (__stdcall* LPFNAPI_buffer_GetPtr)(void* hID, ZVAR hBuf);
typedef bool (__stdcall* LPFNAPI_buffer_GetValue)(void* hID, ZVAR hBuf, long index, void* pValue);
typedef bool (__stdcall* LPFNAPI_buffer_SetValue)(void* hID, ZVAR hBuf, long index, void* pValue);

// view function handle defs

typedef bool (__stdcall* LPFNAPI_view_ShowMap)(void* hID, const char* lpProjMapName);
typedef ZMAP (__stdcall* LPFNAPI_view_GetActiveMap)(void* hID);
typedef bool (__stdcall* LPFNAPI_view_GetSelectedArea)(void* hID, ZLIST hCoordsList);

// file/dir functions

typedef bool (__stdcall* LPFNAPI_file_GetExt)(void* hID, ZVAR hStr, const char* lpFileName);
typedef bool (__stdcall* LPFNAPI_file_GetFilenameNoExt)(void* hID, ZVAR hStr, const char* lpFileName);
typedef bool (__stdcall* LPFNAPI_file_GetDir)(void* hID, ZVAR hStr, const char* lpFileName);
typedef bool (__stdcall* LPFNAPI_file_GetFilenameNoDir)(void* hID, ZVAR hStr, const char* lpFileName);
typedef bool (__stdcall* LPFNAPI_file_FileExists)(void* hID, const char* lpFileName);

// extension functions

typedef ZVAR (__stdcall* LPFNAPI_zeofunc_LoadFunc)(void* hID, const char* lpFnName, long rvalVarID, ZLIST hArgList);
typedef ZVAR (__stdcall* LPFNAPI_zeofunc_LoadFuncEx)(void* hID, const char* lpFnName, const char* lpExportName, long rvalVarID, ZLIST hArgList);
typedef ZVAR (__stdcall* LPFNAPI_zeofunc_GetFunc)(void* hID, const char* lpFnName);
typedef long (__stdcall* LPFNAPI_zeofunc_GetReturnTypeID)(void* hID, ZFUNC hFunc);
typedef bool (__stdcall* LPFNAPI_zeofunc_GetArgListPrototype)(void* hID,  ZFUNC hFunc, ZLIST hArgList);
//typedef ZVAR (__stdcall* LPFNAPI_zeofunc_Execute)(void* hID, ZFUNC hFunc, ZLIST hArgList);
typedef bool (__stdcall* LPFNAPI_zeofunc_Execute2)(void* hID, ZFUNC hFunc, ZLIST hArgList, ZVAR *ppRval);
typedef bool (__stdcall* LPFNAPI_zeofunc_ExecuteThreaded)(void* hID, ZFUNC hFunc, ZLIST hArgList, bool DeleteArgs, long ThreadPriority);

// menu functions

typedef bool (__stdcall* LPFNAPI_menu_InsertItem)(void* hID, const char* lpFnName, const char* lpOptionName);
typedef bool (__stdcall* LPFNAPI_menu_InsertItemEx)(void* hID, const char* lpFnName, const char* lpOptionName, bool IsThreaded);




// function for reporting API version to calling app

extern "C" __declspec( dllexport ) const char* __stdcall ExtGetApiVersion(void);


class CExtAPI {
public:
	CExtAPI(void);
	~CExtAPI(void);

	bool InitAPI(FARPROC pFunc, void* hID);

	// app functions

	void	ReportError(const char* lpErrorMessage);

	// var functions

	ZVAR	var_Create(long VarID, const char* lpVarName);
	ZVAR	var_CreateTemp(long VarID);
	bool	var_Delete(ZVAR hVar);
	bool	var_Rename(ZVAR hVar, const char* lpNewName);
	ZVAR	var_GetVar(const char* lpVarName);
	const char*	var_GetName(ZVAR hVar);
	long	var_GetTypeID(ZVAR hVar);
	bool	var_IsType(ZVAR hVar, long VarID);
	bool	var_GetValue(ZVAR hVar, void* pValue);
	bool	var_SetValue(ZVAR hVar, void* pValue);
	bool	var_GetValueEx(ZVAR hVar, long VarID, void* pValue);
	bool	var_SetValueEx(ZVAR hVar, long VarID, void* pValue);
	bool	var_CopyValue(ZVAR hVarDest, ZVAR hVarSrc);
	bool	var_SetVarRef(ZVAR hPtrVar, ZVAR hSrcVar);
	bool	var_EditUI(ZVAR hVar, const char* lpPrompt);
	void*	var_GetDataPtr(ZVAR hVar);

	// type functions

	long	type_GetTypeID(const char* lpTypeName);
	bool	type_GetTypeName(long VarID, ZVAR hStringVar);

	// string functions

	const char*	str_GetText(ZVAR hStr);
	bool	str_SetText(ZVAR hStr, const char* lpText);

	// list functions

	long	list_nItems(ZLIST hList);
	ZLIST	list_CreateItem(ZLIST hList, long VarID, const char* lpVarName);
	ZLIST	list_GetItemI(ZLIST hList, long index);
	ZLIST	list_GetItemA(ZLIST hList, const char* lpVarName);
	bool	list_DelItemI(ZLIST hList, long index);
	bool	list_DelItemA(ZLIST hList, const char* lpVarName);
	bool	list_DelAll(ZLIST hList);
	bool	list_SortI(ZLIST hList, long From, long To);
	bool	list_SortA(ZLIST hList, const char* lpItemName, long To);

	// map functions

	bool	map_Init(ZMAP hMap, long nx, long ny, long MapTypeID, float HorizScale, bool WrapFlag);
	bool	map_Free(ZMAP hMap);
	long	map_GetMapType(ZMAP hMap);
	long	map_GetPixelSize(ZMAP hMap);
	bool	map_GetWrapFlag(ZMAP hMap);
	bool	map_SetWrapFlag(ZMAP hMap, bool WrapFlag);
	bool	map_GetBusyFlag(ZMAP hMap);
	bool	map_SetBusyFlag(ZMAP hMap, bool BusyFlag);
	long	map_GetWidth(ZMAP hMap);
	long	map_GetHeight(ZMAP hMap);
	bool	map_GetPixel(ZMAP hMap, long x, long y, void* pValue);
	bool	map_SetPixel(ZMAP hMap, long x, long y, void* pValue);
	bool	map_GetMinMaxAlt(ZMAP hMap, float& minval, float& maxval);
	bool	map_SetMinMaxAlt(ZMAP hMap, float& minval, float& maxval);
	float	map_GetHorizScale(ZMAP hMap);
	bool	map_GetMosaicFlag(ZMAP hMap);
	long	map_GetMosaicTileSize(ZMAP hMap);
	long	map_GetMosaicTilesX(ZMAP hMap);
	long	map_GetMosaicTilesY(ZMAP hMap);
	bool	map_GetFlag(ZMAP hMap, long FlagID);
	bool	map_SetFlag(ZMAP hMap, long FlagID, bool FlagValue);
	ZLIST	map_GetSettingsList(ZMAP hMap);
	bool	map_SaveFile(ZMAP hMap, const char* lpFileName, ZFORMAT hFormat, bool SetFlags, bool ShowProgress);
	bool	map_LoadFile(ZMAP hMap, const char* lpFileName, long MapTypeID, ZFORMAT hFormat, bool SetFlags, bool ShowProgress);
	bool	map_GetNameInProject(ZMAP hMap, ZVAR hStr);
	bool	map_InitMosaic(ZMAP hMap, long nx, long ny, long MapTypeID, float HorizScale, bool WrapFlag, const char* lpMosaicFileName, long TileSize, ZFORMAT hFormat, const char* lpProjMapName);
	bool	map_LoadMosaic(ZMAP hMap, const char* lpMosaicFileName);
	bool	map_SaveMosaic(ZMAP hMap);
	ZFORMAT map_GetFormat(ZMAP hMap);
	bool	map_SetFormat(ZMAP hMap, ZFORMAT hFormat);
	const char*	map_GetFilename(ZMAP hMap);
	bool	map_CombineMosaic(ZMAP hMap);
	bool	map_SplitToMosaic(ZMAP hMap, const char* lpMosaicFileName, long TileSize, ZFORMAT hFormat, const char* lpProjMapName);
	bool	map_SaveMosaicAs(ZMAP hMap, const char* lpFileName);
	bool	map_ExportMap(ZMAP hMap, const char* lpFileName, ZFORMAT hFormat, long nx, long ny);
	bool	map_ExportMosaic(ZMAP hMap, const char* lpFileName, ZFORMAT hFormat, long nx, long ny, long TileSize, const char* lpProjMapName);
	void*	map_GetDataPtr(ZMAP hMap);
	void*	map_GetMosaicTile(ZMAP hMap, long tx, long ty);

	// mosaic tile functions

	bool	tile_GetMinMaxAlt(void* hTile, float& minval, float& maxval);
	bool	tile_GetPixel(void* hTile, long x, long y, void* pValue);
	bool	tile_SetPixel(void* hTile, long x, long y, void* pValue);
	bool	tile_GetTileCoords(void* hTile, long& x, long& y);
	bool	tile_SetLock(void* hTile, bool LockState);
	void*	tile_GetDataPtr(void* hTile);

	//format functions

	ZFORMAT format_Create(const char* lpMapName, const char* lpLongName, const char* lpFileExt, const char* lpNativeProgramName);
	ZFORMAT format_CreateGeneric(long MapTypeID, const char* lpLongName, const char* lpFileExt, const char* lpNativeProgramName);
	bool	format_SetFlags(ZFORMAT hFormat, bool Native, bool Mosaic);
	bool	format_SetInfoStr(ZFORMAT hFormat, const char* lpInfoStr);
	const char*	format_GetExt(ZFORMAT hFormat);
	ZLIST	format_GetOptionList(ZFORMAT hFormat);
	bool	format_GetOptionValue(ZFORMAT hFormat, const char* lpOptionName, long VarID, void* pValue);
	bool	format_SetOptionValue(ZFORMAT hFormat, const char* lpOptionName, long VarID, void* pValue);
	ZFORMAT	format_GetFormatByExt(const char* lpMapName, long MapTypeID, const char* lpFileExt);
	ZFORMAT format_GetFormatByExt2(ZMAP hMap, const char* lpFileExt);
	ZLIST	format_GetFormatList(const char* lpMapName, long MapTypeID);
	ZLIST	format_GetFormatList2(ZMAP hMap);
	bool	format_IsMosaic(ZFORMAT hFormat);
	bool	format_IsNative(ZFORMAT hFormat);
	ZFORMAT format_GetActiveFormat(const char* lpMapName, long MapTypeID);	// zeofunc wrapper

	// prog box functions

	bool progbox_ShowWnd(ZVAR hProgWnd);
	bool progbox_HideWnd(ZVAR hProgWnd);
	bool progbox_SetTitle(ZVAR hProgWnd, const char* lpTitleText);
	bool progbox_SetProgress(ZVAR hProgWnd, __int64 p, __int64 pmax);

	// combo box functions

	bool	combosel_SetOptions(ZVAR hComboSel, const char* lpOptionsStr);
	const char*	combosel_GetOptions(ZVAR hComboSel);
	bool	combosel_SetCurSel(ZVAR hComboSel, const char* lpCurSelStr);
	const char*	combosel_GetCurSel(ZVAR hComboSel);

	// project functions

	bool	project_GetHeightfieldRange(float& minval, float& maxval);	// zeofunc wrapper
	ZMAP	project_GetMap(const char* lpMapName);							// zeofunc wrapper
	const char*	project_GetProjectFilename();								// zeofunc wrapper
	ZLIST	project_GetSettingsList();									// zeofunc wrapper

	// view functions

	bool	view_ShowMap(const char* lpProjMapName);
	ZMAP	view_GetActiveMap();
	bool	view_GetSelectedArea(ZLIST hCoordsList);

	// file/dir functions

	bool	file_GetExt(ZVAR hStr, const char* lpFileName);
	bool	file_GetFilenameNoExt(ZVAR hStr, const char* lpFileName);
	bool	file_GetDir(ZVAR hStr, const char* lpFileName);
	bool	file_GetFilenameNoDir(ZVAR hStr, const char* lpFileName);
	bool	file_FileExists(const char* lpFileName);

	// buffer function handle defs

	bool	buffer_Init(ZVAR hBuf, long nItems, long ItemSize);
	bool	buffer_Free(ZVAR hBuf);
	long	buffer_nItems(ZVAR hBuf);
	long	buffer_MemSize(ZVAR hBuf);
	long	buffer_ItemSize(ZVAR hBuf);
	void*	buffer_GetPtr(ZVAR hBuf);
	bool	buffer_GetValue(ZVAR hBuf, long index, void* pValue);
	bool	buffer_SetValue(ZVAR hBuf, long index, void* pValue);

	// extension functions

	ZVAR	zeofunc_LoadFunc(const char* lpFnName, long rvalVarID, ZLIST hArgList);
	ZVAR	zeofunc_LoadFuncEx(const char* lpFnName, const char* lpExportName, long rvalVarID, ZLIST hArgList);
	ZVAR	zeofunc_GetFunc(const char* lpFnName);
	long	zeofunc_GetReturnTypeID(ZFUNC hFunc);
	bool	zeofunc_GetArgListPrototype(ZFUNC hFunc, ZLIST hArgList);
	ZVAR	zeofunc_Execute(ZFUNC hFunc, ZLIST hArgList);
	bool	zeofunc_Execute2(ZFUNC hFunc, ZLIST hArgList, ZVAR* ppRval);
	bool	zeofunc_ExecuteThreaded(ZFUNC hFunc, ZLIST hArgList, bool DeleteArgs, long ThreadPriority);

	// menu functions
	bool	menu_InsertItem(const char* lpFnName, const char* lpOptionName);
	bool	menu_InsertItemEx(const char* lpFnName, const char* lpOptionName, bool IsThreaded);

protected:

	// bootstrapping function

	FARPROC GetFuncHandle(const char* lpFuncName);

	// session ID's

	void* m_hID;

	// app function handles

	LPFNAPI_app_GetFuncHandle	m_lpfnGetFuncHandle;
	LPFNAPI_app_ReportError		m_lpfnReportError;

	// var function handles

	LPFNAPI_var_Create			m_lpfn_var_Create;
	LPFNAPI_var_CreateTemp		m_lpfn_var_CreateTemp;
	LPFNAPI_var_Delete			m_lpfn_var_Delete;
	LPFNAPI_var_Rename			m_lpfn_var_Rename;
	LPFNAPI_var_GetVar			m_lpfn_var_GetVar;
	LPFNAPI_var_GetName			m_lpfn_var_GetName;
	LPFNAPI_var_GetTypeID		m_lpfn_var_GetTypeID;
	LPFNAPI_var_IsType			m_lpfn_var_IsType;
	LPFNAPI_var_GetValue		m_lpfn_var_GetValue;
	LPFNAPI_var_SetValue		m_lpfn_var_SetValue;
	LPFNAPI_var_GetValueEx		m_lpfn_var_GetValueEx;
	LPFNAPI_var_SetValueEx		m_lpfn_var_SetValueEx;
	LPFNAPI_var_CopyValue		m_lpfn_var_CopyValue;
	LPFNAPI_var_SetVarRef		m_lpfn_var_SetVarRef;
	LPFNAPI_var_EditUI			m_lpfn_var_EditUI;
	LPFNAPI_var_GetDataPtr		m_lpfn_var_GetDataPtr;

	// type function handles

	LPFNAPI_type_GetTypeID		m_lpfn_type_GetTypeID;
	LPFNAPI_type_GetTypeName	m_lpfn_type_GetTypeName;

	// string function handles

	LPFNAPI_str_GetText			m_lpfn_str_GetText;
	LPFNAPI_str_SetText			m_lpfn_str_SetText;

	// list function handles

	LPFNAPI_list_nItems			m_lpfn_list_nItems;
	LPFNAPI_list_CreateItem		m_lpfn_list_CreateItem;
	LPFNAPI_list_GetItemI		m_lpfn_list_GetItemI;
	LPFNAPI_list_GetItemA		m_lpfn_list_GetItemA;
	LPFNAPI_list_DelItemI		m_lpfn_list_DelItemI;
	LPFNAPI_list_DelItemA		m_lpfn_list_DelItemA;
	LPFNAPI_list_DelAll			m_lpfn_list_DelAll;
	LPFNAPI_list_SortI			m_lpfn_list_SortI;
	LPFNAPI_list_SortA			m_lpfn_list_SortA;

	// map function handles

	LPFNAPI_map_Init			m_lpfn_map_Init;
	LPFNAPI_map_Free			m_lpfn_map_Free;
	LPFNAPI_map_GetMapType		m_lpfn_map_GetMapType;
	LPFNAPI_map_GetPixelSize	m_lpfn_map_GetPixelSize;
	LPFNAPI_map_GetWrapFlag		m_lpfn_map_GetWrapFlag;
	LPFNAPI_map_SetWrapFlag		m_lpfn_map_SetWrapFlag;
	LPFNAPI_map_GetBusyFlag		m_lpfn_map_GetBusyFlag;
	LPFNAPI_map_SetBusyFlag		m_lpfn_map_SetBusyFlag;
	LPFNAPI_map_GetWidth		m_lpfn_map_GetWidth;
	LPFNAPI_map_GetHeight		m_lpfn_map_GetHeight;
	LPFNAPI_map_GetPixel		m_lpfn_map_GetPixel;
	LPFNAPI_map_SetPixel		m_lpfn_map_SetPixel;
	LPFNAPI_map_GetMinMaxAlt	m_lpfn_map_GetMinMaxAlt;
	LPFNAPI_map_SetMinMaxAlt	m_lpfn_map_SetMinMaxAlt;
	LPFNAPI_map_GetHorizScale	m_lpfn_map_GetHorizScale;
	LPFNAPI_map_GetMosaicFlag		m_lpfn_map_GetMosaicFlag;
	LPFNAPI_map_GetMosaicTileSize	m_lpfn_map_GetMosaicTileSize;
	LPFNAPI_map_GetMosaicTilesX		m_lpfn_map_GetMosaicTilesX;
	LPFNAPI_map_GetMosaicTilesY		m_lpfn_map_GetMosaicTilesY;
	LPFNAPI_map_GetFlag				m_lpfn_map_GetFlag;
	LPFNAPI_map_SetFlag				m_lpfn_map_SetFlag;
	LPFNAPI_map_GetSettingsList		m_lpfn_map_GetSettingsList;
	LPFNAPI_map_SaveFile			m_lpfn_map_SaveFile;
	LPFNAPI_map_LoadFile			m_lpfn_map_LoadFile;
	LPFNAPI_map_GetNameInProject	m_lpfn_map_GetNameInProject;
	LPFNAPI_map_InitMosaic			m_lpfn_map_InitMosaic;
	LPFNAPI_map_LoadMosaic			m_lpfn_map_LoadMosaic;
	LPFNAPI_map_SaveMosaic			m_lpfn_map_SaveMosaic;
	LPFNAPI_map_GetFormat			m_lpfn_map_GetFormat;
	LPFNAPI_map_SetFormat			m_lpfn_map_SetFormat;
	LPFNAPI_map_GetFilename			m_lpfn_map_GetFilename;
	LPFNAPI_map_CombineMosaic		m_lpfn_map_CombineMosaic;
	LPFNAPI_map_SplitToMosaic		m_lpfn_map_SplitToMosaic;
	LPFNAPI_map_SaveMosaicAs		m_lpfn_map_SaveMosaicAs;
	LPFNAPI_map_ExportMap			m_lpfn_map_ExportMap;
	LPFNAPI_map_ExportMosaic		m_lpfn_map_ExportMosaic;
	LPFNAPI_map_GetDataPtr			m_lpfn_map_GetDataPtr;
	LPFNAPI_map_GetMosaicTile		m_lpfn_map_GetMosaicTile;

	// mosaic tile function handles

	LPFNAPI_tile_GetMinMaxAlt	m_lpfn_tile_GetMinMaxAlt;
	LPFNAPI_tile_GetPixel		m_lpfn_tile_GetPixel;
	LPFNAPI_tile_SetPixel		m_lpfn_tile_SetPixel;
	LPFNAPI_tile_GetTileCoords	m_lpfn_tile_GetTileCoords;
	LPFNAPI_tile_SetLock		m_lpfn_tile_SetLock;
	LPFNAPI_tile_GetDataPtr		m_lpfn_tile_GetDataPtr;

	// format function handles

	LPFNAPI_format_Create			m_lpfn_format_Create;
	LPFNAPI_format_CreateGeneric	m_lpfn_format_CreateGeneric;
	LPFNAPI_format_SetFlags			m_lpfn_format_SetFlags;
	LPFNAPI_format_SetInfoStr		m_lpfn_format_SetInfoStr;
	LPFNAPI_format_GetExt			m_lpfn_format_GetExt;
	LPFNAPI_format_GetOptionList	m_lpfn_format_GetOptionList;
	LPFNAPI_format_GetOptionValue	m_lpfn_format_GetOptionValue;
	LPFNAPI_format_SetOptionValue	m_lpfn_format_SetOptionValue;
	LPFNAPI_format_GetFormatByExt	m_lpfn_format_GetFormatByExt;
	LPFNAPI_format_GetFormatList	m_lpfn_format_GetFormatList;
	LPFNAPI_format_IsMosaic			m_lpfn_format_IsMosaic;
	LPFNAPI_format_IsNative			m_lpfn_format_IsNative;

	// prog box function handles

	LPFNAPI_progbox_ShowWnd			m_lpfn_progbox_ShowWnd;
	LPFNAPI_progbox_HideWnd			m_lpfn_progbox_HideWnd;
	LPFNAPI_progbox_SetTitle		m_lpfn_progbox_SetTitle;
	LPFNAPI_progbox_SetProgress		m_lpfn_progbox_SetProgress;

	// combo box function handles

	LPFNAPI_combosel_SetOptions		m_lpfn_combosel_SetOptions;
	LPFNAPI_combosel_GetOptions		m_lpfn_combosel_GetOptions;
	LPFNAPI_combosel_SetCurSel		m_lpfn_combosel_SetCurSel;
	LPFNAPI_combosel_GetCurSel		m_lpfn_combosel_GetCurSel;

	// buffer function handles

	LPFNAPI_buffer_Init			m_lpfn_buffer_Init;
	LPFNAPI_buffer_Free			m_lpfn_buffer_Free;
	LPFNAPI_buffer_nItems		m_lpfn_buffer_nItems;
	LPFNAPI_buffer_MemSize		m_lpfn_buffer_MemSize;
	LPFNAPI_buffer_ItemSize		m_lpfn_buffer_ItemSize;
	LPFNAPI_buffer_GetPtr		m_lpfn_buffer_GetPtr;
	LPFNAPI_buffer_GetValue		m_lpfn_buffer_GetValue;
	LPFNAPI_buffer_SetValue		m_lpfn_buffer_SetValue;

	// view function handles

	LPFNAPI_view_ShowMap					m_lpfn_view_ShowMap;
	LPFNAPI_view_GetActiveMap				m_lpfn_view_GetActiveMap;
	LPFNAPI_view_GetSelectedArea			m_lpfn_view_GetSelectedArea;

	// file/dir function handles

	LPFNAPI_file_GetExt						m_lpfn_file_GetExt;
	LPFNAPI_file_GetFilenameNoExt			m_lpfn_file_GetFilenameNoExt;
	LPFNAPI_file_GetDir						m_lpfn_file_GetDir;
	LPFNAPI_file_GetFilenameNoDir			m_lpfn_file_GetFilenameNoDir;
	LPFNAPI_file_FileExists					m_lpfn_file_FileExists;

	// extension function handles

	LPFNAPI_zeofunc_LoadFunc				m_lpfn_zeofunc_LoadFunc;
	LPFNAPI_zeofunc_LoadFuncEx				m_lpfn_zeofunc_LoadFuncEx;
	LPFNAPI_zeofunc_GetFunc					m_lpfn_zeofunc_GetFunc;
	LPFNAPI_zeofunc_GetReturnTypeID			m_lpfn_zeofunc_GetReturnTypeID;
	LPFNAPI_zeofunc_GetArgListPrototype		m_lpfn_zeofunc_GetArgListPrototype;
	//LPFNAPI_zeofunc_Execute					m_lpfn_zeofunc_Execute;
	LPFNAPI_zeofunc_Execute2				m_lpfn_zeofunc_Execute2;
	LPFNAPI_zeofunc_ExecuteThreaded			m_lpfn_zeofunc_ExecuteThreaded;

	//menu function handles

	LPFNAPI_menu_InsertItem					m_lpfn_menu_InsertItem;
	LPFNAPI_menu_InsertItemEx				m_lpfn_menu_InsertItemEx;
};
