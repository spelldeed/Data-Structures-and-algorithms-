#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<=(n-1);i++)
using namespace std;
ll commoners(set<string> &a, set<string> &b)
{
	vector<string> vf(min(a.size(), b.size()));
	auto it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), vf.begin());
	return(it - vf.begin());
}
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		vector<string> v;
		fo(i, 0, n)
		{
			cin >> v[i];
		}
		map<string, set<string>> m;
		fo(i, 0, n)
		{
			m[v[i].substr(1)].insert(v[i].substr(0, 1));
		}

		ll cnt = 0, c;
		for (auto x : m)
		{
			for (auto y : m)
			{
				if (x != y)
				{
					c = commoners(x.second, y.second);
					cnt += ((x.second.size() - c) * (y.second.size() - c));
				}
			}
		}
		cout << cnt << "\n";
	}
	return(0);
}