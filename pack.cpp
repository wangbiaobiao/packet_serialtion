#include<iostream>
#include<sstream>
using namespace std;
template <int L> class ascii
{
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
	
	cout << DateTime << UPSvolteage<<endl;
	
}
//string getCreateDatTime()
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
	char buffer[100] = "hello";
	istringstream iss("123456");
	RelayHertbeat r(iss);
}
