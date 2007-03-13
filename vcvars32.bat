@echo off

Set PATH=C:\Program Files\Microsoft Visual C++ Toolkit 2003\bin;%PATH%
Set INCLUDE=C:\Program Files\Microsoft Visual C++ Toolkit 2003\include;%INCLUDE%
Set LIB=C:\Program Files\Microsoft Visual C++ Toolkit 2003\lib;%LIB%

Rem Modify paths as necessary below...

Set PATH=%PATH%;D:\Install\Python25;D:\Projects\swig\swigwin-1.3.31;D:\Install\7-Zip;
Set INCLUDE=%INCLUDE%;D:\Install\Python25\include;C:\Program Files\Microsoft Platform SDK\Include;
Set LIB=%LIB%;D:\Install\Python25\libs;C:\Program Files\Microsoft Visual Studio .NET 2003\Vc7\lib;C:\Program Files\Microsoft Platform SDK\Lib;



echo Setting environment for using Microsoft Visual C++ 2003 Toolkit.
echo (If you have another version of Visual Studio or Visual C++ installed and wish
echo to use its tools from the command line, run vcvars32.bat for that version.)
echo.
echo Thank you for choosing the Visual C++ Toolkit 2003!  Get started quickly by
echo building the code samples included in the "Samples" directory.  Each sample
echo includes a short whitepaper discussing the Visual C++ features, and a batch
echo file for building the code.
echo.
echo Type "cl /?" for brief documentation on compiler options.
echo.
echo Visit http://msdn.microsoft.com/visualc/using/documentation/default.aspx for
echo complete compiler documentation.


del /Q .\Release\*.*
rmdir .\Release
mkdir .\Release

swig.exe -c++ -python -Fmicrosoft -v -o zeolite.i.cpp zeolite.i

cl /Od /GL /D "STATIC_LINKED" /D "_WINDLL" /D "_MBCS" /FD /EHsc /MD /Yc"stdafx.h" /Fp"Release\cdPython.pch" /Fo"Release\\" /W3 /c /Wp64 /Zi /TP .\stdafx.cpp

cl /Od /GL /D "STATIC_LINKED" /D "_WINDLL" /D "_MBCS" /FD /EHsc /MD /Fo"Release\\" /W3 /c /Wp64 /Zi /TP "..\Plugin API\zVar.cpp"   "..\Plugin API\zStr.cpp"   "..\Plugin API\zProgBox.cpp"   "..\Plugin API\zMap.cpp"   "..\Plugin API\zList.cpp"   "..\Plugin API\zFunc.cpp"   "..\Plugin API\zFormat.cpp"   "..\Plugin API\zComboSel.cpp"   "..\Plugin API\zColour.cpp"   "..\Plugin API\zBuffer.cpp"   "..\Plugin API\ExtAPI.cpp"   .\zeolite.i.cpp   .\cdPython.cpp

link "/OUT:D:\Projects\l3dtdev\l3dtpython\cdPython\Release\cdPython.dll" /INCREMENTAL:NO /DLL "/DEF:cdPython.def" /SUBSYSTEM:WINDOWS /OPT:NOREF /OPT:NOICF /LTCG /MACHINE:X86 python25.lib kernel32.lib user32.lib comdlg32.lib shell32.lib ".\Release\cdPython.obj" ".\Release\stdafx.obj" ".\Release\zeolite.i.obj" ".\Release\ExtAPI.obj" ".\Release\zBuffer.obj" ".\Release\zColour.obj" ".\Release\zComboSel.obj" ".\Release\zFormat.obj" ".\Release\zFunc.obj" ".\Release\zList.obj" ".\Release\zMap.obj" ".\Release\zProgBox.obj" ".\Release\zStr.obj" ".\Release\zVar.obj" 

Rem Install and bundle into zip file

cp ".\Release\cdPython.dll" "D:\Install\Bundysoft\L3DT Standard 2.5 RC3\Extensions\"
cp ".\zeolite.py" "D:\Install\Bundysoft\L3DT Standard 2.5 RC3\"
cp ".\License.txt" "D:\Install\Bundysoft\L3DT Standard 2.5 RC3\Extensions\cdPythonLicense.txt"
del "D:\Install\Bundysoft\L3DT Standard 2.5 RC3\zeolite.pyc"

cd "D:\Install\Bundysoft\L3DT Standard 2.5 RC3\"

7z a -tzip cdPython.zip "Extensions\cdPython.dll"
7z a -tzip cdPython.zip "Extensions\cdPythonLicense.txt"
7z a -tzip cdPython.zip "zeolite.py"

Rem Delete preinstall files so I have to test the zip file

del "D:\Install\Bundysoft\L3DT Standard 2.5 RC3\Extensions\cdPython.dll"
del "D:\Install\Bundysoft\L3DT Standard 2.5 RC3\Extensions\cdPythonLicense.txt"
del "D:\Install\Bundysoft\L3DT Standard 2.5 RC3\zeolite.py"

Rem Extract from zip

7z x cdPython.zip