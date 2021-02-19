#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<algorithm>
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<=(n-1);i++)
#define f first
#define s second
#define pb push_back
#define in insert
#define mp make_pair
using namespace std;
bool great(pair<string, ll> &x, pair<string, ll> &y)
{
	return(x.second > y.second);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n, m, k,a,b,cnt=0;
		cin >> n >> m >> k;
		set<pair<ll, ll>> st;
		fo(i, 0, k)
		{
			cin >> a >> b;
			st.in({ a,b });
		}
		
		for(auto i:st)
		{
			a = i.f, b = i.s;
			if (st.find({ a - 1,b }) == st.end())
				cnt += 1;
			if (st.find({ a +1,b }) == st.end())
				cnt += 1;
			if (st.find({ a ,b - 1 }) == st.end())
				cnt += 1;
			if (st.find({ a ,b + 1 }) == st.end())
				cnt += 1;
		}
		cout << cnt << "\n";
	}
}