#include "zbuffer.h"
#include "extapi.h"
extern CExtAPI theAPI;

CzBuffer::CzBuffer(void) {
	Create(NULL);
}

CzBuffer::~CzBuffer(void) {
}

bool CzBuffer::Create(const char* lpVarName) {
	return CzVar::Create(VarID_buffer, lpVarName);
}

bool CzBuffer::Init(long nItems, long ItemSize) {
	if(!m_hVar)	return false;
	
	return theAPI.buffer_Init(m_hVar, nItems, ItemSize);
}
bool CzBuffer::Free() {
	if(!m_hVar)	return false;
	
	return theAPI.buffer_Free(m_hVar);
}
long CzBuffer::nItems() {
	if(!m_hVar)	return 0;
	
	return theAPI.buffer_nItems(m_hVar);
}
long CzBuffer::MemSize() {
	if(!m_hVar)	return 0;
	
	return theAPI.buffer_MemSize(m_hVar);
}
long CzBuffer::ItemSize() {
	if(!m_hVar)	return 0;
	
	return theAPI.buffer_ItemSize(m_hVar);
}
void* CzBuffer::GetPtr() {
	if(!m_hVar)	return NULL;
	
	return (void*)theAPI.buffer_GetPtr(m_hVar);
}
bool CzBuffer::GetValue(long index, void* pValue) {
	if(!m_hVar)	return false;
	
	return theAPI.buffer_GetValue(m_hVar, index, pValue);
}
bool CzBuffer::SetValue(long index, void* pValue) {
	if(!m_hVar)	return false;
	
	return theAPI.buffer_SetValue(m_hVar, index, pValue);
}