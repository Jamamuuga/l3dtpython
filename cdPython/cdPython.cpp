// Copyright (C) 2007 A. Carl Douglas   carl.douglas@gmail.com
// All rights reserved.
//
// An extension DLL for L3DT to provide Python scripting.
//


#include "stdafx.h"
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

		// Important note:
		// If PythonXX.dll links to a different version of the c runtime (msvcrXX.dll)
		// to this DLL, then stderr/stdout redirection will not work properly, and
		// you will not see the Python errors in the console.

		fpStdOut = freopen( "CONOUT$", "w", stdout);
		fpStdErr = freopen( "CONOUT$", "w", stderr);

		fprintf(stdout, "Console opened by cdPython\n");

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
bool __stdcall ExtInitPlugin(FARPROC pFunc, LPVOID hID) 
{

	if(!theAPI.InitAPI(pFunc, hID)) {
		MessageBox(NULL, "ExtInitPlugin error", "cdPython", MB_ICONERROR);
		return false;
	}

	CzFunc func;

	func.LoadFunc("ExtAbout", VarID_void, NULL);
	func.LoadFunc("ExtLoadScript", VarID_void, NULL);
	
	// add menu options
	theAPI.menu_InsertItemEx("ExtAbout", "About", false);
	theAPI.menu_InsertItemEx("ExtLoadScript", "Run a Python script", false);

	return true;
}

// Show the version number etc
bool __stdcall ExtAbout(ZVAR hReturnVar, ZLIST hArgList) 
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

// Let the user choose a python script then run that script.
bool __stdcall ExtLoadScript(ZVAR hReturnVar, ZLIST hArgList) 
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

// EOF
