#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define ll long long int
#define fo(i,a,n)  for(ll i=a;i<=(n-1);i++)
#define f first
#define second
using namespace std;
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		vector<ll> v(n);
		fo(i, 0, n)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		cout << abs(v[0] - v[n - 1]) + abs(v[0] - v[1]) + abs(v[1] - v[n - 1]) << "\n";
	}
	return(0);
}