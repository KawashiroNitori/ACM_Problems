#include <iostream>
#include <string.h>
using namespace std;

char str[1001];

bool load()
{
	strcpy(str,"");
	cin>>str;
	return (str!="END\0")?true:false;
}

int main()
{
	while (load())
	{
		cout<<str<<endl;
	}
	return 0; 
}
