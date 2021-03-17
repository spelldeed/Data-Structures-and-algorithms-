#include<iostream>
#define ll long long int
#define fo(i,a,n) for(ll i=a;i<=(n-1);i++)
using namespace std;
#define sp 3
class node
{
public:
	int data;
	node* left, * right;
	node()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
	node(int v)
	{
		data = v;
		left = NULL;
		right = NULL;
	}
};
class bt
{
public :
	node* root;
	bt()
	{
		root = NULL;
	}
	bool isempty();
	node* insert(node*, node*);
	void Preorder(node*);
	void Inorder(node*);
	void Postorder(node*);
	node* copy(node*);
	node * mirror(node*);
	int height(node*);
	void FirstBFS(node*);
	void SecondBFS(node*, int);
};
bool bt::isempty()
{
	return(root == NULL);
}
node* bt::insert(node* r, node* n)
{
	node* ptr = r;
	if (isempty())
	{
		root = n;
		cout << "Node Inserted as ROOT NODE\n";
		return(root);
	}
	if (ptr->data == n->data)
	{
		cout << "Value already exist, same values are not allowed\n";
		return(ptr);
	}
	cout << "We are at node whose value is : " << ptr->data<<"\n\nWhere would you like to insert Data , left or right of current node ? enter 'l' for left and 'r' for right\n";
	char opt;
	cin >> opt;
	if (opt == 'l')
	{
			if (ptr->left == NULL)
			{
				ptr->left = n;
				cout << "Node inserted successfully\n";
				return(ptr);
			}
			else
			{
				ptr->left = insert(ptr->left, n);
			}
		
	}
	else
	{
			if (ptr->right == NULL)
			{
				ptr->right = n;
				cout << "Node inserted successfully\n";
				return(ptr);
			}
			else
			{
				ptr->right = insert(ptr->right, n);
			}
	}
}
void bt::Preorder(node* n)
{
	if (isempty())
	{
		cout << "Tree is Empty\n";
		return;
	}

	else if (n == NULL)
		return;
	else
	{
		cout << n->data << " ";
		Preorder(n->left);
		Preorder(n->right);
	}
}
void bt::Inorder(node* n)
{
	if (isempty())
	{
		cout << "Tree is Empty\n";
		return;
	}

	else if (n == NULL)
		return;
	else
	{
		Inorder(n->left);
		cout << n->data << " ";
		Inorder(n->right);
	}
}
void bt::Postorder(node* n)
{
	if (isempty())
	{
		cout << "Tree is Empty\n";
		return;
	}

	else if (n == NULL)
		return;
	else
	{
		Postorder(n->left);
		Postorder(n->right);
		cout << n->data << " ";

	}
}
node* bt::copy(node* n)
{
	if (n != NULL)
	{
		node* nt = new node(n->data);
		if (root == NULL)
			root = nt;
		nt->left = copy(n->left);
		nt->right = copy(n->right);
		return(nt);
	}
	return(NULL);
}
node* bt::mirror(node* n)
{
	if (n != NULL)
	{
		node* nt = new node(n->data);
		if (root == NULL)
			root = nt;
		nt->left = copy(n->right);
		nt->right = copy(n->left);
		return(nt);
	}
	return(NULL);
}
int bt::height(node* n)
{
	if (isempty())
	{
		cout << "Tree is Empty\n";
		return(0);
	}
	if (n == NULL)
		return(-1);
	int lheight = height(n->left);
	int rheight = height(n->right);
	return(max(lheight + 1, rheight + 1));
}
void bt::FirstBFS(node* n)
{
	if (isempty())
	{
		cout << "Tree is Empty\n";
		return;
	}
	int h = height(root);
	for (int i = 0; i <= (h); i++)
	{
		cout << "\n";
		SecondBFS(n, i);
	}
}
void bt::SecondBFS(node* n, int h)
{
	if (n == NULL)
		return;
	else if (h == 0)
	{
		cout << n->data << " ";
		return;
	}
	else
	{
		SecondBFS(n->left, h - 1);
		SecondBFS(n->right, h - 1);
	}
}
int main()
{
	bt b,cp,mi;
	int c, val, ans = 0;

	do {
		cout << "ENTER : \n" << "1. Insert Node\n" << "2. Copy Tree\n" << "3.Mirror of tree\n" <<  "4. Print/Traversal BST values\n";
		node* n = new node;
		int a;
		cin >> c;
		node* k;
		switch (c)
		{
		case 1:
			cout << "Enter the Value\n";
			cin >> a;
			n->data = a;
			k = b.insert(b.root, n);
			break;
		case 2:
			cp.copy(b.root);
			b.FirstBFS(b.root);
			cp.FirstBFS(cp.root);
			break;

		case 3:
			mi.mirror(b.root);
			b.FirstBFS(b.root);
			mi.FirstBFS(mi.root);
			break;
		case 4:
			cout << "Traversals :-\n";
			cout << "--------------------------------------------------DFS---------------------------------------" << "\n";
			cout << "PREORDER : \n";
			b.Preorder(b.root);
			cout << "\nINORDER : \n";
			b.Inorder(b.root);
			cout << "\nPOSTORDER : \n";
			b.Postorder(b.root);
			cout << "\n\n--------------------------------------------------BFS---------------------------------------" << "\n";
			b.FirstBFS(b.root);
			break;
		default:
				cout << "Invalid choice\n";
		}
		cout << "\nWould u like to continue ?\nEnter '0' to exit : ";
		cin >> ans;
	} while (ans != 0);

}
