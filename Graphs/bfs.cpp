#include <bits/stdc++.h>
using namespace std;
int N = 1e5; 
vector<vector<int>> v(N);
vector<bool> vis(N);
int main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    function<void(int root)> bfs = [&](int root) -> void
    {
        queue<int> q; q.push(root);
        vis[root] = true;
        while(!q.empty())
        {
            int ff = q.front(); q.pop();
            cout << ff << ' ';
            for(const auto& val : v[ff])
            {
                if(!vis[val])
                {
                    vis[val] = true;
                    q.push(val);
                }
            }
        }
    };
    int root; cin >> root;
    bfs(root);
    return 0;
}
