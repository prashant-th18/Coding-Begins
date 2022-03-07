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
    ll nr, ng, nb; cin >> nr >> ng >> nb;
    vector<ll> a(nr);
    for (ll &val : a) {
        cin >> val;
    }
    vector<ll> b(ng);
    for (ll &val : b) {
        cin >> val;
    }
    vector<ll> c(nb);
    for (ll &val : c) {
        cin >> val;
    }
    sort(a.begin(), a.end()); sort(b.begin(), b.end()); sort(c.begin(), c.end());
    ll mini = LLONG_MAX;
    auto fun = [&](ll aa, ll bb, ll cc)
    {
        ll a1 = abs(aa - bb), a2 = abs(bb - cc), a3 = abs(cc - aa);
        mini = min(mini, a1 * a1 + a2 * a2 + a3 * a3);
    };
    auto make = [&](ll aa, ll bb, vector<ll>& temp)
    {
        ll number = (aa + bb) / 2;
        auto ind = lower_bound(all(temp), number) - begin(temp);
        if(ind == sz(temp)) --ind;
        fun(aa, bb, temp[ind]);
        if(ind + 1 < sz(temp)) fun(aa, bb, temp[ind + 1]);
        if(ind + 2 < sz(temp)) fun(aa, bb, temp[ind + 2]);
        if(ind - 1 >= 0) fun(aa, bb, temp[ind - 1]);
        if(ind - 2 >= 0) fun(aa, bb, temp[ind - 2]);
    };
    for(int i = 0; i < nr; ++i)
    {
        auto it1 = lower_bound(all(b), a[i]) - begin(b);
        auto it2 = lower_bound(all(c), a[i]) - begin(c);
        if(it1 == sz(b)) --it1;
        if(it2 == sz(c)) --it2;
        make(a[i], b[it1], c);
        make(a[i], c[it2], b);
        if(it1 - 1 >= 0)
        {
            make(a[i], b[it1 - 1], c);
        }
        if(it2 - 1 >= 0) make(a[i], c[it2 - 1], b);
    }
    cout << mini;
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
