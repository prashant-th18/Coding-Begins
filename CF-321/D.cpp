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

// *-> KISS*
int solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<ll> value(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> value[i + 1];
    }
    vector<array<int, 3>> v(k);
    for (int i = 0; i < k; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[i] = {a, b, c};
    }
    vector<int> vis(n + 1, 0); // 0 -> not visited
                               // 1 -> visited
                               // 2 -> visited and someone's visited parent
    ll ans = 0;
    while(m) {
        vector<array<ll, 3>> temp;
        // [0] -> value
        // [1] -> x
        // [2] -> y
        // Edge from "x" to "y"
        for (int i = 0; i < k; i++) {
            int a = v[i][0], b = v[i][1], c = v[i][2];
            ll op1 = vis[a] == 0 ? value[a] : 0;
            ll op2 = vis[b] == 0 ? value[b] : 0;
            ll op3 = vis[a] != 2 && vis[b] == 0 ? c : 0;
            if(op3 == 0) continue;
            temp.push_back({op3 + op1 + op2, a, b});
        }
        sort(temp.begin(), temp.end(), [&](array<ll, 3> t1, array<ll, 3> t2) {
            return t1[0] > t2[0];
        });
        if(m == 1 || sz(temp) == 0) {
            ll maxx = 0;
            for(int i = 1; i <= n; ++i) if(vis[i] == 0) maxx = max(maxx, value[i]);
            --m;
            ans += maxx;
            break;
        }
        array<ll, 3> f = temp[0];
        ans += f[0];
        if(vis[f[1]] == 0) m -= 2;
        else m--;
        vis[f[1]] = 2;
        vis[f[2]] = 1;
    }
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
