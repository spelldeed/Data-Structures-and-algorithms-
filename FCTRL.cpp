#include<iostream>
#define ll long long int
using namespace std;
void solve()
{
	ll n,sum=0,i=5;
	cin >> n;
	while ((n / i) != 0)
	{
		sum = sum + n / i;
		i *= 5;
	}
	cout << sum << "\n";
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}
