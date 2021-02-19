#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<algorithm>
#define ll long long int
#define fo(i,a,n)  for(ll i=a;i<=(n-1);i++)
#define f first
#define s second
#define in insert
using namespace std;
struct triple
{
	ll x, y, z;
};
int main()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	cin >> v[0];
	set<ll> s;
	s.in(1);
	fo(i, 1, n)
	{
		cin >> v[i];
		if ((v[i] % v[i - 1])!=0)
			s.in(i+1);
	}
	vector<triple> a(k);
	fo(i, 0, k)
	{
		cin >> a[i].x;
		if (a[i].x==1)
			cin >> a[i].y >> a[i].z;
		else
		{
			cin >> a[i].y;
			a[i].z=0;
		}
	}
	fo(i, 0, k)
	{
		if ((a[i].x)==1)
		{
			v[a[i].y - 1] = a[i].z;
			s.in(a[i].y);
			if (a[i].y != n)
			{
				s.in(a[i].y + 1);
				if ((v[a[i].y] % v[a[i].y - 1]) == 0)
					s.erase(a[i].y + 1);
			}
			if (a[i].y != 1)
			{
				if ((v[a[i].y - 1] % v[a[i].y - 2]) == 0)
					s.erase(a[i].y);
			}
		}
		else
		{
			if ((s.upper_bound(a[i].y))==s.begin())
				cout << "1\n";
			else
				cout <<*(--(s.upper_bound(a[i].y))) << "\n";
		}
	}
	

}
