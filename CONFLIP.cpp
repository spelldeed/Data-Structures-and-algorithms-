#include<iostream>
using namespace std;
void solve()
{
	int i, n, k;
	cin >> i >> n >> k;
	if (i == 1)
	{
		if (n % 2 == 0)
			cout << n / 2 << "\n";
		else
		{
			if (k == 2)
				cout << (n / 2) + 1 << "\n";
			else
				cout << (n / 2) << "\n";
		}
		return;
	}
	if (n % 2 == 0)
		cout << n / 2 << "\n";
	else
	{
		if (k == 2)
			cout << (n / 2) << "\n";
		else
			cout << (n / 2) + 1 << "\n";
	}
	return;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int g;
		cin >> g;
		while (g--)
		{
			solve();
		}
	}
}
