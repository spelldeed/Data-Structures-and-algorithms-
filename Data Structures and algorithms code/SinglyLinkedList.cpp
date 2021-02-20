#include<iostream>
using namespace std;
class node
{
public:
	int index;
	int data;
	node* next;
	node()
	{
		index = 0;
		data = 0;
		next = NULL;
	}
	
};
class singlylinkedlist
{
public:
	node* head;
	singlylinkedlist()
	{
		head = NULL;
	}
	singlylinkedlist(node *n)
	{
		head = n;
	}
	bool checker(int);
	void append(node*);
	void prepend(node*);
	void insert_k(node*,int);
	void delete_k(int);
	void print();
	void reverse();
};
bool singlylinkedlist::checker(int a)
{
	node* ptr = head;
	while (ptr!= NULL)
	{
		if (ptr->index == a)
		{
			return(true);
		}
		ptr = ptr->next;
	}
	return(false);
}
void singlylinkedlist::prepend(node* n)
{
	if (head == NULL)
		head = n;
	else if (checker(n->index))
	{
		cout << "Node with similar index exists hence cannot be added\n";
		return;
	}
	else
	{
		n->next = head;
		head = n;
	}
	cout << "Node prepended Successfully!\n";
	return;
}
void singlylinkedlist::append(node* n)
{
	if (head == NULL)
		head = n;
	else if (checker(n->index))
	{
		cout << "Node with similar index exists hence cannot be added\n";
		return;
	}
	else
	{
		node* ptr = head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = n;
	}
	cout << "Node appended Successfully!\n";
	return;
}
void singlylinkedlist::insert_k(node* n,int a)
{
	if (checker(n->index))
	{
		cout << "index provided for new node already exist!\n";
		return;
	}
	if (!checker(a))
	{
		cout << "The provided positon index was not found, hence cannot insert the node\n";
		return;
	}
	node* ptr=head;
	while (ptr != NULL)
	{
		if (ptr->index == a)
		{
			n->next = ptr->next;
			ptr->next = n;
			cout << "Node added successfully!\n";
			return;
		}
		ptr = ptr->next;
	}
	
}
void singlylinkedlist::delete_k(int a)
{
	if (head == NULL)
	{
		cout << "list Empty!\n";
		return;
	}
	if (!checker(a))
	{
		cout << "Provided index doesn't exist.Please enter a valid index\n";
		return;
	}
	
	node* ptr=head;
	if (ptr->index == a)
	{
		head = head->next;
	}
	else
	{
		node* pptr = head->next;
		while (pptr->index != a)
		{
			pptr = pptr->next;
			ptr = ptr->next;
		}
		ptr->next = pptr->next;

	}
	cout << "Node deleted succesfully!\n";
	return;
}
void singlylinkedlist::print()
{
	if (head == NULL)
	{
		cout << "Empty linked list\n";
		return;
	}
	node* ptr = head;
	cout << "index\tData\n";
	while (ptr != NULL)
	{
		cout << ptr->index << "\t" << ptr->data << "\n";
		ptr = ptr->next;
	}
	return;
}
void singlylinkedlist::reverse()
{
	if (head == NULL)
	{
		cout << "Empty linked list\n";
		return;
	}
	node* back, * curr = NULL, * forward = head;
	while (forward != NULL)
	{
		back = curr;
		curr = forward;
		forward = forward->next;
		curr->next = back;
	}
	head = curr;
	print();
	return;
}
void choice()
{
	singlylinkedlist s;
	int ans = 1;

	do {
		int c;
		cout << "ENTER :\n1 TO CREATE\n2 TO PREPEND\n3 TO APPEND\n4 TO INSERT IN BETWEEN\n5 TO DELETE\n6 TO PRINT\n7 TO REVERSE\n";
		cin >> c;
		int m, n, p;
		node* N = new node();

		switch (c)
		{
		case 1:
			cout << "Enter index and Data respectively\n";
			cin >> m >> n;
			N->index = m;
			N->data = n;
			s.prepend(N);
			break;
		case 2:
			cout << "Enter index and Data respectively\n";
			cin >> m >> n;
			N->index = m;
			N->data = n;
			s.prepend(N);
			break;
		case 3:
			cout << "Enter index and Data respectively\n";
			cin >> m >> n;
			N->index = m;
			N->data = n;
			s.append(N);
			break;
		case 4:
			cout << "Enter the index ahead of which you want to insert the new node , index for current node and Data respectively\n";
			cin >> m >> p >> n;
			N->index = p;
			N->data = n;
			s.insert_k(N, m);
			break;
		case 5:
			cout << "Enter index of the node to be deleted\n";
			cin >> m;
			s.delete_k(m);
			break;
		case 6:
			s.print();
			break;
		case 7:
			s.reverse();
			break;
		default:
			cout << "Invalid Input\n";
			
		}
		cout << "Index of current head " << s.head->index << " ---->head\n";
		cout << "Would you like to continue? Enter 1 for Yes\n";
		cin >> ans;
	} while (ans == 1);

	return;
}
int main()
{
	choice();
}
