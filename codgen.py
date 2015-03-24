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
        cout << DateTime << UPSvolteage<<endl;
}
 //string getCreateDatTime()
private:
        %s
};
"""
def myprint(classname, value, length):
        serialize="\n\t".join([ "is >> %s;" % (i) for i in value])
        field = "\n\t".join([ "ascii<%s> %s;" % i for i in itertools.izip(length, value)])
        print template %(classname,classname, serialize, field)

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
	

				
