#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b,ans=0,MAX,t;
    cin>>a>>b;

		MAX=(int)(a+b)/3;

        if (a>b)
		{
			t=a;
			a=b;
			b=t;
		}
        if (a<=MAX)
		{
			cout<<a<<endl;
			return 0;
		}
		else
		{
            while (a>0 && b>0 && a+b>=3)
			{
                a--;
                b--;
                if (a>b)
					a--;
				else
					b--;
				ans++;
			}
		}


	cout<<ans<<endl;

    return 0;
}
