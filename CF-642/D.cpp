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
struct comp
{
    bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) const
    {
        if(get<0>(a) != get<0>(b))
        {
            return get<0>(a) > get<0>(b);
        }
        return get<1>(a) < get<1>(b);
    }
};
// *-> KISS*
int solve() {
    set<tuple<int, int, int>, comp> st;
    int n, cnt {1};
    cin >> n;
    st.insert(tuple(n, 0, n - 1));
    vector<int> v(n);
    while(sz(st) != 0)
    {
        auto p = *st.begin();
        st.erase(st.begin());
        int length = get<0>(p);
        int full = get<1>(p) + get<2>(p);
        if(!(length & 1))
        {
            --full;
        }
        full /= 2;
        v[full] = cnt++;
        if(full - get<1>(p) >= 1)
        {
            st.insert(tuple(full - get<1>(p), get<1>(p), full - 1));
        }
        if(get<2>(p) - full >= 1)
        {
            st.insert(tuple(get<2>(p) - full, full + 1, get<2>(p)));
        }
    }
    for(auto val : v) cout << val << ' ';
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
