#include<iostream>
#include<sstream>
#include<stdio.h>
using namespace std;
int main()
{
	string buffer("1345\0\0\07efdgva",20);
	const char *ch;
	string mm("0",10);
	stringstream is;
	is << buffer;
	//cout << is.str() << endl << buffer.size()<<endl<<int(buffer[15])<<endl<<mm.size()<<endl;
	ch = buffer.data();
	printf("%s\n", ch);
}
