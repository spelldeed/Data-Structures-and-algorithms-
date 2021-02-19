#include<iostream>
#include<vector>
#include<algorithm>
#define f(i,a,n) for(int i=a;i<(n);i++)
#define ll long long int
using namespace std;

void smp()
{
	vector<vector<int>> vm = {{4,3,1,2},
		{2,1,3,4},
		{1,3,4,2},
		{4,3,1,2}},
		vw = {{3,2,4,1},
			{2,3,1,4},
			{3,1,2,4},
			{3,2,4,1}};
	vector<int> vmch(4, 0),vwch(4,-1);
	int wt;
	bool ch = true;
	cout << "\nPROBLEM :\nPreference of male\n";
	f(i,0,4)
	{
		f(j,0,4)
		{
			cout << vm[i][j] << " " ;
			vm[i][j] = vm[i][j] - 1;
		}
		cout << "\n";
	}
	cout << "Preference of female\n";
	int vf[4][4];
	f(i,0,4)
	{
		f(j,0,4)
		{
			cout << vw[i][j] << " ";
			int t=vw[i][j];
			vf[i][t - 1]=j;
		}
		cout << "\n";
	}
	while (ch)
	{
		ch = false;
		for(int i=0;i<=3;i++)
		{
			wt = vm[i][vmch[i]];
			if (vwch[wt] == -1 || vwch[wt] == i)
			{
				vwch[wt]=i;
			}
			else if (vf[wt][i] > vf[wt][vwch[wt]])
			{
				vmch[i]++;
				ch =true;
			}
			else 
			{
				vmch[vwch[wt]]++;
				vwch[wt] = i;
				 ch=true;
			}
		}
	}
	cout << "Solution :\n";
	int i = 1;
	for(auto x:vwch)
	{
		cout << i<<" " << x + 1 << "\n";
		i++;
    }
}
ll gcd_2(ll x, ll y, ll* x1, ll* x2)
{
	if (x == 0)
	{
		*x1 = 0, * x2 = 1;
		return(y);
	}
	ll x3, x4;
	ll g = gcd_2(y % x, x, &x3, &x4);

	*x1 = x4 - (y / x) * x3;
	*x2 = x3;

	return g;
}
ll mul_inverse(ll x, ll y)
{
	ll x1, x2;
	ll ans = gcd_2(x, y, &x1 ,&x2);
	return(((x1 % y) + y) % y);
}
ll gcd(ll x, ll y)
{
	if (y == 0)
		return(x);
	else
		return(gcd(y, x % y));
}


int main()
{
	int n,ans=1;
	ll a = 9384764854422, b = 8923794876682362;
	cout << "PROGRAM :--\n1 for Stable marriage problem\n2 for Euclid's algorithm\n3 for Pigeonhole Principle\n4 for Multiplicative inverse\n";
	do {
		cout << "\nEnter your choice ";
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "-----------------------------STABLE MARRIAGE PROBLEM-------------------------------" << "\n";
			smp();
			cout << "-------------------------------STABLE MARRIAGE PROBLEM ENDS--------------------------" << "\n";
			break;
		case 2:
			cout << "About : Euclid's algo is used to get greatest common divider(gcd) especially for large numbers in desirable time limit";
			cout << " which otherwise via general approach cannot be achieved.\n";
			cout << "\nSolution :\nGCD of 9384764854422,8923794876682362 is --> ";
			cout << (a > b ? gcd(a, b) : gcd(b, a)) << "\n";
			cout << "--------------------------------EUCLID'S ALGORITHM ENDS---------------------------------" << "\n";
			break;
		case 3:
			cout << "----------------------------------PIGEONHOLE PRINCIPAL-------------------------------------" << "\n";
			cout << "About : Pigeonhole principal states that to accomodate 'n' pigeons in 'm' pigeonhole where 'n > m' then atleast one pigeonhole will have two or more pigeons" << "\n";
			cout << "ALSO KNOWN AS SHOE-BOX PRINCIPAL\n"<<"PROBLEM STATEMENT\n";
			cout << "How many different rooms are needed to assign 500 classes if there are 45 different timeperiods in the university"
				<< " timetable are available.\n";
			cout << "Ans = " << ((500 - 1) / 45) + 1 << "\n";
			cout << "-----------------------------------PIGEONHOLE PRINCIPAL PROBLEM ENDS------------------------" << "\n";
			break;
		case 4:
			cout << "-------------------------------------MULTIPLICATIVE INVERSE---------------------------------" << "\n";
			cout << "\nMultiplicative inverse exits if and only if both numbers are coprime";
			cout << "\nNumbers are 392 and 27 , Their GCD is ";
			cout << gcd(392, 27) << "\n";
			gcd(392, 27) != 1 ? cout << "No solution\n" : cout << "Solution : "<<mul_inverse(27,392)<<"\n";
			cout << "---------------------------------------MULTIPLICATIVE INVERSE PROBLEM ENDS--------------------" << "\n";
			break;
		default:
			cout << "\nInvalid Response\n";
		}
		cout << "\nEnter 1 to continue 0 to exit\n";
		cin >> ans;
	} while (ans != 0);

	
}

