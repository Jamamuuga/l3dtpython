// Copyright (C) 2007 A. Carl Douglas   carl.douglas@gmail.com
// All rights reserved.
//
// An extension DLL for L3DT to provide Python scripting.
//
// $Id$


#include "stdafx.h"
#include <commdlg.h> // for open file dialog
#include <Shellapi.h> // for ShellExecute
#include "cdPython.h"

#include "..\Plugin API\ExtAPI.h"
#include "..\Plugin API\zVar.h"
#include "..\Plugin API\zList.h"
#include "..\Plugin API\zStr.h"
#include "..\Plugin API\zMap.h"
#include "..\Plugin API\zFormat.h"
#include "..\Plugin API\zFunc.h"
#include "..\Plugin API\zProgBox.h"
#include "..\Plugin API\zComboSel.h"
#include "..\Plugin API\zColour.h"
#include "..\Plugin API\zBuffer.h"

extern CExtAPI theAPI;

#include "Python.h"

extern "C" void init_zeolite(void); // from SWIG generated file

#ifdef _MANAGED
#pragma managed(push, off)
#endif


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	static FILE *fpStdOut = NULL;
	static FILE *fpStdErr = NULL;

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:

		// Allocate a windows console and redirect stdout and stderr
		// so we can see the python interpreter output and errors.

		AllocConsole();

		// minimise the console window
		HWND hConsole;
		if(hConsole = GetConsoleWindow()) {
			ShowWindow(hConsole, SW_MINIMIZE);
		}

		// Important note:
		// If PythonXX.dll links to a different version of the c runtime (msvcrXX.dll)
		// to this DLL, then stderr/stdout redirection will not work properly, and
		// you will not see the Python errors in the console.

		fpStdOut = freopen( "CONOUT$", "w", stdout);
		fpStdErr = freopen( "CONOUT$", "w", stderr);

		fprintf(stdout, "cdPython " CDPYTHON_VERSION "\nCopyright (C) 2007 A. Carl Douglas\n");

		Py_Initialize();
		init_zeolite(); // SWIG generated method
		break;
	case DLL_PROCESS_DETACH:
		// Free windows console
		fclose(fpStdErr);
		fclose(fpStdOut);
		FreeConsole();
		Py_Finalize();
		break;
	}
	return TRUE;
}

#ifdef _MANAGED
#pragma managed(pop)
#endif


// Initialize zeolite API
extern "C" __declspec( dllexport ) bool __stdcall ExtInitPlugin(FARPROC pFunc, LPVOID hID) 
{

	if(!theAPI.InitAPI(pFunc, hID)) {
		MessageBox(NULL, "ExtInitPlugin error", "cdPython", MB_ICONERROR);
		return false;
	}

	// load some functions
	CzFunc func;
	func.LoadFunc("ExtAbout", VarID_void, NULL);
	func.LoadFunc("LoadScriptUI", VarID_void, NULL); // opens file UI
	func.LoadFunc("ExtWikiPage", VarID_void, NULL);
	func.LoadFunc("ExtZeoPage", VarID_void, NULL);

	// extra function that takes filename as argument
	CzList args;
	args.CreateItem(VarID_string, "FileName");
	func.LoadFunc("LoadScript", VarID_void, args.GetZVAR());

	args.DelAll();
	args.CreateItem(VarID_string, "ScriptStr");
	func.LoadFunc("RunScript", VarID_void, args.GetZVAR());

	// add menu options
	theAPI.menu_InsertItem("LoadScriptUI", "Run script from file");
	theAPI.menu_InsertItem("ExtZeoPage", "Zeolite API docs");
	theAPI.menu_InsertItem("ExtWikiPage", "Visit project page");
	theAPI.menu_InsertItem("ExtAbout", "About cdPython");

	fprintf(stdout, "Zeolite API runtime version %s\n", ExtGetApiVersion());

	return true;
}

// Show the version number etc
extern "C" __declspec( dllexport ) bool __stdcall ExtAbout(ZVAR hReturnVar, ZLIST hArgList) 
{
	static const char title[] =
		"Python Extension Version " CDPYTHON_VERSION;
	static const char msg[] =
		"cdPython Version " CDPYTHON_VERSION "\r\n\r\n"
		"cdPython allows you to run Python scripts and provides Python access to the zeolite API.\r\n\r\n"
		"Copyright (C) 2007 A. Carl Douglas.";

	MessageBox(NULL, msg, title, MB_OK);
	return true;
}

