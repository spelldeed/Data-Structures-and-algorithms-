#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<=(n-1);i++)
using namespace std;
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		vector<ll> v1(n), v2(n);
		fo(i, 0, n)
		{
			cin >> v1[i];
		}
		fo(i, 0, n)
		{
			cin >> v2[i];  
		}
		/*sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		ll mid;
		n % 2 == 0 ? mid = v1[n / 2] + v2[n / 2] + v1[(n / 2) + 1] + v2[(n / 2) + 1] : mid = v1[(n / 2) + 1] + v2[(n / 2) + 1];
		ll mid_index;
		n % 2 == 0 ? mid_index = (n * n) / 2 : mid_index = ((n * n) / 2) + 1;
		ll a;
		fo(i, 0, k)
		{
			cin >> k;
			if(k<=(mid_))
		}*/

	}

}