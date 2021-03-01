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
		ll n, m, x, y;
		cin >> n >> m >> x >> y;
		if ((n - 1 >= 0) && (m - 1 >= 0) && ((n - 1) % x == 0) && ((m - 1) % y == 0))
			cout << "Chefirnemo\n";
		else if((n - 2 >= 0 && m - 2 >= 0 && (n - 2) % x == 0 && (m - 2) % y == 0)) 
			cout << "Chefirnemo\n";
		else 
			cout << "Pofik\n";
	}
}