// include MFC or windows, depending on developer's choice
//#ifdef _MSC_VER
//	#include "afx.h"
//#else
//	#include "windows.h"
//#endif

#include "extapi.h"

// the one and only CExtAPI instance
CExtAPI theAPI;

// function for reporting API version to calling app
extern "C" __declspec( dllexport ) const char* __stdcall ExtGetApiVersion(void) {
	return "2.3";
}


CExtAPI::CExtAPI(void) {

	m_hID = NULL;

	// app functions

	m_lpfnGetFuncHandle = NULL;
	m_lpfnReportError = NULL;

	// var function handles

	m_lpfn_var_Create = NULL;
	m_lpfn_var_CreateTemp = NULL;
	m_lpfn_var_Delete = NULL;
	m_lpfn_var_Rename = NULL;
	m_lpfn_var_GetVar = NULL;
	m_lpfn_var_GetName = NULL;
	m_lpfn_var_GetTypeID = NULL;
	m_lpfn_var_IsType = NULL;
	m_lpfn_var_GetValue = NULL;
	m_lpfn_var_SetValue = NULL;
	m_lpfn_var_GetValueEx = NULL;
	m_lpfn_var_SetValueEx = NULL;
	m_lpfn_var_CopyValue = NULL;
	m_lpfn_var_SetVarRef = NULL;
	m_lpfn_var_EditUI = NULL;
	m_lpfn_var_GetDataPtr = NULL;

	// type function handles

	m_lpfn_type_GetTypeID = NULL;
	m_lpfn_type_GetTypeName = NULL;

	// string function handles

	m_lpfn_str_GetText = NULL;
	m_lpfn_str_SetText = NULL;

	// list function handles

	m_lpfn_list_nItems = NULL;
	m_lpfn_list_CreateItem = NULL;
	m_lpfn_list_GetItemI = NULL;
	m_lpfn_list_GetItemA = NULL;
	m_lpfn_list_DelItemI = NULL;
	m_lpfn_list_DelItemA = NULL;
	m_lpfn_list_DelAll = NULL;
	m_lpfn_list_SortI = NULL;
	m_lpfn_list_SortA = NULL;

	// map functions

	m_lpfn_map_Init = NULL;
	m_lpfn_map_Free = NULL;
	m_lpfn_map_GetMapType = NULL;
	m_lpfn_map_GetPixelSize = NULL;
	m_lpfn_map_GetWrapFlag = NULL;
	m_lpfn_map_SetWrapFlag = NULL;
	m_lpfn_map_GetBusyFlag = NULL;
	m_lpfn_map_SetBusyFlag = NULL;
	m_lpfn_map_GetWidth = NULL;
	m_lpfn_map_GetHeight = NULL;
	m_lpfn_map_GetPixel = NULL;
	m_lpfn_map_SetPixel = NULL;
	m_lpfn_map_GetMinMaxAlt = NULL;
	m_lpfn_map_SetMinMaxAlt = NULL;
	m_lpfn_map_GetHorizScale = NULL;
	m_lpfn_map_GetMosaicFlag = NULL;
	m_lpfn_map_GetMosaicTileSize = NULL;
	m_lpfn_map_GetMosaicTilesX = NULL;
	m_lpfn_map_GetMosaicTilesY = NULL;
	m_lpfn_map_GetFlag = NULL;
	m_lpfn_map_SetFlag = NULL;
	m_lpfn_map_GetSettingsList = NULL;
	m_lpfn_map_SaveFile = NULL;
	m_lpfn_map_LoadFile = NULL;
	m_lpfn_map_GetNameInProject = NULL;
	m_lpfn_map_InitMosaic = NULL;
	m_lpfn_map_LoadMosaic = NULL;
	m_lpfn_map_SaveMosaic = NULL;
	m_lpfn_map_GetFormat = NULL;
	m_lpfn_map_SetFormat = NULL;
	m_lpfn_map_GetFilename = NULL;
	m_lpfn_map_CombineMosaic = NULL;
	m_lpfn_map_SplitToMosaic = NULL;
	m_lpfn_map_SaveMosaicAs = NULL;
	m_lpfn_map_ExportMap = NULL;
	m_lpfn_map_ExportMosaic = NULL;
	m_lpfn_map_GetDataPtr = NULL;
	m_lpfn_map_GetMosaicTile = NULL;

	// tile functions

	m_lpfn_tile_GetMinMaxAlt = NULL;
	m_lpfn_tile_GetPixel = NULL;
	m_lpfn_tile_SetPixel = NULL;
	m_lpfn_tile_GetTileCoords = NULL;
	m_lpfn_tile_SetLock = NULL;
	m_lpfn_tile_GetDataPtr = NULL;

	// format functions

	m_lpfn_format_Create = NULL;
	m_lpfn_format_CreateGeneric = NULL;
	m_lpfn_format_SetFlags = NULL;
	m_lpfn_format_GetExt = NULL;
	m_lpfn_format_GetOptionList = NULL;
	m_lpfn_format_GetOptionValue = NULL;
	m_lpfn_format_SetOptionValue = NULL;
	m_lpfn_format_GetFormatByExt = NULL;
	m_lpfn_format_GetFormatList = NULL;
	m_lpfn_format_IsMosaic = NULL;
	m_lpfn_format_IsNative = NULL;

	// prog box function handles

	m_lpfn_progbox_ShowWnd = NULL;
	m_lpfn_progbox_HideWnd = NULL;
	m_lpfn_progbox_SetTitle = NULL;
	m_lpfn_progbox_SetProgress = NULL;

	// combo box function handles

	m_lpfn_combosel_SetOptions = NULL;
	m_lpfn_combosel_GetOptions = NULL;
	m_lpfn_combosel_SetCurSel = NULL;
	m_lpfn_combosel_GetCurSel = NULL;

	// buffer function handles

	m_lpfn_buffer_Init = NULL;
	m_lpfn_buffer_Free = NULL;
	m_lpfn_buffer_nItems = NULL;
	m_lpfn_buffer_MemSize = NULL;
	m_lpfn_buffer_ItemSize = NULL;
	m_lpfn_buffer_GetPtr = NULL;
	m_lpfn_buffer_GetValue = NULL;
	m_lpfn_buffer_SetValue = NULL;

	// view function handles

	m_lpfn_view_ShowMap = NULL;
	m_lpfn_view_GetActiveMap = NULL;
	m_lpfn_view_GetSelectedArea = NULL;

	// file/dir function handles

	m_lpfn_file_GetExt = NULL;
	m_lpfn_file_GetFilenameNoExt = NULL;
	m_lpfn_file_GetDir = NULL;
	m_lpfn_file_GetFilenameNoDir = NULL;
	m_lpfn_file_FileExists = NULL;

	// extension functions

	m_lpfn_zeofunc_LoadFunc = NULL;
	m_lpfn_zeofunc_LoadFuncEx = NULL;
	m_lpfn_zeofunc_GetFunc = NULL;
	m_lpfn_zeofunc_GetReturnTypeID = NULL;
	m_lpfn_zeofunc_GetArgListPrototype = NULL;
	//m_lpfn_zeofunc_Execute = NULL;
	m_lpfn_zeofunc_Execute2 = NULL;
	m_lpfn_zeofunc_ExecuteThreaded = NULL;

	//menu function handles
	m_lpfn_menu_InsertItem = NULL;
	m_lpfn_menu_InsertItemEx = NULL;
}

CExtAPI::~CExtAPI(void) {
}

