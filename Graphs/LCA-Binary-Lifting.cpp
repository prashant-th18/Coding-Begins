#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
vector<vector<int>> v;
vector<vector<int>> lca;
vector<int> level;
void dfs(int node, int parent, int depth) // Parent of Root node = -1
{
    lca[node][0] = parent;
    level[node] = depth;
    for(const auto& val : v[node])
    {
        if(val != parent)
        {
            dfs(val, node, depth + 1);
        }
    }
}
void init(int n, int col)
{
    // We initialised all the values with -1 which means => for that node 2^i th parent doesn't exist
    // This function is used to initialise the lca vector => specifically the 2^i th parents
    // To get the direct parents(2^0), I will use simple dfs call
    // So number of columns are log(N)
    // i.e. => [0, 1, 2, ... , log(N)]
    // which means [2^0th parent, 2^1th parent, ... ]
    // and row are the nodes [1, 2, 3, ... , N]
    dfs(1, -1, 0); // Assuming 1 to be my Root Node
    // Now I know for all the nodes, their direct (2^0 th parent)
    // DP
    for(int j = 1; j < col; ++j)
    {
        // 2^j th parent
        for(int i = 1; i <= n; ++i)
        {
            int parent = lca[i][j - 1];
            if(parent != -1)
            {
                parent = lca[parent][j - 1];
                lca[i][j] = parent;
            }
        }
    }
}
int LCA(int a, int b)
{
    // b should be deeper
    if(level[a] > level[b])
    {
        swap(a, b);
    }
    int diff = level[b] - level[a];
    while(diff > 0)
    {
        // suppose diff = 13 => 1101 =>
        // make 2^3 jump => 2^2 jump => 2^0 jump
        int max_power = log2(diff);
        b = lca[b][max_power];
        diff -= (1LL << max_power);
    }
    if(a == b) return a;

    /*
    while(lca[a][0] != lca[b][0])
    {
        a = lca[a][0]; b = lca[b][0];
    }
    */ // Because then again, our Complexity of LCA is O(N)

    for(int i = sz(lca[0]) - 1; i >= 0; --i)
    {
        if(lca[a][i] != -1 && (lca[a][i] != lca[b][i]))
        {
            // First, We should not go lift to the place, where parent doesn't exist
            // Second, 2^i the parent of "a" and "b" should not be the same, because in this condition
            // It might be possible that LCA is lost/or we are above LCA
            a = lca[a][i]; b = lca[b][i];
        }
    }
    return lca[a][0];
}
int main()
{
    int n; cin >> n;
    v = vector<vector<int>>(n + 1);
    // Taking input of Rooted Tree
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int col = log2(n) + 1;
    lca = vector<vector<int>>(n + 1, vector<int>(col + 1, -1));
    level.assign(n + 1, 0);
    // In novice approach, we used to lift up by going through all our ancestors which in worst case 
    // scenario will be O(n), which is very Time Consuming
    // In this approach, we are doing "Binary Lifting"
    // As the name suggests, we lift/jump only in the power of 2
    
    // Rules for Binary Lifting ->
    // Suppose "d" is the difference between the levels
    // 1. 2^i <= d
    // Suppose d = 13
    // 1st Jump -> 8 => (d = 5)
    // 2nd Jump -> 4 => (d = 1)
    // 3rd Jump -> 1 => (d = 0)
    // Jumps are just the Binary Representation of initial d (1101) = 13
    // Okay so we have reduces our lifts / jumps from "13" to "3" {logN} ( That's why very efficient )
    // But space complexity will be -> O(NlogN)
    // i.e. We will keep, 
    // What is the 
    // 1. 2^0 = 1 th parent of the node (at distance of 1 from node)
    // 2. 2^1 = 2 th parent of the node (at distance of 2 from node)
    // ...
    // Suppose d is 8.
    // For all the nodes, I have found their 2^0 th, 2^1 th, 2^2 th parent.
    // Now I need to find 2^3 rd parent of the node
    // See, we know, If I have my 2^2 th parent (node1), 
    // what will be the distance between me and 2^2 th parent ->
    // => 2^2 = 4
    // Okay, also what is the difference between 2^2th parent of node1 and node1 ->
    // => 2^2 = 4
    // Also, what is the difference between 2^3 rd parent and "node"
    // => 2^3 = 8
    // So, did you got the relation?
    // => 2^3 = 2^2 + 2^2
    // => For finding node's 2^3 rd parent find node's 2^2 th parent and then find "it's" 2^2th parent
    // So for this storing of 2^i th parent of nodes, we use DP (Dynamic Programming) {Sparse Table}
    init(n, col);
    // lca is initialised
    int q; cin >> q;
    while(q--)
    {
        int a, b; cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }
    return 0;
}
