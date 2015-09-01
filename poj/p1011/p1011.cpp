#include <iostream>
#include <algorithm>
using namespace std;

int n;

bool cmp(int a,int b)
{
	return a>b;
}

bool dfs(int *stick,bool *v,int len,int tar,int s,int num)
{
    if (num==n)
		return true;
    int temp=-1;
	for (int i=s;i<n;i++)
	{
        if (v[i] || stick[i]==temp)
			continue;
        v[i]=true;

        if (stick[i]+len<tar)
			if (dfs(stick,v,len+stick[i],tar,i,num+1))
				return true;
			else
				temp=stick[i];
		else if (stick[i]+len==tar)
			if (dfs(stick,v,0,tar,0,num+1))
				return true;
			else
				temp=stick[i];
		v[i]=false;

		if (len==0)
			break;
	}
	return false;
}

int main()
{
	int stick[65],maxlen;
    bool v[65];
    while (cin>>n && n)
	{
		int sumlen=0;
        for (int i=0;i<n;i++)
		{
            cin>>stick[i];
            v[i]=false;
            sumlen+=stick[i];
		}

		sort(stick,stick+n,cmp);

		maxlen=stick[0];
		bool flag=false;

        for (int i=maxlen;i<=sumlen-maxlen;i++)
		{
            if (!(sumlen%i) && dfs(stick,v,0,i,0,0))
			{
                cout<<i<<endl;
                flag=true;
                break;
			}
		}

		if (!flag)
			cout<<sumlen<<endl;
	}
    return 0;
}
