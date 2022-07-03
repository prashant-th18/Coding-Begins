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

vector<int> take, cur;
vector<vector<int>> v;
ll n, k, d, in = 0;
void fun(int j) { // in -> 0, n - 1,  j -> 0, d - 1
    if(j == d) {
        for(int i = 0; i < d; ++i) {
            v[i][in] = cur[i];
        }
        ++in;
        return;
    }
    int c = 0;
    while(c < sz(take)) {
        cur[j] = take[c++];
        fun(j + 1);
        if(in == n) return;
    }
}
// *-> KISS*
int solve() {
    cin >> n >> k >> d;
    // Find smallest k, such that, k^d >= n
    ll ans = -1;
    ll s = 1, e = 1e9;
    auto find = [&](ll num) -> bool {
        ll res = 1;
        for (int i = 0; i < d; i++) {
            res *= num;
            if(res >= n) return true;
        }
        return false;
    };
    while(s <= e) {
        ll mid = (s + e) / 2;
        if(find(mid)) {
            ans = mid;
            e = mid - 1;
        }
        else s = mid + 1;
    }
    if(ans > k) {
        cout << -1; return 0;
    }
    k = ans;
    take.assign(k, 0);
    iota(all(take), 1);
    v.assign(d, vector<int>(n, -1));
    cur.assign(d, -1);
    fun(0);
    for(int i = 0; i < d; ++i) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
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
