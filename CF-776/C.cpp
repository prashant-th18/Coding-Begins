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
struct edge {
    ll a, b, c;
    bool operator<(const edge& other) const
    {
        return make_tuple(a, b, c) < make_tuple(other.a, other.b, other.c);
    }
};
// *-> KISS*
int solve() {
    ll n, m; cin >> n >> m;
    set<edge> st;
    for (int i = 0; i < m; i++) {
        ll x, w; cin >> x >> w;
        st.insert({w, x, i + 1});
    }
    ll sum = 0;
    deque<pair<ll, ll>> v;
    for (int i = 0; i < 2 * n; i++) {
        sum += st.begin()->a;
        v.push_back(pair(st.begin()->b, st.begin()->c));
        st.erase(st.begin());
    }
    sort(v.begin(), v.end());
    cout << sum << '\n';
    while(sz(v) != 0)
    {
        cout << v.front().ss << ' ' << v.back().ss << '\n';
        v.pop_front();
        v.pop_back();
    }
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
