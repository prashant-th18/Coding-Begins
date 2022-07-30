// 0-1 BFS =>
// SSSP from a vertex "S" to all other vertices given that weight of every edge is either 0 or 1
#include"bits/stdc++.h"
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> v(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back(pair(b, c));
        v[b].push_back(pair(a, c));
    }
    vector<int> d(n + 1, 1e6);
    int s = 1; // Assuming source is "1"
    d[s] = 0;
    deque<int> dq;
    dq.push_back(s);
    while(!dq.empty()) {
        int node = dq.front(); dq.pop_front();
        for(const auto& [val, w] : v[node]) {
            if(d[node] + w < d[val]) {
                d[val] = w + d[node];
                if(w == 1) {
                    dq.push_back(val);
                }
                else dq.push_front(val);
            }
        }
    }
    return 0;
}
