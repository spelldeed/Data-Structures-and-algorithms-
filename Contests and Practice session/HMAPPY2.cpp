#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<=(n-1);i++)
using namespace std;
ll GCD(ll a, ll b)
{
	if (b == 0)
		return(a);
	else
		GCD(b,a % b);
}
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, a, b, k;
		ll cnta = 0;
		ll cntb = 0;
		cin >> n >> a >> b >> k;
		ll p = GCD(max(a, b), min(a, b));
		ll lcm = (a*b)/ p;
		ll total;
		if (p != 1)
		{
			if ((n / a) + (n / b) - 2 * (n / lcm) >= k)
				cout << "Win\n";
			else
				cout << "Lose\n";

		}
		

	}
	return(0);
}