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
    ll n; cin >> n;
    vector<ll> a(n);
    for (ll &val : a) {
        cin >> val;
    }
    vector<ll> b(n);
    for (ll &val : b) {
        cin >> val;
    }
    auto bestCandidate = [&](vector<ll>& v, ll num) -> ll
    {
        ll diff = abs(v[0] - num), index = 0;
        for(int i = 1; i < n; ++i)
        {
            ll d = abs(v[i] - num);
            if(d < diff)
            {
                diff = d;
                index = i;
            }
        }
        return index;
    };
    vector<ll> forf = {0, bestCandidate(b, a[0]), n - 1};
    vector<ll> forl = {0, bestCandidate(b, a[n - 1]), n - 1};
    ll mini = 1e12;
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            ll ans = abs(a[0] - b[forf[i]]) + abs(a[n - 1] - b[forl[j]]);
            if(i > 0 && j > 0)
            {
                ans += abs(b[0] - a[bestCandidate(a, b[0])]);
            }
            if(i < 2 && j < 2)
            {
                ans += abs(b[n - 1] - a[bestCandidate(a, b[n - 1])]);
            }
            mini = min(mini, ans);
        }
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
