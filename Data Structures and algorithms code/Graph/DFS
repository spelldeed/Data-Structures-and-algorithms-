#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Graph
{
public:
	int n;
	map<int, vector<int>> mp;
	map<int, bool> visited;
	Graph(int n)
	{
		this->n = n;
	}
	void connect(int, int);
	void DFS(int);
	void print();
};
void Graph::connect(int x, int y)
{
	mp[x].push_back(y);
	mp[y].push_back(x);//Comment out this line for directed graph.
	visited[x] = false;
	visited[y] = false;
}
void Graph::DFS(int k)
{
	if (visited[k])
		return;
	visited[k] = true;
	cout << k << " ";
	auto it=mp[k].begin();
	for (it = mp[k].begin(); it != mp[k].end(); it++)
	{	
		if (!(visited[*it]))
			DFS(*it);
	}
}
void Graph::print()
{
	auto it = mp.begin();
	for (it = mp.begin(); it != mp.end(); it++)
	{
		cout << it->first << " : ";
		for (auto x : it->second)
			cout << x << " ";
		cout << "\n";

	}
}
int main()
{
	int a,k;
	cin >> a;
	Graph g(a);
	int m, n;
	for (int i = 0; i <= (a - 1); i++)
	{
		cin >> m >> n;
		g.connect(m, n);
	}
	cout << "Enter The node \n";
	cin >> k;
	g.DFS(k);
	cout << "\n----------------------------------------------------------Each Nodes and their respective connections------------------------------------------------------------\n";
	g.print();
	cout << "\n";
	
	
}
