#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define ll long long int 
#define fo(i,a,n) for(ll i=a;i<=(n-1);i++)
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s, t;
		cin >> s >> t;
		map<char, int> fir;
		map<char, int> sec;
		ll count = 0;
		fo(i, 0, s.size())
		{
		   fir[s[i]]++;
		}
		fo(i, 0, t.size())
		{
			sec[t[i]]++;
		}
		
		if (sec.size() >= fir.size())
		{
			for (auto x : fir)
			{

				if (sec[x.first] != 0)
				{
			
					count += min(fir[x.first], sec[x.first]);
				}
			}
		}
		else
		{
			for (auto x : sec)
			{
				if (fir[x.first] != 0)
				{
		
					count += min(fir[x.first], sec[x.first]);
				}
			}
		}
		cout << count << "\n";
	}
}