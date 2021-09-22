#include<iostream>
#include<algorithm>
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<=(n-1);i++)
using namespace std;
pair<ll,ll> fibonacci(ll p)
{
    if (p==0)
    {
        return{0,1};
    }
    pair<ll,ll> dp = fibonacci(p>>1);
    ll x = dp.first*(2*dp.second-dp.first);
    ll y = dp.first*dp.first + dp.second*dp.second;
    if (p&1)
    {
        return{y,x+y};
    }
    else
    {
        return{x,y};
    }

}
int main()
{
    cout << "Enter the position: ";
    ll p;
    cin >> p;
    pair<ll,ll> ans = fibonacci(p);
    cout << "Number at "<< p << ": " << ans.first;
}