#include<iostream>
//#include<stack>
#define ll long long int
#define f(i,a,n) for(ll i=a;i<=(n-1);i++)
using namespace std;
//stack<int> st;
#define MAX 100

class Stack
{
	int top;
	int a[MAX];

public:
	Stack() { top = -1; }
	bool push(int x);
	int pop();
	void display();
	int topE();
	bool empty();
};

bool Stack::push(int x)
{
	if (top >= (MAX - 1))
	{
		cout << "Stack Overflow";
		return false;
	}
	else
	{
		a[++top] = x;
		return true;
	}
}

int Stack::pop()
{
	if (top < 0)
	{
		cout << "Stack Underflow";
		return 0;
	}
	else
	{
		int x = a[top--];
		return x;
	}
}

int Stack::topE()
{
	return a[top];
}

bool Stack::empty()
{
	return (top < 0);
}
void Stack::display()
{
	if (empty())
	{
		cout << "Stack Is EMPTY" << '\n';
		return;
	}
	if (a[top] == 1)
		cout << "^";
	else if (a[top] == 3)
		cout << "*";
	else if (a[top] == 2)
		cout << "/";
	else if (a[top] == 5)
		cout << "+";
	else if (a[top] == 4)
		cout << "-";
	return;
}
int main()
{
	int t;
	cout << "Enter number of testcases : ";
	cin >> t;
	while (t--)
	{
		Stack st;
		cout << "Enter the expression : ";
		string s;
		cin >> s;
		cout << "Infix to Postfix : ";
		f(i, 0, s.size())
		{
			if (s[i] == '(')
				st.push(6);
			if (s[i] == '^')
				st.push(1);
			else if ((s[i] == '*') || (s[i] == '/'))
			{
				while ((!st.empty()) && (st.topE() != 6) && (st.topE() <= 3))
				{
					st.display();
					st.pop();
				}
				s[i] == '*' ? st.push(3) : st.push(2);
			}
			else if ((s[i] == '+') || (s[i] == '-'))
			{
				while ((!st.empty()) && (st.topE() != 6) && (st.topE() <= 5))
				{
					st.display();
					st.pop();
				}
				s[i] == '+' ? st.push(5) : st.push(4);
			}
			else if (s[i] == ')')
			{
				while (st.topE() != 6)
				{
					st.display();
					st.pop();
				}
				st.pop();
			}
			else
			{
				cout << s[i];
			}
		}
		while (!st.empty())
		{
			st.display();
			st.pop();
		}
		cout << "\n";
	}
	return(0);
}