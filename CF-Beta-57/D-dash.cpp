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

int n;
vector<vector<pll>> v;
vector<bool> vis;
ll optimal(int node) {
    vis[node] = true;
    vector<ll> order;
    for(const auto& [val, y] : v[node]) {
        if(!vis[val]) {
            order.push_back(optimal(val) + y);
        }
    }
    if(node != 1) return accumulate(all(order), 0LL);
    if(sz(order) == 0) return 0;
    sort(order.begin(), order.end());
    return 2 * accumulate(order.begin(), order.begin() + sz(order), 0LL);
}
ll maxx = -1;
void getMax(int node, ll s = 0) {
    vis[node] = true;
    for(const auto& [val, y] : v[node]) {
        if(!vis[val]) {
            getMax(val, s + y);
        }
    }
    maxx = max(maxx, s);
}
// *-> KISS*
int solve() {
    cin >> n;
    v.assign(n + 1, vector<pll>());
    vis.assign(n + 1, false);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back(pll(b, c));
        v[b].push_back(pll(a, c));
    }
    // Rooted at 1
    ll a1 = optimal(1);
    vis.assign(n + 1, false);
    getMax(1);
    cout << a1 - maxx;
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
