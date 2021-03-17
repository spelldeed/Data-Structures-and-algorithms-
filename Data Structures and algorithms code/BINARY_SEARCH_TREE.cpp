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
};
class bst
{
public:
	node* root;
	bst()
	{
		root = NULL;
	}
	bool isempty();
	node* insert(node*,node*);
	void Preorder(node*);
	void Inorder(node*);
	void Postorder(node*);
	bool bsearch(int,node *);
	int height(node*);
	void FirstBFS(node*);
	void SecondBFS(node*, int);
	node* deleteBST(node*,int);
};
bool bst::isempty()
{
	return(root == NULL);
}
node* bst::insert(node* r, node* n)
{
	node* ptr=r;
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
	if (ptr->data > n->data)
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
	if (ptr->data < n->data)
	{
		if (ptr->right == NULL)
		{
			ptr->right = n;
			cout << "Node inserted successfully\n";
			return(ptr);
		}
		else
		{
			ptr->right=insert(ptr->right,n);
		}
	}
	
	
}
void bst::Preorder(node* n)
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
void bst::Inorder(node* n)
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
void bst::Postorder(node* n)
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

bool bst::bsearch(int a,node *ptr)
{
	if (isempty())
		return(false);
	if (ptr == NULL)
		return(false);
	if (ptr->data == a)
		return(true);
	if (ptr->data > a)
		bsearch(a,ptr->left);
	else if (ptr->data < a)
		bsearch(a, ptr->right);

}
int bst::height(node *n)
{
	if (isempty())
	{
		cout << "Tree is Empty\n";
		return(0);
	}
	if (n == NULL)
		return(-1);
	int lheight = height(n->left);
	int rheight= height(n->right);
	return(max(lheight+1, rheight+1));
}
void bst::FirstBFS(node* n)
{
	if (isempty())
	{
		cout << "Tree is Empty\n";
		return;
	}
	int h = height(root);
	for (int i = 0; i <= (h); i++)
	{
		SecondBFS(n, i);
	}
}
void bst::SecondBFS(node* n, int h)
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
node* bst::deleteBST(node*r,int v)
{
	if (r == NULL) 
	{
		cout << "Node is absent\n";
		return(NULL);
	}
	else if (v < r->data) 
	{
		r->left = deleteBST(r->left, v);
	}
	
	else if (v > r->data) 
	{
		r->right = deleteBST(r->right, v);
	}

	else {
		
		if (r->left == NULL) 
		{
			node* t = r->right;
			delete r;
			return t;
		}
		else if (r->right == NULL) 
		{
			node* t = r->left;
			delete r;
			return t;
		}
		else 
		{
			
			node* t;
			t = r->right;
			while (t->left != NULL)
			{
				t = t->left;
			}

			r->data = t->data;
		
			r->right= deleteBST(r->right, t->data);
		
		}
	}
	cout << "Node deleted successfully";
	return(r);
}
int main()
{
	bst b;
	int c, val,ans=0;

	do {
		cout << "ENTER : \n" << "1. Insert Node\n" << "2. Search Node\n" << "3. Height of Tree\n"<<"4. Delete Node" << "\n5. Print/Traversal BST values\n" ;
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
			k = b.insert(b.root,n);
			break;
		case 2:
			cout << "Enter the element u want to search : ";
			cin >> a;
			if (b.bsearch(a, b.root))
				cout << "element is present\n";
			else
				cout << "Element is absent\n";
			break;
		case 3:
			cout << "Height of the tree : " << b.height(b.root);
			break;
		case 4:
			cout << "Enter the element you want to delete\n";
			cin >> a;
			k = b.deleteBST(b.root, a);
			break;
			
		case 5:
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