bool CExtAPI::InitAPI(FARPROC pFunc, void* hID) {

	if(!pFunc) {
		MessageBox(NULL, "Invalid callback handle", "Zeolite initialisation", MB_ICONERROR);
		return false;
	}

	if(!hID) {
		MessageBox(NULL, "Invalid ID handle", "Zeolite initialisation", MB_ICONERROR);
		return false;
	}

	//store thr session ID
	m_hID = hID;

	// store the handle to the function by which we load more function handles
	m_lpfnGetFuncHandle = (LPFNAPI_app_GetFuncHandle)pFunc;

	// debugging
//	CString TempStr;
//	TempStr.Format("CExtAPI::InitAPI report:\r\n - GetFuncHandle is 0x%x", m_lpfnGetFuncHandle);
//	AfxMessageBox(TempStr);

	// start loading functions from L3DT

	//
	// app functions
	//

	m_lpfnReportError = (LPFNAPI_app_ReportError)GetFuncHandle("app.ReportError");

	//
	// var functions
	//

	m_lpfn_var_Create = (LPFNAPI_var_Create)GetFuncHandle("var.Create");
	m_lpfn_var_CreateTemp = (LPFNAPI_var_CreateTemp)GetFuncHandle("var.CreateTemp");
	m_lpfn_var_Delete = (LPFNAPI_var_Delete)GetFuncHandle("var.Delete");
	m_lpfn_var_Rename = (LPFNAPI_var_Rename)GetFuncHandle("var.Rename");
	m_lpfn_var_GetVar = (LPFNAPI_var_GetVar)GetFuncHandle("var.GetVar");
	m_lpfn_var_GetName = (LPFNAPI_var_GetName)GetFuncHandle("var.GetName");
	m_lpfn_var_GetTypeID = (LPFNAPI_var_GetTypeID)GetFuncHandle("var.GetTypeID");
	m_lpfn_var_IsType = (LPFNAPI_var_IsType)GetFuncHandle("var.IsType");
	m_lpfn_var_GetValue = (LPFNAPI_var_GetValue)GetFuncHandle("var.GetValue");
	m_lpfn_var_SetValue = (LPFNAPI_var_SetValue)GetFuncHandle("var.SetValue");
	m_lpfn_var_GetValueEx = (LPFNAPI_var_GetValueEx)GetFuncHandle("var.GetValueEx");
	m_lpfn_var_SetValueEx = (LPFNAPI_var_SetValueEx)GetFuncHandle("var.SetValueEx");
	m_lpfn_var_CopyValue = (LPFNAPI_var_CopyValue)GetFuncHandle("var.CopyValue");
	m_lpfn_var_SetVarRef = (LPFNAPI_var_SetVarRef)GetFuncHandle("var.SetVarRef");
	m_lpfn_var_EditUI = (LPFNAPI_var_EditUI)GetFuncHandle("var.EditUI");
	m_lpfn_var_GetDataPtr = (LPFNAPI_var_GetDataPtr)GetFuncHandle("var.GetDataPtr");

	//
	// type functions
	//

	m_lpfn_type_GetTypeID = (LPFNAPI_type_GetTypeID)GetFuncHandle("type.GetTypeID");
	m_lpfn_type_GetTypeName = (LPFNAPI_type_GetTypeName)GetFuncHandle("type.GetTypeName");

	//
	// string functions
	//

	m_lpfn_str_GetText = (LPFNAPI_str_GetText)GetFuncHandle("str.GetText");
	m_lpfn_str_SetText = (LPFNAPI_str_SetText)GetFuncHandle("str.SetText");

	//
	// list functions
	//

	m_lpfn_list_nItems = (LPFNAPI_list_nItems)GetFuncHandle("list.nItems");
	m_lpfn_list_CreateItem = (LPFNAPI_list_CreateItem)GetFuncHandle("list.CreateItem");
	m_lpfn_list_GetItemI = (LPFNAPI_list_GetItemI)GetFuncHandle("list.GetItemI");
	m_lpfn_list_GetItemA = (LPFNAPI_list_GetItemA)GetFuncHandle("list.GetItemA");
	m_lpfn_list_DelItemI = (LPFNAPI_list_DelItemI)GetFuncHandle("list.DelItemI");
	m_lpfn_list_DelItemA = (LPFNAPI_list_DelItemA)GetFuncHandle("list.DelItemA");
	m_lpfn_list_DelAll = (LPFNAPI_list_DelAll)GetFuncHandle("list.DelAll");
	m_lpfn_list_SortI = (LPFNAPI_list_SortI)GetFuncHandle("list.SortI");
	m_lpfn_list_SortA = (LPFNAPI_list_SortA)GetFuncHandle("list.SortA");

	//
	// map functions
	//

	m_lpfn_map_Init = (LPFNAPI_map_Init)GetFuncHandle("map.Init");
	m_lpfn_map_Free = (LPFNAPI_map_Free)GetFuncHandle("map.Free");
	m_lpfn_map_GetMapType = (LPFNAPI_map_GetPixelSize)GetFuncHandle("map.GetMapType");
	m_lpfn_map_GetPixelSize = (LPFNAPI_map_GetPixelSize)GetFuncHandle("map.GetPixelSize");
	m_lpfn_map_GetWrapFlag = (LPFNAPI_map_GetWrapFlag)GetFuncHandle("map.GetWrapFlag");
	m_lpfn_map_SetWrapFlag = (LPFNAPI_map_SetWrapFlag)GetFuncHandle("map.SetWrapFlag");
	m_lpfn_map_GetBusyFlag = (LPFNAPI_map_GetBusyFlag)GetFuncHandle("map.GetBusyFlag");
	m_lpfn_map_SetBusyFlag = (LPFNAPI_map_SetBusyFlag)GetFuncHandle("map.SetBusyFlag");
	m_lpfn_map_GetWidth = (LPFNAPI_map_GetWidth)GetFuncHandle("map.GetWidth");
	m_lpfn_map_GetHeight = (LPFNAPI_map_GetHeight)GetFuncHandle("map.GetHeight");
	m_lpfn_map_GetPixel = (LPFNAPI_map_GetPixel)GetFuncHandle("map.GetPixel");
	m_lpfn_map_SetPixel = (LPFNAPI_map_SetPixel)GetFuncHandle("map.SetPixel");
	m_lpfn_map_GetMinMaxAlt = (LPFNAPI_map_GetMinMaxAlt)GetFuncHandle("map.GetMinMaxAlt");
	m_lpfn_map_SetMinMaxAlt = (LPFNAPI_map_SetMinMaxAlt)GetFuncHandle("map.SetMinMaxAlt");
	m_lpfn_map_GetHorizScale = (LPFNAPI_map_GetHorizScale)GetFuncHandle("map.GetHorizScale");
	m_lpfn_map_GetMosaicFlag = (LPFNAPI_map_GetMosaicFlag)GetFuncHandle("map.GetMosaicFlag");
	m_lpfn_map_GetMosaicTileSize = (LPFNAPI_map_GetMosaicTileSize)GetFuncHandle("map.GetMosaicTileSize");
	m_lpfn_map_GetMosaicTilesX = (LPFNAPI_map_GetMosaicTilesX)GetFuncHandle("map.GetMosaicTilesX");
	m_lpfn_map_GetMosaicTilesY = (LPFNAPI_map_GetMosaicTilesY)GetFuncHandle("map.GetMosaicTilesY");
	m_lpfn_map_GetFlag = (LPFNAPI_map_GetFlag)GetFuncHandle("map.GetFlag");
	m_lpfn_map_SetFlag = (LPFNAPI_map_SetFlag)GetFuncHandle("map.SetFlag");
	m_lpfn_map_GetSettingsList = (LPFNAPI_map_GetSettingsList)GetFuncHandle("map.GetSettingsList");
	m_lpfn_map_SaveFile = (LPFNAPI_map_SaveFile)GetFuncHandle("map.SaveFile");
	m_lpfn_map_LoadFile = (LPFNAPI_map_LoadFile)GetFuncHandle("map.LoadFile");
	m_lpfn_map_GetNameInProject = (LPFNAPI_map_GetNameInProject)GetFuncHandle("map.GetNameInProject");
	m_lpfn_map_InitMosaic = (LPFNAPI_map_InitMosaic)GetFuncHandle("map.InitMosaic");
	m_lpfn_map_LoadMosaic = (LPFNAPI_map_LoadMosaic)GetFuncHandle("map.LoadMosaic");
	m_lpfn_map_SaveMosaic = (LPFNAPI_map_SaveMosaic)GetFuncHandle("map.SaveMosaic");
	m_lpfn_map_GetFormat = (LPFNAPI_map_GetFormat)GetFuncHandle("map.GetFormat");
	m_lpfn_map_SetFormat = (LPFNAPI_map_SetFormat)GetFuncHandle("map.SetFormat");
	m_lpfn_map_GetFilename = (LPFNAPI_map_GetFilename)GetFuncHandle("map.GetFilename");
	m_lpfn_map_CombineMosaic = (LPFNAPI_map_CombineMosaic)GetFuncHandle("map.CombineMosaic");
	m_lpfn_map_SplitToMosaic = (LPFNAPI_map_SplitToMosaic)GetFuncHandle("map.SplitToMosaic");
	m_lpfn_map_SaveMosaicAs = (LPFNAPI_map_SaveMosaicAs)GetFuncHandle("map.SaveMosaicAs");
	m_lpfn_map_ExportMap = (LPFNAPI_map_ExportMap)GetFuncHandle("map.ExportMap");
	m_lpfn_map_ExportMosaic = (LPFNAPI_map_ExportMosaic)GetFuncHandle("map.ExportMosaic");
	m_lpfn_map_GetDataPtr = (LPFNAPI_map_GetDataPtr)GetFuncHandle("map.GetDataPtr");
	m_lpfn_map_GetMosaicTile = (LPFNAPI_map_GetMosaicTile)GetFuncHandle("map.GetMosaicTile");

	//
	// mosaic tile functions
	//

	m_lpfn_tile_GetMinMaxAlt = (LPFNAPI_tile_GetMinMaxAlt)GetFuncHandle("tile.GetMinMaxAlt");
	m_lpfn_tile_GetPixel = (LPFNAPI_tile_GetPixel)GetFuncHandle("tile.GetPixel");
	m_lpfn_tile_SetPixel = (LPFNAPI_tile_SetPixel)GetFuncHandle("tile.SetPixel");
	m_lpfn_tile_GetTileCoords = (LPFNAPI_tile_GetTileCoords)GetFuncHandle("tile.GetTileCoords");
	m_lpfn_tile_SetLock = (LPFNAPI_tile_SetLock)GetFuncHandle("tile.SetLock");
	m_lpfn_tile_GetDataPtr = (LPFNAPI_tile_GetDataPtr)GetFuncHandle("tile.GetDataPtr");

	//
	// format functions
	//

	m_lpfn_format_Create = (LPFNAPI_format_Create)GetFuncHandle("format.Create");
	m_lpfn_format_CreateGeneric = (LPFNAPI_format_CreateGeneric)GetFuncHandle("format.CreateGeneric");
	m_lpfn_format_SetFlags = (LPFNAPI_format_SetFlags)GetFuncHandle("format.SetFlags");
	m_lpfn_format_SetInfoStr = (LPFNAPI_format_SetInfoStr)GetFuncHandle("format.SetInfoStr");
	m_lpfn_format_GetExt = (LPFNAPI_format_GetExt)GetFuncHandle("format.GetExt");
	m_lpfn_format_GetOptionList = (LPFNAPI_format_GetOptionList)GetFuncHandle("format.GetOptionList");
	m_lpfn_format_GetOptionValue = (LPFNAPI_format_GetOptionValue)GetFuncHandle("format.GetOptionValue");
	m_lpfn_format_SetOptionValue = (LPFNAPI_format_SetOptionValue)GetFuncHandle("format.SetOptionValue");
	m_lpfn_format_GetFormatByExt = (LPFNAPI_format_GetFormatByExt)GetFuncHandle("format.GetFormatByExt");
	m_lpfn_format_GetFormatList = (LPFNAPI_format_GetFormatList)GetFuncHandle("format.GetFormatList");
	m_lpfn_format_IsMosaic = (LPFNAPI_format_IsMosaic)GetFuncHandle("format.IsMosaic");
	m_lpfn_format_IsNative = (LPFNAPI_format_IsNative)GetFuncHandle("format.IsNative");

	//
	// prog box function handles
	//

	m_lpfn_progbox_ShowWnd = (LPFNAPI_progbox_ShowWnd)GetFuncHandle("progbox.ShowWnd");
	m_lpfn_progbox_HideWnd = (LPFNAPI_progbox_HideWnd)GetFuncHandle("progbox.HideWnd");
	m_lpfn_progbox_SetTitle = (LPFNAPI_progbox_SetTitle)GetFuncHandle("progbox.SetTitle");
	m_lpfn_progbox_SetProgress = (LPFNAPI_progbox_SetProgress)GetFuncHandle("progbox.SetProgress");

	//
	// combo box function handles
	//

	m_lpfn_combosel_SetOptions = (LPFNAPI_combosel_SetOptions)GetFuncHandle("combosel.SetOptions");
	m_lpfn_combosel_GetOptions = (LPFNAPI_combosel_GetOptions)GetFuncHandle("combosel.GetOptions");
	m_lpfn_combosel_SetCurSel = (LPFNAPI_combosel_SetCurSel)GetFuncHandle("combosel.SetCurSel");
	m_lpfn_combosel_GetCurSel = (LPFNAPI_combosel_GetCurSel)GetFuncHandle("combosel.GetCurSel");

	//
	// buffer function handles
	//

	m_lpfn_buffer_Init = (LPFNAPI_buffer_Init)GetFuncHandle("buffer.Init");
	m_lpfn_buffer_Free = (LPFNAPI_buffer_Free)GetFuncHandle("buffer.Free");
	m_lpfn_buffer_nItems = (LPFNAPI_buffer_nItems)GetFuncHandle("buffer.nItems");
	m_lpfn_buffer_MemSize = (LPFNAPI_buffer_MemSize)GetFuncHandle("buffer.MemSize");
	m_lpfn_buffer_ItemSize = (LPFNAPI_buffer_ItemSize)GetFuncHandle("buffer.ItemSize");
	m_lpfn_buffer_GetPtr = (LPFNAPI_buffer_GetPtr)GetFuncHandle("buffer.GetPtr");
	m_lpfn_buffer_GetValue = (LPFNAPI_buffer_GetValue)GetFuncHandle("buffer.GetValue");
	m_lpfn_buffer_SetValue = (LPFNAPI_buffer_SetValue)GetFuncHandle("buffer.SetValue");

	//
	// view function handles
	//

	m_lpfn_view_ShowMap = (LPFNAPI_view_ShowMap)GetFuncHandle("view.ShowMap");
	m_lpfn_view_GetActiveMap = (LPFNAPI_view_GetActiveMap)GetFuncHandle("view.GetActiveMap");
	m_lpfn_view_GetSelectedArea = (LPFNAPI_view_GetSelectedArea)GetFuncHandle("view.GetSelectedArea");

	//
	// file/dir function handles
	//

	m_lpfn_file_GetExt = (LPFNAPI_file_GetExt)GetFuncHandle("file.GetExt");
	m_lpfn_file_GetFilenameNoExt = (LPFNAPI_file_GetFilenameNoExt)GetFuncHandle("file.GetFilenameNoExt");
	m_lpfn_file_GetDir = (LPFNAPI_file_GetDir)GetFuncHandle("file.GetDir");
	m_lpfn_file_GetFilenameNoDir = (LPFNAPI_file_GetFilenameNoDir)GetFuncHandle("file.GetFilenameNoDir");
	m_lpfn_file_FileExists = (LPFNAPI_file_FileExists)GetFuncHandle("file.FileExists");

	//
	// extension function handles
	//

	m_lpfn_zeofunc_LoadFunc = (LPFNAPI_zeofunc_LoadFunc)GetFuncHandle("zeofunc.LoadFunc");
	m_lpfn_zeofunc_LoadFuncEx = (LPFNAPI_zeofunc_LoadFuncEx)GetFuncHandle("zeofunc.LoadFuncEx");
	m_lpfn_zeofunc_GetFunc = (LPFNAPI_zeofunc_GetFunc)GetFuncHandle("zeofunc.GetFunc");
	m_lpfn_zeofunc_GetReturnTypeID = (LPFNAPI_zeofunc_GetReturnTypeID)GetFuncHandle("zeofunc.GetReturnTypeID");
	m_lpfn_zeofunc_GetArgListPrototype = (LPFNAPI_zeofunc_GetArgListPrototype)GetFuncHandle("zeofunc.GetArgListPrototype");
	//m_lpfn_zeofunc_Execute = (LPFNAPI_zeofunc_Execute)GetFuncHandle("zeofunc.Execute");
	m_lpfn_zeofunc_Execute2 = (LPFNAPI_zeofunc_Execute2)GetFuncHandle("zeofunc.Execute2");
	m_lpfn_zeofunc_ExecuteThreaded = (LPFNAPI_zeofunc_ExecuteThreaded)GetFuncHandle("zeofunc.ExecuteThreaded");

	//
	// menu function handles
	//

	m_lpfn_menu_InsertItem = (LPFNAPI_menu_InsertItem)GetFuncHandle("menu.InsertItem");
	m_lpfn_menu_InsertItemEx = (LPFNAPI_menu_InsertItemEx)GetFuncHandle("menu.InsertItemEx");

	return true;
}

