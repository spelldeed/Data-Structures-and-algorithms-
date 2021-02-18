#include<iostream>
#include<cmath>
using namespace std;
void solve()
{
	int n, k, x, y,a,b,i=0;
	cin >> n >> k >> x >> y;
	if (k == 0)
	{
		if (x == y)
		{
			cout << "YES" << "\n";
			return;
		}
		else
		{
			cout << "NO" << "\n";
			return;
		}
	}
	else
	{
		x + k >= n ? a = (x + k) % n : a = (x + k);
		if (a == y)
		{
			cout << "YES" << "\n";
			return;
		}
		else
		{
			a + k >= n ? b = (a + k) % n : b = a + k;
			while (a != b)
			{
				if (b == y)
				{
					cout << "YES" << "\n";
					return;
				}
				b + k >= n ? b = (b + k) % n : b = b + k;
				i++;
			}
			cout << "NO" << "\n";
			return;
		}
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
	return(0);
}