#include <bits/stdc++.h>
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
	~node()
	{
		delete left;
		delete right;
	}
};
// Preorder starts ---- Preorder -> do operation on root first then on children
// Preorder is -> (TopBottom traversal)
node* buildTree()
{
	int d;
	cin >> d;
	if (d == -1)
	{
		return nullptr;
	}
	node* root = new node(d);
	root -> left = buildTree();
	root -> right = buildTree();
	return root;
}
void print(node* root)
{
	if (root == nullptr)
	{
		return;
	}
	cout << root -> data << " ";
	print(root -> left);
	print(root -> right);
}
// Preorder Ends
// Inorder Starts Here
void printIn(node* root)
{
	if (root == nullptr)
	{
		return;
	}
	// otherwise print Left - Root - Right
	printIn(root -> left);
	cout << root -> data << " ";
	printIn(root -> right);
}
// Inorder ends here
// Postorder starts (Postorder traversal is "Bottom UP Traversal")
void printPost(node* root)
{
	if (root == nullptr)
	{
		return;
	}
	printPost(root -> left);
	printPost(root -> right);
	cout << root -> data << ' ';
}
// Postorder ends
// LevelWise Recursive Using Queue (medium difficulty)
void levelWiseRecursiveQ(queue<node*> q)
{
	queue<node*> t;
	while (!q.empty())
	{
		node* root = q.front();
		q.pop();
		cout << root -> data << ' ';
		if (root -> left) t.push(root -> left);
		if (root -> right) t.push(root -> right);
	}
	cout << endl;
	if (!t.empty())
		levelWiseRecursiveQ(t);
}
// LevelWise Recursive Using Queue Ends Here

// Height Of Tree
int height(node* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	return 1 + max(height(root -> left), height(root -> right));
}
// Height of Tree ends here

// Print kth level of tree
void printKth(node* root, int k)
{
	if (root == nullptr)
	{
		return;
	}
	if (k == 1)
	{
		cout << root -> data << ' ';
		return;
	}
	printKth(root -> left, k - 1);
	printKth(root -> right, k - 1);
}
// Print kth level of tree ends here

// LevelWise Recursive (easy)
// Worst Case Time Complexity -> O(n^2)
void levelWiseRecursive(node* root, int height, int level)
{
	if (level > height)
	{
		return;
	}
	printKth(root, level);
	cout << endl;
	levelWiseRecursive(root, height, level + 1);
}
// LevelWise Recursive ends here

// LevelWise Iterative (print in one line)
void bfs(node* root) // bfs -> Breadth First Search
{
	if (root == nullptr)
	{
		return;
	}
	queue<node*> q;
	q.push(root);
	while (!q.empty())
	{
		node* temp = q.front();
		cout << temp -> data << " , ";
		q.pop();
		if (temp -> left)
		{
			q.push(temp -> left);
		}
		if (temp -> right)
		{
			q.push(temp -> right);
		}
	}
	return;
}
// bfs ends here

// bfs (new line for new level)
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
// bfs (new line) ends here

// count number of nodes
int count(node* root)
{
	if (root == nullptr) return 0;
	return 1 + count(root -> left) + count(root -> right);
}
// count number of nodes ends here

// sum of all nodes of tree
int sum(node* root)
{
	if (root == nullptr) return 0;
	return root -> data + sum(root -> left) + sum(root -> right);
}
// sum of all nodes of tree ends here

// Diameter of tree
// Length of longest path in the tree
// Worst Case Time Complexity -> O(n ^ 2)
int diameter(node* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	int h1 = height(root -> left);
	int h2 = height(root -> right);
	int op1 = h1 + h2;
	int op2 = diameter(root -> left);
	int op3 = diameter(root -> right);
	return max(op1, max(op2, op3));
}
// Length of longest path in the tree ends here

// Diameter (More Optimised) -> O(N)
class mypair
{
public:
	int h;
	int d;

	mypair(int h = 0, int d = 0)
	{
		this -> h = h, this -> d = d;
	}
};
mypair fastDiameter(node* root) // Post Order Traversal
{
	if (root == nullptr)
	{
		return mypair(0, 0);
	}
	mypair p = mypair();
	mypair p1 = fastDiameter(root -> left);
	mypair p2 = fastDiameter(root -> right);
	int presentd = p1.h + p2.h;
	int presenth = 1 + max(p1.h, p2.h);
	p.h = presenth;
	p.d = max(presentd, max(p1.d, p2.d));
	return p;
}
// Diameter (More Optimised) -> By me ends here

