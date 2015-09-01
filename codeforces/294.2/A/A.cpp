#include <iostream>
using namespace std;


int main()
{
	int white=0,black=0;
	char ch;
	for (int i=1;i<=8;i++)
		for (int j=1;j<=8;j++)
		{
			cin>>ch;
			switch (ch)
			{
				case 'Q':
				{
					white+=9;
                    break;
				}
				case 'R':
				{
					white+=5;
                    break;
				}
				case 'B':
				{
					white+=3;
                    break;
				}
				case 'N':
				{
					white+=3;
                    break;
				}
				case 'P':
				{
					white+=1;
                    break;
				}
				case 'K':
				{

                    break;
				}
				case 'q':
				{
					black+=9;
                    break;
				}
				case 'r':
				{
					black+=5;
                    break;
				}
				case 'b':
				{
					black+=3;
                    break;
				}
				case 'n':
				{
					black+=3;
                    break;
				}
				case 'p':
				{
					black+=1;
                    break;
				}
				case 'k':
				{

                    break;
				}
			}
		}

        if (white>black)
			cout<<"White"<<endl;
		if (white==black)
			cout<<"Draw"<<endl;
		if (white<black)
			cout<<"Black"<<endl;
	return 0;
}
