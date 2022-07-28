#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include "bits/stdc++.h"
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
    int n, x, y, z; cin >> n >> x >> y >> z;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> ans;
    deque<array<int, 3>> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = {i, a[i], b[i]};
    }
    sort(all(v), [&](array<int, 3> t1, array<int, 3> t2) {
        if(t1[1] != t2[1]) return t1[1] > t2[1];
        return t1[0] < t2[0];
    });
    while(x > 0) {
        ans.push_back(v.front()[0]);
        v.pop_front(); --x;
    }
    sort(all(v), [&](array<int, 3> t1, array<int, 3> t2) {
        if(t1[2] != t2[2]) return t1[2] > t2[2];
        return t1[0] < t2[0];
    });
    while(y > 0) {
        ans.push_back(v.front()[0]);
        v.pop_front(); --y;
    }
    sort(v.begin(), v.end(), [&](array<int, 3> t1, array<int, 3> t2) {
        if(t1[1] + t1[2] != t2[1] + t2[2]) return t1[1] + t1[2] > t2[1] + t2[2];
        return t1[0] < t2[0];
    });
    while(z > 0) {
        ans.push_back(v.front()[0]);
        v.pop_front(); --z;
    }
    sort(ans.begin(), ans.end());
    for(auto val : ans) cout << val + 1 << '\n';
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;
    int TET = 1;
    if(test) cin >> TET;
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
