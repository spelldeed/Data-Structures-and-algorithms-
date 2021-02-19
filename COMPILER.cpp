#include<iostream>
#define ll long long int
#define f(i,a,n) for(ll i=a;i<=(n-1);i++)
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		ll res = 0, cnt = 0;
		f(i, 0, s.size())
		{
			if (s[i] == '<')
				cnt++;
			else
			{
				if (cnt == 0)
					break;
				else
				{
					cnt--;
					if (cnt == 0)
						res = i + 1;
				}
			}
		}
		cout << res << "\n";
	}
}