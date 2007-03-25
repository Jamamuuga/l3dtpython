#ifndef __EXT_API_DEFINES_INCLUDED__
#define __EXT_API_DEFINES_INCLUDED__

#pragma once

#ifdef MFC
	#include <afx.h>
#else
	#include <windows.h>
#endif

#ifdef __MINGW32__
	#include <ctype.h>
#endif

// variable handles

typedef void* ZVAR;
typedef void* ZMAP;
typedef void* ZLIST;
typedef void* ZFUNC;
typedef void* ZFORMAT;

// some selected variable type defines

#define VarID_INVALID		0
#define VarID_void			1
#define VarID_var			2 // variant type, data is another ZVAR
#define VarID_bool			3
#define VarID_char			4
#define VarID_byte			5
#define VarID_short			6
#define VarID_int			7
#define VarID_int64			8
#define VarID_float			9
#define VarID_double		10
#define VarID_string		11
#define VarID_colour		13
#define VarID_vector3f		14
#define VarID_buffer		15
#define VarID_LPVOID		20
#define VarID_varlist		31
#define VarID_map			60
#define VarID_format		100
#define VarID_ComboSelector	302
#define VarID_Climate		340
#define VarID_LandType		341
#define VarID_ZeoFunc		510
#define VarID_ProgBox		600

// map type defines

#define MAP_Empty				0
#define MAP_BYTE				1
#define MAP_WORD				2
#define MAP_24bit				3
#define MAP_DWORD				4

#define MAP_DesignMap			10	// DM
#define MAP_Heightfield			20	// HF
#define MAP_TerrainNormals		30	// TN
#define MAP_AttributesMap		40	// AM
#define MAP_WaterMap			50	// WM
#define MAP_AuxWaterMap			52	// AuxWM

// map flags (for use with map_GetFlag/SetFlag)

#define MAPFLAG_READY		1
#define MAPFLAG_SAVED		2
#define MAPFLAG_MOSAIC		3
#define MAPFLAG_INVALID		4
#define MAPFLAG_MODIFIED	5
#define MAPFLAG_SEAMFIX		6

// useful structs

typedef struct { signed char x, y, z; } vector3sc;
typedef struct { float x, y, z; } vector3f;
typedef struct { double x, y, z; } vector3d;

typedef struct { vector3f i, j, k; } matrix3x3f;
typedef struct { vector3d i, j, k; } matrix3x3d;

// pixel type structs

typedef struct {
	short int  Alt;		// exact altitude (in m) (-32k -> 32k)
	unsigned char Peak;			// cone strength
	unsigned char Frac;			// fractal strength
	unsigned char Cliffs;		// cliff / plateau strength
	unsigned char Erosion;
	unsigned char Lakes;			// lake number / size
	unsigned char Climate;
	unsigned char SpecType;		// Mountain, Plateau, Volcano
	unsigned char SpecParam;
} DesignMapPixel;

typedef struct {
	unsigned char ClimateID;		// index of climate in group list
	unsigned char LandTypeID;	// index of land type in climate
} AttributesPixel;

typedef struct {
	unsigned short WaterID;	// identifies the body of water holding this pixel
	unsigned char Type;
	float WaterLevel;
} WaterMapPixel;

typedef struct {
	unsigned char Type;
	unsigned char DoneFlag;
	float WaterLevel;
} AuxWaterMapPixel;

typedef vector3sc TerrainNormalPixel;

typedef struct {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} ColourPixel;

#endif