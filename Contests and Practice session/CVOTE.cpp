#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<unordered_map>
#define ll long long int
#define f(i,a,n) for(ll i=a;i<=(n-1);i++)
using namespace std;
bool great(pair<string, ll> &x, pair<string, ll> &y)
{
	return(x.second > y.second);
}
int main()
{
	
		int n, m;
		cin >> n >> m;
		map<string, string> v;
		
		f(i, 0, n)
		{
			string a, b;
			cin >> a >> b;
			v[a] = b;
		}
		map<string, ll> mn, mc;
		f(i, 0, m)
		{
			string a;
			cin >> a;
			mn[a]++;
			mc[v[a]]++;
		}

		vector<pair<string, ll>> mnv = { mn.begin(),mn.end() }, mcv = { mc.begin(),mc.end() };
		//for this whole part shortcut at the end of program
		sort(mnv.begin(), mnv.end(), great);
		sort(mcv.begin(), mcv.end(), great);

		auto it1 = mnv.begin();
		ll x = it1->second;
		auto it2 = mcv.begin();
		ll y = it2->second;
		ll cntn = 0, cntc = 0;
		

		while((cntn!=mnv.size())&& (x == it1->second))
		{
			it1++;
			cntn++;
		}

		while ((cntc != mcv.size()) && (y == it2->second))
		{
			it2++;
			cntc++;
		}

		sort(mnv.begin(), mnv.begin()+cntn);
		sort(mcv.begin(), mcv.begin() + cntc);
		cout << mcv[0].first << "\n" << mnv[0].first << "\n";

		/*
		bool great(pair<string,ll> &x,pair<string,ll> &y)
		{
			if (x.second == y.second)
		       return(x.first < y.first);
	        else
		       return(x.second > y.second);
	    }
		sort(mnv.begin(), mnv.end(), great);
		sort(mcv.begin(), mcv.end(), great);

		cout << mcv[0].first << "\n" << mnv[0].first << "\n";*/
}