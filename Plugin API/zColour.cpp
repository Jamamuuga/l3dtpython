#include "zcolour.h"
#include "ExtAPI.h"
#include "ExtAPI_defines.h"

extern CExtAPI theAPI;

CzColour::CzColour(void) {
	Create(NULL);
}

CzColour::~CzColour(void) {
}

bool CzColour::Create(const char* lpVarName) {
	return CzVar::Create(VarID_colour, lpVarName);
}

BYTE CzColour::GetR() {
	ColourPixel ColPxl;
	if(!theAPI.var_GetValueEx(m_hVar, VarID_colour, &ColPxl))
		return 0;

	return ColPxl.r;
}
BYTE CzColour::GetG() {
	ColourPixel ColPxl;
	if(!theAPI.var_GetValueEx(m_hVar, VarID_colour, &ColPxl))
		return 0;

	return ColPxl.g;
}
BYTE CzColour::GetB() {
	ColourPixel ColPxl;
	if(!theAPI.var_GetValueEx(m_hVar, VarID_colour, &ColPxl))
		return 0;

	return ColPxl.b;
}

COLORREF CzColour::GetCOLORREF() {
	ColourPixel ColPxl;
	if(!theAPI.var_GetValueEx(m_hVar, VarID_colour, &ColPxl))
		return RGB(0, 0, 0);

	return RGB(ColPxl.r, ColPxl.g, ColPxl.b);
}

bool CzColour::SetRGB(BYTE r, BYTE g, BYTE b) {
	ColourPixel ColPxl;
	ColPxl.r = r;
	ColPxl.g = g;
	ColPxl.b = b;
	if(!theAPI.var_SetValueEx(m_hVar, VarID_colour, &ColPxl))
		return false;

	return true;
}
bool CzColour::SetRGB(COLORREF ColRef) {
	ColourPixel ColPxl;
	ColPxl.r = GetRValue(ColRef);
	ColPxl.g = GetRValue(ColRef);
	ColPxl.b = GetRValue(ColRef);
	if(!theAPI.var_SetValueEx(m_hVar, VarID_colour, &ColPxl))
		return false;

	return true;
}