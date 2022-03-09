#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1000000000;
struct edge {
    ll a, b, cost;
    // It stores 
    // Edge [ a  ---->   b] where cost == "edge weight"
};
int main()
{
    int n, m; cin >> n >> m;
    // We have to maintain a Edge List Here, and traverse over that edge list, atmost "n - 1" times
    // Because After kth traversal over edge list and manipulation of the minimum cost of all the
    // edges from the source node, We will find the shortest distance to all those nodes, whose 
    // shortest path have <= k edges
    vector<edge> edge_list(m);
    vector<ll> dist(n + 1, inf);
    vector<ll> parent(n + 1, -1); // Parent of node, which is the penultimate vertex in shortest path
    for(int i = 0; i < m; ++i)
    {
        int a, b, cost; cin >> a >> b >> cost;
        edge_list[i] = {a, b, cost};
    }
    // Assuming Source Vertex to be "1"
    dist[1] = 0;
    for(int i = 0; i < n - 1; ++i) // n - 1 phases
    {
        bool any = false;
        for(int j = 0; j < m; ++j) // Traversal Over the Edge List
        {
            ll new_dis = dist[edge_list[j].a] + edge_list[j].cost;
            if(dist[edge_list[j].b] > new_dis)
            {
                dist[edge_list[j].b] = new_dis;
                any = true;
                parent[edge_list[j].b] = edge_list[j].a;
            }
        }
        if(!any) 
        {
            // Since No change in this phase, therfore after this phase, all phases will not be having
            // any changes, therefore, it is better to stop now
            break;
        }
    }
    // Shortest Distance from source vertex is calculated in O(N * M)
    // Above Code will help to calculate distance from source vertex, but will not help to 
    // check presence of "-ve" cycle, or finding negative cycle
    
    // Below Code will help in that case
    /*
     * How to know, whether our graph is having a negative cycle or not?
     * So, In Bellman Ford Algorithm, we were dealing with the phases, so if you think for a while,
     * in graphs, which doesn't have negative cycles (cycles in which sum of all weights is negative)
     * After "n - 1" phases, we were able to get shortest paths for all the vertices, and we
     * do not record any new change in the "distance" vector
     *
     * But, if we are having a negative cycle in our graph, then all the vertices, which are 
     * reachable from the vertices of this graph, and the vertices present in this graph, their
     * distance from the source vertex will keep on decreasing,
     * So, what we can do is that, after "n - 1" phases, we will have a phase again and if
     * we are able to record any change (relaxation), then it means that "negative cycle" is present.
     */
    dist.assign(n + 1, inf);
    parent.assign(n + 1, -1);
    dist[1] = 0;
    int x = -1; // This will tell about the most recent vertex, that got "relaxation"
    for(int i = 0; i < n; ++i)
    {
        x = -1;
        for(int j = 0; j < m; ++j)
        {
            if(dist[edge_list[j].a] < inf)
            {
                ll new_dis = dist[edge_list[j].a] + edge_list[j].cost;
                if(dist[edge_list[j].b] > new_dis)
                {
                    dist[edge_list[j].b] = max(-inf, new_dis); // Because it maybe possible that it
                                                               // exceeded -inf range which we don't want
                    parent[edge_list[j].b] = edge_list[j].a;
                    x = edge_list[j].b;
                }
            }
        }
    }
    if(x == -1)
    {
        // This means No negative Cycle
        cout << "No Negative Cycle from " << 1 << '\n';
    }
    else
    {
        int y = x;
        for(int i = 0; i < n; ++i)
        {
            y = parent[y];
            // Since we are doing this n times, after these iterations, y will be storing 
            // a vertex which is present in "negative cycle".
            // If you didn't get it, then try making a graph and then think.
        }
        vector<int> path;
        for(int cur = y; ; cur = parent[cur])
        {
            path.push_back(cur);
            if(cur == y && path.size() > 1) break;
        }
        reverse(begin(path), end(path));
        cout << "Negative Cycle\n";
        for(int i = 0; i < path.size(); ++i)
        {
            cout << path[i] << ' ';
        }
    }
    return 0;
}
