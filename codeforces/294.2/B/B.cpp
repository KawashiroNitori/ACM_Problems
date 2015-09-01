#include <iostream>
#include <algorithm>
using namespace std;

int cmp(const void *a,const void *b)
{
	int *aa=(int *)a;
	int *bb=(int *)b;
    return *aa-*bb;
}

int main()
{
    int n,temp;
    int a[100010],b[100010],c[100010];
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
	for (int i=0;i<n-1;i++)
		cin>>b[i];
	for (int i=0;i<n-2;i++)
		cin>>c[i];

    qsort(a,n,sizeof(a[0]),cmp);
    qsort(b,n-1,sizeof(a[0]),cmp);
    qsort(c,n-2,sizeof(a[0]),cmp);

    for (int i=0;i<n;i++)
		if (a[i]!=b[i])
		{
			cout<<a[i]<<endl;
			break;
		}
	for (int i=0;i<n-1;i++)
		if (b[i]!=c[i])
		{
			cout<<b[i]<<endl;
			break;
		}
    return 0;
}
