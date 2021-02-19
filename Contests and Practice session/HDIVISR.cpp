#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#define ll long long int
#define fo(i,a,n)  for(ll i=a;i<=(n-1);i++)
#define f first
#define second
using namespace std;
int main()
{
	ll n;
	cin >> n;
	ll m = 1;
	fo(i, 1, 11)
	{
		if (n % i == 0)
			m = max(m, i);
	}
	cout << m << "\n";
}