#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
int n,m;
struct Node
{
	int value;
	int weight;
};
struct max_node_dist
{
	int max_dist = INT_MAX;
};
struct Compare
{
	constexpr bool operator()(pair<int, int>& a, pair<int, int>& b)const noexcept
	{
		return(a.second > b.second);
	}
};

priority_queue<pair<int,int>, vector<pair<int, int>>,Compare> pq;
map<int, vector<Node>> mp;
map<int,int> previous_track;
void connect(int x, int y, int z)
{
	Node ni;
	ni.value = y;
	ni.weight = z;
	mp[x].push_back(ni);
}
void lazy_Dij(int s,int e)
{
	bool visited=false;
	pq.push(make_pair(s,0 ));
	map<int, max_node_dist> dist;
	dist[s].max_dist = 0;
	while (!pq.empty())
	{
		if (dist[pq.top().first].max_dist >= pq.top().second)
		{
			for (auto y : mp[pq.top().first])
			{
				long long int d = dist[pq.top().first].max_dist + y.weight;

				if (d < dist[y.value].max_dist)
				{
					dist[y.value].max_dist = d;
					pq.push(make_pair(y.value, dist[y.value].max_dist));
					previous_track[pq.top().first] = y.value;
				}
				if (y.value == e)
					visited = true;
			}
		}
		if (pq.top().first == e)
			break;
		pq.pop();
	}
	if (visited)
	{
		cout << "Shortest distance " << dist[e].max_dist << "\n";
		cout << "\nThe path is as follows : ";
		int t=s;
		cout << s << " ";
		while (t != e)
		{
			cout << previous_track[t] << " ";
			t = previous_track[t];
		}
	}
	else
		cout << "Path does not exist\n";
	return;
}
int main()
{
	cout << "Enter number of edges\n";
	cin >> n;
	int x, y, z;
	cout << "Enter the current node, it's neighbour and the edge connecting the neighbour\n";
	cout << "\n*** REMEMBER In Dijkstra's algo edges cannot be negative! ***\n";
	for (int i = 0; i <= (n - 1); i++)
	{
		cin >> x >> y >> z;
		connect(x,y,z);
	}
	int s, e;
	cout << "Enter starting and Ending Nodes respectively : ";
	cin >> s >> e;
	lazy_Dij(s, e);
	return(0);
}
