#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<numeric>
#include<math.h>
#define ll long long int
#define fo(i,a,n,m) for(ll i =a;i<=(n-1);i+=m)
using namespace std;
ll GCD(ll a, ll b)
{
	if (b == 0)
		return(a);
	return(b, a % b);
}
bool isPrime(ll a)
{
	if (a == 1)
		return(false);
	if ((a % 2 == 0) || (a % 3 == 0))
		return(false);
	fo (i, 5, a, 2)
	{
		if (a % i == 0)
			return(false);
	}
	return(true);
}

int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, e, h, a, b, c;
		cin >> n >> e >> h >> a >> b >> c;

		vector<ll> v, v1;
		fo(i, 0, n + 2, 1)
		{
			v1.push_back(i);
		}
		fo(i, 0, n + 1, 1)
		{
			ll index1 = lower_bound(v1.begin(), v1.end(), (2 * n) - e - (2 * i)) - v1.begin();
			ll index2 = upper_bound(v1.begin(), v1.end(), h - (3 * i)) - v1.begin() - 1;
			ll track;
			if ((index1 > index2) || (index1 == n + 1))
				continue;
			if ((index2 == n + 1) && (index2 + (3 * i)) > h)
				continue;
			track = c>a? (index1 < n - i ? index1 : n - i): (index2 < n - i ? index2 : n - i);
			
			ll f = n - track - i;
			if ((track + 2 * i >= 2 * n - e) && (track + 3 * i <= h))
				v.push_back(a * f + b * i + c * track);
		}
		if (v.size() == 0)
			cout << "-1\n";
		else
		{
			sort(v.begin(), v.end());
			cout << v[0] << "\n";
		}
	}
}