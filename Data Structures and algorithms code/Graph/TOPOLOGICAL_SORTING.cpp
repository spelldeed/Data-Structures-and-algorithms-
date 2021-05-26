#include<iostream>
#include<vector>
#include<map>
#include<queue>
#define M -1
using namespace std;
map<int, vector<int>> mp;
map<int, bool> visited;
map<int, int> track;
queue<int> q;
int n;
void connect(int x, int y)
{
	mp[x].push_back(y);
	track[x] = 0;
	visited[x] = false;
	visited[y] = false;
}
int track_node()
{
	auto it = mp.begin();
	for (it = mp.begin(); it != mp.end(); it++)
	{
		for (auto y : it->second)
		{
			track[y]++;
		}
	}
	for (auto it2 = track.begin(); it2 != track.end(); it2++)
	{
		if (it2->second == 0)
			return(it2->first);
	}
	return(M);
}
void dfs(int x)
{
	if (visited[x])
		return;
	
	q.push(x);
	while (!q.empty())
	{
		bool check = false,checkvisi=true;
		visited[q.front()] = true;
		for (auto y : mp[q.front()])
			track[y]--;
		for (auto it = track.begin(); it != track.end(); it++)
		{
			if ((!visited[it->first]) && (it->second == 0))
			{
				q.push(it->first);
				check = true;
				break;
			}
		}
		cout << q.front() << " ";
		q.pop();
		for (auto it2 = visited.begin(); it2 != visited.end(); it2++)
		{
			if (it2->second == false)
			{
				checkvisi = false;
				break;
			}
		}
		if ((!check) && (!checkvisi)) // If there isn't any node with indegree-->  0 and also we still have unvisited node in our graph then rest of the graph is DAG.
		{
			cout << "\n\nGraph is not DAG anymore\n";
			break;
		}
	}
	return;
}
int main()
{
	cout << "*********************INPORTANT : None of the node can be -1\n\n";
	cout << "Enter number of edges : ";
	cin >> n;
	int x, y;
	for (int i = 0; i <= (n - 1); i++)
	{
		cin >> x >> y;
		connect(x, y);
	}
	int r = track_node();
	if (r == -1)
	{
		cout << "Graph is not DAG, hence could not perform Topological sort\n";
		return(0);
	}
	cout << "\nTOPOLOGICAL SORT : ";
	dfs(r);
	return(0);
}
