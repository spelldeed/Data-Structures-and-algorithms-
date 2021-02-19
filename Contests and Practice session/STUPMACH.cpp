#include<iostream>
#include<vector>
#define f(i,a,n) for(long long int i=a;i<=(n-1);i++)
#define ll long long int
using namespace std;
void solve()
{
	ll n;
	cin >> n;
	vector<ll> v(n);
	f(i, 0, n)
	{
		cin >> v[i];
	}
	ll p = v[0];
	ll sum = 0;
	f(i, 0, n)
	{
		if (v[i] >= p)
		{
			sum += p;
		}
		else
		{
			p = v[i];
			sum += p;
		}
	}
	cout << sum << "\n";
	return;
}
int main()
{
	ll t;
	cin >>t;
	while (t--)
	{
		solve();
	}
}