#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#define ll long long int
#define f(i,a,n) for(int i=a;i<=(n-1);i++)
using namespace std;
void solve()
{
	int n,sum=0;
	cin >> n;
	vector<int> v(n);
	set<int> s;
	f(i, 0, n)
	{
		cin >> v[i];
		s.insert(v[i]);
		sum += v[i];
	}
	if (s.size() == 1)
	{
		n % 2 == 0 ? cout << sum / 2 << "\n" : cout << ((n + 1) / 2) * v[0] << "\n";
		return;
	}
	sort(v.begin(), v.end());
	if (n == 2)
	{
		cout << v[1] << "\n";
		return;
	}
	int sum1 = v[n - 1], sum2 = v[n - 2];
	int i = n-3;
	while (i>=0)
	{
		sum1 > sum2 ? sum2 += v[i] : sum1 += v[i];
		i--;
	}
	cout << max(sum1, sum2) << "\n";
	return;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}
