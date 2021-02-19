/*#include<iostream>
#include<vector>
#define ll long long int 
#define f(i,a,n) for(ll i=a;i<=(n-1);i++)
#define m 1000000007
using namespace std;
int main()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	f(i, 0, n)
	{
		cin >> v[i];
	}
	ll res, p = 1;
	f(i, 0, n - 1)
	{
		f(j, i + 1, n)
		{
			if (v[j] < v[i])
			{
				res = j - i + 1;
				p = (p * res) % (m);
				break;
			}
		}
	}
	cout << p;
	return(0);
}*/
#include<iostream>
#include<vector>
#include<stack>
#define m 1000000007
#define ll long long int
#define f(i,a,n) for(ll i=a;i<=(n-1);i++)
#define fm(i,n,a) for(ll i=(n-1);i>=0;i--)
using namespace std;
int main()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	stack < pair<ll, ll>> st;
	f(i, 0, n)
	{
		cin >> v[i];
	}
	ll res = 1, p = 1;
	fm(i, n, 0)
	{
		while ((!st.empty()) && (st.top().first >= v[i]))
			st.pop();
		if (!(st.empty()))
		{
			res = st.top().second-i+1;
			p = (p*res)%m;
			
		}
		st.push({ v[i],i });
	}
	cout << p%m;
	return(0);
}