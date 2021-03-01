#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<=(n-1);i++)
using namespace std;
int GCD(int a, int b)
{
	if (b == 0)
		return(a);
	GCD(b, a % b);
}
bool isPrime(ll n)
{
	if (n == 1)
		return(false);
	if ((n % 2 == 0) || (n % 3 == 0))
		return(false);
	for (ll i = 5; i <= (n - 1); i += 2)
	{
		if (n % i == 0)
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
		vector<ll> v;
		for (ll i = 2; i * i <= n; i++)
		{
			if ((n % i) == 0)
			{
				if ((abs((n / i) - i) % 2 == 0)&&(((n / i) - i)!=0))
				{
					v.push_back(abs(((n / i) - i) / 2));
				}
			}
		}
		if ((n != 1)&&(n%2!=0))
		{
			v.push_back((n - 1) / 2);
		}
		sort(v.begin(), v.end());
		if (v.size() == 0)
			cout << "-1" << "\n";
		else
			cout << v[0]*v[0] << "\n";
	}
}