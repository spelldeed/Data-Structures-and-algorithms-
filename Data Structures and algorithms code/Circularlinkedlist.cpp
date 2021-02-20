#include<iostream>
using namespace std;
class node
{
public:
	int data, index;
	node* next;
	node()
	{
		data = 0;
		index = 0;
		next = NULL;
	}
};
class circularlinkedlist
{
public:
	node* head;
	circularlinkedlist()
	{
		head = NULL;
	}
	circularlinkedlist(node *n)
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
bool circularlinkedlist::checker(int k)
{
	if (head == NULL)
		return(false);
	node* ptr = head;
	while (ptr->next != head)
	{
		if (ptr->index == k)
			return(true);
		ptr = ptr->next;
	}
	if (ptr->index == k)
		return(true);
	return(false);
}
void circularlinkedlist::prepend(node* n)
{
	if (head == NULL)
	{
		head = n;
		n->next = head;
		cout << "Node prepended Successfully\n";
		return;
	}
	if (checker(n->index))
	{
		cout << "Key already exists , hence node was not prepended\n";
		return;
	}
	node* ptr = head;
	while (ptr->next != head)
	{
		ptr = ptr->next;
	}

	n->next = head;
	ptr->next = n;
	head = n;
	cout << "Node prepended Successfully\n";
	return;
}
void circularlinkedlist::append(node* n)
{
	if (head == NULL)
	{
		head = n;
		n->next = head;
		cout << "Node was added as head\n";
		return;
	}
	if (checker(n->index))
	{
		cout << "Key already exists , hence node was not prepended\n";
		return;
	}
	node* ptr = head;
	while (ptr->next != head)
	{
		ptr = ptr->next;
	}

	n->next = head;
	ptr->next = n;
	cout << "Node appended Successfully\n";
	return;
}
void circularlinkedlist::insert_k(node* n, int k)
{
	if (!(checker(k)))
	{
		cout << "Key " << k << " does not exist\nHence node was not inserted\n";
		return;
	}
	if (checker(n->index))
	{
		cout << "Key provided for new node already exists , hence node was not inserted\n";
		return;
	}
	node* ptr = head;
	while (ptr->next != head)
	{
		if (ptr->index == k)
		{
			n->next = ptr->next;
			ptr->next = n;
			cout << "Node inserted Successfully\n";
			return;
		}
		ptr = ptr->next;
	}
	n->next = head;
	ptr->next = n;
	cout << "Node inserted Successfully\n";
	return;
}
void circularlinkedlist::delete_k(int k)
{
	if (head == NULL)
	{
		cout << "List is Empty\n";
		return;
	}
	node* ptr = head,*pptr=NULL;
	if (ptr->index == k)
	{
		while (ptr->next != head)
		{
			ptr = ptr->next;
		}

		ptr->next = head->next;
		head = head->next;
		cout << "Node deleted Successfully\n";
		return;
	}
	while (ptr->next != head)
	{
		if (ptr->index == k)
		{
			pptr->next = ptr->next;
			cout << "Node deleted Successfully\n";
			return;
		}
		pptr = ptr;
		ptr = ptr->next;
	}
	if (ptr->index == k)
	{
		pptr->next = head;
		cout << "Node deleted Successfully\n";
		return;
	}
	
	cout << "Node with key " << k << " does not exist\n";
	return;
}
void circularlinkedlist::print()
{
	if (head == NULL)
	{
		cout << "List is empty\n";
		return;
	}
	cout << "Index\tData\n";
	node* ptr = head;
	while (ptr->next != head)
	{
		cout << ptr->index << "\t" << ptr->data << "\n";
		ptr = ptr->next;
	}
	cout << ptr->index << "\t" << ptr->data << "\n";
	return;
}
int main()
{
	circularlinkedlist cl;
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
			cl.prepend(N);
			break;
		case 2:
			cout << "Enter index and Data respectively\n";
			cin >> m >> n;
			N->index = m;
			N->data = n;
			cl.prepend(N);
			break;
		case 3:
			cout << "Enter index and Data respectively\n";
			cin >> m >> n;
			N->index = m;
			N->data = n;
			cl.append(N);
			break;
		case 4:
			cout << "Enter the index ahead of which you want to insert the new node , index for current node and Data respectively\n";
			cin >> m >> p >> n;
			N->index = p;
			N->data = n;
			cl.insert_k(N, m);
			break;
		case 5:
			cout << "Enter index of the node to be deleted\n";
			cin >> m;
			cl.delete_k(m);
			break;
		case 6:
			cl.print();
			break;
		default:
			cout << "Invalid choice\n";
		}
		cout << "\n key : "<<cl.head->index<< " ---> head" << "\n";
		cout << "Would you like to continue? Enter 1 for Yes\n";
		cin >> ans;
	} while (ans == 1);

	return(0);

}