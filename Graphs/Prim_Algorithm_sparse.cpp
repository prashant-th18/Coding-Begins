// Time Complexity ->
// O(N + MLog(N))
#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int w = 1e9; // Weight
    int p = -1; // Parent
    bool operator<(Edge const& other) const
    {
        return make_pair(w, p) < make_pair(other.w, other.p);
    }
};
int main()
{
    int n, m, total_weight = 0; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<bool> in_mst(n, false);
    vector<Edge> min_e(n);// For Every index, it keeps two things -> Minimum weight it get from any other vertex
                          //-> Parent (That Vertex from where minimum weight edge is present)
    set<Edge> pq;
    // Set keeps {weight, aur kis index pr ye weight hai}
    // Mtlb ki ek toh vo index jispr kisi vertex se weighted edge aaya hua ho, ek toh wo "weight"
    // Dusra, jis index pr ye edge hai (joki abhi MST mai nhi hai)
    
    // Set ke case mai "P" ka alag meaning hai
    // min_e ke case mai alag meaning hai

    min_e[0].w = 0; // Because We start with 0 index
    pq.insert({0, 0}); // Initially only vertex "0" is present, jispr khi se bhi edge nhi hai
    for (int i = 0; i < n; i++) {
        if(pq.empty()) 
        {
            cout << "No MST!"; return 0;
        }
        total_weight += pq.begin()->w;
        int v = pq.begin()->p; // We got the node, whose weight we just added in total_weight(minimum one)
        in_mst[v] = true;
        pq.erase(pq.begin());
        for(auto [node, weight] : adj[v])
        {
            if(!in_mst[node] && min_e[node].w > weight)
            {
                auto present = pq.find({min_e[node].w, node});
                if(present != pq.end())
                {
                    pq.erase(present);
                }
                min_e[node].w = weight;
                min_e[node].p = v;
                pq.insert({weight, node});
            }
        }
        cout << "Parent of " << v << " is " << min_e[v].p << endl;
    }
    cout << total_weight << endl;
    return 0;
}

