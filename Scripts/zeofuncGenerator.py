import zeolite

print 'zeofuncGenerator script'

def processItem(item):
    typeId = item.GetTypeID()
    #print 'type id: ' + str(typeId) + ' name: ' + str(item.GetName())
    if (typeId == zeolite.VarID_varlist):
        varlist = zeolite.CzList()
        varlist.Attach(item.GetZVAR())
        x = 0
        while x < varlist.nItems():
            subitem = zeolite.CzVar(varlist.GetItem(x))
            #print 'var: ' + str(subitem.GetName())
            processItem(subitem)
            x = x + 1
            
    if (typeId == zeolite.VarID_ZeoFunc):
        typename = zeolite.CzStr()
        arglist = zeolite.CzList()
        func = zeolite.CzFunc()
        func.Attach(item.GetZVAR())
        zeolite.cvar.theAPI.type_GetTypeName(func.GetReturnTypeID(), typename.GetZVAR());
        func.GetArgListPrototype(arglist.GetZVAR())
        argi = 0
        definition = typename.GetText() + ' ' + func.GetName() + '('
        while argi < arglist.nItems():
            temp = zeolite.CzVar(arglist.GetItem(argi))
            temp.GetTypeName(typename.GetZVAR())
            definition += typename.GetText() + ' ' + temp.GetName()
            argi = argi + 1
            if (argi != arglist.nItems()):
                definition += ', '
        definition += ')'
        print definition
        
    return

getfunclist = zeolite.CzFunc()
if (getfunclist.GetFunc('zeofunc.GetFuncList') == False):
    print 'GetFunc failed for GetFuncList - this is pretty serious...'

funclist = zeolite.CzList()
funclist.Attach(getfunclist.Execute())

#print 'number of items: ' + str(funclist.nItems())

i = 0
while i < funclist.nItems():
    var = zeolite.CzVar(funclist.GetItem(i))
    processItem(var)
    i = i + 1
    

#funclist.EditUI('zeofuncs')