from xml.dom import minidom
from xml.dom.minidom import getDOMImplementation
import itertools

template = """
class %s
{
public:
%s(istream &is)
{
        %s
}
void serialTion(ostream &os)
{
	%s
}
%s
%s
private:
        %s
};
"""
def myprint(classname, value, length):
        getvalue="\n".join([ "string get%s()\n{\n\tstring value;\n\tvalue = %s.getValue();\n\treturn value;\n}" % i for i in itertools.izip(value, value)])
        setvalue="\n".join([ "void set%s(string data)\n{\n\t%s.setValue(data)\n}" % i for i in itertools.izip(value, value)])
        serialize="\n\t".join([ "is >> %s;" % (i) for i in value])
        serialTion="\n\t".join([ "os << %s;" % (i) for i in value])
        field = "\n\t".join([ "ascii<%s> %s;" % i for i in itertools.izip(length, value)])
        classname="".join([i.capitalize() for i in classname.split("_")])
        print template %(classname,classname, serialize,serialTion, getvalue, setvalue, field)

def print_class(node):
        value=[]
        length=[]
        classname  = node.getAttribute("name")
        for j in node.childNodes:
                if j.localName == 'field':
                        value.append(j.getAttribute("name"))
                        length.append(j.getAttribute("length"))
        myprint(classname, value, length)

doc=minidom.parse("test.xml")
root=doc.documentElement
for i in root.childNodes:
        if i.localName == 'messageDefinition':
                print_class(i)
	

				
