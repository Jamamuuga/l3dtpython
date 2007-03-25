#	$Id$
#
#	cdPython
#	Copyright (C) 2007  A. Carl Douglas
#	

CC= g++
CFLAGS= 
LFLAGS= 
LIBS= 
RM= del
AR= ar

SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
LIB= libzeolite.a	

all: $(LIB)

$(LIB): $(OBJ)
	$(AR) r $@ $^
	
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJ) $(LIB)

.PHONY: clean
 


