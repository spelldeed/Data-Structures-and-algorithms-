#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<numeric>
#define ll long long int
#define fo(i, a, n) for (ll i = a; i <= (n - 1); i++)
using namespace std;
int GCD(int a, int b)
{
	if (b == 0)
		return(a);
	else
		GCD(b, a % b);
}
bool isPrime(int n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;

	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (int i = 5; i * i <= n; i += 2)
		if (n % i == 0)
			return false;

	return true;
}

int main()
{
	ll t,b=4;
	cin >> t;
	set<ll> s;
	vector<ll> v;
	while (t--)
	{
		ll a, n, c = 0;
	
		cin >> a;
		if (a > b)
		{
			fo(j, b, a)
			{
				fo(i, 2, (j/2)+1)
				{
					if ((j%i==0)&&(isPrime(i)) && (i != (j / i)) && (isPrime(j / i)))
					{
						v.push_back(j);
						break;
					}
				}
			}
		}
		auto track = unique(v.begin(), v.end());
		
		v.resize(distance(v.begin(), track));
		for (auto x : v)
		{
			cout << x << " ";
		}
		cout << "\n";
		/*fo(i, 0, v.size())
		{
			n = a / v[i];
			fo(j, 2, (n / 2) + 1)
			{
				if ((j != v[i]) && ((n - j) != v[i]) && (isPrime(j)) && (isPrime(n - j)))
				{
					if ((v[i] * n) == a)
					{
						cout << "YES" << "\n";
						c = 1;
						break;
					}
				}
			}
			if (c == 1)
				break;
		}*/
		fo(i, 0, v.size())
		{
			fo(j, 0, v.size())
			{
				if (v[i] + v[j] == a)
				{
					cout << "YES" << "\n";
					c = 1;
					break;
				}
			}
			if (c == 1)
				break;
		}
		if (c == 0)
			cout << "NO" << "\n";
		b = a;
		fflush(stdin);
	}

}