#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long int
#define fo(i,a,n) for(ll i=a;i<=(n-1);i++)

using namespace std;

vector<int> zeckendorfs_represenation(ll n)
{
    ll a=0;
    ll b=1,c=1;
    vector<ll> dp;
    dp.push_back(0);
    dp.push_back(1);
    while(c<=n)
    {
        dp.push_back(c);
        a=b;
        b=c;
        c = a+b;
        
    }
    vector<int> v(dp.size()-1,0);
    v[v.size()-1]=1;
    while(n>0)
    {
       if(n==1)
       {
           n=0;
           v[0]=1;
           return(v);
       }
       auto upper = upper_bound(dp.begin(),dp.end(),n);
       n-=dp[upper-dp.begin()-1];
       v[upper-dp.begin()-3]=1;
    }
    return(v);
}

int main()
{
    ll n;
    cin >> n;
    vector<int> v = zeckendorfs_represenation(n);
    cout << "Zeckendorf's representation for "<< n << ": ";
    fo(i,0,v.size())
    {
        cout << v[i];
    }
    return(0);
}