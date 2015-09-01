#include <iostream>
#include <stdio.h>
using namespace std;

int L[250002],R[250002];

void Merge(int *a,int l,int mid,int r,long long &inv)
{
	int i,j,k;
	int n1=mid-l+1;
	int n2=r-mid;
	for (i=0;i<n1;i++)
		L[i]=a[l+i];
	for (i=0;i<n2;i++)
		R[i]=a[mid+i+1];

    L[n1]=R[n2]=0x7ffffff;
	i=j=0;

	for (k=l;k<=r;k++)
        if (L[i]<=R[j])
		{
            a[k]=L[i];
            i++;
		}
		else
		{
            a[k]=R[j];
            j++;
            inv+=n1-i;
		}
}

void merge_sort(int *a,int l,int r,long long &inv)
{
	if (l<r)
	{
		int mid=(l+r)>>1;
		merge_sort(a,l,mid,inv);
		merge_sort(a,mid+1,r,inv);
        Merge(a,l,mid,r,inv);
	}
}

int main()
{
	int a[500001],n;
	long long ans;
    while (cin>>n && n)
	{
		ans=0;
        for (int i=0;i<n;i++)
			scanf("%d",&a[i]);

        merge_sort(a,0,n-1,ans);
        cout<<ans<<endl;
	}

	return 0;
}
