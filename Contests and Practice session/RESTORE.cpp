#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
#define f(i,a,n) for(ll i=a;i<=(n-1);i++)
#define fm(i,a,n) for(ll i=(n-1);i>=a;i--)
#define in insert
using namespace std;
void solve()
{
	ll n;
	cin >> n;
	vector<ll> v(n),v1(n);
	f(i, 0, n)
	{
		cin >> v[i];
	}
	int p = n;
	fm(i, 0, n)
	{
		if (v[i] == (i + 1))
		{
			v[i]=p;
			p++;
		}
		else
		{
			v[i]=v[v[i]-1];
		}
	}
	f(i, 0, n)
	{
		cout << v[i] << " ";
	}
	cout << "\n";
	return;
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