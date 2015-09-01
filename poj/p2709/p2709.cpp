#include <iostream>
#include <math.h>
using namespace std;

int n,a[20],b[20],g,g1;

void sort()
{
	int t;
	for (int i=1;i<=3;i++)
		for (int j=i+1;j<=n;j++)
			if (b[i]-a[i]<=b[j]-a[j])
			{
				t=b[i];
				b[i]=b[j];
				b[j]=t;
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
}

int main()
{
	while (cin>>n && n)
	{
		for (int i=1;i<=n;i++)
			cin>>a[i];
		cin>>g;
		g1=0;
		int max=-1,ans;
		
		for (int i=1;i<=n;i++)
			if (max<a[i])
			   max=a[i];
   		
		ans=ceil((double)max/50);   
		
		for (int i=1;i<=n;i++)
			b[i]=ans*50;
		
		while (g1<g)
		{
			sort();
			int c=b[3]-a[3];
			
			if (c==0)
			{
				ans++;
				for (int i=1;i<=n;i++)
					b[i]+=50;
				continue;
			}
			for (int i=1;i<=3;i++)
				b[i]--;
			g1++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
