# $Id$

all:
	cd "Plugin API" && $(MAKE)
	cd "cdPython" && $(MAKE)

install:
	cd "cdPython" && $(MAKE) install

clean:
	cd "Plugin API" && $(MAKE) clean
	cd "cdPython" && $(MAKE) clean