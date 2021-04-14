#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<int, bool> visited;
map<int, vector<int>> mp;
map<int, int> track;
vector<pair<int, int>> bridges;
int n, m;
void connect(int x, int y)
{
	mp[x].push_back(y);
	mp[y].push_back(x);
	track[x] = x;
	track[y] = y;
}
void dfs(int x,int p)
{
	visited[x] = true;
	for (auto y : mp[x])
	{
		if (y == p)
			continue;
		if (!visited[y])
		{
			dfs(y,x);
			track[x] = min(track[y], track[x]);
			if (x < track[y])
			{
				bridges.push_back(make_pair(x, y));
			}

		}
		else
		{
			track[x] = min(track[y], track[x]);
		}
	}
}
int main()
{
	cout << "Enter number of edges and vertices respectively\n";
	cin >> n >> m;
	int x, y;
	cout << "Enter edges :\n";
	for (int i = 0; i <= (n - 1); i++)
	{
		cin >> x >> y;
		connect(x, y);
	}
	for (auto t :mp)
	{	
		if (!visited[t.first])
		{
			dfs(t.first, -1);
		}
	}
	if (bridges.size() != 0)
	{
		cout << "\n\nBRIDGES FOUND IN THE GRAPH\n";
		for (auto p : bridges)
		{
			cout << "Between " << p.first << " and " << p.second << "\n";
		}
	}
	else
		cout << "\nNO BRIDGES";
}
