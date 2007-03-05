#include "zstr.h"
#include "extapi.h"
extern CExtAPI theAPI;

CzStr::CzStr(void) {
	Create(NULL);
}

CzStr::~CzStr(void) {
}

bool CzStr::Create(const char* lpVarName){
	return CzVar::Create(VarID_string, lpVarName);
}

const char* CzStr::GetText() {
	if(!m_hVar)	return NULL;

	return theAPI.str_GetText(m_hVar);
}
bool CzStr::SetText(const char* lpTextStr) {
	if(!m_hVar)	return false;

	return theAPI.str_SetText(m_hVar, lpTextStr);
}

int CzStr::GetLength() { return (int)strlen(GetText()); }
int CzStr::Compare(const char* lpText) { return strcmp(GetText(), lpText); }
int CzStr::CompareNoCase(const char* lpText) {
	int len = GetLength();
	char* pBuf = NULL;

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