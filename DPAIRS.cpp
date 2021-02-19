#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define ll long long int
#define f(i,a,n) for(auto i=a;i!=(n);i++)
using  namespace std;
int main()
{
	ll n, m,a;
	cin >> n >> m;
/////////////////////////////////////////TLE   **********may give WA coz 'no mapping'
	
	/*
	set<ll> s1, s2;
	vector<ll> v;
	f(i, 0, n)
	{
		cin >> a;
		s1.insert(a);
	}
	f(i, 0, m)
	{
		cin >> b;
		s2.insert(b);
	}
	ll i = 0, j = 0;
	f(it1,s1.begin(),s1.end())
	{
		j = 0;
		f(it2,s2.begin(),s2.end())
		{
			if (v.size() == n + m - 1)
				return(0);
			
			if (find(v.begin(), v.end(), *it1+*it2) == v.end())
			{
				v.push_back(*it1 + *it2);
				cout << i << " " << j << "\n";
			}
			j++;
		}
		i++;
	}*/

	vector<pair<ll,ll>> v1,v2;
	f(i, 0, n)
	{
		cin >> a;
		v1.push_back(make_pair(a,i));
	}
	f(i, 0, m)
	{
		cin >> a;
		v2.push_back(make_pair(a,i));
	}
	ll j = 0, k = 0;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	f(i, 0, m)
	{
		cout << v1[0].second<< " " << v2[i].second << "\n";
	}
	f(i, 1, n)
	{
		cout << v1[i].second<< " " <<v2[m-1].second << "\n";
	}
}