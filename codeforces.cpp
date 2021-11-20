#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(T data)
	{
		this -> data = data;
		left = right = nullptr;
	}

	~BinaryTreeNode()
	{
		delete left;
		delete right;
		// delete nullptr ??
		// It's okay, nothing happens compiler skips it.
	}
};
template <typename T>
class LL
{
public:
	T data;
	LL* next;
	LL(T data = 0)
	{
		this -> data = data;
		next = nullptr;
	}
};
void printTree(BinaryTreeNode<int>* root)
{
	// Base Case
	if (root == nullptr)
	{
		return;
	}
	cout << root -> data << ": ";
	if (root -> left != nullptr)
	{
		cout << "L" << root -> left -> data << " ";
	}
	if (root -> right)
	{
		cout << "R" << root -> right -> data;
	}
	cout << endl;
	printTree(root -> left);
	printTree(root -> right);
}
void printTreeLevelWise(BinaryTreeNode<int>* root)
{
	if (root == nullptr)
	{
		return;
	}
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (!pendingNodes.empty())
	{
		BinaryTreeNode<int>* temp = pendingNodes.front();
		pendingNodes.pop();
		cout << temp -> data << ": ";
		if (temp -> left)
		{
			cout << "L: " << temp -> left -> data << " ";
			pendingNodes.push(temp -> left);
		}
		else
		{
			cout << "L: " << -1 << " ";
		}
		if (temp -> right)
		{
			cout << "R: " << temp -> right -> data << " ";
			pendingNodes.push(temp -> right);
		}
		else
		{
			cout << "R: " << -1 << " ";
		}
		cout << endl;
	}
}
BinaryTreeNode<int>* takeInputLevelWise()
{
	int rootData;
	cout << "Enter rootData\n";
	cin >> rootData;
	if (rootData == -1)
	{
		return nullptr;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (!pendingNodes.empty())
	{
		BinaryTreeNode<int>* temp = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left Child of " << temp -> data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1)
		{
			BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
			temp -> left = leftChild;
			pendingNodes.push(leftChild);
		}

		cout << "Enter right Child of " << temp -> data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1)
		{
			BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
			temp -> right = rightChild;
			pendingNodes.push(rightChild);
		}
	}
	return root;
}
BinaryTreeNode<int>* takeInput()
{
	int rootData;
	cout << "Enter Data\n";
	cin >> rootData;
	if (rootData == -1)
	{
		return nullptr;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* leftChild = takeInput();
	BinaryTreeNode<int>* rightChild = takeInput();
	root -> left = leftChild;
	root -> right = rightChild;
	return root;
}
int countNodes(BinaryTreeNode<int>* root)
{
	// Base Case
	if (root == nullptr)
	{
		return 0;
	}
	return countNodes(root -> left) + countNodes(root -> right) + 1;
}
bool isPresent(BinaryTreeNode<int>* root, int key)
{
	if (root == nullptr)
	{
		return false;
	}
	if (root -> data == key) return true;
	return isPresent(root -> left, key) || isPresent(root -> right, key);
}
int heightOfTree(BinaryTreeNode<int>* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	return 1 + max(heightOfTree(root -> left), heightOfTree(root -> right));
}
void mirrorBinaryTree(BinaryTreeNode<int>* root)
{
	if (root == nullptr)
	{
		return;
	}
	queue<BinaryTreeNode<int>*> pendingNodes1, pendingNodes2;

	pendingNodes1.push(root), pendingNodes2.push(root);
	while (!pendingNodes2.empty())
	{
		pendingNodes1 = pendingNodes2;
		pendingNodes2 = queue<BinaryTreeNode<int>*>();
		while (!pendingNodes1.empty())
		{
			BinaryTreeNode<int>* temp = pendingNodes1.front();
			pendingNodes1.pop();
			cout << temp -> data << " ";
			if (temp -> right)
			{
				pendingNodes2.push(temp -> right);
			}
			if (temp -> left)
			{
				pendingNodes2.push(temp -> left);
			}
		}
		cout << endl;
	}
}
void inorder(BinaryTreeNode<int>* root)
{
	if (root == nullptr)
	{
		return;
	}
	inorder(root -> left);
	cout << root -> data << " ";
	inorder(root -> right);
}
void preorder(BinaryTreeNode<int>* root)
{
	if (root == nullptr)
	{
		return;
	}
	cout << root -> data << " ";
	preorder(root -> left);
	preorder(root -> right);
}
void postorder(BinaryTreeNode<int>* root)
{
	if (root == nullptr)
	{
		return;
	}
	postorder(root -> left);
	postorder(root -> right);
	cout << root -> data << " ";
}


// Binary Search Tree Starts Here
// Search in BST starts here
// Time Complexity - O(h)  // h -> height of tree
bool searchInBST(BinaryTreeNode<int>* root, int s)
{
	if (root == nullptr)
	{
		return false;
	}
	if (root -> data == s)
	{
		return true;
	}
	else if (root -> data > s)
	{
		return searchInBST(root -> left, s);
	}
	else
	{
		return searchInBST(root -> right, s);
	}
}
// Search in BST ends here

// Elements Between K1 and K2
void printRange(BinaryTreeNode<int>* root, int l, int r)
{
	if (root == nullptr)
	{
		return;
	}
	int d = root -> data;
	if (d <= l)
	{
		if (d == l) cout << d << ' ';
		printRange(root -> right, l, r);
	}
	else if (l < d && d < r)
	{
		printRange(root -> left, l, r);
		cout << d << ' ';
		printRange(root -> right, l, r);
	}
	else
	{
		printRange(root -> left, l, r);
		if (d == r) cout << d << ' ';
	}
}
// Elements Between K1 and K2 ends here

// Check BST { Time Complexity -> O(Nh )}
int minimum(BinaryTreeNode<int>* l)
{
	if (l == nullptr) return INT_MAX;
	return min(l -> data, min(minimum(l -> left), minimum(l -> right)));
}
int maximum(BinaryTreeNode<int>* r)
{
	if (r == nullptr) return INT_MIN;
	return max(r -> data, max(maximum(r -> left), maximum(r -> right)));
}
bool checkBST1(BinaryTreeNode<int>* root)
{
	if (root == nullptr) return true;
	return (maximum(root -> left) < root -> data) && (minimum(root -> right) >= root -> data) && checkBST1(root -> left) && checkBST1(root -> right);
}

// Time Complexity - O(N)
tuple<int, int, bool> isBST(BinaryTreeNode<int>* root) // Bottom - Up Approach
{
	// in tuple -> 1st) Minimum till now, 2nd) Maximum till now, 3rd) isBST or not
	if (root == nullptr)
	{
		return tuple(INT_MAX, INT_MIN, true);
	}
	auto t1 = isBST(root -> left);
	auto t2 = isBST(root -> right);
	decltype(t1) res;
	bool ans = true;
	ans = ans && (get<2>(t1) && get<2>(t2));
	ans = ans && (get<1>(t1) < root -> data);
	ans = ans && (get<0>(t2) >= root -> data);
	int mini = min(root -> data, min(get<0>(t1), get<0>(t2)));
	int maxx = max(root -> data, max(get<1>(t1), get<1>(t2)));
	res = tuple(mini, maxx, ans);
	return res;
}

// Time Complexity - O(N)
bool isBST2(BinaryTreeNode<int>* root, int mini = INT_MIN, int maxx = INT_MAX) // Top - Bottom Approach
{
	if (root == nullptr)  return true;
	if (mini <= root -> data && root -> data <= maxx)
	{
		return isBST2(root -> left, mini, root -> data - 1) && isBST2(root -> right, root -> data, maxx);
	}
	else return false;
}
// Check BST ends here

// Make a BST from a Sorted Array
BinaryTreeNode<int>* makeBST(int* a, int s, int e)
{
	if (s > e)
	{
		return nullptr;
	}
	int mid = (s + e) / 2;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(a[mid]);
	root -> left = makeBST(a, s, mid - 1);
	root -> right = makeBST(a, mid + 1, e);
	return root;
}
// Make a BST from a Sorted Array ends here

// Make a sorted Linked List from BST
// Time Complexity - O(N)
pair<LL<int>*, LL<int>*> makeLL(BinaryTreeNode<int>* root)
{
	if(root == nullptr)
	{
		return pair(nullptr, nullptr);
	}
	LL<int>* temp = new LL(root -> data);
	auto p1 = makeLL(root -> left);
	decltype(p1) res;
	if(p1.first == nullptr)
	{
		res.first = temp;
		res.second = temp;
	}
	else
	{
		res.first = p1.first;
		p1.second -> next = temp;
		res.second = temp;
	}
	auto p2 = makeLL(root -> right);
	if(p2.first)
	{
		res.second -> next = p2.first;
		res.second = p2.second;
	}
	return res;
}
void print(LL<int>* root)
{
	while(root)
	{
		cout << root -> data << ' ';
		root = root -> next;
	}
}
// Make a sorted Linked List from BST ends here

// Given a Binary Tree and a node, you need to find a path from that node to the root
// path will be given by a vector<int>
vector<int> pathToRoot(BinaryTreeNode<int>* root, int d)
{
	if (root == nullptr)
	{
		return vector<int>();
	}
	vector<int> v;
	if(d == root -> data)
	{
		v.push_back(d);
		return v;
	}
	vector<int> left = pathToRoot(root -> left, d);
	vector<int> right = pathToRoot(root -> right, d);
	if(left.size() != 0)
	{
		left.push_back(root -> data);
		return left;
	}
	if(right.size() != 0)
	{
		right.push_back(root -> data);
		return right;
	}
	return v;
}
// Given a Binary Tree and a node, you need to find a path from that node to the root ends here

int main()
{
	BinaryTreeNode<int>* root = takeInputLevelWise();
	int d; cin >> d;
	vector<int> v = pathToRoot(root , d);
	for(auto val : v) cout << val << ' ';
	return 0;
}