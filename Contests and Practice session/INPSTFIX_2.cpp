#include<iostream>
#include<stack>
#include<map>
#define ll long long int
#define f(i,a,n) for(int i=a;i<=(n-1);i++)
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		map<char, int> m;
		m['+'] = m['-'] = 3;
		m['*'] = m['/'] = 2;
		m['^']=1;
		m['('] = 6;
		stack<char> st;
		f(i, 0, s.size())
		{
			if (s[i] == '(')
				st.push('(');
			else if ((s[i] == '*') || (s[i] == '/') || (s[i] == '+') || (s[i] == '-'))
			{
				while ((!st.empty()) && (m[s[i]] >= m[st.top()]))
				{
					cout << st.top();
					st.pop();
				}
				st.push(s[i]);
			}
			else if (s[i] == '^')
				st.push('^');
			else if (s[i] == ')')
			{
				while (st.top() != '(')
				{
					cout << st.top();
					st.pop();
				}
				st.pop();
			}
			else
				cout << s[i];
		}
		while (!st.empty())
		{
			cout << st.top();
			st.pop();
		}
		cout << "\n";
	}
}