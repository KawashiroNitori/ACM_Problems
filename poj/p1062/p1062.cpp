#include <iostream>
#include <memory.h>
using namespace std;

const int MAXINT=0x7FFFFFFF;
int ans,n,m,t,k,a[101][101],lv[101];
bool v[101];

int dijkstra()
{
	int d[101];
	int min,j;
	for (int i=1;i<=m;i++) d[i]=a[0][i];
	d[0]=0;
	
	while (1)
	{
		min=MAXINT;
		j=0;
		for (int i=1;i<=m;i++)
			if (!v[i] && d[i]<min)
			{
				min=d[i];
				j=i;
			}
			
		if (j==0) break;
		v[j]=true;
		
		for (int i=1;i<=m;i++)
			if (!v[i] && a[j][i]!=-1 && a[j][i]+d[j]<d[i]) d[i]=a[j][i]+d[j];
	}
	return d[1];
}

int main()
{
	ans=MAXINT;
	cin>>n>>m;
	memset(a,-1,sizeof(a));
	for (int i=1;i<=m;i++)
	{
		cin>>a[0][i]>>lv[i]>>t;
		for (int j=1;j<=t;j++) 
		{
			cin>>k;
			cin>>a[k][i];
		}
	}
	
	for (int i=1;i<=m;i++)
	{
		int maxlv=lv[i];
		
		for (int j=1;j<=m;j++)
		if (lv[i]<lv[j] || lv[i]-lv[j]>n)
  		   v[j]=true;
  		else
		   v[j]=false;  
		   
	    t=dijkstra();
	    if (ans>t) ans=t;
	}
	cout<<ans<<endl;
	return 0;
} 
