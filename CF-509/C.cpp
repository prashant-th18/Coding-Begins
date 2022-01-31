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
#define MOD 1000000007
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
    int n, m, d; cin >> n >> m >> d;
    vector<int> ans(n, 0);
    unordered_map<int, int> index;
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        st.insert(a);
        index[a] = i;
    }
    int days = 1;
    while(sz(st) != 0)
    {
        auto f = *st.begin();
        st.erase(st.begin());
        int lower = (f) + d;
        ans[index[f]] = days;
        auto it = st.upper_bound(lower);
        while(it != st.end())
        {
            ans[index[*it]] = days;
            lower = *it;
            st.erase(it);
            lower = lower + d;
            it = st.upper_bound(lower);
        }
        ++days;
    }
    cout << days - 1 << '\n';
    for(const auto& val : ans) cout << val << ' ';
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
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
}
// -> Keep It Simple Stupid!
