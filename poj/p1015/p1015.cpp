#include <iostream>
#include <memory.h>
#include <vector>
#include <math.h>
using namespace std;

int d[201],p[201],v[202],s[202],f[21][802],n,m,FIX,cases=0;
vector<int> path[21][802];

void memcln()
{
	memset(f,-1,sizeof(f));
	for (int i=0;i<m;i++)
		for (int j=0;j<=801;j++)
		path[i][j].clear();
}

void dp()
{
	f[0][FIX]=0;
	for (int k=1;k<=n;k++)
		for (int i=m-1;i>=0;i--)
			for (int j=0;j<2*FIX;j++)
			{
				if (f[i][j]>=0)
				   if (f[i+1][j+v[k]]<=f[i][j]+s[k])
				   {
				   	  f[i+1][j+v[k]]=f[i][j]+s[k];
				   	  path[i+1][j+v[k]]=path[i][j];
				   	  path[i+1][j+v[k]].push_back(k);
				   }
			}
}

int main()
{
	while (cin>>n>>m && n)
	{	
		for (int i=1;i<=n;i++) scanf("%d%d",&d[i],&p[i]);
		memcln();
		FIX=m*20;
		for (int i=1;i<=n;i++)
		{
			v[i]=d[i]-p[i];
			s[i]=d[i]+p[i];
		}
		
		dp();
		
		int i;
		for(i = 0; f[m][FIX+i] == -1 && f[m][FIX-i] == -1; i++); 
		int t=(f[m][FIX+i]>f[m][FIX-i])?i:-i;
		
		cases++;
		cout<<"Jury #"<<cases<<endl;
		cout<<"Best jury has value "<<(f[m][FIX+t]+t)/2<<" for prosecution and value "<<(f[m][FIX+t]-t)/2<<" for defence:"<<endl;
		for (int i=0;i<m;i++) cout<<" "<<path[m][FIX+t][i];
		cout<<endl<<endl;
		
	}
	return 0;
}
