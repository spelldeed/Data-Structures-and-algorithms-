#include<iostream>
#include<vector>
#define ll long long int
#define fo(i,a,n,m) for(ll i=a;i<=(n-1);i+=m)
using namespace std;
vector<ll> memo(1000000,-1);
int solve(vector<ll> v, ll a)
{
	if (a < 0)
		return(0);
	if (a == 0)
		return(1);
	if (memo[a]!=-1)
		return(memo[a]);
	int num;
	fo(i, 0, v.size(), 1)
	{
		num = a - v[i];
		if (solve(v, num)==1)
		{
			memo[a] = 1;
			return(1);
		}
	}
	memo[a] = 0;
	return(0);

}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,size;
		cin >> n>>size;
		vector<ll> v(size);
		fo(i, 0, size, 1)
		{
			cin >> v[i];
		}
		if (solve(v, n)==1)
			cout << "true" << "\n";
		else
			cout << "false" << "\n";
	}
}