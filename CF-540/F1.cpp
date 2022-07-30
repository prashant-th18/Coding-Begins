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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int n, r, b, ans;
vector<int> value;
vector<vector<int>> v;
vector<bool> vis;
pair<int, int> dfs(int node) {
    pair<int, int> an = {0, 0};
    vis[node] = true;
    for(const auto& val : v[node]) {
        if(!vis[val]) {
            pair<int, int> there = dfs(val);
            pair<int, int> here = pair(r - there.ff, b - there.ss);
            if(!((there.ff != 0 && there.ss != 0) || (here.ff != 0 && here.ss != 0))) {
                ++ans;
            }
            an.ff += there.ff;
            an.ss += there.ss;
        }
    }
    an.ff += (value[node] == 1);
    an.ss += (value[node] == 2);
    return an;
}
// *-> KISS*
int solve() {
    cin >> n;
    value.assign(n + 1, 0);
    v.assign(n + 1, vector<int>());
    vis.assign(n + 1, false);
    for (int i = 0; i < n; i++) {
        cin >> value[i + 1];
        r += value[i + 1] == 1;
        b += value[i + 1] == 2;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, bb; cin >> a >> bb;
        v[a].push_back(bb);
        v[bb].push_back(a);
    }
    dfs(1);
    cout << ans;
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
