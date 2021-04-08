#include<iostream>
#include<vector>
#include<map>
using namespace std;
int n,m;
struct Node
{
	int value;
	int weight;
};
struct Max_distance
{
	long long int max_dist = INT_MAX;
};
map<int, vector<Node>> mp;
map<int, bool> visited;
void connect(int x, int y,int z)
{
	Node ni;
	ni.value = y;
	ni.weight = z;
	mp[x].push_back(ni);
}

void Bellman_Ford(int s)
{
	map<int, Max_distance> dist;
	int i = 0;
	dist[s].max_dist = 0;
	visited[s] = true;
	for (auto y : mp[s])
	{
		visited[y.value] = true;
	}
	visited[s] = true;
	while (i != (m-1))
	{
		auto it = mp.begin();
		for (it = mp.begin(); it != mp.end(); it++)
		{
			if (visited[it->first])
			{
				for (auto y : it->second)
				{
					long long int d = dist[it->first].max_dist + y.weight;
					if (dist[y.value].max_dist > d)
						dist[y.value].max_dist = d;
					
				}
			}
		}
		i++;
	}
	cout << "\nShortest Distance from node with value " << s << "\n";
	for (auto x : dist)
	{
		cout << x.first << " : " << x.second.max_dist << "\n";
	}
	cout << "We can access only above nodes from node " << s<<  "\n";
	return;
}
int main()
{
	cout << "enter the number of edges and vertices respectively : ";
	cin >> n>>m;
	int x,y,z;
	cout << "Enter node value, connected to and the weight of the edge respectively\n";
	for (int i = 0; i <= (n - 1); i++)
	{
		cin >> x >> y>>z;
		connect(x, y,z);
	}
	int s;
	cout << "Enter The value of node you would like to start from\n";
	cin >> s;
	Bellman_Ford(s);
}

