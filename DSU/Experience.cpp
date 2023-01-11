#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    vector<int> par(n + 1, -1);
    vector<int> rank(n + 1, 0);
    vector<int> lazy(n + 1, 0);
    vector<vector<int>> li(n + 1);
    
    for(int i = 1; i <= n; ++i) li[i].push_back(i);
    
    auto find = [&](int node) {
        vector<int> t;
        while(par[node] > 0) {
            t.push_back(node);
            node = par[node];
        }
        
        for(auto val : t) par[val] = node;
        return node;
    };
    
    
    for(int i = 0; i < m; ++i) {
        string s; cin >> s;
        if(s == "add") {
            int a, b; cin >> a >> b;
            lazy[find(a)] += b;
        }
        else if(s == "get") {
            int node; cin >> node;
            cout << rank[node] + lazy[find(node)] << '\n';
        }
        else {
            int a, b; cin >> a >> b;
            
            a = find(a), b = find(b);
            
            if(sz(li[a]) > sz(li[b])) swap(a, b);
            
            if(a == b) continue;
            
            for(int j = 0; j < sz(li[a]); ++j) rank[li[a][j]] += (lazy[a] - lazy[b]), li[b].push_back(li[a][j]), par[li[a][j]] = b;
            
            li[a].clear();            
        }
    }
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;
    int TET = 1;
    if(test) cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
        #ifdef LOCAL
            cout << "##################" << '\n';
        #endif

        if (solve()) {
            break;
        }
        cout << '\n';
    }
    #ifdef LOCAL
        cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}
// -> Keep It Simple Stupid!
