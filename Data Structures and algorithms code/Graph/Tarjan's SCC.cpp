#include<iostream>
#include<vector>
#include<map>
#include<stack>

using namespace std;
int n, m;
map<int, vector<int>> mp;
map<int, bool> visited;
map<int, bool> onstack;
map<int, int> track;
stack<int> s;

void connect(int x, int y)
{
	mp[x].push_back(y);
	track[x] = x;
	track[y] = y;
}
void FCC(int y)
{
	cout << "\n";
	while(s.top() != y)
	{
		onstack[s.top()] = false;
		cout << s.top() << " <- ";
		s.pop();
	}
	onstack[s.top()] = false;
	cout << s.top() << " ";
	s.pop();
	cout << "\n";
}
void dfs(int x, int p)
{
	visited[x] = true;
	onstack[x] = true;
	s.push(x);
	for (auto y : mp[x])
	{
		if (p == x)
			continue;
		if (!visited[y])
		{
			dfs(y, x);
			track[x] = min(track[y], track[x]);
			
		}
		if ((visited[y]) && (onstack[y]))
		{
			track[x] = min(track[y], track[x]);
			FCC(y);
		}
	}
}

int main()
{
	cout << "Enter number of edges and vertices respectively\n";
	cin >> n >> m;
	cout << "Enter the edges\n";
	int x, y;
	for (int i = 0; i <= (n - 1); i++)
	{
		cin >> x >> y;
		connect(x, y);
	}
	cout << "\n\nAll the FCC will be displayed below, if any.\n";
	for (auto it : mp)
	{
		if (!visited[it.first])
		{
			dfs(it.first, -1);
		}
	}
	cout << "ID's............\n";

	for (auto tr : track)
	{
		cout << tr.first << " : " << tr.second << "\n";
	}
}
