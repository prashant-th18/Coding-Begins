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
int N = 1e6 + 10;
// *-> KISS*
int solve() {
    ll n, c; cin >> n >> c;
    vector<bool> present(N, false);
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        present[v[i]] = true;
    }
    sort(v.begin(), v.end());
    vector<ll> copy = v;
    copy.resize(unique(all(copy)) - copy.begin());
    vector<bool> done(N, false);
    for(int i = n - 1; i >= 0; --i)
    {
        if(done[v[i]]) continue;
        ll n1 = v[i];
        int index = lower_bound(all(copy), n1) - copy.begin();
        for(int j = 0; j <= index; ++j)
        {
            if(!present[n1 / copy[j]])
            {
                cout << "No"; return 0;
            }
        }
        done[v[i]] = true;
    }
    cout << "Yes";
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
