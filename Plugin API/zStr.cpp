#include "zstr.h"
#include "extapi.h"
extern CExtAPI theAPI;

#include <stdio.h>

CzStr::CzStr(void) {
	Create(0);
}

CzStr::~CzStr(void) {
}

bool CzStr::Create(const char* lpVarName){
	return CzVar::Create(VarID_string, lpVarName);
}

const char* CzStr::GetText() {
	if(!m_hVar)	return 0;

	return theAPI.str_GetText(m_hVar);
}
bool CzStr::SetText(const char* lpTextStr) {
	if(!m_hVar)	return false;

	return theAPI.str_SetText(m_hVar, lpTextStr);
}

int CzStr::GetLength() { return (int)strlen(GetText()); }
bool CzStr::IsStr(const char* lpText) { return !Compare(lpText); }
int CzStr::Compare(const char* lpText) { return strcmp(GetText(), lpText); }
int CzStr::CompareNoCase(const char* lpText) {
	int len = GetLength();
	char* pBuf = 0;

	if(len) {
		if(!(pBuf = (char*)calloc(len+1, 1))) {
			theAPI.ReportError("CzStr::CompareNoCase error:\r\n - canot allocate string buffer");
			return -1;
		}

		char c;
		for(int i=0; i<len; i++) {
			c = GetAt(i);

			if(isalpha(c)) {
				if(!islower(c)) {
					c = tolower(c);
				}
			}
            
			pBuf[i] = c;
		}
	}

	// debugging
	//theAPI.ReportError(pBuf);
	//theAPI.ReportError(lpText);

	int rval = strcmp(pBuf, lpText);

	free(pBuf);

	return rval;
}

char CzStr::GetAt(int index) {
	if(index<0 || index>=GetLength())
		return 0;

	return (GetText()[index]);
}

const char* CzStr::Append(const char* lpNewText) {
	if(!lpNewText)	return GetText();

	long buflen = GetLength()+(long)strlen(lpNewText)+1;
	if(buflen<1)
		return 0;

	char* pBuf = (char*)malloc(buflen);
	if(!pBuf)	return 0;

	sprintf(pBuf, "%s%s", GetText(), lpNewText);
	SetText(pBuf);

	free(pBuf);
	return GetText();
}
const char* CzStr::AppendChar(char c) {
	char c2[2];
	c2[0]=c;
	c2[1]=0;
	return Append(c2);
}