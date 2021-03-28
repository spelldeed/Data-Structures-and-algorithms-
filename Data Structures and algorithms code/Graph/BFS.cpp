#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;
// For cp no class --> better option (OBVIOUSLY)
int n;
map<int, vector<int>> mp;
map<int, bool> visited;
queue<int> q;
void connect(int x, int y)
{
	mp[x].push_back(y);
	mp[y].push_back(x);
	visited[x] = false;
	visited[y] = false;
}
void BFS(int k)
{
	if (visited[k])
	{
		return;
	}
	visited[k] = true;
	for (auto x : mp[k])
	{
		q.push(x);
	}
	cout << q.front() << " ";
	q.pop();
	while ((!q.empty()) && (visited[q.front()] == true))
		q.pop();
	if (!q.empty())
		BFS(q.front());
	else
		return;
}
void print()
{
	auto it = mp.begin();
	for (it = mp.begin(); it != mp.end(); it++)
	{
		cout << it->first << " : ";
		for (auto it2 : mp[it->first])
			cout << it2 << " ";
		cout << "\n";
	}
}
int main()
{
	cin >> n;
	int m, x;
	for (int i = 0; i <= (n - 1); i++)
	{
		cin >> m >> x;
		connect(m, x);
	}
	int k;
	cout << "------------------------------------------------------------------BFS from desired node-------------------------------------------------------------\n";
	cout << "\nEnter the node : ";
	cin >> k;
	q.push(k);
	BFS(q.front());
	cout << "\n";
	cout << "------------------------------------------------------------------Each node and their respective connections-------------------------------------------\n";
	print();
}
