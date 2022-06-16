#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;

	node(int data)
	{
		this -> data = data;
		left = right = nullptr;
	}
};
// Accepts the old root node and data and returns the new root node
node* insertInBST(node* root, int d)
{
	// Base Case
	if(root == nullptr)
	{
		return new node(d);
	}
	// Recursive Case. Insert in the subtree and update pointers
	if(d <= root -> data)
	{
		root -> left = insertInBST(root -> left, d);
	}
	else
	{
		root -> right = insertInBST(root -> right, d);
	}
	return root;
}

node* build()
{
	// Reads a list of numbers till we get -1 and these numbers will be inserted into BST
	int d; cin >> d;
	node* root = nullptr;
	while(d != -1)
	{
		root = insertInBST(root, d);
		cin >> d;
	}
	return root;
}

// bfs print
void bfsNewLine(node* root)
{
	if (root == nullptr)
	{
		return;
	}
	queue<node*> q;
	q.push(root);
	q.push(nullptr);
	while (!q.empty())
	{
		node* temp = q.front();
		q.pop();
		if (temp == nullptr)
		{
			cout << endl;
			if (!q.empty())
				q.push(nullptr);
			continue;
		}
		cout << temp -> data << ", ";
		if (temp -> left) q.push(temp -> left);
		if (temp -> right) q.push(temp -> right);
	}
}
// bfs print ends here

// Prints BST in inorder form
// Inorder of BST is always sorted
void inorder(node* root)
{
	if(root == nullptr) return;
	inorder(root -> left);
	cout << root -> data << ", ";
	inorder(root -> right);
}
// Prints BST in inorder form ends here

// Searching for a node in BST
// Time Complexity - O(h) // h -> height
// logn(balanced tree) <= h <= n(skew tree)
bool search(node* root, int data)
{
	if (root == nullptr)
	{
		return false;
	}
	if(root -> data == data)
	{
		return true;
	}
	else if(data < root -> data)
	{
		return search(root -> left, data);
	}
	else
		return search(root -> right, data);
}

// Delete a Node
node* deleteInBST(node* root, int data)
{
	// Base Case
	if(root == nullptr) return nullptr;

	if(data < root -> data)
	{
		root -> left = deleteInBST(root -> left, data);
		return root;
	}
	else if(data == root -> data)
	{
		// Cases : 
		// 1) No child (Leaf Node)
		if(root -> left == nullptr && root -> right == nullptr)
		{
			return nullptr;
		}

		// 2) 1 Child
			// Right Child Exists
			if(root -> left != nullptr && root -> right == nullptr)
			{
				node* temp = root -> left;
				delete root;
				return temp;
			}
			// Left Child Exists
			if(root -> right != nullptr && root -> left == nullptr)
			{
				node* temp = root -> right;
				delete root;
				return temp;
			}

		// 3) 2 Children
			node* replace = root -> right;

			// Find the inorder successor from the right subtree
			while(replace -> left != nullptr)
			{
				replace = replace -> left;
			}
			root -> data = replace -> data;
			root -> right = deleteInBST(root -> right, replace -> data);
			return root;
	}
	else
	{
		root -> right = deleteInBST(root -> right, data);
		return root;
	}

}
// Time Complexity - O(N)
bool isBST(node* root, int mini = INT_MIN, int maxx = INT_MAX) // Top - Bottom Approach
{
	if (root == nullptr)  return true;
	if (mini <= root -> data && root -> data <= maxx)
	{
		return isBST(root -> left, mini, root -> data) && isBST(root -> right, root -> data + 1, maxx);
	}
	else return false;
}
// Check BST ends here

// Converting BST to sorted LL using no extra memory
class LinkedList
{
public:
	node* head;
	node* tail;
};
LinkedList flatten(node* root)
{
	LinkedList l;
	// Edge Case
	if(root == nullptr)
	{
		l.head = l.tail = nullptr;
		return l;
	}

	// Cases
	// 1) Leaf Node
	if(root -> left == nullptr && root -> right == nullptr)
	{
		l.head = l.tail = root;
		return l;
	}
	// 2) Only 1 Child
	if(root -> left != nullptr && root -> right == nullptr)
	{
		LinkedList leftLL = flatten(root -> left);

		leftLL.tail -> right = root;
		l.head = leftLL.head;
		l.tail = root;
		return l;
	}
	if(root -> left == nullptr && root -> right != nullptr)
	{
		LinkedList rightLL = flatten(root -> right);
		root -> right = rightLL.head;

		l.head = root;
		l.tail = rightLL.tail;
		return l;
	}
	// 3) Two Children
	LinkedList leftLL = flatten(root -> left);
	LinkedList rightLL = flatten(root -> right);

	leftLL.tail -> right = root;
	root -> right = rightLL.head;

	l.head = leftLL.head;
	l.tail = rightLL.tail;
	return l;
}
// Converting BST to sorted LL using no extra memory ends here

// Build BST from In-Order And Pre_order
node* buildTreeFromInPre(vector<int> in, vector<int> pre, int s, int e)
{
	static int i = 0;
	if (s > e)
	{
		return nullptr;
	}
	node* root = new node(pre[i]);
	int index = -1;
	for (int j = s; j <= e; ++j)
	{
		if (in[j] == pre[i])
		{
			index = j;
			break;
		}
	}
	++i;
	root -> left = buildTreeFromInPre(in, pre, s, index - 1);
	root -> right = buildTreeFromInPre(in, pre, index + 1, e);
	return root;
}
// Build BST from In-Order And Pre_order ends here

int main()
{
	int n; cin >> n;
	vector<int> pre(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> pre[i];
	}
	vector<int> in = pre;
	sort(in.begin(), in.end());
	node* root = buildTreeFromInPre(in, pre, 0, n - 1);
	bfsNewLine(root);

	return 0;
}
