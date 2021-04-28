#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
struct MyStruct
{
	int in = 0;
	int out = 0;
};
map<int, vector<int>> mp;
map<int,MyStruct> number;
queue<int> path;
int start,ende ;
int n;
bool euler_circuit, euler_path;
void connect_undirected(int x, int y)
{
	mp[x].push_back(y);
	mp[y].push_back(x);
	
}
void connect_directed(int x, int y)
{
	mp[x].push_back(y);
	number[x].out++;
	number[y].in++;
}
void check_undirected()
{
	int cnt = 0;
	for (auto x : mp)
	{
		if (x.second.size() % 2 != 0)
		{
			cnt++;
			start = x.first ;
		}
	}
	if (cnt == 0)
	{
		euler_circuit = true;
		euler_path = true;
	}
	else if (cnt == 2)
		euler_path = true;
	return;
}
void check_directed()
{
	int cnti = 0,cnto=0;
	for (auto x : number)
	{
		if (x.second.in - x.second.out == 1)
		{
			cnti++;
			ende = x.first;
		}
		else if (x.second.out - x.second.in == 1)
		{
			cnto++;
			start = x.first;
		}
		else if (abs(x.second.in - x.second.out) >= 2)
		{
			cnti = -1;
			break;
		}
	}
	if ((cnti == 0) && (cnto == 0))
	{
		euler_circuit = true;
		euler_path = true;
	}

	else if((cnti == 1) && (cnto == 1))
		euler_path = true;
}
void epath(int x)
{
	while (!mp[x].empty())
	{
		int k = mp[x].front();
		auto it = mp[x].begin();
		mp[x].erase(it);
		epath(k);
	}
	path.push(x);
}
int main()
{
	cout << "Enter\n1 for Undirected Graph\n2 for Directed Graph\n";
	int c;
	cin >> c;
	cout << "Enter number of edges : ";
	cin >> n;
	cout << "\nEnter edges\n";
	int x,y;
	switch (c)
	{
	case 1:
		for (int i = 0; i <= (n - 1); i++)
		{
			cin >> x >> y;
			connect_undirected(x, y);
		}
		check_undirected();
		if (euler_circuit)
			cout << "Euler circuit Exists\n";
		if (euler_path)
			cout << "Euler path Exists\n";
		epath(start);
		if (path.size() == n + 1)
		{
			while (!path.empty())
			{
				cout << path.front() << " ";
				path.pop();
			}
		}
		break;
	case 2:
		for (int i = 0; i <= (n - 1); i++)
		{
			cin >> x >> y;
			connect_directed(x, y);
		}
		check_undirected();
		if (euler_circuit)
			cout << "Euler circuit Exists\n";
		if (euler_path)
			cout << "Euler path Exists\n";
		epath(start);
		if (path.size() == n + 1)
		{
			while (!path.empty())
			{
				cout << path.front() << " ";
				path.pop();
			}
		}
		break;
	}
}