#include<iostream>
#include<algorithm>
#define f(i,a,n) for(int i=a;i<=(n-1);i++)
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int suma = 0, sumb = 0,p=-1,ra=n,rb=n;
		f(i, 0, (2*n))
		{
			i % 2 == 0 ? ra-- : rb--;
			if ((i % 2 == 0) && (s[i] == '1'))
				suma++;
			else if ((i % 2 != 0) && (s[i] == '1'))
				sumb++;
			if ((suma + ra < sumb) || (suma > sumb + rb))
			{
				p = i;
				break;
			}
		}
		if (p != -1)
			cout << p+1 << "\n";
		else
			cout << 2 * n << "\n";
	}
}