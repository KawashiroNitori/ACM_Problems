#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int cases,years=0,n=0;
    double erod[10001],curd;
    cin>>cases;
    while (cases--)
	{
        double x,y,d;
		cin>>x>>y;
		d=(double)sqrt(x*x+y*y);

		while (d>curd)
		{
			years++;
            curd=(double)sqrt((years*100)/3.1415926);
            erod[years]=curd;
		}

		int ans=0;
        while (d>erod[ans]) ans++;

        n++;
        cout<<"Property "<<n<<": This property will begin eroding in year "<<ans<<"."<<endl;
	}
    cout<<"END OF OUTPUT.";
	return 0;
}
