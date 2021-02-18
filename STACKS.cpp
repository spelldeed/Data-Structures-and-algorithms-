#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<=(n-1);i++)
#define f first
#define s second
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
		multiset<ll> s;
		fo(i, 0, n)
		{
			if (s.upper_bound(v[i]) == s.end())
				s.insert(v[i]);
			else
			{
				s.erase(s.find(*(s.upper_bound(v[i]))));
				s.insert(v[i]);
			}
		}
		cout << s.size() << " ";
		for (auto x : s)
		{
			cout << x << " ";
		}
		cout << "\n";
	}
	return(0);
}