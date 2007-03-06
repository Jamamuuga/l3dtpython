// Copyright (C) 2007 A. Carl Douglas   carl.douglas@gmail.com

%module zeolite 

%{
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

extern CExtAPI theAPI;

%pointer_cast(ZMAP, ZVAR, zmap_to_zvar);