// Sum of all nodes beneath a node
// Description ->
// Given a Tree, you need to change every value of node to sum of its descendants
int sumDescendants(node* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	if (root -> left == nullptr && root -> right == nullptr) return root -> data;
	int s = sumDescendants(root -> left) + sumDescendants(root -> right);
	int t = s + root -> data;
	root -> data = s;
	return t;
}

// Height Balanced Binary Tree O(N) -> Bottom - Up Approach
class HBPair
{
public:
	int height;
	bool balanced;
};
HBPair isHeightBalanced(node* root)
{
	HBPair p;
	if (root == nullptr)
	{
		p.height = 0;
		p.balanced = true;
		return p;
	}
	// Recursive Case
	HBPair left_t = isHeightBalanced(root -> left);
	HBPair right_t = isHeightBalanced(root -> right);
	p.height = 1 + max(left_t.height, right_t.height);
	if (abs(left_t.height - right_t.height) <= 1 && left_t.balanced && right_t.balanced)
	{
		p.balanced = true;
	}
	else
		p.balanced = false;
	return p;
}
// Height Balanced Binary Tree ends here

// Build a Tree using a Array/Vector
node* buildTreeFromArray(int* a, int s, int e)
{
	if (s > e)
	{
		return nullptr;
	}
	// Recursive Case
	int mid = (s + e) / 2;
	node* root = new node(a[mid]);
	root -> left = buildTreeFromArray(a, s, mid - 1);
	root -> right = buildTreeFromArray(a, mid + 1, e);
	return root;
}
// Build a Tree using a Array/Vector ends here

// Build a Binary Tree using In-Order And Preorder
node* buildTreeFromInPre(int* in, int* pre, int s, int e)
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
// Build a Binary Tree using In-Order And Preorder ends here

// Build a Binary Tree using In-Order And PostOrder
node* buildTreeFromInPost(int* in, int* post, int s, int e, int size)
{
	static int i = size - 1;
	if (s > e)
	{
		return nullptr;
	}
	node* root = new node(post[i]);
	int index = -1;
	for (int j = s; j <= e; ++j)
	{
		if (in[j] == post[i])
		{
			index = j;
			break;
		}
	}
	--i;
	root -> right = buildTreeFromInPost(in, post, index + 1, e, size);
	root -> left = buildTreeFromInPost(in, post, s, index - 1, size);
	return root;

}
// Build a Binary Tree using In-Order And PostOrder ends here

// Find Minimum and maximum in the Binary Tree
pair<int, int> miniMax(node* root)
{
	if (root == nullptr)
	{
		return pair(INT_MAX, INT_MIN);
	}
	auto p1 = miniMax(root -> left);
	auto p2 = miniMax(root -> right);
	auto p = pair(min(root -> data, min(p1.first, p2.first)), max(root -> data, max(p1.second, p2.second)));
	return p;
}
// Find Minimum and maximum in the Binary Tree ends here

// Make a LinkedList of every level of tree and store their head in the array
class newNode
{
public:
	node* d;
	newNode* next;

	newNode(node* t) : d(t), next(nullptr) {}
};
newNode** levelWiseLinkedList(node* root)
{
	newNode** data = new newNode*[height(root)];
	int k = 0;
	queue<node*> q;
	q.push(root);
	q.push(nullptr);
	newNode* head = nullptr, *tail = nullptr;
	while (!q.empty())
	{
		node* temp = q.front();
		q.pop();
		if (temp == nullptr)
		{
			data[k++] = head;
			head = tail = nullptr;
			if (q.empty())
				break;
			q.push(nullptr);
		}
		else
		{
		    if(temp -> left) q.push(temp -> left);
		    if(temp -> right) q.push(temp -> right);
			if (head == nullptr)
			{
				head = tail = new newNode(temp);
			}
			else
			{
				newNode* a = new newNode(temp);
				tail -> next = a;
				tail = tail -> next;
			}
		}
	}
	return data;
}

void printList(newNode* temp)
{
	while(temp != nullptr)
	{
		cout << temp -> d -> data << ' ';
		temp = temp -> next;
	}
	cout << endl;
}
// Make a LinkedList of every level of tree and store their head in the array

//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
int main()
{
	node* root = buildTree();
	newNode** t = levelWiseLinkedList(root);
	for(int i = 0; i < height(root); ++i)
	{
		printList(t[i]);
	}
	return 0;
}