//
// app functions
//

void CExtAPI::ReportError(const char* lpErrorMessage) {
	
	if(!m_lpfnReportError) {
		MessageBox(NULL, lpErrorMessage, "Zeolite error", MB_ICONERROR);
	}

	m_lpfnReportError(m_hID, lpErrorMessage);
}

//
// var functions
//

ZVAR CExtAPI::var_Create(long VarID, const char* lpVarName) {
	if(!m_lpfn_var_Create) {
		ReportError("CExtAPI::var_Create error - function not found");
		return NULL;
	}

	return m_lpfn_var_Create(m_hID, VarID, lpVarName);
}
ZVAR CExtAPI::var_CreateTemp(long VarID) {
	if(!m_lpfn_var_CreateTemp) {
		ReportError("CExtAPI::var_CreateTemp error - function not found");
		return NULL;
	}

	return m_lpfn_var_CreateTemp(m_hID, VarID);
}
bool CExtAPI::var_Delete(ZVAR hVar) {
	if(!m_lpfn_var_Delete) {
		ReportError("CExtAPI::var_Delete error - function not found");
		return false;
	}

	return m_lpfn_var_Delete(m_hID, hVar);
}
bool CExtAPI::var_Rename(ZVAR hVar, const char* lpNewName) {
	if(!m_lpfn_var_Rename) {
		ReportError("CExtAPI::var_Rename error - function not found");
		return false;
	}

	return m_lpfn_var_Rename(m_hID, hVar, lpNewName);
}
ZVAR CExtAPI::var_GetVar(const char* lpVarName) {
	if(!m_lpfn_var_GetVar) {
		ReportError("CExtAPI::var_GetVar error - function not found");
		return NULL;
	}

	return m_lpfn_var_GetVar(m_hID, lpVarName);
}
const char* CExtAPI::var_GetName(ZVAR hVar) {
	if(!m_lpfn_var_GetName) {
		ReportError("CExtAPI::var_GetName error - function not found");
		return NULL;
	}

	return m_lpfn_var_GetName(m_hID, hVar);
}
long CExtAPI::var_GetTypeID(ZVAR hVar) {
	if(!m_lpfn_var_GetTypeID) {
		ReportError("CExtAPI::var_GetTypeID error - function not found");
		return 0;
	}

	return m_lpfn_var_GetTypeID(m_hID, hVar);
}
bool CExtAPI::var_IsType(ZVAR hVar, long VarID) {
	if(!m_lpfn_var_IsType) {
		ReportError("CExtAPI::var_IsType error - function not found");
		return false;
	}

	return m_lpfn_var_IsType(m_hID, hVar, VarID);
}
bool CExtAPI::var_GetValue(ZVAR hVar, void* pValue) {
	if(!m_lpfn_var_GetValue) {
		ReportError("CExtAPI::var_GetValue error - function not found");
		return false;
	}

	return m_lpfn_var_GetValue(m_hID, hVar, pValue);
}
bool CExtAPI::var_SetValue(ZVAR hVar, void* pValue) {
	if(!m_lpfn_var_SetValue) {
		ReportError("CExtAPI::var_SetValue error - function not found");
		return false;
	}

	return m_lpfn_var_SetValue(m_hID, hVar, pValue);
}
bool CExtAPI::var_GetValueEx(ZVAR hVar, long VarID, void* pValue) {
	if(!m_lpfn_var_GetValueEx) {
		ReportError("CExtAPI::var_GetValueEx error - function not found");
		return false;
	}

	return m_lpfn_var_GetValueEx(m_hID, hVar, VarID, pValue);
}
bool CExtAPI::var_SetValueEx(ZVAR hVar, long VarID, void* pValue) {
	if(!m_lpfn_var_SetValueEx) {
		ReportError("CExtAPI::var_SetValueEx error - function not found");
		return false;
	}

	return m_lpfn_var_SetValueEx(m_hID, hVar, VarID, pValue);
}
bool CExtAPI::var_CopyValue(ZVAR hVarDest, ZVAR hVarSrc) {
	if(!m_lpfn_var_CopyValue) {
		ReportError("CExtAPI::var_CopyValue error - function not found");
		return false;
	}

	return m_lpfn_var_CopyValue(m_hID, hVarDest, hVarSrc);
}
bool CExtAPI::var_SetVarRef(ZVAR hPtrVar, ZVAR hSrcVar) {
	if(!m_lpfn_var_SetVarRef) {
		ReportError("CExtAPI::var_SetVarRef error - function not found");
		return false;
	}

	return m_lpfn_var_SetVarRef(m_hID, hPtrVar, hSrcVar);
}
bool CExtAPI::var_EditUI(ZVAR hVar, const char* lpPrompt) {
	if(!m_lpfn_var_EditUI) {
		ReportError("CExtAPI::var_EditUI error - function not found");
		return false;
	}

	return m_lpfn_var_EditUI(m_hID, hVar, lpPrompt);
}
void* CExtAPI::var_GetDataPtr(ZVAR hVar) {
	if(!m_lpfn_var_GetDataPtr) {
		ReportError("CExtAPI::var_GetDataPtr error - function not found");
		return false;
	}

	return m_lpfn_var_GetDataPtr(m_hID, hVar);
}

