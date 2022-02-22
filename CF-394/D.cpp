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
    ll n, l, r; cin >> n >> l >> r;
    vector<tuple<ll, ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> get<0>(v[i]);
        get<2>(v[i]) = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> get<1>(v[i]);
    }
    auto f = [&](tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) -> bool
    {
          return get<1>(a) < get<1>(b);
    };
    sort(v.begin(), v.end(), f);
    ll maxx = LLONG_MIN;
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        ll s = l, e = r, ans = -1;
        while(s <= e)
        {
            ll mid = midpoint(s, e);
            if(mid - get<0>(v[i]) > maxx)
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        if(ans == -1)
        {
            cout << -1; return 0;
        }
        else
        {
            maxx = ans - get<0>(v[i]);
            b[get<2>(v[i])] = ans;
        }
    }
    for(auto val : b) cout << val << ' ';
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
    return 0;
}
// -> Keep It Simple Stupid!
