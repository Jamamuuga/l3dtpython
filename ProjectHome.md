## Overview ##

Run python scripts and access the Zeolite API from Python!

To build this DLL, you will need a Visual C++ compiler, SWIG 1.3, and Python 2.5.

### Installation Instructions ###

  1. Get Python here:  http://www.python.org/ftp/python/2.5/python-2.5.msi
  1. Then get cdPython here:  http://l3dtpython.googlecode.com/files/cdPython-0.10.zip
  1. Go to D:\Install\Bundysoft\L3DT Standard 2.5 RC3 (or wherever L3DT.exe is installed) extract the cdPython.zip to here.

cdPython is now installed.  Try it out with the following steps:

  1. Get a script to try out, like HFtoBMP: http://l3dtpython.googlecode.com/files/HFtoBMP.py
  1. Create a Terrain.
  1. Start L3DT, go to cdPython->Run a Python script, browse to HFtoBMP.py, press OK, enter a filename in the text box (without the BMP extension), press OK
  1. Go to the folder where the HFtoBMP.py script is and there should be a BMP file with the filename you gave.

### How to write a Python script for Zeolite ###

Import the zeolite module in your Python code, e.g.

```
import zeolite
```

Create zeolite objects through the zeolite module, e.g.

```
str = zeolite.CzStr()
str.Create(None)
str.EditUI('Enter a filename')
```

To access the core ExtAPI object, you can reference it through the cvar attribute in the zeolite module:

```
hf = zeolite.cvar.theAPI.project_GetMap('HF')
```

Note that the following special cast functions will help in some cases:

```
foo = zeolite.zmap_to_zvar(bar) # you need to convert ZMAP to ZVAR
foo = zeolite.zlist_to_zvar(bar) # you need to convert ZLIST to ZVAR
foo = zeolite.zformat_to_zvar(bar) # you need to convert ZFORMAT to ZVAR
foo = zeolite.zfunc_to_zvar(bar) # you need to convert ZFUNC to ZVAR
foo = zeolite.zvar_to_zmap(bar) # you need to convert ZVAR to ZMAP
foo = zeolite.zvar_to_zlist(bar) # you need to convert ZVAR to ZLIST
foo = zeolite.zvar_to_zfunc(bar) # you need to convert ZVAR to ZFUNC
foo = zeolite.zvar_to_zformat(bar) # you need to convert ZVAR to ZFORMAT
```

For the full zeolite API reference, see http://www.bundysoft.com/docs/doku.php?id=zeolite:functions