//
// type functions
//

long CExtAPI::type_GetTypeID(const char* lpTypeName) {
	if(!m_lpfn_type_GetTypeID) {
		ReportError("CExtAPI::type_GetTypeID error - function not found");
		return 0;
	}

	return m_lpfn_type_GetTypeID(m_hID, lpTypeName);
}
bool CExtAPI::type_GetTypeName(long VarID, ZVAR hStringVar) {
	if(!m_lpfn_type_GetTypeName) {
		ReportError("CExtAPI::type_GetTypeName error - function not found");
		return false;
	}

	return m_lpfn_type_GetTypeName(m_hID, VarID, hStringVar);
}

//
// string functions
//

const char* CExtAPI::str_GetText(ZVAR hStr) {
	if(!m_lpfn_str_GetText) {
		ReportError("CExtAPI::str_GetText error - function not found");
		return NULL;
	}

	return m_lpfn_str_GetText(m_hID, hStr);
}
bool CExtAPI::str_SetText(ZVAR hStr, const char* lpText) {
	if(!m_lpfn_str_SetText) {
		ReportError("CExtAPI::str_SetText error - function not found");
		return false;
	}

	return m_lpfn_str_SetText(m_hID, hStr, lpText);
}

//
// list functions
//

long CExtAPI::list_nItems(ZLIST hList) {
	if(!m_lpfn_list_nItems) {
		ReportError("CExtAPI::list_nItems error - function not found");
		return 0;
	}

	return m_lpfn_list_nItems(m_hID, hList);
}
ZVAR CExtAPI::list_CreateItem(ZLIST hList, long VarID, const char* lpVarName) {
	if(!m_lpfn_list_CreateItem) {
		ReportError("CExtAPI::list_CreateItem error - function not found");
		return NULL;
	}

	return m_lpfn_list_CreateItem(m_hID, hList, VarID, lpVarName);
}
ZVAR CExtAPI::list_GetItemI(ZLIST hList, long index) {
	if(!m_lpfn_list_GetItemI) {
		ReportError("CExtAPI::list_GetItemI error - function not found");
		return NULL;
	}

	return m_lpfn_list_GetItemI(m_hID, hList, index);
}
ZVAR CExtAPI::list_GetItemA(ZLIST hList, const char* lpVarName) {
	if(!m_lpfn_list_GetItemA) {
		ReportError("CExtAPI::list_GetItemA error - function not found");
		return NULL;
	}

	return m_lpfn_list_GetItemA(m_hID, hList, lpVarName);
}
bool CExtAPI::list_DelItemI(ZLIST hList, long index) {
	if(!m_lpfn_list_DelItemI) {
		ReportError("CExtAPI::list_DelItemI error - function not found");
		return false;
	}

	return m_lpfn_list_DelItemI(m_hID, hList, index);
}
bool CExtAPI::list_DelItemA(ZLIST hList, const char* lpVarName) {
	if(!m_lpfn_list_DelItemA) {
		ReportError("CExtAPI::list_DelItemA error - function not found");
		return false;
	}

	return m_lpfn_list_DelItemA(m_hID, hList, lpVarName);
}
bool CExtAPI::list_DelAll(ZLIST hList) {
	if(!m_lpfn_list_DelAll) {
		ReportError("CExtAPI::list_DelAll error - function not found");
		return false;
	}

	return m_lpfn_list_DelAll(m_hID, hList);
}
bool CExtAPI::list_SortI(ZLIST hList, long From, long To) {
	if(!m_lpfn_list_SortI) {
		ReportError("CExtAPI::list_SortI error - function not found");
		return false;
	}

	return m_lpfn_list_SortI(m_hID, hList, From, To);
}
bool CExtAPI::list_SortA(ZLIST hList, const char* lpItemName, long To) {
	if(!m_lpfn_list_SortA) {
		ReportError("CExtAPI::list_SortA error - function not found");
		return false;
	}

	return m_lpfn_list_SortA(m_hID, hList, lpItemName, To);
}

//
// map functions
//

