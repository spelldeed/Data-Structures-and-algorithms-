#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<numeric>
#include<stack>
#include<queue>
#define ll long long int
#define fo(i,a,n,m) for(ll i=a;i<=(n-1);i+=m)
using namespace std;
ll GCD(ll a, ll b)
{
	if (b == 0)
		return(a);
	GCD(b, a % b);
}
bool isPrime(ll a)
{
	if (a == 1)
		return(false);
	if ((a % 2 == 0) || (a % 3 == 0))
		return(false);
	fo(i, 5, a, 2)
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
		ll n;
		cin >> n;
		vector<ll> v(n);
		ll cnt = 0,track=0;
		fo(i, 0, n, 1)
		{
			cin >> v[i];
			
		}
		sort(v.begin(), v.end());
		fo(i, 0, n, 1)
		{
			if (i + 1 > v[i])
			{
				cnt = cnt + i + 1 - v[i];
			}
			if (v[i] > i + 1)
				track = 1;
		}
		if (track == 1)
			cout << "Second" << "\n";
		else if(cnt%2==0)
			cout << "Second" << "\n";
		else
			cout << "First" << "\n";

	}
}