#include <iostream>
#include <memory.h>
using namespace std;

int a[1001][1001],cases,x,y,n,m;

const int MAXINT=0x7fffffff;

int max(int a,int b)
{
	if (a>b)
 	   return a;
 	else
	   return b;		   
}

int min(int a,int b)
{
	if (a>b)
	   return b;
 	else
	   return a;  
}

int dijkstra()
{
	int j,d[1001],maxx;
	bool v[1001];
	memset(v,false,sizeof(v));
	d[1]=MAXINT;
	for (int i=1;i<=n;i++)
		d[i]=a[1][i];
	while (1)
	{
		j=0;
		maxx=-1;
		for (int i=1;i<=n;i++)
			if (!v[i] && d[i]!=-1 && maxx<d[i])
			{
				maxx=d[i];
				j=i;
			}
		if (j==0) break;	
		v[j]=true;
		
		for (int i=1;i<=n;i++)
			if (!v[i])
			   d[i]=max(d[i],min(a[j][i],d[j]));
	}
	
	return d[n];
}

int main()
{
	cin>>cases;
	int ii=0;
	while (cases--)
	{
		cin>>n>>m;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				a[i][j]=-1;
				
		for (int i=1;i<=m;i++)
		{
			cin>>x>>y;
			cin>>a[x][y];
			a[y][x]=a[x][y];
		}
		
		ii++;
		printf("Scenario #%d:\n%d\n\n",ii,dijkstra());
	}
	return 0;
}
