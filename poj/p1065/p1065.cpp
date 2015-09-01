#include <iostream>
#include <memory.h>
using namespace std;

int cases,l[5001],w[5001],n;
bool v[5001];

void qsort(int left,int right)
{
	int i,j,midl,midw,t;
	i=left;
	j=right;
	midl=l[(i+j)/2];
	midw=w[(i+j)/2];
	do
	{
	  while (l[i]<midl) i++;
	  while (l[j]>midl) j--;
	  if (i<=j)
 	  {
 	  	t=l[i];
 	  	l[i]=l[j];
 	  	l[j]=t;
 	  	t=w[i];
 	  	w[i]=w[j];
 	  	w[j]=t;
 	  	i++;
 	  	j--;
	  }
	}
	while (i<=j);
 	if (i<right) qsort(i,right);
 	if (left<j) qsort(left,j);	
}

void sort()
{
	int t;
	for (int i=1;i<=n-1;i++)
		for (int j=i+1;j<=n;j++)
			if (l[i]>l[j] || (l[i]==l[j] && w[i]>=w[j]))
			{
				t=l[i];
				l[i]=l[j];
				l[j]=t;
				t=w[i];
				w[i]=w[j];
				w[j]=t;
			}
}

int main()
{
	cin>>cases;
	while (cases--)
	{
		int ans=0,w1=0,fin=0;
		cin>>n;
		for (int i=1;i<=n;i++)
			cin>>l[i]>>w[i];
		
		memset(v,false,sizeof(v));
		
		sort();
		while (fin<n)
		{
			ans++;
			for (int i=1;i<=n;i++)
				if (!v[i] && w1<=w[i])
				{
					fin++;
					v[i]=true;
					w1=w[i];
				}
			w1=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}
