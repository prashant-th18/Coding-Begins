#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
struct Edge
{
    int w = INF; // Weight
    int p = -1; // No parent
};
int main()
{
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        --a;
        --b;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    auto prim = [&]() -> void
    {
        vector<bool> in_mst(n, false);
        vector<Edge> min_e(n);
        int total_weight = 0;
        // Making weight of vertex "0" equal to "0" so that it can be selected as the first vertex of MST
        min_e[0].w = 0;
        for(int i = 0; i < n; ++i)
        {
            int v = -1; // Which vertex to be added to MST this time
            for(int j = 0; j < n; ++j)
            {
                if(!in_mst[j] && (v == -1 || min_e[j].w < min_e[v].w)) // If weight of "j" is less and not selected
                {                                                      // Select Vertex "j"
                      v = j;                                  
                }
            }
            if(v == -1)
            {
                cout << "No MST!"; exit(0);
            }
            in_mst[v] = true;
            total_weight += min_e[v].w;
            // Printing Parent
            cout << "Parent of " << v << " is " << min_e[v].p << endl;

            for(auto [node, weight] : adj[v])
            {
                if(!in_mst[node] && (min_e[node].w > weight))
                {
                    min_e[node].w = weight;
                    min_e[node].p = v;
                }
            }
        }
        cout << total_weight << endl;
    };
    prim();
    return 0;
}
