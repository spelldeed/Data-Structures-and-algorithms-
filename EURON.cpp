#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
#define ll long long int 
#define fo(i,a,n) for(ll i=a;i<=(n-1);i++)
#define f first
#define s second
using namespace std;
int main()
{
	ll n;
	cin >> n;
	vector<ll> v(n);
	ll a,cnt=0;
	fo(i, 0, n)
	{
		cin >> a;
		auto u = upper_bound(v.begin(), v.end(), a)-v.begin();
		cnt += v.size() - u;
		v.insert(v.begin() + u, a);
	}
	cout << cnt << "\n";
}



