#include<iostream>
#include<vector>
#define ll long long int
#define fo(i,a,n,m) for(ll i=a;i<=(n-1);i+=m)
using namespace std;
ll n;
vector<ll> memo(n+1,0);

ll sumRange(ll left, ll right)
{
    if (left == 0)
        return(memo[right]);
    else
        return(memo[right] - memo[left-1]);
}

int main()
{
	ll t;
	cin >> n;
    vector<ll> nums(n);
    fo(i, 0, n, 1)
    {
        cin >> nums[i];
        if (i == 0)
            memo[0] = nums[0];
        if (i != 0)
            memo[i] = memo[i - 1] + nums[i];
        
    }
    cout << "\n";
    cin >> t;
	while (t--)
	{
		ll a, b;
		cin >> a >> b;
	    
		cout << sumRange(a, b) << "\n";
	}
}
