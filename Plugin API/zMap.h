#pragma once
#include "zvar.h"

class CzMap :
	public CzVar
{
public:
	CzMap(void);
	~CzMap(void);

	bool Create(const char* lpVarName = 0);

	bool	Init(long nx, long ny, long MapTypeID, float HorizScale, bool WrapFlag);
	bool	Free();
	long	GetMapType();
	long	GetPixelSize();
	bool	GetWrapFlag();
	bool	SetWrapFlag(bool WrapFlag);
	bool	GetBusyFlag();
	bool	SetBusyFlag(bool BusyFlag);
	long	nx(); // get height
	long	ny(); // get height
	bool	GetPixel(long x, long y, void* pValue);
	bool	SetPixel(long x, long y, void* pValue);
	bool	GetMinMaxAlt(float& minval, float& maxval);
	bool	SetMinMaxAlt(float& minval, float& maxval);
	float	GetHorizScale();
	bool	GetMosaicFlag();
	long	GetMosaicTileSize();
	long	GetMosaicTilesX();
	long	GetMosaicTilesY();
	bool	GetFlag(long FlagID);
	bool	SetFlag(long FlagID, bool FlagValue);
	ZLIST	GetSettingsList();
	bool	SaveFile(const char* lpFileName, ZFORMAT hFormat, bool SetFlags, bool ShowProgress);
	bool	LoadFile(const char* lpFileName, long MapTypeID, ZFORMAT hFormat, bool SetFlags, bool ShowProgress);
	bool	GetNameInProject(ZVAR hStr);
	bool	InitMosaic(long nx, long ny, long MapTypeID, float HorizScale, bool WrapFlag, const char* lpMosaicFileName, long TileSize, ZFORMAT hFormat, const char* lpProjMapName);
	bool	LoadMosaic(const char* lpMosaicFileName);
	bool	SaveMosaic();
	ZFORMAT GetFormat();
	bool	SetFormat(ZFORMAT hFormat);
	const char*	GetFilename();
	bool	CombineMosaic();
	bool	SplitToMosaic(const char* lpMosaicFileName, long TileSize, ZFORMAT hFormat, const char* lpProjMapName);
	bool	SaveMosaicAs(const char* lpFileName);
	bool	ExportMap(const char* lpFileName, ZFORMAT hFormat, long nx, long ny);
	bool	ExportMosaic(const char* lpFileName, ZFORMAT hFormat, long nx, long ny, long TileSize, const char* lpProjMapName);
	void*	GetDataPtr();
};
