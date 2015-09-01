#include <iostream>
#include <memory.h>
using namespace std;

int tstcase=0,a[50002],n=0;
int f1[50002],f2[50002];

int max(int a,int b)
{
	if (a>b) return a; else return b;
}

void dp1()
{
	int sum=0,t=-20000;
	memset(f1,-20000,sizeof(int)*n+1);
	f1[1]=a[1];
	for (int i=1;i<=n;i++)
	{
		sum+=a[i];
		t=max(sum,t);
		f1[i]=t;
		sum=max(sum,0);
	}
}

int dp2()
{
	int sum=0,ans=-20000,t=-20000;
	memset(f2,-20000,sizeof(int)*n+1);
	f2[n]=a[n];
	for (int i=n;i>=2;i--)
	{
		sum+=a[i];
		t=max(sum,t);
		f2[i]=t;
		sum=max(sum,0);
		ans=max(f1[i-1]+f2[i],ans);
	}
	return ans;
}

int main()
{
	cin>>tstcase;
	while(tstcase--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		dp1();
		int ans=dp2();
		cout<<ans<<endl;
	}
	return 0;
} 
