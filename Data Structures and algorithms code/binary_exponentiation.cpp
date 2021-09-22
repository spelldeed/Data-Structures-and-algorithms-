#include<iostream>
#include<vector>
#define ll long long int
#define fo(i,a,n) for(ll i =a;i<=(n-1);i++)

using namespace std;
ll recursive(ll a, ll b)
{
   if(b==0)
   {
       return(1);
   }
   ll dp = recursive(a,b/2);
   if(b%2)
   {
       return(dp*dp*a);
   }
   else
   {
       return(dp*dp);
   }
}

ll non_recursive(ll a, ll b)
{
ll dp = 1;
while(b>0)
{
    if(b&1)
    {
        dp*=a;
    }
    a=a*a;
    b>>=1;
}
return(dp);
}

int main()
{
    cout << "Enter number and power : ";
    ll a,b;
    cin >>a>>b;
    cout << "First method: ";
    cout << recursive(a,b) ;
    cout << "\nSecond method ";
    cout << non_recursive(a,b);
}