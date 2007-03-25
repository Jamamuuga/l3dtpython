# $Id$

all:
	cd "Plugin API" && $(MAKE)
	cd "cdPython" && $(MAKE)
	
clean:
	cd "Plugin API" && $(MAKE) clean
	cd "cdPython" && $(MAKE) clean