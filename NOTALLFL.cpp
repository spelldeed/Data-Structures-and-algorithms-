#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		int k;
		cin >> k;
		vector<int> a(N), flavor(k);;
		for (int j = 0; j < N; j++)
			cin >> a[j];
		 
		for (int j = 0; j < k; j++)
			flavor[j] = 0;
		int X = 0;
		int mi = -5000000;
		int count = 0;
		for (int j = 0; j < N; j++)
		{
			if (flavor[a[j] - 1] == 0)
			{
				flavor[a[j] - 1]++;
				count++;
			}
			else
			{
				flavor[a[j] - 1]++;
			}
			if (count == k)
			{
				flavor[a[X] - 1]--;
				if (flavor[a[X] - 1] == 0)
					count--;
				if (mi < (j - X))
					mi = j - X;
				X++;
			}
		}



		if (mi == -5000000)
			cout << N << endl;
		else
		{
			if ((N - X) > mi)
				cout << N - X << endl;
			else
				cout << mi << endl;
		}

	}
}