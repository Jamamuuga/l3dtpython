#	$Id$
#
#	cdPython
#	Copyright (C) 2007  A. Carl Douglas
#	
#

CC= g++ -Wall
CFLAGS= -I"D:\Install\Python25\Include"
LFLAGS= -L"D:\Install\Python25\libs"
LIBS= -lcomdlg32 -lpython25
SWIG= swig
RM= del
CP= copy
ZIP= 7z

IF= zeolite.i
SRC= $(wildcard *.cpp) $(IF).cpp
OBJ= $(SRC:.cpp=.o)

DLL= cdPython.dll

PYTHON=python25

L3DTDIR= D:\Install\Bundysoft\L3DT Standard 2.5 RC3
L3DTEXTDIR= D:\Install\Bundysoft\L3DT Standard 2.5 RC3\Extensions

LIBZEOLITEDIR= ../Plugin API
LIBZEOLITE= libzeolite.a

all: clean $(LIBZEOLITE) swig $(DLL)

install:
	$(CP) $(DLL) "$(L3DTEXTDIR)\$(DLL)"
#	$(CP) ".\Release\cdPython.dll" "D:\Install\Bundysoft\L3DT Standard 2.5 RC3\Extensions\"
#	$(CP) ".\zeolite.py" "D:\Install\Bundysoft\L3DT Standard 2.5 RC3\"
#	$(CP) ".\License.txt" "D:\Install\Bundysoft\L3DT Standard 2.5 RC3\Extensions\cdPythonLicense.txt"
#	$(RM) "D:\Install\Bundysoft\L3DT Standard 2.5 RC3\zeolite.pyc"
#	cd "D:\Install\Bundysoft\L3DT Standard 2.5 RC3\"
#	$(ZIP) a -tzip cdPython.zip "Extensions\cdPython.dll"
#	$(ZIP) a -tzip cdPython.zip "Extensions\cdPythonLicense.txt"
#	$(ZIP) a -tzip cdPython.zip "zeolite.py"
#	$(RM) "D:\Install\Bundysoft\L3DT Standard 2.5 RC3\Extensions\cdPython.dll"
#	$(RM) "D:\Install\Bundysoft\L3DT Standard 2.5 RC3\Extensions\cdPythonLicense.txt"
#	$(RM) "D:\Install\Bundysoft\L3DT Standard 2.5 RC3\zeolite.py"
#	$(ZIP) x cdPython.zip

libpython:
	pexports "C:/WINDOWS/system32/$(PYTHON).dll" > $(PYTHON).def
	dlltool --dllname $(PYTHON).dll --def $(PYTHON).def --output-lib lib$(PYTHON).a
#	reimp "D:\Install\Python25\libs\python25.lib"
	$(CP) lib$(PYTHON).a "D:\Install\Python25\libs"

$(LIBZEOLITE):
	cd "../Plugin API" && $(MAKE)

swig:
	$(SWIG) -c++ -python -v -o $(IF).cpp $(IF)

$(DLL): $(OBJ)
	$(CC) $(CFLAGS) -shared -o $@ $^ "$(LIBZEOLITEDIR)/$(LIBZEOLITE)" -Wl,--kill-at,--add-stdcall-alias $(LFLAGS) $(LIBS)
	
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(IF).cpp $(OBJ) $(DLL)

.PHONY: clean
 


