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
unordered_map<ll, bool> mp;
vector<ll> v;
// *-> KISS*
int solve() {
    ll n; cin >> n;
    if(n == 1)
    {
        cout << 0; return 0;
    }
    ll cnt = 0;
    while(n > 0) {
        if(mp.count(n))
        {
            --n; continue;
        }
        auto it = lower_bound(all(v), n) - v.begin();
        ll elem = v[it];
        ll newnum = elem - n - 1;
        ll elements = n - newnum;
        cnt += elements * elem;
        n = newnum;
    }
    cout << cnt;
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    for(ll i = 1; i < 40; ++i)
    {
        ll num = (1LL << i) - 1;
        mp[num] = true;
        v.push_back(num);
    }
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
}
// -> Keep It Simple Stupid!
