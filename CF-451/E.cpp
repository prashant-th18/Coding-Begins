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
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    unordered_map<ll, bool> sq;
    vector<ll> all_sq;
    for(ll i = 0; i <= 1e5; ++i)
    {
        sq[i * i] = true;
        all_sq.push_back(i * i);
    }
    int initial = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        if(sq.count(v[i])) ++initial;
        if(v[i] == 0) ++zero;
    }
    if(initial >= n / 2)
    {
        int temp = initial - n / 2;
        int rem = initial - zero;
        if(rem >= temp)
        {
            cout << temp;
            return 0;
        }
        else
        {
            cout << (2 * temp - rem); return 0;
        }
    }
    vector<ll> diff;
    for (int i = 0; i < n; i++) {
        if(sq.count(v[i])) continue;
        auto it = lower_bound(all(all_sq), v[i]);
        ll d = 1e9;
        d = min(d, *it - v[i]);
        --it;
        d = min(d, v[i] - *it);
        diff.push_back(d);
    }
    sort(diff.begin(), diff.end());
    cout << accumulate(begin(diff), begin(diff) + n / 2 - initial, 0LL);
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
