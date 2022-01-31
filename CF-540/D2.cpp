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
    ll n, m, sum {}; cin >> n >> m;
    vector<ll> v(n);
    for (ll &val : v) {
        cin >> val;
        sum += val;
    }
    sort(v.rbegin(), v.rend());
    if(m > sum)
    {
        cout << -1; return 0;
    }
    sum = 0;
    ll days = 0;
    for(int i = 0; i < n; ++i)
    {
        ++days;
        sum += v[i];
    }
    while(sum > m && sz(v) != 0)
    {
        int last = v.back(), cnt {};
        ll temp_sum = sum;
        for(int j = 1; j <= last - 1; ++j)
        {
            if(temp_sum - j >= m && (cnt + 1) < sz(v))
            {
                ++cnt;
                temp_sum -= j;
            }
            else break;
        }
        if(cnt == 0)
        {
            
        }
        // cnt + 1 udao
        for(int i = 0; i <= cnt; ++i) v.pop_back();
        sum = temp_sum;
        days -= cnt;
    }
    cout << days;
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
