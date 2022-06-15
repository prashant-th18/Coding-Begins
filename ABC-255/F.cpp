#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */

vector<pair<int, int>> v;

// https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
int buildTree(vector<int>& in, vector<int>& pre, int inStrt, int inEnd, map<int, int>& mp)
{
	static int preIndex = 0;

	if (inStrt > inEnd)
		return -1;

	/* Pick current node from Preorder traversal using preIndex
	and increment preIndex */
	int curr = pre[preIndex++];
	/* If this node has no children then return */
	if (inStrt == inEnd)
		return curr;

	/* Else find the index of this node in Inorder traversal */
	int inIndex = mp[curr];

	/* Using index in Inorder traversal, construct left and
	right subtress */
	v[curr].ff = buildTree(in, pre, inStrt, inIndex - 1, mp);
    v[curr].ss = buildTree(in, pre, inIndex + 1, inEnd, mp);

	return curr;
}

// This function mainly creates an unordered_map, then
// calls buildTree()
int buldTreeWrap(vector<int>& in, vector<int>& pre, int len)
{
	// Store indexes of all items so that we
	// we can quickly find later
	map<int, int> mp;
	for (int i = 0; i < len; i++)
		mp[in[i]] = i;

	return buildTree(in, pre, 0, len - 1, mp);
}

// https://www.geeksforgeeks.org/check-if-given-inorder-and-preorder-traversals-are-valid-for-any-binary-tree-without-building-the-tree/
// C++ program to check if given inorder
// and preorder traversals of size N are
// valid for a binary tree or not
bool checkInorderPreorderUtil(int inStart, int inEnd, int& preIndex, vector<int>& preorder, map<int, int>& inorderIndexMap)
{
	if (inStart > inEnd)
		return true;

	// Build the current Node
	int rootData = preorder[preIndex];
	preIndex++;

	// If the element at current Index
	// is not present in the inorder
	// then tree can't be built
	if (inorderIndexMap.find(rootData)	== inorderIndexMap.end())
		return false;

	int inorderIndex = inorderIndexMap[rootData];

	// If the inorderIndex does not fall
	// within the range of the inorder
	// traversal of the current tree
	// then return false
	if (!(inStart <= inorderIndex && inorderIndex <= inEnd))
		return false;

	int leftInorderStart = inStart;
	int leftInorderEnd = inorderIndex - 1;
	int rightInorderStart = inorderIndex + 1;
	int rightInorderEnd = inEnd;

	// Check if the left subtree can be
	// built from the inorder traversal
	// of the left subtree and preorder
	if (!checkInorderPreorderUtil(leftInorderStart, leftInorderEnd, preIndex, preorder, inorderIndexMap))
		return false;

	// Check if the left subtree can be
	// built from the inorder traversal
	// of the left subtree and preorder
	else
		return checkInorderPreorderUtil( rightInorderStart, rightInorderEnd, preIndex, preorder, inorderIndexMap);
}

// Function to check for the validation of
// inorder and preorder
bool checkInorderPreorder(vector<int>& pre, vector<int>& in, int& n)
{
	map<int, int> inorderIndexMap;

	for (int i = 0; i < n; i++)
		inorderIndexMap[in[i]] = i;

	int preIndex = 0;
	if (checkInorderPreorderUtil(0, n - 1, preIndex, pre, inorderIndexMap)) {
		return true;
	}
	else {
		return false;
	}
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<int> preorder(n), inorder(n);
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    
    }
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    if(checkInorderPreorder(preorder, inorder, n) == false) {
        cout << -1; return 0;
    }
    v.assign(n + 50, make_pair(-1, -1));
    int root = buldTreeWrap(inorder, preorder, n);
    if(root == 1) {
        int c = 1;
        for(int i = 1; i <= n; ++i) {
            c += ((v[i].ff != -1));
            c += ((v[i].ss != -1));
        }
        if(c != n) cout << -1;
        else {
            for(int i = 1; i <= n; ++i) {
                cout << ((v[i].ff == -1) ? (0) : (v[i].ff)) << ' ' << ((v[i].ss == -1) ? (0) : (v[i].ss)) << '\n';
            }
        }
    }
    else cout << -1;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
#ifdef LOCAL
        cout << "##################" << '\n';
#endif
        if (solve())
        {
            break;
        }
        cout << '\n';
    }
#ifdef LOCAL
    cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}
// -> Keep It Simple Stupid!
