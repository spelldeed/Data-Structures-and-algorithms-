#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

#define ll long long int
#define f(i,a,n) for(ll i=a;i<=(n-1);i++)
#define fm(i,a,n) for(ll i=(n-1);i>=0;i--)
using namespace std;
int main()
{
	ll n, vn, wn,a,b;
	cin >> n >> vn >> wn;
	//stack<pair<ll, ll>> st;
	vector<pair<ll, ll>> vt(n);
	
	f(i, 0, n)
	{
		cin >> a>>b;
		vt.push_back(make_pair(a, b));
	}
	sort(vt.rbegin(), vt.rend());
	vector<ll> v(vn), w(wn),f;
	
	/*f(i, 0, n)
	{
		st.push({ vt[i].first, vt[i].second });
	}
	*/
	f(i, 0, vn)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	
	f(i, 0, wn)
	{
		cin >> w[i];
	}
	sort(w.begin(), w.end());
	//******************************* THIS COMMENT SOLUTION WILL CAUSE TLE!!!!!!!! hence not used************************
	/*f(i, 0, vn)
	{
		f(j, 0, wn)
		{
		    if(st.empty())
			     break;
			if ((st.top().first >= v[i]) && (st.top().second <= w[j]))
			{
				f.push_back(w[j] - v[i] + 1);
			}
			else if (st.top().first < v[i])
			{
				st.pop();
				i = 0;
				j = 0;
				break;
			}
		}
	}*/
	
		//sort(f.begin(), f.end());
		//cout << f[0] << "\n";
	
	f(i, 0, n)
	{
		auto tb = upper_bound(v.begin(), v.end(), vt[i].first), te = lower_bound(w.begin(), w.end(), vt[i].second);
		if ((tb == v.begin())||(te==w.end()))
			continue;
		tb--;
		f.push_back(*te - *tb + 1);
	}
	sort(f.begin(), f.end());
	cout << f[0] << "\n";
}