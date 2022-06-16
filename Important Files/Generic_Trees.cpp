#include<bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
	T data;
	vector<TreeNode<T>*> children;

	TreeNode(T data)
	{
		this -> data = data;
	}

	~TreeNode()
	{
		for (int i = 0; i < children.size(); ++i)
		{
			delete children[i];
		}
	}
};
// Taking Input using Recursion
TreeNode<int>* takeInput()
{
	int rootData;
	cout << "Enter data\n";
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	int n;
	cout << "Enter number of children of " << rootData << endl;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		TreeNode<int>* child = takeInput();
		root -> children.push_back(child);
	}
	return root;
}
TreeNode<int>* takeInputLevelWise()
{
	// We will use queue in this function
	int rootData;
	cout << "Enter rootData\n";
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (!pendingNodes.empty())
	{
		TreeNode<int>* frontNode = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter number of children of " << frontNode -> data << endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; ++i)
		{
			cout << "Enter " << i << "th child of " << frontNode -> data << endl;
			int childData;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			frontNode -> children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}
void printTree(TreeNode<int>* root)
{
	// Edge case (Not base case)
	if (root == nullptr)
	{
		return;
	}

	cout << root -> data << ": ";
	for (int i = 0; i < root -> children.size(); ++i)
	{
		cout << root -> children[i] -> data << ", ";
	}
	cout << endl;
	for (int i = 0; i < (root -> children).size(); ++i)
	{
		printTree(root -> children[i]);
	}
}
// Task : LevelWise Printing
void printTreeLevelWise(TreeNode<int>* root)
{
	// Using queue here
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (!pendingNodes.empty())
	{
		TreeNode<int>* frontNode = pendingNodes.front();
		pendingNodes.pop();
		cout << frontNode -> data << ": ";
		for (int i = 0; i < frontNode -> children.size(); ++i)
		{
			cout << frontNode -> children[i] -> data << ", ";
			pendingNodes.push(frontNode -> children[i]);
		}
		cout << endl;
	}
}
int countNodes(TreeNode<int>* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	int sum = 1;
	for (int i = 0; i < root -> children.size(); ++i)
	{
		sum += countNodes(root -> children[i]);
	}
	return sum;
}
int sumOfAllNodes(TreeNode<int>* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	int sum = root -> data;
	for (int i = 0; i < root -> children.size(); ++i)
	{
		sum += sumOfAllNodes(root -> children[i]);
	}
	return sum;
}
int largestDataNode(TreeNode<int>* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	int maxx = root -> data;
	for (int i = 0; i < root -> children.size(); ++i)
	{
		maxx = max(maxx, largestDataNode(root -> children[i]));
	}
	return maxx;
}
int heightOfTree(TreeNode<int>* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < root -> children.size(); ++i)
	{
		ans = max(ans, heightOfTree(root -> children[i]));
	}
	++ans;
	return ans;
}
// Task : Print all nodes at depth K
void printNodes_D_Depth(TreeNode<int>* root, int level)
{
	//Edge case
	if (root == nullptr)
	{
		return;
	}
	if (level == 0)
	{
		cout << root -> data << ", ";
		return;
	}
	for (int i = 0; i < root -> children.size(); ++i)
	{
		printNodes_D_Depth(root -> children[i], level - 1);
	}
}
// Task : Count Leaf Nodes
int countLeafNodes(TreeNode<int>* root)
{
	// Edge Test
	if (root == nullptr)
	{
		return 0;
	}

	// Base Case
	if ((root -> children).size() == 0)
	{
		return 1;
	}
	int sum = 0;
	for (int i = 0; i < root -> children.size(); ++i)
	{
		sum += countLeafNodes(root -> children[i]);
	}
	return sum;
}
void preorder(TreeNode<int>* root) // printing root first and then children
{
	// Edge Case
	if (root == nullptr)
	{
		return;
	}

	cout << root -> data << " ";
	for (int i = 0; i < root -> children.size(); ++i)
	{
		preorder(root -> children[i]);
	}
}
void postorder(TreeNode<int>* root)
{
	if (root == nullptr)
	{
		return;
	}

	for (int i = 0; i < root -> children.size(); ++i)
	{
		postorder(root -> children[i]);
	}
	cout << root -> data << " ";
}
void deleteTree(TreeNode<int>* root) // Post Order Traversal
{
	if (root == nullptr)
	{
		return;
	}
	for (int i = 0; i < root -> children.size(); ++i)
	{
		deleteTree(root -> children[i]);
	}
	delete root;
}
////
bool presentOrNot(TreeNode<int>* root, int x)
{
	if (root == nullptr)
	{
		return false;
	}
	if (root -> data == x)
	{
		return true;
	}
	bool res = false;
	for (int i = 0; i < root -> children.size(); ++i)
	{
		res |= presentOrNot(root -> children[i], x);
	}
	return res;
}
////
int greaterThanX(TreeNode<int>* root, int x)
{
	if (root == nullptr)
	{
		return 0;
	}
	int cnt = 0;
	if (root -> data > x)
	{
		++cnt;
	}
	for (int i = 0; i < root -> children.size(); ++i)
	{
		cnt += greaterThanX(root -> children[i], x);
	}
	return cnt;
}
////
pair<int, int> maxChildSum(TreeNode<int>* root) // Given a generic tree, find maximum of all of the sums of
// node data + data of its immediate children
{
	if (root == nullptr)
	{
		return pair<int, int>(0, 0);
	}
	pair<int, int> p;
	int sum = root -> data;
	for (int i = 0; i < root -> children.size(); ++i)
	{
		sum += root -> children[i] -> data;
	}
	p = pair(root -> data, sum);
	for (int i = 0; i < root -> children.size(); ++i)
	{
		pair<int, int> temp = maxChildSum(root -> children[i]);
		if (temp.second > p.second)
		{
			p = temp;
		}
	}
	return p;
}
TreeNode<int>* nextLarger(TreeNode<int>* root, int n)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	TreeNode<int>* temp = nullptr;
	if (root -> data > n)
	{
		temp = root;
	}
	for (int i = 0; i < root -> children.size(); ++i)
	{
		TreeNode<int>* t = nextLarger(root -> children[i], n);
		if (t == nullptr) continue;
		else
		{
			if (temp == nullptr) temp = t;
			else
			{
				if (t -> data < temp -> data)
					temp = t;
			}
		}
	}
	return temp;
}
// Find Second Largest Element
pair<TreeNode<int>*, TreeNode<int>*> secondLargest(TreeNode<int>* root)
{
	TreeNode<int>* maximum = nullptr;
	TreeNode<int>* smaximum = nullptr;
	maximum = root;
	for (int i = 0; i < root -> children.size(); ++i)
	{
		auto p = secondLargest(root -> children[i]);
		// p maximum is greater than maximum
		if (p.first -> data > maximum -> data)
		{
			auto temp = maximum;
			maximum = p.first;
			if (p.second == nullptr)
			{
				smaximum = temp;
			}
			else
			{
				if (p.second -> data > temp -> data)
				{
					smaximum = p.second;
				}
				else
				{
					smaximum = temp;
				}
			}
		}
		else
		{
			if(smaximum == nullptr)
			{
				smaximum = p.first;
			}
			else
			{
				if(p.first -> data > smaximum -> data)
				{
					smaximum = p.first;
				}
			}
		}
	}
	return pair(maximum, smaximum);
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main()
{
	TreeNode<int>* root = takeInputLevelWise();
	auto got_it = secondLargest(root);
	cout << got_it.second -> data;
	return 0;
}
