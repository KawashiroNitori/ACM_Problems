#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
using namespace std;

struct DNA
{
	int inv;
	char str[51];
	char st[51];
};

int cmp(const void *a,const void *b)
{
    struct DNA *aa=(DNA *)a;
    struct DNA *bb=(DNA *)b;
    return ((aa->inv>bb->inv)?1:-1);
}

int L[250],R[250];
int n,m;

void Merge(int *a,int l,int mid,int r,int &inv)
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

void merge_sort(int *a,int l,int r,int &inv)
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

    DNA a[101];
	int arr[51];

    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        cin>>a[i].str;
        a[i].inv=0;
        for (int j=0;j<n;j++)
            arr[j]=a[i].str[j];
        merge_sort(arr,0,n-1,a[i].inv);
    }

    qsort(a,m,sizeof(a[0]),cmp);
	for (int i=0;i<m;i++)
		cout<<a[i].str<<endl;
    return 0;
}
