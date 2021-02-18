#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<=(n-1);i++)
using namespace std;
bool great(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
	return(a.second > b.second);
}
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll a, b;
		cin >> a >> b;
		vector<pair<ll, ll>> v;
		fo(i, 2, ll(sqrt((a*b)/2)))
		{
			v.push_back(make_pair((a * b) % (i*i), i));
		}
		sort(v.begin(), v.end());
		ll upr;
		fo(i, 0, v.size())
		{
			if (v[i].first > v[0].first)
			{
				upr = i;
				break;
			}
		}
		sort(v.begin(), v.begin()+upr, great);
		cout << v[0].second << "\n";
	}
}