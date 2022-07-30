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

int n, m;
vector<vector<pll>> v;
vector<bool> vis;
vector<int> col;
vector<int> ans;
bool check(int node, int c = 0) {
    col[node] = c;
    vis[node] = true;
    for(const auto& [val, _] : v[node]) {
        if(!vis[val] && !check(val, 1 - c)) return false;
        if(vis[val] && col[node] == col[val]) return false;
    }
    return true;
}
void dfs(int node, int c = 0) {
    vis[node] = true;
    for(const auto& [val, in] : v[node]) {
        if(!vis[val]) {
            if(in < 0) ans[-in] = 1 - c;
            else ans[in] = c;
            dfs(val, 1 - c);
        }
        else {
            int t = abs(in);
            if(ans[t] != -1) continue;
            else {
                if(in < 0) ans[t] = 1 - c;
                else ans[t] = c;
            }
        }
    }
}
// *-> KISS*
int solve() {
    cin >> n >> m;
    v.assign(n + 1, vector<pll>());
    vis.assign(n + 1, false);
    col.assign(n + 1, 0);
    ans.assign(m + 1, -1);
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(pll(b, i));
        v[b].push_back(pll(a, -i));
    }
    if(check(1) == false) cout << "NO";
    else {
        cout << "YES\n";
        vis.assign(n + 1, false);
        dfs(1);
        for(int i = 0; i < m; ++i) cout << ans[i + 1];
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
