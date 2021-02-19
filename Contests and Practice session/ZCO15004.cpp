#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define ll long long int
#define f(i,a,n) for(ll i=a;i<=(n-1);i++)
#define m 50000000
#define x 100000
#define y 500
using namespace std;
//bool byY(pair<ll, ll>& a, pair<ll, ll>& b)
//{
	//return(a.second < b.second);
//}
int main()
{
	ll n,p,q,last;
	cin >> n;
	vector<ll> v(x+1,y);
	
	f(i, 0, n)
	{
		cin >> p >> q;
		v[p] = min(v[p],q);
	}
	ll dist,area=0;
	v[x] = 0;
	f(i, 1, y+1)
	{
		last = 0;
		f(j, 1, x+1)
		{
			if (v[j] < i)
			{
				dist = j - last;
				dist *= i;
				area = max(area, dist);
				last = j;
			}
		}
	}
	cout << area << "\n";
	
	/*sort(v.begin(), v.end());
	ll a, b, c, d;
	a = v[0].first;
	b = v[n - 1].first;
	sort(v.begin(), v.end(), byY);
	c = v[0].second;
	d = v[n - 1].second;
	vector<ll> vf;
	vf.push_back(x * c);
	if(x-b>y)
	    vf.push_back(y * (x - b));
	//vf.push_back(x * (y - d));
	if(a>y)
	    vf.push_back(y * (a));
	sort(vf.rbegin(), vf.rend());
	cout << vf[0] << "\n";*/
	return(0);
}
