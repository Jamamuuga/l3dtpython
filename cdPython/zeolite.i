// Copyright (C) 2007 A. Carl Douglas   carl.douglas@gmail.com
// $Id$

%module zeolite 

%{
#include "..\Plugin API\ExtAPI_defines.h"
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
%}

%include "windows.i"
%include "cpointer.i"
%include "typemaps.i"

%include "..\Plugin API\ExtAPI_defines.h"
%include "..\Plugin API\ExtAPI.h"
%include "..\Plugin API\zVar.h"
%include "..\Plugin API\zList.h"
%include "..\Plugin API\zStr.h"
%include "..\Plugin API\zMap.h"
%include "..\Plugin API\zFormat.h"
%include "..\Plugin API\zFunc.h"
%include "..\Plugin API\zProgBox.h"
%include "..\Plugin API\zComboSel.h"
%include "..\Plugin API\zColour.h"
%include "..\Plugin API\zBuffer.h"

%pointer_cast(ZMAP, ZVAR, zmap_to_zvar)
%pointer_cast(ZLIST, ZVAR, zlist_to_zvar)
%pointer_cast(ZFORMAT, ZVAR, zformat_to_zvar)
%pointer_cast(ZFUNC, ZVAR, zfunc_to_zvar)
%pointer_cast(ZVAR, ZMAP, zvar_to_zmap)
%pointer_cast(ZVAR, ZLIST, zvar_to_zlist)
%pointer_cast(ZVAR, ZFUNC, zvar_to_zfunc)
%pointer_cast(ZVAR, ZFORMAT, zvar_to_zformat)

%pointer_class(int,intp)
%pointer_class(short,shortp)
%pointer_class(bool,boolp)
%pointer_class(float,floatp)
%pointer_class(double,doublep)
%pointer_class(char, charp)

extern CExtAPI theAPI;
