#include<iostream>
using namespace std;
class node
{
public:
	int index;
	int data;
	node* next, * previous;
	node()
	{
		index = 0;
		data = 0;
		next = NULL;
		previous = NULL;
	}
};
class doublylinkedlist
{
public:
	node* head;
	doublylinkedlist()
	{
		head = NULL;
	}
	doublylinkedlist(node* n)
	{
		head = n;
	}
	bool checker(int);
	void prepend(node*);
	void append(node*);
	void insert_k(node*, int);
	void delete_k(int);
	void print();
};
bool doublylinkedlist::checker(int k)
{
	if (head == NULL)
		return(false);
	node* t=NULL;
	node* ptr=head;
	while (ptr != NULL)
	{
		if (ptr->index == k)
		{
			t = ptr;
			break;
		}
		ptr = ptr->next;
	}
	if (t != NULL)
		return(true);
	return(false);
}
void doublylinkedlist::prepend(node* n)
{
	if (head == NULL)
	{
		head = n;
		cout << "Node prepended Successfully!\n";
		return;
	}
	if (checker(n->index))
	{
		cout << "Entered key for the new node already exists! hence the new node could'nt be inserted.\n";
		return;
	}
	head->previous = n;
	n->next = head;
	head = n;
	cout << "Node prepended Successfully!\n";
	return;
}
void doublylinkedlist::append(node* n)
{
	if (head == NULL)
	{
		head = n;
		cout << "Node appended successfully\n";
		return;
	}
	if (checker(n->index))
	{
		cout << "Entered key for the new node already exists! hence the new node could'nt be inserted.\n";
		return;
	}
	node* ptr=head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	n->previous = ptr;
	ptr->next = n;
	cout << "Node appended successfully\n";
	return;
}
void doublylinkedlist::insert_k(node* n, int k)
{
	if (!(checker(k)))
	{
		cout << "Entered key of node next to which new node was supposed to be inserted was not found 1hence failed to insert the node";
		return;
	}
	if (checker(n->index))
	{
		cout << "Entered key for the new node already exists! hence the new node could'nt be inserted.\n";
		return;
	}
	node* ptr = head;
	while (ptr->index != k)
	{
		ptr = ptr->next;
	}
	node* pptr = ptr->next;
	if (pptr == NULL)
	{
		ptr->next = n;
		n->previous = ptr;
	}
	else
	{
		n->next = ptr->next;
		n->previous = ptr;
		pptr->previous = n;
		ptr->next = n;
	}
	cout << "Node inserted Successfully\n";
	return;
}
void doublylinkedlist::delete_k(int k)
{
	if (head == NULL)
	{
		cout << "List is empty\n";
		return;
	}
	node* ptr = head,*mptr=NULL,*pptr=NULL;
	if (head->index == k)
	{
		head = head->next;
		cout << "Node deleted succesfully\n";
		return;
	}
	while (ptr != NULL)
	{
		if (ptr->index == k)
		{
			mptr->next = ptr->next;
			pptr->previous = mptr;
			cout << "Node deleted successfully\n";
			return;
		}
		mptr = ptr;
		ptr = ptr->next;
		if (ptr->next == NULL)
		{
			if (ptr->index == k)
			{
				mptr->next = NULL;
				ptr->previous = NULL;
				cout << "Node deleted successfully\n";
				return;
			}
			cout << "Node Does'nt exist\n";
			return;
		}
		pptr = ptr->next;

	}
	
}
void doublylinkedlist::print()
{
	if (head == NULL)
	{
		cout << "List is empty\n";
		return;
	}
	node* ptr = head;
	cout << "INDEX\tDATA\n";
	while (ptr != NULL)
	{
		cout << ptr->index << "\t" << ptr->data << "\n";
		ptr = ptr->next;
	}
	return;
}
int main()
{
	doublylinkedlist d;
	int ans = 1;

	do {
		int c;
		cout << "ENTER :\n1 TO CREATE\n2 TO PREPEND\n3 TO APPEND\n4 TO INSERT IN BETWEEN\n5 TO DELETE\n6 TO PRINT\n";
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
			d.prepend(N);
			break;
		case 2:
			cout << "Enter index and Data respectively\n";
			cin >> m >> n;
			N->index = m;
			N->data = n;
			d.prepend(N);
			break;
		case 3:
			cout << "Enter index and Data respectively\n";
			cin >> m >> n;
			N->index = m;
			N->data = n;
			d.append(N);
			break;
		case 4:
			cout << "Enter the index ahead of which you want to insert the new node , index for current node and Data respectively\n";
			cin >> m >> p >> n;
			N->index = p;
			N->data = n;
			d.insert_k(N, m);
			break;
		case 5:
			cout << "Enter index of the node to be deleted\n";
			cin >> m;
			d.delete_k(m);
			break;
		case 6:
			d.print();
			break;

		}
		cout << "Would you like to continue? Enter 1 for Yes\n";
		cin >> ans;
	} while (ans == 1);

	return(0);

}