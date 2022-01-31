// Rules : 
// 1) Each node must be a member of one of the two sets { A set may remain empty }
// 2) Edges should be present between nodes of two different sets only.
#include <bits/stdc++.h>
using namespace std;
int N = 2e5 + 1;
vector<vector<int>> v(N); // Adjacency List
vector<bool> vis(N, false);
vector<int> col(N); // Either the colour of the node is 0 or 1
// Bipartite Checking and Assigning Function
bool dfs(int s, int c)
{
    vis[s] = true;
    col[s] = c;
    for(int child : v[s])
    {
        if(!vis[child])
        {
            if( dfs(child, c ^ 1) == false ) // XOR will invert the color for the "nbr"
            {
                return false;
            }
        }
        else
        {
            if(col[s] == col[child])
            {
                return false; 
            }
        }
    }
    return true;
}
int main()
{
    int vertices, edges; cin >> vertices >> edges;
    for (int i = 0; i < edges; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(dfs(1, 0))
    {
        for (int i = 1; i <= vertices; i++) {
            cout << i << ' ' << col[i] << '\n';
        }
    }
    else
    {
        cout << "Not Possible";
    }
    return 0;
}
