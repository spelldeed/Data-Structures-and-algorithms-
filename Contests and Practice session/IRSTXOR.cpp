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
	int t;
	cin >> t;
	while (t--)
	{
		ll c;
		cin >> c;
		ll a = floor(log2(c));
		ll b = ceil(log2(c));
		ll m = pow(2,a);
		ll n = pow(2,b);
		if (a == b)
			cout << (m - 1) * ((m * 2) - 1) << "\n";
		else
			cout << (m - 1) * (n - (c - (m - 1))) << "\n";
	}
}