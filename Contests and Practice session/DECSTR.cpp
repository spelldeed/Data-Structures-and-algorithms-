#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define ll long long int
#define fo(i,a,n) for(int i=a;i>(n-1);i--)
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;
		string s;
		if (k <= 25)
		{
			if (k != 0)
			{
				fo(i, 97 + k, 97)
				{
					s += char(i);
				}
			}
		}
		else
		{
			int rem = k % 25;
			if (rem != 0)
			{
				fo(i, 97 + rem, 97)
				{
					s += char(i);
				}
			}
			int times = k / 25;
			while (times--)
			{
				fo(i, 97 + 25, 97)
				{
					s += char(i);
				}
			}
			
		}
	
		cout << s << "\n";
	}
}