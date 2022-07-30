#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second
using pll = pair<ll, ll>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5;
// *-> KISS*
int solve() {
    int n, m; cin >> n >> m;
    vector<int> par(n + 1, -1);
    vector<ll> rank(n + 1, 1);
    vector<vector<pll>> w(N);
    for (int i = 0; i < n - 1; i++) {
        ll a, b, c; cin >> a >> b >> c;
        w[c].push_back(pll(a, b));
    }
    multiset<ll> st;
    for (int i = 0; i < N; i++) {
        st.insert(1);
    }
    ll ans = 0;
    // Functions
    auto find = [&](int node) {
        vector<int> temp;
        while(par[node] > 0) {
            temp.push_back(node);
            node = par[node];
        }
        for(auto val : temp) par[val] = node;
        return node;
    };
    auto un = [&](int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return;
        ll t = rank[a] + rank[b];
        if(rank[a] > rank[b]) {
            par[b] = a;
        }
        else {
            par[a] = b;
        }
        ans -= (rank[a] * (rank[a] - 1)) / 2;
        ans -= (rank[b] * (rank[b] - 1)) / 2;
        
        st.erase(st.lower_bound(rank[a]));
        st.erase(st.lower_bound(rank[b]));

        if(rank[a] > rank[b]) rank[a] = t;
        else rank[b] = t;
        
        ans += t * (t - 1) / 2;
        st.insert(t);
    };
    //
    vector<ll> path(N, 0);
    for(int i = 1; i < N; ++i) {
        vector<pll>& temp = w[i];
        for(int j = 0; j < sz(temp); ++j) {
            un(temp[j].ff, temp[j].ss);
        }
        path[i] = ans;
    }
    while(m--) {
        int q; cin >> q;
        cout << path[q] << ' ';
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
