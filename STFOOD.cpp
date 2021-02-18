#include<iostream>
#include<vector>
#include<algorithm>
#define pb push_back
#define f(i,a,n) for(int i=a;i<=(n-1);i++)
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> s(n), p(n), v(n),a(n);
		f(i, 0, n)
		{
			cin >> s[i] >> p[i] >> v[i];
			a.pb((p[i] / (s[i] + 1)) * v[i]);
		}
// instead of using sort profit can be calculated by setting a max variable and keeping a track of maximum element in vector 'a'.
		sort(a.rbegin(), a.rend());
		cout << a[0] << "\n";
	}
}
