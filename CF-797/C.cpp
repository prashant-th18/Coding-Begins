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
const int MOD = 1000000007;
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
    vector<ll> a(n), b(n);
    deque<array<ll, 3>> dq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dq.push_back({a[i], i, -1});
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        dq.push_back({b[i], i, 1});
    }
    sort(dq.begin(), dq.end(), [&](array<ll, 3> t1, array<ll, 3> t2) {
        if(t1[1] != t2[1]) return t1[1] < t2[1];
        return t1[0] < t2[0];
    });
    vector<ll> t(n, 0);
    ll cnt = 0;
    while(!dq.empty()) {
        array<ll, 3> temp = dq.front();
        dq.pop_front();
        cnt = max(cnt, temp[0]);
        if(temp[2] == -1) {
            t[temp[1]] = cnt;
        }
        else {
            t[temp[1]] = b[temp[1]] - t[temp[1]];
        }
    }
    for(auto val : t) cout << val << ' ';
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
