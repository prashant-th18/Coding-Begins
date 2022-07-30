#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include "debug.h"
#else
    #include "bits/stdc++.h"
    using namespace std;
    typedef long long ll;
    #define sz(s) ((int)s.size())
    #define all(v) begin(v), end(v)
    #define debug(...)
#endif

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 20;
int n, m;
vector<vector<int>> v;
int dp[(1 << N)][N];
void add(int& a, int b) {
    a = (a % MOD + b % MOD) % MOD;
}
int func(int mask, int node) {
    mask |= (1 << node);
    if(dp[mask][node] != -1) return dp[mask][node];
    if(node == n - 1) {
        if(__builtin_popcount(mask) == n) {
            return 1;
        }
        return 0;
    }
    // Make dp[mask] = 0;
    dp[mask][node] = 0;
    for(const auto& val : v[node]) {
        if(!((mask >> val) & 1)) {
            add(dp[mask][node], func(mask, val));
        }
    }
    return dp[mask][node];
}
// *-> KISS*
int solve() {
    for(int i = 0; i < (1 << N); ++i) {
        for(int j = 0; j < N; ++j) dp[i][j] = -1;
    }
    cin >> n >> m;
    v.assign(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        --a; --b;
        v[a].push_back(b);
    }
    cout << func(0, 0);
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
