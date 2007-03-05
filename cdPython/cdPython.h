// Copyright (C) 2007 A. Carl Douglas
// All rights reserved.

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CDPYTHON_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CDPYTHON_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CDPYTHON_EXPORTS
#define CDPYTHON_API __declspec(dllexport)
#else
#define CDPYTHON_API __declspec(dllimport)
#endif


#define CDPYTHON_VERSION "0.1"
#define CDPYTHON_VERSION_NUM_MAJOR 0x00
#define CDPYTHON_VERSION_NUM_MINOR 0x01
#define CDPYTHON_VERSION_NUM (CDPYTHON_VERSION_NUM_MAJOR << 8) | CDPYTHON_VERSION_NUM_MINOR