#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
struct node
{
	int data=0;
	int weight=0;
	int from = 0;
};
struct comp
{
	constexpr bool operator()(pair<int, int>& a, pair<int, int>& b)const noexcept
	{
		return(a.second > b.second);
	}
};

queue<node> edges;

map<int, vector<node>> mp;
map<int, bool> visited;
priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
int n, m;
void connect(int x, int y, int z)
{
	node n;
	n.data = y;
	n.weight = z;
	mp[x].push_back(n);
	n.data = x;
	mp[y].push_back(n);
}

void prim_algo(int x)
{
	visited[x] = true;
	if (edges.size() == m - 1)
		return;
	
	for (auto y : mp[x])
	{
		if (!visited[y.data])
		{
			pq.push(make_pair(y.data, y.weight));
		}
	}
	int k = pq.top().first;
	while (visited[k])
	{
		pq.pop();
		k = pq.top().first;
	}
	node n;
	n.data = k;
	n.weight = pq.top().second;
	n.from = x;
	edges.push(n);
	pq.pop();
	prim_algo(k);
}
int main()
{
	cout << "Each and every vertices should be connected to atleast one other vertices\n";
	cout << "Enter number of edges and vertices respectively :";
	
	cin >> n >> m;
	int x, y,z;
	cout << "Enter From, to and weight of the edge respectively\n";
	for (int i = 0; i <= (n - 1); i++)
	{
		cin >> x >> y >> z;
		connect(x, y, z);
	}
	cout << "\nEnter the value of node you would like to start from\n";
	int s;
	cin >> s;
	prim_algo(s);
	if (edges.size() == m - 1)
	{
		cout << "\nWe got the minimum spanning tree :-\n";
		int sum = 0;
		cout << "FROM\tTO\tWeight\n";
		while (!edges.empty())
		{
			cout << edges.front().from << " -----> " << edges.front().data << "\t" << edges.front().weight << "\n";
			sum += edges.front().weight;
			edges.pop();
		}
		cout << "Cost : ";
		cout << sum << "\n";
	}
}