bool CExtAPI::map_Init(ZMAP hMap, long nx, long ny, long MapTypeID, float HorizScale, bool WrapFlag) {
	if(!m_lpfn_map_Init) {
		ReportError("CExtAPI::map_Init error - function not found");
		return false;
	}

	return m_lpfn_map_Init(m_hID, hMap, nx, ny, MapTypeID, HorizScale, WrapFlag);
}
bool CExtAPI::map_Free(ZMAP hMap) {
	if(!m_lpfn_map_Free) {
		ReportError("CExtAPI::map_Free error - function not found");
		return false;
	}

	return m_lpfn_map_Free(m_hID, hMap);
}
long CExtAPI::map_GetMapType(ZMAP hMap) {
	if(!m_lpfn_map_GetMapType) {
		ReportError("CExtAPI::map_GetMapType error - function not found");
		return 0;
	}

	return m_lpfn_map_GetMapType(m_hID, hMap);
}
long CExtAPI::map_GetPixelSize(ZMAP hMap) {
	if(!m_lpfn_map_GetPixelSize) {
		ReportError("CExtAPI::map_GetPixelSize error - function not found");
		return 0;
	}

	return m_lpfn_map_GetPixelSize(m_hID, hMap);
}
bool CExtAPI::map_GetWrapFlag(ZMAP hMap) {
	if(!m_lpfn_map_GetWrapFlag) {
		ReportError("CExtAPI::map_GetWrapFlag error - function not found");
		return false;
	}

	return m_lpfn_map_GetWrapFlag(m_hID, hMap);
}
bool CExtAPI::map_SetWrapFlag(ZMAP hMap, bool WrapFlag) {
	if(!m_lpfn_map_SetWrapFlag) {
		ReportError("CExtAPI::map_SetWrapFlag error - function not found");
		return false;
	}

	return m_lpfn_map_SetWrapFlag(m_hID, hMap, WrapFlag);
}
bool CExtAPI::map_GetBusyFlag(ZMAP hMap) {
	if(!m_lpfn_map_GetBusyFlag) {
		ReportError("CExtAPI::map_GetBusyFlag error - function not found");
		return false;
	}

	return m_lpfn_map_GetBusyFlag(m_hID, hMap);
}
bool CExtAPI::map_SetBusyFlag(ZMAP hMap, bool BusyFlag) {
	if(!m_lpfn_map_SetBusyFlag) {
		ReportError("CExtAPI::map_SetBusyFlag error - function not found");
		return false;
	}

	return m_lpfn_map_SetBusyFlag(m_hID, hMap, BusyFlag);
}
long CExtAPI::map_GetWidth(ZMAP hMap) {
	if(!m_lpfn_map_GetWidth) {
		ReportError("CExtAPI::map_GetWidth error - function not found");
		return 0;
	}

	return m_lpfn_map_GetWidth(m_hID, hMap);
}
long CExtAPI::map_GetHeight(ZMAP hMap) {
	if(!m_lpfn_map_GetHeight) {
		ReportError("CExtAPI::map_GetHeight error - function not found");
		return 0;
	}

	return m_lpfn_map_GetHeight(m_hID, hMap);
}
bool CExtAPI::map_GetPixel(ZMAP hMap, long x, long y, void* pValue) {
	if(!m_lpfn_map_GetPixel) {
		ReportError("CExtAPI::map_GetPixel error - function not found");
		return false;
	}

	return m_lpfn_map_GetPixel(m_hID, hMap, x, y, pValue);
}
bool CExtAPI::map_SetPixel(ZMAP hMap, long x, long y, void* pValue) {
	if(!m_lpfn_map_SetPixel) {
		ReportError("CExtAPI::map_SetPixel error - function not found");
		return false;
	}

	return m_lpfn_map_SetPixel(m_hID, hMap, x, y, pValue);
}
bool CExtAPI::map_GetMinMaxAlt(ZMAP hMap, float& minval, float& maxval) {
	if(!m_lpfn_map_GetMinMaxAlt) {
		ReportError("CExtAPI::map_GetMinMaxAlt error - function not found");
		return false;
	}

	return m_lpfn_map_GetMinMaxAlt(m_hID, hMap, minval, maxval);
}
bool CExtAPI::map_SetMinMaxAlt(ZMAP hMap, float& minval, float& maxval) {
	if(!m_lpfn_map_SetMinMaxAlt) {
		ReportError("CExtAPI::map_SetMinMaxAlt error - function not found");
		return false;
	}

	return m_lpfn_map_SetMinMaxAlt(m_hID, hMap, minval, maxval);
}
float CExtAPI::map_GetHorizScale(ZMAP hMap) {
	if(!m_lpfn_map_GetHorizScale) {
		ReportError("CExtAPI::map_GetHorizScale error - function not found");
		return false;
	}

	return m_lpfn_map_GetHorizScale(m_hID, hMap);
}
bool CExtAPI::map_GetMosaicFlag(ZMAP hMap) {
	if(!m_lpfn_map_GetMosaicFlag) {
		ReportError("CExtAPI::map_GetMosaicFlag error - function not found");
		return false;
	}

	return m_lpfn_map_GetMosaicFlag(m_hID, hMap);
}
long CExtAPI::map_GetMosaicTileSize(ZMAP hMap) {
	if(!m_lpfn_map_GetMosaicTileSize) {
		ReportError("CExtAPI::map_GetMosaicTileSize error - function not found");
		return 0;
	}

	return m_lpfn_map_GetMosaicTileSize(m_hID, hMap);
}
long CExtAPI::map_GetMosaicTilesX(ZMAP hMap) {
	if(!m_lpfn_map_GetMosaicTilesX) {
		ReportError("CExtAPI::map_GetMosaicTilesX error - function not found");
		return 0;
	}

	return m_lpfn_map_GetMosaicTilesX(m_hID, hMap);
}
long CExtAPI::map_GetMosaicTilesY(ZMAP hMap) {
	if(!m_lpfn_map_GetMosaicTilesY) {
		ReportError("CExtAPI::map_GetMosaicTilesY error - function not found");
		return 0;
	}

	return m_lpfn_map_GetMosaicTilesY(m_hID, hMap);
}
bool CExtAPI::map_GetFlag(ZMAP hMap, long FlagID) {
	if(!m_lpfn_map_GetFlag) {
		ReportError("CExtAPI::map_GetFlag error - function not found");
		return false;
	}

	return m_lpfn_map_GetFlag(m_hID, hMap, FlagID);
}
bool CExtAPI::map_SetFlag(ZMAP hMap, long FlagID, bool FlagValue) {
	if(!m_lpfn_map_SetFlag) {
		ReportError("CExtAPI::map_SetFlag error - function not found");
		return false;
	}

	return m_lpfn_map_SetFlag(m_hID, hMap, FlagID, FlagValue);
}
ZLIST CExtAPI::map_GetSettingsList(ZMAP hMap) {
	if(!m_lpfn_map_GetSettingsList) {
		ReportError("CExtAPI::map_GetSettingsList error - function not found");
		return NULL;
	}

	return m_lpfn_map_GetSettingsList(m_hID, hMap);
}

bool CExtAPI::map_SaveFile(ZMAP hMap, const char* lpFileName, ZFORMAT hFormat, bool SetFlags, bool ShowProgress) {
	if(!m_lpfn_map_SaveFile) {
		ReportError("CExtAPI::map_SaveFile error - function not found");
		return NULL;
	}

	return m_lpfn_map_SaveFile(m_hID, hMap, lpFileName, hFormat, SetFlags, ShowProgress);
}

bool CExtAPI::map_LoadFile(ZMAP hMap, const char* lpFileName, long MapTypeID, ZFORMAT hFormat, bool SetFlags, bool ShowProgress) {
	if(!m_lpfn_map_LoadFile) {
		ReportError("CExtAPI::map_LoadFile error - function not found");
		return NULL;
	}

	return m_lpfn_map_LoadFile(m_hID, hMap, lpFileName, MapTypeID, hFormat, SetFlags, ShowProgress);
}

bool CExtAPI::map_GetNameInProject(ZMAP hMap, ZVAR hStr) {
	if(!m_lpfn_map_GetNameInProject) {
		ReportError("CExtAPI::map_GetNameInProject error - function not found");
		return NULL;
	}

	return m_lpfn_map_GetNameInProject(m_hID, hMap, hStr);
}

bool CExtAPI::map_InitMosaic(ZMAP hMap, long nx, long ny, long MapTypeID, float HorizScale, bool WrapFlag, const char* lpMosaicFileName, long TileSize, ZFORMAT hFormat, const char* lpProjMapName) {
	if(!m_lpfn_map_InitMosaic) {
		ReportError("CExtAPI::map_InitMosaic error - function not found");
		return false;
	}

	return m_lpfn_map_InitMosaic(m_hID, hMap, nx, ny, MapTypeID, HorizScale, WrapFlag, lpMosaicFileName, TileSize, hFormat, lpProjMapName);
}
bool CExtAPI::map_LoadMosaic(ZMAP hMap, const char* lpMosaicFileName) {
	if(!m_lpfn_map_LoadMosaic) {
		ReportError("CExtAPI::map_LoadMosaic error - function not found");
		return false;
	}

	return m_lpfn_map_LoadMosaic(m_hID, hMap, lpMosaicFileName);
}
bool CExtAPI::map_SaveMosaic(ZMAP hMap) {
	if(!m_lpfn_map_SaveMosaic) {
		ReportError("CExtAPI::map_SaveMosaic error - function not found");
		return false;
	}

	return m_lpfn_map_SaveMosaic(m_hID, hMap);
}

ZFORMAT CExtAPI::map_GetFormat(ZMAP hMap) {
	if(!m_lpfn_map_GetFormat) {
		ReportError("CExtAPI::map_GetFormat error - function not found");
		return NULL;
	}

	return m_lpfn_map_GetFormat(m_hID, hMap);
}
bool CExtAPI::map_SetFormat(ZMAP hMap, ZFORMAT hFormat) {
	if(!m_lpfn_map_SetFormat) {
		ReportError("CExtAPI::map_SetFormat error - function not found");
		return false;
	}

	return m_lpfn_map_SetFormat(m_hID, hMap, hFormat);
}
const char* CExtAPI::map_GetFilename(ZMAP hMap) {
	if(!m_lpfn_map_GetFilename) {
		ReportError("CExtAPI::map_GetFilename error - function not found");
		return NULL;
	}

	return m_lpfn_map_GetFilename(m_hID, hMap);
}

