#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int surfaceArea(vector<vector<int>> v)
{
    int sum = 0;
    for (int i = 0; i <= (v.size() - 1); i++)
    {
        for (int j = 1; j <= (v[i].size() - 1); j++)
        {
            sum += abs(v[i][j] - v[i][j - 1]);
        }
        sum += v[i][0];
        sum += v[i][v[0].size() - 1];
    }

    
    vector<vector<int>> vt(v[0].size(), vector<int> (v.size()));
    for (int i = 0; i <= (v.size() - 1); i++)
    {
        for (int j = 0; j <= (v[i].size() - 1); j++)
        {
            vt[j][i] = v[i][j];
        }
    }

    for (int i = 0; i <= (vt.size() - 1); i++)
    {
        for (int j = 1; j <= (vt[i].size() - 1); j++)
        {
            sum += abs(vt[i][j] - vt[i][j - 1]);
        }
        sum += vt[i][0];
        sum += vt[i][vt[0].size() - 1];
    }

    return(sum + (v.size() * v[0].size() * 2));
}
int main()
{
	int m, n;
	cin >> m >> n;
	vector<vector<int>> v(m,vector<int> (n));
	for (int i = 0; i <= (m - 1); i++)
	{
		for (int j = 0; j <= (n - 1); j++)
		{
			cin >> v[i][j];
		}
	}
	cout << surfaceArea(v) << "\n";
}