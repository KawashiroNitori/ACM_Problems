#include <iostream>
#include <cstring>
using namespace std;

bool c[105][105];

const int dx[]={0,1,1,1,0,-1,-1,-1};
const int dy[]={-1,-1,0,1,1,1,0,-1};

void dfs(int x,int y)
{
    c[x][y]=false;
    for (int i=0;i<8;i++)
        if (c[x+dx[i]][y+dy[i]])
            dfs(x+dx[i],y+dy[i]);
}

int main()
{
    int m,n,ans=0;
    char ch;
    memset(c,false,sizeof(c));
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            cin>>ch;
            if (ch=='W')
                c[i][j]=true;
        }
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            if (c[i][j])
            {
                dfs(i,j);
                ans++;
            }
    cout<<ans<<endl;
    return 0;
}
