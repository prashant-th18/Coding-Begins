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
    int n, k; cin >> n >> k;
    vector<int> v(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        t[i] = v[i];
    }
    sort(t.begin(), t.end());
    auto check = [&](int s, int e) -> bool {
        int in1 = upper_bound(all(t), e) - begin(t);
        int in2 = lower_bound(all(t), s) - begin(t);
        int C = in1 - in2;
        int NC = n - C;
        return C - NC >= k;
    };
    int y = 1e9, x = -1e9;
    int minn = *min_element(all(t)), maxx = *max_element(all(t));
    for(int i = minn; i <= maxx; ++i) {
        int s = i, e = maxx, ans = -1;
        while(s <= e) {
            int mid = (s + e) >> 1;
            if(check(i, mid)) {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        if(ans != -1) {
            if(ans - i < y - x) {
                y = ans;
                x = i;
            }
        }
    }
    vector<pair<int, int>> ans;
    {
        int st = 0, cnt = 0, pos = 0, neg = 0, in = 0;
        while(cnt < k - 1) {
            if(x <= v[in] && v[in] <= y) ++pos;
            else ++neg;
            if(pos > neg) {
                ans.push_back(pair(st, in));
                ++cnt;
                st = in + 1;
                pos = 0, neg = 0;
            }
            ++in;
        }
        ans.push_back(pair(st, n - 1));
    }
    cout << x << ' ' << y << '\n';
    for(auto& [a, b] : ans) cout << a + 1 << ' ' << b + 1 << '\n';
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
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
