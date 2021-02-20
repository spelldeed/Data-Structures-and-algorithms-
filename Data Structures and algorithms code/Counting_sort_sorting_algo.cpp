#include<iostream>
#include<vector>
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<=(n-1);i++)
using namespace std;
int main()
{
	cout << "Enter Size of the sequence\n";
	ll n;
	cin >> n;
	cout << "Enter " << n << " elements in the range of [0-20]\n";
	vector<ll> v(n),vf(n);
	vector<ll> vi(21, 0);
	fo(i, 0, n)
	{
		cin >> v[i];
	}
	fo(i, 0, n)
	{
		++vi[v[i]];
	}
	fo(i, 1, 21)
	{
		vi[i] = vi[i - 1] + vi[i];
	}
	fo(i, 0, n)
	{
		vf[--vi[v[i]]] = v[i];
	}
	cout << "Sorted Array is as follows\n";
	fo(i, 0, n)
	{
		cout << vf[i] << " ";
	}
}