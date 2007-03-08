# This script saves the height field as a BMP
# (C) 2007 A. Carl Douglas

import zeolite

print 'HFtoBMP running'

string = zeolite.CzStr()
string.Create(None)
string.EditUI("Enter filename")

hmap = zeolite.CzMap()
hf = zeolite.cvar.theAPI.project_GetMap("HF")
hmap.Attach(zeolite.zmap_to_zvar(hf))

format = zeolite.CzFormat()
format.GetByExt("HF", 0, "bmp")

filename = string.GetText() + ".bmp"

hmap.SaveFile(filename, zeolite.zvar_to_zformat(format.GetZVAR()), True, True)

print 'HFtoBMP done.'