bool CExtAPI::map_CombineMosaic(ZMAP hMap) {
	if(!m_lpfn_map_CombineMosaic) {
		ReportError("CExtAPI::map_CombineMosaic error - function not found");
		return NULL;
	}

	return m_lpfn_map_CombineMosaic(m_hID, hMap);
}
bool CExtAPI::map_SplitToMosaic(ZMAP hMap, const char* lpMosaicFileName, long TileSize, ZFORMAT hFormat, const char* lpProjMapName) {
	if(!m_lpfn_map_SplitToMosaic) {
		ReportError("CExtAPI::map_SplitToMosaic error - function not found");
		return false;
	}

	return m_lpfn_map_SplitToMosaic(m_hID, hMap, lpMosaicFileName, TileSize, hFormat, lpProjMapName);
}

bool CExtAPI::map_SaveMosaicAs(ZMAP hMap, const char* lpFileName) {
	if(!m_lpfn_map_SaveMosaicAs) {
		ReportError("CExtAPI::map_SaveMosaicAs error - function not found");
		return false;
	}

	return m_lpfn_map_SaveMosaicAs(m_hID, hMap, lpFileName);
}
bool CExtAPI::map_ExportMap(ZMAP hMap, const char* lpFileName, ZFORMAT hFormat, long nx, long ny) {
	if(!m_lpfn_map_ExportMap) {
		ReportError("CExtAPI::map_ExportMap error - function not found");
		return false;
	}

	return m_lpfn_map_ExportMap(m_hID, hMap, lpFileName, hFormat, nx, ny);
}
bool CExtAPI::map_ExportMosaic(ZMAP hMap, const char* lpFileName, ZFORMAT hFormat, long nx, long ny, long TileSize, const char* lpProjMapName) {
	if(!m_lpfn_map_ExportMosaic) {
		ReportError("CExtAPI::map_ExportMosaic error - function not found");
		return false;
	}

	return m_lpfn_map_ExportMosaic(m_hID, hMap, lpFileName, hFormat, nx, ny, TileSize, lpProjMapName);
}

void* CExtAPI::map_GetDataPtr(ZMAP hMap) {
	if(!m_lpfn_map_GetDataPtr) {
		ReportError("CExtAPI::map_GetDataPtr error - function not found");
		return NULL;
	}

	return m_lpfn_map_GetDataPtr(m_hID, hMap);
}

void* CExtAPI::map_GetMosaicTile(ZMAP hMap, long tx, long ty) {
	if(!m_lpfn_map_GetMosaicTile) {
		ReportError("CExtAPI::map_GetMosaicTile error - function not found");
		return NULL;
	}

	return m_lpfn_map_GetMosaicTile(m_hID, hMap, tx, ty);
}

//
// mosaic tile functions
//

bool CExtAPI::tile_GetPixel(void* hTile, long x, long y, void* pValue) {
	if(!m_lpfn_tile_GetPixel) {
		ReportError("CExtAPI::tile_GetPixel error - function not found");
		return false;
	}

	return m_lpfn_tile_GetPixel(m_hID, hTile, x, y, pValue);
}
bool CExtAPI::tile_SetPixel(void* hTile, long x, long y, void* pValue) {
	if(!m_lpfn_tile_SetPixel) {
		ReportError("CExtAPI::tile_SetPixel error - function not found");
		return false;
	}

	return m_lpfn_tile_SetPixel(m_hID, hTile, x, y, pValue);
}
bool CExtAPI::tile_GetMinMaxAlt(void* hTile, float& minval, float& maxval) {
	if(!m_lpfn_tile_GetMinMaxAlt) {
		ReportError("CExtAPI::tile_GetMinMaxAlt error - function not found");
		return false;
	}

	return m_lpfn_tile_GetMinMaxAlt(m_hID, hTile, minval, maxval);
}
bool CExtAPI::tile_GetTileCoords(void* hTile, long &x, long &y) {
	if(!m_lpfn_tile_GetTileCoords) {
		ReportError("CExtAPI::tile_GetTileCoords error - function not found");
		return false;
	}

	return m_lpfn_tile_GetTileCoords(m_hID, hTile, x, y);
}
bool CExtAPI::tile_SetLock(void* hTile, bool LockState) {
	if(!m_lpfn_tile_SetLock) {
		ReportError("CExtAPI::tile_SetLock error - function not found");
		return false;
	}

	return m_lpfn_tile_SetLock(m_hID, hTile, LockState);
}
void* CExtAPI::tile_GetDataPtr(void* hTile) {
	if(!m_lpfn_tile_GetDataPtr) {
		ReportError("CExtAPI::tile_GetDataPtr error - function not found");
		return NULL;
	}

	return m_lpfn_tile_GetDataPtr(m_hID, hTile);
}

//
// format functions
//

ZFORMAT CExtAPI::format_Create(LPCTSTR lpMapName, const char* lpLongName, const char* lpFileExt, const char* lpNativeProgramName) {
	if(!m_lpfn_format_Create) {
		ReportError("CExtAPI::format_Create error - function not found");
		return NULL;
	}

	return m_lpfn_format_Create(m_hID, lpMapName, lpLongName, lpFileExt, lpNativeProgramName);
}
ZFORMAT CExtAPI::format_CreateGeneric(long MapTypeID, LPCTSTR lpLongName, const char* lpFileExt, const char* lpNativeProgramName) {
	if(!m_lpfn_format_Create) {
		ReportError("CExtAPI::format_CreateGeneric error - function not found");
		return NULL;
	}

	return m_lpfn_format_CreateGeneric(m_hID, MapTypeID, lpLongName, lpFileExt, lpNativeProgramName);
}
bool CExtAPI::format_SetFlags(ZFORMAT hFormat, bool Native, bool Mosaic) {
	if(!m_lpfn_format_SetFlags) {
		ReportError("CExtAPI::format_SetFlags error - function not found");
		return false;
	}

	return m_lpfn_format_SetFlags(m_hID, hFormat, Native, Mosaic);
}
bool CExtAPI::format_SetInfoStr(ZFORMAT hFormat, const char* lpInfoStr) {
	if(!m_lpfn_format_SetInfoStr) {
		ReportError("CExtAPI::format_SetInfoStr error - function not found");
		return false;
	}

	return m_lpfn_format_SetInfoStr(m_hID, hFormat, lpInfoStr);
}
const char* CExtAPI::format_GetExt(ZFORMAT hFormat) {
	if(!m_lpfn_format_GetExt) {
		ReportError("CExtAPI::format_GetExt error - function not found");
		return NULL;
	}

	return m_lpfn_format_GetExt(m_hID, hFormat);
}
ZLIST CExtAPI::format_GetOptionList(ZFORMAT hFormat) {
	if(!m_lpfn_format_GetOptionList) {
		ReportError("CExtAPI::format_GetOptionList error - function not found");
		return NULL;
	}

	return m_lpfn_format_GetOptionList(m_hID, hFormat);
}
bool CExtAPI::format_SetOptionValue(ZFORMAT hFormat, const char* lpOptionName, long VarID, void* pValue) {
	if(!m_lpfn_format_SetOptionValue) {
		ReportError("CExtAPI::format_SetOptionValue error - function not found");
		return false;
	}

	return m_lpfn_format_SetOptionValue(m_hID, hFormat, lpOptionName, VarID, pValue);
}
bool CExtAPI::format_GetOptionValue(ZFORMAT hFormat, const char* lpOptionName, long VarID, void* pValue) {
	if(!m_lpfn_format_GetOptionValue) {
		ReportError("CExtAPI::format_GetOptionValue error - function not found");
		return false;
	}

	return m_lpfn_format_GetOptionValue(m_hID, hFormat, lpOptionName, VarID, pValue);
}

ZFORMAT	CExtAPI::format_GetFormatByExt(const char* lpMapName, long MapTypeID, const char* lpFileExt) {
	if(!m_lpfn_format_GetFormatByExt) {
		ReportError("CExtAPI::format_GetFormatByExt error - function not found");
		return NULL;
	}

	return m_lpfn_format_GetFormatByExt(m_hID, lpMapName, MapTypeID, lpFileExt);
}
ZLIST CExtAPI::format_GetFormatList(const char* lpMapName, long MapTypeID) {
	if(!m_lpfn_format_GetFormatList) {
		ReportError("CExtAPI::format_GetFormatList error - function not found");
		return NULL;
	}

	return m_lpfn_format_GetFormatList(m_hID, lpMapName, MapTypeID);
}

ZFORMAT	CExtAPI::format_GetFormatByExt2(ZMAP hMap, const char* lpFileExt) {
	
	ZVAR hStr = theAPI.var_CreateTemp(VarID_string);

	map_GetNameInProject(hMap, hStr);

	ZLIST hRval = format_GetFormatByExt(theAPI.str_GetText(hStr), theAPI.map_GetMapType(hMap), lpFileExt);

	theAPI.var_Delete(hStr);

	return hRval;

}
ZLIST CExtAPI::format_GetFormatList2(ZMAP hMap) {

	ZVAR hStr = theAPI.var_CreateTemp(VarID_string);

	map_GetNameInProject(hMap, hStr);

	ZLIST hRval = format_GetFormatList(theAPI.str_GetText(hStr), theAPI.map_GetMapType(hMap));

	theAPI.var_Delete(hStr);

	return hRval;
}

