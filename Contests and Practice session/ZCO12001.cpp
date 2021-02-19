#include<iostream>
#include<vector>
#include<stack>
#define ll long long int
#define f(i,a,n) for(ll i =a;i<=(n-1);i++)
#define pb push_back
using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll max_depth = 0, depth_i = 0, match_i = 0, depth = 0;
	vector<int> v(n), vm;
	vm.pb(0);
	stack<int> s;
	f(i, 0, n)
	{
		cin >> v[i];
	}
	f(i, 0, n)
	{
		if (v[i] == 1)
		{
			s.push(1);
			depth++;
		}
		else
		{
			s.pop();
			if (max_depth < depth)
			{
				max_depth = depth;
				depth_i = i;
			}
			depth--;
			if (s.empty())
			{
				vm.pb(i + 1);
			}
		}
	}
	ll max_diff = 0;
	f(i, 1, vm.size())
	{
		if (max_diff < (vm[i] - vm[i - 1]))
		{
			max_diff = vm[i] - vm[i - 1];
			match_i = vm[i - 1] + 1;
		}
	}
	cout << max_depth << " " << depth_i << " " << max_diff << " " << match_i << "\n";
}
int main()
{
	solve();
}