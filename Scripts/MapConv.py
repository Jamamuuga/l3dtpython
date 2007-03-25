# execute mapconv to generate a TA Spring map
# Copyright (C) 2007 A. Carl Douglas

import zeolite
import os

# exports a map layer to a BMP file
def saveMapToBMP(mapname, filename):
    hmap = zeolite.CzMap()
    hf = zeolite.cvar.theAPI.project_GetMap(mapname)
    hmap.Attach(zeolite.zmap_to_zvar(hf))

    format = zeolite.CzFormat()
    format.GetByExt(mapname, 0, 'bmp')

    hmap.SaveFile(filename, zeolite.zvar_to_zformat(format.GetZVAR()), True, True)
    return

args = zeolite.CzList()

compression = zeolite.floatp()
compression.assign(0.5)

compression_var = zeolite.CzVar(args.CreateItem(zeolite.VarID_float, 'compression'))
compression_var.SetValue(zeolite.VarID_float, compression.cast())

maxheight = zeolite.intp()
maxheight.assign(300)
                         
maxheight_var = zeolite.CzVar(args.CreateItem(zeolite.VarID_int, 'max height'))
maxheight_var.SetValue(zeolite.VarID_int, maxheight.cast())

minheight = zeolite.intp()
minheight.assign(50)

minheight_var = zeolite.CzVar(args.CreateItem(zeolite.VarID_int, 'min height'))
minheight_var.SetValue(zeolite.VarID_int, minheight.cast())

lowpass = zeolite.boolp()
lowpass.assign(False)
lowpass_var = zeolite.CzVar(args.CreateItem(zeolite.VarID_bool, 'low pass'))
lowpass_var.SetValue(zeolite.VarID_bool, lowpass.cast())

invert = zeolite.boolp()
invert.assign(False)
invert_var = zeolite.CzVar(args.CreateItem(zeolite.VarID_bool, 'invert'))
invert_var.SetValue(zeolite.VarID_bool, invert.cast())

mapname_handle = args.CreateItem(zeolite.VarID_string, 'map name')
mapname_str = zeolite.CzStr()
mapname_str.Attach(mapname_handle)
mapname_str.SetText('HelloWorld')

handle = args.CreateItem(zeolite.VarID_map, 'texturemap')
texture_map = zeolite.CzMap()
texture_map.Attach(handle)

handle = args.CreateItem(zeolite.VarID_map, 'heightmap')
height_map = zeolite.CzMap()
height_map.Attach(handle)

handle = args.CreateItem(zeolite.VarID_map, 'featuremap')
feature_map = zeolite.CzMap()
feature_map.Attach(handle)

handle = args.CreateItem(zeolite.VarID_map, 'typemap')
type_map = zeolite.CzMap()
type_map.Attach(handle)

args.EditUI('MapConv parameters')

# Handles to variables aren't preserved when you edit a list,
# so you have to retrieve the handles afterwards using args.GetItem
compression_var.Attach(args.GetItem('compression'))
maxheight_var.Attach(args.GetItem('max height'))
minheight_var.Attach(args.GetItem('min height'))
lowpass_var.Attach(args.GetItem('low pass'))
invert_var.Attach(args.GetItem('invert'))
mapname_str.Attach(args.GetItem('map name'))

outputfile = mapname_str.GetText()
outputfile.replace(' ','') # remove spaces
outputfile += '.smf'

# Output the maps to BMP format
hfbmp = 'heightmap.bmp'
saveMapToBMP('HF', hfbmp)

texturebmp = 'texture.bmp'
saveMapToBMP('TX', texturebmp)

metalbmp = 'metalmap.bmp'

featurebmp = 'featuremap.bmp'

typebmp = 'typemap.bmp'

cmd = 'D:\Projects\springmapping\Mapconv_v0_6\MapConv.exe'

# compression
cmd += ' -c ' + str(compression.value())

# max height
cmd += ' -x ' + str(maxheight.value())

# min height
cmd += ' -n ' + str(minheight.value())

# output filename
cmd += ' -o ' + outputfile

# texture
cmd += ' -t ' + texturebmp

# metal map
cmd += ' -m ' + metalbmp

# height map
cmd += ' -a ' + hfbmp

# feature map
#cmd += ' -f ' + featurebmp

# terrain type map
#cmd += ' -y ' + typebmp

# lowpass, smoothing
lowpass_var.GetValue(zeolite.VarID_bool, lowpass.cast())
if lowpass.value() == True:
    cmd += ' -l '

# invert height map
invert_var.GetValue(zeolite.VarID_bool, invert.cast())
if invert.value() == True:
    cmd += ' -i '

print cmd

os.system(cmd)
