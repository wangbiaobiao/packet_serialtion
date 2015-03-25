#include<iostream>
#include<sstream>
#include<string.h>
using namespace std;
template <int L> class ascii
{
public:
string getValue()
{
	string value(data,L);
	return value;
}
void setValue(string value)
{
	strncpy(data,value.data(),L);
}
private:
	char data[L+1];
friend	istream & operator >>(istream &is, ascii & mydata)
	{
		is.read(mydata.data, L);
		return is;
	}
friend	ostream & operator <<(ostream &is, ascii & mydata)
	{
		is.write(mydata.data, L);
		return is;
	}
};
class RelayHertbeat
{
public:
RelayHertbeat(istream &is)
{
	is >> DateTime;
	is >> UPSvolteage;
	is >> relayTemprature;
	is >> relayCurrent;
	
}
void serialTion(ostream &os)
{
	os << DateTime;
	os << UPSvolteage;
	os << relayTemprature;
	os << relayCurrent;
}
string getDateTime()
{	
	string value;
	value = DateTime.getValue();
	return value;
}
void setDateTime(string data)
{
	DateTime.setValue(data);

}
private:
ascii<2> DateTime;
ascii<1> UPSvolteage;
ascii<1> relayTemprature;
ascii<1> relayCurrent;
};

/*class packageFactory()
{
 static package* createPackage(istream&)
{
	stream >> type;
	switch (type) {
	case HeartBeat::typeName:
		return new HearBeat(stream);
	

}*/
int main()
{
	string str("h\0llo",6);
	istringstream iss(str);
	RelayHertbeat r(iss);
	ostringstream oss;
	cout<<r.getDateTime()<<endl;
	r.serialTion(oss);
	cout<<oss.str()<<endl;
}
