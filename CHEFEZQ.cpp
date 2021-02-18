#include<iostream>
#include<vector>
using namespace std;
void solve()
{
	long long int n, k, sum = 0, i;
	cin >> n >> k;
	vector<long long int> v(n);
	for (int j = 0; j <= (n - 1); j++)
	{
		cin >> v[j];
	}
	for (i = 0; i <= (n - 1); i++)
	{
		sum = sum + v[i] - k;
		if (sum < 0)
		{
			cout << i + 1 << "\n";
			return;
		}
	}
	cout << (sum / k) + i + 1 << "\n";
	return;
}
void main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return;
}