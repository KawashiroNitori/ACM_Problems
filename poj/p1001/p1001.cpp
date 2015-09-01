#include <iostream>
#include <memory.h>
#include <string>
using namespace std;

string s;
int n,a[201],b[201],dot;

void init()
{
	bool flag=false;
	int i;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	b[1]=1;
	b[0]=1;
	a[0]=s.size();
	for (i=1;i<=a[0];i++)
		if (s[a[0]-i]!='.')
  			a[i]=s[a[0]-i]-'0';
  		else
  		{
  			dot=a[0]-i;
  			break;
		}
	for (i;i<=a[0]-1;i++)
		a[i]=s[a[0]-i-1]-'0';
}

void himulti()
{
	int len;
	for (int i=1;i<=a[0];i++)
		for (int j=1;j<=b[0];j++)
		{
			b[i+j-1]+=a[i]*b[j];
			b[i+j]+=b[i+j-1]/10;
			b[i+j-1]=b[i+j-1]%10;
		}
		len=a[0]+b[0]+1;
		while (b[len]==0 && len>1) len--;
		b[0]=len;
}

void print()
{
	if (dot>=b[0])
	{
		b[0]=dot;
	}
	for (int i=b[0];i>=1;i--)
		if (i==dot)
			cout<<'.'<<b[i];
		else
			cout<<b[i];
	cout<<endl;
}

int main()
{
	while (cin>>s>>n)
	{
		init();
		for (int i=a[0];i>=1;i--)
			cout<<a[i];
			cout<<endl;
		dot=dot*n;
		for (int i=1;i<=n;i++)
			himulti();
		print();	
	}
	return 0;
}
