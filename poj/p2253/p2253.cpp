#include <iostream>
#include <math.h>
using namespace std;

int cases=0,n;
double a[1001][1001],x[1001],y[1001];
const int MAXINT=0x7fffffff;

double min(double a,double b)
{
	if (a>b)
	   return b;
	else
	   return a;   
}

double max(double a,double b)
{
	if (a<b)
	   return b;
	else
	   return a;   
}

double dijkstra()
{
	double d[1001];
	bool v[1001]={false};
	int j,minn;
	
	for (int i=1;i<=n;i++)
		d[i]=a[1][i];
	d[1]=MAXINT;
	while (1)
	{
		j=0;
		minn=MAXINT;
		for (int i=1;i<=n;i++)
			if (!v[i] && minn>d[i])
   			{
   				minn=d[i];
   				j=i;
   			}
		if (j==0) break;
		v[j]=true;
		
		for (int i=1;i<=n;i++)
			if (!v[i])
			   d[i]=min(d[i],max(a[j][i],d[j]));
	}
	return d[2];
}

int main()
{
	while (cin>>n && n)
	{
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				a[i][j]=MAXINT;
		
		for (int i=1;i<=n;i++)
		{
			cin>>x[i]>>y[i];
			for (int j=1;j<=n;j++)
			{
				a[i][j]=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
				a[j][i]=a[i][j];
			}
		}
		/*
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
				cout<<a[i][j]<<" ";
				cout<<endl;
		}
		*/
		printf("Scenario #%d\nFrog Distance = %.3f\n\n",++cases,dijkstra());
	}
	return 0;
}
