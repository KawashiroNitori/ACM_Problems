#include <iostream>
using namespace std;

void swap(int& a,int& b)
{
    int t;
    t=a;
    a=b;
    b=t;
}

int main()
{
    int n;
    long long ans=0;
    int a[20001];
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    while (n>1)
    {
        int min1=1,min2=2;
        if (a[min1]>a[min2])
            swap(min1,min2);
        for (int i=3;i<=n;i++)
            if (a[i]<a[min1])
            {
                min2=min1;
                min1=i;
            }
            else if (a[i]<a[min2])
                min2=i;

        int t=a[min1]+a[min2];
        ans+=t;
        if (min1==n)
            swap(min1,min2);
        a[min1]=t;
        a[min2]=a[n];
        n--;
    }
    cout<<ans<<endl;
    return 0;
}
