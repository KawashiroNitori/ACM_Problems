#include <iostream>
#include <cmath>
using namespace std;

long long exgcd(long long a,long long b,long long *x,long long *y)
{
    if (b==0)
	{
		*x=1;
		*y=0;
		return a;
	}
	else
	{
		long long r=exgcd(b,a%b,x,y);
		long long t=*x;
		*x=*y;
		*y=t-a/b**y;
		return r;
	}
}

int main()
{
	long long x,y,m,n,l,a,b,k0,t0,d,k,t;
	cin>>x>>y>>m>>n>>l;

	a=m-n;
	b=y-x;
    if (a<0) {a=-a;b=-b;}
    d=exgcd(a,l,&k0,&t0);
    if (b%d!=0)
		cout<<"Impossible"<<endl;
    else
	{
        k=k0*b/d;
        t=t0*b/d;
        l=l/d;
        if (k>=0)
			k%=l;
        else
			k=k%l+l;
        cout<<k<<endl;
	}
	return 0;
}
