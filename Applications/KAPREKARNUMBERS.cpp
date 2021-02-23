#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void kaprekarNumbers(long long int  p, long long int q)
{
    string s, st, e, k;
    vector<long long int> v;
    for (long long int i = p; i <= q; i++)
    {
        k = to_string(i);
        s = to_string(i * i);

        st = s.substr(0,s.size()- k.size());
        e = s.substr(s.size()-k.size());
        if (s.size() > k.size())
        {
            if (stoi(st) + stoi(e) == i)
            {
                v.push_back(i);
            }
        }
        else
        {
            if (stoi(e) == i)
            {
                v.push_back(i);
            }
        }
    }
    if (v.size() == 0)
    {
        cout << "INVALID RANGE";
        return;
    }
    else
    {
        for (auto x : v)
        {
            cout << x << " ";
        }
        return;
    }
}
int main()
{
	long long int p, q;
	cin >> p >> q;
	kaprekarNumbers(p, q);
}