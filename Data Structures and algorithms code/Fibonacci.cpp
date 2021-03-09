#include<iostream>
#include<vector>
#define ll long long int
#define fo(i,a,n,m) for(ll i=a;i<=(n-1);i+=m)
using namespace std;
vector<ll> v(500, 0);

ll fibonacci(ll n)
{
	if (n <= 2)
		return(1);
	if (v[n] != 0)
		return(v[n]);
	v[n] = fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cout << "number should be less than 500" << "\n";
		int n;
		cin >> n;
		cout << fibonacci(n) << "\n";
	}

}