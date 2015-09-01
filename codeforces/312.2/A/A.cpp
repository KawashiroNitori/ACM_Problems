#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n,t1,t2,ans1=0,ans2=0;
    bool rev=false;
    map<int,int> tree1,tree2;
    tree1[0]=0;
    map<int,int>::iterator iter,temp;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>t1>>t2;
        tree1[t1]=t2;
    }

    tree2=tree1;

    iter=tree1.find(0);
    rev=false;
    do
    {
        ans1+=iter->second;
        cout<<iter->first<<endl;

        tree1.erase(iter);
        iter=temp;
        rev=!rev;
    }while ((!rev && iter!=tree1.end()) || (rev && iter!=tree1.begin()));

/*
    iter=tree2.find(0);
    rev=true;
    do
    {
        ans2+=iter->second;
        if (rev)
            tree2.erase(iter--);
        else
            tree2.erase(iter++);
        rev=!rev;
    }while ((!rev && iter!=tree2.end()) || (rev && iter!=tree2.begin()));*/

    if (ans1<ans2)
        ans1=ans2;

    cout<<ans1<<endl;
    return 0;
}
