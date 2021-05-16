#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<numeric>

using namespace std;
struct trackr
{
	int incrementr = 0;
	vector<long long int> vr;
};
struct trackc
{
	long long int incrementc = 0;
	vector<long long int> vc;
};
int main()
{
	map<int, trackr> mp;
	long long int maxr = 0;
	long long int maxc = 0;
	map<int, trackc> mpc;
	long long int n, op;
	cin >> n >> op;
	while (op--)
	{
		string s;
		long long int num, add;
		cin >> s>>num>>add;
		if (s == "RowAdd")
		{
			mp[num].incrementr++;
			mp[num].vr.push_back(add);
		}
		else
		{
			mpc[num].incrementc++;
			mpc[num].vc.push_back(add);
			
		}
	}
	long long int ansr = 0, ansc = 0;
	for (auto x : mp)
	{
		/*long long int sum = 0;
		if (maxr < x.second.incrementr)
		{
			maxr = x.first;
			ansr = accumulate(x.second.vr.begin(), x.second.vr.end(), 0LL);
			
		}
		else if (maxr == x.second.incrementr)
		{
			if (ansr < accumulate(x.second.vr.begin(), x.second.vr.end(), 0LL))
			    ansr = accumulate(x.second.vr.begin(), x.second.vr.end(), 0LL);
		}
		printf("%lld", ansr);*/
		if (ansr < accumulate(x.second.vr.begin(), x.second.vr.end(), 0LL))
			ansr = accumulate(x.second.vr.begin(), x.second.vr.end(), 0LL);
	}
	for (auto x : mpc)
	{
		/*long long int sum = 0;
		if (maxc < x.second.incrementc)
		{
			maxc = x.first;
			ansc = accumulate(x.second.vc.begin(), x.second.vc.end(), 0LL);
			
		}
		else if (maxc == x.second.incrementc)
		{
			if (ansc < accumulate(x.second.vc.begin(), x.second.vc.end(), 0LL))
				ansc = accumulate(x.second.vc.begin(), x.second.vc.end(), 0LL);
		}
		printf("%lld", ansc);*/
		if (ansc < accumulate(x.second.vc.begin(), x.second.vc.end(), 0LL))
			ansc = accumulate(x.second.vc.begin(), x.second.vc.end(), 0LL);
	}
	printf("%lld", ansc + ansr);
	
}