bool CExtAPI::format_IsMosaic(ZFORMAT hFormat) {
	if(!m_lpfn_format_IsMosaic) {
		ReportError("CExtAPI::format_IsMosaic error - function not found");
		return false;
	}

	return m_lpfn_format_IsMosaic(m_hID, hFormat);
}
bool CExtAPI::format_IsNative(ZFORMAT hFormat) {
	if(!m_lpfn_format_IsNative) {
		ReportError("CExtAPI::format_IsNative error - function not found");
		return false;
	}

	return m_lpfn_format_IsNative(m_hID, hFormat);
}

ZFORMAT CExtAPI::format_GetActiveFormat(const char* lpMapName, long MapTypeID) {
	ZFUNC hFunc = zeofunc_GetFunc("classes.format.GetActiveFormat");
	if(!hFunc) {
		ReportError("CExtAPI::format_GetActiveFormat error:\r\n - cannot retrieve function handle");
		return NULL;
	}

	ZLIST hArgs = var_CreateTemp(VarID_varlist);
	if(!hArgs) {
		ReportError("CExtAPI::format_GetActiveFormat error:\r\n - cannot create arg list");
		return NULL;
	}

	ZVAR hFileName = list_CreateItem(hArgs, VarID_string, "MapName");
	if(!str_SetText(hFileName, lpMapName)) {
		ReportError("CExtAPI::format_GetActiveFormat error:\r\n - cannot set hFileName value");
		return NULL;
	}

	ZVAR hMapID = list_CreateItem(hArgs, VarID_int, "MapTypeID");
	if(!var_SetValueEx(hMapID, VarID_int, &MapTypeID)) {
		ReportError("CExtAPI::format_GetActiveFormat error:\r\n - cannot set MapTypeID value");
		return NULL;
	}

	ZVAR hRval = NULL;
	if(!zeofunc_Execute2(hFunc, hArgs, &hRval)) {
		ReportError("CExtAPI::format_GetActiveFormat error:\r\n - zeofunc call failed");
		return NULL;
	}

	theAPI.var_Delete(hArgs);

	return hRval;
}

//
// prog box functions
//

bool CExtAPI::progbox_ShowWnd(ZVAR hProgWnd) {
	if(!m_lpfn_progbox_ShowWnd) {
		ReportError("CExtAPI::progbox_ShowWnd error - function not found");
		return false;
	}

	return m_lpfn_progbox_ShowWnd(m_hID, hProgWnd);
}
bool CExtAPI::progbox_HideWnd(ZVAR hProgWnd) {
	if(!m_lpfn_progbox_HideWnd) {
		ReportError("CExtAPI::progbox_HideWnd error - function not found");
		return false;
	}

	return m_lpfn_progbox_HideWnd(m_hID, hProgWnd);
}
bool CExtAPI::progbox_SetTitle(ZVAR hProgWnd, const char* lpTitleText) {
	if(!m_lpfn_progbox_SetTitle) {
		ReportError("CExtAPI::progbox_SetTitle error - function not found");
		return false;
	}

	return m_lpfn_progbox_SetTitle(m_hID, hProgWnd, lpTitleText);
}
bool CExtAPI::progbox_SetProgress(ZVAR hProgWnd, __int64 p, __int64 pmax) {
	if(!m_lpfn_progbox_SetProgress) {
		ReportError("CExtAPI::progbox_SetProgress error - function not found");
		return false;
	}

	return m_lpfn_progbox_SetProgress(m_hID, hProgWnd, p, pmax);
}

//
// combo box functions
//

bool CExtAPI::combosel_SetOptions(ZVAR hComboSel, const char* lpOptionsStr) {
	if(!m_lpfn_combosel_SetOptions) {
		ReportError("CExtAPI::combosel_SetOptions error - function not found");
		return false;
	}

	return m_lpfn_combosel_SetOptions(m_hID, hComboSel, lpOptionsStr);
}
const char* CExtAPI::combosel_GetOptions(ZVAR hComboSel) {
	if(!m_lpfn_combosel_GetOptions) {
		ReportError("CExtAPI::combosel_GetOptions error - function not found");
		return false;
	}

	return m_lpfn_combosel_GetOptions(m_hID, hComboSel);
}
bool CExtAPI::combosel_SetCurSel(ZVAR hComboSel, const char* lpCurSelStr) {
	if(!m_lpfn_combosel_SetCurSel) {
		ReportError("CExtAPI::combosel_SetCurSel error - function not found");
		return false;
	}

	return m_lpfn_combosel_SetCurSel(m_hID, hComboSel, lpCurSelStr);
}
const char* CExtAPI::combosel_GetCurSel(ZVAR hComboSel) {
	if(!m_lpfn_combosel_GetCurSel) {
		ReportError("CExtAPI::combosel_GetCurSel error - function not found");
		return false;
	}

	return m_lpfn_combosel_GetCurSel(m_hID, hComboSel);
}

//
// buffer functions
//

bool CExtAPI::buffer_Init(ZVAR hBuf, long nItems, long ItemSize) {
	if(!m_lpfn_buffer_Init) {
		ReportError("CExtAPI::buffer_Init error - function not found");
		return false;
	}

	return m_lpfn_buffer_Init(m_hID, hBuf, nItems, ItemSize);
}
bool CExtAPI::buffer_Free(ZVAR hBuf) {
	if(!m_lpfn_buffer_Free) {
		ReportError("CExtAPI::buffer_Free error - function not found");
		return false;
	}

	return m_lpfn_buffer_Free(m_hID, hBuf);
}
long CExtAPI::buffer_nItems(ZVAR hBuf) {
	if(!m_lpfn_buffer_nItems) {
		ReportError("CExtAPI::buffer_nItems error - function not found");
		return 0;
	}

	return m_lpfn_buffer_nItems(m_hID, hBuf);
}
long CExtAPI::buffer_MemSize(ZVAR hBuf) {
	if(!m_lpfn_buffer_MemSize) {
		ReportError("CExtAPI::buffer_MemSize error - function not found");
		return 0;
	}

	return m_lpfn_buffer_MemSize(m_hID, hBuf);
}
long CExtAPI::buffer_ItemSize(ZVAR hBuf) {
	if(!m_lpfn_buffer_ItemSize) {
		ReportError("CExtAPI::buffer_ItemSize error - function not found");
		return 0;
	}

	return m_lpfn_buffer_ItemSize(m_hID, hBuf);
}
void* CExtAPI::buffer_GetPtr(ZVAR hBuf) {
	if(!m_lpfn_buffer_GetPtr) {
		ReportError("CExtAPI::buffer_GetPtr error - function not found");
		return NULL;
	}

	return m_lpfn_buffer_GetPtr(m_hID, hBuf);
}
bool CExtAPI::buffer_GetValue(ZVAR hBuf, long index, void* pValue) {
	if(!m_lpfn_buffer_GetValue) {
		ReportError("CExtAPI::buffer_GetValue error - function not found");
		return false;
	}

	return m_lpfn_buffer_GetValue(m_hID, hBuf, index, pValue);
}
bool CExtAPI::buffer_SetValue(ZVAR hBuf, long index, void* pValue) {
	if(!m_lpfn_buffer_SetValue) {
		ReportError("CExtAPI::buffer_SetValue error - function not found");
		return false;
	}

	return m_lpfn_buffer_SetValue(m_hID, hBuf, index, pValue);
}

//
// project functions
//

ZMAP CExtAPI::project_GetMap(const char* lpMapName) {

	ZFUNC hFunc = zeofunc_GetFunc("project.GetMap");
	if(!hFunc) {
		ReportError("CExtAPI::project_GetMap error - function not found");
		return NULL;
	}

	ZLIST hArgs = var_CreateTemp(VarID_varlist);
	if(!hArgs) {
		ReportError("CExtAPI::project_GetMap error:\r\n - cannot create arg list");
		return NULL;
	}

	ZVAR hMapName = list_CreateItem(hArgs, VarID_string, "MapName");
	if(!str_SetText(hMapName, lpMapName)) {
		ReportError("CExtAPI::project_GetMap error:\r\n - cannot set MapName value");
		return NULL;
	}

	ZVAR hRval1 = NULL, hRval2;
	if(!zeofunc_Execute2(hFunc, hArgs, &hRval1)) {
		return NULL;
	}
	if(!theAPI.var_GetValueEx(hRval1, VarID_LPVOID, &hRval2)) {
		return NULL;
	}
    
	// cleanup
	theAPI.var_Delete(hArgs);

	return hRval2;
}

