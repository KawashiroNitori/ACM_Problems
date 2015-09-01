#include <iostream>
using namespace std;

int modexp(int a,int b,int n)
{
	unsigned long long t=1;

    if (b==0)
		return 1;
	if (b==1)
		return a%n;
    t=modexp(a,b>>1,n);
    t=t*t%n;

    if (b&0x1)
		t=t*a%n;
	return t;
}

int main()
{
    int cases,m,h,a,b,sum;
    cin>>cases;
    while (cases--)
	{
        cin>>m>>h;
        sum=0;
        for (int i=1;i<=h;i++)
		{
			cin>>a>>b;
            sum+=modexp(a,b,m);
		}
        cout<<sum%m<<endl;
	}
	return 0;
}
