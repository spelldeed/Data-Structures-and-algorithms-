#include<iostream>
#include<cmath>
using namespace std;
bool power_2(int n)
{
	if (n == 0)
		return(false);
	else
		return(ceil(log2(n)) == floor(log2(n)));
}
void solve()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << "1" << "\n";
		return;
	}
	if (power_2(n))
	{
		cout << "-1" << "\n";
		return;
	}
	else if (n == 3)
	{
		cout << "2 3 1 " << "\n";
		return;
	}
	else
	{
		cout << "2 3 1 ";
		for (int i = 4; i <= n; i++)
		{
			if (power_2(i))
			{
				cout << i + 1 << " " << i << " ";
				i++;
			}
			else
				cout << i << " ";
		}
		cout << "\n";
	}
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