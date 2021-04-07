#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
int n, m, nl = 1, nn = 0, cnt = 0;
int er, ec;
vector<vector<string>> mp(m,vector<string> (n));
vector<vector<bool>> visited(m, vector<bool>(n));
vector<int> rr = { -1,0,1,0 };
vector<int> rc = { 0,1,0,-1 };

queue<int> qr,qc;
void connect(int i, int j, string x)
{
	mp[i][j] = x;
	visited[i][j] = false;
}
void solve(int sr, int sc)
{
	if (visited[sr][sc])
		return;
	visited[sr][sc] = true;
	while (!qr.empty())
	{
		sr = qr.front();
		sc = qc.front();
		qr.pop();
		qc.pop();
		if ((sr == er) && (sc == ec))
		{
			cout << cnt;
			return;
		}
		for (int i = 0; i <= 3; i++)
		{
			if ((sr + rr[i] < 0) || (sc + rc[i] < 0))
				continue;
			if ((sr + rr[i] >= m) || (sc + rc[i] >=n))
				continue;
			if (visited[sr + rr[i]][sc + rc[i]])
				continue;
			if (mp[sr + rr[i]][sc + rc[i]] == "#")
				continue;
			qr.push(sr + rr[i]);
			qc.push(sc + rc[i]);
			visited[sr + rr[i]][sc + rc[i]] = true;
			nn++;
		}
		nl--;    // Visualize this nn and nl part to get a better understanding
		if (nl == 0)
		{
			nl = nn;
			nn = 0;
			cnt++;
		}
	}
	cout << "Path Does not Exist\n";
	return;
}
int main()
{
	cout << "Enter Dimension of the Grid : Format---------> ROW COLUMN\n";

	cin >> m >> n;
	mp.resize(m);
	visited.resize(m);
	for (int i = 0; i <= m - 1; i++)
	{
		mp[i].resize(n);
		visited[i].resize(n);
	}
	string x;
	cout << "Enter Elements of The Grid\n";
	for (int i = 0; i <= (m - 1); i++)
	{
		for (int j = 0; j <= (n - 1); j++)
		{
			cin >> x;
			connect(i, j, x);
		}
	}
	int sr, sc;
	cout << "Enter the Starting Coordinates and The ending Coordinates\n";
	cin >> sr >> sc >> er >> ec;
	qr.push(sr);
	qc.push(sc);
	cout << "\n\nNo. of minimum Steps required are : ";
	solve(sr, sc);

}

/*
--------------------Sample Input--------------------------
5 7
. . . # . . .
. # . . . # .
. # . . . . .
. . # # . . .
# . # . . # .
0 0 4 3
*/