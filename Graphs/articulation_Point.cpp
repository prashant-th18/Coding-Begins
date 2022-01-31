#include <bits/stdc++.h>
using namespace std;
int N = 2e5;
vector<vector<int>> v(N); // Adjacency List
vector<bool> vis(N, false); // Visited Vector
vector<int> in(N); // In-Time
vector<int> low(N); // Low-Time
int main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    set<int> cut_vertex; // Used set, so that only unique nodes are present
    int timer = 1;
    function<void(int, int)> dfs = [&](int node, int parent = -1) -> void
    {
        vis[node] = true;
        low[node] = in[node] = timer++;
        int children = 0; // This will help in case of root node
        for(const auto& child : v[node])
        {
            if(child == parent) continue; // Child - Parent Edge is never a Back - Edge
            if(vis[child])
            {
                low[node] = min(low[node], in[child]);
            }
            else
            {
                // Making a DFS Call
                dfs(child, node);
                if(low[child] >= in[node] && parent != -1)
                {
                    cut_vertex.insert(node);
                }
                low[node] = min(low[node], low[child]); 
                // This says that If my child is connected to some ancestor, I am also connected to that ancestor
                ++children; // Means for "node", number of subtree is increased.
            }
        }
        if(parent == -1 && children > 1)
        {
            cut_vertex.insert(node);
            // Why we are treating root differently?
            // So the Reason is that, In case of root, every other node has it's "low" >= in[root]
            // Which means that everytime root will become a "Articulation Point" which is obv not true
            // So what we are doing is that, We are maintaining a "children" variable which will count
            // how many children are there for a node.
            // In case of Root, it will help because it children > 1 in case of root,
            // that means if I remove root, previous connected components - 1 + children -> this many connected 
            // components will be generated which obv increase pre_connected_components if and only if children > 1
        }
    };
    dfs(1, -1);
    cout << cut_vertex.size() << '\n';
    for(auto val : cut_vertex) cout << val << ' ';
    return 0;
}
