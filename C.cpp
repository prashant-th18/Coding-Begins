#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */

// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<int> in(n + 1, 0);
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int t; cin >> t;
            v[t].push_back(i + 1);
            in[i + 1]++;
        }
    }
    set<int> st;
    for(int i = 1; i <= n; ++i) {
        if(in[i] == 0) st.insert(i);
    }
    int cnt = 1, ans = 0;
    if(sz(st) == 0) {
        cout << -1; return 0;
    }
    int num = *st.begin();
    while(sz(st) != 0) {
        auto it = st.lower_bound(num);
        if(it == st.end()) {
            num = *st.begin();
            ++cnt;
        }
        else {
            int node = *it;
            for(const auto& val : v[node]) {
                --in[val];
                if(in[val] == 0) {
                    st.insert(val);
                }
            }
            num = node;
            ++ans;
            st.erase(node);
        }
    }
    if(ans == n) cout << cnt;
    else cout << -1;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
#ifdef LOCAL
        cout << "##################" << '\n';
#endif
        if (solve())
        {
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
