#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve()
{
	int n, x, p, k;
	cin >> n >> x >> p >> k;
	vector<int> v(n);
	for (int i = 0; i <= (n - 1); i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	if (v[p - 1] == x)
	{
		cout << "0" << "\n";
		return;
	}
	if(v[k-1]>x)
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
/*#include <iostream>
#include<string>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int j = 0;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			if (s[i] != '0')
				break;
			j++;
		}
		for (int i = (s.size() - 1-j); i >= 0; i--)
		{
			cout << s[i];
		}
		cout << "\n";
	}
}
#include<iostream>
using namespace std;
int main()
{
	int arr[100];
	for (int i = 0; i <= 99; i++)
	{
		cin >> arr[i];
		if (arr[i] == 42)
			return(0);
		else
			cout << arr[i] << "\n";
	}
	return(0);
}

#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;
/*int main()
{
	ll n;
	cin >> n;
	vector<ll> v(n);
	for (ll i = 0; i <=(n-1) ; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	ll max = 0;
	for (ll i = 0; i <= (n - 1); i++)
	{
		if ((v[i] * (n - i)) > max)
			max = v[i] * (n - i);
	}
	printf("%lld\n", max);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i <=(n-1) ; i++)
		{
			cin >> v[i];
		}
		if (n == 1)
		{
			cout << "1" << "\n";
		}
		else
		{
			int a, cnt = 0;
			a = *min_element(v.begin(), v.end());
			for (int i = 1; i <= (n - 1); i++)
			{
				if (v[i - 1] > v[i])
					cnt++;
				else
					v[i] = v[i - 1] - 1;
				if (a == v[i - 1])
				{
					cnt++;
					break;
				}
			}
			cout << cnt << "\n";
		}
	}
}*/