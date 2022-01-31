// We are using Kahn's Algorithm here
// It is valid in dAG { Directed Acyclic Graph }
#include <bits/stdc++.h>
using namespace std;
int N = 1e5;
vector<vector<int>> v(N); // Adjacency List
vector<bool> vis(N, false); // Boolean Vector
vector<int> in(N); // Stores In-Degree of a Node
void kahn(int n)
{
    vector<int> res; // This will store the topo sort of graph
    queue<int> q;
    for(int i = 1; i <= n; ++i)
    {
        if(in[i] == 0) q.push(i);
    }
    // Why I am always pushing only those nodes which are having in[node] == 0?
    // This is because if A node has in[node] == 0, then all it's dependencies are pushed into the main res vector
    // before it, making topo sort valid.
    while(!q.empty())
    {
        int ff = q.front(); q.pop();
        
        res.push_back(ff); // We are able to push it because it's in[ff] == 0!
        // When I push some node in "res" then we have to delete all the out-going nodes from it
        for(int val : v[ff])
        {
            --in[val];
            if(in[val] == 0) q.push(val);
        }
    }
    cout << "Topological Sorting is : \n";
    for(auto val : res) cout << val << ' ';
}
int main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        ++in[b]; // Since there's Directed edge from a -> b, therefore we have increased the in-degree of "b"
    }
    kahn(n);
    return 0;
}
