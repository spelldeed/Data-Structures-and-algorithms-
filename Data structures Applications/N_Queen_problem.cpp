#include<iostream>
#include<vector>
#define ll long long int
#define f(i,a,n) for(int i=a;i<=(n-1);i++)
using namespace std;
int n;
int k=100,cnt=0;
vector<int> v0(k,0);
vector<vector<int>> v(k, v0);
bool o_tracker(int r, int c)
{
	f(i, 0, n)
	{
		if (v[r][i])
			return(false);
	}
	int i = r, j = c;
	while ((i >= 0) && (j >= 0))
	{
		if (v[i][j])
			return(false);
		i--;
		j--;
	}
	i = r;
	j = 0;
	while ((i >= 0) && (j <= (n - 1)))
	{
		if (v[i][j])
			return(false);
		i--;
		j++;
	}
	return(true);
}
bool row_tracker(int c)
{
	if (c == n)
		return(true);
	f(i, 0, n)
	{
		if (o_tracker(i, c))
		{
			v[i][c] = 1;
			if (row_tracker(c + 1))
				return(true);
			v[i][c] = 0;
		}
	}
	return(false);
}
bool final_check()
{
	if (!row_tracker(0))
		return(false);
	return(true);
}
int main()
{
	
	cout << "Enter the desired side of chessboard : ";
	cin >> n;
	if (final_check())
	{
		cout << "Solution exists! The positions are as follows:-\n";
		f(i, 0, n)
		{
			f(j, 0, n)
			{
				cout << v[i][j] << " ";
			}
			cout << "\n";
		}
		return(0);
	}
	else
		cout << "No solution\n";
	return(0);
}
