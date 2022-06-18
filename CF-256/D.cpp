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
    ll n, s; cin >> n >> s;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].ff >> v[i].ss;
    }
    ll si = 1, ei = s, ans{};
    while(si <= ei) {
        ll mid = midpoint(si, ei);
        ll lower {}, higher {}, sum {};
        for (int i = 0; i < n; i++) {
            if(v[i].ss < mid) sum += v[i].ff, ++lower;
            else if(mid < v[i].ff) sum += v[i].ff, ++higher;
        }
        if(lower > n / 2) {
            ei = mid - 1;
        }
        else if(higher > n / 2) {
            si = mid + 1;
        }
        else {
            lower = n / 2 - lower;
            higher = n / 2 - higher;
            vector<ll> temp;
            for(int i = 0; i < n; ++i) {
                if(v[i].ff <= mid && mid <= v[i].ss) {
                    temp.push_back(v[i].ff);
                }
            }
            sort(temp.begin(), temp.end());
            for (int i = 0; i < sz(temp); i++) {
                if(lower) {
                    --lower;
                    sum += temp[i];
                }
                else {
                    sum += mid;
                }
            }
            if(sum <= s) {
                ans = mid;
                si = mid + 1;
            }
            else {
                ei = mid - 1;
            }
        }
    }
    cout << ans;
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
