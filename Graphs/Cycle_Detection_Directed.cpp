#include <bits/stdc++.h>
using namespace std;
int N = 2e5 + 1;
vector<vector<int>> v(N); // Adjacency List
vector<int> vis(N, 0); // Visited Vector
// In Visited Vector
// 0 -> Unvisited
// 1 -> Currently active
// 2 -> Completed
bool dfs(int s)
{
    vis[s] = 1;
    for(const auto& val : v[s])
    {
        if(vis[val] == 0)
        {
            if( dfs(val) == true ) return true;
        }
        else if(vis[val] == 1)
        {
            return true;
        }
    }
    vis[s] = 2;
    return false;
}
int main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    cout << "Cycle status : " << dfs(1) << endl;
    return 0;
}
