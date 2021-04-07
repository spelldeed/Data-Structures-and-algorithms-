#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<int, vector<int>> mp;
map<int, bool> visited;
int n;
void connect(int x, int y)
{
	mp[x].push_back(y);
	visited[x] = false;
	visited[y] = false;
}
void dfs(int x)
{
	if (visited[x])
		return;
	visited[x] = true;
	cout << x << " ";
	for (auto& y : mp[x])
	{
		dfs(y);
	}
}
void dfs_for_all()
{
	auto it = mp.begin();
	for (it = mp.begin(); it != mp.end(); it++)
	{
		for (auto y : it->second)
		{
			if (visited[y])
				continue;
			cout << y << " ";
		}
	}
}
void printk()
{
	auto it = mp.begin();
	for (it = mp.begin(); it != mp.end(); it++)
	{
		cout << it->first << " : ";
		for (auto x : it->second)
		{
			cout << x << " ";
		}
		cout << "\n";
	}
}
int main()
{
	cout << "Enter the the number of Edges\n";
	cin >> n;
	int x, y;
	for (int i = 0; i <= (n - 1); i++)
	{
		cin >> x >> y;
		connect(x, y);
	}
	cout << "Enter the node you would like to start from : ";
	int c;
	cin >> c;
	dfs(c);
	dfs_for_all();
	cout << "\n----------------------------------------------------------Each Nodes and their respective connections------------------------------------------------------------\n";
	printk();
}
