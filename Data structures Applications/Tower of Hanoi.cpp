#include<iostream>
using namespace std;
void tower_of_hanoi(int n, char start, char mid, char end)
{
	if (n == 1)
	{
		cout << "Move " << n << " from rod " << start << " to rod " << end << "\n";
		return;
	}
	tower_of_hanoi(n - 1, start, end, mid);
	cout << "Move " << n << " from rod " << start << " to rod " << end << "\n";
	tower_of_hanoi(n - 1, mid, start, end);
}
int main()
{
	int n;
	cout << "Enter number of disks : ";
	cin >> n;
	cout << "Rod names--->\n'A' : Source\n'B' : Auxilliary\n'C' : Destination\n";
	tower_of_hanoi(n, 'A', 'B', 'C');
}
