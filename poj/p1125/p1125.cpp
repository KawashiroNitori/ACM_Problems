#include <iostream>
#include <memory.h>
using namespace std;

int minp,mind,t,k,n,c[101][101];

int dijkstra(int v0)
{
	bool v[101];
	int d[101],j,min;
	
	memset(v,false,sizeof(v));
	for (int i=1;i<=n;i++)
		d[i]=(c[v0][i]==-1)?0x7fffffff:c[v0][i];
	d[v0]=0;
	
	while (1)
	{
		min=0x7fffffff;
		j=0;
		for (int i=1;i<=n;i++)
			if (!v[i] && min>d[i])
			{
				j=i;
				min=d[i];
			}
		if (j==0) break;
		v[j]=true;
		
		for (int i=1;i<=n;i++)
			if (!v[i] && c[j][i]!=-1 && c[j][i]+d[j]<d[i])
			   d[i]=c[j][i]+d[j];
	}
	int max=0;
	for (int i=1;i<=n;i++)
	{	
		if (max<d[i]) max=d[i];
		if (d[i]==0x7fffffff) return d[i];
	}
		return max;
}

int main()
{
	while (cin>>n && n)
	{
		memset(c,-1,sizeof(c));
		mind=0x7fffffff;
		for (int i=1;i<=n;i++)
		{
			cin>>k;
			for (int j=1;j<=k;j++)
			{
				cin>>t;
				cin>>c[i][t];
			}
		}
		
		for (int i=1;i<=n;i++)
		{
			t=dijkstra(i);
			if (t<mind && t!=-1)
			{
				minp=i;
				mind=t;
			}
		}
		if (mind!=0x7fffffff)
		   cout<<minp<<' '<<mind<<endl;
  		else   
 		   cout<<"disjoint"<<endl;   
	}
	return 0;
}
