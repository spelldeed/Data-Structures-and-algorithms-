#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
#define ll long long int
#define fo(i,a,n) for(int i=a;i<=(n-1);i++)
#define f first
#define s second
using namespace std;


int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> vi(n);
		fo(i, 0, n)
		{
			cin >> vi[i];
		}
		int x;
		vector<tuple<int,int,int>> v;
		fo(i, 0, n)
		{
			cin >> x;
			v.push_back(make_tuple( vi[i],x ,i));
			fflush(stdin);
		}
		
		int cnt = 0;
		if (n == 2)
		{
			if ((get<0>(v[0])== 2) && (get<1>(v[0])== 1))
			{
				cnt = 2;
			}
			else if (get<0>(v[0]) == 1)
			{
				cnt = 0;
			}
			else
				cnt = 1;
		}
		else
		{
			sort(v.begin(), v.end());
			fo(i, 1, n)
			{
				if (get<2>(v[i]) <= get<2>(v[i - 1]))
				{
					while (get<2>(v[i]) - get<2>(v[i-1]) <= 0)
					{
						get<2>(v[i]) += get<1>(v[i]);
						cnt++;
					}
				}
			}
		}
		cout <<cnt << "\n";
	}
}