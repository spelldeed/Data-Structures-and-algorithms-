#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<numeric>
#include<math.h>
#include<stack>
#include<queue>
#define ll long long int
#define fo(i,a,n,m) for(ll i=a;i<=(n-1);i+=m)
using namespace std;
ll GCD(ll a, ll b)
{
	if (b == 0)
		return(a);
	return(b, a % b);
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
ll maxSubArray(vector<ll>& nums)
{
	ll sum = nums[0], result = nums[0];
	fo(i,1,nums.size(),1)
	{
		sum = max(sum + nums[i], nums[i]);
		result = max(result, sum);
	}
	return(result);

}
int main()
{
	int n;
	cin >> n;
	vector<ll> v(n);
	fo(i, 0, n, 1)
	{
		cin >> v[i];
	}
	cout << maxSubArray(v) << "\n";
}