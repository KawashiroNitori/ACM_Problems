#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int dx[]={0,0,-1,1};
const int dy[]={-1,1,0,0};
const int HASHKEY=1000003;
const int MAXN=362881;
const int fact[]={1,1,2,6,24,120,720,5040,40320,362880};
int top=1,last=2,now=1;
int fa[MAXN];
int move[MAXN];
int dis[MAXN];
int next[HASHKEY];
int states[HASHKEY];
int q[MAXN+10];
int d[9];

int getHash(int n)
{
	return n%HASHKEY;
}

int getCantor(int* a)
{
	int t,ans=0;
    for (int i=0;i<9;i++)
	{
		t=0;
		for (int j=i+1;j<=8;j++)
			if (a[i]>a[j])
				t++;
        ans=ans+fact[8-i]*t;
	}
	return ans;
}


int getNum(int* a)
{
    int res=0;
    for (int i=0;i<=8;i++)
		res=res*10+a[i];
	return res;
}

void exdNum(int n,int* a)
{
    for (int i=8;i>=0;i--)
	{
        a[i]=n%10;
        n/=10;
	}
}

bool insert(int node)
{
	int key=getHash(node);
    while (next[key])
	{
        if (states[next[key]]==node)
			return false;
		key=next[key];
	}
    next[key]=now;
    states[now]=node;
    now++;
    return true;
}

void bfs(int node)
{
	int oldst[9],newst[9],i,x,y,z,newx,newy,newz,oldnode,newnode;
    fa[0]=0;
    dis[0]=0;
    q[top]=node;
    insert(node);
    while (top<last)
	{
        oldnode=q[top];
        exdNum(oldnode,oldst);
        for (i=0;i<9;i++)
            if (oldst[i]==0)
				break;

		x=i/3;
		y=i%3;
        z=i;
        for (i=0;i<4;i++)
		{
            newx=x+dx[i];
            newy=y+dy[i];
            if (newx>=0 && newy>=0 && newx<3 && newy<3)
			{
                newz=newx*3+newy;
                memcpy(newst,oldst,sizeof(oldst));
                newst[newz]=oldst[z];
                newst[z]=oldst[newz];
                oldnode=getNum(newst);
                if (insert(oldnode))
				{
                    int id_old=getCantor(oldst);
                    int id_new=getCantor(newst);
                    fa[id_new]=id_old;
                    dis[id_new]=dis[id_old]+1;
                    move[id_new]=i;
                    q[last]=oldnode;
                    last++;
				}
			}
		}
		top++;
	}
}


void solve()
{
    int key=getNum(d);
    int l=0,ind;
    bool flag=false;
    for (int i=1;i<=last;i++)
		if (key==q[i])
		{
			flag=true;
			break;
		}
	if (flag)
	{
        ind=getCantor(d);
        l=ind;
        cout<<dis[ind]<<endl;
        for (int i=dis[ind];i>=1;i--,l=fa[l])
		{
            switch (move[l])
            {
            	case 0:
					cout<<'r';
					break;
				case 1:
					cout<<'l';
					break;
				case 2:
					cout<<'d';
					break;
				case 3:
					cout<<'u';
					break;
            }
		}
		cout<<endl;
	}
	else
		cout<<"unsolvable"<<endl;
}

int main()
{
	char c;
	int i=0;

	bfs(123456780);
    while(~scanf("%c",&c))
	{
		if (c==' ' || c=='\n')
			continue;
        if (c=='x')
            d[i]=0;
		else
            d[i]=c-'0';
        i++;
        if (i%9==0)
		{
			solve();
			i=0;
		}
	}
	return 0;
}
