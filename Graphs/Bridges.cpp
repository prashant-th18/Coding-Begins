#include <bits/stdc++.h>
using namespace std;
int N = 1e5;
vector<vector<int>> v(N); // Adjacency List
vector<bool> vis(N, false); // Visited Vector
vector<int> in(N); // It stores the time at which ith node is visited
vector<int> low(N); // low[i] = min(in[ancestor1], in[ancestor2]..); initially low[i] = in[i];
int main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int timer = 0;
    function<void(int node, int parent)> dfs = [&](int node, int parent) -> void
    {
        vis[node] = true;
        low[node] = in[node] = timer;
        timer++;
        for(int child : v[node])
        {
            if(child == parent) continue;
            else
            {
                if(vis[child])
                {
                    // Edge     child - node      is a back-edge
                    low[node] = min(low[node], in[child]);
                }
                else
                {
                    // Edge     child - node      is a forward edge
                    dfs(child, node);
                    if(low[child] > in[node])
                    {
                        cout << node << " - " << child << " is a bridge\n";
                    }
                    low[node] = min(low[node], low[child]);
                }
            }
        }
    };
    dfs(1, -1);
    return 0;
}
