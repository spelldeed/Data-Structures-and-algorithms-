#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<string>
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<=(n-1);i++)
#define f first
#define s second 
using namespace std;
struct four
{
	string d,e,f,g ;
};
double timeConversion(string s,string k)
{
	if ((k == "AM") && (s.substr(0, 2) == "12"))
		s.replace(0, 2, "00");
	else if ((k == "PM") && ((stoi(s.substr(0, 2))) < 12))
		s.replace(0, 2, to_string(((stoi(s.substr(0, 2))) + 12) % 24));
	s.replace(2, 1,".");
	
	return(stod(s));
}

int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		string arr[2];
		cin >> arr[0] >> arr[1];
		double x= timeConversion(arr[0],arr[1]);
		string a, b, c, d ;
		ll n;
		cin >> n;
		vector<pair<double, double>> v;
		fo(i, 0, n)
		{
			cin >> a >> b >> c >> d;
			v.push_back(make_pair( timeConversion(a, b),timeConversion(c, d) ));
			fflush(stdin);
		}
		fo(i, 0, n)
		{
			if (v[i].f <= v[i].s)
			{
				if ((v[i].f <= x) && (x <= v[i].s))
					cout << "1";
				else
					cout << "0";
			}
			else
			{
				if (((v[i].first <= x) && (x <= 11.59)) || (x <= v[i].s))
					cout << "1";
				else
					cout << "0";
			}
		}
		
		
		cout << "\n";
	
	}
	return(0);
}
