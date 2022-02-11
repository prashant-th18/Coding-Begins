// KOSARAJU'S ALGORITHM
#include <bits/stdc++.h>
using namespace std;
int N = 2e5 + 1;
vector<vector<int>> v(N); // Main Graph
vector<vector<int>> transpose(N); // Transpose Graph
vector<bool> vis(N + 1, false); // Visited Vector
vector<int> order; // Stores elements in the increasing order of their Out-Time
vector<int> SCC; // stores elements for a SCC { Strongly Connected Components }
void dfs(int node)
{
    vis[node] = true;
    for(const auto& val : v[node])
    {
        if(!vis[val])
        {
            dfs(val);
        }
    }
    order.push_back(node); // why? -> Because till now, 
                           // all the nodes which will have lesser out-time will be 
                           // pushed into the order vector
}
void dfs1(int node)
{
    vis[node] = true;
    for(const auto& val : transpose[node])
    {
        if(!vis[val])
        {
            dfs1(val);
        }
    }
    SCC.push_back(node);
}
int main()
{
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        // In the original graph, there exist a directed edge from a -> b
        v[a].push_back(b);
        // But for tranpose, it is opposite
        transpose[b].push_back(a);
    }
    // Calling dfs function over all the nodes to get the correct order of their out-time
    for(int i = 1; i <= n; ++i)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    vis.clear();
    vis.assign(N + 1, false);
    // Now we have the order
    // In this order, the first element is having the lowest out-time and the last element is having maximum
    // out-time
    // Since, we are dealing with the condensation graph, and it is a dAG { Directed Acyclic Graph }
    // and also according to Kosaraju's Algo, we have to start from that node which is having maximum out-time
    // since then only we can ensure that there's no other node which should be traversed earlier
    
    // What we do now is that, we start from the node having maximum out-time as well as it is unvisited
    // And we traverse this node's SCC in transpose vector because since it's out-time is maximum among all those
    // which are unvisited, then in transpose vector, we will be able to go from this node to only those nodes 
    // to which some edges exist and are NOT VISITED. 
    // By this, we can see that we will traverse only the SCC of that node from which we called dfs, and hence we
    // get our SCC vector
    for(int i = n - 1; i >= 0; --i)
    {
        if(!vis[order[i]])
        {
            dfs1(order[i]);
            // Now we got the strongly connected component in which `order[i]` is present.
            cout << "dfs1() called from " << order[i] << " and printing SCC" << '\n';
            for(const auto& val : SCC)
            {
                cout << val << ' ';
            }
            cout << '\n';
            SCC.clear();
        }
    }
    return 0;
}
