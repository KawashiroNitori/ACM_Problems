#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int r,n,ans;
    int a[1001];
    while (cin>>r>>n && ~r)
    {
        ans=0;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        int i=1;
        while (i<=n)
        {
            int s,p;
            s=a[i++];
            while (i<=n && a[i]<=s+r)
                i++;
            p=a[i-1];
            while (i<=n && a[i]<=p+r)
            i++;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
