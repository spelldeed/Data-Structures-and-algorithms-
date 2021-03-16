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
	fo(i, 5, a,2)
	{
		if (a % i == 0)
			return(false);
	}
	return(true);
}
int main()
{
	ll n, h, x;
	cin >> n >> h >> x;
	vector<ll> v(n);
	fo(i, 0, n, 1)
	{
		cin >> v[i];
	}
	auto y = lower_bound(v.begin(), v.end(), h - x)-v.begin();
	if (y == n)
		cout << "NO" << "\n";
	else
		cout << "YES" << "\n";
	return(0);

}