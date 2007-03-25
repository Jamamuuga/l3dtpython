#	$Id$
#
#	cdPython
#	Copyright (C) 2007  A. Carl Douglas
#	
#

CC= g++
CFLAGS= -I"D:\Install\Python25\Include"
LFLAGS= -L"D:\Install\Python25\libs"
LIBS= -l$(PYTHON) -lcomdlg32
SWIG= swig
RM= del

IF= zeolite.i
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
	
DLL= cdPython.dll

PYTHON=python25

LIBZEOLITEDIR= ../Plugin API
LIBZEOLITE= libzeolite.a

all: clean $(LIBZEOLITE) swig $(DLL)

libpython:
	pexports "C:/WINDOWS/system32/$(PYTHON).dll" > $(PYTHON).def
	dlltool --dllname $(PYTHON).dll --def $(PYTHON).def --output-lib lib$(PYTHON).a

$(LIBZEOLITE):
	cd "../Plugin API" && $(MAKE)

swig:
	$(SWIG) -c++ -python -v -o $(IF).cpp $(IF)

$(DLL): $(OBJ)
	$(CC) $(CFLAGS) -shared -o $@ $^ "$(LIBZEOLITEDIR)/$(LIBZEOLITE)" -Wl,--kill-at,--add-stdcall-alias $(LFLAGS) $(LIBS)
	
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJ) $(DLL)

.PHONY: clean
 