bool CExtAPI::project_GetHeightfieldRange(float& minval, float& maxval) {
	ZFUNC hFunc = zeofunc_GetFunc("project.GetSettingsList");
	if(!hFunc) {
		ReportError("CExtAPI::project_GetHeightfieldRange error - function not found");
		return false;
	}

	ZLIST hRval = NULL;
	if(!zeofunc_Execute2(hFunc, NULL, &hRval)) {
		ReportError("CExtAPI::project_GetHeightfieldRange error - zeofunc failed");
		return false;
	}

	if(!var_GetValue(theAPI.list_GetItemA(hRval, "MinAlt"), &minval)) {
		ReportError("CExtAPI::project_GetHeightfieldRange error - cannot get min alt");
		return false;
	}

	if(!var_GetValue(theAPI.list_GetItemA(hRval, "MaxAlt"), &maxval)) {
		ReportError("CExtAPI::project_GetHeightfieldRange error - cannot get max alt");
		return false;
	}

	return true;
}


const char* CExtAPI::project_GetProjectFilename() {
	ZFUNC hFunc = zeofunc_GetFunc("project.GetProjectPath");
	if(!hFunc) {
		ReportError("CExtAPI::project_GetProjectFilename error - function not found");
		return NULL;
	}

	ZVAR hRval = NULL;
	if(!zeofunc_Execute2(hFunc, NULL, &hRval)) {
		ReportError("CExtAPI::project_GetProjectFilename error - zeofunc failed");
		return NULL;
	}

    return theAPI.str_GetText(hRval);
}
ZLIST CExtAPI::project_GetSettingsList() {
	ZFUNC hFunc = zeofunc_GetFunc("project.GetSettingsList");
	if(!hFunc) {
		ReportError("CExtAPI::project_GetSettingsList error - function not found");
		return NULL;
	}

	ZVAR hRval = NULL;
	if(!zeofunc_Execute2(hFunc, NULL, &hRval)) {
		ReportError("CExtAPI::project_GetSettingsList error - zeofunc failed");
		return NULL;
	}

	return hRval;
}

//
// view functions
//

bool CExtAPI::view_ShowMap(const char* lpProjMapName) {
	if(!m_lpfn_view_ShowMap) {
		ReportError("CExtAPI::view_ShowMap error - function not found");
		return false;
	}

	return m_lpfn_view_ShowMap(m_hID, lpProjMapName);
}

ZMAP CExtAPI::view_GetActiveMap() {
	if(!m_lpfn_view_GetActiveMap) {
		ReportError("CExtAPI::view_GetActiveMap error - function not found");
		return NULL;
	}

	return m_lpfn_view_GetActiveMap(m_hID);
}
bool CExtAPI::view_GetSelectedArea(ZLIST hCoordsList) {
	if(!m_lpfn_view_GetSelectedArea) {
		ReportError("CExtAPI::view_GetSelectedArea error - function not found");
		return false;
	}

	return m_lpfn_view_GetSelectedArea(m_hID, hCoordsList);
}

//
// file/dir functions
//

bool CExtAPI::file_GetExt(ZVAR hStr, const char* lpFileName) {
	if(!m_lpfn_file_GetExt) {
		ReportError("CExtAPI::file_GetExt error - function not found");
		return false;
	}

	return m_lpfn_file_GetExt(m_hID, hStr, lpFileName);
}
bool	CExtAPI::file_GetFilenameNoExt(ZVAR hStr, const char* lpFileName) {
	if(!m_lpfn_file_GetFilenameNoExt) {
		ReportError("CExtAPI::file_GetFilenameNoExt error - function not found");
		return false;
	}

	return m_lpfn_file_GetFilenameNoExt(m_hID, hStr, lpFileName);
}
bool CExtAPI::file_GetDir(ZVAR hStr, const char* lpFileName) {
	if(!m_lpfn_file_GetDir) {
		ReportError("CExtAPI::file_GetDir error - function not found");
		return false;
	}

	return m_lpfn_file_GetDir(m_hID, hStr, lpFileName);
}
bool	CExtAPI::file_GetFilenameNoDir(ZVAR hStr, const char* lpFileName) {
	if(!m_lpfn_file_GetFilenameNoDir) {
		ReportError("CExtAPI::file_GetFilenameNoDir error - function not found");
		return false;
	}

	return m_lpfn_file_GetFilenameNoDir(m_hID, hStr, lpFileName);
}
bool CExtAPI::file_FileExists(const char* lpFileName) {
	if(!m_lpfn_file_FileExists) {
		ReportError("CExtAPI::file_FileExists error - function not found");
		return false;
	}

	return m_lpfn_file_FileExists(m_hID, lpFileName);
}

//
// extension functions
//

ZVAR CExtAPI::zeofunc_LoadFunc(const char* lpFnName, long rvalVarID, ZLIST hArgList) {
	if(!m_lpfn_zeofunc_LoadFunc) {
		ReportError("CExtAPI::zeofunc_LoadFunc error - function not found");
		return NULL;
	}

	return m_lpfn_zeofunc_LoadFunc(m_hID, lpFnName, rvalVarID, hArgList);
}
ZVAR CExtAPI::zeofunc_LoadFuncEx(const char* lpFnName, const char* lpExportName, long rvalVarID, ZLIST hArgList) {
	if(!m_lpfn_zeofunc_LoadFuncEx) {
		ReportError("CExtAPI::zeofunc_LoadFuncEx error - function not found");
		return NULL;
	}

	return m_lpfn_zeofunc_LoadFuncEx(m_hID, lpFnName, lpExportName, rvalVarID, hArgList);
}
ZVAR CExtAPI::zeofunc_GetFunc(const char* lpFnName) {
	if(!m_lpfn_zeofunc_GetFunc) {
		ReportError("CExtAPI::zeofunc_GetFunc error - function not found");
		return NULL;
	}

	return m_lpfn_zeofunc_GetFunc(m_hID, lpFnName);
}
long CExtAPI::zeofunc_GetReturnTypeID(ZFUNC hFunc) {
	if(!m_lpfn_zeofunc_LoadFunc) {
		ReportError("CExtAPI::zeofunc_GetReturnTypeID error - function not found");
		return 0;
	}

	return m_lpfn_zeofunc_GetReturnTypeID(m_hID, hFunc);
}
bool CExtAPI::zeofunc_GetArgListPrototype(ZFUNC hFunc, ZLIST hArgList) {
	if(!m_lpfn_zeofunc_GetArgListPrototype) {
		ReportError("CExtAPI::zeofunc_GetArgListPrototype error - function not found");
		return false;
	}

	return m_lpfn_zeofunc_GetArgListPrototype(m_hID, hFunc, hArgList);
}
ZVAR CExtAPI::zeofunc_Execute(ZFUNC hFunc, ZLIST hArgList) {
	// wrapper for Execute2
	// note, this function is not fully thread-safe, as multiple
	// simultanous calls to Execute will return the same rval object handle

	ZVAR hRval = NULL;
	
	if(!zeofunc_Execute2(hFunc, hArgList, &hRval))
		return NULL;

	return hRval;
}
bool CExtAPI::zeofunc_Execute2(ZFUNC hFunc, ZLIST hArgList, ZVAR* ppRval) {
	if(!m_lpfn_zeofunc_Execute2) {
		ReportError("CExtAPI::zeofunc_Execute2 error - function not found");
		return NULL;
	}

	return m_lpfn_zeofunc_Execute2(m_hID, hFunc, hArgList, ppRval);
}
bool CExtAPI::zeofunc_ExecuteThreaded(ZFUNC hFunc, ZLIST hArgList, bool DeleteArgs, long ThreadPriority) {
	if(!m_lpfn_zeofunc_ExecuteThreaded) {
		ReportError("CExtAPI::zeofunc_ExecuteThreaded error - function not found");
		return false;
	}

	return m_lpfn_zeofunc_ExecuteThreaded(m_hID, hFunc, hArgList, DeleteArgs, ThreadPriority);
}

//
// menu functions
//

bool CExtAPI::menu_InsertItem(const char* lpFnName, const char* lpOptionName) {
	if(!m_lpfn_menu_InsertItem) {
		ReportError("CExtAPI::menu_InsertItem error - function not found");
		return NULL;
	}

	return m_lpfn_menu_InsertItem(m_hID, lpFnName, lpOptionName);
}
bool CExtAPI::menu_InsertItemEx(const char* lpFnName, const char* lpOptionName, bool IsThreaded) {
	if(!m_lpfn_menu_InsertItemEx) {
		ReportError("CExtAPI::menu_InsertItemEx error - function not found");
		return NULL;
	}

	return m_lpfn_menu_InsertItemEx(m_hID, lpFnName, lpOptionName, IsThreaded);
}

//
// bootstrapping function
//

FARPROC CExtAPI::GetFuncHandle(const char* lpFuncName) {
	if(!m_lpfnGetFuncHandle) {
		ReportError("CExtAPI::GetFuncHandle error - API not initialised");
		return NULL;
	}

	FARPROC hProc = m_lpfnGetFuncHandle(m_hID, lpFuncName);
	if(!hProc) {
		ReportError("CExtAPI::GetFuncHandle error - Function not found");
		return NULL;
	}

	return hProc;
}