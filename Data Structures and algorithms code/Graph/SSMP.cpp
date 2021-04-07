#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#define M INT_MAX
using namespace std;
struct neighbour_info
{
	int value;
	int weight;
};
struct def
{
	int max_dist = INT_MAX;
};
map<int, vector<int>> mp;
map<int, vector<neighbour_info>> info;
map<int, bool> visited;
map<int, int> track;
vector<int> topological;
queue<int> q;
int n,m;
void connect(int x, int y,int z)
{
	mp[x].push_back(y);
	neighbour_info ni;
	ni.value = y;
	ni.weight = z;
	info[x].push_back(ni);
	track[x] = 0;
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
		bool check = false, checkvisi = true;
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
		topological.push_back(q.front());
		q.pop();
		for (auto it2 = visited.begin(); it2 != visited.end(); it2++)
		{
			if (it2->second == false)
			{
				checkvisi = false;
				break;
			}
		}
		if ((!check) && (!checkvisi))
		{
			cout << "\n\nGraph is not DAG anymore\n";
			topological.clear();
			break;
		}
	}
	return;
}
void sssp(int start,int end)
{
	map<int, def> dist;
	dist[start].max_dist = 0;
	dist[topological[0]].max_dist = 0;
	for (int i = 0; i <= topological.size() - 1; i++)
	{
		if (!mp[topological[i]].empty())
		{
			for (auto y : info[topological[i]])
			{
				long long int d = dist[topological[i]].max_dist + y.weight;
				if (dist[y.value].max_dist > d)
					dist[y.value].max_dist = d;
				else
					dist[y.value].max_dist = dist[y.value].max_dist;
			}
		}
	}
	cout << "Shortest Length : " << dist[end].max_dist << "\n";
	
}
int main()
{
	cout << "Enter number of edges and nodes\n";
	cin >> n>>m;
	int x, y,z;
	cout << "Enter node value, connected to and the weight of the edge respectively";
	for (int i = 0; i <= (n - 1); i++)
	{
		cin >> x >> y>>z;
		connect(x, y,z);
	}
	int r = track_node();
	if (r == M)
	{
		cout << "\nGraph is not DAG, hence could not perform Topological sort\n";
		return(0);
	}
	cout << "\nTOPOLOGICAL SORT : ";
	dfs(r);
	if (topological.size() == 0)
	{
		cout << "\nShortest Path could not be found as the graph is not DAG\n";
		return(0);
	}
	cout << "\nEnter the ***valid*** starting and ending node according to your DAG respectively:\n";
	visited.clear();
	int s,e;
	cin >> s>>e;
	sssp(s, e);
	return(0);
}
