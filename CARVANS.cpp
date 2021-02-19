#include<iostream>
#include<vector>
using namespace std;
void solve()
{
	int n,cnt=1;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i <= (n - 1); i++)
	{
		cin >> v[i];
	}
	if (n == 1)
	{
		cout << "1" << "\n";
		return;
	}
	else
	{
		for (int i = 1; i <=(n-1) ; i++)
		{
			if (v[i - 1] <= v[i])
				v[i] = v[i - 1] - 1;
			else
				cnt++;
		}
		cout << cnt << "\n";
		return;
	}
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