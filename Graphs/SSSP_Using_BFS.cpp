#include <bits/stdc++.h>
using namespace std;
int N = 1e5;
vector<vector<int>> v(N); // Adjacency List
vector<bool> vis(N, false); // Visited Vector
vector<int> dis(N, 0); // Distance Vector

// It's important to note that the given graph is "Un-Weighted" Graph.
int main()
{
    int n, m; cin >> n >> m;
    for (int i = 0;  i < m;  i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    function<void(int node)> bfs = [&](int node) -> void
    {
        queue<int> q; q.push(node);
        vis[node] = true;
        dis[node] = 0;
        while(!q.empty())
        {
            int ff = q.front(); q.pop();
            for(const auto& val : v[ff])
            {
                if(!vis[val])
                {
                    vis[val] = true;
                    dis[val] = dis[ff] + 1;
                    q.push(val);
                }
            }
        }
    };
    int root; cin >> root;
    bfs(root);
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    return 0;
}
