#include<iostream>
#include<vector>
#define ll long long int
#define fo(i,a,n,m) for(ll i=a;i<=(n-1);i+=m)
using namespace std;
vector<vector<ll>> v(500,vector<ll>(500, 0));
ll grid_traveler(ll m, ll n)
{
	if ((m == 1) && (n == 1))
		return(1);
	if ((m == 0) || (n == 0))
		return(0);
	if (v[m][n] != 0)
		return(v[m][n]);
	v[m][n] = grid_traveler(m - 1, n) + grid_traveler(m, n - 1);
	return(v[m][n]);
}
int main()
{
	cout << "The row and column cannot be more than 500\n";
	int t;
	cin >> t;
	while (t--)
	{
		ll m, n;
		cin >> m >> n;
		cout<<grid_traveler(m, n)<<"\n";
	}

}