#include<iostream>
#define I "INDIAN"
#define NI "NON_INDIAN"
#define CW "CONTEST_WON" 
#define TC "TOP_CONTRIBUTOR"
#define BF "BUG_FOUND"
#define CH "CONTEST_HOSTED"
using namespace std;
void solve()
{
	int n,sum=0,k;
	string s,s1;
	cin >> n >> s;
	for (int i = 0; i <= (n - 1); i++)
	{
		cin >> s1;
		if (s1 == CW)
		{
			cin >> k;
			if (k <= 20)
				sum += 300 + 20 - k;
			else
				sum += 300;
		}
		else if (s1 == TC)
			sum += 300;
		else if (s1 == BF)
		{
			cin >> k;
			sum += k;
		}
		else if (s1 == CH)
			sum += 50;
	}
	(s == I) ? cout << sum / 200 << "\n" : cout << sum / 400 << "\n";
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