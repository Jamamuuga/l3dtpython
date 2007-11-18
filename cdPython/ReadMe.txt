
To regenerate when the Zeolite API changes:

If methods have been removed from Zeolite, you will need to create an empty zeofuncapi.c to prevent cdPython from trying to resolve missing functions.

1) Use existing cdPython.dll extension in the new version of L3DT

2) Run script "zeofuncGenerator.py"

3) Copy output zeofuncapi.c into cdPython source directly, next to cdPython.cpp

4) zeolite.i has a line #include "zeofuncapi.c", so rebuilding cdPython will pick up the newly generated source.

