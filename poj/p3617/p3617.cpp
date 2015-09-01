#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n,i,j;
    char ch;
    char s[30001];
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>s[i];
    int l,r;
    l=1;
    r=n;
    n=0;
    while (l<=r)
    {
        i=l-1;
        j=r+1;
        while (i<j && s[++i]==s[--j]);
        if (s[i]>s[j])
        {
            ch=s[r];
            r--;
        }
        else
        {
            ch=s[l];
            l++;
        }

        printf("%c",ch);
        if (++n%80==0)
            printf("\n");
    }
    cout<<endl;
    return 0;
}
