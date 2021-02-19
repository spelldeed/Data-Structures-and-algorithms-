#include<iostream>
#include<algorithm>
#include<queue>
#define ll long long int
#define f(i,a,n) for(ll i=a;i<=(n-1);i++)
using namespace std;
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, z,a,b,cnt=0;
		cin >> n >> z;
		priority_queue<ll> p;
		f(i, 0, n)
		{
			cin >> a;
			p.push(a);
		}
		while ((!p.empty())&&(z>0))
		{
			z = z - p.top();
			b = p.top()/2;
			p.pop();
			if (b > 0)
				p.push(b);
			cnt++;
		}
		z > 0 ? cout << "Evacuate" << "\n" : cout << cnt << "\n";
	}
}