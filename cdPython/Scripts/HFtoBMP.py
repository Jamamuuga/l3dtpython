# This script saves the height field as a BMP
# (C) 2007 A. Carl Douglas

import zeolite

str = zeolite.CzStr()
str.Create(None)
str.EditUI("Enter filename")

map = zeolite.CzMap()
hf = zeolite.cvar.theAPI.project_GetMap("HF")
map.Attach(zeolite.zmap_to_zvar(hf))

format = zeolite.CzFormat()
format.GetByExt("HF", 0, "bmp")

filename = str.GetText() + ".bmp"

map.SaveFile(filename, format, True, True)
