#include <iostream>
#include <cstdio>
using namespace std;

int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int cases,l,n,minans,maxans;
    int a;
    cin>>cases;
    while (cases--)
    {
        maxans=0;
        minans=0;
        cin>>l>>n;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            maxans=max(max(l-a,a),maxans);
            minans=max(min(l-a,a),minans);
        }
        cout<<minans<<' '<<maxans<<endl;
    }
    return 0;
}
