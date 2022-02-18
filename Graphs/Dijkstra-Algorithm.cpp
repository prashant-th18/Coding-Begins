// Dijkstra's Algorithm
// SSSP on weighted (Directed/Undirected) Graph
#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int main()
{
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> v(n + 1);
    // Every Node will have a vector of pair of integers, which will store {neighbour, weight to this
    //                                                                                     neighbour}
    for(int i = 0; i < m; ++i)
    {
        int a, b, w; cin >> a >> b >> w; // We are assuming Graph to be __Undirected__
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    // We will use Priority_Queue which will store pair of integers
    // The second integer will be the node number
    // Whereas the first integer will be distance of this node from the source node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Now my priority queue will store {weight, node} in the ascending order
    // Which means .top() will be having the minimum weight
    
    // Distance vector to store distance from the source node
    vector<int> dist(n + 1, inf); // inf means node "i" is not reachable from source till now
    pq.push({0, 1}); dist[1] = 0; // Assuming Source node = 1
    while(!pq.empty())
    {
        int curr_node = pq.top().second; // Node which is having minimum distance till now
        int node_dis = pq.top().first; // minimum distance
        
        if(dist[curr_node] != node_dis) continue; 
       // What above line means that okay, we have found earlier a minimum distance to node "curr_node"
       // And it's neighbour has been minimized using that minimum distance, and now you don't need
       // to process this node again
        pq.pop();
        for(const auto& [neighbour, weight] : v[curr_node])
        {
            if(node_dis + weight < dist[neighbour])
            {
                dist[neighbour] = node_dis + weight; // Distance updated
                pq.push({dist[neighbour], neighbour}); // Pushed intor pq, so that "neigbour's" 
                                                     // neighbour distance can be minimized
            }
        }
    }
    cout << "Distance Vector\n";
    for(int i = 1; i <= n; ++i) cout << dist[i] << ' ';
    return 0;
}
