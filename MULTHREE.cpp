#include<iostream>
#include<string>
#define ll long long int
using namespace std;
void solve()
{
	ll d0, d1, n;
	cin >> n >> d0 >> d1;
	/*sum3 = d0 + d1;
    if (n <= 3)
	{
		sum3 = (d0 + d1) * 2;
		sum3 % 3 == 0 ? cout << "YES" << "\n" : cout << "NO" << "\n";
		return;
	}
	string s;
	s.insert(0, to_string(d0));
	s.insert(0, to_string(d1));
	s.insert(0, to_string(d0 + d1));
	for (ll i = 3; i <= (n - 1); i++)
	{
		sum3 = sum3 + (sum3 % 10);
		s.insert(i, to_string(sum3 % 10));
		if (s.substr(i - 3, i) == "2486")
			break;
	}
	sum3 = sum3 + (((n - s.size()) / 4) * 20);
	if ((n - s.size()) % 4 == 1)
		sum3 = sum3 + 2;
	else if ((n - s.size()) % 4 == 2)
		sum3 = sum3 + 6;
	else if ((n - s.size()) % 4 == 3)
		sum3 = sum3 + 14;
	sum3 % 3 == 0 ? cout << "YES" << "\n" : cout << "NO" << "\n";
	return;*/
	//
	// TIME LIMIT EXCEEDED
	/*
	ll sum;
	sum = (d0 + d1) % 10;
	if (sum == 5)
	{
		cout << "NO" << "\n";
		return;
	}
	if (n == 2)
	{
		(d0+d1) % 3 == 0 ? cout << "YES" << "\n" : cout << "NO" << "\n";
		return;
	}
	sum3 = sum;
	sum = sum+d0+d1 + ((n - 3) / 4) * 20;
	if ((sum3 == 9) || (sum3 == 4))
	{
		if ((n - 3) % 4 == 1)
			sum = sum + 8;
		else if ((n - 3) % 4 == 2)
			sum = sum + 14;
		else if ((n - 3) % 4 == 3)
			sum = sum + 16;
	}
	else if ((sum3 == 8) || (sum3 == 3))
	{
		if ((n - 3) % 4 == 1)
			sum = sum + 6;
		else if ((n - 3) % 4 == 2)
			sum = sum + 8;
		else if ((n - 3) % 4 == 3)
			sum = sum + 12;
	}
	else if ((sum3 == 7) || (sum3 == 2))
	{
		if ((n - 3) % 4 == 1)
			sum = sum + 4;
		else if ((n - 3) % 4 == 2)
			sum = sum + 12;
		else if ((n - 3) % 4 == 3)
			sum = sum + 18;
	}
	else if ((sum3 == 6) || (sum3 == 1))
	{
		if ((n - 3) % 4 == 1)
			sum = sum + 8;
		else if ((n - 3) % 4 == 2)
			sum = sum + 12;
		else if ((n - 3) % 4 == 3)
			sum = sum + 14;
	}
	sum % 3 == 0 ? cout << "YES" << "\n" : cout << "NO" << "\n";
	return;
	*/

			
			ll sum = d0 + d1;
			ll res = 0;
			sum = sum % 10;
			if (n > 2) {

				if (sum == 1 || sum == 6) {
					ll d = (n - 3) / 4;
					res += d * 20;
					if ((n - 3) % 4 == 1)res += 8;
					if ((n- 3) % 4 == 2)res += 4 + 8;
					if ((n - 3) % 4 == 3)res += 2 + 4 + 8;
				}
				if (sum == 2 || sum == 7) {
					ll d = (n - 3) / 4;
					res += d * 20;
					if ((n - 3) % 4 == 1)res += 4;
					if ((n - 3) % 4 == 2)res += 8 + 4;
					if ((n - 3) % 4 == 3)res += 6 + 4 + 8;
				}
				if (sum == 3 || sum == 8) {
					ll d = (n - 3) / 4;
					res += d * 20;
					if ((n - 3) % 4 == 1)res += 6;
					if ((n - 3) % 4 == 2)res += 2 + 6;
					if ((n - 3) % 4 == 3)res += 4 + 2 + 6;
				}
				if (sum == 4 || sum == 9) {
					ll d = (n - 3) / 4;
					res += d * 20;
					if ((n- 3) % 4 == 1)res += 8;
					if ((n - 3) % 4 == 2)res += 6 + 8;
					if ((n - 3) % 4 == 3)res += 2 + 8 + 6;
				}
			}
			res += sum + d0 + d1; if (n == 2)res -= sum;

			if (res % 3 == 0)cout << "YES\n";
			else
				cout << "NO\n";

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
	