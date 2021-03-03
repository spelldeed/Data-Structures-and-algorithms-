#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<numeric>
#define ll long long int
#define fo(i,a,n,k) for(ll i=a;i<=(n-1);i+=k)
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
		ll  m = floor(log2(n));
		ll limit = pow(2, m);
		ll a = 0, b = 1,c=0;
		vector<ll> v;
		v.push_back(a);
		v.push_back(b);
		fo(i, 2, 61, 1)
		{
			c = a %10 + b % 10;
			a = b%10;
			b = c%10;
			v.push_back(c);
		}
		if (n == 0)
			cout << "0" << "\n";
		else
		    cout << v[(limit % 60) - 1]%10 << "\n";
		
	}
}