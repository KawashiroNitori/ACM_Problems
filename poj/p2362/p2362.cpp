#include <iostream>
#include <algorithm>
using namespace std;

int cmp(const void* a,const void* b)
{
    return (int*)b-(int*)a;
}

bool dfs(int* stick,bool* v,int side,int n,int sides,int len,int first)
{
    //cout<<side<<' '<<n<<' '<<sides<<' '<<len<<endl;
    if (sides==3)
        return true;
    for (int i=first;i<n;i++)
    {
        if (!v[i] && len+stick[i]<=side)
        {
            v[i]=true;
            len+=stick[i];
            if (len==side)
            {
                if (dfs(stick,v,side,n,sides+1,0,0))
                    return true;
            }
            else
            {
                if (dfs(stick,v,side,n,sides,len,i))
                    return true;
            }

            v[i]=false;
            len-=stick[i];
        }
    }
    return false;
}

int main()
{
    int cases;
    int n,stick[21],sum;
    bool v[21];
    cin>>cases;
    while (cases--)
    {
        sum=0;
        cin>>n;
        for (int i=0;i<n;i++)
        {
            cin>>stick[i];
            v[i]=false;
            sum+=stick[i];
        }

        if (n<4 || sum%4)
        {
            cout<<"no"<<endl;
            continue;
        }

        qsort(stick,n,sizeof(int),cmp);

        if (sum/4<stick[0])
        {
            cout<<"no"<<endl;
            continue;
        }

        if (dfs(stick,v,sum/4,n,0,0,0))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
