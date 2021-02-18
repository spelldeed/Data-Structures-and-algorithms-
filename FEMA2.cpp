#include<iostream>
#include<algorithm>
#include<queue>
#define ll long long int
#define f(i,a,n) for(ll i=a;i<=(n-1);i++)
using namespace std;
void solve()
{
	int n, k,cnt=0;
	cin >> n >> k;
	queue<ll> mg;
	queue<ll> fe;
	string s;
	cin >> s;
	f(i, 0, n)
	{
		if (s[i] == 'I')
			fe.push(i);
		if (s[i] == 'M')
			mg.push(i);
		if (s[i] == 'X' || (i == (n - 1)))
		{
			int l, r, cc;
			while (!mg.empty() && !fe.empty())
			{
				cc = 0;
				l = min(fe.front(), mg.front());
				r = max(fe.front(), mg.front());
				f(j, l, r + 1)
				{
					if (s[i] == ':')
						cc++;
				}
				if (k + 1 - abs(l - r) - cc > 0)
				{
					cnt++;
					fe.pop();
					mg.pop();
				}
				else if (mg.front() > fe.front())
					fe.pop();
				else
					mg.pop();
			}
			while (!mg.empty())
				mg.pop();
			while (!fe.empty())
				fe.pop();
		}
	}
	cout << cnt << "\n";
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}