// Show the wiki page
extern "C" __declspec( dllexport ) bool __stdcall ExtWikiPage(ZVAR hReturnVar, ZLIST hArgList)  
{
       ShellExecute(NULL, "open", "http://www.bundysoft.com/wiki/doku.php?id=plugins:general:cdPython", NULL, NULL, SW_SHOWNORMAL);
       return true;
}

// Show the zeolite page
extern "C" __declspec( dllexport ) bool __stdcall ExtZeoPage(ZVAR hReturnVar, ZLIST hArgList)  
{
       ShellExecute(NULL, "open", "http://www.bundysoft.com/docs/doku.php?id=zeolite", NULL, NULL, SW_SHOWNORMAL);
       return true;
}

// Let the user choose a python script then run that script.
extern "C" __declspec( dllexport ) bool __stdcall LoadScriptUI(ZVAR hReturnVar, ZLIST hArgList) 
{
	OPENFILENAME ofn;       // common dialog box structure
	char szFile[MAX_PATH];  // buffer for file name

	// Initialize OPENFILENAME
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = szFile;
	//
	// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
	// use the contents of szFile to initialize itself.
	//
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFilter = "Python files (*.py)\0*.py\0All files (*.*)\0*.*\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	// Display the Open dialog box. 
	if (GetOpenFileName(&ofn)==TRUE) 
	{
		// Thank you:  http://www.ragestorm.net/tutorial?id=21#8
		PyObject* PyFileObject = PyFile_FromString(ofn.lpstrFile, "r");

		if (PyFileObject == NULL) 
		{
			PyErr_Print();
			PyErr_Clear();
			return false;
		}

		// Because microsoft C runtimes are not binary compatible, we can't
		// just call fopen to get a FILE * and pass that FILE * to another application
		// or library (Python25.dll in this case) that uses a different version 
		// of the C runtime that this DLL uses. Using PyFile_AsFile is a work-around...

		if (PyRun_SimpleFile(PyFile_AsFile(PyFileObject), ofn.lpstrFile) == -1)
		{
			PyErr_Print();
			PyErr_Clear();
		}

		Py_DECREF(PyFileObject);
	}

	return true;
}

// extension function that allows other plugins to run python scripts from files
extern "C" __declspec( dllexport ) bool __stdcall LoadScript(ZVAR hReturnVar, ZLIST hArgList)  {

       CzStr FileName;
       if(!FileName.Attach(theAPI.list_GetItemI(hArgList, 0))) {
               theAPI.ReportError("cdPython::LoadScript error:\r\n - cannot retrieve file name argument");
               return false;
       }

       if(!FileName.GetLength()) {
               theAPI.ReportError("cdPython::LoadScript error:\r\n - zero-length file name");
               return false;
       }

       if(!theAPI.file_FileExists((char*)FileName)) { // check func name?
               theAPI.ReportError("cdPython::LoadScript error:\r\n - file not found");
               return false;
       }

       // Thank you:  http://www.ragestorm.net/tutorial?id=21#8
       PyObject* PyFileObject = PyFile_FromString((char*)FileName, "r");

       if (PyFileObject == NULL)
       {
               PyErr_Print();
               PyErr_Clear();
               return false;
       }

       if (PyRun_SimpleFile(PyFile_AsFile(PyFileObject), (char*)FileName) == -1)
       {
               PyErr_Print();
               PyErr_Clear();
       }

       Py_DECREF(PyFileObject);

       return true;
}

// extension function that allows other plugins to run python scripts from string
extern "C" __declspec( dllexport ) bool __stdcall RunScript(ZVAR hReturnVar, ZLIST hArgList)  {

       CzStr ScriptStr;
       if(!ScriptStr.Attach(theAPI.list_GetItemI(hArgList, 0))) {
               theAPI.ReportError("cdPython::RunScript error:\r\n - cannot retrieve file name argument");
               return false;
       }

       if(!ScriptStr.GetLength()) {
               theAPI.ReportError("cdPython::LoadScript error:\r\n - zero-length script");
               return false;
       }

       if (PyRun_SimpleString((char*)ScriptStr) == -1)         {
               PyErr_Print();
               PyErr_Clear();
       }

       return true;
}

// EOF
